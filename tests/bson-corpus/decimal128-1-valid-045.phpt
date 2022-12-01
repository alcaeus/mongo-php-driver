--TEST--
Decimal128: Non-Canonical Parsing - infinity
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('180000001364000000000000000000000000000000007800');
$canonicalExtJson = '{"d" : {"$numberDecimal" : "Infinity"}}';
$degenerateExtJson = '{"d" : {"$numberDecimal" : "infinity"}}';

// Canonical BSON -> Native -> Canonical BSON
echo bin2hex(fromPHP(toPHP($canonicalBson))), "\n";

// Canonical BSON -> Native -> Canonical BSON
echo bin2hex((string) MongoDB\BSON\Document::fromBSONString($canonicalBson)), "\n";

// Canonical BSON -> Canonical extJSON
echo json_canonicalize(toCanonicalExtendedJSON($canonicalBson)), "\n";

// Canonical BSON -> BSON object -> Canonical extJSON
echo json_canonicalize(MongoDB\BSON\Document::fromBSONString($canonicalBson)->toCanonicalExtendedJSON()), "\n";

// Canonical extJSON -> Canonical BSON
echo bin2hex(fromJSON($canonicalExtJson)), "\n";

// Canonical extJSON -> BSON object -> Canonical BSON
echo bin2hex((string) MongoDB\BSON\Document::fromJSON($canonicalExtJson)), "\n";

// Degenerate extJSON -> Canonical BSON
echo bin2hex(fromJSON($degenerateExtJson)), "\n";

// Degenerate extJSON -> BSON object -> Canonical BSON
echo bin2hex((string) MongoDB\BSON\Document::fromJSON($degenerateExtJson)), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
180000001364000000000000000000000000000000007800
180000001364000000000000000000000000000000007800
{"d":{"$numberDecimal":"Infinity"}}
{"d":{"$numberDecimal":"Infinity"}}
180000001364000000000000000000000000000000007800
180000001364000000000000000000000000000000007800
180000001364000000000000000000000000000000007800
180000001364000000000000000000000000000000007800
===DONE===