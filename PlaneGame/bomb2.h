#pragma once
#include "GameObject.h"

class CBomb2 :public CGameObject	//子弹类
{
public:
	CBomb2(int x,int y,int nMontion); //坐标(继承自父类)，方向
	~CBomb2(void);
	
	
	CBomb2();

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();


	void SetInfo(int h, int v,int n,int m);			//

	void setToEnemy(POSITION t)
	{
		ToEnemy=t;
	}
	POSITION getToEnemy()
	{
		return ToEnemy;
	}

	void SetPlane(int x,int y)
	{
		m_EnemyPos.x=x;
		m_EnemyPos.y=y;
	}

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+BALL_HEIGHT,m_ptPos.y+BALL_HEIGHT));
	}
private:
	static const int BALL_HEIGHT=20; //子弹的高度和宽度
	static CImageList m_Images;		//子弹图像列表
	int index;				//方向
	CPoint m_EnemyPos;
	int v;
	int h_h;
	int v_h;
	POSITION ToEnemy;
};
