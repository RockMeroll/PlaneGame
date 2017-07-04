#pragma once
#include "GameObject.h"

class CDazhao :public CGameObject	//子弹类
{
public:
	CDazhao(int x,int y,int nMontion); //坐标(继承自父类)，方向
	~CDazhao(void);
	
	
	CDazhao();

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();


	void SetInfo(int h, int v,int n);			//
	
	void setTimeY(int t)
	{
		timeY=t;
	}
	void setTimeX(int t)
	{
		timeX=t;
	}

	CRect GetRect()
	{
		if(flag==2)
			return CRect(CPoint(m_ptPos.x+90,m_ptPos.y),CPoint(m_ptPos.x+BALL_HEIGHT-90,m_ptPos.y+BALL_HEIGHT));
		else 
			return CRect(m_ptPos,CPoint(m_ptPos.x+BALL_HEIGHT,m_ptPos.y+BALL_HEIGHT));
	
	}
private:
	static const int BALL_HEIGHT=256; //子弹的高度和宽度
	static CImageList m_Images;		//子弹图像列表			
	int flag;
	CPoint yuan;
	int index;
	int timeY;
	int timeX;
};
