--TEST--
MongoDB\BSON\Writer::writeInt() writes $numberLong depending on size (64-bit platforms)
--FILE--
<?php

$int32 = unserialize('C:18:"MongoDB\BSON\Int64":29:{a:1:{s:7:"integer";s:2:"16";}}');
$int64 = unserialize('C:18:"MongoDB\BSON\Int64":47:{a:1:{s:7:"integer";s:19:"9223372036854775807";}}');

$tests = [
    'int32' => 16,
    'int32 in Int64 BSON object' => $int32,
    'int64 in Int64 BSON object' => $int64,
];

foreach ($tests as $test => $value) {
    echo "Testing ", $test, "\n";
    echo (new MongoDB\BSON\Writer())
        ->writeKey('int')->writeInt($value)
        ->write()
        ->toCanonicalExtendedJSON(), "\n";
}

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
Testing int32
{ "int" : { "$numberInt" : "16" } }
Testing int32 in Int64 BSON object
{ "int" : { "$numberLong" : "16" } }
Testing int64 in Int64 BSON object
{ "int" : { "$numberLong" : "9223372036854775807" } }
===DONE===
