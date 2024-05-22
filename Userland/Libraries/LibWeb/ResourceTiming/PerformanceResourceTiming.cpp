/*
 * Copyright (c) 2024, Jamie Mansfield <jmansfield@cadixdev.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/Bindings/PerformanceResourceTimingPrototype.h>
#include <LibWeb/Fetch/Infrastructure/FetchTimingInfo.h>
#include <LibWeb/ResourceTiming/PerformanceResourceTiming.h>

namespace Web::ResourceTiming {

JS_DEFINE_ALLOCATOR(PerformanceResourceTiming);

void PerformanceResourceTiming::initialize(JS::Realm& realm)
{
    Base::initialize(realm);
    WEB_SET_PROTOTYPE_FOR_INTERFACE(PerformanceResourceTiming);
}

// https://w3c.github.io/resource-timing/#dfn-setup-the-resource-timing-entry
void PerformanceResourceTiming::setup(String initiator_type, String requested_url, Fetch::Infrastructure::FetchTimingInfo timing_info, String cache_mode, Fetch::Infrastructure::Response::BodyInfo body_info, u16 response_status, String delivery_type)
{
    // 1. Assert that cacheMode is the empty string, "local", or "validated".
    VERIFY(cache_mode.is_empty() || cache_mode == "local" || cache_mode == "validated");

    // 2. Let global be entry's relevant global object.
    // 3. Initialize entry given the result of converting timingInfo's start time given global, "resource", requestedURL, and the result of converting timingInfo's end time given global.
    initialise_entry(timing_info.start_time(), PerformanceTimeline::EntryTypes::resource, requested_url, timing_info.end_time());

    // 4. Set entry's initiator type to initiatorType.
    m_initiator_type = initiator_type;

    // 5. Set entry's requested URL to requestedURL.
    m_requested_url = requested_url;

    // 6. Set entry's timing info to timingInfo.
    m_timing_info = timing_info;

    // 7. Set entry's response body info to bodyInfo.
    m_body_info = body_info;

    // 8. Set entry's cache mode to cacheMode.
    m_cache_mode = cache_mode;

    // 9. Set entry's response status to responseStatus.
    m_response_status = response_status;

    // 10. If deliveryType is the empty string and cacheMode is not, then set deliveryType to "cache".
    if (delivery_type.is_empty() && !cache_mode.is_empty())
        delivery_type = "cache"_string;

    // 11. Set entry's delivery type to deliveryType.
    m_delivery_type = delivery_type;
}

}
