<?php

/**
 * @generate-class-entries static
 * @generate-function-entries static
 */

namespace MongoDB\Driver;

/** @not-serializable */
final class ServerDescription
{
    /**
     * @var string
     * @cvalue PHONGO_SERVER_TYPE_UNKNOWN
     */
    public const TYPE_UNKNOWN = UNKNOWN;

    /**
     * @var string
     * @cvalue PHONGO_SERVER_TYPE_STANDALONE
     */
    public const TYPE_STANDALONE = UNKNOWN;

    /**
     * @var string
     * @cvalue PHONGO_SERVER_TYPE_MONGOS
     */
    public const TYPE_MONGOS = UNKNOWN;

    /**
     * @var string
     * @cvalue PHONGO_SERVER_TYPE_POSSIBLE_PRIMARY
     */
    public const TYPE_POSSIBLE_PRIMARY = UNKNOWN;

    /**
     * @var string
     * @cvalue PHONGO_SERVER_TYPE_RS_PRIMARY
     */
    public const TYPE_RS_PRIMARY = UNKNOWN;

    /**
     * @var string
     * @cvalue PHONGO_SERVER_TYPE_RS_SECONDARY
     */
    public const TYPE_RS_SECONDARY = UNKNOWN;

    /**
     * @var string
     * @cvalue PHONGO_SERVER_TYPE_RS_ARBITER
     */
    public const TYPE_RS_ARBITER = UNKNOWN;

    /**
     * @var string
     * @cvalue PHONGO_SERVER_TYPE_RS_OTHER
     */
    public const TYPE_RS_OTHER = UNKNOWN;

    /**
     * @var string
     * @cvalue PHONGO_SERVER_TYPE_RS_GHOST
     */
    public const TYPE_RS_GHOST = UNKNOWN;

    /**
     * @var string
     * @cvalue PHONGO_SERVER_TYPE_LOAD_BALANCER
     */
    public const TYPE_LOAD_BALANCER = UNKNOWN;

    public readonly array $helloResponse;
    public readonly string $host;
    public readonly int $lastUpdateTime;
    public readonly ?int $roundTripTime;
    public readonly int $port;
    public readonly string $type;

    final private function __construct() {}

    /** @deprecated */
    final public function getHelloResponse(): array {}

    /** @deprecated */
    final public function getHost(): string {}

    /** @deprecated */
    final public function getLastUpdateTime(): int {}

    /** @deprecated */
    final public function getPort(): int {}

    /** @deprecated */
    final public function getRoundTripTime(): ?int {}

    /** @deprecated */
    final public function getType(): string {}
}
