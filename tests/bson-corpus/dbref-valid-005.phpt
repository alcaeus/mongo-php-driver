--TEST--
Document type (DBRef sub-documents): Document with key names similar to those of a DBRef
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('3e0000000224726566000c0000006e6f742d612d646272656600072469640058921b3e6e32ab156a22b59e022462616e616e6100050000007065656c0000');
$canonicalExtJson = '{"$ref": "not-a-dbref", "$id": {"$oid": "58921b3e6e32ab156a22b59e"}, "$banana": "peel"}';

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
3e0000000224726566000c0000006e6f742d612d646272656600072469640058921b3e6e32ab156a22b59e022462616e616e6100050000007065656c0000
3e0000000224726566000c0000006e6f742d612d646272656600072469640058921b3e6e32ab156a22b59e022462616e616e6100050000007065656c0000
{"$ref":"not-a-dbref","$id":{"$oid":"58921b3e6e32ab156a22b59e"},"$banana":"peel"}
{"$ref":"not-a-dbref","$id":{"$oid":"58921b3e6e32ab156a22b59e"},"$banana":"peel"}
3e0000000224726566000c0000006e6f742d612d646272656600072469640058921b3e6e32ab156a22b59e022462616e616e6100050000007065656c0000
3e0000000224726566000c0000006e6f742d612d646272656600072469640058921b3e6e32ab156a22b59e022462616e616e6100050000007065656c0000
===DONE===