// PlaneGameView.h : CPlaneGameView ��Ľӿ�
//
#include "SimpleFactory.h"

#pragma once
class CMyPlane;
class CPlaneGameView : public CView
{

	enum ObjType{enEnemy,enBomb,enBall,enStrengthen,enBoss,enGold,enBomb2,enDazhao,enExplosion,enMap,enProgress,enPlane}; //enumö������
	
protected: // �������л�����
	CPlaneGameView();					//���캯��
	DECLARE_DYNCREATE(CPlaneGameView)

// ����
public:
	CPlaneGameDoc* GetDocument() const;

// ����
public:

	void showInfo(CDC* pMemDC,CString xinxi,int x,int y) 
		{
			CString str_score=xinxi;
			pMemDC->SetBkMode(TRANSPARENT);
			pMemDC->SetTextAlign(TA_LEFT);
			pMemDC->SetTextColor(RGB(255,0,0));
			pMemDC->TextOut(x,y,str_score);
		
		}
	void showInfo(CDC* pMemDC,int score ,CString xinxi,int x,int y) 
		{
			CString str_s;
			str_s.Format(_T("%d"),score);
			CString str_score=xinxi+str_s;	
			pMemDC->SetBkMode(TRANSPARENT);//TRANSPARENT��ʹ��͸�������
			pMemDC->SetTextAlign(TA_LEFT);//TA_CENTER��׼�����޶����ε�����ˮƽ���롣
			pMemDC->SetTextColor(RGB(255,0,0));
			pMemDC->TextOut(x,y,str_score);
		
		}


// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	//��ӡ
	//virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	//virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CPlaneGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//�ڴ�DC
	CDC*        m_pMemDC;
	//�豸DC
	CClientDC*  m_pDC;
	//�ڴ�λͼ
	CBitmap*    m_pMemBitmap;

	AbstractFactory* factory ;
protected:
	//��ʼ����Ϸ
	BOOL InitGame();
	//������Ϸ
	void StopGame();

	//ˢ����Ϸ��֡����
	void UpdateFrame(CDC* pMemDC);

	
	void AI();

	//��ü���״̬1->down
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}
	
	CMyPlane*  m_pMe;		//�Լ��ķɻ�
	CMaps* maps;			//��������ͼƬ
	CProgress* progress;	//������
	
	CButton *btn ;	//��ť

	CObList    m_ObjList[9];	//��������ը���л����ӵ�������
	
	CStrengthen* shengming;
	CStrengthen* dazhao;

	bool wudi;

	static int BossBa_time;

	int score;		//�÷�
	int mission;	//�ؿ�
	int m_time;		//ʱ��
	int pro;		//�׶�

// ���ɵ���Ϣӳ�亯��
protected:

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();		

	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void btnclick0(void);
	afx_msg void btnclick1(void);
	afx_msg void btnclick2(void);
	afx_msg void btnclick3(void);
	afx_msg void btnclick4(void);
	afx_msg void btnclick5(void);
};

#ifndef _DEBUG  // PlaneGameView.cpp �еĵ��԰汾
inline CPlaneGameDoc* CPlaneGameView::GetDocument() const
   { return reinterpret_cast<CPlaneGameDoc*>(m_pDocument); }
#endif

