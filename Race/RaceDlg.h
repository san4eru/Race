
// RaceDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CRaceDlg
class CRaceDlg : public CDialogEx
{
// Создание
public:
	CRaceDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RACE_DIALOG };
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
	CProgressCtrl p1;
	CProgressCtrl p2;
	CProgressCtrl p3;
	CProgressCtrl p4;
	afx_msg void OnBnClickedButton1();
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
