#include "StdAfx.h"
#include "bomb2.h"
#include "resource.h"
#include "math.h"
CImageList CBomb2::m_Images;

CBomb2::CBomb2(int x,int y,int nMontion):CGameObject(x,y),index(nMontion)
{

}


CBomb2::CBomb2()
{
	index=0;
	v=1;
	ToEnemy=0;
}


void CBomb2::SetInfo(int h, int v,int n,int m)			//
{
	m_ptPos.x=h;
	m_ptPos.y=v;
	m_EnemyPos.x=n;
	m_EnemyPos.y=m;
	v=1;
}

CBomb2::~CBomb2(void)
{
}
BOOL CBomb2::Draw(CDC* pDC,BOOL bPause)
{
	if(!bPause)	
	{

		h_h= m_EnemyPos.y-m_ptPos.y;
		v_h= m_EnemyPos.x-m_ptPos.x;
		//if(!(m_ptPos.x>m_EnemyPos.x&&m_ptPos.x<m_EnemyPos.x+6))
		//if(!(m_ptPos.y>m_EnemyPos.y&&m_ptPos.y<m_EnemyPos.y+11))
		
		double h=h_h;
		double v=v_h;
			if(h_h>0)
			{
				if(h/v>0&&h/v<=1)
					index=5;
				else if(h/v>1)
					index=6;
				else if(h/v<-3.73205)
					index=7;	
				else if(h/v>=-3.73205&&h/v<-1.73205)
					index=8;
				else if(h/v>=-1.73205&&h/v<0)
					index=9;
				else
					index=7;
				//m_ptPos.x=m_ptPos.x-5;
			
			}else if(h_h<0)
			{	
				h=-h;
				if(h/v>0&&h/v<=1)
					index=3;
				else if(h/v>1&&h/v<=1.73205)
					index=2;
				else if(h/v>1.73205&&h/v<=3.73205)
					index=1;
				else if(h/v>3.73205)
					index=0;
				else if(h/v<-3.73205)
					index=12;	
				else if(h/v>=-3.73205&&h/v<-1.73205)
					index=11;
				else if(h/v>=-1.73205&&h/v<-1)
					index=10;
				else if(h/v>=-1)
					index=9;
				else 
					index=0;
				
				//m_ptPos.x=m_ptPos.x-5;
			
			}
				
		if(!(m_ptPos.x>m_EnemyPos.x&&m_ptPos.x<m_EnemyPos.x+11))
		{
			if(v_h>0)
				m_ptPos.x=m_ptPos.x+12;
			if(v_h<0)
				m_ptPos.x=m_ptPos.x-12;
		}

		if(!(m_ptPos.y>m_EnemyPos.y&&m_ptPos.y<m_EnemyPos.y+11))
		{
			if(h_h>0)
				m_ptPos.y=m_ptPos.y+12;
			if(h_h<0)
				m_ptPos.y=m_ptPos.y-12;
		}
		
	}


	//ÅÐ¶Ï³¬³öÆÁÄ»·¶Î§
	if(m_ptPos.y > GAME_HEIGHT+BALL_HEIGHT )
		return FALSE;
	if(m_ptPos.y < -BALL_HEIGHT)
		return FALSE;
	
	m_Images.Draw(pDC,index,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}

BOOL CBomb2::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP7,RGB(0,0,0),20,20,13); 
}