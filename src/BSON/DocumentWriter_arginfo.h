/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 2dc1673f82b20cb3ebd00f15ce2f6bc8dde7748a */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_write, 0, 0, MongoDB\\BSON\\Document, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeKey, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeBoolean, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_TYPE_INFO(0, value, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeDouble, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeInt, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, value, MongoDB\\BSON\\Int64, MAY_BE_LONG, NULL)
ZEND_END_ARG_INFO()
#endif

#if !(PHP_VERSION_ID >= 80000)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeInt, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeNull, 0, 0, MongoDB\\BSON\\DocumentWriter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeString, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeBinary, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\BinaryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeDecimal128, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\Decimal128Interface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeInt32, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
#define arginfo_class_MongoDB_BSON_DocumentWriter_writeInt64 arginfo_class_MongoDB_BSON_DocumentWriter_writeInt
#endif

#if !(PHP_VERSION_ID >= 80000)
#define arginfo_class_MongoDB_BSON_DocumentWriter_writeInt64 arginfo_class_MongoDB_BSON_DocumentWriter_writeInt
#endif

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeJavascript, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\JavascriptInterface, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_MongoDB_BSON_DocumentWriter_writeMaxKey arginfo_class_MongoDB_BSON_DocumentWriter_writeNull

#define arginfo_class_MongoDB_BSON_DocumentWriter_writeMinKey arginfo_class_MongoDB_BSON_DocumentWriter_writeNull

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeObjectId, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\ObjectIdInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeRegularExpression, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\RegexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeTimestamp, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\TimestampInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeUTCDateTime, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_OBJ_INFO(0, value, MongoDB\\BSON\\\125TCDateTimeInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeArray, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_OBJ_INFO(0, array, MongoDB\\BSON\\ArrayList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_MongoDB_BSON_DocumentWriter_writeDocument, 0, 1, MongoDB\\BSON\\DocumentWriter, 0)
	ZEND_ARG_OBJ_INFO(0, document, MongoDB\\BSON\\Document, 0)
ZEND_END_ARG_INFO()


static ZEND_METHOD(MongoDB_BSON_DocumentWriter, write);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeKey);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeBoolean);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeDouble);
#if PHP_VERSION_ID >= 80000
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeInt);
#endif
#if !(PHP_VERSION_ID >= 80000)
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeInt);
#endif
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeNull);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeString);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeBinary);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeDecimal128);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeInt32);
#if PHP_VERSION_ID >= 80000
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeInt64);
#endif
#if !(PHP_VERSION_ID >= 80000)
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeInt64);
#endif
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeJavascript);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeMaxKey);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeMinKey);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeObjectId);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeRegularExpression);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeTimestamp);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeUTCDateTime);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeArray);
static ZEND_METHOD(MongoDB_BSON_DocumentWriter, writeDocument);


static const zend_function_entry class_MongoDB_BSON_DocumentWriter_methods[] = {
	ZEND_ME(MongoDB_BSON_DocumentWriter, write, arginfo_class_MongoDB_BSON_DocumentWriter_write, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeKey, arginfo_class_MongoDB_BSON_DocumentWriter_writeKey, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeBoolean, arginfo_class_MongoDB_BSON_DocumentWriter_writeBoolean, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeDouble, arginfo_class_MongoDB_BSON_DocumentWriter_writeDouble, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#if PHP_VERSION_ID >= 80000
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeInt, arginfo_class_MongoDB_BSON_DocumentWriter_writeInt, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#endif
#if !(PHP_VERSION_ID >= 80000)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeInt, arginfo_class_MongoDB_BSON_DocumentWriter_writeInt, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#endif
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeNull, arginfo_class_MongoDB_BSON_DocumentWriter_writeNull, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeString, arginfo_class_MongoDB_BSON_DocumentWriter_writeString, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeBinary, arginfo_class_MongoDB_BSON_DocumentWriter_writeBinary, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeDecimal128, arginfo_class_MongoDB_BSON_DocumentWriter_writeDecimal128, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeInt32, arginfo_class_MongoDB_BSON_DocumentWriter_writeInt32, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#if PHP_VERSION_ID >= 80000
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeInt64, arginfo_class_MongoDB_BSON_DocumentWriter_writeInt64, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#endif
#if !(PHP_VERSION_ID >= 80000)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeInt64, arginfo_class_MongoDB_BSON_DocumentWriter_writeInt64, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
#endif
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeJavascript, arginfo_class_MongoDB_BSON_DocumentWriter_writeJavascript, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeMaxKey, arginfo_class_MongoDB_BSON_DocumentWriter_writeMaxKey, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeMinKey, arginfo_class_MongoDB_BSON_DocumentWriter_writeMinKey, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeObjectId, arginfo_class_MongoDB_BSON_DocumentWriter_writeObjectId, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeRegularExpression, arginfo_class_MongoDB_BSON_DocumentWriter_writeRegularExpression, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeTimestamp, arginfo_class_MongoDB_BSON_DocumentWriter_writeTimestamp, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeUTCDateTime, arginfo_class_MongoDB_BSON_DocumentWriter_writeUTCDateTime, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeArray, arginfo_class_MongoDB_BSON_DocumentWriter_writeArray, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_BSON_DocumentWriter, writeDocument, arginfo_class_MongoDB_BSON_DocumentWriter_writeDocument, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	ZEND_FE_END
};

static zend_class_entry *register_class_MongoDB_BSON_DocumentWriter(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "MongoDB\\BSON", "DocumentWriter", class_MongoDB_BSON_DocumentWriter_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}
