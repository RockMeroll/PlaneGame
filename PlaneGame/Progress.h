#pragma once
#include "GameObject.h"

class CProgress :public CGameObject	//�ӵ���
{
public:
	CProgress(int x,int y,int nMontion); //����(�̳��Ը���)������
	~CProgress(void);
	
	
	CProgress();

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();


	void SetInfo(int h, int v,int n);			//
	
	void SetTime(int m);


	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x,m_ptPos.y));
	}
private:
	static CImageList m_Images;		//������ͼ���б�
	int    pro;				//ʱ�䣬���ڼ������
};
