--TEST--
MongoDB\BSON\Binary::$type property
--FILE--
<?php

$tests = [
    [MongoDB\BSON\Binary::TYPE_GENERIC, 'TYPE_GENERIC'],
    [MongoDB\BSON\Binary::TYPE_FUNCTION, 'TYPE_FUNCTION'],
    [MongoDB\BSON\Binary::TYPE_UUID, 'TYPE_UUID'],
    [MongoDB\BSON\Binary::TYPE_MD5, 'TYPE_MD5'],
    [MongoDB\BSON\Binary::TYPE_USER_DEFINED, 'TYPE_USER_DEFINED'],
];

foreach ($tests as [$type, $name]) {
    $data = str_repeat("\0", $type === MongoDB\BSON\Binary::TYPE_UUID ? 16 : 1);
    $binary = new MongoDB\BSON\Binary($data, $type);
    printf("Testing %s\n", $name);
    var_dump($binary->getType() === $binary->type);
    var_dump($binary->type);
}

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
Testing TYPE_GENERIC
bool(true)
int(0)
Testing TYPE_FUNCTION
bool(true)
int(1)
Testing TYPE_UUID
bool(true)
int(4)
Testing TYPE_MD5
bool(true)
int(5)
Testing TYPE_USER_DEFINED
bool(true)
int(128)
===DONE===
