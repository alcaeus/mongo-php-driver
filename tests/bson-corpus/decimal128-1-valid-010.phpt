--TEST--
Decimal128: Special - Invalid representation treated as -0
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('18000000136400DCBA9876543210DEADBEEF00000010EC00');
$canonicalExtJson = '{"d" : {"$numberDecimal" : "-0"}}';

// Canonical BSON -> Native -> Canonical BSON
echo bin2hex(fromPHP(toPHP($canonicalBson))), "\n";

// Canonical BSON -> Canonical extJSON
echo json_canonicalize(toCanonicalExtendedJSON($canonicalBson)), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
18000000136400dcba9876543210deadbeef00000010ec00
{"d":{"$numberDecimal":"-0"}}
===DONE===