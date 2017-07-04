#pragma once
#include "GameObject.h"

class CMaps :public CGameObject	//子弹类
{
public:
	CMaps(int x,int y,int nMontion); //坐标(继承自父类)，方向
	~CMaps(void);
	
	
	CMaps();

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();
	static BOOL LoadImage2();

	

	void SetInfo(int h, int v,int h2,int v2,int n);			//
	
	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x,m_ptPos.y));
	}

private:

	static CImageList m_Images;		//星球图像列表
	static CImageList m_Images2;		//星球图像列表
	int    m_nMotion;				//方向
	CPoint  m_ptPos2;
	int index;
};
