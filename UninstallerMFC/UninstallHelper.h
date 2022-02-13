#pragma once
#include <vector>
#include "AppList.h"
class UninstallHelper
{
	std::vector<UninstallInfo> uninstallInfoVector;
	void Applist_X32();
	void Applist_X64();
	void App_user();
	public:
		bool GetUninstallVector(std::vector<UninstallInfo> *uninstallInfoVector);
};

bool CheckRegExist(HKEY RootKey, LPCTSTR _SubKey);

