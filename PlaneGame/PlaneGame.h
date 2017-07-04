// PlaneGame.h : PlaneGame 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CPlaneGameApp:
// 有关此类的实现，请参阅 PlaneGame.cpp
//

class CPlaneGameApp : public CWinApp //应用程序类
{
public:
	CPlaneGameApp();



// 重写
public:
	virtual BOOL InitInstance();

	//int ExitInstance();
	
// 实现
	afx_msg void OnAppAbout();//关于					程序第六步
	DECLARE_MESSAGE_MAP()
};

extern CPlaneGameApp theApp;