#include "StdAfx.h"
#include "Gold.h"
#include "resource.h"

CImageList CGold::m_Images;

CGold::CGold(int x,int y,int nMontion):CGameObject(x,y),index(nMontion)
{

}


CGold::CGold()
{
	index=0;
	v=1;
}


void CGold::SetInfo(int h, int v,int n,int m)			//
{
	m_ptPos.x=h;
	m_ptPos.y=v;
	m_planePos.x=n;
	m_planePos.y=m;
	v=1;
}

CGold::~CGold(void)
{
}
BOOL CGold::Draw(CDC* pDC,BOOL bPause)
{
	if(!bPause)	
	{

		h_h= m_planePos.y-m_ptPos.y;
		v_h= m_planePos.x-m_ptPos.x;
		if(!(m_ptPos.x>m_planePos.x&&m_ptPos.x<m_planePos.x+6))
		{
			if(v_h>0)
				m_ptPos.x=m_ptPos.x+5;
			if(v_h<0)
				m_ptPos.x=m_ptPos.x-5;
		}

		if(!(m_ptPos.y>m_planePos.y&&m_ptPos.y<m_planePos.y+11))
		{
			if(h_h>0)
				m_ptPos.y=m_ptPos.y+10;
			if(h_h<0)
				m_ptPos.y=m_ptPos.y-10;
		}
		
	}

	if(index>5)
	{
		index=0;
		//return FALSE;
	}
	//ÅÐ¶Ï³¬³öÆÁÄ»·¶Î§
	if(m_ptPos.y > GAME_HEIGHT+BALL_HEIGHT )
		return FALSE;
	if(m_ptPos.y < -BALL_HEIGHT)
		return FALSE;
	
	m_Images.Draw(pDC,index,m_ptPos,ILD_TRANSPARENT);
	index++;
	return TRUE;
}

BOOL CGold::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP12,RGB(0,0,0),15,15,6); 
}