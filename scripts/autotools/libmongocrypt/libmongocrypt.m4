if test "$PHP_CLIENT_SIDE_ENCRYPTION" != "no"; then
  AC_SUBST(MONGOCRYPT_ENABLE_TRACE, 1)
  AC_SUBST(MONGOCRYPT_IS_POSIX, 1)
  AC_SUBST(MONGOCRYPT_IS_WIN, 0)

  PHP_MONGODB_LIBMONGOCRYPT_CFLAGS="$PHP_MONGODB_BUNDLED_CFLAGS -std=gnu99"

  dnl Generated with: find src/libmongocrypt/src -maxdepth 1 -name '*.c' -print0 | cut -sz -d / -f 4- | sort -dz | tr '\000' ' '
  PHP_MONGODB_MONGOCRYPT_SOURCES="mongocrypt-binary.c mongocrypt-buffer.c mongocrypt.c mongocrypt-cache.c mongocrypt-cache-collinfo.c mongocrypt-cache-key.c mongocrypt-ciphertext.c mongocrypt-crypto.c mongocrypt-ctx.c mongocrypt-ctx-datakey.c mongocrypt-ctx-decrypt.c mongocrypt-ctx-encrypt.c mongocrypt-key-broker.c mongocrypt-key.c mongocrypt-kms-ctx.c mongocrypt-log.c mongocrypt-marking.c mongocrypt-opts.c mongocrypt-status.c mongocrypt-traverse-util.c"

  dnl Generated with: find src/libmongocrypt/src/os_posix -name '*.c' -print0 | cut -sz -d / -f 5- | sort -dz | tr '\000' ' '
  PHP_MONGODB_MONGOCRYPT_POSIX_SOURCES="os_mutex.c os_once.c"

  dnl Generated with: find src/libmongocrypt/kms-message/src -name '*.c' ! -name 'kms_crypto_*' -print0 | cut -sz -d / -f 5- | sort -dz | tr '\000' ' '
  PHP_MONGODB_MONGOCRYPT_KMS_MESSAGE_SOURCES="hexlify.c kms_b64.c kms_caller_identity_request.c kms_decrypt_request.c kms_encrypt_request.c kms_kv_list.c kms_message.c kms_request.c kms_request_opt.c kms_request_str.c kms_response.c kms_response_parser.c sort.c"

  PHP_MONGODB_ADD_SOURCES([src/libmongocrypt/src/], $PHP_MONGODB_MONGOCRYPT_SOURCES, $PHP_MONGODB_LIBMONGOCRYPT_CFLAGS)
  PHP_MONGODB_ADD_SOURCES([src/libmongocrypt/kms-message/src/], $PHP_MONGODB_MONGOCRYPT_KMS_MESSAGE_SOURCES, $PHP_MONGODB_LIBMONGOCRYPT_CFLAGS)

  PHP_MONGODB_ADD_SOURCES([src/libmongocrypt/src/os_posix], $PHP_MONGODB_MONGOCRYPT_POSIX_SOURCES, $PHP_MONGODB_LIBMONGOCRYPT_CFLAGS)

  PHP_MONGODB_ADD_INCLUDE([src/libmongocrypt/src])
  PHP_MONGODB_ADD_INCLUDE([src/libmongocrypt/kms-message/src])
  PHP_MONGODB_ADD_INCLUDE([src/libmongocrypt-compat])

  PHP_MONGODB_ADD_BUILD_DIR([src/libmongocrypt/src])
fi
