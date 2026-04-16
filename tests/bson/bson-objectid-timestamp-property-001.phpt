--TEST--
MongoDB\BSON\ObjectId::$timestamp property
--FILE--
<?php

$oid = new MongoDB\BSON\ObjectId('53e2a1c40640fd72175d4603');
var_dump($oid->getTimestamp() === $oid->timestamp);
var_dump($oid->timestamp);

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
bool(true)
int(1407361476)
===DONE===
