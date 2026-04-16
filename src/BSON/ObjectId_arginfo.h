/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 01f3b945bf4ebeb16a445ebec8839090241840ca */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_MongoDB_BSON_ObjectId___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, id, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_BSON_ObjectId_getTimestamp, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_BSON_ObjectId___toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_ObjectId___set_state, 0, 1, MongoDB\\BSON\\ObjectId, 0)
	ZEND_ARG_TYPE_INFO(0, properties, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_BSON_ObjectId___unserialize, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_BSON_ObjectId___serialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_BSON_ObjectId_jsonSerialize, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

static ZEND_METHOD(MongoDB_BSON_ObjectId, __construct);
static ZEND_METHOD(MongoDB_BSON_ObjectId, getTimestamp);
static ZEND_METHOD(MongoDB_BSON_ObjectId, __toString);
static ZEND_METHOD(MongoDB_BSON_ObjectId, __set_state);
static ZEND_METHOD(MongoDB_BSON_ObjectId, __unserialize);
static ZEND_METHOD(MongoDB_BSON_ObjectId, __serialize);
static ZEND_METHOD(MongoDB_BSON_ObjectId, jsonSerialize);

static const zend_function_entry class_MongoDB_BSON_ObjectId_methods[] = {
	ZEND_ME(MongoDB_BSON_ObjectId, __construct, arginfo_class_MongoDB_BSON_ObjectId___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_ObjectId, getTimestamp, arginfo_class_MongoDB_BSON_ObjectId_getTimestamp, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_ObjectId, __toString, arginfo_class_MongoDB_BSON_ObjectId___toString, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_ObjectId, __set_state, arginfo_class_MongoDB_BSON_ObjectId___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_ObjectId, __unserialize, arginfo_class_MongoDB_BSON_ObjectId___unserialize, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_ObjectId, __serialize, arginfo_class_MongoDB_BSON_ObjectId___serialize, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_ObjectId, jsonSerialize, arginfo_class_MongoDB_BSON_ObjectId_jsonSerialize, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_FE_END
};

static zend_class_entry *register_class_MongoDB_BSON_ObjectId(zend_class_entry *class_entry_MongoDB_BSON_ObjectIdInterface, zend_class_entry *class_entry_JsonSerializable, zend_class_entry *class_entry_MongoDB_BSON_Type, zend_class_entry *class_entry_Stringable)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "MongoDB\\BSON", "ObjectId", class_MongoDB_BSON_ObjectId_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif
	zend_class_implements(class_entry, 4, class_entry_MongoDB_BSON_ObjectIdInterface, class_entry_JsonSerializable, class_entry_MongoDB_BSON_Type, class_entry_Stringable);

	zval property_timestamp_default_value;
	ZVAL_UNDEF(&property_timestamp_default_value);
	zend_string *property_timestamp_name = zend_string_init("timestamp", sizeof("timestamp") - 1, 1);
	zend_declare_typed_property(class_entry, property_timestamp_name, &property_timestamp_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_timestamp_name);

	return class_entry;
}
