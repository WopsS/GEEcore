#include <geecore/detail/proxies/VersionProxy.functions.hpp>

geecore::detail::proxies::GetFileVersionInfoAType geecore::detail::proxies::GetFileVersionInfoA;
geecore::detail::proxies::GetFileVersionInfoByHandleType geecore::detail::proxies::GetFileVersionInfoByHandle;
geecore::detail::proxies::GetFileVersionInfoExAType geecore::detail::proxies::GetFileVersionInfoExA;
geecore::detail::proxies::GetFileVersionInfoExWType geecore::detail::proxies::GetFileVersionInfoExW;
geecore::detail::proxies::GetFileVersionInfoSizeAType geecore::detail::proxies::GetFileVersionInfoSizeA;
geecore::detail::proxies::GetFileVersionInfoSizeExAType geecore::detail::proxies::GetFileVersionInfoSizeExA;
geecore::detail::proxies::GetFileVersionInfoSizeExWType geecore::detail::proxies::GetFileVersionInfoSizeExW;
geecore::detail::proxies::GetFileVersionInfoSizeWType geecore::detail::proxies::GetFileVersionInfoSizeW;
geecore::detail::proxies::GetFileVersionInfoWType geecore::detail::proxies::GetFileVersionInfoW;
geecore::detail::proxies::VerFindFileAType geecore::detail::proxies::VerFindFileA;
geecore::detail::proxies::VerFindFileWType geecore::detail::proxies::VerFindFileW;
geecore::detail::proxies::VerInstallFileAType geecore::detail::proxies::VerInstallFileA;
geecore::detail::proxies::VerInstallFileWType geecore::detail::proxies::VerInstallFileW;
geecore::detail::proxies::VerLanguageNameAType geecore::detail::proxies::VerLanguageNameA;
geecore::detail::proxies::VerLanguageNameWType geecore::detail::proxies::VerLanguageNameW;
geecore::detail::proxies::VerQueryValueAType geecore::detail::proxies::VerQueryValueA;
geecore::detail::proxies::VerQueryValueWType geecore::detail::proxies::VerQueryValueW;

BOOL APIENTRY geecore_GetFileVersionInfoA(LPCSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
    return geecore::detail::proxies::GetFileVersionInfoA(lptstrFilename, dwHandle, dwLen, lpData);
}

void geecore_GetFileVersionInfoByHandle()
{
    geecore::detail::proxies::GetFileVersionInfoByHandle();
}

BOOL APIENTRY
geecore_GetFileVersionInfoExA(DWORD dwFlags, LPCSTR lpwstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
    return geecore::detail::proxies::GetFileVersionInfoExA(dwFlags, lpwstrFilename, dwHandle, dwLen, lpData);
}

BOOL APIENTRY
geecore_GetFileVersionInfoExW(DWORD dwFlags, LPCWSTR lpwstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
    return geecore::detail::proxies::GetFileVersionInfoExW(dwFlags, lpwstrFilename, dwHandle, dwLen, lpData);
}

DWORD APIENTRY geecore_GetFileVersionInfoSizeA(LPCSTR lptstrFilename, LPDWORD lpdwHandle)
{
    return geecore::detail::proxies::GetFileVersionInfoSizeA(lptstrFilename, lpdwHandle);
}

DWORD APIENTRY geecore_GetFileVersionInfoSizeExA(DWORD dwFlags, LPCSTR lpwstrFilename, LPDWORD lpdwHandle)
{
    return geecore::detail::proxies::GetFileVersionInfoSizeExA(dwFlags, lpwstrFilename, lpdwHandle);
}

DWORD APIENTRY geecore_GetFileVersionInfoSizeExW(DWORD dwFlags, LPCWSTR lpwstrFilename, LPDWORD lpdwHandle)
{
    return geecore::detail::proxies::GetFileVersionInfoSizeExW(dwFlags, lpwstrFilename, lpdwHandle);
}

DWORD APIENTRY geecore_GetFileVersionInfoSizeW(LPCWSTR lptstrFilename, LPDWORD lpdwHandle)
{
    return geecore::detail::proxies::GetFileVersionInfoSizeW(lptstrFilename, lpdwHandle);
}

BOOL APIENTRY geecore_GetFileVersionInfoW(LPCWSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
    return geecore::detail::proxies::GetFileVersionInfoW(lptstrFilename, dwHandle, dwLen, lpData);
}

DWORD APIENTRY geecore_VerFindFileA(DWORD uFlags,
                                    LPCSTR szFilename,
                                    LPCSTR szWinDir,
                                    LPCSTR szAppDir,
                                    LPSTR szCurDir,
                                    PUINT puCurDirLen,
                                    LPSTR szDestDir,
                                    PUINT puDestDirLen)
{
    return geecore::detail::proxies::VerFindFileA(uFlags,
                                                  szFilename,
                                                  szWinDir,
                                                  szAppDir,
                                                  szCurDir,
                                                  puCurDirLen,
                                                  szDestDir,
                                                  puDestDirLen);
}

DWORD APIENTRY geecore_VerFindFileW(DWORD uFlags,
                                    LPCWSTR szFileName,
                                    LPCWSTR szWinDir,
                                    LPCWSTR szAppDir,
                                    LPWSTR szCurDir,
                                    PUINT puCurDirLen,
                                    LPWSTR szDestDir,
                                    PUINT puDestDirLen)
{
    return geecore::detail::proxies::VerFindFileW(uFlags,
                                                  szFileName,
                                                  szWinDir,
                                                  szAppDir,
                                                  szCurDir,
                                                  puCurDirLen,
                                                  szDestDir,
                                                  puDestDirLen);
}

DWORD APIENTRY geecore_VerInstallFileA(DWORD uFlags,
                                       LPCSTR szSrcFileName,
                                       LPCSTR szDestFileName,
                                       LPCSTR szSrcDir,
                                       LPCSTR szDestDir,
                                       LPCSTR szCurDir,
                                       LPSTR szTmpFile,
                                       PUINT puTmpFileLen)
{
    return geecore::detail::proxies::VerInstallFileA(uFlags,
                                                     szSrcFileName,
                                                     szDestFileName,
                                                     szSrcDir,
                                                     szDestDir,
                                                     szCurDir,
                                                     szTmpFile,
                                                     puTmpFileLen);
}

DWORD APIENTRY geecore_VerInstallFileW(DWORD uFlags,
                                       LPCWSTR szSrcFileName,
                                       LPCWSTR szDestFileName,
                                       LPCWSTR szSrcDir,
                                       LPCWSTR szDestDir,
                                       LPCWSTR szCurDir,
                                       LPWSTR szTmpFile,
                                       PUINT puTmpFileLen)
{
    return geecore::detail::proxies::VerInstallFileW(uFlags,
                                                     szSrcFileName,
                                                     szDestFileName,
                                                     szSrcDir,
                                                     szDestDir,
                                                     szCurDir,
                                                     szTmpFile,
                                                     puTmpFileLen);
}

DWORD APIENTRY geecore_VerLanguageNameA(DWORD wLang, LPSTR szLang, DWORD cchLang)
{
    return geecore::detail::proxies::VerLanguageNameA(wLang, szLang, cchLang);
}

DWORD APIENTRY geecore_VerLanguageNameW(DWORD wLang, LPWSTR szLang, DWORD cchLang)
{
    return geecore::detail::proxies::VerLanguageNameW(wLang, szLang, cchLang);
}

BOOL APIENTRY geecore_VerQueryValueA(LPCVOID pBlock, LPCSTR lpSubBlock, LPVOID* lplpBuffer, PUINT puLen)
{
    return geecore::detail::proxies::VerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen);
}

BOOL APIENTRY geecore_VerQueryValueW(LPCVOID pBlock, LPCWSTR lpSubBlock, LPVOID* lplpBuffer, PUINT puLen)
{
    return geecore::detail::proxies::VerQueryValueW(pBlock, lpSubBlock, lplpBuffer, puLen);
}
