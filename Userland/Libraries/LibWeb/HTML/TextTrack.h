/*
 * Copyright (c) 2024, Jamie Mansfield <jmansfield@cadixdev.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/String.h>
#include <LibJS/Forward.h>
#include <LibJS/Heap/GCPtr.h>
#include <LibWeb/DOM/EventTarget.h>
#include <LibWeb/Forward.h>
#include <LibWeb/WebIDL/ExceptionOr.h>

namespace Web::HTML {

class TextTrack final : public DOM::EventTarget {
    WEB_PLATFORM_OBJECT(TextTrack, DOM::EventTarget);
    JS_DECLARE_ALLOCATOR(TextTrack);

public:
    static WebIDL::ExceptionOr<JS::NonnullGCPtr<TextTrack>> construct_impl(JS::Realm&);
    virtual ~TextTrack() override;

    void set_oncuechange(WebIDL::CallbackType*);
    WebIDL::CallbackType* oncuechange();

private:
    TextTrack(JS::Realm&);

    virtual void initialize(JS::Realm&) override;
};

}
