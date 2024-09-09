--TEST--
MongoDB\Driver\ServerDescription: var_export()
--SKIPIF--
<?php require __DIR__ . "/../utils/basic-skipif.inc"; ?>
<?php skip_if_not_live(); ?>
<?php skip_if_not_clean(); ?>
--FILE--
<?php
require_once __DIR__ . "/../utils/basic.inc";

$manager = create_test_manager();
$server = $manager->selectServer(new MongoDB\Driver\ReadPreference('primary'));

echo var_export($server->getServerDescription(), true), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
%r\\?%rMongoDB\Driver\ServerDescription::__set_state(array(
   'helloResponse' =>%w
  array (%A
  ),
   'host' => '%s',
   'lastUpdateTime' => %r('\d+'|\d+)%r,
   'roundTripTime' => %r(NULL|\d+)%r,
   'port' => %d,
   'type' => '%r(Standalone|Mongos|RSPrimary|LoadBalancer)%r',
))
===DONE===
