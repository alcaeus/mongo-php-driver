/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: a9146db50032c40673a564835063ad223587297a */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_MongoDB_BSON_Javascript___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, code, IS_STRING, 0)
	ZEND_ARG_TYPE_MASK(0, scope, MAY_BE_ARRAY|MAY_BE_OBJECT|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Javascript___set_state, 0, 1, MongoDB\\BSON\\Javascript, 0)
	ZEND_ARG_TYPE_INFO(0, properties, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_BSON_Javascript_getCode, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_BSON_Javascript_getScope, 0, 0, IS_OBJECT, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_MongoDB_BSON_Javascript___toString arginfo_class_MongoDB_BSON_Javascript_getCode

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_BSON_Javascript___unserialize, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_BSON_Javascript_jsonSerialize, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

static ZEND_METHOD(MongoDB_BSON_Javascript, __construct);
static ZEND_METHOD(MongoDB_BSON_Javascript, __set_state);
static ZEND_METHOD(MongoDB_BSON_Javascript, getCode);
static ZEND_METHOD(MongoDB_BSON_Javascript, getScope);
static ZEND_METHOD(MongoDB_BSON_Javascript, __toString);
static ZEND_METHOD(MongoDB_BSON_Javascript, __unserialize);
static ZEND_METHOD(MongoDB_BSON_Javascript, jsonSerialize);

static const zend_function_entry class_MongoDB_BSON_Javascript_methods[] = {
	ZEND_ME(MongoDB_BSON_Javascript, __construct, arginfo_class_MongoDB_BSON_Javascript___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Javascript, __set_state, arginfo_class_MongoDB_BSON_Javascript___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Javascript, getCode, arginfo_class_MongoDB_BSON_Javascript_getCode, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Javascript, getScope, arginfo_class_MongoDB_BSON_Javascript_getScope, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Javascript, __toString, arginfo_class_MongoDB_BSON_Javascript___toString, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Javascript, __unserialize, arginfo_class_MongoDB_BSON_Javascript___unserialize, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Javascript, jsonSerialize, arginfo_class_MongoDB_BSON_Javascript_jsonSerialize, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_FE_END
};

static zend_class_entry *register_class_MongoDB_BSON_Javascript(zend_class_entry *class_entry_MongoDB_BSON_JavascriptInterface, zend_class_entry *class_entry_JsonSerializable, zend_class_entry *class_entry_MongoDB_BSON_Type, zend_class_entry *class_entry_Stringable)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "MongoDB\\BSON", "Javascript", class_MongoDB_BSON_Javascript_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif
	zend_class_implements(class_entry, 4, class_entry_MongoDB_BSON_JavascriptInterface, class_entry_JsonSerializable, class_entry_MongoDB_BSON_Type, class_entry_Stringable);

	zval property_code_default_value;
	ZVAL_UNDEF(&property_code_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_CODE), &property_code_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));

	zval property_scope_default_value;
	ZVAL_UNDEF(&property_scope_default_value);
	zend_string *property_scope_name = zend_string_init("scope", sizeof("scope") - 1, 1);
	zend_declare_typed_property(class_entry, property_scope_name, &property_scope_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_OBJECT|MAY_BE_NULL));
	zend_string_release(property_scope_name);

	return class_entry;
}
