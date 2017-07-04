// PlaneGameView.h : CPlaneGameView 类的接口
//
#include "SimpleFactory.h"

#pragma once
class CMyPlane;
class CPlaneGameView : public CView
{

	enum ObjType{enEnemy,enBomb,enBall,enStrengthen,enBoss,enGold,enBomb2,enDazhao,enExplosion,enMap,enProgress,enPlane}; //enum枚举类型
	
protected: // 仅从序列化创建
	CPlaneGameView();					//构造函数
	DECLARE_DYNCREATE(CPlaneGameView)

// 属性
public:
	CPlaneGameDoc* GetDocument() const;

// 操作
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
			pMemDC->SetBkMode(TRANSPARENT);//TRANSPARENT是使用透明的输出
			pMemDC->SetTextAlign(TA_LEFT);//TA_CENTER基准点与限定矩形的中心水平对齐。
			pMemDC->SetTextColor(RGB(255,0,0));
			pMemDC->TextOut(x,y,str_score);
		
		}


// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	//打印
	//virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	//virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CPlaneGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//内存DC
	CDC*        m_pMemDC;
	//设备DC
	CClientDC*  m_pDC;
	//内存位图
	CBitmap*    m_pMemBitmap;

	AbstractFactory* factory ;
protected:
	//初始化游戏
	BOOL InitGame();
	//结束游戏
	void StopGame();

	//刷新游戏的帧画面
	void UpdateFrame(CDC* pMemDC);

	
	void AI();

	//获得键的状态1->down
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}
	
	CMyPlane*  m_pMe;		//自己的飞机
	CMaps* maps;			//两个星球图片
	CProgress* progress;	//进度条
	
	CButton *btn ;	//按钮

	CObList    m_ObjList[9];	//导弹、爆炸、敌机、子弹、道具
	
	CStrengthen* shengming;
	CStrengthen* dazhao;

	bool wudi;

	static int BossBa_time;

	int score;		//得分
	int mission;	//关卡
	int m_time;		//时间
	int pro;		//阶段

// 生成的消息映射函数
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

#ifndef _DEBUG  // PlaneGameView.cpp 中的调试版本
inline CPlaneGameDoc* CPlaneGameView::GetDocument() const
   { return reinterpret_cast<CPlaneGameDoc*>(m_pDocument); }
#endif

