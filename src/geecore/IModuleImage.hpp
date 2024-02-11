#pragma once

#include <filesystem>

#include <kangaru/kangaru.hpp>

#include <geecore/SpecialMemberFunctions.hpp>

namespace geecore
{
class IModuleImage
{
public:
    IModuleImage() noexcept = default;
    virtual ~IModuleImage() noexcept = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(IModuleImage);

    /**
     * @brief Returns the file name of the module.
     * @return The file name of the module.
     */
    virtual const std::filesystem::path& file_name() const noexcept = 0;
};

struct ModuleImageService : kgr::abstract_service<IModuleImage>
{
};
} // namespace geecore
