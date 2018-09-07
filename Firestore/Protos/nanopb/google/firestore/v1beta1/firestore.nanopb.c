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

/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.1 */

#include "firestore.nanopb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t google_firestore_v1beta1_GetDocumentRequest_fields[5] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_GetDocumentRequest, name, name, 0),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_GetDocumentRequest, mask, name, &google_firestore_v1beta1_DocumentMask_fields),
    PB_ONEOF_FIELD(consistency_selector,   3, BYTES   , ONEOF, POINTER , OTHER, google_firestore_v1beta1_GetDocumentRequest, transaction, mask, 0),
    PB_ONEOF_FIELD(consistency_selector,   5, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_GetDocumentRequest, read_time, mask, &google_protobuf_Timestamp_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_ListDocumentsRequest_fields[10] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_ListDocumentsRequest, parent, parent, 0),
    PB_FIELD(  2, STRING  , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_ListDocumentsRequest, collection_id, parent, 0),
    PB_FIELD(  3, INT32   , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_ListDocumentsRequest, page_size, collection_id, 0),
    PB_FIELD(  4, STRING  , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_ListDocumentsRequest, page_token, page_size, 0),
    PB_FIELD(  6, STRING  , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_ListDocumentsRequest, order_by, page_token, 0),
    PB_FIELD(  7, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_ListDocumentsRequest, mask, order_by, &google_firestore_v1beta1_DocumentMask_fields),
    PB_ONEOF_FIELD(consistency_selector,   8, BYTES   , ONEOF, POINTER , OTHER, google_firestore_v1beta1_ListDocumentsRequest, transaction, mask, 0),
    PB_ONEOF_FIELD(consistency_selector,  10, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_ListDocumentsRequest, read_time, mask, &google_protobuf_Timestamp_fields),
    PB_FIELD( 12, BOOL    , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_ListDocumentsRequest, show_missing, consistency_selector.read_time, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_ListDocumentsResponse_fields[3] = {
    PB_FIELD(  1, MESSAGE , REPEATED, POINTER , FIRST, google_firestore_v1beta1_ListDocumentsResponse, documents, documents, &google_firestore_v1beta1_Document_fields),
    PB_FIELD(  2, STRING  , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_ListDocumentsResponse, next_page_token, documents, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_CreateDocumentRequest_fields[6] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_CreateDocumentRequest, parent, parent, 0),
    PB_FIELD(  2, STRING  , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_CreateDocumentRequest, collection_id, parent, 0),
    PB_FIELD(  3, STRING  , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_CreateDocumentRequest, document_id, collection_id, 0),
    PB_FIELD(  4, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_CreateDocumentRequest, document, document_id, &google_firestore_v1beta1_Document_fields),
    PB_FIELD(  5, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_CreateDocumentRequest, mask, document, &google_firestore_v1beta1_DocumentMask_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_UpdateDocumentRequest_fields[5] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, google_firestore_v1beta1_UpdateDocumentRequest, document, document, &google_firestore_v1beta1_Document_fields),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_UpdateDocumentRequest, update_mask, document, &google_firestore_v1beta1_DocumentMask_fields),
    PB_FIELD(  3, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_UpdateDocumentRequest, mask, update_mask, &google_firestore_v1beta1_DocumentMask_fields),
    PB_FIELD(  4, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_UpdateDocumentRequest, current_document, mask, &google_firestore_v1beta1_Precondition_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_DeleteDocumentRequest_fields[3] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_DeleteDocumentRequest, name, name, 0),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_DeleteDocumentRequest, current_document, name, &google_firestore_v1beta1_Precondition_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_BatchGetDocumentsRequest_fields[7] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_BatchGetDocumentsRequest, database, database, 0),
    PB_FIELD(  2, STRING  , REPEATED, POINTER , OTHER, google_firestore_v1beta1_BatchGetDocumentsRequest, documents, database, 0),
    PB_FIELD(  3, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_BatchGetDocumentsRequest, mask, documents, &google_firestore_v1beta1_DocumentMask_fields),
    PB_ONEOF_FIELD(consistency_selector,   4, BYTES   , ONEOF, POINTER , OTHER, google_firestore_v1beta1_BatchGetDocumentsRequest, transaction, mask, 0),
    PB_ONEOF_FIELD(consistency_selector,   5, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_BatchGetDocumentsRequest, new_transaction, mask, &google_firestore_v1beta1_TransactionOptions_fields),
    PB_ONEOF_FIELD(consistency_selector,   7, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_BatchGetDocumentsRequest, read_time, mask, &google_protobuf_Timestamp_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_BatchGetDocumentsResponse_fields[5] = {
    PB_ONEOF_FIELD(result,   1, MESSAGE , ONEOF, STATIC  , FIRST, google_firestore_v1beta1_BatchGetDocumentsResponse, found, found, &google_firestore_v1beta1_Document_fields),
    PB_ONEOF_FIELD(result,   2, STRING  , ONEOF, POINTER , UNION, google_firestore_v1beta1_BatchGetDocumentsResponse, missing, missing, 0),
    PB_FIELD(  3, BYTES   , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_BatchGetDocumentsResponse, transaction, result.missing, 0),
    PB_FIELD(  4, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_BatchGetDocumentsResponse, read_time, transaction, &google_protobuf_Timestamp_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_BeginTransactionRequest_fields[3] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_BeginTransactionRequest, database, database, 0),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_BeginTransactionRequest, options, database, &google_firestore_v1beta1_TransactionOptions_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_BeginTransactionResponse_fields[2] = {
    PB_FIELD(  1, BYTES   , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_BeginTransactionResponse, transaction, transaction, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_CommitRequest_fields[4] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_CommitRequest, database, database, 0),
    PB_FIELD(  2, MESSAGE , REPEATED, POINTER , OTHER, google_firestore_v1beta1_CommitRequest, writes, database, &google_firestore_v1beta1_Write_fields),
    PB_FIELD(  3, BYTES   , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_CommitRequest, transaction, writes, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_CommitResponse_fields[3] = {
    PB_FIELD(  1, MESSAGE , REPEATED, POINTER , FIRST, google_firestore_v1beta1_CommitResponse, write_results, write_results, &google_firestore_v1beta1_WriteResult_fields),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_CommitResponse, commit_time, write_results, &google_protobuf_Timestamp_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_RollbackRequest_fields[3] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_RollbackRequest, database, database, 0),
    PB_FIELD(  2, BYTES   , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_RollbackRequest, transaction, database, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_RunQueryRequest_fields[6] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_RunQueryRequest, parent, parent, 0),
    PB_ONEOF_FIELD(query_type,   2, MESSAGE , ONEOF, STATIC  , OTHER, google_firestore_v1beta1_RunQueryRequest, structured_query, parent, &google_firestore_v1beta1_StructuredQuery_fields),
    PB_ONEOF_FIELD(consistency_selector,   5, BYTES   , ONEOF, POINTER , OTHER, google_firestore_v1beta1_RunQueryRequest, transaction, query_type.structured_query, 0),
    PB_ONEOF_FIELD(consistency_selector,   6, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_RunQueryRequest, new_transaction, query_type.structured_query, &google_firestore_v1beta1_TransactionOptions_fields),
    PB_ONEOF_FIELD(consistency_selector,   7, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_RunQueryRequest, read_time, query_type.structured_query, &google_protobuf_Timestamp_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_RunQueryResponse_fields[5] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, google_firestore_v1beta1_RunQueryResponse, document, document, &google_firestore_v1beta1_Document_fields),
    PB_FIELD(  2, BYTES   , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_RunQueryResponse, transaction, document, 0),
    PB_FIELD(  3, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_RunQueryResponse, read_time, transaction, &google_protobuf_Timestamp_fields),
    PB_FIELD(  4, INT32   , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_RunQueryResponse, skipped_results, read_time, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_WriteRequest_fields[6] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_WriteRequest, database, database, 0),
    PB_FIELD(  2, STRING  , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_WriteRequest, stream_id, database, 0),
    PB_FIELD(  3, MESSAGE , REPEATED, POINTER , OTHER, google_firestore_v1beta1_WriteRequest, writes, stream_id, &google_firestore_v1beta1_Write_fields),
    PB_FIELD(  4, BYTES   , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_WriteRequest, stream_token, writes, 0),
    PB_FIELD(  5, MESSAGE , REPEATED, POINTER , OTHER, google_firestore_v1beta1_WriteRequest, labels, stream_token, &google_firestore_v1beta1_WriteRequest_LabelsEntry_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_WriteRequest_LabelsEntry_fields[3] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_WriteRequest_LabelsEntry, key, key, 0),
    PB_FIELD(  2, STRING  , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_WriteRequest_LabelsEntry, value, key, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_WriteResponse_fields[5] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_WriteResponse, stream_id, stream_id, 0),
    PB_FIELD(  2, BYTES   , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_WriteResponse, stream_token, stream_id, 0),
    PB_FIELD(  3, MESSAGE , REPEATED, POINTER , OTHER, google_firestore_v1beta1_WriteResponse, write_results, stream_token, &google_firestore_v1beta1_WriteResult_fields),
    PB_FIELD(  4, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_WriteResponse, commit_time, write_results, &google_protobuf_Timestamp_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_ListenRequest_fields[5] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_ListenRequest, database, database, 0),
    PB_ONEOF_FIELD(target_change,   2, MESSAGE , ONEOF, STATIC  , OTHER, google_firestore_v1beta1_ListenRequest, add_target, database, &google_firestore_v1beta1_Target_fields),
    PB_ONEOF_FIELD(target_change,   3, INT32   , ONEOF, STATIC  , UNION, google_firestore_v1beta1_ListenRequest, remove_target, database, 0),
    PB_FIELD(  4, MESSAGE , REPEATED, POINTER , OTHER, google_firestore_v1beta1_ListenRequest, labels, target_change.remove_target, &google_firestore_v1beta1_ListenRequest_LabelsEntry_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_ListenRequest_LabelsEntry_fields[3] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_ListenRequest_LabelsEntry, key, key, 0),
    PB_FIELD(  2, STRING  , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_ListenRequest_LabelsEntry, value, key, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_ListenResponse_fields[6] = {
    PB_ONEOF_FIELD(response_type,   2, MESSAGE , ONEOF, STATIC  , FIRST, google_firestore_v1beta1_ListenResponse, target_change, target_change, &google_firestore_v1beta1_TargetChange_fields),
    PB_ONEOF_FIELD(response_type,   3, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_ListenResponse, document_change, document_change, &google_firestore_v1beta1_DocumentChange_fields),
    PB_ONEOF_FIELD(response_type,   4, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_ListenResponse, document_delete, document_delete, &google_firestore_v1beta1_DocumentDelete_fields),
    PB_ONEOF_FIELD(response_type,   5, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_ListenResponse, filter, filter, &google_firestore_v1beta1_ExistenceFilter_fields),
    PB_ONEOF_FIELD(response_type,   6, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_ListenResponse, document_remove, document_remove, &google_firestore_v1beta1_DocumentRemove_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_Target_fields[7] = {
    PB_ONEOF_FIELD(target_type,   2, MESSAGE , ONEOF, STATIC  , FIRST, google_firestore_v1beta1_Target, query, query, &google_firestore_v1beta1_Target_QueryTarget_fields),
    PB_ONEOF_FIELD(target_type,   3, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_Target, documents, documents, &google_firestore_v1beta1_Target_DocumentsTarget_fields),
    PB_ONEOF_FIELD(resume_type,   4, BYTES   , ONEOF, POINTER , OTHER, google_firestore_v1beta1_Target, resume_token, target_type.documents, 0),
    PB_ONEOF_FIELD(resume_type,  11, MESSAGE , ONEOF, STATIC  , UNION, google_firestore_v1beta1_Target, read_time, target_type.documents, &google_protobuf_Timestamp_fields),
    PB_FIELD(  5, INT32   , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Target, target_id, resume_type.read_time, 0),
    PB_FIELD(  6, BOOL    , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_Target, once, target_id, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_Target_DocumentsTarget_fields[2] = {
    PB_FIELD(  2, STRING  , REPEATED, POINTER , FIRST, google_firestore_v1beta1_Target_DocumentsTarget, documents, documents, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_Target_QueryTarget_fields[3] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_Target_QueryTarget, parent, parent, 0),
    PB_ONEOF_FIELD(query_type,   2, MESSAGE , ONEOF, STATIC  , OTHER, google_firestore_v1beta1_Target_QueryTarget, structured_query, parent, &google_firestore_v1beta1_StructuredQuery_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_TargetChange_fields[6] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, google_firestore_v1beta1_TargetChange, target_change_type, target_change_type, 0),
    PB_FIELD(  2, INT32   , REPEATED, POINTER , OTHER, google_firestore_v1beta1_TargetChange, target_ids, target_change_type, 0),
    PB_FIELD(  3, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_TargetChange, cause, target_ids, &google_rpc_Status_fields),
    PB_FIELD(  4, BYTES   , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_TargetChange, resume_token, cause, 0),
    PB_FIELD(  6, MESSAGE , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_TargetChange, read_time, resume_token, &google_protobuf_Timestamp_fields),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_ListCollectionIdsRequest_fields[4] = {
    PB_FIELD(  1, STRING  , SINGULAR, POINTER , FIRST, google_firestore_v1beta1_ListCollectionIdsRequest, parent, parent, 0),
    PB_FIELD(  2, INT32   , SINGULAR, STATIC  , OTHER, google_firestore_v1beta1_ListCollectionIdsRequest, page_size, parent, 0),
    PB_FIELD(  3, STRING  , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_ListCollectionIdsRequest, page_token, page_size, 0),
    PB_LAST_FIELD
};

const pb_field_t google_firestore_v1beta1_ListCollectionIdsResponse_fields[3] = {
    PB_FIELD(  1, STRING  , REPEATED, POINTER , FIRST, google_firestore_v1beta1_ListCollectionIdsResponse, collection_ids, collection_ids, 0),
    PB_FIELD(  2, STRING  , SINGULAR, POINTER , OTHER, google_firestore_v1beta1_ListCollectionIdsResponse, next_page_token, collection_ids, 0),
    PB_LAST_FIELD
};



/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(google_firestore_v1beta1_GetDocumentRequest, consistency_selector.read_time) < 65536 && pb_membersize(google_firestore_v1beta1_GetDocumentRequest, mask) < 65536 && pb_membersize(google_firestore_v1beta1_ListDocumentsRequest, consistency_selector.read_time) < 65536 && pb_membersize(google_firestore_v1beta1_ListDocumentsRequest, mask) < 65536 && pb_membersize(google_firestore_v1beta1_CreateDocumentRequest, document) < 65536 && pb_membersize(google_firestore_v1beta1_CreateDocumentRequest, mask) < 65536 && pb_membersize(google_firestore_v1beta1_UpdateDocumentRequest, document) < 65536 && pb_membersize(google_firestore_v1beta1_UpdateDocumentRequest, update_mask) < 65536 && pb_membersize(google_firestore_v1beta1_UpdateDocumentRequest, mask) < 65536 && pb_membersize(google_firestore_v1beta1_UpdateDocumentRequest, current_document) < 65536 && pb_membersize(google_firestore_v1beta1_DeleteDocumentRequest, current_document) < 65536 && pb_membersize(google_firestore_v1beta1_BatchGetDocumentsRequest, consistency_selector.new_transaction) < 65536 && pb_membersize(google_firestore_v1beta1_BatchGetDocumentsRequest, consistency_selector.read_time) < 65536 && pb_membersize(google_firestore_v1beta1_BatchGetDocumentsRequest, mask) < 65536 && pb_membersize(google_firestore_v1beta1_BatchGetDocumentsResponse, result.found) < 65536 && pb_membersize(google_firestore_v1beta1_BatchGetDocumentsResponse, read_time) < 65536 && pb_membersize(google_firestore_v1beta1_BeginTransactionRequest, options) < 65536 && pb_membersize(google_firestore_v1beta1_CommitResponse, commit_time) < 65536 && pb_membersize(google_firestore_v1beta1_RunQueryRequest, query_type.structured_query) < 65536 && pb_membersize(google_firestore_v1beta1_RunQueryRequest, consistency_selector.new_transaction) < 65536 && pb_membersize(google_firestore_v1beta1_RunQueryRequest, consistency_selector.read_time) < 65536 && pb_membersize(google_firestore_v1beta1_RunQueryResponse, document) < 65536 && pb_membersize(google_firestore_v1beta1_RunQueryResponse, read_time) < 65536 && pb_membersize(google_firestore_v1beta1_WriteResponse, commit_time) < 65536 && pb_membersize(google_firestore_v1beta1_ListenRequest, target_change.add_target) < 65536 && pb_membersize(google_firestore_v1beta1_ListenResponse, response_type.target_change) < 65536 && pb_membersize(google_firestore_v1beta1_ListenResponse, response_type.document_change) < 65536 && pb_membersize(google_firestore_v1beta1_ListenResponse, response_type.document_delete) < 65536 && pb_membersize(google_firestore_v1beta1_ListenResponse, response_type.filter) < 65536 && pb_membersize(google_firestore_v1beta1_ListenResponse, response_type.document_remove) < 65536 && pb_membersize(google_firestore_v1beta1_Target, target_type.query) < 65536 && pb_membersize(google_firestore_v1beta1_Target, target_type.documents) < 65536 && pb_membersize(google_firestore_v1beta1_Target, resume_type.read_time) < 65536 && pb_membersize(google_firestore_v1beta1_Target_QueryTarget, query_type.structured_query) < 65536 && pb_membersize(google_firestore_v1beta1_TargetChange, cause) < 65536 && pb_membersize(google_firestore_v1beta1_TargetChange, read_time) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_google_firestore_v1beta1_GetDocumentRequest_google_firestore_v1beta1_ListDocumentsRequest_google_firestore_v1beta1_ListDocumentsResponse_google_firestore_v1beta1_CreateDocumentRequest_google_firestore_v1beta1_UpdateDocumentRequest_google_firestore_v1beta1_DeleteDocumentRequest_google_firestore_v1beta1_BatchGetDocumentsRequest_google_firestore_v1beta1_BatchGetDocumentsResponse_google_firestore_v1beta1_BeginTransactionRequest_google_firestore_v1beta1_BeginTransactionResponse_google_firestore_v1beta1_CommitRequest_google_firestore_v1beta1_CommitResponse_google_firestore_v1beta1_RollbackRequest_google_firestore_v1beta1_RunQueryRequest_google_firestore_v1beta1_RunQueryResponse_google_firestore_v1beta1_WriteRequest_google_firestore_v1beta1_WriteRequest_LabelsEntry_google_firestore_v1beta1_WriteResponse_google_firestore_v1beta1_ListenRequest_google_firestore_v1beta1_ListenRequest_LabelsEntry_google_firestore_v1beta1_ListenResponse_google_firestore_v1beta1_Target_google_firestore_v1beta1_Target_DocumentsTarget_google_firestore_v1beta1_Target_QueryTarget_google_firestore_v1beta1_TargetChange_google_firestore_v1beta1_ListCollectionIdsRequest_google_firestore_v1beta1_ListCollectionIdsResponse)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(google_firestore_v1beta1_GetDocumentRequest, consistency_selector.read_time) < 256 && pb_membersize(google_firestore_v1beta1_GetDocumentRequest, mask) < 256 && pb_membersize(google_firestore_v1beta1_ListDocumentsRequest, consistency_selector.read_time) < 256 && pb_membersize(google_firestore_v1beta1_ListDocumentsRequest, mask) < 256 && pb_membersize(google_firestore_v1beta1_CreateDocumentRequest, document) < 256 && pb_membersize(google_firestore_v1beta1_CreateDocumentRequest, mask) < 256 && pb_membersize(google_firestore_v1beta1_UpdateDocumentRequest, document) < 256 && pb_membersize(google_firestore_v1beta1_UpdateDocumentRequest, update_mask) < 256 && pb_membersize(google_firestore_v1beta1_UpdateDocumentRequest, mask) < 256 && pb_membersize(google_firestore_v1beta1_UpdateDocumentRequest, current_document) < 256 && pb_membersize(google_firestore_v1beta1_DeleteDocumentRequest, current_document) < 256 && pb_membersize(google_firestore_v1beta1_BatchGetDocumentsRequest, consistency_selector.new_transaction) < 256 && pb_membersize(google_firestore_v1beta1_BatchGetDocumentsRequest, consistency_selector.read_time) < 256 && pb_membersize(google_firestore_v1beta1_BatchGetDocumentsRequest, mask) < 256 && pb_membersize(google_firestore_v1beta1_BatchGetDocumentsResponse, result.found) < 256 && pb_membersize(google_firestore_v1beta1_BatchGetDocumentsResponse, read_time) < 256 && pb_membersize(google_firestore_v1beta1_BeginTransactionRequest, options) < 256 && pb_membersize(google_firestore_v1beta1_CommitResponse, commit_time) < 256 && pb_membersize(google_firestore_v1beta1_RunQueryRequest, query_type.structured_query) < 256 && pb_membersize(google_firestore_v1beta1_RunQueryRequest, consistency_selector.new_transaction) < 256 && pb_membersize(google_firestore_v1beta1_RunQueryRequest, consistency_selector.read_time) < 256 && pb_membersize(google_firestore_v1beta1_RunQueryResponse, document) < 256 && pb_membersize(google_firestore_v1beta1_RunQueryResponse, read_time) < 256 && pb_membersize(google_firestore_v1beta1_WriteResponse, commit_time) < 256 && pb_membersize(google_firestore_v1beta1_ListenRequest, target_change.add_target) < 256 && pb_membersize(google_firestore_v1beta1_ListenResponse, response_type.target_change) < 256 && pb_membersize(google_firestore_v1beta1_ListenResponse, response_type.document_change) < 256 && pb_membersize(google_firestore_v1beta1_ListenResponse, response_type.document_delete) < 256 && pb_membersize(google_firestore_v1beta1_ListenResponse, response_type.filter) < 256 && pb_membersize(google_firestore_v1beta1_ListenResponse, response_type.document_remove) < 256 && pb_membersize(google_firestore_v1beta1_Target, target_type.query) < 256 && pb_membersize(google_firestore_v1beta1_Target, target_type.documents) < 256 && pb_membersize(google_firestore_v1beta1_Target, resume_type.read_time) < 256 && pb_membersize(google_firestore_v1beta1_Target_QueryTarget, query_type.structured_query) < 256 && pb_membersize(google_firestore_v1beta1_TargetChange, cause) < 256 && pb_membersize(google_firestore_v1beta1_TargetChange, read_time) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_google_firestore_v1beta1_GetDocumentRequest_google_firestore_v1beta1_ListDocumentsRequest_google_firestore_v1beta1_ListDocumentsResponse_google_firestore_v1beta1_CreateDocumentRequest_google_firestore_v1beta1_UpdateDocumentRequest_google_firestore_v1beta1_DeleteDocumentRequest_google_firestore_v1beta1_BatchGetDocumentsRequest_google_firestore_v1beta1_BatchGetDocumentsResponse_google_firestore_v1beta1_BeginTransactionRequest_google_firestore_v1beta1_BeginTransactionResponse_google_firestore_v1beta1_CommitRequest_google_firestore_v1beta1_CommitResponse_google_firestore_v1beta1_RollbackRequest_google_firestore_v1beta1_RunQueryRequest_google_firestore_v1beta1_RunQueryResponse_google_firestore_v1beta1_WriteRequest_google_firestore_v1beta1_WriteRequest_LabelsEntry_google_firestore_v1beta1_WriteResponse_google_firestore_v1beta1_ListenRequest_google_firestore_v1beta1_ListenRequest_LabelsEntry_google_firestore_v1beta1_ListenResponse_google_firestore_v1beta1_Target_google_firestore_v1beta1_Target_DocumentsTarget_google_firestore_v1beta1_Target_QueryTarget_google_firestore_v1beta1_TargetChange_google_firestore_v1beta1_ListCollectionIdsRequest_google_firestore_v1beta1_ListCollectionIdsResponse)
#endif


/* @@protoc_insertion_point(eof) */
