/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: a4d276313866d2a9c6ade5656765fabe173fb77f */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_write, 0, 0, MongoDB\\BSON\\Document, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeKey, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeBoolean, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_TYPE_INFO(0, value, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeDouble, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeInt, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, value, MongoDB\\BSON\\Int64, MAY_BE_LONG, NULL)
ZEND_END_ARG_INFO()
#endif

#if !(PHP_VERSION_ID >= 80000)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeInt, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeNull, 0, 0, MongoDB\\BSON\\Writer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeString, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeBinary, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\BinaryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeDecimal128, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\Decimal128Interface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeInt32, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
#define arginfo_class_MongoDB_BSON_Writer_writeInt64 arginfo_class_MongoDB_BSON_Writer_writeInt
#endif

#if !(PHP_VERSION_ID >= 80000)
#define arginfo_class_MongoDB_BSON_Writer_writeInt64 arginfo_class_MongoDB_BSON_Writer_writeInt
#endif

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeJavascript, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\JavascriptInterface, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_MongoDB_BSON_Writer_writeMaxKey arginfo_class_MongoDB_BSON_Writer_writeNull

#define arginfo_class_MongoDB_BSON_Writer_writeMinKey arginfo_class_MongoDB_BSON_Writer_writeNull

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeObjectId, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\ObjectIdInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeRegularExpression, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\RegexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeTimestamp, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\TimestampInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeUTCDateTime, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\\125TCDateTimeInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeArray, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_OBJ_INFO(0, array, MongoDB\\BSON\\ArrayList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_Writer_writeDocument, 0, 1, MongoDB\\BSON\\Writer, 0)
	ZEND_ARG_OBJ_INFO(0, document, MongoDB\\BSON\\Document, 0)
ZEND_END_ARG_INFO()


static ZEND_METHOD(MongoDB_BSON_Writer, write);
static ZEND_METHOD(MongoDB_BSON_Writer, writeKey);
static ZEND_METHOD(MongoDB_BSON_Writer, writeBoolean);
static ZEND_METHOD(MongoDB_BSON_Writer, writeDouble);
#if PHP_VERSION_ID >= 80000
static ZEND_METHOD(MongoDB_BSON_Writer, writeInt);
#endif
#if !(PHP_VERSION_ID >= 80000)
static ZEND_METHOD(MongoDB_BSON_Writer, writeInt);
#endif
static ZEND_METHOD(MongoDB_BSON_Writer, writeNull);
static ZEND_METHOD(MongoDB_BSON_Writer, writeString);
static ZEND_METHOD(MongoDB_BSON_Writer, writeBinary);
static ZEND_METHOD(MongoDB_BSON_Writer, writeDecimal128);
static ZEND_METHOD(MongoDB_BSON_Writer, writeInt32);
#if PHP_VERSION_ID >= 80000
static ZEND_METHOD(MongoDB_BSON_Writer, writeInt64);
#endif
#if !(PHP_VERSION_ID >= 80000)
static ZEND_METHOD(MongoDB_BSON_Writer, writeInt64);
#endif
static ZEND_METHOD(MongoDB_BSON_Writer, writeJavascript);
static ZEND_METHOD(MongoDB_BSON_Writer, writeMaxKey);
static ZEND_METHOD(MongoDB_BSON_Writer, writeMinKey);
static ZEND_METHOD(MongoDB_BSON_Writer, writeObjectId);
static ZEND_METHOD(MongoDB_BSON_Writer, writeRegularExpression);
static ZEND_METHOD(MongoDB_BSON_Writer, writeTimestamp);
static ZEND_METHOD(MongoDB_BSON_Writer, writeUTCDateTime);
static ZEND_METHOD(MongoDB_BSON_Writer, writeArray);
static ZEND_METHOD(MongoDB_BSON_Writer, writeDocument);


static const zend_function_entry class_MongoDB_BSON_Writer_methods[] = {
	ZEND_ME(MongoDB_BSON_Writer, write, arginfo_class_MongoDB_BSON_Writer_write, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeKey, arginfo_class_MongoDB_BSON_Writer_writeKey, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeBoolean, arginfo_class_MongoDB_BSON_Writer_writeBoolean, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeDouble, arginfo_class_MongoDB_BSON_Writer_writeDouble, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#if PHP_VERSION_ID >= 80000
	ZEND_ME(MongoDB_BSON_Writer, writeInt, arginfo_class_MongoDB_BSON_Writer_writeInt, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#endif
#if !(PHP_VERSION_ID >= 80000)
	ZEND_ME(MongoDB_BSON_Writer, writeInt, arginfo_class_MongoDB_BSON_Writer_writeInt, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#endif
	ZEND_ME(MongoDB_BSON_Writer, writeNull, arginfo_class_MongoDB_BSON_Writer_writeNull, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeString, arginfo_class_MongoDB_BSON_Writer_writeString, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeBinary, arginfo_class_MongoDB_BSON_Writer_writeBinary, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeDecimal128, arginfo_class_MongoDB_BSON_Writer_writeDecimal128, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeInt32, arginfo_class_MongoDB_BSON_Writer_writeInt32, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#if PHP_VERSION_ID >= 80000
	ZEND_ME(MongoDB_BSON_Writer, writeInt64, arginfo_class_MongoDB_BSON_Writer_writeInt64, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#endif
#if !(PHP_VERSION_ID >= 80000)
	ZEND_ME(MongoDB_BSON_Writer, writeInt64, arginfo_class_MongoDB_BSON_Writer_writeInt64, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#endif
	ZEND_ME(MongoDB_BSON_Writer, writeJavascript, arginfo_class_MongoDB_BSON_Writer_writeJavascript, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeMaxKey, arginfo_class_MongoDB_BSON_Writer_writeMaxKey, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeMinKey, arginfo_class_MongoDB_BSON_Writer_writeMinKey, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeObjectId, arginfo_class_MongoDB_BSON_Writer_writeObjectId, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeRegularExpression, arginfo_class_MongoDB_BSON_Writer_writeRegularExpression, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeTimestamp, arginfo_class_MongoDB_BSON_Writer_writeTimestamp, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeUTCDateTime, arginfo_class_MongoDB_BSON_Writer_writeUTCDateTime, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeArray, arginfo_class_MongoDB_BSON_Writer_writeArray, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_Writer, writeDocument, arginfo_class_MongoDB_BSON_Writer_writeDocument, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_FE_END
};

static zend_class_entry *register_class_MongoDB_BSON_Writer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "MongoDB\\BSON", "Writer", class_MongoDB_BSON_Writer_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}
