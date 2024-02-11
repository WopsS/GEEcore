#pragma once

#include <memory>
#include <utility>

#include <Windows.h>

#include <kangaru/kangaru.hpp>

#include <geecore/SpecialMemberFunctions.hpp>

namespace geecore
{
class Host;

/**
 * @brief A builder class for creating Host objects
 */
class [[nodiscard]] HostBuilder
{
public:
    /**
     * @brief Default constructor.
     */
    HostBuilder();

    /**
     * @brief Default destructor.
     */
    ~HostBuilder() = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(HostBuilder);

    /**
     * @brief Adds a service to the Host with the provided arguments.
     *
     * @tparam T    The service type to be added.
     * @tparam Args The argument types for constructing the service.
     *
     * @param args[in] The arguments for constructing the service.
     * @return Reference to the HostBuilder instance for chaining.
     */
    template<typename T, typename... Args>
    HostBuilder& add_service(Args&&... args);

    /**
     * @brief Adds a mapped service to the Host with the provided arguments.
     *
     * @tparam T    The service type to be added.
     * @tparam Args The argument types for constructing the service.
     *
     * @param args[in] The arguments for constructing the service.
     * @return Reference to the HostBuilder instance for chaining.
     */
    template<typename T, typename... Args>
    HostBuilder& add_mapped_service(Args&&... args);

    /**
     * @brief Adds the loader lifetime service to the Host.
     *
     * @return Reference to the HostBuilder instance for chaining.
     */
    HostBuilder& add_loader_lifetime();

    /**
     * @brief Adds the module image to the Host.
     *
     * @param module_image[in] The module image to be added.
     * @return Reference to the HostBuilder instance for chaining.
     */
    HostBuilder& add_module_image(HMODULE module_handle);

    /**
     * @brief Sets the Host build by this class as the default instance.
     *
     * @return Reference to the HostBuilder instance for chaining.
     */
    HostBuilder& set_as_default();

    /**
     * @brief Constructs and returns a shared pointer to the constructed Host object.
     *
     * @return A std::shared_ptr to the constructed Host.
     */
    [[nodiscard]]
    std::shared_ptr<geecore::Host> build();

private:
    kgr::container m_services;

    bool m_is_default;
};

template<typename T, typename... Args>
inline HostBuilder& HostBuilder::add_service(Args&&... args)
{
    m_services.emplace<T>(std::forward<Args>(args)...);
    return *this;
}

template<typename T, typename... Args>
inline HostBuilder& HostBuilder::add_mapped_service(Args&&... args)
{
    m_services.emplace<kgr::mapped_service_t<T>>(std::forward<Args>(args)...);
    return *this;
}
} // namespace geecore
