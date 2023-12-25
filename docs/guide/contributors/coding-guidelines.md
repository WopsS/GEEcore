# Coding Guidelines

This page outlines the coding guidelines for this library. All contributors are
**required** to adhere to these guidelines.

## C++ version

The primary focus of this library is on C++23; however, the use of newer C++
standards is acceptable. To ensure compatibility, macros are utilized to provide
a fallback mechanism to the targeted version.

::: code-group

```cpp [✔ Correct]
#if GEECORE_HAS_CPP17_ATTRIBUTE(nodiscard)
#define GEECORE_NODISCARD [[nodiscard]]
#else
#define GEECORE_NODISCARD
#endif
```

```cpp [❌ Wrong]
#if GEECORE_HAS_CPP17_ATTRIBUTE(nodiscard)
#define GEECORE_NODISCARD [[nodiscard]]
#endif
```

:::

## General

- Use [EditorConfig](https://editorconfig.org/) and
  [clang-format](https://clang.llvm.org/docs/ClangFormat.html) for consistent
  styling.
- Indent with **4 spaces**.
- Choose descriptive names; minimize obscure abbreviations.
- Use `auto` for type deduction where appropriate.

## Header Files

- Use `#pragma once` for header guards.
- Organize includes and forward declarations neatly.
  - Order of includes:
    1. Corresponding header for a source file (e.g. `MyClass.cpp` should first
       include `MyClass.hpp`)
    2. Standard libraries (e.g. `<stdexcept>`, `<string>`).
    3. Third-party libraries (e.g. `<fmt/format.h>`).
    4. GEEcore library files (e.g. `<geecore/SpecialMemberFunctions.hpp>`).

## Classes and Structs

- Clearly separate public, protected, and private sections.
- Use `= default` for default constructors and destructors.
- Employ `[[nodiscard]]` where return values should not be ignored.
- All classes should be marked as `final` by default, remove if necessary.
- Prefer `noexcept` specifier for constructors and destructors when exceptions
  are not expected.
- Manage copy and move semantics explicitly.

## Functions

- Use `[[nodiscard]]` for functions where the return value should not be
  ignored.
- Mark functions as `noexcept` where exceptions are not expected.

## Naming Conventions

- **Classes/Structs**: Use `PascalCase`.
- **Enumerations**:
  - Enum Types: `PascalCase`.
  - Enum Values: `PascalCase`.
- **Constants/Macros**: Use `ALL_CAPS`.
- **Private Member Variables**: Prefix with `m_` and use `snake_case`.
- **Function Names**: Use `snake_case`.
- **Variables**: Use `snake_case`.

## Comments

- Use inline comments for complex logic.
- Use Doxygen-style comments for documentation.
- Briefly describe the purpose of classes and functions.

## Other

- Utilize smart pointers for dynamic memory.
- Avoid raw pointer usage unless necessary.
- Always use `enum class` over `enum`.
