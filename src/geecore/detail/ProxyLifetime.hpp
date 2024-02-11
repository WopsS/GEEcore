#pragma once

#include <filesystem>
#include <list>
#include <memory>
#include <string>

#include <geecore/ILifetime.hpp>
#include <geecore/IModuleImage.hpp>
#include <geecore/SpecialMemberFunctions.hpp>
#include <geecore/detail/DllProxy.hpp>

namespace geecore::detail
{
class ProxyLifetime : public ILifetime
{
public:
    ProxyLifetime(const IModuleImage& module_image);
    ~ProxyLifetime() noexcept override = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(ProxyLifetime);

    void start() override;
    void stop() override;

private:
    [[nodiscard]]
    static const std::list<std::shared_ptr<DllProxy>>& supported_proxies();

    [[nodiscard]]
    static std::shared_ptr<DllProxy> find_proxy_by_name(const std::wstring& name);

    [[nodiscard]]
    static std::filesystem::path resolve_proxy_name_for_module(const IModuleImage& module_image);

    [[nodiscard]]
    static std::shared_ptr<DllProxy> find_proxy_for_module(const IModuleImage& module_image);

    std::shared_ptr<DllProxy> m_proxy;
};
} // namespace geecore::detail
