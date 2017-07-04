#include "StdAfx.h"
#include "MyPlane.h"
#include "resource.h"

CImageList CMyPlane::m_Images;
CImageList CMyPlane::m_Images_blood; //����д��һ�䣬�൱�ڶ�m_Images_blood��ʼ����Ҫ��LoadImage2()�޷�����

CMyPlane::~CMyPlane(void)
{
}
CMyPlane::CMyPlane(void):m_nHorMotion(0),m_nVerMotion(0)	//���캯����ˮƽ�ʹ�ֱ����Ϊ0
{
	m_nWait = 0;		//������ʱ
	m_ptPos.x = GAME_WIDTH/2-20;	//�����λ��x����
	m_ptPos.y = GAME_HEIGHT-50;	//�����λ��y����
	m_blood=10;

	m_ball=1;
	m_life=0;
	m_dazhao=1;
	m_fanghu=1;
}

BOOL CMyPlane::Fired()	//�ɻ����ƶ������в��ܷ���
{
	if(m_nWait==0)		//���ӳ���0ʱ������
		return TRUE;
	else
		return FALSE;

}

BOOL CMyPlane::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP6,RGB(0,0,0),PLANE_WIDTH,PLANE_HEIGHT,4);	//����GameObject.cpp�ж����LoadImage()����
}

BOOL CMyPlane::LoadImage2()
{

	return CGameObject::LoadImage(m_Images_blood,IDB_BITMAP1,RGB(0,0,0),50,3,10);	//����GameObject.cpp�ж����LoadImage()����
}

BOOL CMyPlane::Draw(CDC* pDC,BOOL bPause)	//����Draw()����
{
	m_nWait++;
	if(m_nWait>3)
		m_nWait=0;


	if(!bPause)	//���ûֹͣ
	{
		m_ptPos.x = m_ptPos.x + m_nHorMotion*10;	//������x����+ˮƽ����*6���� m_ptPos.x = m_ptPos.x + 1*6 ����ʾ��������6������
		m_ptPos.y = m_ptPos.y - m_nVerMotion*10;	//������y����+��ֱ����*6���� m_ptPos.y = m_ptPos.y + -1*6 ����ʾ��������6������
	}

	if(m_ptPos.x>=GAME_WIDTH-PLANE_WIDTH)	//�������x���곬���� ��Ļ�Ŀ��-�ɻ��Ŀ�ȣ�����������
		m_ptPos.x =GAME_WIDTH-PLANE_WIDTH;
	if(m_ptPos.x<=0)
		m_ptPos.x=0;

	if(m_ptPos.y<=0)
		m_ptPos.y =0;

	if(m_ptPos.y>=GAME_HEIGHT-PLANE_HEIGHT)
		m_ptPos.y=GAME_HEIGHT-PLANE_HEIGHT;	//����ͬ��

	if(m_ball>8)
		m_ball=8;
	m_Images.Draw(pDC,(m_ball-1)%4,m_ptPos,ILD_TRANSPARENT);//����CImageList��Draw()�������������ϷŲ��������ڱ��϶���ͼ��ILD_TRANSPARENT��ʾʹ�����룬���۱���ɫ��͸���ػ���ͼ��
	m_Images_blood.Draw(pDC,m_blood,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}