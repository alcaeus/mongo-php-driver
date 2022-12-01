--TEST--
Document type (DBRef sub-documents): Sub-document resembles DBRef but $id is missing
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('26000000036462726566001a0000000224726566000b000000636f6c6c656374696f6e000000');
$canonicalExtJson = '{"dbref": {"$ref": "collection"}}';

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
26000000036462726566001a0000000224726566000b000000636f6c6c656374696f6e000000
26000000036462726566001a0000000224726566000b000000636f6c6c656374696f6e000000
{"dbref":{"$ref":"collection"}}
{"dbref":{"$ref":"collection"}}
26000000036462726566001a0000000224726566000b000000636f6c6c656374696f6e000000
26000000036462726566001a0000000224726566000b000000636f6c6c656374696f6e000000
===DONE===