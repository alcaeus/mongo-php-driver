--TEST--
MongoDB\BSON\ObjectId #004 Constructor supports uppercase hexadecimal strings
--FILE--
<?php

var_dump(new MongoDB\BSON\ObjectId('56925B7330616224D0000001'));

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
object(MongoDB\BSON\ObjectId)#%d (%d) {
  ["timestamp"]=>
  int(1452432243)
}
===DONE===
