#pragma once
#include "GameObject.h"

class CMaps :public CGameObject	//�ӵ���
{
public:
	CMaps(int x,int y,int nMontion); //����(�̳��Ը���)������
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

	static CImageList m_Images;		//����ͼ���б�
	static CImageList m_Images2;		//����ͼ���б�
	int    m_nMotion;				//����
	CPoint  m_ptPos2;
	int index;
};
