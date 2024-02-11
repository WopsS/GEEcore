#pragma once

#include <filesystem>

#include <Windows.h>

#include <kangaru/kangaru.hpp>

#include <geecore/IAppMetadata.hpp>
#include <geecore/IModuleImage.hpp>

namespace geecore::detail
{
class ModuleImage : public IModuleImage
{
public:
    ModuleImage(HMODULE module);
    ~ModuleImage() noexcept override = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(ModuleImage);

    const std::filesystem::path& file_name() const noexcept override;

private:
    std::filesystem::path m_file_name;
};

struct ModuleImageService
    : kgr::single_service<ModuleImage>
    , kgr::overrides<geecore::ModuleImageService>
{
};
} // namespace geecore::detail
