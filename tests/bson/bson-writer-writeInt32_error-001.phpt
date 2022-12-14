--TEST--
MongoDB\BSON\Writer::writeInt32() errors when given a 64-bit value
--SKIPIF--
<?php if (8 !== PHP_INT_SIZE) { die('skip Only for 64-bit platform'); } ?>
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

echo throws(function () {
    (new MongoDB\BSON\Writer())
        ->writeKey('int')->writeInt32(9223372036854775807);
}, MongoDB\Driver\Exception\InvalidArgumentException::class), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
OK: Got MongoDB\Driver\Exception\InvalidArgumentException
Cannot write a 64-bit integer value as int32
===DONE===
