--TEST--
MongoDB\BSON\Binary::$data property
--FILE--
<?php

$tests = [
    new MongoDB\BSON\Binary('foobar', MongoDB\BSON\Binary::TYPE_GENERIC),
    new MongoDB\BSON\Binary('', MongoDB\BSON\Binary::TYPE_GENERIC),
    new MongoDB\BSON\Binary('hello world', MongoDB\BSON\Binary::TYPE_GENERIC),
];

foreach ($tests as $binary) {
    var_dump($binary->getData() === $binary->data);
    var_dump($binary->data);
}

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
bool(true)
string(6) "foobar"
bool(true)
string(0) ""
bool(true)
string(11) "hello world"
===DONE===
