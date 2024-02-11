#pragma once

#include <filesystem>

#include <Windows.h>
#include <wil/resource.h>

#include <geecore/SpecialMemberFunctions.hpp>
#include <geecore/exceptions/Win32Exception.hpp>

namespace geecore::detail
{
class DllProxy
{
public:
    DllProxy() noexcept = default;
    virtual ~DllProxy() noexcept = default;

    GEECORE_NOEXCEPT_COPYABLE_AND_MOVEABLE(DllProxy);

    virtual std::wstring_view name() const = 0;

    void load();
    void unload();

protected:
    virtual void resolve_exports() const = 0;
    virtual void clear_resolved_exports() const = 0;

    template<typename T>
    [[nodiscard]]
    T get_proc_address(const std::string_view proc_name) const;

private:
    void load_module();

    wil::unique_hmodule m_module;
};

template<typename T>
inline T DllProxy::get_proc_address(const std::string_view proc_name) const
{
    // Not necessary to throw an exception here, as the address can be null. It can happen because of older operating
    // systems.

    auto address = GetProcAddress(m_module.get(), proc_name.data());
    return reinterpret_cast<T>(address);
}
} // namespace geecore::detail
