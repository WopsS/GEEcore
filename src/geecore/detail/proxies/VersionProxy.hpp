#pragma once

#include <geecore/SpecialMemberFunctions.hpp>
#include <geecore/detail/DllProxy.hpp>

namespace geecore::detail
{
class VersionProxy : public DllProxy
{
public:
    VersionProxy() noexcept = default;
    virtual ~VersionProxy() noexcept = default;

    GEECORE_NON_COPYABLE(VersionProxy);
    GEECORE_NOEXCEPT_MOVEABLE(VersionProxy);

    std::wstring_view name() const override;

private:
    void resolve_exports() const override;
    void clear_resolved_exports() const override;
};
} // namespace geecore::detail
