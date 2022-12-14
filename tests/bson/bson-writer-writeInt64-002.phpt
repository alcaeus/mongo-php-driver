--TEST--
MongoDB\BSON\Writer::writeInt64() always writes $numberLong (64-bit platforms)
--SKIPIF--
<?php if (8 !== PHP_INT_SIZE) { die('skip Only for 64-bit platform'); } ?>
--FILE--
<?php

echo (new MongoDB\BSON\Writer())
    ->writeKey('int')->writeInt64(9223372036854775807)
    ->write()
    ->toCanonicalExtendedJSON(), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
{ "int" : { "$numberLong" : "9223372036854775807" } }
===DONE===
