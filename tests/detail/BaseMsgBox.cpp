#include <geecore/detail/BaseMsgBox.hpp>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_tostring.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <geecore/MsgBoxPrimitives.hpp>

namespace geecore::tests
{
namespace
{
class FakeMsgBox : public geecore::detail::BaseMsgBox<FakeMsgBox>
{
public:
    using BaseMsgBox::buttons;
    using BaseMsgBox::icon;
};

auto generate_icon()
{
    return GENERATE(geecore::MsgBoxIcon::None,
                    geecore::MsgBoxIcon::Information,
                    geecore::MsgBoxIcon::Warning,
                    geecore::MsgBoxIcon::Error);
}

auto generate_buttons()
{
    return GENERATE(geecore::MsgBoxButtons::Ok,
                    geecore::MsgBoxButtons::OkCancel,
                    geecore::MsgBoxButtons::YesNo,
                    geecore::MsgBoxButtons::YesNoCancel);
}
} // namespace
} // namespace geecore::tests

CATCH_REGISTER_ENUM(geecore::MsgBoxIcon,
                    geecore::MsgBoxIcon::None,
                    geecore::MsgBoxIcon::Information,
                    geecore::MsgBoxIcon::Warning,
                    geecore::MsgBoxIcon::Error);

CATCH_REGISTER_ENUM(geecore::MsgBoxButtons,
                    geecore::MsgBoxButtons::Ok,
                    geecore::MsgBoxButtons::OkCancel,
                    geecore::MsgBoxButtons::YesNo,
                    geecore::MsgBoxButtons::YesNoCancel);

TEST_CASE("a 'BaseMsgBox' should have its icon set to 'None' when it is default constructed", "[message_box]")
{
    geecore::tests::FakeMsgBox msg;
    REQUIRE(msg.icon() == geecore::MsgBoxIcon::None);
}

TEST_CASE("a 'BaseMsgBox' should have its buttons set to 'Ok' when it is default constructed", "[message_box]")
{
    geecore::tests::FakeMsgBox msg;
    REQUIRE(msg.buttons() == geecore::MsgBoxButtons::Ok);
}

TEST_CASE("a 'BaseMsgBox' should have its icon set to the specified value when 'with_icon' is called", "[message_box]")
{
    auto icon = geecore::tests::generate_icon();

    geecore::tests::FakeMsgBox msg;
    msg.with_icon(icon);

    REQUIRE(msg.icon() == icon);
}

TEST_CASE("a 'BaseMsgBox' should have its buttons set to the specified value when 'with_buttons' is called",
          "[message_box]")
{
    auto buttons = geecore::tests::generate_buttons();

    geecore::tests::FakeMsgBox msg;
    msg.with_buttons(buttons);

    REQUIRE(msg.buttons() == buttons);
}

TEST_CASE("a 'BaseMsgBox' should have its icon and buttons set to the specified values when 'with_icon' and "
          "'with_buttons' are called",
          "[message_box]")
{
    auto icon = geecore::tests::generate_icon();
    auto buttons = geecore::tests::generate_buttons();

    geecore::tests::FakeMsgBox msg;
    msg.with_icon(icon).with_buttons(buttons);

    REQUIRE(msg.icon() == icon);
    REQUIRE(msg.buttons() == buttons);
}
