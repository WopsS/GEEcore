# Service Container

The service container serves as an efficient mechanism for handling class
dependencies and executing dependency injection. In simpler terms, dependency
injection refers to the process where class dependencies are supplied directly
to the class through the constructor.

:::info

GEEcore uses the [kangaru](https://github.com/gracicot/kangaru) library for its
service container.

:::

## Creating a Service

There are two ways to create a service in
[kangaru](https://github.com/gracicot/kangaru):

1. **Manual Definition**: Define service classes using `kgr::service`,
   `kgr::single_service`, etc.
2. **Automatic Definition**: Let [kangaru](https://github.com/gracicot/kangaru)
   automagically generate the service definitions for you.

Both methods are supported in GEEcore. Here's an example of how to create a
service using both methods:

::: code-group

```cpp{10-13} [Manual Definition]
#include <kangaru/kangaru.hpp>

class ModuleImage
{
public:
    ModuleImage() = default;
    ~ModuleImage() = default;
};

struct ModuleImageService
    : kgr::single_service<ModuleImage>
{
};
```

```cpp{9} [Automatic Definition]
#include <kangaru/kangaru.hpp>

class ModuleImage
{
public:
    ModuleImage() = default;
    ~ModuleImage() = default;

    friend class service_map(ModuleImage const&) -> kgr::autowire_single;
};
```

:::

:::tip

For more information about creating and configuring services, refer to the
[kangaru](https://gracicot.github.io/kangaru/) repository.

:::

## Adding a Service to the Container

Once a service is defined, it can be added to the container. The method to add a
service depends on how the service was created.

The snippet below demonstrates how to add the service defined above to the
container:

::: code-group

```cpp{2} [Manual Definition]
auto host = geecore::HostBuilder()
    .add_service<ModuleImageService>()
    // ...
    .build();
```

```cpp{2} [Automatic Definition]
auto host = geecore::HostBuilder()
    .add_mapped_service<ModuleImage>()
    // ...
    .build();
```

:::

:::tip IMPORTANT

Services can only be added in the `HostBuilder`. Once the `Host` class is built,
the service container is locked and no further services can be added.

:::

## Using a Service

To use a service, simply request it from the container in the constructor of the
class that requires it.

:::tip IMPORTANT

The requesting class must also be registered in the container.

:::

The snipped below demonstrates the class definition that requests the service:

```cpp
class Application
{
public:
    Application(const ModuleImage& module_image);
    ~Application() = default;
};
```
