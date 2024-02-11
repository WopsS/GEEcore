#pragma once

#include <filesystem>
#include <string>
#include <string_view>

#include <kangaru/service.hpp>

#include <geecore/SpecialMemberFunctions.hpp>

namespace geecore
{
/**
 * @brief Represents the metadata of an application.
 */
class IAppMetadata
{
public:
    IAppMetadata() noexcept = default;
    virtual ~IAppMetadata() noexcept = default;

    GEECORE_NON_COPYABLE_AND_NON_MOVEABLE(IAppMetadata);

    // TODO: const return and const return ref?

    /**
     * @brief Returns the name of the application.
     * @return The name of the application.
     */
    virtual const std::wstring_view name() const = 0;

    /**
     * @brief Returns the root directory of the application.
     * @return The root directory of the application.
     */
    virtual const std::filesystem::path& root_directory() const noexcept = 0;
};

struct AppMetadataService : kgr::abstract_service<IAppMetadata>
{
};
} // namespace geecore
