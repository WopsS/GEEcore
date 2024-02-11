#pragma once

#include <memory>

#include <kangaru/container.hpp>

#include <geecore/HostBuilder.hpp>
#include <geecore/SpecialMemberFunctions.hpp>

namespace geecore
{
class Host
{
public:
    ~Host() = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(Host);

    [[nodiscard]]
    static std::shared_ptr<geecore::Host> instance();

    [[nodiscard]]
    static void set_default_instance(std::shared_ptr<Host> instance);

    void start();
    void stop();

private:
    friend class HostBuilder;

    Host(kgr::container services);

    kgr::container m_services;
    bool m_is_started;
};
} // namespace geecore
