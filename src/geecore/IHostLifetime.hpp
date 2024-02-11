#pragma once

#include <kangaru/kangaru.hpp>

#include <geecore/ILifetime.hpp>
#include <geecore/SpecialMemberFunctions.hpp>

namespace geecore
{
class IHostLifetime : public ILifetime
{
public:
    IHostLifetime() noexcept = default;
    virtual ~IHostLifetime() noexcept override = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(IHostLifetime);
};

namespace detail
{
struct HostLifetimeService : kgr::abstract_service<IHostLifetime>
{
};
} // namespace detail
} // namespace geecore
