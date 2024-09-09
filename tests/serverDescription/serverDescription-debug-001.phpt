--TEST--
MongoDB\Driver\ServerDescription debug output
--SKIPIF--
<?php require __DIR__ . "/../utils/basic-skipif.inc"; ?>
<?php skip_if_not_live(); ?>
--FILE--
<?php
require_once __DIR__ . "/../utils/basic.inc";

$manager = create_test_manager();
$server = $manager->selectServer(new MongoDB\Driver\ReadPreference('primary'));
var_dump($server->getServerDescription());

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
object(MongoDB\Driver\ServerDescription)#%d (%d) {
  ["helloResponse"]=>
  array(%d) {%A
  }
  ["host"]=>
  string(%d) "%s"
  ["lastUpdateTime"]=>
  %r(string\(\d+\) "\d+"|int\(\d+\))%r
  ["roundTripTime"]=>
  %r(NULL|int\(\d+\))%r
  ["port"]=>
  int(%d)
  ["type"]=>
  string(%d) "%r(Standalone|Mongos|RSPrimary|LoadBalancer)%r"
}
===DONE===
