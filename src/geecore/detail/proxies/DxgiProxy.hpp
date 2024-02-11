#pragma once

#include <geecore/SpecialMemberFunctions.hpp>
#include <geecore/detail/DllProxy.hpp>

namespace geecore::detail
{
class DxgiProxy : public DllProxy
{
public:
    DxgiProxy() noexcept = default;
    virtual ~DxgiProxy() noexcept = default;

    GEECORE_NON_COPYABLE(DxgiProxy);
    GEECORE_NOEXCEPT_MOVEABLE(DxgiProxy);

    std::wstring_view name() const override;

private:
    void resolve_exports() const override;
    void clear_resolved_exports() const override;
};
} // namespace geecore::detail
