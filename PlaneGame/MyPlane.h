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

	//飞机水平运行方向m_nHorMotion的seter和geter
	void SetHorMotion(int nMotion)
	{
		m_nHorMotion = nMotion;
	}
	int GetHorMotion() const
	{
		return m_nHorMotion;
	}

	//飞机垂直运行方向m_nVerMotion的seter和geter
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
		return CRect(m_ptPos,CPoint(m_ptPos.x+PLANE_WIDTH,m_ptPos.y+PLANE_HEIGHT));//返回飞机的矩形区域
	}

	//飞机血量m_blood的seter和geter
	int getBlood()
	{
		return m_blood;
	}
	void setBlood(int x)
	{
		m_blood=x;
	}
	
	//子弹数
	int getBall()
	{
		return m_ball;
	}
	void setBall(int x)
	{
		m_ball=x;
	}

	//生命数
	int getLife()
	{
		return m_life;
	}
	void setLife(int x)
	{
		m_life=x;
	}

	//防护罩数
	int getFanghu()
	{
		return m_fanghu;
	}
	void setFanghu(int x)
	{
		m_fanghu=x;
	}
	
	//大招
	int getDazhao()
	{
		return m_dazhao;
	}
	void setDazhao(int x)
	{
		m_dazhao=x;
	}

	//是否可以开火发射导弹
	BOOL Fired();

public:
	static const int PLANE_WIDTH=52;	//飞机的宽
	static const int PLANE_HEIGHT=50;	//飞机的高
private:
	
	static CImageList m_Images;		//相同大小图像的一个集合 即飞机图片
	int    m_nHorMotion;			//飞机水平运行方向0->静止，1->右 -1->左
	int    m_nVerMotion;			//飞机垂直运行方向0->静止，1->上 -1->下
	int    m_nWait;				//发射延时


	static CImageList m_Images_blood;		//血量图片
	int    m_blood;				//血量
	int m_ball;		//子弹数
	int m_life;		//生命数
	int m_dazhao;	//大招数
	int m_fanghu;
	
};
