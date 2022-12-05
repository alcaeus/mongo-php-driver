--TEST--
Regular Expression type: regex with options
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('0F0000000B610061626300696D0000');
$canonicalExtJson = '{"a" : {"$regularExpression" : { "pattern": "abc", "options" : "im"}}}';

// Canonical BSON -> Native -> Canonical BSON
echo bin2hex(fromPHP(toPHP($canonicalBson))), "\n";

// Canonical BSON -> Canonical extJSON
echo json_canonicalize(toCanonicalExtendedJSON($canonicalBson)), "\n";

// Canonical extJSON -> Canonical BSON
echo bin2hex(fromJSON($canonicalExtJson)), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
0f0000000b610061626300696d0000
{"a":{"$regularExpression":{"pattern":"abc","options":"im"}}}
0f0000000b610061626300696d0000
===DONE===