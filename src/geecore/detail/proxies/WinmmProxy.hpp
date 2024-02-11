#pragma once

#include <geecore/SpecialMemberFunctions.hpp>
#include <geecore/detail/DllProxy.hpp>

namespace geecore::detail
{
class WinmmProxy : public DllProxy
{
public:
    WinmmProxy() noexcept = default;
    virtual ~WinmmProxy() noexcept = default;

    GEECORE_NON_COPYABLE(WinmmProxy);
    GEECORE_NOEXCEPT_MOVEABLE(WinmmProxy);

    std::wstring_view name() const override;

private:
    void resolve_exports() const override;
    void clear_resolved_exports() const override;
};
} // namespace geecore::detail
