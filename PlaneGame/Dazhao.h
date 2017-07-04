#pragma once
#include "GameObject.h"

class CDazhao :public CGameObject	//�ӵ���
{
public:
	CDazhao(int x,int y,int nMontion); //����(�̳��Ը���)������
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
	static const int BALL_HEIGHT=256; //�ӵ��ĸ߶ȺͿ��
	static CImageList m_Images;		//�ӵ�ͼ���б�			
	int flag;
	CPoint yuan;
	int index;
	int timeY;
	int timeX;
};
