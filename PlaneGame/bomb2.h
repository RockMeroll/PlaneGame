#pragma once
#include "GameObject.h"

class CBomb2 :public CGameObject	//�ӵ���
{
public:
	CBomb2(int x,int y,int nMontion); //����(�̳��Ը���)������
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
	static const int BALL_HEIGHT=20; //�ӵ��ĸ߶ȺͿ��
	static CImageList m_Images;		//�ӵ�ͼ���б�
	int index;				//����
	CPoint m_EnemyPos;
	int v;
	int h_h;
	int v_h;
	POSITION ToEnemy;
};
