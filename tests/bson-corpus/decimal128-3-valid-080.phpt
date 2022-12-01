--TEST--
Decimal128: [basx296] some more negative zeros [systematic tests below]
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('1800000013640000000000000000000000000000003AB000');
$canonicalExtJson = '{"d" : {"$numberDecimal" : "-0.000"}}';
$degenerateExtJson = '{"d" : {"$numberDecimal" : "-0.0E-2"}}';

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
1800000013640000000000000000000000000000003ab000
1800000013640000000000000000000000000000003ab000
{"d":{"$numberDecimal":"-0.000"}}
{"d":{"$numberDecimal":"-0.000"}}
1800000013640000000000000000000000000000003ab000
1800000013640000000000000000000000000000003ab000
1800000013640000000000000000000000000000003ab000
1800000013640000000000000000000000000000003ab000
===DONE===