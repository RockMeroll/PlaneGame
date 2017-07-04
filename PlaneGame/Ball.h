#pragma once
#include "GameObject.h"

class CBall :public CGameObject	//�ӵ���
{
public:
	CBall(int x,int y,int nMontion); //����(�̳��Ը���)������
	~CBall(void);
	
	
	CBall();

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();


	int flag;

	void SetInfo(int h, int v,int x,int y,int n);			//



	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+BALL_HEIGHT,m_ptPos.y+BALL_HEIGHT));
	}
private:
	static const int BALL_HEIGHT=8; //�ӵ��ĸ߶ȺͿ��
	static CImageList m_Images;		//�ӵ�ͼ���б�
	int    m_nMotion;				//����
	int X;
	int Y;
};
