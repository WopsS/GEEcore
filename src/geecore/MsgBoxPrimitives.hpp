#pragma once

#include <cstdint>

namespace geecore
{
enum class MsgBoxIcon : std::uint8_t
{
    None = 0,
    Information,
    Warning,
    Error
};

enum class MsgBoxButtons : std::uint8_t
{
    Ok = 0,
    OkCancel,
    YesNo,
    YesNoCancel
};

enum class MsgBoxSelection : std::uint8_t
{
    Unknown = 0, // Used to specify unhandled values.
    Ok,
    Cancel,
    Yes,
    No
};
} // namespace geecore
