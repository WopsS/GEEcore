# Testing Guidelines

This document outlines the essential guidelines for testing within this library.
All contributors are **required** to adhere to these practices.

## Foreword

For unit testing, we utilize [Catch2](https://github.com/catchorg/Catch2),
leveraging its powerful features, including:

- `TEST_CASE` and `SECTION` macros for test organization
- [Matchers](https://github.com/catchorg/Catch2/blob/v3.1.1/docs/matchers.md)
  for enhanced assertions
- [Data generators](https://github.com/catchorg/Catch2/blob/v3.1.1/docs/generators.md)
  for generating test data

However, it's important to note the following:

- Avoid creating unnecessary `TEST_CASE`s when a `SECTION` suffices.
- Refrain from using
  [BDD-style test cases](https://github.com/catchorg/Catch2/blob/v3.1.1/docs/test-cases-and-sections.md#bdd-style-test-cases).

## General

- Tests should have a clear and specific purpose, focusing on verifying a single
  behavior or aspect of the code.
- Tests should be concise and to the point.
- Tests should be independent, capable of running alone or in any order.
- Avoid testing private or protected methods directly.
- Minimize the usage of control structures (`if`, `switch`, `for`, `while`,
  etc.) unless necessary.

## Test and Section Naming

Tests should follow a structured naming convention:

```txt
<unit under test> should <expected result> when <condition>
```

A section's name should adhere to one of the following structures:

- `and <parameter(s)>` **_OR_**
- `using <parameter(s)>` **_OR_**
- `with <parameter(s)>`

::: tip :thought_balloon: Rationale

Clear and descriptive names for tests and sections within tests serve as
documentation, aiding both new and existing developers in understanding the
purpose and context of each test case. When tests adhere to a structured naming
convention, we achieve the following benefits:

- **Clarity**: Test names that describe the expected behavior help in quickly
  understanding what aspect of the code is being verified.
- **Readability**: Consistent naming conventions make the test suite easier to
  comprehend, maintain, and navigate.
- **Documentation**: Well-named tests act as living documentation, providing
  insights into the intended functionality and behavior of the codebase.

:::

::: code-group

```cpp [✔ Correct]
TEST_CASE("an object should be nothrow moveable when using 'GEECORE_NOEXCEPT_MOVEABLE' macro", ...)
{
    SECTION("and the move constructor is used")
    {
        // ...
    }
    SECTION("and the move assignment operator is used")
    {
        // ...
    }
}
```

```cpp [❌ Wrong]
TEST_CASE("GEECORE_NOEXCEPT_MOVEABLE", ...)
{
    SECTION("move constructor")
    {
        // ...
    }
    SECTION("assignment operator")
    {
        // ...
    }
}
```

:::

## Tagging

[Catch2](https://github.com/catchorg/Catch2) facilitates the categorization and
filtering of test cases through
[tagging](https://github.com/catchorg/Catch2/blob/v3.4.0/docs/test-cases-and-sections.md#tags).
When creating a test case, it must contain:

- A tag associated with the unit of work being tested. For instance, a test case
  for a class named `my_cool_class` should be defined as
  `TEST_CASE("<NAME>", "[my_cool_class]<OTHER_TAGS>")`.

::: tip :thought_balloon: Rationale

Tagging test cases using tools like [Catch2](https://github.com/catchorg/Catch2)
enables better organization, categorization, and filtering of test suites.

:::
