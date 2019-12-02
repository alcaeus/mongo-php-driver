--TEST--
MongoDB\Driver\Manager::__construct(): auto encryption options
--FILE--
<?php

$baseOptions = [
    'keyVaultNamespace' => 'admin.dataKeys',
    'kmsProviders' => ['aws' => (object) ['accessKeyId' => 'abc', 'secretAccessKey' => 'def']]
];

$tests = [
    [],
    ['keyVaultClient' => new MongoDB\Driver\Manager()],
    ['schemaMap' => [
        'default.default' => [
            'properties' => [
                'encrypted_objectId' => [
                    'encrypt' => [
                        'keyId' => [
                            [
                                '$binary' => [
                                    'base64' => 'AAAAAAAAAAAAAAAAAAAAAA==',
                                    'subType' => '04',
                                ],
                            ],
                        ],
                        'bsonType' => 'objectId',
                        'algorithm' => 'AEAD_AES_256_CBC_HMAC_SHA_512-Deterministic',
                    ],
                ],
            ],
            'bsonType' => 'object',
        ],
    ]],
    ['bypassAutoEncryption' => true],
    ['extraOptions' => ['mongocryptdBypassSpawn' => true]],
];

foreach ($tests as $driverOptions) {
    $manager = new MongoDB\Driver\Manager(null, [], ['autoEncryption' => $driverOptions + $baseOptions]);
    var_dump($manager);
}

?>
===DONE===
<?php exit(0); ?>
--EXPECTF--
object(MongoDB\Driver\Manager)#%d (%d) {
  ["uri"]=>
  string(20) "mongodb://127.0.0.1/"
  ["cluster"]=>
  array(0) {
  }
}
object(MongoDB\Driver\Manager)#%d (%d) {
  ["uri"]=>
  string(20) "mongodb://127.0.0.1/"
  ["cluster"]=>
  array(0) {
  }
}
object(MongoDB\Driver\Manager)#%d (%d) {
  ["uri"]=>
  string(20) "mongodb://127.0.0.1/"
  ["cluster"]=>
  array(0) {
  }
}
object(MongoDB\Driver\Manager)#%d (%d) {
  ["uri"]=>
  string(20) "mongodb://127.0.0.1/"
  ["cluster"]=>
  array(0) {
  }
}
object(MongoDB\Driver\Manager)#%d (%d) {
  ["uri"]=>
  string(20) "mongodb://127.0.0.1/"
  ["cluster"]=>
  array(0) {
  }
}
===DONE===
