#include <geecore/exceptions.hpp>

#include <Windows.h>

geecore::exception::exception(
    std::string_view what_msg, std::stacktrace stacktrace,
    const std::function<void(std::back_insert_iterator<fmt::memory_buffer>&)>& details_appender_fn,
    const std::function<void(std::back_insert_iterator<fmt::memory_buffer>&)>& extra_message_appender_fn)
    : std::runtime_error(create_message(what_msg, stacktrace, details_appender_fn, extra_message_appender_fn))
{
}

std::string geecore::exception::create_message(
    std::string_view what_msg, std::stacktrace stacktrace,
    const std::function<void(std::back_insert_iterator<fmt::memory_buffer>&)>& details_appender_fn,
    const std::function<void(std::back_insert_iterator<fmt::memory_buffer>&)>& extra_message_appender_fn)
{
    auto buffer = fmt::memory_buffer();
    auto out = std::back_inserter(buffer);

    fmt::format_to(out, "{}", what_msg);

    if (details_appender_fn)
    {
        fmt::format_to(out, " (");
        details_appender_fn(out);
        fmt::format_to(out, ")");
    }

    if (extra_message_appender_fn)
    {
        fmt::format_to(out, ": ");
        extra_message_appender_fn(out);
    }

    fmt::format_to(out, "\n\nStacktrace:\n{}", std::to_string(stacktrace));
    return fmt::to_string(buffer);
}
