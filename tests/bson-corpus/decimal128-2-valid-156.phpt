--TEST--
Decimal128: [decq020] Normality
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('18000000136400F2AF967ED05C82DE3297FF6FDE3C403000');
$canonicalExtJson = '{"d" : {"$numberDecimal" : "1234567890123456789012345678901234"}}';

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
18000000136400f2af967ed05c82de3297ff6fde3c403000
18000000136400f2af967ed05c82de3297ff6fde3c403000
{"d":{"$numberDecimal":"1234567890123456789012345678901234"}}
{"d":{"$numberDecimal":"1234567890123456789012345678901234"}}
18000000136400f2af967ed05c82de3297ff6fde3c403000
18000000136400f2af967ed05c82de3297ff6fde3c403000
===DONE===