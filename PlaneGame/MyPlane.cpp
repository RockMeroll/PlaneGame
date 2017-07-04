#include "StdAfx.h"
#include "MyPlane.h"
#include "resource.h"

CImageList CMyPlane::m_Images;
CImageList CMyPlane::m_Images_blood; //必须写这一句，相当于对m_Images_blood初始化，要不LoadImage2()无法访问

CMyPlane::~CMyPlane(void)
{
}
CMyPlane::CMyPlane(void):m_nHorMotion(0),m_nVerMotion(0)	//构造函数，水平和垂直方向都为0
{
	m_nWait = 0;		//发射延时
	m_ptPos.x = GAME_WIDTH/2-20;	//物体的位置x坐标
	m_ptPos.y = GAME_HEIGHT-50;	//物体的位置y坐标
	m_blood=10;

	m_ball=1;
	m_life=0;
	m_dazhao=1;
	m_fanghu=1;
}

BOOL CMyPlane::Fired()	//飞机在移动过程中不能发射
{
	if(m_nWait==0)		//当延迟是0时，可以
		return TRUE;
	else
		return FALSE;

}

BOOL CMyPlane::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP6,RGB(0,0,0),PLANE_WIDTH,PLANE_HEIGHT,4);	//调用GameObject.cpp中定义的LoadImage()函数
}

BOOL CMyPlane::LoadImage2()
{

	return CGameObject::LoadImage(m_Images_blood,IDB_BITMAP1,RGB(0,0,0),50,3,10);	//调用GameObject.cpp中定义的LoadImage()函数
}

BOOL CMyPlane::Draw(CDC* pDC,BOOL bPause)	//定义Draw()方法
{
	m_nWait++;
	if(m_nWait>3)
		m_nWait=0;


	if(!bPause)	//如果没停止
	{
		m_ptPos.x = m_ptPos.x + m_nHorMotion*10;	//将物体x坐标+水平方向*6，如 m_ptPos.x = m_ptPos.x + 1*6 ，表示向右走了6个像素
		m_ptPos.y = m_ptPos.y - m_nVerMotion*10;	//将物体y坐标+垂直方向*6，如 m_ptPos.y = m_ptPos.y + -1*6 ，表示向下走了6个像素
	}

	if(m_ptPos.x>=GAME_WIDTH-PLANE_WIDTH)	//如果物体x坐标超过了 屏幕的宽度-飞机的宽度，则不能再增加
		m_ptPos.x =GAME_WIDTH-PLANE_WIDTH;
	if(m_ptPos.x<=0)
		m_ptPos.x=0;

	if(m_ptPos.y<=0)
		m_ptPos.y =0;

	if(m_ptPos.y>=GAME_HEIGHT-PLANE_HEIGHT)
		m_ptPos.y=GAME_HEIGHT-PLANE_HEIGHT;	//至此同理

	if(m_ball>8)
		m_ball=8;
	m_Images.Draw(pDC,(m_ball-1)%4,m_ptPos,ILD_TRANSPARENT);//调用CImageList的Draw()函数，绘制在拖放操作中正在被拖动的图象，ILD_TRANSPARENT表示使用掩码，无论背景色，透明地绘制图像。
	m_Images_blood.Draw(pDC,m_blood,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}