// PlaneGame.h : PlaneGame Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CPlaneGameApp:
// �йش����ʵ�֣������ PlaneGame.cpp
//

class CPlaneGameApp : public CWinApp //Ӧ�ó�����
{
public:
	CPlaneGameApp();



// ��д
public:
	virtual BOOL InitInstance();

	//int ExitInstance();
	
// ʵ��
	afx_msg void OnAppAbout();//����					���������
	DECLARE_MESSAGE_MAP()
};

extern CPlaneGameApp theApp;