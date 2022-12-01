--TEST--
ObjectId: Random
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('1400000007610056E1FC72E0C917E9C471416100');
$canonicalExtJson = '{"a" : {"$oid" : "56e1fc72e0c917e9c4714161"}}';

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
1400000007610056e1fc72e0c917e9c471416100
1400000007610056e1fc72e0c917e9c471416100
{"a":{"$oid":"56e1fc72e0c917e9c4714161"}}
{"a":{"$oid":"56e1fc72e0c917e9c4714161"}}
1400000007610056e1fc72e0c917e9c471416100
1400000007610056e1fc72e0c917e9c471416100
===DONE===