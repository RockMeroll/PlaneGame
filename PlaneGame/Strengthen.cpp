#include "StdAfx.h"
#include "Strengthen.h"
#include "resource.h"

CImageList CStrengthen::m_Images;

CStrengthen::CStrengthen(void)	//���캯��
{

	//���ȷ��Xλ��
	m_ptPos.x = rand()%(GAME_WIDTH-ENEMY_HEIGHT)+1;

	//���ȷ��ͼ������
	//m_nImgIndex = rand()%2;
	
	m_nImgIndex = 0;
	
	//����ͼ������ȷ������
	m_nMotion=1;
	m_ptPos.y=-ENEMY_HEIGHT;
	jiemian=false;
	
	//���ȷ���ٶ�
	m_V = rand()%6+2;

}



CStrengthen::~CStrengthen(void)
{
}
BOOL CStrengthen::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP14,RGB(0,0,0),30,30,3); //2��ʾͼƬ�����������ͼƬ���������л�ͼƬ
}

BOOL CStrengthen::Draw(CDC* pDC,BOOL bPause)
{
	if(!jiemian)
	{
		if(!bPause)
		{
			m_ptPos.y = m_ptPos.y + m_nMotion * m_V;	//�ƶ�
		}
	}
	

	//�жϳ�����Ļ��Χ
	if(m_ptPos.y > GAME_HEIGHT+ENEMY_HEIGHT )
		return FALSE;
	if(m_ptPos.y < -ENEMY_HEIGHT)
		return FALSE;

	if(m_nImgIndex<4&&m_nImgIndex>=0)
		m_Images.Draw(pDC,m_nImgIndex,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}
BOOL CStrengthen::Fired() //�л����ƶ������в��ܷ���
{
		return TRUE;
}