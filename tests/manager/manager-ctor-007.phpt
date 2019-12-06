--TEST--
MongoDB\Driver\Manager::__construct(): Passing a manager as driver option
--FILE--
<?php
require_once __DIR__ . "/../utils/basic.inc";

$manager = new MongoDB\Driver\Manager(URI, [], ['autoEncryption' => ['keyVaultClient' => new MongoDB\Driver\Manager()]]);
?>
===DONE===
<?php exit(0); ?>
--EXPECT--
===DONE===
