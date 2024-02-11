#include <geecore/detail/ProxyLifetime.hpp>

#include <string.h>

#include <geecore/Exception.hpp>
#include <geecore/detail/proxies/D3d11Proxy.hpp>
#include <geecore/detail/proxies/DxgiProxy.hpp>
#include <geecore/detail/proxies/VersionProxy.hpp>
#include <geecore/detail/proxies/WinmmProxy.hpp>

geecore::detail::ProxyLifetime::ProxyLifetime(const IModuleImage& module_image)
{
    m_proxy = find_proxy_for_module(module_image);
    if (!m_proxy)
    {
        throw geecore::Exception("The proxy referenced by this DLL is not supported by the application");
    }
}

void geecore::detail::ProxyLifetime::start()
{
    if (m_proxy)
    {
        m_proxy->load();
    }
}

void geecore::detail::ProxyLifetime::stop()
{
    if (m_proxy)
    {
        m_proxy->unload();
    }
}

const std::list<std::shared_ptr<geecore::detail::DllProxy>>& geecore::detail::ProxyLifetime::supported_proxies()
{
    static const std::list<std::shared_ptr<geecore::detail::DllProxy>> proxies = {std::make_shared<D3d11Proxy>(),
                                                                                  std::make_shared<DxgiProxy>(),
                                                                                  std::make_shared<VersionProxy>(),
                                                                                  std::make_shared<WinmmProxy>()};
    return proxies;
}

std::shared_ptr<geecore::detail::DllProxy> geecore::detail::ProxyLifetime::find_proxy_by_name(const std::wstring& name)
{
    for (const auto& proxy : supported_proxies())
    {
        const auto proxy_name = proxy->name();
        if (_wcsicmp(proxy_name.data(), name.c_str()) == 0)
        {
            return proxy;
        }
    }

    return nullptr;
}

std::filesystem::path geecore::detail::ProxyLifetime::resolve_proxy_name_for_module(const IModuleImage& module_image)
{
    const auto& file_name = module_image.file_name();
    return file_name.stem();
}

std::shared_ptr<geecore::detail::DllProxy> geecore::detail::ProxyLifetime::find_proxy_for_module(
    const IModuleImage& module_image)
{
    const auto proxy_name = resolve_proxy_name_for_module(module_image);
    return find_proxy_by_name(proxy_name);
}
