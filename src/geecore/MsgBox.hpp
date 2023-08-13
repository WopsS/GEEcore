#pragma once

#include <geecore/detail/BasicMsgBoxExceptionless.hpp>
#include <geecore/detail/drivers/Win32MsgBoxDriver.hpp>

namespace geecore
{
/**
 * @brief A message box driver using Win32 to display messages.
 * @note The driver supports wide characters (wchar_t) for the message box content.
 */
using Win32MsgBoxDriver = detail::Win32MsgBoxDriver<wchar_t>;

/**
 * @brief An ANSI message box driver using Win32 to display messages.
 * @note The driver supports narrow characters (char) for the message box content.
 */
using Win32MsgBoxDriverAnsi = detail::Win32MsgBoxDriver<char>;

/**
 * @brief A message box class for exception handling contexts.
 *
 * @note It is important to create instances of this class directly rather than as pointers. This is because the message
 * box can store variables passed by pointer or reference, and managing their lifetimes properly is crucial for correct
 * behavior.
 *
 * @note The message box supports wide characters (wchar_t) for the content.
 */
using MsgBoxExceptionless = detail::BasicMsgBoxExceptionless<wchar_t>;

/**
 * @brief An ASNI message box class for exception handling contexts.
 *
 * @note Same as MsgBoxExceptionless.
 * @note The message box supports narrow characters (char) for the content.
 */
using MsgBoxExceptionlessAnsi = detail::BasicMsgBoxExceptionless<char>;
} // namespace geecore
