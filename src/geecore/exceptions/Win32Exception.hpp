#pragma once

#include <stacktrace>
#include <string>
#include <system_error>

#include <geecore/Exception.hpp>

namespace geecore
{
/**
 * @brief An exception representing a Win32 error.
 */
class [[nodiscard]] Win32Exception : public Exception
{
public:
    /**
     * @brief Constructs a new exception using the last error code returned by 'GetLastError'.
     *
     * @param[in] what_msg      Explanatory string.
     * @param[in] stacktrace    The stacktrace where the exception occured.
     *
     * @throw std::bad_alloc
     */
    Win32Exception(std::string_view what_msg, std::stacktrace stacktrace = std::stacktrace::current());

    /**
     * @brief Constructs a new exception using the specified Win32 error code.
     *
     * @param[in] what_msg      Explanatory string.
     * @param[in] win32_err     The Win32 error.
     * @param[in] stacktrace    The stacktrace where the exception occured.
     *
     * @throw std::bad_alloc
     */
    Win32Exception(std::string_view what_msg,
                   const std::error_code& win32_err,
                   std::stacktrace stacktrace = std::stacktrace::current());

    /**
     * @brief Get the stored last error.
     * @return The stored last error.
     */
    [[nodiscard]]
    const std::error_code& last_error() const noexcept;

private:
    std::error_code m_last_error;
};
} // namespace geecore
