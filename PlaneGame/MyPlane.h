#pragma once
#include "GameObject.h"

class CMyPlane :public CGameObject
{
public:
	CMyPlane(void);
	~CMyPlane(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();
	static BOOL LoadImage2();

	//�ɻ�ˮƽ���з���m_nHorMotion��seter��geter
	void SetHorMotion(int nMotion)
	{
		m_nHorMotion = nMotion;
	}
	int GetHorMotion() const
	{
		return m_nHorMotion;
	}

	//�ɻ���ֱ���з���m_nVerMotion��seter��geter
	void SetVerMotion(int nMotion)
	{
		m_nVerMotion = nMotion;
	}
	int GetVerMotion() const
	{
		return m_nVerMotion;
	}

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+PLANE_WIDTH,m_ptPos.y+PLANE_HEIGHT));//���طɻ��ľ�������
	}

	//�ɻ�Ѫ��m_blood��seter��geter
	int getBlood()
	{
		return m_blood;
	}
	void setBlood(int x)
	{
		m_blood=x;
	}
	
	//�ӵ���
	int getBall()
	{
		return m_ball;
	}
	void setBall(int x)
	{
		m_ball=x;
	}

	//������
	int getLife()
	{
		return m_life;
	}
	void setLife(int x)
	{
		m_life=x;
	}

	//��������
	int getFanghu()
	{
		return m_fanghu;
	}
	void setFanghu(int x)
	{
		m_fanghu=x;
	}
	
	//����
	int getDazhao()
	{
		return m_dazhao;
	}
	void setDazhao(int x)
	{
		m_dazhao=x;
	}

	//�Ƿ���Կ����䵼��
	BOOL Fired();

public:
	static const int PLANE_WIDTH=52;	//�ɻ��Ŀ�
	static const int PLANE_HEIGHT=50;	//�ɻ��ĸ�
private:
	
	static CImageList m_Images;		//��ͬ��Сͼ���һ������ ���ɻ�ͼƬ
	int    m_nHorMotion;			//�ɻ�ˮƽ���з���0->��ֹ��1->�� -1->��
	int    m_nVerMotion;			//�ɻ���ֱ���з���0->��ֹ��1->�� -1->��
	int    m_nWait;				//������ʱ


	static CImageList m_Images_blood;		//Ѫ��ͼƬ
	int    m_blood;				//Ѫ��
	int m_ball;		//�ӵ���
	int m_life;		//������
	int m_dazhao;	//������
	int m_fanghu;
	
};
