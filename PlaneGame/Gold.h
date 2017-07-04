#pragma once
#include "GameObject.h"

class CGold :public CGameObject	//�ӵ���
{
public:
	CGold(int x,int y,int nMontion); //����(�̳��Ը���)������
	~CGold(void);
	
	
	CGold();

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();


	void SetInfo(int h, int v,int n,int m);			//

	void SetPlane(int x,int y)
	{
		m_planePos.x=x;
		m_planePos.y=y;
	}

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+BALL_HEIGHT,m_ptPos.y+BALL_HEIGHT));
	}
private:
	static const int BALL_HEIGHT=15; //�ӵ��ĸ߶ȺͿ��
	static CImageList m_Images;		//�ӵ�ͼ���б�
	int index;				//����
	CPoint m_planePos;
	int v;
	int h_h;
	int v_h;
};
