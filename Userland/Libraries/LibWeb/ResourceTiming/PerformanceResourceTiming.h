/*
 * Copyright (c) 2024, Jamie Mansfield <jmansfield@cadixdev.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/Fetch/Response.h>
#include <LibWeb/PerformanceTimeline/EntryTypes.h>
#include <LibWeb/PerformanceTimeline/PerformanceEntry.h>

namespace Web::ResourceTiming {

// https://w3c.github.io/resource-timing/#dom-performanceresourcetiming
class PerformanceResourceTiming final : public PerformanceTimeline::PerformanceEntry {
    WEB_PLATFORM_OBJECT(PerformanceResourceTiming, PerformanceTimeline::PerformanceEntry);
    JS_DECLARE_ALLOCATOR(PerformanceResourceTiming);

public:
    void setup(String initiator_type, String requested_url, Fetch::Infrastructure::FetchTimingInfo timing_info, String cache_mode, Fetch::Infrastructure::Response::BodyInfo body_info, u16 response_status, String delivery_type);

    FlyString const& entry_type() const override { return PerformanceTimeline::EntryTypes::resource; };

    PerformanceTimeline::ShouldAddEntry should_add_entry(Optional<PerformanceTimeline::PerformanceObserverInit const&> = {}) const override { return PerformanceTimeline::ShouldAddEntry::Yes; };

    String initiator_type() { return m_initiator_type; }
    String delivery_type() { return m_delivery_type; }
    u16 response_status() { return m_response_status; }

private:
    virtual void initialize(JS::Realm&) override;

    String m_initiator_type;
    String m_delivery_type;
    String m_requested_url;
    JS::GCPtr<Fetch::Infrastructure::FetchTimingInfo> m_timing_info;
    Fetch::Infrastructure::Response::BodyInfo m_body_info;
    String m_cache_mode;
    u16 m_response_status
};

}
