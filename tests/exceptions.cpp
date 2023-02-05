#include <Windows.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include <fmt/format.h>

#include <geecore/exceptions.hpp>

using Catch::Matchers::Equals;

TEST_CASE("an exception should contain the message and the stacktrace when 'exception(std::string_view, "
          "std::stacktrace)' constructor is called",
          "[exception]")
{
    auto stacktrace = std::stacktrace::current();
    auto e = geecore::exception("a test exception", stacktrace);

    REQUIRE_THAT(e.what(), Equals(fmt::format("a test exception\n\nStacktrace:\n{}", std::to_string(stacktrace))));
}

TEST_CASE("an exception should contain the message, the details, and the stacktrace when 'exception(std::string_view, "
          "std::stacktrace, const std::function<void(...)>&)' constructor is called",
          "[exception]")
{
    auto stacktrace = std::stacktrace::current();
    auto e =
        geecore::exception("a test exception", stacktrace,
                           [](std::back_insert_iterator<fmt::memory_buffer>& out) { fmt::format_to(out, "HELLO"); });

    REQUIRE_THAT(e.what(),
                 Equals(fmt::format("a test exception (HELLO)\n\nStacktrace:\n{}", std::to_string(stacktrace))));
}

TEST_CASE("an exception should contain the message, the message, and the stacktrace when 'exception(std::string_view, "
          "std::stacktrace, {}, const std::function<void(...)>&)' constructor is called",
          "[exception]")
{
    auto stacktrace = std::stacktrace::current();
    auto e =
        geecore::exception("a test exception", stacktrace, {},
                           [](std::back_insert_iterator<fmt::memory_buffer>& out) { fmt::format_to(out, "HELLO"); });

    REQUIRE_THAT(e.what(),
                 Equals(fmt::format("a test exception: HELLO\n\nStacktrace:\n{}", std::to_string(stacktrace))));
}

TEST_CASE("an exception should contain the message, the message, and the stacktrace when 'exception(std::string_view, "
          "std::stacktrace, const std::function<void(...)>&, const std::function<void(...)>&)' constructor is called",
          "[exception]")
{
    auto stacktrace = std::stacktrace::current();
    auto e = geecore::exception(
        "a test exception", stacktrace,
        [](std::back_insert_iterator<fmt::memory_buffer>& out) { fmt::format_to(out, "HELLO"); },
        [](std::back_insert_iterator<fmt::memory_buffer>& out) { fmt::format_to(out, "CAN YOU CATCH THIS?"); });

    REQUIRE_THAT(e.what(), Equals(fmt::format("a test exception (HELLO): CAN YOU CATCH THIS?\n\nStacktrace:\n{}",
                                              std::to_string(stacktrace))));
}
