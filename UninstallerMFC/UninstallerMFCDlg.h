
// UninstallerMFCDlg.h: файл заголовка
//

#pragma once
#include <vector>
#include "AppList.h"

std::vector<UninstallInfo> uninstallInfoVector;
// Диалоговое окно CUninstallerMFCDlg
class CUninstallerMFCDlg : public CDialogEx
{
// Создание
public:
	CUninstallerMFCDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UNINSTALLERMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV

	
// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl hListCtr;
	afx_msg void OnBnClickedButton1();
};
