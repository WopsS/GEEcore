#pragma once

#include <filesystem>

#include <kangaru/kangaru.hpp>

#include <geecore/SpecialMemberFunctions.hpp>

namespace geecore
{
class IHostImage
{
public:
    IHostImage() noexcept = default;
    virtual ~IHostImage() noexcept = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(IHostImage);

    /**
     * @brief Returns the directory from where the host image is running.
     * @return The directory from where the host image is running.
     */
    virtual const std::filesystem::path& directory() const noexcept = 0;

    /**
     * @brief Returns the file name of the host image.
     * @return The file name of the host image.
     */
    virtual const std::filesystem::path& file_name() const noexcept = 0;
};

struct HostImageService : kgr::abstract_service<IHostImage>
{
};
} // namespace geecore
