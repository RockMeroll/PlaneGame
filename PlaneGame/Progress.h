#pragma once
#include "GameObject.h"

class CProgress :public CGameObject	//子弹类
{
public:
	CProgress(int x,int y,int nMontion); //坐标(继承自父类)，方向
	~CProgress(void);
	
	
	CProgress();

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();


	void SetInfo(int h, int v,int n);			//
	
	void SetTime(int m);


	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x,m_ptPos.y));
	}
private:
	static CImageList m_Images;		//进度条图像列表
	int    pro;				//时间，用于计算进度
};
