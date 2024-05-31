/*
 * Copyright (c) 2024, Andrew Kaster <akaster@serenityos.org>
 * Copyright (c) 2024, Jamie Mansfield <jmansfield@cadixdev.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "LibWeb/Fetch/Infrastructure/NetworkPartitionKey.h"
#include <LibWeb/Fetch/Request.h>

namespace Web::Fetch::Infrastructure {

// https://fetch.spec.whatwg.org/#determine-the-network-partition-key
NetworkPartitionKey determine_the_network_partition_key(HTML::Environment const& environment)
{
    // 1. Let topLevelOrigin be environment’s top-level origin.
    auto top_level_origin = environment.top_level_origin;

    // FIXME: 2. If topLevelOrigin is null, then set topLevelOrigin to environment’s top-level creation URL’s origin
    // This field is supposed to be nullable

    // 3. Assert: topLevelOrigin is an origin.

    // FIXME: 4. Let topLevelSite be the result of obtaining a site, given topLevelOrigin.

    // 5. Let secondKey be null or an implementation-defined value.
    void* second_key = nullptr;

    // 6. Return (topLevelSite, secondKey).
    return { top_level_origin, second_key };
}

// https://fetch.spec.whatwg.org/#request-determine-the-network-partition-key
Optional<NetworkPartitionKey> determine_the_network_partition_key(Infrastructure::Request const& request)
{
    // 1. If request’s reserved client is non-null, then return the result of determining the network partition key given request’s reserved client.
    if (auto reserved_client = request.reserved_client())
        return determine_the_network_partition_key(*reserved_client);

    // 2. If request’s client is non-null, then return the result of determining the network partition key given request’s client.
    if (auto client = request.client())
        return determine_the_network_partition_key(*client);

    return {};
}

// https://fetch.spec.whatwg.org/#resolve-an-origin
void resolve_an_origin(NetworkPartitionKey key, HTML::Origin origin)
{
    // 1. If origin’s host is an IP address, then return « origin’s host ».
    origin.host();

    // 2. If origin’s host’s public suffix is "localhost" or "localhost.", then return « ::1, 127.0.0.1 ».

    // 3. Perform an implementation-defined operation to turn origin into a set of one or more IP addresses.
    //     - It is also implementation-defined whether other operations might be performed to get connection information
    //       beyond just IP addresses. For example, if origin’s scheme is an HTTP(S) scheme, the implementation might perform
    //       a DNS query for HTTPS RRs. [SVCB]
    //     - If this operation succeeds, return the set of IP addresses and any additional implementation-defined information.

    // 4. Return failure.
}

}
