--TEST--
MongoDB\BSON\Regex::$pattern property
--FILE--
<?php

$tests = [
    new MongoDB\BSON\Regex('regexp', 'i'),
    new MongoDB\BSON\Regex('.*', ''),
    new MongoDB\BSON\Regex('^foo$', 'im'),
];

foreach ($tests as $regex) {
    var_dump($regex->getPattern() === $regex->pattern);
    var_dump($regex->pattern);
}

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
bool(true)
string(6) "regexp"
bool(true)
string(2) ".*"
bool(true)
string(5) "^foo$"
===DONE===
