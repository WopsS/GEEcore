#include <geecore/detail/DllProxy.hpp>

#include <wil/win32_helpers.h>

#include <geecore/exceptions/Win32Exception.hpp>

void geecore::detail::DllProxy::load()
{
    load_module();
    resolve_exports();
}

void geecore::detail::DllProxy::unload()
{
    clear_resolved_exports();
    m_module.reset();
}

void geecore::detail::DllProxy::load_module()
{
    auto system_directory = wil::GetSystemDirectoryW();

    auto module_path = std::filesystem::path(system_directory.get()) / name();
    module_path.replace_extension(L"dll");

    // TODO: Duplicate for ModuleLifetime.
    auto module = LoadLibraryW(module_path.c_str());
    if (!module)
    {
        throw Win32Exception("The proxy module could not be loaded");
    }

    m_module.reset(module);
}
