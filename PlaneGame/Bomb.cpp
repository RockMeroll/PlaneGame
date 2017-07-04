#include "StdAfx.h"
#include "Bomb.h"
#include "resource.h"


CImageList CBomb::m_Images;


CBomb::CBomb(int x,int y):CGameObject(x,y)
{

}

CBomb::CBomb()
{
	Index=0;
}
void CBomb:: SetInfo(int x,int y,int n)
{
	m_ptPos.x=x;
	m_ptPos.y=y;
	Index=n;
}

CBomb::~CBomb(void)
{
}
BOOL CBomb::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP15,RGB(0,0,0),10,20,5);
}
BOOL CBomb::Draw(CDC* pDC,BOOL bPause)
{
	int x=0;
	if(!bPause)
	{
		if(Index==0||Index==1)
		{
			x=0;
		}
		else if(Index==2)
		{
			m_ptPos.x=m_ptPos.x+3;
			x=1;
		}
		else if(Index==3)
		{
			m_ptPos.x=m_ptPos.x-3;
			x=2;
		}
		else if(Index==4)
		{
			m_ptPos.x=m_ptPos.x+7;
			x=3;
		}
		else if(Index==5)
		{
			m_ptPos.x=m_ptPos.x-7;
			x=4;
		}
		m_ptPos.y = m_ptPos.y - 16; //移动  本来是8
	}
	

	//判断超出屏幕范围
	if(m_ptPos.y < -BOMB_HEIGHT)
		return FALSE;
	if(m_ptPos.y > GAME_HEIGHT)
		return FALSE;
	m_Images.Draw(pDC,x,m_ptPos,ILD_TRANSPARENT);
	
	return TRUE;
}