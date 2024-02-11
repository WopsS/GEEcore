#include <geecore/detail/ModuleImage.hpp>

#include <Windows.h>
#include <wil/win32_helpers.h>

geecore::detail::ModuleImage::ModuleImage(HMODULE module)
{
    auto file_name = wil::GetModuleFileNameW(module);
    auto file_path = std::filesystem::path(file_name.get());

    m_file_name = file_path.filename();
}

const std::filesystem::path& geecore::detail::ModuleImage::file_name() const noexcept
{
    return m_file_name;
}
