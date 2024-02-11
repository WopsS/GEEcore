#include <geecore/detail/ModuleLifetime.hpp>

#include <geecore/exceptions/Win32Exception.hpp>

geecore::detail::ModuleLifetime::ModuleLifetime(const ILoaderAppMetadata& app_metadata)
    : m_app_metadata(app_metadata)
{
}

void geecore::detail::ModuleLifetime::start()
{
    auto path = m_app_metadata.module_path();

    auto module = LoadLibraryW(path.c_str());
    if (!module)
    {
        throw Win32Exception("The application module could not be loaded");
    }

    m_module.reset(module);
}

void geecore::detail::ModuleLifetime::stop()
{
    m_module.reset();
}
