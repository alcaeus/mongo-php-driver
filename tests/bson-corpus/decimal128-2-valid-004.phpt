--TEST--
Decimal128: [decq821] values around [u]int32 edges (zeros done earlier)
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('18000000136400FFFFFF7F0000000000000000000040B000');
$canonicalExtJson = '{"d" : {"$numberDecimal" : "-2147483647"}}';

// Canonical BSON -> Native -> Canonical BSON
echo bin2hex(fromPHP(toPHP($canonicalBson))), "\n";

// Canonical BSON -> Canonical extJSON
echo json_canonicalize(toCanonicalExtendedJSON($canonicalBson)), "\n";

// Canonical extJSON -> Canonical BSON
echo bin2hex(fromJSON($canonicalExtJson)), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
18000000136400ffffff7f0000000000000000000040b000
{"d":{"$numberDecimal":"-2147483647"}}
18000000136400ffffff7f0000000000000000000040b000
===DONE===