#pragma once
#include <Windows.h>
#include <string>

class UninstallInfo
{
public:
	std::wstring UninstallPath;
	std::wstring DisplayName;
	std::wstring RegKeyName;
	std::wstring DisplayIcon;
	HKEY RegAppHKEY;
	DWORD DwType;

	UninstallInfo(WCHAR _UninstallPath[1023], WCHAR _DisplayName[1023], WCHAR _DisplayIcon[1023], WCHAR _RegKeyName[1023], HKEY _RegAppHKEY, DWORD _DwType)
	{
		UninstallPath = _UninstallPath;
		DisplayName = _DisplayName;
		DisplayIcon = _DisplayIcon;
		RegKeyName = _RegKeyName;
		RegAppHKEY = _RegAppHKEY;
		DwType = _DwType;
	};
};