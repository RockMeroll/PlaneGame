#include "StdAfx.h"
#include "Enemy.h"
#include "resource.h"

CImageList CEnemy::m_Images;
CImageList CEnemy::m_Images_blood;

CEnemy::CEnemy(void)	//构造函数
{
	m_blood=5;

	//随机确定X位置
	m_ptPos.x = rand()%(GAME_WIDTH-ENEMY_HEIGHT)+1;

	//随机确定图像索引
	//m_nImgIndex = rand()%2;
	
	m_nImgIndex = 0;
	
	//根据图像索引确定方向
	m_nMotion=1;
	m_ptPos.y=-ENEMY_HEIGHT;
	
	/*
	if (m_nImgIndex%2!=0)//如果是图像索引是偶数，即m_nImgIndex是奇数=1的飞机图片是向上飞的
	{
		m_nMotion=-1;
		m_ptPos.y = GAME_HEIGHT+ENEMY_HEIGHT;

	}
	*/
	
	
	//随机确定速度
	m_V = rand()%6+2;

	m_nWait=0;
	ToBomb2=NULL;
}



CEnemy::~CEnemy(void)
{
}
BOOL CEnemy::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_ENEMY,RGB(0,0,0),35,35,2); //2表示图片里包括两个子图片，即两个敌机图片
}
BOOL CEnemy::LoadImage2()
{
	return CGameObject::LoadImage(m_Images_blood,IDB_BITMAP2,RGB(0,0,0),35,2,5); //2表示图片里包括两个子图片，即两个敌机图片
}


BOOL CEnemy::Draw(CDC* pDC,BOOL bPause)
{
	m_nWait++;
	if(m_nWait>20) //延迟20后绘制飞机
		m_nWait=0;

	if(!bPause)
	{
		m_ptPos.y = m_ptPos.y + m_nMotion * m_V;	//移动
	}
	
	if(m_blood<1)
		return FALSE;
	
	//判断超出屏幕范围
	if(m_ptPos.y > GAME_HEIGHT+ENEMY_HEIGHT )
		return FALSE;
	if(m_ptPos.y < -ENEMY_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC,m_nImgIndex,m_ptPos,ILD_TRANSPARENT);
	m_Images_blood.Draw(pDC,m_blood,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}
BOOL CEnemy::Fired() //敌机在移动过程中不能发射
{
	if(m_nWait==0)
		return TRUE;
	else
		return FALSE;
}