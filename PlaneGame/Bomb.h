#pragma once
#include "gameobject.h"

class CBomb :public CGameObject	//µºµØ¿‡
{
public:
	CBomb();
	CBomb(int x,int y);
	~CBomb(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();

	void SetInfo(int x,int y,int n);
	int getHeight()
	{
		return BOMB_HEIGHT;
	}

	int getIndex()
	{
		return Index;
	}
	void setInde(int x)
	{
		Index=x;
	}

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+10,m_ptPos.y+BOMB_HEIGHT));
	}
private:
	static const int BOMB_HEIGHT = 20;
	static CImageList m_Images;
	int Index;
};
