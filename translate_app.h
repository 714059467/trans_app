
// translate_app.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ctranslate_appApp: 
// �йش����ʵ�֣������ translate_app.cpp
//

class Ctranslate_appApp : public CWinApp
{
public:
	Ctranslate_appApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ctranslate_appApp theApp;