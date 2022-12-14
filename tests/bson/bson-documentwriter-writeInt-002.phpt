--TEST--
MongoDB\BSON\DocumentWriter::writeInt() writes $numberLong depending on size (64-bit platforms)
--SKIPIF--
<?php if (8 !== PHP_INT_SIZE) { die('skip Only for 64-bit platform'); } ?>
--FILE--
<?php

echo (new MongoDB\BSON\DocumentWriter())
    ->writeKey('int')->writeInt(9223372036854775807)
    ->write()
    ->toCanonicalExtendedJSON(), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
{ "int" : { "$numberLong" : "9223372036854775807" } }
===DONE===
