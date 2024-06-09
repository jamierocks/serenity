/*
 * Copyright (c) 2024, Jamie Mansfield <jmansfield@cadixdev.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibJS/Runtime/Realm.h>
#include <LibWeb/Bindings/TextTrackPrototype.h>
#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/HTML/EventNames.h>
#include <LibWeb/HTML/TextTrack.h>

namespace Web::HTML {

JS_DEFINE_ALLOCATOR(TextTrack);

WebIDL::ExceptionOr<JS::NonnullGCPtr<TextTrack>> TextTrack::construct_impl(JS::Realm& realm)
{
    return realm.heap().allocate<TextTrack>(realm, realm);
}

TextTrack::TextTrack(JS::Realm& realm)
    : DOM::EventTarget(realm)
{
}

TextTrack::~TextTrack() = default;

void TextTrack::initialize(JS::Realm& realm)
{
    Base::initialize(realm);
    WEB_SET_PROTOTYPE_FOR_INTERFACE(TextTrack);
}

// https://html.spec.whatwg.org/multipage/media.html#handler-texttrack-oncuechange
void TextTrack::set_oncuechange(WebIDL::CallbackType* event_handler)
{
    set_event_handler_attribute(HTML::EventNames::cuechange, event_handler);
}

// https://html.spec.whatwg.org/multipage/media.html#handler-texttrack-oncuechange
WebIDL::CallbackType* TextTrack::oncuechange()
{
    return event_handler_attribute(HTML::EventNames::cuechange);
}

}
