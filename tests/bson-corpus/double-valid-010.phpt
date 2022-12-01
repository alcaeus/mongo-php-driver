--TEST--
Double type: NaN with payload
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('10000000016400120000000000F87F00');
$canonicalExtJson = '{"d": {"$numberDouble": "NaN"}}';
$relaxedExtJson = '{"d": {"$numberDouble": "NaN"}}';

// Canonical BSON -> Native -> Canonical BSON
echo bin2hex(fromPHP(toPHP($canonicalBson))), "\n";

// Canonical BSON -> Native -> Canonical BSON
echo bin2hex((string) MongoDB\BSON\Document::fromBSONString($canonicalBson)), "\n";

// Canonical BSON -> Canonical extJSON
echo json_canonicalize(toCanonicalExtendedJSON($canonicalBson)), "\n";

// Canonical BSON -> BSON object -> Canonical extJSON
echo json_canonicalize(MongoDB\BSON\Document::fromBSONString($canonicalBson)->toCanonicalExtendedJSON()), "\n";

// Canonical BSON -> Relaxed extJSON
echo json_canonicalize(toRelaxedExtendedJSON($canonicalBson)), "\n";

// Canonical BSON -> BSON object -> Relaxed extJSON
echo json_canonicalize(MongoDB\BSON\Document::fromBSONString($canonicalBson)->toRelaxedExtendedJSON()), "\n";

// Relaxed extJSON -> BSON -> Relaxed extJSON
echo json_canonicalize(toRelaxedExtendedJSON(fromJSON($relaxedExtJson))), "\n";

// Relaxed extJSON -> BSON object -> Relaxed extJSON
echo json_canonicalize(MongoDB\BSON\Document::fromJSON($relaxedExtJson)->toRelaxedExtendedJSON()), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
10000000016400120000000000f87f00
10000000016400120000000000f87f00
{"d":{"$numberDouble":"NaN"}}
{"d":{"$numberDouble":"NaN"}}
{"d":{"$numberDouble":"NaN"}}
{"d":{"$numberDouble":"NaN"}}
{"d":{"$numberDouble":"NaN"}}
{"d":{"$numberDouble":"NaN"}}
===DONE===