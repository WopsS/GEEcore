#include <geecore/detail/HostImage.hpp>

#include <Windows.h>
#include <wil/win32_helpers.h>

geecore::detail::HostImage::HostImage()
{
    auto file_name = wil::GetModuleFileNameW();
    auto file_path = std::filesystem::path(file_name.get());

    m_directory = file_path.parent_path();
    m_file_name = file_path.filename();
}

const std::filesystem::path& geecore::detail::HostImage::directory() const noexcept
{
    return m_directory;
}

const std::filesystem::path& geecore::detail::HostImage::file_name() const noexcept
{
    return m_file_name;
}
