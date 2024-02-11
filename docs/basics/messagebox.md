# MessageBox

The `MsgBox` and `MsgBoxExceptionless` classes offer a Fluent-API for creating
modal dialog boxes in both `char` and `wchar_t` versions. They are designed for
efficient and flexible message display in applications.

To display a message box, a driver is required. This design allows for easy
mocking of message boxes in unit tests. The library includes two default
drivers:

- `Win32MsgBoxDriver` for wide string messages.
- `Win32MsgBoxDriverAnsi` for ANSI string messages.

:::tip

The `MsgBoxExceptionless` class is specifically designed for use in exception
handling contexts. It avoids throwing exceptions and instead uses
[std::expected](https://en.cppreference.com/w/cpp/utility/expected) for error
handling. This class is useful in scenarios where exception handling is not
desirable or possible.

:::

## Example

::: code-group

```cpp [Wide]
geecore::Win32MsgBoxDriver driver;
geecore::MsgBoxExceptionless(driver)
    .with_title(L"My Application")
    .with_text(L"This is an error message.")
    .with_icon(geecore::MsgBoxIcon::Error)
    .show();
```

```cpp [ANSI]
geecore::Win32MsgBoxDriverAnsi driver;
geecore::MsgBoxExceptionlessAnsi(driver)
    .with_title("My Application")
    .with_text("This is an error message.")
    .with_icon(geecore::MsgBoxIcon::Error)
    .show();
```

:::

::: warning

It is important to instantiate instances of the `MsgBox` / `MsgBoxExceptionless`
class directly rather than as pointers due to its handling of variables passed
by pointers or references. Managing their lifetimes properly is essential for
the correct behavior of the message box.

:::
