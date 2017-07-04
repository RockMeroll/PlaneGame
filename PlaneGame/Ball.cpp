#include "StdAfx.h"
#include "Ball.h"
#include "resource.h"

CImageList CBall::m_Images;

CBall::CBall(int x,int y,int nMontion):CGameObject(x,y),m_nMotion(nMontion)
{

}


CBall::CBall()
{

}


void CBall::SetInfo(int h, int v,int x,int y,int n)			//
{
	m_ptPos.x=h;
	m_ptPos.y=v;
	X=x;
	Y=y;
	flag=n;
}

CBall::~CBall(void)
{
}
BOOL CBall::Draw(CDC* pDC,BOOL bPause)
{
	if(!bPause)	
	{
		if(flag==1)
			m_ptPos.y = m_ptPos.y +  8;	//ÒÆ¶¯
		else if(flag==2)
		{	
			m_ptPos.x = m_ptPos.x +  X*4;
			m_ptPos.y = m_ptPos.y +  Y*4;
			
		}
	}

	//ÅÐ¶Ï³¬³öÆÁÄ»·¶Î§
	if(m_ptPos.y > GAME_HEIGHT+BALL_HEIGHT )
		return FALSE;
	if(m_ptPos.y < -BALL_HEIGHT)
		return FALSE;
	if(m_ptPos.x< 0)
		return FALSE;
	if(m_ptPos.x >GAME_WIDTH)
		return FALSE;
	
	m_Images.Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);

	return TRUE;
}

BOOL CBall::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BALL,RGB(0,0,0),8,8,1); 
}