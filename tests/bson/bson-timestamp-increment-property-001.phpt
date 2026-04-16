--TEST--
MongoDB\BSON\Timestamp::$increment property
--FILE--
<?php

$tests = [
    new MongoDB\BSON\Timestamp(1234, 5678),
    new MongoDB\BSON\Timestamp(2147483647, 0),
    new MongoDB\BSON\Timestamp(0, 2147483647),
];

foreach ($tests as $ts) {
    printf("Test %s\n", $ts);
    var_dump($ts->getIncrement() === $ts->increment);
    var_dump($ts->increment);
    echo "\n";
}

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
Test [1234:5678]
bool(true)
int(1234)

Test [2147483647:0]
bool(true)
int(2147483647)

Test [0:2147483647]
bool(true)
int(0)

===DONE===
