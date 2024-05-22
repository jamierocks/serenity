/*
 * Copyright (c) 2024, Jamie Mansfield <jmansfield@cadixdev.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/HTML/EmbedderPolicy.h>

namespace Web::HTML {

StringView to_string(EmbedderPolicyValue embedder_policy_value)
{
    switch (embedder_policy_value) {
    case EmbedderPolicyValue::UnsafeNone:
        return "unsafe-none"sv;
    case EmbedderPolicyValue::RequireCorp:
        return "require-corp"sv;
    case EmbedderPolicyValue::Credentialless:
        return "credentialless"sv;
    }
    VERIFY_NOT_REACHED();
}

Optional<EmbedderPolicyValue> from_string(StringView string)
{
    if (string.equals_ignoring_ascii_case("unsafe-none"sv))
        return EmbedderPolicyValue::UnsafeNone;
    if (string.equals_ignoring_ascii_case("require-corp"sv))
        return EmbedderPolicyValue::RequireCorp;
    if (string.equals_ignoring_ascii_case("credentialless"sv))
        return EmbedderPolicyValue::Credentialless;
    return {};
}

}
