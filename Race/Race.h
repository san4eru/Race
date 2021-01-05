
// Race.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CRaceApp:
// Сведения о реализации этого класса: Race.cpp
//

class CRaceApp : public CWinApp
{
public:
	CRaceApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CRaceApp theApp;
