--TEST--
MongoDB\Driver\Manager::__construct(): prevent regressions on shutdown
--SKIPIF--
<?php require __DIR__ . "/../utils/basic-skipif.inc"; ?>
<?php skip_if_not_libmongocrypt(); ?>
<?php skip_if_not_live(); ?>
--FILE--
<?php
require_once __DIR__ . "/../utils/basic.inc";

$key = base64_decode('Mng0NCt4ZHVUYUJCa1kxNkVyNUR1QURhZ2h2UzR2d2RrZzh0cFBwM3R6NmdWMDFBMUN3YkQ5aXRRMkhGRGdQV09wOGVNYUMxT2k3NjZKelhaQmRCZGJkTXVyZG9uSjFk');
$keyVaultClient = new MongoDB\Driver\Manager(URI, [], ['unique' => 'foo']);

$encryptionOptions = [
    'keyVaultNamespace' => 'default.keys',
    'kmsProviders' => ['local' => ['key' => new MongoDB\BSON\Binary($key, 0)]],
    'keyVaultClient' => $keyVaultClient,
];

$manager = new MongoDB\Driver\Manager(URI, [], ['autoEncryption' => $encryptionOptions]);

$clientEncryption = $manager->createClientEncryption($encryptionOptions);

$clientEncryption->createDataKey('local');

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
===DONE===
