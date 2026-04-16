--TEST--
MongoDB\BSON\Javascript::$code property
--FILE--
<?php

$tests = [
    new MongoDB\BSON\Javascript('function(bar) { return bar; }'),
    new MongoDB\BSON\Javascript('function() { return foo; }', ['foo' => 42]),
];

foreach ($tests as $js) {
    var_dump($js->getCode() === $js->code);
    var_dump($js->code);
}

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
bool(true)
string(29) "function(bar) { return bar; }"
bool(true)
string(26) "function() { return foo; }"
===DONE===
