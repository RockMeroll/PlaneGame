#pragma once
#include "GameObject.h"

class CBall :public CGameObject	//子弹类
{
public:
	CBall(int x,int y,int nMontion); //坐标(继承自父类)，方向
	~CBall(void);
	
	
	CBall();

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();


	int flag;

	void SetInfo(int h, int v,int x,int y,int n);			//



	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+BALL_HEIGHT,m_ptPos.y+BALL_HEIGHT));
	}
private:
	static const int BALL_HEIGHT=8; //子弹的高度和宽度
	static CImageList m_Images;		//子弹图像列表
	int    m_nMotion;				//方向
	int X;
	int Y;
};
