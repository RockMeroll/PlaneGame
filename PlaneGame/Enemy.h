#pragma once
#include "gameobject.h"

class CEnemy :public CGameObject //敌机类
{
public:
	CEnemy(void);
	~CEnemy(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();
	static BOOL LoadImage2();

	int getBlood()
	{
		return m_blood;
	}
	void setBlood(int x)
	{
		m_blood=x;
	}

	void setToBomb2(POSITION t)
	{
		ToBomb2=t;
	}
	POSITION getToBomb2()
	{
		return ToBomb2;
	}


	void setPoint(int x, int y)
	{
		m_ptPos.x=x;
		m_ptPos.y=y;
	}
	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+ENEMY_HEIGHT,m_ptPos.y+ENEMY_HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
	//是否可以开火发射子弹
	BOOL Fired();
private:
	static const int ENEMY_HEIGHT = 35;
	static CImageList m_Images;
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上
	//图像索引
	int m_nImgIndex;
	//速度
	int m_V;
	int    m_nWait;//发射延时


	static CImageList m_Images_blood; 
	int    m_blood;				//血量

	POSITION ToBomb2;

};
