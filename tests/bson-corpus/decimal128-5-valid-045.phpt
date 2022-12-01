--TEST--
Decimal128: [decq621] fold-down full sequence (Clamped)
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('18000000136400000080F64AE1C7022D1500000000FE5F00');
$canonicalExtJson = '{"d" : {"$numberDecimal" : "1.00000000000000000000000E+6134"}}';
$degenerateExtJson = '{"d" : {"$numberDecimal" : "1E+6134"}}';

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
18000000136400000080f64ae1c7022d1500000000fe5f00
18000000136400000080f64ae1c7022d1500000000fe5f00
{"d":{"$numberDecimal":"1.00000000000000000000000E+6134"}}
{"d":{"$numberDecimal":"1.00000000000000000000000E+6134"}}
18000000136400000080f64ae1c7022d1500000000fe5f00
18000000136400000080f64ae1c7022d1500000000fe5f00
18000000136400000080f64ae1c7022d1500000000fe5f00
18000000136400000080f64ae1c7022d1500000000fe5f00
===DONE===