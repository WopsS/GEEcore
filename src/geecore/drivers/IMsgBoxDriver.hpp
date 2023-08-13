#pragma once

#include <expected>
#include <system_error>

#include <geecore/MsgBoxPrimitives.hpp>
#include <geecore/SpecialMemberFunctions.hpp>

namespace geecore
{
/**
 * @brief Interface for a message box driver.
 * @tparam T The character type for message box content.
 */
template<typename T>
class [[nodiscard]] IMsgBoxDriver
{
public:
    /**
     * @brief Default constructor.
     */
    IMsgBoxDriver() noexcept = default;

    /**
     * @brief Default destructor.
     */
    virtual ~IMsgBoxDriver() noexcept = default;

    GEECORE_NOEXCEPT_COPYABLE_AND_MOVEABLE(IMsgBoxDriver);

    /**
     * @brief Displays a message box with the specified icon, title, text, and buttons.
     *
     * @param[in] icon      The icon to display in the message box.
     * @param[in] title     The title of the message box.
     * @param[in] text      The text content of the message box.
     * @param[in] buttons   The buttons to include in the message box.
     *
     * @return Returns the selected button on success, or an error code on failure.
     */
    [[nodiscard]]
    virtual std::expected<MsgBoxSelection, std::error_code> show(MsgBoxIcon icon,
                                                                 const T* title,
                                                                 const T* text,
                                                                 MsgBoxButtons buttons) const noexcept = 0;
};
} // namespace geecore
