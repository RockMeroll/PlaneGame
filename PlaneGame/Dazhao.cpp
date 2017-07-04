#include "StdAfx.h"
#include "Dazhao.h"
#include "resource.h"

CImageList CDazhao::m_Images;

CDazhao::CDazhao(int x,int y,int nMontion):CGameObject(x,y)
{

}


CDazhao::CDazhao()
{

}


void CDazhao::SetInfo(int h, int v,int n)			//
{
	m_ptPos.x=h;
	m_ptPos.y=v;
	yuan.x=h;
	yuan.y=v;
	flag=n;

	if(flag==1)
		index=0;
	else if(flag==2)
		index=3;
	else if(flag==3)
		index=4;
}

CDazhao::~CDazhao(void)
{
}
BOOL CDazhao::Draw(CDC* pDC,BOOL bPause)
{
	if(!bPause)	
	{
		
		if(flag==1)
		{
			if(m_ptPos.y<yuan.y-200)
			{
				if(index==0)
				{
					index=1;
				}else if(index==1)
				{
					index=2;
				}else if(index==2)
				{
					index=1;
				}
			}else
			{
				m_ptPos.y = m_ptPos.y -8;	//ÒÆ¶¯
			}
		}else if(flag==2)
		{
			index=3;
		}
		else if(flag==3)
		{
			index=4;
			
		}
		
	}
	if(timeX-timeY>200)
		return FALSE;
	//ÅÐ¶Ï³¬³öÆÁÄ»·¶Î§
	if(m_ptPos.y > GAME_HEIGHT+BALL_HEIGHT )
		return FALSE;
	if(m_ptPos.y < -BALL_HEIGHT)
		return FALSE;
	
	m_Images.Draw(pDC,index,m_ptPos,ILD_TRANSPARENT);

	return TRUE;
}

BOOL CDazhao::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP17,RGB(0,0,0),256,250,6); 
}