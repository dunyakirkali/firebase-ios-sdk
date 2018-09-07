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

/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 */

#ifndef PB_GOOGLE_FIRESTORE_V1BETA1_COMMON_NANOPB_H_INCLUDED
#define PB_GOOGLE_FIRESTORE_V1BETA1_COMMON_NANOPB_H_INCLUDED
#include <pb.h>

#include "google/api/annotations.nanopb.h"

#include "google/protobuf/timestamp.nanopb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _google_firestore_v1beta1_DocumentMask {
    pb_size_t field_paths_count;
    char **field_paths;
/* @@protoc_insertion_point(struct:google_firestore_v1beta1_DocumentMask) */
} google_firestore_v1beta1_DocumentMask;

typedef struct _google_firestore_v1beta1_TransactionOptions_ReadWrite {
    pb_bytes_array_t *retry_transaction;
/* @@protoc_insertion_point(struct:google_firestore_v1beta1_TransactionOptions_ReadWrite) */
} google_firestore_v1beta1_TransactionOptions_ReadWrite;

typedef struct _google_firestore_v1beta1_Precondition {
    pb_size_t which_condition_type;
    union {
        bool exists;
        google_protobuf_Timestamp update_time;
    } condition_type;
/* @@protoc_insertion_point(struct:google_firestore_v1beta1_Precondition) */
} google_firestore_v1beta1_Precondition;

typedef struct _google_firestore_v1beta1_TransactionOptions_ReadOnly {
    pb_size_t which_consistency_selector;
    union {
        google_protobuf_Timestamp read_time;
    } consistency_selector;
/* @@protoc_insertion_point(struct:google_firestore_v1beta1_TransactionOptions_ReadOnly) */
} google_firestore_v1beta1_TransactionOptions_ReadOnly;

typedef struct _google_firestore_v1beta1_TransactionOptions {
    pb_size_t which_mode;
    union {
        google_firestore_v1beta1_TransactionOptions_ReadOnly read_only;
        google_firestore_v1beta1_TransactionOptions_ReadWrite read_write;
    } mode;
/* @@protoc_insertion_point(struct:google_firestore_v1beta1_TransactionOptions) */
} google_firestore_v1beta1_TransactionOptions;

/* Default values for struct fields */

/* Initializer values for message structs */
#define google_firestore_v1beta1_DocumentMask_init_default {0, NULL}
#define google_firestore_v1beta1_Precondition_init_default {0, {0}}
#define google_firestore_v1beta1_TransactionOptions_init_default {0, {google_firestore_v1beta1_TransactionOptions_ReadOnly_init_default}}
#define google_firestore_v1beta1_TransactionOptions_ReadWrite_init_default {NULL}
#define google_firestore_v1beta1_TransactionOptions_ReadOnly_init_default {0, {google_protobuf_Timestamp_init_default}}
#define google_firestore_v1beta1_DocumentMask_init_zero {0, NULL}
#define google_firestore_v1beta1_Precondition_init_zero {0, {0}}
#define google_firestore_v1beta1_TransactionOptions_init_zero {0, {google_firestore_v1beta1_TransactionOptions_ReadOnly_init_zero}}
#define google_firestore_v1beta1_TransactionOptions_ReadWrite_init_zero {NULL}
#define google_firestore_v1beta1_TransactionOptions_ReadOnly_init_zero {0, {google_protobuf_Timestamp_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define google_firestore_v1beta1_DocumentMask_field_paths_tag 1
#define google_firestore_v1beta1_TransactionOptions_ReadWrite_retry_transaction_tag 1
#define google_firestore_v1beta1_Precondition_exists_tag 1
#define google_firestore_v1beta1_Precondition_update_time_tag 2
#define google_firestore_v1beta1_TransactionOptions_ReadOnly_read_time_tag 2
#define google_firestore_v1beta1_TransactionOptions_read_only_tag 2
#define google_firestore_v1beta1_TransactionOptions_read_write_tag 3

/* Struct field encoding specification for nanopb */
extern const pb_field_t google_firestore_v1beta1_DocumentMask_fields[2];
extern const pb_field_t google_firestore_v1beta1_Precondition_fields[3];
extern const pb_field_t google_firestore_v1beta1_TransactionOptions_fields[3];
extern const pb_field_t google_firestore_v1beta1_TransactionOptions_ReadWrite_fields[2];
extern const pb_field_t google_firestore_v1beta1_TransactionOptions_ReadOnly_fields[2];

/* Maximum encoded size of messages (where known) */
/* google_firestore_v1beta1_DocumentMask_size depends on runtime parameters */
#define google_firestore_v1beta1_Precondition_size 24
#define google_firestore_v1beta1_TransactionOptions_size (0 + (google_firestore_v1beta1_TransactionOptions_ReadWrite_size > 26 ? google_firestore_v1beta1_TransactionOptions_ReadWrite_size : 26))
/* google_firestore_v1beta1_TransactionOptions_ReadWrite_size depends on runtime parameters */
#define google_firestore_v1beta1_TransactionOptions_ReadOnly_size 24

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define COMMON_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
