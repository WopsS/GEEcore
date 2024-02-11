#include <geecore/exceptions/Win32Exception.hpp>

#include <iterator>
#include <stacktrace>
#include <string>
#include <system_error>

#include <Windows.h>

#include <fmt/core.h>
#include <fmt/format.h>

#include <geecore/Exception.hpp>

geecore::Win32Exception::Win32Exception(std::string_view what_msg, std::stacktrace stacktrace)
    : Win32Exception(what_msg, {static_cast<int>(GetLastError()), std::system_category()}, stacktrace)
{
}

geecore::Win32Exception::Win32Exception(std::string_view what_msg,
                                        const std::error_code& win32_err,
                                        std::stacktrace stacktrace)
    : Exception(
          what_msg,
          stacktrace,
          [&win32_err](std::back_insert_iterator<fmt::memory_buffer>& out)
          { fmt::format_to(out, "last_error: {}", win32_err.value()); },
          [&win32_err](std::back_insert_iterator<fmt::memory_buffer>& out)
          { fmt::format_to(out, "{}", win32_err.message()); })
    , m_last_error(win32_err)
{
}

const std::error_code& geecore::Win32Exception::last_error() const noexcept
{
    return m_last_error;
}
