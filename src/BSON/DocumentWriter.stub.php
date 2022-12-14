<?php

/**
 * @generate-class-entries static
 * @generate-function-entries static
 */

namespace MongoDB\BSON;

final class DocumentWriter
{
    // TODO: Naming - I'm not happy with this
    final public function write(): Document {}

    // This allows us to create codecs that write a value without knowing what field to write to.
    // However, the resulting API in the other write methods gets unwieldy as it's counter-intuitive
    final public function writeKey(string $key): DocumentWriter {}

    // PHP base types
    final public function writeBoolean(bool $value): DocumentWriter {}
    final public function writeDouble(float $value): DocumentWriter {}
#if PHP_VERSION_ID >= 80000
    final public function writeInt(int|Int64 $value): DocumentWriter {}
#else
    /** @param int|int64 $value */
    final public function writeInt($value): DocumentWriter {}
#endif
    final public function writeNull(): DocumentWriter {}
    final public function writeString(string $value): DocumentWriter {}

    // BSON types
    final public function writeBinary(BinaryInterface $value): DocumentWriter {}
    final public function writeDecimal128(Decimal128Interface $value): DocumentWriter {}

    // TODO: do we want/need explicit 32-bit and 64-bit methods?
    final public function writeInt32(int $value): DocumentWriter {}
#if PHP_VERSION_ID >= 80000
    final public function writeInt64(int|Int64 $value): DocumentWriter {}
#else
    /** @param int|int64 $value */
    final public function writeInt64($value): DocumentWriter {}
#endif
    final public function writeJavascript(JavascriptInterface $value): DocumentWriter {}
    final public function writeMaxKey(): DocumentWriter {}
    final public function writeMinKey(): DocumentWriter {}
    final public function writeObjectId(ObjectIdInterface $value): DocumentWriter {}
    final public function writeRegularExpression(RegexInterface $value): DocumentWriter {}
    final public function writeTimestamp(TimestampInterface $value): DocumentWriter {}
    final public function writeUTCDateTime(UTCDateTimeInterface $value): DocumentWriter {}

    // Arrays and documents
    final public function writeArray(ArrayList $array): DocumentWriter {}

    final public function writeDocument(Document $document): DocumentWriter {}
}
