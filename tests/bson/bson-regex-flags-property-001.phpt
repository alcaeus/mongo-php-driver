--TEST--
MongoDB\BSON\Regex::$flags property
--FILE--
<?php

$tests = [
    new MongoDB\BSON\Regex('regexp', 'i'),
    new MongoDB\BSON\Regex('regexp', ''),
    new MongoDB\BSON\Regex('regexp', 'mi'),
];

foreach ($tests as $regex) {
    var_dump($regex->getFlags() === $regex->flags);
    var_dump($regex->flags);
}

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
bool(true)
string(1) "i"
bool(true)
string(0) ""
bool(true)
string(2) "im"
===DONE===
