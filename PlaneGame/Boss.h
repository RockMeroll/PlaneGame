#pragma once
#include "gameobject.h"

class CBoss :public CGameObject //敌机类
{
public:
	CBoss(void);
	~CBoss(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();
	static BOOL LoadImage2();
	static BOOL LoadImage3();
	static BOOL LoadImage4();
	//真BOSS
	int getBossBlood()
	{
		return BOSS_BLOOD;
	}
	int getBlood()
	{
		return m_blood;
	}
	void setBlood(int x)
	{
		m_blood=x;
	}

	void setIndex(int x)
	{
		m_nImgIndex=x;
	}
	//小BOSS
	int getBossBlood2()
	{
		return BOSS_BLOOD2;
	}
	int getBlood2()
	{
		return m_blood2;
	}
	void setBlood2(int x)
	{
		m_blood2=x;
	}

	void setIndex2(int x)
	{
		m_nImgIndex2=x;
	}
	CPoint GetPoint2()
	{
		return m_ptPos2;
	}



	bool getZhenboss()
	{
		return zhenboss;
	}
	void setZhenboss(bool x)
	{
		zhenboss=x;
	}

	bool getMove()
	{
		return move;
	}

	CRect GetRect()
	{
		if(zhenboss)
			return CRect(m_ptPos,CPoint(m_ptPos.x+ENEMY_WIDTH,m_ptPos.y+ENEMY_HEIGHT));
		else
			return CRect(m_ptPos2,CPoint(m_ptPos2.x+80,m_ptPos2.y+80));
	}

	void setTimeY(int t)
	{
		timeY=t;
	}
	void setTimeX(int t)
	{
		timeX=t;
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
	//是否可以开火发射子弹
	BOOL Fired();
private:
	static const int BOSS_BLOOD = 500;
	static const int BOSS_BLOOD2 = 50;
	static const int ENEMY_HEIGHT = 75;
	static const int ENEMY_WIDTH = 100;
	static CImageList m_Images;
	static CImageList m_Images2;
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上
	int    m_nMotion2;
	//图像索引
	int m_nImgIndex;
	int m_nImgIndex2;
	//速度
	int m_V;
	int    m_nWait;//发射延时
	bool move;
	int timeY;
	int timeX;
	static CImageList m_Images_blood; 
	static CImageList m_Images_blood2; 
	int    m_blood;				//血量
	int    m_blood2;				//血量

	bool zhenboss;
	 CPoint m_ptPos2;

	 int fangxiangX;
	 int fangxiangY;
};
