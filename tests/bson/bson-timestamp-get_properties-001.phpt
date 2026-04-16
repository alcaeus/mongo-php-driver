--TEST--
MongoDB\BSON\Timestamp get_properties handler (get_object_vars)
--FILE--
<?php

$timestamp = new MongoDB\BSON\Timestamp(1234, 5678);

var_dump(get_object_vars($timestamp));

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
array(2) {
  ["increment"]=>
  int(1234)
  ["timestamp"]=>
  int(5678)
}
===DONE===
