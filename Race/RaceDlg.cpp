
// RaceDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Race.h"
#include "RaceDlg.h"
#include "afxdialogex.h"

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


// Диалоговое окно CRaceDlg



CRaceDlg::CRaceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RACE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, p1);
	DDX_Control(pDX, IDC_PROGRESS2, p2);
	DDX_Control(pDX, IDC_PROGRESS3, p3);
	DDX_Control(pDX, IDC_PROGRESS4, p4);
}

BEGIN_MESSAGE_MAP(CRaceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRaceDlg::OnBnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Обработчики сообщений CRaceDlg

BOOL CRaceDlg::OnInitDialog()
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

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CRaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRaceDlg::OnPaint()
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
HCURSOR CRaceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int flag = 0;

void CRaceDlg::OnBnClickedButton1()
{
	p1.SetPos(0);
	p2.SetPos(0);
	p3.SetPos(0);
	p4.SetPos(0);
	flag = 0;
	srand(time(0));
	SetTimer(1, 500, 0);
}

void CRaceDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1)
	{
		p1.SetPos(p1.GetPos() + rand() % 50);
		p2.SetPos(p2.GetPos() + rand() % 50);
		p3.SetPos(p3.GetPos() + rand() % 50);
		p4.SetPos(p4.GetPos() + rand() % 50);

		if (p1.GetPos() == 100 && flag == 0)
			flag = 1;

		if (p2.GetPos() == 100 && flag == 0)
			flag = 2;

		if (p3.GetPos() == 100 && flag == 0)
			flag = 3;

		if (p4.GetPos() == 100 && flag == 0)
			flag = 4;

		if (p1.GetPos() == 100 && p2.GetPos() == 100 && p3.GetPos() == 100 && p4.GetPos() == 100)
		{
			KillTimer(1);

			if (flag == 1)
				MessageBox(L"Победил 1-ый!");
			else if (flag == 2)
				MessageBox(L"Победил 2-ой!");
			else if (flag == 3)
				MessageBox(L"Победил 3-ий!");
			else if (flag == 4)
				MessageBox(L"Победил 4-ый!");
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}
