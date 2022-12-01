--TEST--
Document type (DBRef sub-documents): DBRef with database and additional fields
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('48000000036462726566003c0000000224726566000b000000636f6c6c656374696f6e0010246964002a00000002246462000300000064620002666f6f0004000000626172000000');
$canonicalExtJson = '{"dbref": {"$ref": "collection", "$id": {"$numberInt": "42"}, "$db": "db", "foo": "bar"}}';

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
48000000036462726566003c0000000224726566000b000000636f6c6c656374696f6e0010246964002a00000002246462000300000064620002666f6f0004000000626172000000
48000000036462726566003c0000000224726566000b000000636f6c6c656374696f6e0010246964002a00000002246462000300000064620002666f6f0004000000626172000000
{"dbref":{"$ref":"collection","$id":{"$numberInt":"42"},"$db":"db","foo":"bar"}}
{"dbref":{"$ref":"collection","$id":{"$numberInt":"42"},"$db":"db","foo":"bar"}}
48000000036462726566003c0000000224726566000b000000636f6c6c656374696f6e0010246964002a00000002246462000300000064620002666f6f0004000000626172000000
48000000036462726566003c0000000224726566000b000000636f6c6c656374696f6e0010246964002a00000002246462000300000064620002666f6f0004000000626172000000
===DONE===