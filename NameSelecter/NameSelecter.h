
// NameSelecter.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNameSelecterApp: 
// �йش����ʵ�֣������ NameSelecter.cpp
//

class CNameSelecterApp : public CWinApp
{
public:
	CNameSelecterApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNameSelecterApp theApp;