/*
 * Copyright 2014-present MongoDB, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <php.h>
#include <zend_smart_str.h>
#include <ext/standard/php_var.h>
#include <Zend/zend_interfaces.h>

#include "php_phongo.h"
#include "phongo_error.h"
#include "DocumentWriter_arginfo.h"

zend_class_entry* php_phongo_documentwriter_ce;

static bool phongo_documentwriter_fetch_key(php_phongo_documentwriter_t* writer, char** key, size_t* key_len)
{
	if (!writer->key) {
		phongo_throw_exception(PHONGO_ERROR_LOGIC, "Cannot write a value without a key");
		return false;
	}

	*key     = writer->key;
	*key_len = writer->key_len;

	return true;
}

static void phongo_documentwriter_clear_key(php_phongo_documentwriter_t* writer)
{
	if (!writer->key) {
		return;
	}

	efree(writer->key);
	writer->key = NULL;
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, write)
{
	php_phongo_documentwriter_t* intern;
	php_phongo_document_t*       document_intern;
	zval                         document;

	PHONGO_PARSE_PARAMETERS_NONE();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	object_init_ex(&document, php_phongo_document_ce);

	document_intern       = Z_DOCUMENT_OBJ_P(&document);
	document_intern->bson = bson_copy(intern->bson);

	RETURN_ZVAL(&document, 1, 1);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeKey)
{
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_STRING(key, key_len)
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	phongo_documentwriter_clear_key(intern);

	intern->key     = estrdup(key);
	intern->key_len = key_len;

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeBoolean)
{
	zend_bool                    value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_BOOL(value)
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_bool(intern->bson, key, key_len, value);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeDouble)
{
	double                       value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(value);
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_double(intern->bson, key, key_len, value);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeInt)
{
	zval*                        value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_ZVAL(value)
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	if (Z_TYPE_P(value) == IS_LONG) {
		zend_long lvalue = Z_LVAL_P(value);
		// Append int. On 32-bit platforms, this will always be an int32
		if (SIZEOF_ZEND_LONG == 8 && (lvalue > INT32_MAX || lvalue < INT32_MIN)) {
			bson_append_int64(intern->bson, key, key_len, lvalue);
		} else {
			bson_append_int32(intern->bson, key, key_len, lvalue);
		}
	} else if (Z_TYPE_P(value) == IS_OBJECT && instanceof_function(Z_OBJCE_P(value), php_phongo_int64_ce)) {
		bson_append_int64(intern->bson, key, key_len, Z_INT64_OBJ_P(value)->integer);
	} else {
		phongo_throw_exception(PHONGO_ERROR_INVALID_ARGUMENT, "Expected value to be int or %s, %s given", ZSTR_VAL(php_phongo_int64_ce->name), PHONGO_ZVAL_CLASS_OR_TYPE_NAME_P(value));
		return;
	}

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeNull)
{
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_NONE();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_null(intern->bson, key, key_len);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeString)
{
	char*                        value;
	size_t                       value_len;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_STRING(value, value_len)
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_utf8(intern->bson, key, key_len, value, value_len);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeBinary)
{
	zval*                        value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;
	php_phongo_binary_t*         binary_intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_OBJECT_OF_CLASS(value, php_phongo_binary_interface_ce)
	PHONGO_PARSE_PARAMETERS_END();

	intern        = Z_DOCUMENTWRITER_OBJ_P(getThis());
	binary_intern = Z_BINARY_OBJ_P(value);

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_binary(intern->bson, key, key_len, binary_intern->type, (const uint8_t*) binary_intern->data, (uint32_t) binary_intern->data_len);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeDecimal128)
{
	zval*                        value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_OBJECT_OF_CLASS(value, php_phongo_decimal128_interface_ce)
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_decimal128(intern->bson, key, key_len, &(Z_DECIMAL128_OBJ_P(value)->decimal));

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeInt32)
{
	zend_long                    value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_LONG(value);
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	if (SIZEOF_ZEND_LONG == 8 && (value > INT32_MAX || value < INT32_MIN)) {
		phongo_throw_exception(PHONGO_ERROR_INVALID_ARGUMENT, "Cannot write a 64-bit integer value as int32");
		return;
	}

	bson_append_int32(intern->bson, key, key_len, value);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeInt64)
{
	zval*                        value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_ZVAL(value)
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	if (Z_TYPE_P(value) == IS_LONG) {
		bson_append_int64(intern->bson, key, key_len, Z_LVAL_P(value));
	} else if (Z_TYPE_P(value) == IS_OBJECT && instanceof_function(Z_OBJCE_P(value), php_phongo_int64_ce)) {
		bson_append_int64(intern->bson, key, key_len, Z_INT64_OBJ_P(value)->integer);
	} else {
		phongo_throw_exception(PHONGO_ERROR_INVALID_ARGUMENT, "Expected value to be int or %s, %s given", ZSTR_VAL(php_phongo_int64_ce->name), PHONGO_ZVAL_CLASS_OR_TYPE_NAME_P(value));
		return;
	}

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeJavascript)
{
	zval*                        value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;
	php_phongo_javascript_t*     javascript_intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_OBJECT_OF_CLASS(value, php_phongo_javascript_interface_ce)
	PHONGO_PARSE_PARAMETERS_END();

	intern            = Z_DOCUMENTWRITER_OBJ_P(getThis());
	javascript_intern = Z_JAVASCRIPT_OBJ_P(value);

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	if (javascript_intern->scope) {
		bson_append_code_with_scope(intern->bson, key, key_len, javascript_intern->code, javascript_intern->scope);
	} else {
		bson_append_code(intern->bson, key, key_len, javascript_intern->code);
	}

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeMaxKey)
{
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_NONE();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_maxkey(intern->bson, key, key_len);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeMinKey)
{
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_NONE();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_minkey(intern->bson, key, key_len);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeObjectId)
{
	zval*                        value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;
	bson_oid_t                   oid;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_OBJECT_OF_CLASS(value, php_phongo_objectid_interface_ce)
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());
	bson_oid_init_from_string(&oid, Z_OBJECTID_OBJ_P(value)->oid);

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_oid(intern->bson, key, key_len, &oid);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeRegularExpression)
{
	zval*                        value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;
	php_phongo_regex_t*          regex_intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_OBJECT_OF_CLASS(value, php_phongo_regex_interface_ce)
	PHONGO_PARSE_PARAMETERS_END();

	intern       = Z_DOCUMENTWRITER_OBJ_P(getThis());
	regex_intern = Z_REGEX_OBJ_P(value);

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_regex(intern->bson, key, key_len, regex_intern->pattern, regex_intern->flags);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeTimestamp)
{
	zval*                        value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;
	php_phongo_timestamp_t*      timestamp_intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_OBJECT_OF_CLASS(value, php_phongo_timestamp_interface_ce)
	PHONGO_PARSE_PARAMETERS_END();

	intern           = Z_DOCUMENTWRITER_OBJ_P(getThis());
	timestamp_intern = Z_TIMESTAMP_OBJ_P(value);

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_timestamp(intern->bson, key, key_len, timestamp_intern->timestamp, timestamp_intern->increment);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeUTCDateTime)
{
	zval*                        value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_OBJECT_OF_CLASS(value, php_phongo_utcdatetime_interface_ce)
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_date_time(intern->bson, key, key_len, Z_UTCDATETIME_OBJ_P(value)->milliseconds);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeArray)
{
	zval*                        value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_OBJECT_OF_CLASS(value, php_phongo_arraylist_ce)
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_array(intern->bson, key, key_len, Z_ARRAYLIST_OBJ_P(value)->bson);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

static PHP_METHOD(MongoDB_BSON_DocumentWriter, writeDocument)
{
	zval*                        value;
	char*                        key;
	size_t                       key_len;
	php_phongo_documentwriter_t* intern;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_OBJECT_OF_CLASS(value, php_phongo_document_ce)
	PHONGO_PARSE_PARAMETERS_END();

	intern = Z_DOCUMENTWRITER_OBJ_P(getThis());

	if (!phongo_documentwriter_fetch_key(intern, &key, &key_len)) {
		/* Exception already thrown */
		return;
	}

	bson_append_document(intern->bson, key, key_len, Z_DOCUMENT_OBJ_P(value)->bson);

	phongo_documentwriter_clear_key(intern);

	RETURN_ZVAL(getThis(), 1, 0);
}

/* MongoDB\BSON\DocumentWriter object handlers */
static zend_object_handlers php_phongo_handler_documentwriter;

static void php_phongo_documentwriter_free_object(zend_object* object)
{
	php_phongo_documentwriter_t* intern = Z_OBJ_DOCUMENTWRITER(object);

	bson_destroy(intern->bson);
	phongo_documentwriter_clear_key(intern);

	zend_object_std_dtor(&intern->std);
}

static zend_object* php_phongo_documentwriter_create_object(zend_class_entry* class_type)
{
	php_phongo_documentwriter_t* intern = zend_object_alloc(sizeof(php_phongo_documentwriter_t), class_type);

	zend_object_std_init(&intern->std, class_type);
	object_properties_init(&intern->std, class_type);

	intern->std.handlers = &php_phongo_handler_documentwriter;
	intern->bson         = bson_new();

	return &intern->std;
}

void php_phongo_documentwriter_init_ce(INIT_FUNC_ARGS)
{
	php_phongo_documentwriter_ce                = register_class_MongoDB_BSON_DocumentWriter();
	php_phongo_documentwriter_ce->create_object = php_phongo_documentwriter_create_object;

	memcpy(&php_phongo_handler_documentwriter, phongo_get_std_object_handlers(), sizeof(zend_object_handlers));
	/* Re-assign default handler previously removed in php_phongo.c */
	php_phongo_handler_documentwriter.clone_obj = zend_objects_clone_obj;
	php_phongo_handler_documentwriter.free_obj  = php_phongo_documentwriter_free_object;
	php_phongo_handler_documentwriter.offset    = XtOffsetOf(php_phongo_documentwriter_t, std);
}
