if test "$PHP_CLIENT_SIDE_ENCRYPTION" != "no"; then
  AC_MSG_CHECKING([which crypto library to use for libmongocrypt])
  AC_MSG_RESULT([$PHP_MONGODB_SSL])

  dnl Disable Windows crypto
  AC_SUBST(MONGOCRYPT_ENABLE_CRYPTO_CNG, 0)

  if test "$PHP_MONGODB_SSL" = "darwin"; then
    AC_SUBST(MONGOC_ENABLE_CLIENT_SIDE_ENCRYPTION, 1)
    AC_SUBST(MONGOCRYPT_ENABLE_CRYPTO, 1)
    AC_SUBST(MONGOCRYPT_ENABLE_CRYPTO_OPENSSL, 0)
    AC_SUBST(MONGOCRYPT_ENABLE_CRYPTO_COMMON_CRYPTO, 1)

    dnl TODO remove these extra calls once MONGOCRYPT-218 is merged
    PHP_MONGODB_ADD_SOURCES([src/libmongocrypt/src/], "crypto/commoncrypto.c", $PHP_MONGODB_LIBMONGOCRYPT_CFLAGS)
    PHP_MONGODB_ADD_SOURCES([src/libmongocrypt/kms-message/src/], "kms_crypto_apple.c", $PHP_MONGODB_LIBMONGOCRYPT_CFLAGS)
  elif test "$PHP_MONGODB_SSL" = "openssl" -o "$PHP_MONGODB_SSL" = "libressl"; then
    AC_SUBST(MONGOC_ENABLE_CLIENT_SIDE_ENCRYPTION, 1)
    AC_SUBST(MONGOCRYPT_ENABLE_CRYPTO, 1)
    AC_SUBST(MONGOCRYPT_ENABLE_CRYPTO_OPENSSL, 1)
    AC_SUBST(MONGOCRYPT_ENABLE_CRYPTO_COMMON_CRYPTO, 0)

    dnl TODO remove these extra calls once MONGOCRYPT-218 is merged
    PHP_MONGODB_ADD_SOURCES([src/libmongocrypt/src/], "crypto/openssl.c", $PHP_MONGODB_LIBMONGOCRYPT_CFLAGS)
    PHP_MONGODB_ADD_SOURCES([src/libmongocrypt/kms-message/src/], "kms_crypto_openssl.c", $PHP_MONGODB_LIBMONGOCRYPT_CFLAGS)
  elif test "$PHP_CLIENT_SIDE_ENCRYPTION" = "auto"; then
    AC_MSG_RESULT(No SSL library found. Compiling without libmongocrypt. Please specify a library using the --with-mongodb-ssl option)
    AC_SUBST(MONGOC_ENABLE_CLIENT_SIDE_ENCRYPTION, 0)
    AC_SUBST(MONGOCRYPT_ENABLE_CRYPTO, 0)
    AC_SUBST(MONGOCRYPT_ENABLE_CRYPTO_OPENSSL, 0)
    AC_SUBST(MONGOCRYPT_ENABLE_CRYPTO_COMMON_CRYPTO, 0)
  else
    AC_MSG_ERROR(Need an SSL library to compile with libmongocrypt. Please specify it using the --with-mongodb-ssl option)
  fi
else
  AC_SUBST(MONGOC_ENABLE_CLIENT_SIDE_ENCRYPTION, 0)
fi
