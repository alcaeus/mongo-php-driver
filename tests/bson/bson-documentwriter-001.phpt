--TEST--
MongoDB\BSON\DocumentWriter test
--FILE--
<?php

$document = (new MongoDB\BSON\DocumentWriter())
    // Write an identifier
    ->writeKey('_id')->writeObjectId(new MongoDB\BSON\ObjectId())

    // Only the last key is retained
    ->writeKey('foo')->writeKey('bar')->writeString('bar')

    // Write a field in one call
    ->writeKey('bool')->writeBoolean(true)
    ->writeKey('pi')->writeDouble(3.1415926)
    ->writeKey('int')->writeInt(16)
    ->writeKey('int32')->writeInt32(16)
    ->writeKey('int64')->writeInt64(16)
    ->writeKey('int64_implicit')->writeInt(2**33)
    ->writeKey('null')->writeNull()
    ->writeKey('string')->writeString('someValue')

    // Write an entire document in one go
    ->writeKey('document')->writeDocument(MongoDB\BSON\Document::fromPHP(['foo' => 'bar']))

    // Write an entire array in one go
    ->writeKey('array')->writeArray(MongoDB\BSON\ArrayList::fromPHP([1, 2, 'foo']))

    ->write();

var_dump($document instanceof MongoDB\BSON\Document);
var_dump($document->toPHP());

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
bool(true)
object(stdClass)#%d (%d) {
  ["_id"]=>
  object(MongoDB\BSON\ObjectId)#%d (%d) {
    ["oid"]=>
    string(24) "%s"
  }
  ["bar"]=>
  string(3) "bar"
  ["bool"]=>
  bool(true)
  ["pi"]=>
  float(3.1415926)
  ["int"]=>
  int(16)
  ["int32"]=>
  int(16)
  ["int64"]=>
  int(16)
  ["int64_implicit"]=>
  int(8589934592)
  ["null"]=>
  NULL
  ["string"]=>
  string(9) "someValue"
  ["document"]=>
  object(stdClass)#%d (%d) {
    ["foo"]=>
    string(3) "bar"
  }
  ["array"]=>
  array(3) {
    [0]=>
    int(1)
    [1]=>
    int(2)
    [2]=>
    string(3) "foo"
  }
}
===DONE===
