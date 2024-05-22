/*
 * Copyright (c) 2023, Luke Wilde <lukew@serenityos.org>
 * Copyright (c) 2024, Jamie Mansfield <jmansfield@cadixdev.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/Bindings/PerformanceEntryPrototype.h>
#include <LibWeb/PerformanceTimeline/PerformanceEntry.h>

namespace Web::PerformanceTimeline {

PerformanceEntry::PerformanceEntry(JS::Realm& realm, String const& name, HighResolutionTime::DOMHighResTimeStamp start_time, HighResolutionTime::DOMHighResTimeStamp duration)
    : Bindings::PlatformObject(realm)
    , m_name(name)
    , m_start_time(start_time)
    , m_duration(duration)
{
}

PerformanceEntry::~PerformanceEntry() = default;

void PerformanceEntry::initialize(JS::Realm& realm)
{
    Base::initialize(realm);
    WEB_SET_PROTOTYPE_FOR_INTERFACE(PerformanceEntry);
}

// https://w3c.github.io/performance-timeline/#dfn-initialize-a-performanceentry
void PerformanceEntry::initialise_entry(HighResolutionTime::DOMHighResTimeStamp start_time, FlyString const&, String const& name, HighResolutionTime::DOMHighResTimeStamp end_time)
{
    // NOTE: Not all specs use this function, so in the interim this supplements the pre-existing constructor & overloading functions.

    // FIXME: 1. Assert: entryType is defined in the entry type registry.

    // 2. Initialize entry's startTime to startTime.
    m_start_time = start_time;

    // FIXME: 3. Initialize entry's entryType to entryType.

    // 4. Initialize entry's name to name.
    m_name = name;

    // 5. Initialize entry's end time to endTime.
    // NOTE: The getter steps for the duration attribute are to return 0 if this's end time is 0; otherwise this's end time - this's startTime.
    if (end_time == 0) {
        m_duration = 0;
    } else {
        m_duration = end_time - start_time;
    }
}

}
