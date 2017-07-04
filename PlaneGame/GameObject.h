#pragma once

//��Ϸ����ĸ���
class CGameObject : public CObject
{
public:

	CGameObject(int x=0,int y=0);	//���캯�� Ĭ��ֵx,y,=0
	virtual ~CGameObject();
	
	//���ƶ���
	virtual BOOL Draw(CDC* pDC,BOOL bPause)=0;//�麯��

	//��þ�������
	virtual CRect GetRect()=0;//�麯��

	//������Ͻ�����
	CPoint GetPoint()
	{
		return m_ptPos;
	}


protected:
	//����ͼ������
	static BOOL LoadImage(CImageList& imgList,UINT bmpID,COLORREF crMask,int cx,int cy,int nInitial);
protected:
	//�����λ��
	CPoint  m_ptPos;
};


