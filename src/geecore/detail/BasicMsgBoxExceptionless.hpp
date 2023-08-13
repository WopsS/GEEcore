#pragma once

#include <expected>
#include <system_error>
#include <type_traits>

#include <geecore/MsgBoxPrimitives.hpp>
#include <geecore/SpecialMemberFunctions.hpp>
#include <geecore/detail/BaseMsgBox.hpp>
#include <geecore/drivers/IMsgBoxDriver.hpp>

namespace geecore::detail
{
/**
 * @brief A message box class for exception handling contexts.
 *
 * @tparam T The character type supported by the message box.
 *
 * @note It is important to create instances of this class directly rather than as pointers. This is because the message
 * box can store variables passed by pointer or reference, and managing their lifetimes properly is crucial for correct
 * behavior.
 */
template<typename T>
class [[nodiscard]] BasicMsgBoxExceptionless : private BaseMsgBox<BasicMsgBoxExceptionless<T>>
{
public:
    /**
     * @brief Constructs a BasicMsgBoxExceptionless object.
     *
     * @param driver[in] The message box driver.
     */
    BasicMsgBoxExceptionless(const IMsgBoxDriver<T>& driver) noexcept;

    /**
     * @brief Default destructor.
     */
    ~BasicMsgBoxExceptionless() noexcept = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(BasicMsgBoxExceptionless);

    /**
     * @brief Sets the title of the message box to the given value.
     *
     * @param title[in] The title of the message box.
     * @return A reference to the current object.
     */
    BasicMsgBoxExceptionless& with_title(const T* title) noexcept;

    /**
     * @brief Sets the text of the message box to the given value.
     *
     * @param text[in] The text of the message box.
     * @return A reference to the current object.
     */
    BasicMsgBoxExceptionless& with_text(const T* text) noexcept;

    /**
     * @brief Displays the message box.
     *
     * @return An std::expected object containing the selected button or an error code.
     *         Returns a valid result on success, or an error code on failure.
     *         The error code represents the failure to display the message box.
     */
    std::expected<MsgBoxSelection, std::error_code> show() const noexcept;

    using BaseMsgBox<BasicMsgBoxExceptionless<T>>::with_icon;
    using BaseMsgBox<BasicMsgBoxExceptionless<T>>::with_buttons;

private:
    const IMsgBoxDriver<T>& m_driver;
    const T* m_title;
    const T* m_text;
};

template<typename T>
inline BasicMsgBoxExceptionless<T>::BasicMsgBoxExceptionless(const IMsgBoxDriver<T>& driver) noexcept
    : m_driver(driver)
{
    if constexpr (std::is_same_v<T, wchar_t>)
    {
        m_title = L"GEEcore";
        m_text = L"";
    }
    else
    {
        m_title = "GEEcore";
        m_text = "";
    }
}

template<typename T>
inline BasicMsgBoxExceptionless<T>& BasicMsgBoxExceptionless<T>::with_title(const T* title) noexcept
{
    m_title = title;
    return *this;
}

template<typename T>
inline BasicMsgBoxExceptionless<T>& BasicMsgBoxExceptionless<T>::with_text(const T* text) noexcept
{
    m_text = text;
    return *this;
}

template<typename T>
inline std::expected<MsgBoxSelection, std::error_code> BasicMsgBoxExceptionless<T>::show() const noexcept
{
    return m_driver.show(BaseMsgBox<BasicMsgBoxExceptionless<T>>::icon(),
                         m_title,
                         m_text,
                         BaseMsgBox<BasicMsgBoxExceptionless<T>>::buttons());
}
} // namespace geecore::detail
