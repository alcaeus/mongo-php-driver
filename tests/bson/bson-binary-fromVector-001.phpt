--TEST--
MongoDB\BSON\Binary::fromVector() construction of various vector types
--FILE--
<?php

var_dump(MongoDB\BSON\Binary::fromVector([1.0, -1.0, 0.5, -0.5], MongoDB\BSON\VectorType::Float32));
var_dump(MongoDB\BSON\Binary::fromVector([-128, 0, 1, 127], MongoDB\BSON\VectorType::Int8));
var_dump(MongoDB\BSON\Binary::fromVector([1, 0, true, false], MongoDB\BSON\VectorType::PackedBit));

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
object(MongoDB\BSON\Binary)#%d (%d) {
  ["data"]=>
  string(%d) "%a"
  ["type"]=>
  int(9)
}
object(MongoDB\BSON\Binary)#%d (%d) {
  ["data"]=>
  string(%d) "%a"
  ["type"]=>
  int(9)
}
object(MongoDB\BSON\Binary)#%d (%d) {
  ["data"]=>
  string(%d) "%a"
  ["type"]=>
  int(9)
}
===DONE===
