#include "StdAfx.h"
#include "Explosion.h"
#include "resource.h"

CImageList CExplosion::m_Images;

CExplosion::CExplosion(int x,int y):CGameObject(x,y),m_nProcess(0)	//定义构造函数，物体位	置为x,y，图像索引的步进计数为m_nProcess=0
{
}
CExplosion::CExplosion()
{
}

void CExplosion::SetInfo(int x,int y)
{
		m_ptPos.x=x;
		m_ptPos.y=y;
		m_nProcess=0;   
}

CExplosion::~CExplosion(void)
{
}
BOOL CExplosion::Draw(CDC* pDC,BOOL bPause)	//定义Draw()函数
{
	//只有8张图片
	if(m_nProcess>=7)
	{
		m_nProcess=0;
		return FALSE;
	}

	//用新位置绘制图像
	m_Images.Draw(pDC,m_nProcess,m_ptPos,ILD_TRANSPARENT); //pDC:内存DC	m_nProcess:图片索引		m_ptPos:图片位置	ILD_TRASNPARENT :使用掩码绘制图象,不考虑背景色
	m_nProcess++;
	return TRUE;
}




BOOL CExplosion::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_EXPLOSION,RGB(0,0,0),66,66,8); //IDB_EXPLOSION:为图片ID
}


//LoadImage():载入图片到m_Images
//m_Images.Draw():绘制图片到内存DC