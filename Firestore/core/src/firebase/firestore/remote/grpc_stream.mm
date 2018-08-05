/*
 * Copyright 2018 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Firestore/core/src/firebase/firestore/remote/grpc_stream.h"

#include <utility>

#include "Firestore/Source/Remote/FSTDatastore.h"
#include "Firestore/core/src/firebase/firestore/remote/stream_operation.h"
#include "Firestore/core/src/firebase/firestore/util/error_apple.h"
#include "Firestore/core/src/firebase/firestore/util/hard_assert.h"
#include "Firestore/core/src/firebase/firestore/util/log.h"
#include "Firestore/core/src/firebase/firestore/util/status.h"
#include "absl/memory/memory.h"

namespace firebase {
namespace firestore {
namespace remote {

namespace {

using auth::CredentialsProvider;
using auth::Token;
using core::DatabaseInfo;
using model::DatabaseId;
using model::SnapshotVersion;
using util::AsyncQueue;
using util::TimerId;

/**
 * Initial backoff time after an error.
 * Set to 1s according to https://cloud.google.com/apis/design/errors.
 */
const double kBackoffFactor = 1.5;
const AsyncQueue::Milliseconds kBackoffInitialDelay{std::chrono::seconds(1)};
const AsyncQueue::Milliseconds kBackoffMaxDelay{std::chrono::seconds(60)};
const AsyncQueue::Milliseconds kIdleTimeout{std::chrono::seconds(60)};

// Operations

class StreamStart : public StreamOperation {
 public:
  using StreamOperation::StreamOperation;

 private:
  void DoExecute(GrpcCall* const call) override {
    call->Start(this);
  }
  void OnCompletion(Stream* const stream, const bool ok) override {
    stream->OnStreamStart(ok);
  }
};

class StreamRead : public StreamOperation {
 public:
  using StreamOperation::StreamOperation;

 private:
  void DoExecute(GrpcCall* const call) override {
    call->Read(&message_, this);
  }
  void OnCompletion(Stream* const stream, const bool ok) override {
    stream->OnStreamRead(ok, message_);
  }

  grpc::ByteBuffer message_;
};

class StreamWrite : public StreamOperation {
 public:
  StreamWrite(Stream* const stream,
              const std::shared_ptr<GrpcCall>& call,
              const int generation,
              const grpc::ByteBuffer& message)
      : StreamOperation{stream, call, generation}, message_{&message} {
  }

 private:
  void DoExecute(GrpcCall* const call) override {
    call->Write(*message_, this);
  }
  void OnCompletion(Stream* const stream, const bool ok) override {
    stream->OnStreamWrite(ok);
  }

  const grpc::ByteBuffer* message_;
};

class StreamFinish : public StreamOperation {
 public:
  using StreamOperation::StreamOperation;

 private:
  void DoExecute(GrpcCall* const call) override {
    call->TryCancel();
    call->Finish(&grpc_status_, this);
  }

  void OnCompletion(Stream* stream, const bool ok) override {
    HARD_ASSERT(ok,
                "Calling Finish on a GRPC call should never fail, "
                "according to the docs");
    stream->OnStreamFinish(ToFirestoreStatus(grpc_status_));
  }

  static util::Status ToFirestoreStatus(const grpc::Status from) {
    if (from.ok()) {
      return {};
    }
    return {Datastore::ToFirestoreErrorCode(from.error_code()),
            from.error_message()};
  }

  grpc::Status grpc_status_;
};

}  // namespace

namespace internal {

grpc::ByteBuffer SerializerBridge::ToByteBuffer(FSTQueryData* query) const {
  GCFSListenRequest* request = [GCFSListenRequest message];
  request.database = [serializer_ encodedDatabaseID];
  request.addTarget = [serializer_ encodedTarget:query];
  request.labels = [serializer_ encodedListenRequestLabelsForQueryData:query];

  return ToByteBuffer([request data]);
}

grpc::ByteBuffer SerializerBridge::ToByteBuffer(FSTTargetID target_id) const {
  GCFSListenRequest* request = [GCFSListenRequest message];
  request.database = [serializer_ encodedDatabaseID];
  request.removeTarget = target_id;

  return ToByteBuffer([request data]);
}

grpc::ByteBuffer SerializerBridge::ToByteBuffer(NSData* data) const {
  const grpc::Slice slice{[data bytes], [data length]};
  return grpc::ByteBuffer{&slice, 1};
}

FSTWatchChange* SerializerBridge::ToWatchChange(GCFSListenResponse* proto) const {
  return [serializer_ decodedWatchChange:proto];
}

SnapshotVersion SerializerBridge::ToSnapshotVersion(GCFSListenResponse* proto) const {
  return [serializer_ versionFromListenResponse:proto];
}

NSData* SerializerBridge::ToNsData(const grpc::ByteBuffer& buffer) const {
  std::vector<grpc::Slice> slices;
  const grpc::Status status = buffer.Dump(&slices);
  HARD_ASSERT(status.ok(), "Trying to convert a corrupted grpc::ByteBuffer");

  if (slices.size() == 1) {
    return [NSData dataWithBytes:slices.front().begin()
                          length:slices.front().size()];
  } else {
    NSMutableData* data = [NSMutableData dataWithCapacity:buffer.Length()];
    for (const auto& slice : slices) {
      [data appendBytes:slice.begin() length:slice.size()];
    }
    return data;
  }
}

void DelegateBridge::NotifyDelegateOnOpen() {
  id<FSTStreamDelegate> delegate = delegate_;
  [delegate watchStreamDidOpen];
}

NSError* DelegateBridge::NotifyDelegateOnChange(const grpc::ByteBuffer& message) {
  NSError* error;
  auto* proto = ToProto<GCFSListenResponse>(message, &error);
  if (proto) {
    id<FSTStreamDelegate> delegate = delegate_;
    [delegate watchStreamDidChange:ToWatchChange(proto)
                   snapshotVersion:ToSnapshotVersion(proto)];
    return nil;
  }

  NSDictionary* info = @{
    NSLocalizedDescriptionKey : @"Unable to parse response from the server",
    NSUnderlyingErrorKey : error,
    @"Expected class" : [GCFSListenResponse class],
    @"Received value" : ToNsData(message),
  };
  return [NSError errorWithDomain:FIRFirestoreErrorDomain
                             code:FIRFirestoreErrorCodeInternal
                         userInfo:info];
}

void DelegateBridge::NotifyDelegateOnError(const FirestoreErrorCode error_code) {
  id<FSTStreamDelegate> delegate = delegate_;
  NSError* error = util::MakeNSError(error_code, "Server error");  // TODO
  [delegate watchStreamWasInterruptedWithError:error];
}

}  // namespace

Stream::Stream(AsyncQueue* const async_queue,
               CredentialsProvider* const credentials_provider,
               FSTSerializerBeta* serializer,
               Datastore* const datastore,
               const TimerId backoff_timer_id,
               const TimerId idle_timer_id)
    : firestore_queue_{async_queue},
      credentials_provider_{credentials_provider},
      datastore_{datastore},
      buffered_writer_{this},
      serializer_bridge_{serializer},
      backoff_{firestore_queue_, backoff_timer_id, kBackoffFactor,
               kBackoffInitialDelay, kBackoffMaxDelay},
      idle_timer_id_{idle_timer_id} {
}

// Starting

void Stream::Start() {
  firestore_queue_->VerifyIsCurrentQueue();

  if (state_ == State::GrpcError) {
    BackoffAndTryRestarting();
    return;
  }

  // TODO: util::LogDebug(%@ %p start", NSStringFromClass([self class]),
  // (__bridge void *)self);

  HARD_ASSERT(state_ == State::Initial, "Already started");
  state_ = State::Starting;

  // Auth may outlive the stream, so make sure it doesn't try to access a
  // deleted object.
  std::weak_ptr<Stream> weak_self{shared_from_this()};
  const int auth_generation = generation();
  // TODO OBC: refactor, way too nested.
  credentials_provider_->GetToken(
      [weak_self, auth_generation](util::StatusOr<Token> maybe_token) {
        if (auto live_instance = weak_self.lock()) {
          live_instance->firestore_queue_->EnqueueRelaxed(
              [maybe_token, weak_self, auth_generation] {
                if (auto live_instance = weak_self.lock()) {
                  // Streams can be stopped while waiting for authorization.
                  if (live_instance->generation_ == auth_generation) {
                    live_instance->ResumeStartAfterAuth(maybe_token);
                  }
                }
              });
        }
      });
}

void Stream::ResumeStartAfterAuth(const util::StatusOr<Token>& maybe_token) {
  firestore_queue_->VerifyIsCurrentQueue();

  HARD_ASSERT(state_ == State::Starting,
              "State should still be 'Starting' (was %s)", state_);

  if (!maybe_token.ok()) {
    OnStreamFinish(maybe_token.status());
    return;
  }

  const absl::string_view token = [&] {
    const auto token = maybe_token.ValueOrDie();
    return token.user().is_authenticated() ? token.token()
                                           : absl::string_view{};
  }();
  grpc_call_ = DoCreateGrpcCall(datastore_, token);

  Execute<StreamStart>();
  // TODO: set state to open here, or only upon successful completion?
  // Objective-C does it here. C++, for now at least, does it upon successful
  // completion.
}

void Stream::OnStreamStart(const bool ok) {
  firestore_queue_->VerifyIsCurrentQueue();
  if (!ok) {
    OnConnectionBroken();
    return;
  }

  state_ = State::Open;

  buffered_writer_.Start();
  Execute<StreamRead>();
}

// Backoff

void Stream::BackoffAndTryRestarting() {
  // LogDebug(@"%@ %p backoff", NSStringFromClass([self class]), (__bridge void
  // *)self);
  firestore_queue_->VerifyIsCurrentQueue();

  HARD_ASSERT(state_ == State::GrpcError,
              "Should only perform backoff in an error case");

  backoff_.BackoffAndRun([this] { ResumeStartFromBackoff(); });
  state_ = State::ReconnectingWithBackoff;
}

void Stream::ResumeStartFromBackoff() {
  firestore_queue_->VerifyIsCurrentQueue();

  if (state_ == State::ShuttingDown) {
    // We should have canceled the backoff timer when the stream was closed, but
    // just in case we make this a no-op.
    return;
  }

  // In order to have performed a backoff the stream must have been in an error
  // state just prior to entering the backoff state. If we weren't stopped we
  // must be in the backoff state.
  HARD_ASSERT(state_ == State::ReconnectingWithBackoff,
              "State should still be backoff (was %s)", state_);

  state_ = State::Initial;
  Start();
  HARD_ASSERT(IsStarted(), "Stream should have started.");
}

void Stream::CancelBackoff() {
  firestore_queue_->VerifyIsCurrentQueue();

  HARD_ASSERT(!IsStarted(), "Can only cancel backoff after an error (was %s)",
              state_);

  // Clear the error condition.
  state_ = State::Initial;
  backoff_.Reset();
}

// Idleness

void Stream::MarkIdle() {
  firestore_queue_->VerifyIsCurrentQueue();
  if (IsOpen() && !idleness_timer_) {
    idleness_timer_ = firestore_queue_->EnqueueAfterDelay(
        kIdleTimeout, idle_timer_id_, [this] { StopDueToIdleness(); });
  }
}

void Stream::CancelIdleCheck() {
  idleness_timer_.Cancel();
}

// Read/write

// Called by `BufferedWriter`.
void Stream::Write(const grpc::ByteBuffer& message) {
  Execute<StreamWrite>(message);
}

void Stream::OnStreamRead(const bool ok, const grpc::ByteBuffer& message) {
  firestore_queue_->VerifyIsCurrentQueue();
  if (!ok) {
    OnConnectionBroken();
    return;
  }

  client_side_error_ = DoOnStreamRead(message);
  if (client_side_error_) {
    OnConnectionBroken();
    return;
  }

  if (IsOpen()) {
    // While `Stop` hasn't been called, continue waiting for new messages
    // indefinitely.
    Execute<StreamRead>();
  }
}

void Stream::OnStreamWrite(const bool ok) {
  firestore_queue_->VerifyIsCurrentQueue();
  if (!ok) {
    OnConnectionBroken();
    return;
  }

  DoOnStreamWrite();
  buffered_writer_.OnSuccessfulWrite();
}

// Stopping

void Stream::Stop() {
  firestore_queue_->VerifyIsCurrentQueue();

  RaiseGeneration();
  if (!IsStarted()) {
    return;
  }

  buffered_writer_.Stop();
  HalfCloseConnection();
  // If this is an intentional close, ensure we don't delay our next connection
  // attempt.
  backoff_.Reset();

  state_ = State::Initial;
}

void Stream::RaiseGeneration() {
  if (IsStarted()) {
    ++generation_;
  }
}

void Stream::OnConnectionBroken() {
  firestore_queue_->VerifyIsCurrentQueue();

  RaiseGeneration();
  if (!IsOpen()) {
    return;
  }

  buffered_writer_.Stop();
  HalfCloseConnection();

  state_ = State::GrpcError;
}

void Stream::HalfCloseConnection() {
  firestore_queue_->VerifyIsCurrentQueue();
  if (!IsOpen()) {
    return;
  }

  Execute<StreamFinish>();
}

void Stream::OnStreamFinish(const util::Status status) {
  firestore_queue_->VerifyIsCurrentQueue();

  const FirestoreErrorCode error = [&] {
    if (client_side_error_ && status.code() == FirestoreErrorCode::Ok) {
      return FirestoreErrorCode::Internal;
    }
    return status.error_code();
  }();

  if (client_side_error_) {
    LOG_DEBUG("%s", client_side_error_.value());
  } else if (error == FirestoreErrorCode::ResourceExhausted) {
    // LogDebug("%@ %p Using maximum backoff delay to prevent overloading the
    // backend.", [self class],
    //       (__bridge void *)self);
    backoff_.ResetToMax();
  } else if (error == FirestoreErrorCode::Unauthenticated) {
    credentials_provider_->InvalidateToken();
  }
  client_side_error_.reset();

  DoOnStreamFinish(error);

  // After a GRPC call has been finished, it is no longer valid. Pending
  // operations, if any, have their own `shared_ptr` to the call.
  grpc_call_.reset();
}

void Stream::StopDueToIdleness() {
  firestore_queue_->VerifyIsCurrentQueue();
  if (!IsOpen()) {
    return;
  }

  Stop();
  // When timing out an idle stream there's no reason to force the stream
  // into backoff when it restarts.
  CancelBackoff();
  state_ = State::Initial;  // FIXME to distinguish from other stop cases.
}

// Check state

bool Stream::IsOpen() const {
  firestore_queue_->VerifyIsCurrentQueue();
  return state_ == State::Open;
}

bool Stream::IsStarted() const {
  firestore_queue_->VerifyIsCurrentQueue();
  const bool is_starting =
      (state_ == State::Starting || state_ == State::ReconnectingWithBackoff);
  return is_starting || IsOpen();
}

// Watch stream

WatchStream::WatchStream(AsyncQueue* const async_queue,
                         CredentialsProvider* const credentials_provider,
                         FSTSerializerBeta* serializer,
                         Datastore* const datastore,
                         id delegate)
    : Stream{async_queue,
             credentials_provider,
             serializer,
             datastore,
             TimerId::ListenStreamConnectionBackoff,
             TimerId::ListenStreamIdle},
      delegate_bridge_{delegate} {
}

void WatchStream::WatchQuery(FSTQueryData* query) {
  firestore_queue_->VerifyIsCurrentQueue();

  CancelIdleCheck();
  buffered_writer_.Enqueue(serializer_bridge_.ToByteBuffer(query));
}

void WatchStream::UnwatchTargetId(FSTTargetID target_id) {
  firestore_queue_->VerifyIsCurrentQueue();

  CancelIdleCheck();
  buffered_writer_.Enqueue(serializer_bridge_.ToByteBuffer(target_id));
}

std::shared_ptr<GrpcCall> WatchStream::DoCreateGrpcCall(Datastore* const datastore,
                                       const absl::string_view token) {
  return datastore->CreateGrpcCall(
      token, "/google.firestore.v1beta1.Firestore/Listen");
}

void WatchStream::DoOnStreamStart() {
  delegate_bridge_.NotifyDelegateOnOpen();
}

absl::optional<std::string> WatchStream::DoOnStreamRead(
    const grpc::ByteBuffer& message) {
  // FIXME OBC remove nserror
  NSError* error = delegate_bridge_.NotifyDelegateOnChange(message);
  if (error) {
    return util::MakeString([error description]);
  }
  return {};
}

void WatchStream::DoOnStreamWrite() {
  // Nothing to do.
}

void WatchStream::DoOnStreamFinish(const FirestoreErrorCode error) {
  delegate_bridge_.NotifyDelegateOnError(error);
}

// serializer, queue, and writer have to be protected
// separating objcbridge was wrong

}  // namespace remote
}  // namespace firestore
}  // namespace firebase