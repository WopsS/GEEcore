#include <geecore/detail/proxies/VersionProxy.hpp>

#include <geecore/detail/proxies/VersionProxy.functions.hpp>

std::wstring_view geecore::detail::VersionProxy::name() const
{
    return L"version";
}

void geecore::detail::VersionProxy::resolve_exports() const
{
    proxies::GetFileVersionInfoA = get_proc_address<proxies::GetFileVersionInfoAType>("GetFileVersionInfoA");
    proxies::GetFileVersionInfoByHandle =
        get_proc_address<proxies::GetFileVersionInfoByHandleType>("GetFileVersionInfoByHandle");
    proxies::GetFileVersionInfoExA = get_proc_address<proxies::GetFileVersionInfoExAType>("GetFileVersionInfoExA");
    proxies::GetFileVersionInfoExW = get_proc_address<proxies::GetFileVersionInfoExWType>("GetFileVersionInfoExW");
    proxies::GetFileVersionInfoSizeA =
        get_proc_address<proxies::GetFileVersionInfoSizeAType>("GetFileVersionInfoSizeA");
    proxies::GetFileVersionInfoSizeExA =
        get_proc_address<proxies::GetFileVersionInfoSizeExAType>("GetFileVersionInfoSizeExA");
    proxies::GetFileVersionInfoSizeExW =
        get_proc_address<proxies::GetFileVersionInfoSizeExWType>("GetFileVersionInfoSizeExW");
    proxies::GetFileVersionInfoSizeW =
        get_proc_address<proxies::GetFileVersionInfoSizeWType>("GetFileVersionInfoSizeW");
    proxies::GetFileVersionInfoW = get_proc_address<proxies::GetFileVersionInfoWType>("GetFileVersionInfoW");
    proxies::VerFindFileA = get_proc_address<proxies::VerFindFileAType>("VerFindFileA");
    proxies::VerFindFileW = get_proc_address<proxies::VerFindFileWType>("VerFindFileW");
    proxies::VerInstallFileA = get_proc_address<proxies::VerInstallFileAType>("VerInstallFileA");
    proxies::VerInstallFileW = get_proc_address<proxies::VerInstallFileWType>("VerInstallFileW");
    proxies::VerLanguageNameA = get_proc_address<proxies::VerLanguageNameAType>("VerLanguageNameA");
    proxies::VerLanguageNameW = get_proc_address<proxies::VerLanguageNameWType>("VerLanguageNameW");
    proxies::VerQueryValueA = get_proc_address<proxies::VerQueryValueAType>("VerQueryValueA");
    proxies::VerQueryValueW = get_proc_address<proxies::VerQueryValueWType>("VerQueryValueW");
}

void geecore::detail::VersionProxy::clear_resolved_exports() const
{
    proxies::GetFileVersionInfoA = nullptr;
    proxies::GetFileVersionInfoByHandle = nullptr;
    proxies::GetFileVersionInfoExA = nullptr;
    proxies::GetFileVersionInfoExW = nullptr;
    proxies::GetFileVersionInfoSizeA = nullptr;
    proxies::GetFileVersionInfoSizeExA = nullptr;
    proxies::GetFileVersionInfoSizeExW = nullptr;
    proxies::GetFileVersionInfoSizeW = nullptr;
    proxies::GetFileVersionInfoW = nullptr;
    proxies::VerFindFileA = nullptr;
    proxies::VerFindFileW = nullptr;
    proxies::VerInstallFileA = nullptr;
    proxies::VerInstallFileW = nullptr;
    proxies::VerLanguageNameA = nullptr;
    proxies::VerLanguageNameW = nullptr;
    proxies::VerQueryValueA = nullptr;
    proxies::VerQueryValueW = nullptr;
}
