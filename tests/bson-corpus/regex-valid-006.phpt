--TEST--
Regular Expression type: flags not alphabetized
--DESCRIPTION--
Generated by scripts/convert-bson-corpus-tests.php

DO NOT EDIT THIS FILE
--FILE--
<?php

require_once __DIR__ . '/../utils/basic.inc';

$canonicalBson = hex2bin('100000000B610061626300696D780000');
$degenerateBson = hex2bin('100000000B6100616263006D69780000');
$canonicalExtJson = '{"a" : {"$regularExpression" : { "pattern": "abc", "options" : "imx"}}}';
$degenerateExtJson = '{"a" : {"$regularExpression" : { "pattern": "abc", "options" : "mix"}}}';

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

// Degenerate BSON -> Native -> Canonical BSON
echo bin2hex(fromPHP(toPHP($degenerateBson))), "\n";

// Degenerate BSON -> Native -> Canonical BSON
echo bin2hex(fromPHP(MongoDB\BSON\Document::fromBSONString($degenerateBson)->toPHP())), "\n";

// Degenerate BSON -> Canonical extJSON
echo json_canonicalize(toCanonicalExtendedJSON($degenerateBson)), "\n";

// Degenerate BSON -> BSON object -> Canonical extJSON
echo json_canonicalize(MongoDB\BSON\Document::fromBSONString($degenerateBson)->toCanonicalExtendedJSON()), "\n";

// Degenerate extJSON -> Canonical BSON
echo bin2hex(fromJSON($degenerateExtJson)), "\n";

// Degenerate extJSON -> BSON object -> Canonical BSON
echo bin2hex((string) MongoDB\BSON\Document::fromJSON($degenerateExtJson)), "\n";

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
100000000b610061626300696d780000
100000000b610061626300696d780000
{"a":{"$regularExpression":{"pattern":"abc","options":"imx"}}}
{"a":{"$regularExpression":{"pattern":"abc","options":"imx"}}}
100000000b610061626300696d780000
100000000b610061626300696d780000
100000000b610061626300696d780000
100000000b610061626300696d780000
{"a":{"$regularExpression":{"pattern":"abc","options":"imx"}}}
{"a":{"$regularExpression":{"pattern":"abc","options":"imx"}}}
100000000b610061626300696d780000
100000000b610061626300696d780000
===DONE===