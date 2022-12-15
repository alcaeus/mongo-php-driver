--TEST--
MongoDB\BSON\DocumentWriter writing array
--FILE--
<?php

$document = (new MongoDB\BSON\DocumentWriter())
    ->writeKey('0')->writeInt(1)
    ->writeKey('1')->writeInt(2)
    ->writeKey('2')->writeString('foo')
    ->write();

var_dump($document instanceof MongoDB\BSON\ArrayList);
var_dump($document->toPHP());

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
bool(true)
array(3) {
  [0]=>
  int(1)
  [1]=>
  int(2)
  [2]=>
  string(3) "foo"
}
===DONE===
