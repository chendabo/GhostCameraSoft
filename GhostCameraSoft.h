
// GhostCameraSoft.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGhostCameraSoftApp: 
// �йش����ʵ�֣������ GhostCameraSoft.cpp
//

class CGhostCameraSoftApp : public CWinApp
{
public:
	CGhostCameraSoftApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGhostCameraSoftApp theApp;