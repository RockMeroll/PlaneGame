// GameObject.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GameObject.h"


// CGameObject


CGameObject::CGameObject(int x,int y):m_ptPos(x,y)//���幹�캯��
{
		
}

CGameObject::~CGameObject()
{
}

BOOL CGameObject::LoadImage(CImageList& imgList,UINT bmpID,COLORREF crMask,int cx,int cy,int nInitial)
{
	CBitmap bmp;
	if(!bmp.LoadBitmap(bmpID))		//����ָ����λͼ��Դ
		return FALSE;
	if(!imgList.Create(cx, cy, ILC_COLOR24|ILC_MASK, nInitial, 0))	//cx ,cyͼƬ��ʵ�����ؿ����;����������������ͼ���б�����ͣ����ĸ�������ImageList��ʼ������ͼ���������������ռ䲻��ʱ����
		return FALSE;
	imgList.Add(&bmp, crMask); //�򴫹�����imgList����Ӹ���bmpID�ҵ�����ͼ��crMask:������������,����ɫÿ���ص�λͼ�ض����Ѹ���Ϊ��ɫ�����������ж�Ӧ��λ����Ϊһ����
	return TRUE;
}

