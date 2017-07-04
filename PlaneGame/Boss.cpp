#include "StdAfx.h"
#include "Boss.h"
#include "resource.h"

CImageList CBoss::m_Images;
CImageList CBoss::m_Images_blood;
CImageList CBoss::m_Images2;
CImageList CBoss::m_Images_blood2;

CBoss::CBoss(void)	//���캯��
{
	m_blood=BOSS_BLOOD;
	m_blood2=BOSS_BLOOD2;
	//���ȷ��Xλ��
	m_ptPos.x = rand()%(GAME_WIDTH-ENEMY_HEIGHT)+1;
	m_ptPos2.x = rand()%(GAME_WIDTH-ENEMY_HEIGHT)+1;
	//���ȷ��ͼ������
	//m_nImgIndex = rand()%2;
	
	m_nImgIndex = 0;
	m_nImgIndex2= rand()%2;
	move=true;
	//����ͼ������ȷ������
	m_nMotion=1;
	m_nMotion2=1;
	
	m_ptPos.x=GAME_WIDTH/2-50;
	m_ptPos.y=-ENEMY_HEIGHT;

	m_ptPos2.x=-80;
	m_ptPos2.y=0;

	
	/*
	if (m_nImgIndex%2!=0)//�����ͼ��������ż������m_nImgIndex������=1�ķɻ�ͼƬ�����Ϸɵ�
	{
		m_nMotion=-1;
		m_ptPos.y = GAME_HEIGHT+ENEMY_HEIGHT;

	}
	*/
	
	
	//���ȷ���ٶ�
	m_V = rand()%3+2;
	fangxiangX=1;
	fangxiangY=1;
	m_nWait=0;
}



CBoss::~CBoss(void)
{
}
BOOL CBoss::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP9,RGB(0,0,0),100,75,2); //2��ʾͼƬ�����������ͼƬ���������л�ͼƬ
}
BOOL CBoss::LoadImage2()
{
	return CGameObject::LoadImage(m_Images_blood,IDB_BITMAP10,RGB(0,0,0),100,3,10); //2��ʾͼƬ�����������ͼƬ���������л�ͼƬ
}

BOOL CBoss::LoadImage3()
{
	return CGameObject::LoadImage(m_Images2,IDB_BITMAP19,RGB(255,255,255),80,80,2); //2��ʾͼƬ�����������ͼƬ���������л�ͼƬ

}
BOOL CBoss::LoadImage4()
{
	return CGameObject::LoadImage(m_Images_blood2,IDB_BITMAP20,RGB(0,0,0),80,3,10); //2��ʾͼƬ�����������ͼƬ���������л�ͼƬ

}



BOOL CBoss::Draw(CDC* pDC,BOOL bPause)
{
	m_nWait++;
	if(m_nWait>20) //�ӳ�20����Ʒɻ�
		m_nWait=0;

	if(!bPause)
	{
		
		m_ptPos.y = m_ptPos.y +  m_V;	//BOSS�ƶ�
		if(m_ptPos.y>ENEMY_HEIGHT+10)
		{
			m_ptPos.y=ENEMY_HEIGHT+10;
			if((timeX-timeY)>200&&(timeX-timeY)<400)
			{
				move=false;	
			}else if(timeX-timeY>400)
			{
				timeY=timeX;
			}else
			{
				//BOSS�ƶ�
				m_ptPos.x=m_ptPos.x+m_nMotion*m_V;
				if(m_ptPos.x>GAME_WIDTH-ENEMY_WIDTH||m_ptPos.x<0)
					m_nMotion=-m_nMotion;
				


				//СBOSS�ƶ�
				m_ptPos2.y = m_ptPos2.y +  fangxiangY*2;	
				m_ptPos2.x = m_ptPos2.x +  fangxiangX*2;	
				if(m_ptPos2.y>GAME_HEIGHT/3||m_ptPos2.y<0)
				{
					fangxiangY=-fangxiangY;
				}
				if(m_ptPos2.x>GAME_WIDTH-80||m_ptPos2.x<-80)
				{
					fangxiangX=-fangxiangX;
				}

				move=true;	

			}
		}
	
		

		

	}

	//�жϳ�����Ļ��Χ
	if(m_ptPos.y > GAME_HEIGHT+ENEMY_HEIGHT )
		return FALSE;
	if(m_ptPos.y < -ENEMY_HEIGHT)
		return FALSE;
	
	if(m_ptPos2.y > GAME_HEIGHT+ENEMY_HEIGHT )
		return FALSE;
	if(m_ptPos2.y < -ENEMY_HEIGHT)
		return FALSE;

	if(zhenboss&&m_nImgIndex<6)
	{
		m_Images.Draw(pDC,m_nImgIndex,m_ptPos,ILD_TRANSPARENT);
		m_Images_blood.Draw(pDC,m_blood/(BOSS_BLOOD/10),m_ptPos,ILD_TRANSPARENT);
	}
	if(!zhenboss&&m_nImgIndex<2)
	{
		
		m_Images2.Draw(pDC,m_nImgIndex2,m_ptPos2,ILD_TRANSPARENT);
		m_Images_blood2.Draw(pDC,m_blood2/(BOSS_BLOOD2/10),m_ptPos2,ILD_TRANSPARENT);
	}
	return TRUE;
}
BOOL CBoss::Fired() //�л����ƶ������в��ܷ���
{
	if(m_nWait==0)
	{
			
		return TRUE;
	}
	else
		return FALSE;
}