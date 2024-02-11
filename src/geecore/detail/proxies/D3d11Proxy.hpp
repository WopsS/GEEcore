#pragma once

#include <geecore/SpecialMemberFunctions.hpp>
#include <geecore/detail/DllProxy.hpp>

namespace geecore::detail
{
class D3d11Proxy : public DllProxy
{
public:
    D3d11Proxy() noexcept = default;
    virtual ~D3d11Proxy() noexcept = default;

    GEECORE_NON_COPYABLE(D3d11Proxy);
    GEECORE_NOEXCEPT_MOVEABLE(D3d11Proxy);

    std::wstring_view name() const override;

private:
    void resolve_exports() const override;
    void clear_resolved_exports() const override;
};
} // namespace geecore::detail
