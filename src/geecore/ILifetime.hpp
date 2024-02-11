#pragma once

#include <geecore/SpecialMemberFunctions.hpp>

namespace geecore
{
class ILifetime
{
public:
    ILifetime() noexcept = default;
    virtual ~ILifetime() noexcept = default;

    GEECORE_NOEXCEPT_COPYABLE_AND_MOVEABLE(ILifetime);

    virtual void start() = 0;
    virtual void stop() = 0;
};
} // namespace geecore
