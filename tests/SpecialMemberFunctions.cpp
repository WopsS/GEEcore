#include <cstdint>
#include <type_traits>

#include <catch2/catch_test_macros.hpp>

#include <geecore/SpecialMemberFunctions.hpp>

TEST_CASE("an object should be copyable when using 'GEECORE_COPYABLE' macro", "[special_member_functions]")
{
    struct TestStruct
    {
        TestStruct() noexcept
            : m_some_member(1)
        {
        }

        TestStruct(TestStruct&& rhs) noexcept
            : m_some_member(rhs.m_some_member)
        {
        }

        TestStruct& operator=(TestStruct&& rhs) noexcept
        {
            m_some_member = std::move(rhs.m_some_member);
        }

        ~TestStruct() noexcept = default;

        GEECORE_COPYABLE(TestStruct);

    private:
        std::int32_t m_some_member;
    };

    SECTION("and the copy constructor is called")
    {
        REQUIRE(std::is_copy_constructible_v<TestStruct>);
    }
    SECTION("and the copy assignment operator is called")
    {
        REQUIRE(std::is_copy_assignable_v<TestStruct>);
    }
}

TEST_CASE("an object should be nothrow copyable when using 'GEECORE_NOEXCEPT_COPYABLE' macro",
          "[special_member_functions]")
{
    struct TestStruct
    {
        TestStruct() noexcept
            : m_some_member(1)
        {
        }

        TestStruct(TestStruct&& rhs) noexcept
            : m_some_member(rhs.m_some_member)
        {
        }

        TestStruct& operator=(TestStruct&& rhs) noexcept
        {
            m_some_member = std::move(rhs.m_some_member);
        }

        ~TestStruct() noexcept = default;

        GEECORE_NOEXCEPT_COPYABLE(TestStruct);

    private:
        std::int32_t m_some_member;
    };

    SECTION("and the copy constructor is called")
    {
        REQUIRE(std::is_nothrow_copy_constructible_v<TestStruct>);
    }
    SECTION("and the copy assignment operator is called")
    {
        REQUIRE(std::is_nothrow_copy_assignable_v<TestStruct>);
    }
}

TEST_CASE("an object should be nothrow moveable when using 'GEECORE_NOEXCEPT_MOVEABLE' macro",
          "[special_member_functions]")
{
    struct TestStruct
    {
        TestStruct()
            : m_some_member(new int(1))
        {
        }

        TestStruct(const TestStruct& rhs)
            : m_some_member(new int(2))
        {
            if (rhs.m_some_member)
            {
                *m_some_member = *rhs.m_some_member;
            }
        }

        TestStruct& operator=(const TestStruct& rhs)
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

        ~TestStruct() noexcept
        {
            delete m_some_member;
        }

        GEECORE_NOEXCEPT_MOVEABLE(TestStruct);

    private:
        std::int32_t* m_some_member;
    };

    SECTION("and the move constructor is called")
    {
        REQUIRE(std::is_nothrow_move_constructible_v<TestStruct>);
    }
    SECTION("and the move assignment operator is called")
    {
        REQUIRE(std::is_nothrow_move_assignable_v<TestStruct>);
    }
}

TEST_CASE("an object should be non-copyable when using 'GEECORE_NON_COPYABLE' macro", "[special_member_functions]")
{
    struct TestStruct
    {
        GEECORE_NON_COPYABLE(TestStruct);
    };

    SECTION("and the copy constructor is called")
    {
        REQUIRE(!std::is_nothrow_copy_constructible_v<TestStruct>);
    }
    SECTION("and the copy assignment operator is called")
    {
        REQUIRE(!std::is_nothrow_copy_assignable_v<TestStruct>);
    }
}

TEST_CASE("an object should be non-movable when using 'GEECORE_NON_MOVEABLE' macro", "[special_member_functions]")
{
    struct TestStruct
    {
        GEECORE_NON_MOVEABLE(TestStruct);
    };

    SECTION("and the move constructor is called")
    {
        REQUIRE(!std::is_nothrow_move_constructible_v<TestStruct>);
    }
    SECTION("and the move assignment operator is called")
    {
        REQUIRE(!std::is_nothrow_move_assignable_v<TestStruct>);
    }
}
