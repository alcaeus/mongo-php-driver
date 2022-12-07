--TEST--
MongoDB\BSON\ArrayList::fromPHP(): create from PHP array
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

var_dump(MongoDB\BSON\ArrayList::fromPHP([1, 2, 3]));

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
object(MongoDB\BSON\ArrayList)#%d (%d) {
  ["data"]=>
  string(36) "GgAAABAwAAEAAAAQMQACAAAAEDIAAwAAAAA="
  ["length"]=>
  int(26)
}
===DONE===
