<?php

/**
 * @generate-class-entries static
 * @generate-function-entries static
 */

namespace MongoDB\BSON;

final class Writer
{
    // TODO: Naming - I'm not happy with this
    final public function write(): Document {}

    // This allows us to create codecs that write a value without knowing what field to write to.
    // However, the resulting API in the other write methods gets unwieldy as it's counter-intuitive
    final public function writeKey(string $key): Writer {}

    // PHP base types
    final public function writeBoolean(bool $value): Writer {}
    final public function writeDouble(float $value): Writer {}
#if PHP_VERSION_ID >= 80000
    final public function writeInt(int|Int64 $value): Writer {}
#else
    /** @param int|int64 $value */
    final public function writeInt($value): Writer {}
#endif
    final public function writeNull(): Writer {}
    final public function writeString(string $value): Writer {}

    // BSON types
    final public function writeBinary(BinaryInterface $value): Writer {}
    final public function writeDecimal128(Decimal128Interface $value): Writer {}

    // TODO: do we want/need explicit 32-bit and 64-bit methods?
    final public function writeInt32(int $value): Writer {}
#if PHP_VERSION_ID >= 80000
    final public function writeInt64(int|Int64 $value): Writer {}
#else
    /** @param int|int64 $value */
    final public function writeInt64($value): Writer {}
#endif
    final public function writeJavascript(JavascriptInterface $value): Writer {}
    final public function writeMaxKey(): Writer {}
    final public function writeMinKey(): Writer {}
    final public function writeObjectId(ObjectIdInterface $value): Writer {}
    final public function writeRegularExpression(RegexInterface $value): Writer {}
    final public function writeTimestamp(TimestampInterface $value): Writer {}
    final public function writeUTCDateTime(UTCDateTimeInterface $value): Writer {}

    // Arrays and documents
    final public function writeArray(ArrayList $array): Writer {}

    final public function writeDocument(Document $document): Writer {}
}
