#include <geecore/detail/BasicMsgBoxExceptionless.hpp>

#include <string>
#include <string_view>
#include <type_traits>

#include <trompeloeil.hpp>

#include <catch2/catch_template_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/trompeloeil.hpp>

#include <geecore/MsgBoxPrimitives.hpp>
#include <mocks/MockMsgBoxDriver.hpp>

namespace geecore::tests
{
namespace
{
template<typename T>
std::basic_string<T> ansi_or_wide(const char* ansi, const wchar_t* wide)
{
    if constexpr (std::is_same_v<T, wchar_t>)
    {
        return wide;
    }
    else
    {
        return ansi;
    }
}

template<typename T>
auto generate_title()
{
    return GENERATE(geecore::tests::ansi_or_wide<T>("RED3ext", L"RED3ext"),
                    geecore::tests::ansi_or_wide<T>("RED4ext", L"RED4ext"));
}

template<typename T>
auto generate_text()
{
    return GENERATE(
        geecore::tests::ansi_or_wide<T>("Geralt is a witcher! :O", L"Geralt is a witcher! :O"),
        geecore::tests::ansi_or_wide<T>("Please do not break many things in next game patch",
                                        L"Please do not break many things in next game patch"),
        geecore::tests::ansi_or_wide<T>(
            "If you see this, please stop modding. Modding break games and don't work on consoles! :run:",
            L"If you see this, please stop modding. Modding break games and don't work on consoles! :run:"));
}
} // namespace
} // namespace geecore::tests

TEMPLATE_TEST_CASE("a 'MsgBoxExceptionless' should be default constructed with its title set to 'GEEcore'",
                   "[message_box]",
                   char,
                   wchar_t)
{
    std::basic_string<TestType> title;

    geecore::tests::MockMsgBoxDriver<TestType> driver;

    ALLOW_CALL(driver, show(trompeloeil::_, trompeloeil::_, trompeloeil::_, trompeloeil::_))
        .LR_SIDE_EFFECT(title = _2)
        .RETURN(geecore::MsgBoxSelection::Ok);

    geecore::detail::BasicMsgBoxExceptionless<TestType>(driver).show();

    REQUIRE(title == geecore::tests::ansi_or_wide<TestType>("GEEcore", L"GEEcore"));
}

TEMPLATE_TEST_CASE("a 'MsgBoxExceptionless' should be default constructed with its text empty",
                   "[message_box]",
                   char,
                   wchar_t)
{
    std::basic_string<TestType> text(10, static_cast<TestType>(65));

    geecore::tests::MockMsgBoxDriver<TestType> driver;

    ALLOW_CALL(driver, show(trompeloeil::_, trompeloeil::_, trompeloeil::_, trompeloeil::_))
        .LR_SIDE_EFFECT(text = _3)
        .RETURN(geecore::MsgBoxSelection::Ok);

    geecore::detail::BasicMsgBoxExceptionless<TestType>(driver).show();

    REQUIRE(text.empty());
}

TEMPLATE_TEST_CASE(
    "a 'MsgBoxExceptionless' should have its title set to the specified value when 'with_title' is called",
    "[message_box]",
    char,
    wchar_t)
{
    auto title = geecore::tests::generate_title<TestType>();

    geecore::tests::MockMsgBoxDriver<TestType> driver;

    ALLOW_CALL(driver, show(trompeloeil::_, trompeloeil::_, trompeloeil::_, trompeloeil::_))
        .RETURN(geecore::MsgBoxSelection::Unknown);

    REQUIRE_CALL(driver, show(trompeloeil::_, title.c_str(), trompeloeil::_, trompeloeil::_))
        .RETURN(geecore::MsgBoxSelection::Ok);

    geecore::detail::BasicMsgBoxExceptionless<TestType>(driver).with_title(title.c_str()).show();
}

TEMPLATE_TEST_CASE("a 'MsgBoxExceptionless' should have its text set to the specified value when 'with_text' is called",
                   "[message_box]",
                   char,
                   wchar_t)
{
    auto text = geecore::tests::generate_text<TestType>();

    geecore::tests::MockMsgBoxDriver<TestType> driver;

    ALLOW_CALL(driver, show(trompeloeil::_, trompeloeil::_, trompeloeil::_, trompeloeil::_))
        .RETURN(geecore::MsgBoxSelection::Unknown);

    REQUIRE_CALL(driver, show(trompeloeil::_, trompeloeil::_, text.c_str(), trompeloeil::_))
        .RETURN(geecore::MsgBoxSelection::Ok);

    geecore::detail::BasicMsgBoxExceptionless<TestType>(driver).with_text(text.c_str()).show();
}

TEMPLATE_TEST_CASE("a 'MsgBoxExceptionless' should have its title and text set to the specified values when "
                   "'with_title' and 'with_text' are called",
                   "[message_box]",
                   char,
                   wchar_t)
{
    auto title = geecore::tests::generate_title<TestType>();
    auto text = geecore::tests::generate_text<TestType>();

    geecore::tests::MockMsgBoxDriver<TestType> driver;

    ALLOW_CALL(driver, show(trompeloeil::_, trompeloeil::_, trompeloeil::_, trompeloeil::_))
        .RETURN(geecore::MsgBoxSelection::Unknown);

    REQUIRE_CALL(driver, show(trompeloeil::_, title.c_str(), text.c_str(), trompeloeil::_))
        .RETURN(geecore::MsgBoxSelection::Ok);

    geecore::detail::BasicMsgBoxExceptionless<TestType>(driver)
        .with_title(title.c_str())
        .with_text(text.c_str())
        .show();
}
