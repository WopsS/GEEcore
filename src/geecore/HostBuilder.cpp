#include <geecore/HostBuilder.hpp>

#include <geecore/Host.hpp>
#include <geecore/detail/HostImage.hpp>
#include <geecore/detail/LoaderLifetime.hpp>
#include <geecore/detail/ModuleImage.hpp>

geecore::HostBuilder::HostBuilder()
    : m_is_default(false)
{
    add_service<detail::HostImageService>();
}

geecore::HostBuilder& geecore::HostBuilder::add_module_image(HMODULE module_handle)
{
    add_service<detail::ModuleImageService>(module_handle);
    return *this;
}

geecore::HostBuilder& geecore::HostBuilder::set_as_default()
{
    m_is_default = true;
    return *this;
}

geecore::HostBuilder& geecore::HostBuilder::add_loader_lifetime()
{
    add_service<detail::LoaderLifetimeService>();
    return *this;
}

std::shared_ptr<geecore::Host> geecore::HostBuilder::build()
{
    std::shared_ptr<Host> host(new Host(std::move(m_services)));

    if (m_is_default)
    {
        Host::set_default_instance(host);
    }

    return host;
}
