#include <geecore/exceptions/Win32Exception.hpp>

#include <exception>
#include <stacktrace>
#include <system_error>

#include <Windows.h>
#include <fmt/core.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

using Catch::Matchers::Equals;

TEST_CASE("a win32 exception should contain the message, the win32 code, the win32 code's message, and the stacktrace "
          "when the 'Win32Exception(std::string_view, std::stacktrace)' constructor is called",
          "[exception]")
{
    SetLastError(ERROR_STATE_CREATE_CONTAINER_FAILED);

    auto stacktrace = std::stacktrace::current();
    auto e = geecore::Win32Exception("a test exception", stacktrace);

    REQUIRE_THAT(
        e.what(),
        Equals(fmt::format(
            "a test exception (last_error: 15805): State Manager failed to create the container.\n\nStacktrace:\n{}",
            std::to_string(stacktrace))));
}

TEST_CASE("a win32 exception should contain the message, the win32 code, the win32 code's message, and the stacktrace "
          "when the 'Win32Exception(std::string_view, const std::error_code&, std::stacktrace)' constructor is called",
          "[exception]")
{
    std::error_code ec(ERROR_STATE_CREATE_CONTAINER_FAILED, std::system_category());
    auto stacktrace = std::stacktrace::current();
    auto e = geecore::Win32Exception("a test exception", ec, stacktrace);

    REQUIRE_THAT(
        e.what(),
        Equals(fmt::format(
            "a test exception (last_error: 15805): State Manager failed to create the container.\n\nStacktrace:\n{}",
            std::to_string(stacktrace))));
}
