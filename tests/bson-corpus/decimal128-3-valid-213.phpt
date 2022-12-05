--TEST--
Decimal128: [basx305] Engineering notation tests
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('180000001364000A00000000000000000000000000543000');
$canonicalExtJson = '{"d" : {"$numberDecimal" : "1.0E+11"}}';
$degenerateExtJson = '{"d" : {"$numberDecimal" : "10e10"}}';

// Canonical BSON -> Native -> Canonical BSON
echo bin2hex(fromPHP(toPHP($canonicalBson))), "\n";

// Canonical BSON -> Canonical extJSON
echo json_canonicalize(toCanonicalExtendedJSON($canonicalBson)), "\n";

// Canonical extJSON -> Canonical BSON
echo bin2hex(fromJSON($canonicalExtJson)), "\n";

// Degenerate extJSON -> Canonical BSON
echo bin2hex(fromJSON($degenerateExtJson)), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
180000001364000a00000000000000000000000000543000
{"d":{"$numberDecimal":"1.0E+11"}}
180000001364000a00000000000000000000000000543000
180000001364000a00000000000000000000000000543000
===DONE===