--TEST--
MongoDB\BSON\Javascript::$scope property
--FILE--
<?php

$tests = [
    new MongoDB\BSON\Javascript('function(bar) { return bar; }'),
    new MongoDB\BSON\Javascript('function(bar) { return bar; }', null),
    new MongoDB\BSON\Javascript('function() { return foo; }', ['foo' => 42]),
    new MongoDB\BSON\Javascript('function() { return foo; }', (object) ['foo' => 42]),
];

foreach ($tests as $js) {
    var_dump($js->scope);
}

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
NULL
NULL
object(stdClass)#%d (1) {
  ["foo"]=>
  int(42)
}
object(stdClass)#%d (1) {
  ["foo"]=>
  int(42)
}
===DONE===
