--TEST--
MongoDB\BSON\Timestamp debug handler
--FILE--
<?php

$timestamp = new MongoDB\BSON\Timestamp(1234, 5678);

var_dump($timestamp);

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
object(MongoDB\BSON\Timestamp)#1 (2) {
  ["increment"]=>
  int(1234)
  ["timestamp"]=>
  int(5678)
}
===DONE===
