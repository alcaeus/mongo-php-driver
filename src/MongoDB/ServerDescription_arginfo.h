/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: f7a3fcd41b5ae0caf295b24c2c9283737f4224ec */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_MongoDB_Driver_ServerDescription___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_Driver_ServerDescription_getHelloResponse, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_Driver_ServerDescription_getHost, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_Driver_ServerDescription_getLastUpdateTime, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_MongoDB_Driver_ServerDescription_getPort arginfo_class_MongoDB_Driver_ServerDescription_getLastUpdateTime

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_MongoDB_Driver_ServerDescription_getRoundTripTime, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_MongoDB_Driver_ServerDescription_getType arginfo_class_MongoDB_Driver_ServerDescription_getHost


static ZEND_METHOD(MongoDB_Driver_ServerDescription, __construct);
static ZEND_METHOD(MongoDB_Driver_ServerDescription, getHelloResponse);
static ZEND_METHOD(MongoDB_Driver_ServerDescription, getHost);
static ZEND_METHOD(MongoDB_Driver_ServerDescription, getLastUpdateTime);
static ZEND_METHOD(MongoDB_Driver_ServerDescription, getPort);
static ZEND_METHOD(MongoDB_Driver_ServerDescription, getRoundTripTime);
static ZEND_METHOD(MongoDB_Driver_ServerDescription, getType);


static const zend_function_entry class_MongoDB_Driver_ServerDescription_methods[] = {
	ZEND_ME(MongoDB_Driver_ServerDescription, __construct, arginfo_class_MongoDB_Driver_ServerDescription___construct, ZEND_ACC_PRIVATE|ZEND_ACC_FINAL)
	ZEND_ME(MongoDB_Driver_ServerDescription, getHelloResponse, arginfo_class_MongoDB_Driver_ServerDescription_getHelloResponse, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_DEPRECATED)
	ZEND_ME(MongoDB_Driver_ServerDescription, getHost, arginfo_class_MongoDB_Driver_ServerDescription_getHost, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_DEPRECATED)
	ZEND_ME(MongoDB_Driver_ServerDescription, getLastUpdateTime, arginfo_class_MongoDB_Driver_ServerDescription_getLastUpdateTime, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_DEPRECATED)
	ZEND_ME(MongoDB_Driver_ServerDescription, getPort, arginfo_class_MongoDB_Driver_ServerDescription_getPort, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_DEPRECATED)
	ZEND_ME(MongoDB_Driver_ServerDescription, getRoundTripTime, arginfo_class_MongoDB_Driver_ServerDescription_getRoundTripTime, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_DEPRECATED)
	ZEND_ME(MongoDB_Driver_ServerDescription, getType, arginfo_class_MongoDB_Driver_ServerDescription_getType, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_DEPRECATED)
	ZEND_FE_END
};

static zend_class_entry *register_class_MongoDB_Driver_ServerDescription(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "MongoDB\\Driver", "ServerDescription", class_MongoDB_Driver_ServerDescription_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE;

	zval const_TYPE_UNKNOWN_value;
	zend_string *const_TYPE_UNKNOWN_value_str = zend_string_init(PHONGO_SERVER_TYPE_UNKNOWN, strlen(PHONGO_SERVER_TYPE_UNKNOWN), 1);
	ZVAL_STR(&const_TYPE_UNKNOWN_value, const_TYPE_UNKNOWN_value_str);
	zend_string *const_TYPE_UNKNOWN_name = zend_string_init_interned("TYPE_UNKNOWN", sizeof("TYPE_UNKNOWN") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_TYPE_UNKNOWN_name, &const_TYPE_UNKNOWN_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_TYPE_UNKNOWN_name);

	zval const_TYPE_STANDALONE_value;
	zend_string *const_TYPE_STANDALONE_value_str = zend_string_init(PHONGO_SERVER_TYPE_STANDALONE, strlen(PHONGO_SERVER_TYPE_STANDALONE), 1);
	ZVAL_STR(&const_TYPE_STANDALONE_value, const_TYPE_STANDALONE_value_str);
	zend_string *const_TYPE_STANDALONE_name = zend_string_init_interned("TYPE_STANDALONE", sizeof("TYPE_STANDALONE") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_TYPE_STANDALONE_name, &const_TYPE_STANDALONE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_TYPE_STANDALONE_name);

	zval const_TYPE_MONGOS_value;
	zend_string *const_TYPE_MONGOS_value_str = zend_string_init(PHONGO_SERVER_TYPE_MONGOS, strlen(PHONGO_SERVER_TYPE_MONGOS), 1);
	ZVAL_STR(&const_TYPE_MONGOS_value, const_TYPE_MONGOS_value_str);
	zend_string *const_TYPE_MONGOS_name = zend_string_init_interned("TYPE_MONGOS", sizeof("TYPE_MONGOS") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_TYPE_MONGOS_name, &const_TYPE_MONGOS_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_TYPE_MONGOS_name);

	zval const_TYPE_POSSIBLE_PRIMARY_value;
	zend_string *const_TYPE_POSSIBLE_PRIMARY_value_str = zend_string_init(PHONGO_SERVER_TYPE_POSSIBLE_PRIMARY, strlen(PHONGO_SERVER_TYPE_POSSIBLE_PRIMARY), 1);
	ZVAL_STR(&const_TYPE_POSSIBLE_PRIMARY_value, const_TYPE_POSSIBLE_PRIMARY_value_str);
	zend_string *const_TYPE_POSSIBLE_PRIMARY_name = zend_string_init_interned("TYPE_POSSIBLE_PRIMARY", sizeof("TYPE_POSSIBLE_PRIMARY") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_TYPE_POSSIBLE_PRIMARY_name, &const_TYPE_POSSIBLE_PRIMARY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_TYPE_POSSIBLE_PRIMARY_name);

	zval const_TYPE_RS_PRIMARY_value;
	zend_string *const_TYPE_RS_PRIMARY_value_str = zend_string_init(PHONGO_SERVER_TYPE_RS_PRIMARY, strlen(PHONGO_SERVER_TYPE_RS_PRIMARY), 1);
	ZVAL_STR(&const_TYPE_RS_PRIMARY_value, const_TYPE_RS_PRIMARY_value_str);
	zend_string *const_TYPE_RS_PRIMARY_name = zend_string_init_interned("TYPE_RS_PRIMARY", sizeof("TYPE_RS_PRIMARY") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_TYPE_RS_PRIMARY_name, &const_TYPE_RS_PRIMARY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_TYPE_RS_PRIMARY_name);

	zval const_TYPE_RS_SECONDARY_value;
	zend_string *const_TYPE_RS_SECONDARY_value_str = zend_string_init(PHONGO_SERVER_TYPE_RS_SECONDARY, strlen(PHONGO_SERVER_TYPE_RS_SECONDARY), 1);
	ZVAL_STR(&const_TYPE_RS_SECONDARY_value, const_TYPE_RS_SECONDARY_value_str);
	zend_string *const_TYPE_RS_SECONDARY_name = zend_string_init_interned("TYPE_RS_SECONDARY", sizeof("TYPE_RS_SECONDARY") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_TYPE_RS_SECONDARY_name, &const_TYPE_RS_SECONDARY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_TYPE_RS_SECONDARY_name);

	zval const_TYPE_RS_ARBITER_value;
	zend_string *const_TYPE_RS_ARBITER_value_str = zend_string_init(PHONGO_SERVER_TYPE_RS_ARBITER, strlen(PHONGO_SERVER_TYPE_RS_ARBITER), 1);
	ZVAL_STR(&const_TYPE_RS_ARBITER_value, const_TYPE_RS_ARBITER_value_str);
	zend_string *const_TYPE_RS_ARBITER_name = zend_string_init_interned("TYPE_RS_ARBITER", sizeof("TYPE_RS_ARBITER") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_TYPE_RS_ARBITER_name, &const_TYPE_RS_ARBITER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_TYPE_RS_ARBITER_name);

	zval const_TYPE_RS_OTHER_value;
	zend_string *const_TYPE_RS_OTHER_value_str = zend_string_init(PHONGO_SERVER_TYPE_RS_OTHER, strlen(PHONGO_SERVER_TYPE_RS_OTHER), 1);
	ZVAL_STR(&const_TYPE_RS_OTHER_value, const_TYPE_RS_OTHER_value_str);
	zend_string *const_TYPE_RS_OTHER_name = zend_string_init_interned("TYPE_RS_OTHER", sizeof("TYPE_RS_OTHER") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_TYPE_RS_OTHER_name, &const_TYPE_RS_OTHER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_TYPE_RS_OTHER_name);

	zval const_TYPE_RS_GHOST_value;
	zend_string *const_TYPE_RS_GHOST_value_str = zend_string_init(PHONGO_SERVER_TYPE_RS_GHOST, strlen(PHONGO_SERVER_TYPE_RS_GHOST), 1);
	ZVAL_STR(&const_TYPE_RS_GHOST_value, const_TYPE_RS_GHOST_value_str);
	zend_string *const_TYPE_RS_GHOST_name = zend_string_init_interned("TYPE_RS_GHOST", sizeof("TYPE_RS_GHOST") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_TYPE_RS_GHOST_name, &const_TYPE_RS_GHOST_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_TYPE_RS_GHOST_name);

	zval const_TYPE_LOAD_BALANCER_value;
	zend_string *const_TYPE_LOAD_BALANCER_value_str = zend_string_init(PHONGO_SERVER_TYPE_LOAD_BALANCER, strlen(PHONGO_SERVER_TYPE_LOAD_BALANCER), 1);
	ZVAL_STR(&const_TYPE_LOAD_BALANCER_value, const_TYPE_LOAD_BALANCER_value_str);
	zend_string *const_TYPE_LOAD_BALANCER_name = zend_string_init_interned("TYPE_LOAD_BALANCER", sizeof("TYPE_LOAD_BALANCER") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_TYPE_LOAD_BALANCER_name, &const_TYPE_LOAD_BALANCER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_TYPE_LOAD_BALANCER_name);

	zval property_helloResponse_default_value;
	ZVAL_UNDEF(&property_helloResponse_default_value);
	zend_string *property_helloResponse_name = zend_string_init("helloResponse", sizeof("helloResponse") - 1, 1);
	zend_declare_typed_property(class_entry, property_helloResponse_name, &property_helloResponse_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_helloResponse_name);

	zval property_host_default_value;
	ZVAL_UNDEF(&property_host_default_value);
	zend_string *property_host_name = zend_string_init("host", sizeof("host") - 1, 1);
	zend_declare_typed_property(class_entry, property_host_name, &property_host_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_host_name);

	zval property_lastUpdateTime_default_value;
	ZVAL_UNDEF(&property_lastUpdateTime_default_value);
	zend_string *property_lastUpdateTime_name = zend_string_init("lastUpdateTime", sizeof("lastUpdateTime") - 1, 1);
	zend_declare_typed_property(class_entry, property_lastUpdateTime_name, &property_lastUpdateTime_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_lastUpdateTime_name);

	zval property_roundTripTime_default_value;
	ZVAL_UNDEF(&property_roundTripTime_default_value);
	zend_string *property_roundTripTime_name = zend_string_init("roundTripTime", sizeof("roundTripTime") - 1, 1);
	zend_declare_typed_property(class_entry, property_roundTripTime_name, &property_roundTripTime_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG|MAY_BE_NULL));
	zend_string_release(property_roundTripTime_name);

	zval property_port_default_value;
	ZVAL_UNDEF(&property_port_default_value);
	zend_string *property_port_name = zend_string_init("port", sizeof("port") - 1, 1);
	zend_declare_typed_property(class_entry, property_port_name, &property_port_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_port_name);

	zval property_type_default_value;
	ZVAL_UNDEF(&property_type_default_value);
	zend_string *property_type_name = zend_string_init("type", sizeof("type") - 1, 1);
	zend_declare_typed_property(class_entry, property_type_name, &property_type_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_type_name);

	return class_entry;
}
