
// JALKitDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CJALKitDemoApp:
// �йش����ʵ�֣������ JALKitDemo.cpp
//

class CJALKitDemoApp : public CWinApp
{
public:
	CJALKitDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CJALKitDemoApp theApp;