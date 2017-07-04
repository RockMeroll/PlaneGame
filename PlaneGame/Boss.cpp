#include "StdAfx.h"
#include "Boss.h"
#include "resource.h"

CImageList CBoss::m_Images;
CImageList CBoss::m_Images_blood;
CImageList CBoss::m_Images2;
CImageList CBoss::m_Images_blood2;

CBoss::CBoss(void)	//构造函数
{
	m_blood=BOSS_BLOOD;
	m_blood2=BOSS_BLOOD2;
	//随机确定X位置
	m_ptPos.x = rand()%(GAME_WIDTH-ENEMY_HEIGHT)+1;
	m_ptPos2.x = rand()%(GAME_WIDTH-ENEMY_HEIGHT)+1;
	//随机确定图像索引
	//m_nImgIndex = rand()%2;
	
	m_nImgIndex = 0;
	m_nImgIndex2= rand()%2;
	move=true;
	//根据图像索引确定方向
	m_nMotion=1;
	m_nMotion2=1;
	
	m_ptPos.x=GAME_WIDTH/2-50;
	m_ptPos.y=-ENEMY_HEIGHT;

	m_ptPos2.x=-80;
	m_ptPos2.y=0;

	
	/*
	if (m_nImgIndex%2!=0)//如果是图像索引是偶数，即m_nImgIndex是奇数=1的飞机图片是向上飞的
	{
		m_nMotion=-1;
		m_ptPos.y = GAME_HEIGHT+ENEMY_HEIGHT;

	}
	*/
	
	
	//随机确定速度
	m_V = rand()%3+2;
	fangxiangX=1;
	fangxiangY=1;
	m_nWait=0;
}



CBoss::~CBoss(void)
{
}
BOOL CBoss::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP9,RGB(0,0,0),100,75,2); //2表示图片里包括两个子图片，即两个敌机图片
}
BOOL CBoss::LoadImage2()
{
	return CGameObject::LoadImage(m_Images_blood,IDB_BITMAP10,RGB(0,0,0),100,3,10); //2表示图片里包括两个子图片，即两个敌机图片
}

BOOL CBoss::LoadImage3()
{
	return CGameObject::LoadImage(m_Images2,IDB_BITMAP19,RGB(255,255,255),80,80,2); //2表示图片里包括两个子图片，即两个敌机图片

}
BOOL CBoss::LoadImage4()
{
	return CGameObject::LoadImage(m_Images_blood2,IDB_BITMAP20,RGB(0,0,0),80,3,10); //2表示图片里包括两个子图片，即两个敌机图片

}



BOOL CBoss::Draw(CDC* pDC,BOOL bPause)
{
	m_nWait++;
	if(m_nWait>20) //延迟20后绘制飞机
		m_nWait=0;

	if(!bPause)
	{
		
		m_ptPos.y = m_ptPos.y +  m_V;	//BOSS移动
		if(m_ptPos.y>ENEMY_HEIGHT+10)
		{
			m_ptPos.y=ENEMY_HEIGHT+10;
			if((timeX-timeY)>200&&(timeX-timeY)<400)
			{
				move=false;	
			}else if(timeX-timeY>400)
			{
				timeY=timeX;
			}else
			{
				//BOSS移动
				m_ptPos.x=m_ptPos.x+m_nMotion*m_V;
				if(m_ptPos.x>GAME_WIDTH-ENEMY_WIDTH||m_ptPos.x<0)
					m_nMotion=-m_nMotion;
				


				//小BOSS移动
				m_ptPos2.y = m_ptPos2.y +  fangxiangY*2;	
				m_ptPos2.x = m_ptPos2.x +  fangxiangX*2;	
				if(m_ptPos2.y>GAME_HEIGHT/3||m_ptPos2.y<0)
				{
					fangxiangY=-fangxiangY;
				}
				if(m_ptPos2.x>GAME_WIDTH-80||m_ptPos2.x<-80)
				{
					fangxiangX=-fangxiangX;
				}

				move=true;	

			}
		}
	
		

		

	}

	//判断超出屏幕范围
	if(m_ptPos.y > GAME_HEIGHT+ENEMY_HEIGHT )
		return FALSE;
	if(m_ptPos.y < -ENEMY_HEIGHT)
		return FALSE;
	
	if(m_ptPos2.y > GAME_HEIGHT+ENEMY_HEIGHT )
		return FALSE;
	if(m_ptPos2.y < -ENEMY_HEIGHT)
		return FALSE;

	if(zhenboss&&m_nImgIndex<6)
	{
		m_Images.Draw(pDC,m_nImgIndex,m_ptPos,ILD_TRANSPARENT);
		m_Images_blood.Draw(pDC,m_blood/(BOSS_BLOOD/10),m_ptPos,ILD_TRANSPARENT);
	}
	if(!zhenboss&&m_nImgIndex<2)
	{
		
		m_Images2.Draw(pDC,m_nImgIndex2,m_ptPos2,ILD_TRANSPARENT);
		m_Images_blood2.Draw(pDC,m_blood2/(BOSS_BLOOD2/10),m_ptPos2,ILD_TRANSPARENT);
	}
	return TRUE;
}
BOOL CBoss::Fired() //敌机在移动过程中不能发射
{
	if(m_nWait==0)
	{
			
		return TRUE;
	}
	else
		return FALSE;
}