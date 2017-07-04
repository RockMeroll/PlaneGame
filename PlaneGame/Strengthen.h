#pragma once
#include "gameobject.h"

class CStrengthen :public CGameObject //�л���
{
public:
	CStrengthen(void);
	~CStrengthen(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+ENEMY_HEIGHT,m_ptPos.y+ENEMY_HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}

	bool getJiemian()
	{
		return jiemian;
	}
	int getIndex()
	{
		return m_nImgIndex;
	}
	void setIndex(int x)
	{
		m_nImgIndex=x;
	}
	void setPoint(int x,int y,bool j)
	{
		m_ptPos.x=x;
		m_ptPos.y=y;
		jiemian=j;
	}

	//�Ƿ���Կ������ӵ�
	BOOL Fired();
private:
	static const int ENEMY_HEIGHT = 30;
	static CImageList m_Images;
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����
	//ͼ������
	int m_nImgIndex;
	//�ٶ�
	int m_V;
	bool jiemian;
};
