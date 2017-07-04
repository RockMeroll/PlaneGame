#pragma once
#include "gameobject.h"

class CExplosion :public CGameObject	//继承CGameObject类，并对父类函数进行重写
{
public:
	CExplosion();
	CExplosion(int x,int y);	//构造函数
	~CExplosion(void);

	BOOL Draw(CDC* pDC,BOOL bPause);	//声明

	static BOOL LoadImage();	//声明

	void SetInfo(int x,int y);

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+EXPLOSION_WIDTH,m_ptPos.y+EXPLOSION_WIDTH));
	}
private:
	//炸弹的图片列表
	static CImageList m_Images;
	//图像索引
	int   m_nProcess;
public:
	static const int  EXPLOSION_WIDTH = 66;

};
