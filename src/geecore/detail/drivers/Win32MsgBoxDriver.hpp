#pragma once

#include <cassert>
#include <expected>
#include <system_error>
#include <type_traits>

#include <Windows.h>

#include <geecore/MsgBoxPrimitives.hpp>
#include <geecore/SpecialMemberFunctions.hpp>
#include <geecore/drivers/IMsgBoxDriver.hpp>

namespace geecore::detail
{
/**
 * @brief A message box driver using Win32 to display messages.
 */
template<typename T>
class [[nodiscard]] Win32MsgBoxDriver : public IMsgBoxDriver<T>
{
public:
    Win32MsgBoxDriver() noexcept = default;
    ~Win32MsgBoxDriver() noexcept = default;

    GEECORE_NOEXCEPT_COPYABLE_AND_MOVEABLE(Win32MsgBoxDriver);

    [[nodiscard]]
    virtual std::expected<MsgBoxSelection, std::error_code> show(MsgBoxIcon icon,
                                                                 const T* title,
                                                                 const T* text,
                                                                 MsgBoxButtons buttons) const noexcept;

private:
    static UINT convert_icon_to_native(MsgBoxIcon icon) noexcept;
    static UINT convert_buttons_to_native(MsgBoxButtons buttons) noexcept;
    static std::expected<MsgBoxSelection, std::error_code> convert_native_result(int result) noexcept;
};

template<typename T>
inline std::expected<MsgBoxSelection, std::error_code> Win32MsgBoxDriver<T>::show(MsgBoxIcon icon,
                                                                                  const T* title,
                                                                                  const T* text,
                                                                                  MsgBoxButtons buttons) const noexcept
{
    auto flags = convert_icon_to_native(icon) | convert_buttons_to_native(buttons);

    int result;
    if constexpr (std::is_same_v<T, WCHAR>)
    {
        result = MessageBoxW(nullptr, text, title, flags);
    }
    else
    {
        result = MessageBoxA(nullptr, text, title, flags);
    }

    return convert_native_result(result);
}

template<typename T>
inline UINT Win32MsgBoxDriver<T>::convert_icon_to_native(MsgBoxIcon icon) noexcept
{
    switch (icon)
    {
    case MsgBoxIcon::Information:
    {
        return MB_ICONINFORMATION;
    }
    case MsgBoxIcon::Warning:
    {
        return MB_ICONWARNING;
    }
    case MsgBoxIcon::Error:
    {
        return MB_ICONERROR;
    }
    default:
    {
        return 0;
    }
    }
}

template<typename T>
inline UINT Win32MsgBoxDriver<T>::convert_buttons_to_native(MsgBoxButtons buttons) noexcept
{
    switch (buttons)
    {
    case MsgBoxButtons::Ok:
    {
        return MB_OK;
    }
    case MsgBoxButtons::OkCancel:
    {
        return MB_OKCANCEL;
    }
    case MsgBoxButtons::YesNo:
    {
        return MB_YESNO;
    }
    case MsgBoxButtons::YesNoCancel:
    {
        return MB_YESNOCANCEL;
    }
    default:
    {
        return 0;
    }
    }
}

template<typename T>
inline std::expected<MsgBoxSelection, std::error_code> Win32MsgBoxDriver<T>::convert_native_result(int result) noexcept
{
    if (result == 0)
    {
        auto err = GetLastError();
        std::error_code ec(err, std::system_category());

        return std::unexpected(std::move(ec));
    }

    switch (result)
    {
    case IDOK:
    {
        return MsgBoxSelection::Ok;
    }
    case IDCANCEL:
    {
        return MsgBoxSelection::Cancel;
    }
    case IDYES:
    {
        return MsgBoxSelection::Yes;
    }
    case IDNO:
    {
        return MsgBoxSelection::Yes;
    }
    default:
    {
        // This path should never be reached.
        assert(false);
        return MsgBoxSelection::Unknown;
    }
    }
}
} // namespace geecore::detail
