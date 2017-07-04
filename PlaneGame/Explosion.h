#pragma once
#include "gameobject.h"

class CExplosion :public CGameObject	//�̳�CGameObject�࣬���Ը��ຯ��������д
{
public:
	CExplosion();
	CExplosion(int x,int y);	//���캯��
	~CExplosion(void);

	BOOL Draw(CDC* pDC,BOOL bPause);	//����

	static BOOL LoadImage();	//����

	void SetInfo(int x,int y);

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+EXPLOSION_WIDTH,m_ptPos.y+EXPLOSION_WIDTH));
	}
private:
	//ը����ͼƬ�б�
	static CImageList m_Images;
	//ͼ������
	int   m_nProcess;
public:
	static const int  EXPLOSION_WIDTH = 66;

};
