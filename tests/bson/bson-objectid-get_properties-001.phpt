--TEST--
MongoDB\BSON\ObjectId get_properties handler (get_object_vars)
--FILE--
<?php

$oid = new MongoDB\BSON\ObjectId('53e2a1c40640fd72175d4603');

var_dump(get_object_vars($oid));

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
array(1) {
  ["timestamp"]=>
  int(1407361476)
}
===DONE===
