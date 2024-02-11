#pragma once

#include <filesystem>

#include <kangaru/kangaru.hpp>

#include <geecore/IAppMetadata.hpp>
#include <geecore/IHostImage.hpp>

namespace geecore::detail
{
class HostImage : public IHostImage
{
public:
    HostImage();
    ~HostImage() noexcept override = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(HostImage);

    const std::filesystem::path& directory() const noexcept override;
    const std::filesystem::path& file_name() const noexcept override;

private:
    std::filesystem::path m_directory;
    std::filesystem::path m_file_name;
};

struct HostImageService
    : kgr::single_service<HostImage>
    , kgr::overrides<geecore::HostImageService>
{
};
} // namespace geecore::detail
