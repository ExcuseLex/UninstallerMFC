
// UninstallerMFCDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "UninstallerMFC.h"
#include "UninstallerMFCDlg.h"
#include "UninstallHelper.h"
#include "afxdialogex.h"
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CUninstallerMFCDlg



CUninstallerMFCDlg::CUninstallerMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UNINSTALLERMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUninstallerMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, hListCtr);
}

BEGIN_MESSAGE_MAP(CUninstallerMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CUninstallerMFCDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CUninstallerMFCDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений CUninstallerMFCDlg





BOOL CUninstallerMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	

	hListCtr.InsertColumn(0, L"ID", LVCFMT_LEFT, 30);		
	hListCtr.InsertColumn(1, L"Name", LVCFMT_LEFT, 140);
	hListCtr.InsertColumn(2, L"Version", LVCFMT_LEFT, 100);
	hListCtr.InsertColumn(3, L"Size", LVCFMT_LEFT, 80);
	hListCtr.GetSelectionMark();
	hListCtr.SetExtendedStyle(hListCtr.GetExtendedStyle() | LVS_EX_FULLROWSELECT);


	int nItem;

	
	UninstallHelper uninstallHelper;
	/*std::vector<UninstallInfo> uninstallInfoVector;*/
	uninstallHelper.GetUninstallVector(&uninstallInfoVector);

 	for (int i = 0; i < uninstallInfoVector.size(); i++)
	{
		nItem = hListCtr.InsertItem(i, L"1");
		hListCtr.SetItemText(nItem, 1, uninstallInfoVector[i].DisplayName.c_str());
		hListCtr.SetItemText(nItem, 2, L"1.1");
		hListCtr.SetItemText(nItem, 3, L"100 mb");
	}
	

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CUninstallerMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CUninstallerMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CUninstallerMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUninstallerMFCDlg::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}


void CUninstallerMFCDlg::OnBnClickedButton1()
{
	auto ggg = hListCtr.GetSelectionMark();

	PROCESS_INFORMATION PI;
	STARTUPINFOW SI;
	ZeroMemory(&PI, sizeof(PI));
	ZeroMemory(&SI, sizeof(SI));
	SI.cb = sizeof(STARTUPINFOW);

	if (CreateProcessW(NULL, (LPWSTR)uninstallInfoVector[ggg].UninstallPath.c_str(), NULL, NULL, FALSE, NULL, NULL, NULL, &SI, &PI))
	{
		WaitForSingleObject(PI.hProcess, INFINITE);
		CloseHandle(PI.hProcess);
		CloseHandle(PI.hThread);
	}
	int g = GetLastError();

	CheckRegExist();
}
