#include "StdAfx.h"
#include "Strengthen.h"
#include "resource.h"

CImageList CStrengthen::m_Images;

CStrengthen::CStrengthen(void)	//构造函数
{

	//随机确定X位置
	m_ptPos.x = rand()%(GAME_WIDTH-ENEMY_HEIGHT)+1;

	//随机确定图像索引
	//m_nImgIndex = rand()%2;
	
	m_nImgIndex = 0;
	
	//根据图像索引确定方向
	m_nMotion=1;
	m_ptPos.y=-ENEMY_HEIGHT;
	jiemian=false;
	
	//随机确定速度
	m_V = rand()%6+2;

}



CStrengthen::~CStrengthen(void)
{
}
BOOL CStrengthen::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP14,RGB(0,0,0),30,30,3); //2表示图片里包括两个子图片，即两个敌机图片
}

BOOL CStrengthen::Draw(CDC* pDC,BOOL bPause)
{
	if(!jiemian)
	{
		if(!bPause)
		{
			m_ptPos.y = m_ptPos.y + m_nMotion * m_V;	//移动
		}
	}
	

	//判断超出屏幕范围
	if(m_ptPos.y > GAME_HEIGHT+ENEMY_HEIGHT )
		return FALSE;
	if(m_ptPos.y < -ENEMY_HEIGHT)
		return FALSE;

	if(m_nImgIndex<4&&m_nImgIndex>=0)
		m_Images.Draw(pDC,m_nImgIndex,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}
BOOL CStrengthen::Fired() //敌机在移动过程中不能发射
{
		return TRUE;
}