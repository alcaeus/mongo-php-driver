--TEST--
Decimal128: [decq626] fold-down full sequence
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('180000001364000000A0DEC5ADC935360000000000FE5F00');
$canonicalExtJson = '{"d" : {"$numberDecimal" : "1.000000000000000000000E+6132"}}';

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
180000001364000000a0dec5adc935360000000000fe5f00
180000001364000000a0dec5adc935360000000000fe5f00
{"d":{"$numberDecimal":"1.000000000000000000000E+6132"}}
{"d":{"$numberDecimal":"1.000000000000000000000E+6132"}}
180000001364000000a0dec5adc935360000000000fe5f00
180000001364000000a0dec5adc935360000000000fe5f00
===DONE===