#pragma once

#include <filesystem>

#include <kangaru/service.hpp>

#include <geecore/IAppMetadata.hpp>
#include <geecore/SpecialMemberFunctions.hpp>

namespace geecore
{
/**
 * @brief Represents the metadata of a loader application.
 */
class ILoaderAppMetadata : public IAppMetadata
{
public:
    ILoaderAppMetadata() noexcept = default;
    virtual ~ILoaderAppMetadata() noexcept override = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(ILoaderAppMetadata);

    /**
     * @brief Returns the path of the module that will be loaded.
     * @return The path of the module.
     */
    virtual std::filesystem::path module_path() const = 0;
};

struct LoaderAppMetadataService : kgr::abstract_service<ILoaderAppMetadata>
{
};
} // namespace geecore
