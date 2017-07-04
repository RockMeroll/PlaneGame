#include "StdAfx.h"
#include "Explosion.h"
#include "resource.h"

CImageList CExplosion::m_Images;

CExplosion::CExplosion(int x,int y):CGameObject(x,y),m_nProcess(0)	//���幹�캯��������λ	��Ϊx,y��ͼ�������Ĳ�������Ϊm_nProcess=0
{
}
CExplosion::CExplosion()
{
}

void CExplosion::SetInfo(int x,int y)
{
		m_ptPos.x=x;
		m_ptPos.y=y;
		m_nProcess=0;   
}

CExplosion::~CExplosion(void)
{
}
BOOL CExplosion::Draw(CDC* pDC,BOOL bPause)	//����Draw()����
{
	//ֻ��8��ͼƬ
	if(m_nProcess>=7)
	{
		m_nProcess=0;
		return FALSE;
	}

	//����λ�û���ͼ��
	m_Images.Draw(pDC,m_nProcess,m_ptPos,ILD_TRANSPARENT); //pDC:�ڴ�DC	m_nProcess:ͼƬ����		m_ptPos:ͼƬλ��	ILD_TRASNPARENT :ʹ���������ͼ��,�����Ǳ���ɫ
	m_nProcess++;
	return TRUE;
}




BOOL CExplosion::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_EXPLOSION,RGB(0,0,0),66,66,8); //IDB_EXPLOSION:ΪͼƬID
}


//LoadImage():����ͼƬ��m_Images
//m_Images.Draw():����ͼƬ���ڴ�DC