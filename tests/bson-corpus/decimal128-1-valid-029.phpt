--TEST--
Decimal128: Scientific - 0 with Negative Exponent
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('1800000013640000000000000000000000000000007A2B00');
$canonicalExtJson = '{"d" : {"$numberDecimal" : "0E-611"}}';

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

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
1800000013640000000000000000000000000000007a2b00
1800000013640000000000000000000000000000007a2b00
{"d":{"$numberDecimal":"0E-611"}}
{"d":{"$numberDecimal":"0E-611"}}
1800000013640000000000000000000000000000007a2b00
1800000013640000000000000000000000000000007a2b00
===DONE===