#pragma once

#include <geecore/MsgBoxPrimitives.hpp>
#include <geecore/SpecialMemberFunctions.hpp>

namespace geecore::detail
{
template<typename T>
class [[nodiscard]] BaseMsgBox
{
public:
    /**
     * @brief Sets the icon of the message box to the specified icon.
     *
     * @param icon[in] The icon to set.
     * @return A reference to the current object.
     */
    T& with_icon(MsgBoxIcon icon) noexcept;

    /**
     * @brief Sets the buttons of the message box to the specified buttons.
     *
     * @param buttons[in] The buttons to set.
     * @return A reference to the current object.
     */
    T& with_buttons(MsgBoxButtons buttons) noexcept;

protected:
    BaseMsgBox() noexcept;
    ~BaseMsgBox() noexcept = default;

    GEECORE_NOEXCEPT_COPYABLE_AND_MOVEABLE(BaseMsgBox);

    MsgBoxIcon icon() const noexcept;
    MsgBoxButtons buttons() const noexcept;

private:
    MsgBoxIcon m_icon;
    MsgBoxButtons m_buttons;
};

template<typename T>
inline BaseMsgBox<T>::BaseMsgBox() noexcept
    : m_icon(MsgBoxIcon::None)
    , m_buttons(MsgBoxButtons::Ok)
{
}

template<typename T>
inline MsgBoxIcon BaseMsgBox<T>::icon() const noexcept
{
    return m_icon;
}

template<typename T>
inline T& BaseMsgBox<T>::with_icon(MsgBoxIcon icon) noexcept
{
    m_icon = icon;
    return *reinterpret_cast<T*>(this);
}

template<typename T>
inline MsgBoxButtons BaseMsgBox<T>::buttons() const noexcept
{
    return m_buttons;
}

template<typename T>
inline T& BaseMsgBox<T>::with_buttons(MsgBoxButtons buttons) noexcept
{
    m_buttons = buttons;
    return *reinterpret_cast<T*>(this);
}
} // namespace geecore::detail
