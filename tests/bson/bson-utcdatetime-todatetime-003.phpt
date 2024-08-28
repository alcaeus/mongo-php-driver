--TEST--
MongoDB\BSON\UTCDateTime::toDateTime() with dates before the Unix epoch
--INI--
date.timezone=UTC
--FILE--
<?php

$date = new \DateTimeImmutable('1960-01-01 12:12:12.1');
echo $date->format('Y-m-d H:i:s.u'), PHP_EOL;

$utcdatetime = new MongoDB\BSON\UTCDateTime($date);

$newDate = $utcdatetime->toDateTime();
echo $newDate->format('Y-m-d H:i:s.u'), PHP_EOL;

?>
===DONE===
<?php exit(0); ?>
--EXPECT--
1960-01-01 12:12:12.100000
1960-01-01 12:12:12.100000
===DONE===
