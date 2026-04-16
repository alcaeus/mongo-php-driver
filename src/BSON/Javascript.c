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

#include "bson/bson.h"

#include <php.h>
#include <Zend/zend_interfaces.h>

#include "phongo.h"
#include "phongo_bson_encode.h"
#include "phongo_error.h"
#include "Javascript_arginfo.h"

zend_class_entry* phongo_javascript_ce;

static void phongo_javascript_update_properties(phongo_javascript_t* intern)
{
	zend_update_property_stringl(phongo_javascript_ce, &intern->std, ZEND_STRL("code"), intern->code, intern->code_len);

	if (intern->scope && intern->scope->len) {
		phongo_bson_state state;

		PHONGO_BSON_INIT_STATE(state);

		if (!phongo_bson_to_zval_ex(intern->scope, &state)) {
			zval_ptr_dtor(&state.zchild);
			zend_update_property_null(phongo_javascript_ce, &intern->std, ZEND_STRL("scope"));
			return;
		}

		zend_update_property(phongo_javascript_ce, &intern->std, ZEND_STRL("scope"), &state.zchild);
		zval_ptr_dtor(&state.zchild);
	} else {
		zend_update_property_null(phongo_javascript_ce, &intern->std, ZEND_STRL("scope"));
	}
}

/* Initialize the object and return whether it was successful. An exception will
 * be thrown on error. */
static bool phongo_javascript_init(phongo_javascript_t* intern, const char* code, size_t code_len, zval* scope)
{
	if (scope && Z_TYPE_P(scope) != IS_OBJECT && Z_TYPE_P(scope) != IS_ARRAY && Z_TYPE_P(scope) != IS_NULL) {
		phongo_throw_exception(PHONGO_ERROR_INVALID_ARGUMENT, "Expected scope to be array or object, %s given", zend_get_type_by_const(Z_TYPE_P(scope)));
		return false;
	}

	if (strlen(code) != (size_t) code_len) {
		phongo_throw_exception(PHONGO_ERROR_INVALID_ARGUMENT, "Code cannot contain null bytes");
		return false;
	}

	intern->code     = estrndup(code, code_len);
	intern->code_len = code_len;

	if (scope && (Z_TYPE_P(scope) == IS_OBJECT || Z_TYPE_P(scope) == IS_ARRAY)) {
		intern->scope = bson_new();
		phongo_zval_to_bson(scope, PHONGO_BSON_NONE, intern->scope, NULL);
	} else {
		intern->scope = NULL;
	}

	phongo_javascript_update_properties(intern);

	return true;
}

/* Initialize the object from a HashTable and return whether it was successful.
 * An exception will be thrown on error. */
static bool phongo_javascript_init_from_hash(phongo_javascript_t* intern, HashTable* props)
{
	zval *code, *scope;

	if ((code = zend_hash_str_find(props, "code", sizeof("code") - 1)) && Z_TYPE_P(code) == IS_STRING) {
		scope = zend_hash_str_find(props, "scope", sizeof("scope") - 1);

		return phongo_javascript_init(intern, Z_STRVAL_P(code), Z_STRLEN_P(code), scope);
	}

	phongo_throw_exception(PHONGO_ERROR_INVALID_ARGUMENT, "%s initialization requires \"code\" string field", ZSTR_VAL(phongo_javascript_ce->name));
	return false;
}

/* Construct a new BSON Javascript type. The scope is a document mapping
   identifiers and values, representing the scope in which the code string will
   be evaluated. Note that this type cannot be represented as Extended JSON. */
static PHP_METHOD(MongoDB_BSON_Javascript, __construct)
{
	PHONGO_INTERN_FROM_THIS(javascript);

	char*  code;
	size_t code_len;
	zval*  scope = NULL;

	PHONGO_PARSE_PARAMETERS_START(1, 2)
	Z_PARAM_STRING(code, code_len)
	Z_PARAM_OPTIONAL
	Z_PARAM_ARRAY_OR_OBJECT_EX(scope, 1, 0)
	PHONGO_PARSE_PARAMETERS_END();

	phongo_javascript_init(intern, code, code_len, scope);
}

static PHP_METHOD(MongoDB_BSON_Javascript, __set_state)
{
	HashTable* props;
	zval*      array;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_ARRAY(array)
	PHONGO_PARSE_PARAMETERS_END();

	PHONGO_INTERN_INIT_EX(javascript, return_value);
	props = Z_ARRVAL_P(array);

	phongo_javascript_init_from_hash(intern, props);
}

/* Return the Javascript's code string. */
static PHP_METHOD(MongoDB_BSON_Javascript, __toString)
{
	PHONGO_INTERN_FROM_THIS(javascript);

	PHONGO_PARSE_PARAMETERS_NONE();

	RETURN_STRINGL(intern->code, intern->code_len);
}

static PHP_METHOD(MongoDB_BSON_Javascript, getCode)
{
	PHONGO_INTERN_FROM_THIS(javascript);

	PHONGO_PARSE_PARAMETERS_NONE();

	RETURN_STRINGL(intern->code, intern->code_len);
}

static PHP_METHOD(MongoDB_BSON_Javascript, getScope)
{
	PHONGO_INTERN_FROM_THIS(javascript);

	PHONGO_PARSE_PARAMETERS_NONE();

	if (!intern->scope) {
		RETURN_NULL();
	}

	if (intern->scope->len) {
		phongo_bson_state state;

		PHONGO_BSON_INIT_STATE(state);

		if (!phongo_bson_to_zval_ex(intern->scope, &state)) {
			zval_ptr_dtor(&state.zchild);
			return;
		}

		RETURN_ZVAL(&state.zchild, 0, 1);
	} else {
		RETURN_NULL();
	}
}

static PHP_METHOD(MongoDB_BSON_Javascript, jsonSerialize)
{
	PHONGO_INTERN_FROM_THIS(javascript);

	PHONGO_PARSE_PARAMETERS_NONE();

	array_init_size(return_value, 2);
	ADD_ASSOC_STRINGL(return_value, "$code", intern->code, intern->code_len);

	if (intern->scope && intern->scope->len) {
		phongo_bson_state state;

		PHONGO_BSON_INIT_STATE(state);
		if (!phongo_bson_to_zval_ex(intern->scope, &state)) {
			zval_ptr_dtor(&state.zchild);
			return;
		}

		ADD_ASSOC_ZVAL_EX(return_value, "$scope", &state.zchild);
	}
}

static PHP_METHOD(MongoDB_BSON_Javascript, __serialize)
{
	PHONGO_INTERN_FROM_THIS(javascript);

	PHONGO_PARSE_PARAMETERS_NONE();

	array_init_size(return_value, 2);
	ADD_ASSOC_STRINGL(return_value, "code", intern->code, intern->code_len);

	if (intern->scope && intern->scope->len) {
		phongo_bson_state state;

		PHONGO_BSON_INIT_STATE(state);

		if (!phongo_bson_to_zval_ex(intern->scope, &state)) {
			zval_ptr_dtor(&state.zchild);
			return;
		}

		ADD_ASSOC_ZVAL_EX(return_value, "scope", &state.zchild);
	} else {
		add_assoc_null(return_value, "scope");
	}
}

static PHP_METHOD(MongoDB_BSON_Javascript, __unserialize)
{
	zval* data;

	PHONGO_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_ARRAY(data)
	PHONGO_PARSE_PARAMETERS_END();

	phongo_javascript_init_from_hash(Z_JAVASCRIPT_OBJ_P(getThis()), Z_ARRVAL_P(data));
}

/* MongoDB\BSON\Javascript object handlers */
static zend_object_handlers phongo_handler_javascript;

static void phongo_javascript_free_object(zend_object* object)
{
	PHONGO_INTERN_FROM_Z_OBJ(javascript, object);

	zend_object_std_dtor(&intern->std);

	if (intern->code) {
		efree(intern->code);
	}
	if (intern->scope) {
		bson_destroy(intern->scope);
		intern->scope = NULL;
	}
}

zend_object* phongo_javascript_create_object(zend_class_entry* class_type)
{
	PHONGO_INTERN_OBJECT_ALLOC(javascript, class_type);

	intern->std.handlers = &phongo_handler_javascript;

	return &intern->std;
}

static zend_object* phongo_javascript_clone_object(zend_object* object)
{
	PHONGO_INTERN_FROM_Z_OBJ(javascript, object);

	phongo_javascript_t* new_intern;
	zend_object*         new_object;

	new_object = phongo_javascript_create_object(object->ce);

	new_intern = Z_OBJ_JAVASCRIPT(new_object);
	zend_objects_clone_members(&new_intern->std, &intern->std);

	/* Copy C struct fields directly; zend_objects_clone_members already
	 * copied the native read-only properties from the original. */
	new_intern->code     = estrndup(intern->code, intern->code_len);
	new_intern->code_len = intern->code_len;
	new_intern->scope    = intern->scope ? bson_copy(intern->scope) : NULL;

	return new_object;
}

static int phongo_javascript_compare_objects(zval* o1, zval* o2)
{
	phongo_javascript_t *intern1, *intern2;

	ZEND_COMPARE_OBJECTS_FALLBACK(o1, o2);

	intern1 = Z_JAVASCRIPT_OBJ_P(o1);
	intern2 = Z_JAVASCRIPT_OBJ_P(o2);

	/* Do not consider the scope document for comparisons */
	return strcmp(intern1->code, intern2->code);
}

void phongo_javascript_init_ce(INIT_FUNC_ARGS)
{
	phongo_javascript_ce                = register_class_MongoDB_BSON_Javascript(phongo_javascript_interface_ce, phongo_json_serializable_ce, phongo_type_ce, zend_ce_stringable);
	phongo_javascript_ce->create_object = phongo_javascript_create_object;

	memcpy(&phongo_handler_javascript, phongo_get_std_object_handlers(), sizeof(zend_object_handlers));
	phongo_handler_javascript.compare   = phongo_javascript_compare_objects;
	phongo_handler_javascript.clone_obj = phongo_javascript_clone_object;
	phongo_handler_javascript.free_obj  = phongo_javascript_free_object;
	phongo_handler_javascript.offset    = XtOffsetOf(phongo_javascript_t, std);
}

bool phongo_javascript_new(zval* object, const char* code, size_t code_len, const bson_t* scope)
{
	if (scope) {
		phongo_bson_state state;
		bool              valid_scope;

		PHONGO_BSON_INIT_STATE(state);

		valid_scope = phongo_bson_to_zval_ex(scope, &state);
		zval_ptr_dtor(&state.zchild);

		if (!valid_scope) {
			return false;
		}
	}

	PHONGO_INTERN_INIT_EX(javascript, object);
	intern->code     = estrndup(code, code_len);
	intern->code_len = code_len;
	intern->scope    = scope ? bson_copy(scope) : NULL;

	phongo_javascript_update_properties(intern);

	return true;
}
