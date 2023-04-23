#include <cstdint>
#include <type_traits>

#include <catch2/catch_test_macros.hpp>

#include <geecore/special_member_functions.hpp>

TEST_CASE("an object should be copyable when using 'GEECORE_COPYABLE' macro", "[special_member_functions]")
{
    struct test_struct
    {
        test_struct() noexcept
            : m_some_member(1)
        {
        }

        test_struct(test_struct&& rhs) noexcept
            : m_some_member(rhs.m_some_member)
        {
        }

        test_struct& operator=(test_struct&& rhs) noexcept
        {
            m_some_member = std::move(rhs.m_some_member);
        }

        ~test_struct() noexcept = default;

        GEECORE_COPYABLE(test_struct);

    private:
        std::int32_t m_some_member;
    };

    SECTION("and the copy constructor is called")
    {
        REQUIRE(std::is_copy_constructible_v<test_struct>);
    }
    SECTION("and the copy assignment operator is called")
    {
        REQUIRE(std::is_copy_assignable_v<test_struct>);
    }
}
TEST_CASE("an object should be nothrow copyable when using 'GEECORE_NOEXCEPT_COPYABLE' macro",
          "[special_member_functions]")
{
    struct test_struct
    {
        test_struct() noexcept
            : m_some_member(1)
        {
        }

        test_struct(test_struct&& rhs) noexcept
            : m_some_member(rhs.m_some_member)
        {
        }

        test_struct& operator=(test_struct&& rhs) noexcept
        {
            m_some_member = std::move(rhs.m_some_member);
        }

        ~test_struct() noexcept = default;

        GEECORE_NOEXCEPT_COPYABLE(test_struct);

    private:
        std::int32_t m_some_member;
    };

    SECTION("and the copy constructor is called")
    {
        REQUIRE(std::is_nothrow_copy_constructible_v<test_struct>);
    }
    SECTION("and the copy assignment operator is called")
    {
        REQUIRE(std::is_nothrow_copy_assignable_v<test_struct>);
    }
}

TEST_CASE("an object should be nothrow moveable when using 'GEECORE_NOEXCEPT_MOVEABLE' macro",
          "[special_member_functions]")
{
    struct test_struct
    {
        test_struct()
            : m_some_member(new int(1))
        {
        }

        test_struct(const test_struct& rhs)
            : m_some_member(new int(2))
        {
            if (rhs.m_some_member)
            {
                *m_some_member = *rhs.m_some_member;
            }
        }

        test_struct& operator=(const test_struct& rhs)
        {
            if (this != &rhs)
            {
                return *this;
            }

            if (rhs.m_some_member)
            {
                if (!m_some_member)
                {
                    m_some_member = new int(3);
                }

                *m_some_member = *rhs.m_some_member;
            }
        }

        ~test_struct() noexcept
        {
            delete m_some_member;
        }

        GEECORE_NOEXCEPT_MOVEABLE(test_struct);

    private:
        std::int32_t* m_some_member;
    };

    SECTION("and the move constructor is called")
    {
        REQUIRE(std::is_nothrow_move_constructible_v<test_struct>);
    }
    SECTION("and the move assignment operator is called")
    {
        REQUIRE(std::is_nothrow_move_assignable_v<test_struct>);
    }
}

TEST_CASE("an object should be non-copyable when using 'GEECORE_NON_COPYABLE' macro", "[special_member_functions]")
{
    struct test_struct
    {
        GEECORE_NON_COPYABLE(test_struct);
    };

    SECTION("and the copy constructor is called")
    {
        REQUIRE(!std::is_nothrow_copy_constructible_v<test_struct>);
    }
    SECTION("and the copy assignment operator is called")
    {
        REQUIRE(!std::is_nothrow_copy_assignable_v<test_struct>);
    }
}

TEST_CASE("an object should be non-movable when using 'GEECORE_NON_MOVEABLE' macro", "[special_member_functions]")
{
    struct test_struct
    {
        GEECORE_NON_MOVEABLE(test_struct);
    };

    SECTION("and the move constructor is called")
    {
        REQUIRE(!std::is_nothrow_move_constructible_v<test_struct>);
    }
    SECTION("and the move assignment operator is called")
    {
        REQUIRE(!std::is_nothrow_move_assignable_v<test_struct>);
    }
}
