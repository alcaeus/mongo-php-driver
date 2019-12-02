--TEST--
MongoDB\Driver\Manager::__construct(): incomplete auto encryption options
--FILE--
<?php

require_once __DIR__ . '/../utils/tools.php';

$tests = [
    [],
    ['keyVaultNamespace' => 'admin.keys'],
];

foreach ($tests as $driverOptions) {
    echo throws(function() use ($driverOptions) {
        $manager = new MongoDB\Driver\Manager(null, [], ['autoEncryption' => $driverOptions]);
    }, 'MongoDB\Driver\Exception\RuntimeException'), "\n\n";
}

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
OK: Got MongoDB\Driver\Exception\RuntimeException
Key vault namespace option required

OK: Got MongoDB\Driver\Exception\RuntimeException
KMS providers option required

===DONE===
