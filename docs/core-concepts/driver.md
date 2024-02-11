# Driver

A driver in GEEcore is a low-level class responsible for translating Win32 API
calls into a more abstract and easy-to-use API. This abstraction allows for more
straightforward interaction with the Win32 API and facilitates the development
of applications that interact with these APIs. Moreover, this abstraction layer
enhances the testability of your code by providing a clear separation between
your application logic and the underlying system calls.

Currently, GEEcore has one driver:

- `MsgBoxDriver` - A driver that uses the `MessageBox` Win32 API to display a
  message box.
