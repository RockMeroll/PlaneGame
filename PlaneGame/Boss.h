#pragma once
#include "gameobject.h"

class CBoss :public CGameObject //�л���
{
public:
	CBoss(void);
	~CBoss(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();
	static BOOL LoadImage2();
	static BOOL LoadImage3();
	static BOOL LoadImage4();
	//��BOSS
	int getBossBlood()
	{
		return BOSS_BLOOD;
	}
	int getBlood()
	{
		return m_blood;
	}
	void setBlood(int x)
	{
		m_blood=x;
	}

	void setIndex(int x)
	{
		m_nImgIndex=x;
	}
	//СBOSS
	int getBossBlood2()
	{
		return BOSS_BLOOD2;
	}
	int getBlood2()
	{
		return m_blood2;
	}
	void setBlood2(int x)
	{
		m_blood2=x;
	}

	void setIndex2(int x)
	{
		m_nImgIndex2=x;
	}
	CPoint GetPoint2()
	{
		return m_ptPos2;
	}



	bool getZhenboss()
	{
		return zhenboss;
	}
	void setZhenboss(bool x)
	{
		zhenboss=x;
	}

	bool getMove()
	{
		return move;
	}

	CRect GetRect()
	{
		if(zhenboss)
			return CRect(m_ptPos,CPoint(m_ptPos.x+ENEMY_WIDTH,m_ptPos.y+ENEMY_HEIGHT));
		else
			return CRect(m_ptPos2,CPoint(m_ptPos2.x+80,m_ptPos2.y+80));
	}

	void setTimeY(int t)
	{
		timeY=t;
	}
	void setTimeX(int t)
	{
		timeX=t;
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
	//�Ƿ���Կ������ӵ�
	BOOL Fired();
private:
	static const int BOSS_BLOOD = 500;
	static const int BOSS_BLOOD2 = 50;
	static const int ENEMY_HEIGHT = 75;
	static const int ENEMY_WIDTH = 100;
	static CImageList m_Images;
	static CImageList m_Images2;
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����
	int    m_nMotion2;
	//ͼ������
	int m_nImgIndex;
	int m_nImgIndex2;
	//�ٶ�
	int m_V;
	int    m_nWait;//������ʱ
	bool move;
	int timeY;
	int timeX;
	static CImageList m_Images_blood; 
	static CImageList m_Images_blood2; 
	int    m_blood;				//Ѫ��
	int    m_blood2;				//Ѫ��

	bool zhenboss;
	 CPoint m_ptPos2;

	 int fangxiangX;
	 int fangxiangY;
};
