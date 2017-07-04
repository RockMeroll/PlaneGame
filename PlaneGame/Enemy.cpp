#include "StdAfx.h"
#include "Enemy.h"
#include "resource.h"

CImageList CEnemy::m_Images;
CImageList CEnemy::m_Images_blood;

CEnemy::CEnemy(void)	//���캯��
{
	m_blood=5;

	//���ȷ��Xλ��
	m_ptPos.x = rand()%(GAME_WIDTH-ENEMY_HEIGHT)+1;

	//���ȷ��ͼ������
	//m_nImgIndex = rand()%2;
	
	m_nImgIndex = 0;
	
	//����ͼ������ȷ������
	m_nMotion=1;
	m_ptPos.y=-ENEMY_HEIGHT;
	
	/*
	if (m_nImgIndex%2!=0)//�����ͼ��������ż������m_nImgIndex������=1�ķɻ�ͼƬ�����Ϸɵ�
	{
		m_nMotion=-1;
		m_ptPos.y = GAME_HEIGHT+ENEMY_HEIGHT;

	}
	*/
	
	
	//���ȷ���ٶ�
	m_V = rand()%6+2;

	m_nWait=0;
	ToBomb2=NULL;
}



CEnemy::~CEnemy(void)
{
}
BOOL CEnemy::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_ENEMY,RGB(0,0,0),35,35,2); //2��ʾͼƬ�����������ͼƬ���������л�ͼƬ
}
BOOL CEnemy::LoadImage2()
{
	return CGameObject::LoadImage(m_Images_blood,IDB_BITMAP2,RGB(0,0,0),35,2,5); //2��ʾͼƬ�����������ͼƬ���������л�ͼƬ
}


BOOL CEnemy::Draw(CDC* pDC,BOOL bPause)
{
	m_nWait++;
	if(m_nWait>20) //�ӳ�20����Ʒɻ�
		m_nWait=0;

	if(!bPause)
	{
		m_ptPos.y = m_ptPos.y + m_nMotion * m_V;	//�ƶ�
	}
	
	if(m_blood<1)
		return FALSE;
	
	//�жϳ�����Ļ��Χ
	if(m_ptPos.y > GAME_HEIGHT+ENEMY_HEIGHT )
		return FALSE;
	if(m_ptPos.y < -ENEMY_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC,m_nImgIndex,m_ptPos,ILD_TRANSPARENT);
	m_Images_blood.Draw(pDC,m_blood,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}
BOOL CEnemy::Fired() //�л����ƶ������в��ܷ���
{
	if(m_nWait==0)
		return TRUE;
	else
		return FALSE;
}