--TEST--
MongoDB\BSON\Writer error test
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

// Cannot write without a key
echo throws(function () {
    (new MongoDB\BSON\Writer())->writeString('foo');
}, MongoDB\Driver\Exception\LogicException::class), "\n";

// Key is deleted after first write call
echo throws(function () {
    (new MongoDB\BSON\Writer())
        ->writeKey('foo')->writeString('foo')
        ->writeString('bar');
}, MongoDB\Driver\Exception\LogicException::class), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
OK: Got MongoDB\Driver\Exception\LogicException
Cannot write a value without a key
OK: Got MongoDB\Driver\Exception\LogicException
Cannot write a value without a key
===DONE===
