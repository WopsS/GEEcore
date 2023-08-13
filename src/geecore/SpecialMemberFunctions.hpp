#pragma once

#define GEECORE_COPYABLE(cls)                                                                                          \
    cls(const cls&) = default;                                                                                         \
    cls& operator=(const cls&) = default

#define GEECORE_NOEXCEPT_COPYABLE(cls)                                                                                 \
    cls(const cls&) noexcept = default;                                                                                \
    cls& operator=(const cls&) noexcept = default

#define GEECORE_NOEXCEPT_MOVEABLE(cls)                                                                                 \
    cls(cls&&) noexcept = default;                                                                                     \
    cls& operator=(cls&&) noexcept = default

#define GEECORE_NOEXCEPT_COPYABLE_AND_MOVEABLE(cls)                                                                    \
    GEECORE_NOEXCEPT_COPYABLE(cls);                                                                                    \
    GEECORE_NOEXCEPT_MOVEABLE(cls)

#define GEECORE_NON_COPYABLE(cls)                                                                                      \
    cls(const cls&) = delete;                                                                                          \
    cls& operator=(const cls&) = delete

#define GEECORE_NON_MOVEABLE(cls)                                                                                      \
    cls(cls&&) = delete;                                                                                               \
    cls& operator=(cls&&) = delete

#define GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(cls)                                                                     \
    GEECORE_NON_COPYABLE(cls);                                                                                         \
    GEECORE_NON_MOVEABLE(cls)
