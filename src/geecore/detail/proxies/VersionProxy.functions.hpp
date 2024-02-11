#pragma once

#include <Windows.h>

namespace geecore::detail::proxies
{
using GetFileVersionInfoAType = decltype(&::GetFileVersionInfoA);
using GetFileVersionInfoByHandleType = void (*)();
using GetFileVersionInfoExAType = decltype(&::GetFileVersionInfoExA);
using GetFileVersionInfoExWType = decltype(&::GetFileVersionInfoExW);
using GetFileVersionInfoSizeAType = decltype(&::GetFileVersionInfoSizeA);
using GetFileVersionInfoSizeExAType = decltype(&::GetFileVersionInfoSizeExA);
using GetFileVersionInfoSizeExWType = decltype(&::GetFileVersionInfoSizeExW);
using GetFileVersionInfoSizeWType = decltype(&::GetFileVersionInfoSizeW);
using GetFileVersionInfoWType = decltype(&::GetFileVersionInfoW);
using VerFindFileAType = decltype(&::VerFindFileA);
using VerFindFileWType = decltype(&::VerFindFileW);
using VerInstallFileAType = decltype(&::VerInstallFileA);
using VerInstallFileWType = decltype(&::VerInstallFileW);
using VerLanguageNameAType = decltype(&::VerLanguageNameA);
using VerLanguageNameWType = decltype(&::VerLanguageNameW);
using VerQueryValueAType = decltype(&::VerQueryValueA);
using VerQueryValueWType = decltype(&::VerQueryValueW);

extern GetFileVersionInfoAType GetFileVersionInfoA;
extern GetFileVersionInfoByHandleType GetFileVersionInfoByHandle;
extern GetFileVersionInfoExAType GetFileVersionInfoExA;
extern GetFileVersionInfoExWType GetFileVersionInfoExW;
extern GetFileVersionInfoSizeAType GetFileVersionInfoSizeA;
extern GetFileVersionInfoSizeExAType GetFileVersionInfoSizeExA;
extern GetFileVersionInfoSizeExWType GetFileVersionInfoSizeExW;
extern GetFileVersionInfoSizeWType GetFileVersionInfoSizeW;
extern GetFileVersionInfoWType GetFileVersionInfoW;
extern VerFindFileAType VerFindFileA;
extern VerFindFileWType VerFindFileW;
extern VerInstallFileAType VerInstallFileA;
extern VerInstallFileWType VerInstallFileW;
extern VerLanguageNameAType VerLanguageNameA;
extern VerLanguageNameWType VerLanguageNameW;
extern VerQueryValueAType VerQueryValueA;
extern VerQueryValueWType VerQueryValueW;
} // namespace geecore::detail::proxies
