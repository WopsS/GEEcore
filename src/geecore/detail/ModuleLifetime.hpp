#pragma once

#include <Windows.h>
#include <wil/resource.h>

#include <geecore/ILifetime.hpp>
#include <geecore/ILoaderAppMetadata.hpp>
#include <geecore/SpecialMemberFunctions.hpp>

namespace geecore::detail
{
class ModuleLifetime : public ILifetime
{
public:
    ModuleLifetime(const ILoaderAppMetadata& app_metadata);
    ~ModuleLifetime() noexcept override = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(ModuleLifetime);

    void start() override;
    void stop() override;

private:
    const ILoaderAppMetadata& m_app_metadata;
    wil::unique_hmodule m_module;
};
} // namespace geecore::detail
