# Host

The `Host` class is the entry point for a GEEcore application. It is responsible
for setting up the application's services and managing the application's
lifetime. The `Host` class can manage two types of applications:

- **Generic Application**: A standard application with its own lifecycle.
- **Loader Application**: This type of application acts as an injector, using
  proxy DLLs to trick the target process into loading your custom DLL.

## Creating a Host

In general a host is created using the `HostBuilder` class. The `HostBuilder`
class provides a fluent API for configuring the `Host` and its services.

The `HostBuilder` class provides the following methods:

- `add_service<T, Args...>(Args&&... args)`: Adds a service of type `T` to the
  host.
- `add_mapped_service<T, Args...>(Args&&... args)`: Adds a mapped service of
  type `T` to the host.
- `add_loader_lifetime()`: Adds the loader lifetime service to the host. That
  means that the host will be acting as a loader for your custom DLL.
- `set_as_default()`: Sets the host built by this class as the default instance.
- `build()`: Constructs and returns a shared pointer to the constructed `Host`
  object.

:::info

These functions are a subset of `HostBuilder`'s methods. For a complete list of
methods, refer to the `HostBuilder` class in the GEEcore library.

:::

```cpp
#include <geecore/HostBuilder.hpp>

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
    {
        auto host = geecore::HostBuilder()  // Create the host builder.
            .add_service<CustomService>()   // Adding a custom service.
            .set_as_default()               // Set the host as the default instance.
            .build();                       // Build the host.
    }
    }
}
```

## Starting and stopping the host

Once you have created a host, it needs to be started and stopped. The `Host`
class provides the following methods for starting and stopping the host:

- `start()`: Starts the host.
- `stop()`: Stops the host.

```cpp
#include <geecore/HostBuilder.hpp>

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    GEECORE_UNUSED(reserved);

    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
    {
        auto host = geecore::HostBuilder()
                        // ...
                        .set_as_default()
                        .build();

        host->start();

        break;
    }
    case DLL_PROCESS_DETACH:
    {
        auto host = geecore::Host::instance();
        if (host)
        {
            host->stop();
        }

        break;
    }
    }

    return TRUE;
}
```

## Setting the host as a loader

If you want to use the `Host` as a loader for your custom DLL, you need to:

1. Add a `ILoaderAppMetadata` service to the host. This service provides the
   metadata of the loader app.
2. Call `add_module_image`, which adds the `IModuleImage` service to the host.
   This service provides information about the loader's DLL, such as its name,
   which is important for proxying.
3. Call `add_loader_lifetime()` on the `HostBuilder` instance. This method adds
   the loader lifetime service to the host.
4. In your `CMakeLists.txt`, call `geecore_set_target_as_loader` to set the
   target as a loader. This function adds a `def` file to your project, which
   exports the proxied functions.

:::tip IMPORTANT

Due to how [kangaru](https://gracicot.github.io/kangaru/) works, you have to add
the services in the order specified above.

:::

::: code-group

```cpp [Main.cpp]
#include <geecore/HostBuilder.hpp>

#include "AppMetadata.hpp"

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    GEECORE_UNUSED(reserved);

    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
    {
        auto host = geecore::HostBuilder()
                        .add_service<AppMetadataService>()
                        .add_module_image(module)
                        .add_loader_lifetime()
                        .set_as_default()
                        .build();

        host->start();

        break;
    }
    case DLL_PROCESS_DETACH:
    {
        auto host = geecore::Host::instance();
        if (host)
        {
            host->stop();
        }

        break;
    }
    }

    return TRUE;
}
```

```cpp [AppMetadata.hpp]
#pragma once

#include <filesystem>
#include <string_view>

#include <kangaru/kangaru.hpp>

#include <geecore/ILoaderAppMetadata.hpp>

class AppMetadata : public geecore::ILoaderAppMetadata
{
public:
    AppMetadata() = default;
    ~AppMetadata() final = default;

    const std::wstring_view name() const final;
    const std::filesystem::path& root_directory() const noexcept final;

    std::filesystem::path module_path() const final;
};

struct AppMetadataService
    : kgr::single_service<AppMetadata>
    , kgr::overrides<geecore::LoaderAppMetadataService>
{
};
```

```cpp [AppMetadata.cpp]
#include "AppMetadata.hpp"

const std::wstring_view red3ext::AppMetadata::name() const
{
    return L"Your App Name";
}

const std::filesystem::path& red3ext::AppMetadata::root_directory() const noexcept
{
    // Your own implementation.
}

std::filesystem::path red3ext::AppMetadata::module_path() const
{
    return root_directory() / L"YourMainDllName.dll";
}
```

```cmake [CMakeLists.txt]
# ...

geecore_set_target_as_loader(YourLoader)

#...
```

:::

## Setting the host as the default instance

If you have code that needs to access the `Host` instance (for example, to
handle events from a hook), you can set the `Host` as the default instance using
the `set_as_default()` method. Once the `Host` is set as the default instance,
you can access it using the `instance()` method.
