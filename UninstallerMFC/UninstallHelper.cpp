#include "pch.h"
#include "UninstallHelper.h"

void UninstallHelper::Applist_X32() {
    HKEY startHKey = HKEY_LOCAL_MACHINE;
    HKEY hUninstKey = NULL;
    HKEY hAppKey = NULL;
    WCHAR sAppKeyName[1024];
    WCHAR sUninstallPath[1024];
    WCHAR sDisplayName[1024];
    WCHAR sDisplayIcon[1024];
    WCHAR sSubKey[1024];

    WCHAR sRoot[] = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall";
    long lResult = ERROR_SUCCESS;
    DWORD dwType = KEY_READ;
    DWORD dwByte = KEY_ALL_ACCESS | KEY_WOW64_32KEY;
    DWORD dwBufferSize = 0;


    if (RegOpenKeyEx(startHKey, sRoot, 0, KEY_READ | KEY_WOW64_32KEY, &hUninstKey) == ERROR_SUCCESS)
    {
        for (DWORD dwIndex = 0; lResult == ERROR_SUCCESS; dwIndex++)
        {
            dwBufferSize = sizeof(sAppKeyName);
            if ((lResult = RegEnumKeyEx(hUninstKey, dwIndex, (LPWSTR)sAppKeyName,
                &dwBufferSize, NULL, NULL, NULL, NULL)) == ERROR_SUCCESS)
            {
                wsprintf(sSubKey, L"%s\\%s", sRoot, sAppKeyName);

                if (RegOpenKeyEx(startHKey, sSubKey, 0, KEY_READ | KEY_WOW64_32KEY, &hAppKey) != ERROR_SUCCESS)
                {
                    RegCloseKey(hAppKey);
                    RegCloseKey(hUninstKey);
                }

                dwBufferSize = sizeof(sDisplayName);
                if (RegQueryValueEx(hAppKey, L"DisplayName", NULL,
                    &dwType, (unsigned char*)sDisplayName, &dwBufferSize) == ERROR_SUCCESS)
                {
                    dwBufferSize = sizeof(sUninstallPath);
                    if (RegQueryValueEx(hAppKey, L"UninstallString", NULL,
                        &dwType, (unsigned char*)sUninstallPath, &dwBufferSize) == ERROR_SUCCESS)
                    {
                        dwBufferSize = sizeof(sDisplayIcon);
                        if (RegQueryValueEx(hAppKey, L"DisplayIcon", NULL,
                            &dwType, (unsigned char*)sDisplayIcon, &dwBufferSize) == ERROR_SUCCESS)
                        {
                            uninstallInfoVector.push_back(UninstallInfo(sUninstallPath, sDisplayName, sDisplayIcon, sAppKeyName, startHKey, dwByte));
                        }
                    }
                }
                RegCloseKey(hAppKey);
            }
        }
    }
    RegCloseKey(hUninstKey);
}

void UninstallHelper:: Applist_X64() {
    HKEY startHKey = HKEY_LOCAL_MACHINE;
    HKEY hUninstKey = NULL;
    HKEY hAppKey = NULL;
    WCHAR sAppKeyName[1024];
    WCHAR sUninstallPath[1024];
    WCHAR sDisplayName[1024];
    WCHAR sDisplayIcon[1024];
    WCHAR sSubKey[1024];

    WCHAR sRoot[] = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall";
    long lResult = ERROR_SUCCESS;
    DWORD dwType = KEY_READ;
    DWORD dwByte = KEY_ALL_ACCESS | KEY_WOW64_64KEY;
    DWORD dwBufferSize = 0;


    if (RegOpenKeyEx(startHKey, sRoot, 0, KEY_READ | KEY_WOW64_64KEY, &hUninstKey) == ERROR_SUCCESS)
    {
        for (DWORD dwIndex = 0; lResult == ERROR_SUCCESS; dwIndex++)
        {
            dwBufferSize = sizeof(sAppKeyName);
            if ((lResult = RegEnumKeyEx(hUninstKey, dwIndex, (LPWSTR)sAppKeyName,
                &dwBufferSize, NULL, NULL, NULL, NULL)) == ERROR_SUCCESS)
            {
                wsprintf(sSubKey, L"%s\\%s", sRoot, sAppKeyName);

                if (RegOpenKeyEx(startHKey, sSubKey, 0, KEY_READ | KEY_WOW64_64KEY, &hAppKey) != ERROR_SUCCESS)
                {
                    RegCloseKey(hAppKey);
                    RegCloseKey(hUninstKey);
                }

                dwBufferSize = sizeof(sDisplayName);
                if (RegQueryValueEx(hAppKey, L"DisplayName", NULL,
                    &dwType, (unsigned char*)sDisplayName, &dwBufferSize) == ERROR_SUCCESS)
                {
                    dwBufferSize = sizeof(sUninstallPath);
                    if (RegQueryValueEx(hAppKey, L"UninstallString", NULL,
                        &dwType, (unsigned char*)sUninstallPath, &dwBufferSize) == ERROR_SUCCESS)
                    {
                        dwBufferSize = sizeof(sDisplayIcon);
                        if (RegQueryValueEx(hAppKey, L"DisplayIcon", NULL,
                            &dwType, (unsigned char*)sDisplayIcon, &dwBufferSize) == ERROR_SUCCESS)
                        {
                            uninstallInfoVector.push_back(UninstallInfo(sUninstallPath, sDisplayName, sDisplayIcon, sAppKeyName, startHKey, dwByte));
                        }
                    }
                }
                RegCloseKey(hAppKey);
            }
        }
    }
    RegCloseKey(hUninstKey);
}

void UninstallHelper::App_user() {
    HKEY startHKey = HKEY_CURRENT_USER;
    HKEY hUninstKey = NULL;
    HKEY hAppKey = NULL;
    WCHAR sAppKeyName[1024];
    WCHAR sUninstallPath[1024];
    WCHAR sDisplayName[1024];
    WCHAR sDisplayIcon[1024];
    WCHAR sSubKey[1024];

    WCHAR sRoot[] = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall";
    long lResult = ERROR_SUCCESS;
    DWORD dwType = KEY_READ;
    DWORD dwByte = KEY_ALL_ACCESS;
    DWORD dwBufferSize = 0;


    if (RegOpenKeyEx(startHKey, sRoot, 0, KEY_ALL_ACCESS, &hUninstKey) == ERROR_SUCCESS)
    {
        for (DWORD dwIndex = 0; lResult == ERROR_SUCCESS; dwIndex++)
        {
            dwBufferSize = sizeof(sAppKeyName);
            if ((lResult = RegEnumKeyEx(hUninstKey, dwIndex, (LPWSTR)sAppKeyName,
                &dwBufferSize, NULL, NULL, NULL, NULL)) == ERROR_SUCCESS)
            {
                wsprintf(sSubKey, L"%s\\%s", sRoot, sAppKeyName);

                if (RegOpenKeyEx(startHKey, sSubKey, 0, KEY_ALL_ACCESS, &hAppKey) != ERROR_SUCCESS)
                {
                    RegCloseKey(hAppKey);
                    RegCloseKey(hUninstKey);
                }

                dwBufferSize = sizeof(sDisplayName);
                if (RegQueryValueEx(hAppKey, L"DisplayName", NULL,
                    &dwType, (unsigned char*)sDisplayName, &dwBufferSize) == ERROR_SUCCESS)
                {
                    dwBufferSize = sizeof(sUninstallPath);
                    if (RegQueryValueEx(hAppKey, L"UninstallString", NULL,
                        &dwType, (unsigned char*)sUninstallPath, &dwBufferSize) == ERROR_SUCCESS)
                    {
                        dwBufferSize = sizeof(sDisplayIcon);
                        if (RegQueryValueEx(hAppKey, L"DisplayIcon", NULL,
                            &dwType, (unsigned char*)sDisplayIcon, &dwBufferSize) == ERROR_SUCCESS)
                        {
                            uninstallInfoVector.push_back(UninstallInfo(sUninstallPath, sDisplayName, sDisplayIcon, sAppKeyName, startHKey, dwByte));
                        }
                    }
                }
                RegCloseKey(hAppKey);
            }
        }
    }
    RegCloseKey(hUninstKey);
}

bool CheckRegExist(HKEY RootKey, LPCTSTR _SubKey)
{
    HKEY hKey;
    bool ret = false;

    if (RegOpenKeyEx(RootKey, _SubKey, NULL, KEY_READ, &hKey) == ERROR_SUCCESS)
    {
        RegCloseKey(hKey);
        ret = true;
    }

    return ret;
}

bool UninstallHelper::GetUninstallVector(std::vector<UninstallInfo> *uninstallVector)
{

    Applist_X32();
    Applist_X64();
    App_user();
    *uninstallVector = uninstallInfoVector;
    return false;
}
