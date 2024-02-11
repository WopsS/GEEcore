#include <geecore/detail/LoaderLifetime.hpp>

#include <utility>

#include <geecore/Exception.hpp>

geecore::detail::LoaderLifetime::LoaderLifetime(const ILoaderAppMetadata& app_metadata,
                                                const IModuleImage& module_image)
    : m_proxy_lifetime(module_image)
    , m_module_lifetime(app_metadata)
{
}

void geecore::detail::LoaderLifetime::start()
{
    m_proxy_lifetime.start();
    m_module_lifetime.start();
}

void geecore::detail::LoaderLifetime::stop()
{
    m_module_lifetime.stop();
    m_proxy_lifetime.stop();
}
