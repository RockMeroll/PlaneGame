#include "StdAfx.h"
#include "Progress.h"
#include "resource.h"

CImageList CProgress::m_Images;

CProgress::CProgress(int x,int y,int _time):CGameObject(x,y),pro(_time)
{

}


CProgress::CProgress()
{

}
void CProgress::SetTime(int m)
{
	pro=m;
}


void CProgress::SetInfo(int h, int v,int n)			//
{
	m_ptPos.x=h;
	m_ptPos.y=v;
	pro=n;
}

CProgress::~CProgress(void)
{
}
BOOL CProgress::Draw(CDC* pDC,BOOL bPause)
{

	m_Images.Draw(pDC,pro,m_ptPos,ILD_TRANSPARENT);

	return TRUE;
}

BOOL CProgress::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP5,RGB(0,0,0),50,3,10); 
}