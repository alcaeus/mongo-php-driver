--TEST--
MongoDB\Driver\clientEncryption::__construct()
--FILE--
<?php

$key = base64_decode('Mng0NCt4ZHVUYUJCa1kxNkVyNUR1QURhZ2h2UzR2d2RrZzh0cFBwM3R6NmdWMDFBMUN3YkQ5aXRRMkhGRGdQV09wOGVNYUMxT2k3NjZKelhaQmRCZGJkTXVyZG9uSjFk');

$manager = new MongoDB\Driver\Manager();
$clientEncryption = new MongoDB\Driver\ClientEncryption($manager, 'default.keys', ['local' => ['key' => new MongoDB\BSON\Binary($key, 0)]]);

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
===DONE===
