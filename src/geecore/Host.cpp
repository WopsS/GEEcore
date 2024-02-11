#include <geecore/Host.hpp>

#include <type_traits>

#include <geecore/Exception.hpp>
#include <geecore/IHostLifetime.hpp>

namespace
{
std::shared_ptr<geecore::Host> g_default_instance;
}

geecore::Host::Host(kgr::container services)
    : m_services(std::move(services))
    , m_is_started(false)
{
}

std::shared_ptr<geecore::Host> geecore::Host::instance()
{
    return g_default_instance;
}

void geecore::Host::set_default_instance(std::shared_ptr<geecore::Host> instance)
{
    g_default_instance = std::move(instance);
}

void geecore::Host::start()
{
    if (m_is_started)
    {
        throw Exception("The host has already been started");
    }

    auto& lifetime = m_services.service<detail::HostLifetimeService>();
    lifetime.start();

    m_is_started = true;
}

void geecore::Host::stop()
{
    if (!m_is_started)
    {
        // No action needed if the host is not started.
        // Avoid throwing exceptions here, as this function may be called in sensitive contexts,such as DllMain during
        // unloading.
        return;
    }

    auto& lifetime = m_services.service<detail::HostLifetimeService>();
    lifetime.stop();

    m_is_started = false;
}
