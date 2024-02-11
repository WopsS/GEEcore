#pragma once

#include <kangaru/kangaru.hpp>

#include <geecore/IHostLifetime.hpp>
#include <geecore/ILoaderAppMetadata.hpp>
#include <geecore/IModuleImage.hpp>
#include <geecore/detail/ModuleLifetime.hpp>
#include <geecore/detail/ProxyLifetime.hpp>

namespace geecore::detail
{
class LoaderLifetime : public IHostLifetime
{
public:
    LoaderLifetime(const ILoaderAppMetadata& app_metadata, const IModuleImage& module_image);
    ~LoaderLifetime() noexcept override = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(LoaderLifetime);

    void start() override;
    void stop() override;

private:
    ProxyLifetime m_proxy_lifetime;
    ModuleLifetime m_module_lifetime;
};

struct LoaderLifetimeService
    : kgr::single_service<LoaderLifetime, kgr::dependency<LoaderAppMetadataService, ModuleImageService>>
    , kgr::overrides<HostLifetimeService>
{
};
} // namespace geecore::detail
