--TEST--
MongoDB\BSON\DocumentWriter::writeInt64() only accepts ints or Int64 objects
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

echo throws(function () {
    (new MongoDB\BSON\DocumentWriter())
        ->writeKey('int')->writeInt64(null);
}, MongoDB\Driver\Exception\InvalidArgumentException::class), "\n";

echo throws(function () {
    (new MongoDB\BSON\DocumentWriter())
        ->writeKey('int')->writeInt64('3');
}, MongoDB\Driver\Exception\InvalidArgumentException::class), "\n";

echo throws(function () {
    (new MongoDB\BSON\DocumentWriter())
        ->writeKey('int')->writeInt64(new MongoDB\BSON\ObjectId());
}, MongoDB\Driver\Exception\InvalidArgumentException::class), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
OK: Got MongoDB\Driver\Exception\InvalidArgumentException
Expected value to be int or MongoDB\BSON\Int64, null given
OK: Got MongoDB\Driver\Exception\InvalidArgumentException
Expected value to be int or MongoDB\BSON\Int64, string given
OK: Got MongoDB\Driver\Exception\InvalidArgumentException
Expected value to be int or MongoDB\BSON\Int64, MongoDB\BSON\ObjectId given
===DONE===
