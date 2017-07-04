#pragma once
#include "gameobject.h"

class CEnemy :public CGameObject //�л���
{
public:
	CEnemy(void);
	~CEnemy(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();
	static BOOL LoadImage2();

	int getBlood()
	{
		return m_blood;
	}
	void setBlood(int x)
	{
		m_blood=x;
	}

	void setToBomb2(POSITION t)
	{
		ToBomb2=t;
	}
	POSITION getToBomb2()
	{
		return ToBomb2;
	}


	void setPoint(int x, int y)
	{
		m_ptPos.x=x;
		m_ptPos.y=y;
	}
	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+ENEMY_HEIGHT,m_ptPos.y+ENEMY_HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
	//�Ƿ���Կ������ӵ�
	BOOL Fired();
private:
	static const int ENEMY_HEIGHT = 35;
	static CImageList m_Images;
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����
	//ͼ������
	int m_nImgIndex;
	//�ٶ�
	int m_V;
	int    m_nWait;//������ʱ


	static CImageList m_Images_blood; 
	int    m_blood;				//Ѫ��

	POSITION ToBomb2;

};
