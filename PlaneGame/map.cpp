#include "StdAfx.h"
#include "map.h"
#include "resource.h"

CImageList CMaps::m_Images;
CImageList CMaps::m_Images2;

CMaps::CMaps(int x,int y,int nMontion):CGameObject(x,y),m_nMotion(nMontion)
{

}


CMaps::CMaps()
{
	index=0;
}


void CMaps::SetInfo(int h, int v,int h2 ,int v2 ,int n)			//
{
	m_ptPos.x=h;
	m_ptPos.y=v;
	m_ptPos2.x=h2;
	m_ptPos2.y=v2;
	index=n;
}

CMaps::~CMaps(void)
{
}
BOOL CMaps::Draw(CDC* pDC,BOOL bPause)
{
	if(!bPause)	
	{
		m_ptPos.y = m_ptPos.y + 2;	//ÒÆ¶¯
	}

	//ÅÐ¶Ï³¬³öÆÁÄ»·¶Î§
	if(m_ptPos.y > GAME_HEIGHT )
		m_ptPos.y=-800;
	
	if(!bPause)	
	{
		m_ptPos2.y = m_ptPos2.y + 2;	//ÒÆ¶¯
	}

	//ÅÐ¶Ï³¬³öÆÁÄ»·¶Î§
	if(m_ptPos2.y > GAME_HEIGHT)
		m_ptPos2.y=-800;

	if(index>4)
	{	
		index=4;
	}
	
	m_Images.Draw(pDC,index,m_ptPos,ILD_TRANSPARENT);
	m_Images2.Draw(pDC,index,m_ptPos2,ILD_TRANSPARENT);
	
	return TRUE;
}

BOOL CMaps::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP21,RGB(0,0,0),600,800,5); 
}
BOOL CMaps::LoadImage2()
{
	return CGameObject::LoadImage(m_Images2,IDB_BITMAP21,RGB(0,0,0),600,800,5); 
}
