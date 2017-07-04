// PlaneGameView.cpp : CPlaneGameView 类的实现
//

#include "stdafx.h"
#include "PlaneGame.h"

#include "PlaneGameDoc.h"
#include "PlaneGameView.h"
#include "MyPlane.h"
#include "Enemy.h"
#include "Bomb.h"
#include "map.h"
#include "Ball.h"
#include "Gold.h"
#include "Boss.h"
#include "Progress.h"
#include "Strengthen.h"
#include "Explosion.h"
#include <atlimage.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlaneGameView

IMPLEMENT_DYNCREATE(CPlaneGameView, CView)

BEGIN_MESSAGE_MAP(CPlaneGameView, CView)

	ON_BN_CLICKED(buttonID+0,&CPlaneGameView::btnclick0)
	ON_BN_CLICKED(buttonID+1,&CPlaneGameView::btnclick1)
	ON_BN_CLICKED(buttonID+2,&CPlaneGameView::btnclick2)
	ON_BN_CLICKED(buttonID+3,&CPlaneGameView::btnclick3)
	ON_BN_CLICKED(buttonID+4,&CPlaneGameView::btnclick4)
	ON_BN_CLICKED(buttonID+5,&CPlaneGameView::btnclick5)
	ON_WM_TIMER()
END_MESSAGE_MAP()

afx_msg void CPlaneGameView::btnclick0(void)//开始游戏
{
	//MessageBox(_T("btn click0"));
	for(int i=0;i<9;i++)
	{
		m_ObjList[i].RemoveAll();
	}
	if(m_pMe==NULL)
		m_pMe = (CMyPlane *)factory->createProduct(enPlane);
	//初始化
	m_pMe->setBall(1);
	m_pMe->setDazhao(1);
	m_pMe->setFanghu(1);
	m_pMe->setLife(0);
	wudi=false;
	SetTimer(1,20,NULL);
	
	m_time=0;
	score=0;
	mission=1;
	maps->SetInfo(0,0,0,-800,mission-1);

	btn[0].ShowWindow(SW_HIDE);	
	btn[1].ShowWindow(SW_HIDE);	
	btn[2].ShowWindow(SW_HIDE);	
	btn[3].ShowWindow(SW_HIDE);	
	btn[4].ShowWindow(SW_HIDE);	
	btn[5].ShowWindow(SW_HIDE);	
	
    return afx_msg void();
}


afx_msg void CPlaneGameView::btnclick1(void)//无敌模式
{
	for(int i=0;i<9;i++)
	{
		m_ObjList[i].RemoveAll();
	}
	if(m_pMe==NULL)
		m_pMe = (CMyPlane *)factory->createProduct(enPlane);
	m_pMe->setBall(1);
	m_pMe->setDazhao(999);
	m_pMe->setFanghu(999);
	m_pMe->setBlood(10);
	m_pMe->setLife(0);
	wudi=true;
	SetTimer(1,20,NULL);
	
	m_time=0;
	score=0;
	mission=1;
	maps->SetInfo(0,0,0,-800,mission-1);
	btn[0].ShowWindow(SW_HIDE);	
	btn[1].ShowWindow(SW_HIDE);	
	btn[2].ShowWindow(SW_HIDE);	
	btn[3].ShowWindow(SW_HIDE);	
	btn[4].ShowWindow(SW_HIDE);	
	btn[5].ShowWindow(SW_HIDE);	
    return afx_msg void();
}
afx_msg void CPlaneGameView::btnclick2(void)//重新开始
{
	for(int i=0;i<9;i++)
	{
		m_ObjList[i].RemoveAll();
	}
	if(m_pMe==NULL)
		m_pMe = (CMyPlane *)factory->createProduct(enPlane);
	m_pMe->setBall(1);
	m_pMe->setDazhao(1);
	m_pMe->setFanghu(1);
	m_pMe->setLife(0);
	m_time=0;
	score=0;
	mission=1;

	progress->SetInfo(45,68,pro);
	maps->SetInfo(0,0,0,-800,mission-1);

	SetTimer(1,20,NULL);

	btn[0].ShowWindow(SW_HIDE);	
	btn[1].ShowWindow(SW_HIDE);	
	btn[2].ShowWindow(SW_HIDE);	
	btn[3].ShowWindow(SW_HIDE);	
	btn[4].ShowWindow(SW_HIDE);	
	btn[5].ShowWindow(SW_HIDE);	
    return afx_msg void();
}

afx_msg void CPlaneGameView::btnclick3(void)//回到主菜单
{
	
	//m_pMe = (CMyPlane *)factory->createProduct(enPlane);
	btn[2].ShowWindow(SW_HIDE);	
	btn[3].ShowWindow(SW_HIDE);	
	btn[4].ShowWindow(SW_HIDE);	
	btn[5].ShowWindow(SW_HIDE);	

	btn[0].ShowWindow(SW_SHOW);	
	btn[1].ShowWindow(SW_SHOW);	
    return afx_msg void();
}
afx_msg void CPlaneGameView::btnclick4(void)//继续
{
	btn[0].ShowWindow(SW_HIDE);	
	btn[1].ShowWindow(SW_HIDE);	
	btn[2].ShowWindow(SW_HIDE);	
	btn[3].ShowWindow(SW_HIDE);	
	btn[4].ShowWindow(SW_HIDE);	
	btn[5].ShowWindow(SW_HIDE);	
	
	SetTimer(1,20,NULL);
     return afx_msg void();
}
afx_msg void CPlaneGameView::btnclick5(void)//下一关
{
	
	mission++;
	maps->SetInfo(0,0,0,-800,mission-1);
	m_time=0;
	m_pMe->setBall(1);
	m_pMe->setBlood(10);
	for(int i=0;i<9;i++)
	{
		if(i!=enStrengthen)
			m_ObjList[i].RemoveAll();
	}
	SetTimer(1,20,NULL);

	btn[0].ShowWindow(SW_HIDE);	
	btn[1].ShowWindow(SW_HIDE);	
	btn[2].ShowWindow(SW_HIDE);	
	btn[3].ShowWindow(SW_HIDE);	
	btn[4].ShowWindow(SW_HIDE);	
	btn[5].ShowWindow(SW_HIDE);	

    return afx_msg void();
}


// CPlaneGameView 构造/析构

CPlaneGameView::CPlaneGameView():m_pMe(NULL)
{
	// TODO: 在此处添加构造代码
	
}

CPlaneGameView::~CPlaneGameView()
{
}

BOOL CPlaneGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPlaneGameView 绘制

void CPlaneGameView::OnDraw(CDC* /*pDC*/)
{
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
}



// CPlaneGameView 诊断

#ifdef _DEBUG
void CPlaneGameView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneGameDoc* CPlaneGameView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneGameDoc)));
	return (CPlaneGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneGameView 消息处理程序
void CPlaneGameView::OnInitialUpdate()									// 1
{
	CView::OnInitialUpdate();
	// TODO: 在此添加专用代码和/或调用基类
		
		m_time = 0;//时间

		btn = new CButton[6];  //1开始游戏，2无敌模式，3重新开始
		DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;  
		DWORD dwStyle2 = WS_CHILD | BS_PUSHBUTTON; 
			btn[0].Create(_T("开始游戏"), dwStyle,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100,GAME_WIDTH/2+50,GAME_HEIGHT/2-75),this,buttonID+0);   
			//btn[0].SetFont(GetParent()->GetFont());  
			btn[1].Create(_T("无敌模式"), dwStyle,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100+35,GAME_WIDTH/2+50,GAME_HEIGHT/2-75+35),this,buttonID+1);   
			btn[1].SetFont(GetParent()->GetFont());  
			btn[2].Create(_T("重新开始"), dwStyle2,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100,GAME_WIDTH/2+50,GAME_HEIGHT/2-75),this,buttonID+2);   
			btn[2].SetFont(GetParent()->GetFont());
			btn[3].Create(_T("返回主菜单"), dwStyle2,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100+35,GAME_WIDTH/2+50,GAME_HEIGHT/2-75+35),this,buttonID+3);   
			btn[3].SetFont(GetParent()->GetFont()); 
			btn[4].Create(_T("继续"), dwStyle2,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100,GAME_WIDTH/2+50,GAME_HEIGHT/2-75),this,buttonID+4);   
			btn[4].SetFont(GetParent()->GetFont());
			btn[5].Create(_T("进入下一关"), dwStyle2,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100,GAME_WIDTH/2+50,GAME_HEIGHT/2-75),this,buttonID+5);   
			btn[5].SetFont(GetParent()->GetFont());

		//初始化游戏
		InitGame();														
}
void CPlaneGameView::StopGame()
{
	delete m_pMe;		//飞机类   CMyPlane*
	delete m_pMemDC;	//内存DC   CDC*  
	delete m_pDC;		//设备DC   CClientDC*
	delete m_pMemBitmap;//内存位图 CBitmap*  
}

BOOL CPlaneGameView::InitGame()											// 2
{
	
	factory = new SimpleFactory();		//工厂

	//CRect rc;
	//GetClientRect(rc);		//得到客户区Rect
		

	//产生随机数种子
	srand( (unsigned)time( NULL ) );


	//建立设备DC
	m_pDC = new CClientDC(this);	//CClientDC


	//建立内存DC
	m_pMemDC = new CDC;				//CDC
	m_pMemDC->CreateCompatibleDC(m_pDC);								//创建一个与指定设备DC(CClientDC)兼容的内存DC(CDC)

	//建立内存位图
	m_pMemBitmap = new CBitmap;		//CBitmap
	m_pMemBitmap->CreateCompatibleBitmap(m_pDC,GAME_WIDTH,GAME_HEIGHT); //创建一幅与设备DC(CClientDC)有关的位图(CBitmap)，它与指定的设备场景兼容
							//位图(CBitmap)选入内存DC(CDC)

	//将位图选入内存DC
	m_pMemDC->SelectObject(m_pMemBitmap);	

	CMyPlane::LoadImage();	//以下几个类的LoadImage()都对父类进行了重载，执行中都调用了父类的LoadImage()，只是调用的参数不同
	CMyPlane::LoadImage2();	//血条
	CMaps::LoadImage();
	CMaps::LoadImage2();
	CProgress::LoadImage();
	CEnemy::LoadImage();	//因为每个类中static CImageList m_Images;静态变量，所以m_Images只需要一次确定，其他类都能用
	CEnemy::LoadImage2();
	CBoss::LoadImage();	//因为每个类中static CImageList m_Images;静态变量，所以m_Images只需要一次确定，其他类都能用
	CBoss::LoadImage2();
	CBoss::LoadImage3();
	CBoss::LoadImage4();
	CBomb2::LoadImage();
	CBomb::LoadImage();
	CBall::LoadImage();
	CExplosion::LoadImage();
	CStrengthen::LoadImage();
	CGold::LoadImage();
	CDazhao::LoadImage();
	
	wudi=false;

	//产生主角(战机)
	m_pMe = (CMyPlane *)factory->createProduct(enPlane);	//飞机
	
	mission=1;
	maps = (CMaps *)factory->createProduct(enMap);		//背景图
	maps->SetInfo(0,0,0,-800,mission-1);
	
	progress = (CProgress *)factory->createProduct(enProgress);	//进度条
	progress->SetInfo(45,68,pro);
	
	shengming=(CStrengthen *)factory->createProduct(enStrengthen);	//生命图标
	shengming->setIndex(3);

	dazhao=(CStrengthen *)factory->createProduct(enStrengthen);	//大招图标
	dazhao->setIndex(2);

	return TRUE;
}

void CPlaneGameView::UpdateFrame(CDC* pMemDC)	//传来的参数pMemDC是内存DC							//4     4和5不断的循环
{
	//进度条用
	if(m_time/100<5)
	{
		pro=0;
	}else if(m_time/100>=5&&m_time/100<10)
	{
		pro=1;
	}else if(m_time/100>=10&&m_time/100<15)
	{
		pro=2;
	}else if(m_time/100>=15&&m_time/100<20)
	{
		pro=3;
	}else if(m_time/100>=20&&m_time/100<25)
	{
		pro=4;
	}else if(m_time/100>=25&&m_time/100<30)
	{
		pro=5;
	}else if(m_time/100>=30&&m_time/100<35)
	{
		pro=6;
	}else if(m_time/100>=35&&m_time/100<40)
	{
		pro=7;
	}else if(m_time/100>=40&&m_time/100<45)
	{
		pro=8;
	}else if(m_time/100>=45)
	{
		pro=9;
	}else{
		pro=0;
	}
	
	
	if(maps!=NULL)		
	{
		maps->Draw(m_pMemDC,FALSE);			//画背景图
	}

	if(progress!=NULL)		
	{
		progress->SetTime(pro);
		progress->Draw(m_pMemDC,FALSE);		//画进度条
	}
	

	//绘制我方战机
	if(m_pMe!=NULL)		//如果战机还没被delete
	{
	   m_pMe->Draw(m_pMemDC,FALSE); //false 表示没有停止运动
		
		showInfo(m_pMemDC,score,_T("得分："),0,0);
		showInfo(m_pMemDC,mission,_T("关卡："),0,20);
		showInfo(m_pMemDC,m_pMe->getBlood()*10,_T("血量："),0,40);
		showInfo(m_pMemDC,_T("进度："),0,60);
		showInfo(m_pMemDC,_T("按Esc暂停/继续"),0,80);
		showInfo(m_pMemDC,_T("大招:"),0,100);
		showInfo(m_pMemDC,_T("  Z 空间弹"),0,120);
		showInfo(m_pMemDC,_T("  X 激光炮"),0,140);
		showInfo(m_pMemDC,_T("  C 跟踪弹"),0,160);
		showInfo(m_pMemDC,_T("  V 防护盾"),0,180);
		showInfo(m_pMemDC,_T("空格  秒杀"),0,200);
		//showInfo(m_pMemDC,m_time,_T("时间："),0,GAME_HEIGHT-100);
		
		shengming->setPoint(0,GAME_HEIGHT-85,false);
		shengming->Draw(m_pMemDC,FALSE);	//画生命图标
		showInfo(m_pMemDC,m_pMe->getFanghu(),_T(""),35,GAME_HEIGHT-75);

		dazhao->setPoint(0,GAME_HEIGHT-55,false);
		dazhao->Draw(m_pMemDC,FALSE);	//画生命图标
		showInfo(m_pMemDC,m_pMe->getDazhao(),_T(""),35,GAME_HEIGHT-45);
		
	}
	else
	{   
		//Game Over
		showInfo(m_pMemDC,_T("game over!"),GAME_WIDTH/2-40,GAME_HEIGHT/2);
		KillTimer(1);
		btn[2].ShowWindow(SW_SHOW);
		btn[3].ShowWindow(SW_SHOW);
	}
	
	//绘制 导弹、爆炸、敌机、子弹
	for(int i=0;i<9;i++)
	{
		POSITION pos1,pos2;			//POSITION用来存放各种List或Array对象的索引，便于在遍历时标识元素的位置。
		for( pos1 = m_ObjList[i].GetHeadPosition(); ( pos2 = pos1 ) != NULL; )	//GetHeadPosition()得到头索引。
		{
			CGameObject* pObj = (CGameObject*)m_ObjList[i].GetNext( pos1 );//GetNext(pos1)将pos1的值设置为下一位置，返回值为当前节点的地址，即当前物体的对象地址
			if(!pObj->Draw(pMemDC,FALSE))	//如果绘制失败，因为坐标超出屏幕范围
			{
				m_ObjList[i].RemoveAt(pos2);//pos2为当前物体的位置，RemoveAt(pos2)即删除pos2所指的
					//pObj=NULL;
					delete pObj;
			}	
		}
	}

	//复制内存DC到设备DC
	m_pDC->BitBlt(0,0,GAME_WIDTH,GAME_HEIGHT,m_pMemDC,0,0,SRCCOPY);	//BitBlt()用于从原设备中复制位图到目标设备,SRCCOPY:直接复制源设备区域到目标设备中
}
void CPlaneGameView::AI()																			//5
{

	static int nCreator = rand() %30+15;

	//随机产生敌机
	if(nCreator<=0)
	{
		nCreator = rand()%30+10;

		CEnemy* enemy = (CEnemy *)factory->createProduct(enEnemy);
		m_ObjList[enEnemy].AddTail(enemy);  //将CEnemy类型的CObject添加到m_ObjList
	}
	nCreator--;
		
	if(m_pMe==NULL)	//如果自己飞机已经爆炸了，就不向下执行了
		return;
	
	//金币轨迹
	POSITION gPos1,gPos2;
	for( gPos1 = m_ObjList[enGold].GetHeadPosition(); ( gPos2 = gPos1 ) != NULL; )	//GetHeadPosition()得到头索引。
		{
			CGold* pObj = (CGold*)m_ObjList[enGold].GetNext( gPos1 );//GetNext(pos1)将pos1的值设置为下一位置，返回值为当前节点的地址，即当前物体的对象地址
			pObj->SetPlane(m_pMe->GetPoint().x,m_pMe->GetPoint().y);
		}
	
	//产生boss
	if((m_time>4500&&m_time<4504))
	{
		CBoss* boss = (CBoss *)factory->createProduct(enBoss);
		boss->setIndex(mission);
		boss->setTimeY(m_time);
		boss->setZhenboss(true);
		m_ObjList[enBoss].AddTail(boss);  //将CEnemy类型的CObject添加到m_ObjList
		
	}
	
	//产生小BOSS
	if(m_pMe==NULL)	
		return;
	if(score>20&&score%20>0&&score%20<3)
	{
		if(!m_ObjList[enBoss].GetCount())
		{
			CBoss* boss = (CBoss *)factory->createProduct(enBoss);
			boss->setZhenboss(false);
			boss->setTimeY(m_time);
			m_ObjList[enBoss].AddTail(boss);  //将CEnemy类型的CObject添加到m_ObjList
		
		}
	}

	if(GetKey(VK_ESCAPE)==1)
	{
		KillTimer(1);
		btn[3].ShowWindow(SW_SHOW);
		btn[4].ShowWindow(SW_SHOW);
	}

	static int yanchi5 = 3;//获取按键延迟
	if(GetKey(0x56)==1)						//V
	{
		if(m_pMe->getFanghu()>0)
		{
			if(yanchi5<0)
			{
				m_pMe->setFanghu(m_pMe->getFanghu()-1);

				CPoint Da_Pt=m_pMe->GetPoint();
				CDazhao* dazhao = (CDazhao *)factory->createProduct(enDazhao);
				dazhao->SetInfo(Da_Pt.x-110,Da_Pt.y-100,3);
				dazhao->setTimeY(m_time);
				m_ObjList[enDazhao].AddTail(dazhao);

			yanchi5=3;
			}
		}
		yanchi5--;
	}

	static int yanchi4 = 3;//获取按键延迟
	if(GetKey(0x43)==1)
	{
		if(m_pMe->getDazhao()>0)
		{
			if(yanchi4<0)
			{
				m_pMe->setDazhao(m_pMe->getDazhao()-1);

				CPoint Da_Pt =m_pMe->GetPoint();
				double x1=Da_Pt.x;
				double y1=Da_Pt.y;

				POSITION enemyPos1,enemyPos2;
				double juli=10000000;
				POSITION minPos=NULL;
				for( enemyPos1 = m_ObjList[enEnemy].GetHeadPosition(); ( enemyPos2 = enemyPos1 ) != NULL; )	//GetHeadPosition()得到头索引。
				{
					CEnemy* pObj = (CEnemy*)m_ObjList[enEnemy].GetNext( enemyPos1 );//GetNext(pos1)将pos1的值设置为下一位置，返回值为当前节点的地址，即当前物体的对象地址
					
					if(pObj->getToBomb2()!=NULL)
						continue;
					
					CPoint enemyPt = pObj->GetPoint();
					double x2=enemyPt.x;
					double y2=enemyPt.y;

					double n= (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
					if(n<juli)
					{
						minPos=enemyPos2;
						juli=n;
					}
				}
				if(minPos!=NULL)
				{
					CEnemy* pObj = (CEnemy*)m_ObjList[enEnemy].GetNext( minPos );
					CPoint pppt = m_pMe->GetPoint();
					CBomb2* bomb2 = (CBomb2 *)factory->createProduct(enBomb2);
					bomb2->SetInfo(pppt.x,pppt.y,pppt.x,0);
					bomb2->setToEnemy(minPos);
					m_ObjList[enBomb2].AddTail(bomb2);  //将CEnemy类型的CObject添加到m_ObjList
					pObj->setToBomb2(minPos);
				}
			yanchi4=3;
			}
		}
		yanchi4--;
	}

	//导弹2轨迹
	POSITION bomb2Pos1,bomb2Pos2;
	for( bomb2Pos1 = m_ObjList[enBomb2].GetHeadPosition(); ( bomb2Pos2 = bomb2Pos1 ) != NULL; )
	{
		CBomb2* bomb = (CBomb2*)m_ObjList[enBomb2].GetNext( bomb2Pos1 );
		bool flag=false;
		POSITION toEnPos1,toEnPos2;
		for( toEnPos1 = m_ObjList[enEnemy].GetHeadPosition(); ( toEnPos2 = toEnPos1 ) != NULL; )
		{
				CEnemy* enemyTo = (CEnemy*)m_ObjList[enEnemy].GetNext( toEnPos1 );
				if(bomb->getToEnemy()==enemyTo->getToBomb2())
				{
					flag=true;
					CPoint enemyPt = enemyTo->GetPoint();
					bomb->SetPlane(enemyPt.x,enemyPt.y);
				}
		}
		if(!flag)
		{
			bomb->SetInfo(0,GAME_HEIGHT+100,0,0);
		}

	}

	static int yanchi3 = 3;//获取按键延迟
	if(GetKey(0x58)==1)					//X 激光
	{
		CPoint Da_Pt =m_pMe->GetPoint();
		if(m_pMe->getDazhao()>0)
		{
			if(yanchi3<0)
			{
				m_pMe->setDazhao(m_pMe->getDazhao()-1);
				int x=Da_Pt.y/250;
				int x_yu=Da_Pt.y%250;
				for(int i=x;i>=-1;i--)
				{
					CDazhao* dazhao = (CDazhao *)factory->createProduct(enDazhao);
					dazhao->SetInfo(Da_Pt.x-110,(i-1)*250+x_yu,2);
					dazhao->setTimeY(m_time);
					m_ObjList[enDazhao].AddTail(dazhao);
				}
			yanchi3=3;
			}
		}
		yanchi3--;
	}

	static int yanchi2 = 3;//获取按键延迟
	if(GetKey(0x5A)==1)
	{
		CPoint Da_Pt =m_pMe->GetPoint();
		if(m_pMe->getDazhao()>0)
		{
			if(yanchi2<0)
			{
				m_pMe->setDazhao(m_pMe->getDazhao()-1);
				
				CDazhao* dazhao = (CDazhao *)factory->createProduct(enDazhao);
				dazhao->SetInfo(Da_Pt.x-110,Da_Pt.y-200,1);
				dazhao->setTimeY(m_time);
				m_ObjList[enDazhao].AddTail(dazhao);

			yanchi2=3;
			}
		}
		yanchi2--;
	}

	//大招轨迹
	if(m_pMe==NULL)	
		return;
	POSITION daPos1,daPos2;
	for( daPos1 = m_ObjList[enDazhao].GetHeadPosition(); ( daPos2 = daPos1 ) != NULL; )
	{
		CDazhao* dazhao = (CDazhao*)m_ObjList[enDazhao].GetNext( daPos1 );
		dazhao->setTimeX(m_time);
	}


	static int yanchi = 3;//获取按键延迟
	if(GetKey(VK_SPACE)==1)
	{
		
		if(m_pMe->getDazhao()>0)
		{
			if(yanchi<0)
			{
				m_pMe->setDazhao(m_pMe->getDazhao()-1);
			
				//消除敌机
				POSITION ePos1=NULL,ePos2=NULL;
				for(ePos1=m_ObjList[enEnemy].GetHeadPosition();(ePos2=ePos1)!=NULL;)
				{
					CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos1);
					CRect mRect = pEnemy->GetRect();//敌机矩形
					CRect tmpRect;
		
					//添加爆炸效果
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

					//删除敌机
					m_ObjList[enEnemy].RemoveAt(ePos2);
					delete pEnemy;
					score++;

				}
	
				//消除子弹
				POSITION pos1=NULL,pos2=NULL;
				for(pos1=m_ObjList[enBall].GetHeadPosition();(pos2=pos1)!=NULL;)
				{
					CBall* pEnemy = (CBall*)m_ObjList[enBall].GetNext(pos1);
					//删除子弹
					m_ObjList[enBall].RemoveAt(pos2);
				}


			yanchi=3;
			}
		}
		yanchi--;
	}

	//检测四个方向键，移动战机
	for(int i=0;i<4;i++)
	{
		int nMeMotion=0;
		m_pMe->SetVerMotion(0);
		m_pMe->SetHorMotion(0);

		nMeMotion = GetKey(VK_UP);
		if(nMeMotion==1)
			m_pMe->SetVerMotion(1);
		    
		nMeMotion = GetKey(VK_DOWN);
		if(nMeMotion==1)
			m_pMe->SetVerMotion(-1);

		nMeMotion = GetKey(VK_RIGHT);
		if(nMeMotion==1)
			m_pMe->SetHorMotion(1);

		nMeMotion = GetKey(VK_LEFT);
		if(nMeMotion==1)
			m_pMe->SetHorMotion(-1);
	}
	
	//战机发射子弹
	if(m_pMe!=NULL && m_pMe->Fired())
	{
		CPoint pt = m_pMe->GetPoint();//返回标示飞机位置的CPoint
		
		if(m_pMe->getBall()==1){
			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+20,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb1);//左炮弹	
		}else if (m_pMe->getBall()==2)
		{	
			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+10,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb1);//左炮弹	
			
			CBomb* bomb2 = (CBomb *)factory->createProduct(enBomb);
			bomb2->SetInfo(pt.x+30,pt.y+10,1);
			m_ObjList[enBomb].AddTail(bomb2);//右炮弹	
		}else if (m_pMe->getBall()==3)
		{	

			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+10,pt.y+10,3);
			m_ObjList[enBomb].AddTail(bomb1);//左炮弹	
			
			CBomb* bomb2 = (CBomb *)factory->createProduct(enBomb);
			bomb2->SetInfo(pt.x+20,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb2);//中炮弹	

			CBomb* bomb3 = (CBomb *)factory->createProduct(enBomb);
			bomb3->SetInfo(pt.x+30,pt.y+10,2);
			m_ObjList[enBomb].AddTail(bomb3);//左炮弹	
		}
		else if(m_pMe->getBall()==4)
		{	
			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+15,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb1);//左1	
			
			CBomb* bomb2 = (CBomb *)factory->createProduct(enBomb);
			bomb2->SetInfo(pt.x+25,pt.y+10,1);
			m_ObjList[enBomb].AddTail(bomb2);//右1	

			CBomb* bomb3 = (CBomb *)factory->createProduct(enBomb);
			bomb3->SetInfo(pt.x+5,pt.y+10,3);
			m_ObjList[enBomb].AddTail(bomb3);//左2	

			CBomb* bomb4 = (CBomb *)factory->createProduct(enBomb);
			bomb4->SetInfo(pt.x+35,pt.y+10,2);
			m_ObjList[enBomb].AddTail(bomb4);//右2	
		}	
		else if(m_pMe->getBall()==5)
		{	
			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+10,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb1);//左1	
			
			CBomb* bomb2 = (CBomb *)factory->createProduct(enBomb);
			bomb2->SetInfo(pt.x+30,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb2);//右1	
			
			CBomb* bomb5 = (CBomb *)factory->createProduct(enBomb);
			bomb5->SetInfo(pt.x+20,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb5);//中炮弹	

			CBomb* bomb3 = (CBomb *)factory->createProduct(enBomb);
			bomb3->SetInfo(pt.x+0,pt.y+10,3);
			m_ObjList[enBomb].AddTail(bomb3);//左2	

			CBomb* bomb4 = (CBomb *)factory->createProduct(enBomb);
			bomb4->SetInfo(pt.x+40,pt.y+10,2);
			m_ObjList[enBomb].AddTail(bomb4);//右2	
		}	
		else if(m_pMe->getBall()==6)
		{	
			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+15,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb1);//左1	
			
			CBomb* bomb2 = (CBomb *)factory->createProduct(enBomb);
			bomb2->SetInfo(pt.x+25,pt.y+10,1);
			m_ObjList[enBomb].AddTail(bomb2);//右1	

			CBomb* bomb3 = (CBomb *)factory->createProduct(enBomb);
			bomb3->SetInfo(pt.x+5,pt.y+10,3);
			m_ObjList[enBomb].AddTail(bomb3);//左2	

			CBomb* bomb4 = (CBomb *)factory->createProduct(enBomb);
			bomb4->SetInfo(pt.x+35,pt.y+10,2);
			m_ObjList[enBomb].AddTail(bomb4);//右2	

			CBomb* bomb5 = (CBomb *)factory->createProduct(enBomb);
			bomb5->SetInfo(pt.x-5,pt.y+10,5);
			m_ObjList[enBomb].AddTail(bomb5);//左3	

			CBomb* bomb6 = (CBomb *)factory->createProduct(enBomb);
			bomb6->SetInfo(pt.x+45,pt.y+10,4);
			m_ObjList[enBomb].AddTail(bomb6);//右3	
		}	
	}	

	if(m_pMe==NULL)
		return;
	//敌机发射子弹
	CPoint PlanePt = m_pMe->GetPoint();
	for(POSITION ePos=m_ObjList[enEnemy].GetHeadPosition();ePos!=NULL;)//遍历敌机
	{
          CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos);//当前敌机
		  if(!pEnemy->Fired())//如果敌机不能发射，遍历下一个
			  continue;
		  CPoint  ePt = pEnemy->GetPoint();

		  BOOL by=FALSE;

		  //敌机在战机前面
		  if(pEnemy->GetMontion()==1 &&ePt.y>PlanePt.y-300&& ePt.y<PlanePt.y) //GetMontion()得到敌机飞行方向，1为向下飞，并且飞机的y大于敌机的y
		         by=  TRUE;
		  //敌机在战机后面
		  if(pEnemy->GetMontion()==-1 && ePt.y>PlanePt.y)
				 by=  TRUE;	

		  if(by && ePt.x >= PlanePt.x-200 && ePt.x<PlanePt.x+CMyPlane::PLANE_WIDTH+200)  //敌机面对飞机 并且 敌机的x坐标处于飞机的宽度之内
		  {
				CBall* ball = (CBall *)factory->createProduct(enBall);
				ball->SetInfo(ePt.x+10,ePt.y+10,0,0,1);
				m_ObjList[enBall].AddTail(ball);
		  }
	}

	if(m_pMe==NULL)
		return;
	//Boss发射子弹
	for(POSITION ePos=m_ObjList[enBoss].GetHeadPosition();ePos!=NULL;)//遍历boss
	{
          CBoss* pEnemy = (CBoss*)m_ObjList[enBoss].GetNext(ePos);//当前boss
		  if(!pEnemy->Fired())//如果boss不能发射，遍历下一个
			  continue;
		  if(!pEnemy->getZhenboss())
			  continue;
		  CPoint  ePt = pEnemy->GetPoint();
		  pEnemy->setTimeX(m_time);
		  if(!pEnemy->getMove())
		  {
			CBall* ball = (CBall *)factory->createProduct(enBall);
			ball->SetInfo(ePt.x+50,ePt.y+80,0,3,2);
			m_ObjList[enBall].AddTail(ball); //下

			CBall* ball2 = (CBall *)factory->createProduct(enBall);
			ball2->SetInfo(ePt.x+50,ePt.y+80,2,2,2);
			m_ObjList[enBall].AddTail(ball2); //右下

			CBall* ball3 = (CBall *)factory->createProduct(enBall);
			ball3->SetInfo(ePt.x+50,ePt.y+80,3,0,2);
			m_ObjList[enBall].AddTail(ball3); //右

			CBall* ball4 = (CBall *)factory->createProduct(enBall);
			ball4->SetInfo(ePt.x+50,ePt.y+80,2,-2,2);
			m_ObjList[enBall].AddTail(ball4); //右上

			CBall* ball5 = (CBall *)factory->createProduct(enBall);
			ball5->SetInfo(ePt.x+50,ePt.y+80,0,-3,2);
			m_ObjList[enBall].AddTail(ball5); //上

			CBall* ball6 = (CBall *)factory->createProduct(enBall);
			ball6->SetInfo(ePt.x+50,ePt.y+80,-2,-2,2);
			m_ObjList[enBall].AddTail(ball6); //左上

			CBall* ball7 = (CBall *)factory->createProduct(enBall);
			ball7->SetInfo(ePt.x+50,ePt.y+80,-3,0,2);
			m_ObjList[enBall].AddTail(ball7); //左

			CBall* ball8 = (CBall *)factory->createProduct(enBall);
			ball8->SetInfo(ePt.x+50,ePt.y+80,-2,2,2);
			m_ObjList[enBall].AddTail(ball8); //左下
		  }
	}

	if(m_pMe==NULL)
		return;
	//小Boss发射子弹
	for(POSITION ePos=m_ObjList[enBoss].GetHeadPosition();ePos!=NULL;)//遍历boss
	{
			CBoss* pEnemy = (CBoss*)m_ObjList[enBoss].GetNext(ePos);//当前boss
			if(!pEnemy->Fired())//如果boss不能发射，遍历下一个
			  continue;
			if(pEnemy->getZhenboss())
			  continue;
			CPoint  ePt = pEnemy->GetPoint2();
			pEnemy->setTimeX(m_time);
			if(!pEnemy->getMove())
			{
		  
			CBall* ball = (CBall *)factory->createProduct(enBall);
			ball->SetInfo(ePt.x+35,ePt.y+80,0,2,2);
			m_ObjList[enBall].AddTail(ball); //中

			CBall* ball2 = (CBall *)factory->createProduct(enBall);
			ball2->SetInfo(ePt.x+25,ePt.y+70,-1,2,2);
			m_ObjList[enBall].AddTail(ball2); //下

			CBall* ball3 = (CBall *)factory->createProduct(enBall);
			ball3->SetInfo(ePt.x+45,ePt.y+70,1,2,2);
			m_ObjList[enBall].AddTail(ball3); //下
			}
	}

	if(m_pMe==NULL)
		return;
	//吃道具
	POSITION sPos1=NULL,sPos2=NULL;
	CRect smRect = m_pMe->GetRect();	//飞机的矩形
	for(sPos1=m_ObjList[enStrengthen].GetHeadPosition();( sPos2 = sPos1 ) != NULL;) //遍历子道具
	{
		CStrengthen* strengthen = (CStrengthen*)m_ObjList[enStrengthen].GetNext(sPos1);//当前道具
		CRect bRect = strengthen->GetRect();	//子弹的矩形
		CRect tmpRect;
		if(strengthen->getJiemian())
			continue;
		if(tmpRect.IntersectRect(&bRect,smRect)) //判断飞机与子弹是否相交，IntersectRect()使tmpRect等于两个现有矩形的交,如果交不为空，则返回非零值；否则，如果交为空则返回0。
		{
			if(strengthen->getIndex()==0)//子弹数
			{
				if(m_pMe->getBall()<6)
					m_pMe->setBall(m_pMe->getBall()+1);
			}else if(strengthen->getIndex()==1)//生命数
			{
				m_pMe->setLife(m_pMe->getLife()+1);

				CStrengthen* ball = (CStrengthen *)factory->createProduct(enStrengthen);
				ball->setIndex(1);
				ball->setPoint(GAME_WIDTH*(m_pMe->getLife()/13+1)-40*(m_pMe->getLife()),(m_pMe->getLife()/13)*40,true);
				//ball->setPoint(800-50,0,true);
				m_ObjList[enStrengthen].AddTail(ball);
				
			}else if(strengthen->getIndex()==2)//道具
			{
				m_pMe->setDazhao(m_pMe->getDazhao()+1);

			}else if(strengthen->getIndex()==3)//道具
			{
					m_pMe->setFanghu(m_pMe->getFanghu()+1);
			}		
				//删除道具
				m_ObjList[enStrengthen].RemoveAt(sPos2);
				//delete strengthen;
				break;
		}
	}
	
	if(m_pMe==NULL)
		return;
	//吃金币
	POSITION ggPos1=NULL,ggPos2=NULL;
	CRect ggRect = m_pMe->GetRect();	//飞机的矩形
	for(ggPos1=m_ObjList[enGold].GetHeadPosition();( ggPos2 = ggPos1 ) != NULL;) //遍历子道具
	{
		CGold* strengthen = (CGold*)m_ObjList[enGold].GetNext(ggPos1);//当前道具
		CRect bRect = strengthen->GetRect();	//子弹的矩形
		CRect tmpRect;
		if(tmpRect.IntersectRect(&bRect,ggRect)) //判断飞机与子弹是否相交，IntersectRect()使tmpRect等于两个现有矩形的交,如果交不为空，则返回非零值；否则，如果交为空则返回0。
		{
			m_ObjList[enGold].RemoveAt(ggPos2);
			score++;
		}
	}
	
	if(m_pMe==NULL)
		return;
	//敌机子弹炸掉战机
	POSITION bPos1=NULL,bPos2=NULL;
	CRect mRect = m_pMe->GetRect();	//飞机的矩形
	for(bPos1=m_ObjList[enBall].GetHeadPosition();( bPos2 = bPos1 ) != NULL;) //遍历子弹
	{
		CBall* pBall = (CBall*)m_ObjList[enBall].GetNext(bPos1);//当前子弹
		CRect bRect = pBall->GetRect();	//子弹的矩形
		CRect tmpRect;
		if(tmpRect.IntersectRect(&bRect,mRect)) //判断飞机与子弹是否相交，IntersectRect()使tmpRect等于两个现有矩形的交,如果交不为空，则返回非零值；否则，如果交为空则返回0。
		{
			if(m_pMe->getBlood()>1)
			{
					if(!wudi){
						m_pMe->setBlood(m_pMe->getBlood()-1);
					}
				//添加爆炸效果
				CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
				explosion->SetInfo(mRect.left,mRect.top);
				m_ObjList[enExplosion].AddTail(explosion);
				
				//删除子弹
				m_ObjList[enBall].RemoveAt(bPos2);
				delete pBall;
			}
			else
			{
				if(m_pMe->getLife()>0)
				{
					
					m_pMe->setBlood(10);
					m_pMe->setLife(m_pMe->getLife()-1);

					//更新界面
					POSITION mPos1=NULL,mPos2=NULL;
					for(mPos1=m_ObjList[enStrengthen].GetTailPosition();(mPos2=mPos1)!=NULL;)
					{
						CStrengthen* stren = (CStrengthen*)m_ObjList[enStrengthen].GetPrev(mPos1);
						if(stren->getJiemian())
						{
							m_ObjList[enStrengthen].RemoveAt(mPos2);
							break;
						}
					}

					//删除子弹
					m_ObjList[enBall].RemoveAt(bPos2);
						delete pBall;
				}else
				{
					//添加爆炸效果
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

					//删除子弹
					m_ObjList[enBall].RemoveAt(bPos2);
					//if(pBall!=NULL)
						delete pBall;

					//删除战机
					delete m_pMe;
					
					m_pMe=NULL;
					break;
				}
			}
			
		}
	}
	if(m_pMe==NULL)
		return;
	//敌机 撞 战机
	POSITION eePos1=NULL,eePos2=NULL;
	CRect ppRect = m_pMe->GetRect();	//飞机的矩形
	for(eePos1=m_ObjList[enEnemy].GetHeadPosition();( eePos2 = eePos1 ) != NULL;) //遍历敌机
	{
		CEnemy* pBall = (CEnemy*)m_ObjList[enEnemy].GetNext(eePos1);//当前敌机
		CRect bRect = pBall->GetRect();	//敌机的矩形
		CRect tmpRect;
		if(tmpRect.IntersectRect(&bRect,ppRect)) //判断飞机与子弹是否相交，IntersectRect()使tmpRect等于两个现有矩形的交,如果交不为空，则返回非零值；否则，如果交为空则返回0。
		{
			if(m_pMe->getBlood()>1)
			{
				if(!wudi)//如果不是无敌
				{
					m_pMe->setBlood(m_pMe->getBlood()-1);
				}
				//删除敌机
				pBall->setPoint(0, GAME_HEIGHT+100);

				static int count = rand() %3+2;
					//随机产生道具
					if(count<0)
					{		
						count = rand()%3+2;//+3
						int nDaoju = rand()%4;
						CStrengthen* strengthen  = (CStrengthen *)factory->createProduct(enStrengthen);	//进度条
						strengthen->setIndex(nDaoju);
						strengthen->setPoint(bRect.left,bRect.top,false);
						m_ObjList[enStrengthen].AddTail(strengthen);  //将CEnemy类型的CObject添加到m_ObjList
					}
					count--;

			}else
			{
				if(m_pMe->getLife()>0)
				{
					m_pMe->setBlood(10);
					m_pMe->setLife(m_pMe->getLife()-1);
						

					//更新界面
					POSITION mPos1=NULL,mPos2=NULL;
					for(mPos1=m_ObjList[enStrengthen].GetTailPosition();(mPos2=mPos1)!=NULL;)
					{
						CStrengthen* stren = (CStrengthen*)m_ObjList[enStrengthen].GetPrev(mPos1);
						if(stren->getJiemian())
						{
							m_ObjList[enStrengthen].RemoveAt(mPos2);
							break;
						}
					}
					//删除敌机
					pBall->setPoint(0, GAME_HEIGHT+100);	
				}else
				{
					//删除敌机
					pBall->setPoint(0, GAME_HEIGHT+100);

					//删除战机
					delete m_pMe;
					
					m_pMe=NULL;
					break;
				}
			}
			//添加爆炸效果
			CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
			explosion->SetInfo(ppRect.left,ppRect.top);
			m_ObjList[enExplosion].AddTail(explosion);
		}
	}
	//大小boss 撞 战机
	if(m_pMe==NULL)
		return;
	POSITION bbPos1=NULL,bbPos2=NULL;
	CRect bpRect = m_pMe->GetRect();	//飞机的矩形
	for(bbPos1=m_ObjList[enBoss].GetHeadPosition();( bbPos2 = bbPos1 ) != NULL;) //遍历敌机
	{
		CBoss* pBall = (CBoss*)m_ObjList[enBoss].GetNext(bbPos1);//当前敌机
		CRect bRect = pBall->GetRect();	//boss的矩形
		CRect tmpRect;
		if(tmpRect.IntersectRect(&bRect,bpRect)) //判断飞机与子弹是否相交，IntersectRect()使tmpRect等于两个现有矩形的交,如果交不为空，则返回非零值；否则，如果交为空则返回0。
		{
			
			if(m_pMe->getBlood()>1)
			{
				if(!wudi)//如果不是无敌
				{
					m_pMe->setBlood(m_pMe->getBlood()-1);
				}
				//boss减血
				if(pBall->getZhenboss())
					pBall->setBlood(pBall->getBlood()-(pBall->getBossBlood()/10));
				//小boss减血
				if(!pBall->getZhenboss())
					pBall->setBlood2(pBall->getBlood2()-(pBall->getBossBlood2()/10));
			}else
			{
				if(m_pMe->getLife()>0)
				{
					m_pMe->setBlood(10);
					m_pMe->setLife(m_pMe->getLife()-1);
					
					//更新界面

					
					POSITION mPos1=NULL,mPos2=NULL;
					for(mPos1=m_ObjList[enStrengthen].GetTailPosition();(mPos2=mPos1)!=NULL;)
					{
						CStrengthen* stren = (CStrengthen*)m_ObjList[enStrengthen].GetPrev(mPos1);
						if(stren->getJiemian())
						{
							m_ObjList[enStrengthen].RemoveAt(mPos2);
							break;
						}
					}
					//boss减血
					pBall->setBlood(pBall->getBlood()-(pBall->getBossBlood()/10));	
				}else
				{

					//boss减血
					pBall->setBlood(pBall->getBlood()-(pBall->getBossBlood()/10));

					//删除战机
					delete m_pMe;
					
					m_pMe=NULL;
					break;
				}
			}
		
		//添加爆炸效果
		CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
		explosion->SetInfo(bRect.left,bRect.top);
		m_ObjList[enExplosion].AddTail(explosion);	
		}
	}

	if(m_pMe==NULL)
		return;
	//战机 导弹炸掉 敌机
	POSITION mPos1=NULL,mPos2=NULL;
	for(mPos1=m_ObjList[enBomb].GetHeadPosition();(mPos2=mPos1)!=NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(mPos1);
		CRect bRect = pBomb->GetRect();	//导弹矩形

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enEnemy].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();//敌机矩形
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//如果敌机与导弹相交
			{
				
				if(pEnemy->getBlood()>1)
				{
					pEnemy->setBlood(pEnemy->getBlood()-1);
					
					//删除导弹
					CBomb* bomb_t = (CBomb*)m_ObjList[enBomb].GetNext(mPos2);
					bomb_t->SetInfo(0,GAME_HEIGHT+100,0);				//直接移到屏幕外

					//添加爆炸效果
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

				}
				else
				{
	
					static int count = rand() %3+2;
					//随机产生道具
					if(count<0)
					{		
						count = rand()%3+2;//+3
						int nDaoju = rand()%4;
						CStrengthen* strengthen  = (CStrengthen *)factory->createProduct(enStrengthen);	//进度条
						strengthen->setIndex(nDaoju);
						strengthen->setPoint(mRect.left,mRect.top,false);
						m_ObjList[enStrengthen].AddTail(strengthen);  //将CEnemy类型的CObject添加到m_ObjList
					}
					count--;

					CGold* gold = (CGold *)factory->createProduct(enGold);
					gold->SetInfo(mRect.left+20,mRect.top+10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
					m_ObjList[enGold].AddTail(gold);	
					
					//删除敌机
					m_ObjList[enEnemy].RemoveAt(ePos2);
					delete pEnemy;

					break;
				}
			}
		}
	}


	if(m_pMe==NULL)
		return;
	//战机 导弹炸掉 小boss
	POSITION m_xPos1=NULL,m_xPos2=NULL;
	for(m_xPos1=m_ObjList[enBomb].GetHeadPosition();(m_xPos2=m_xPos1)!=NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(m_xPos1);
		CRect bRect = pBomb->GetRect();	//导弹矩形

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enBoss].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CBoss* pEnemy = (CBoss*)m_ObjList[enBoss].GetNext(ePos1);
			if(pEnemy->getZhenboss())
				continue;
			CRect mRect = pEnemy->GetRect();//敌机矩形
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//如果敌机与导弹相交
			{
				if(pEnemy->getBlood2()>1)
				{
					pEnemy->setBlood2(pEnemy->getBlood2()-1);
					
					//删除导弹
					CBomb* bomb_t = (CBomb*)m_ObjList[enBomb].GetNext(m_xPos2);
					bomb_t->SetInfo(0,GAME_HEIGHT+100,0);				//直接移到屏幕外

					//添加爆炸效果
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(bRect.left,bRect.top-60);
					m_ObjList[enExplosion].AddTail(explosion);

				}
				else
				{

					static int count = rand() %3+2;

					//随机产生道具
					if(count<0)
					{
						count = rand()%3+2;//+3
						int nDaoju = rand()%4;
						CStrengthen* strengthen  = (CStrengthen *)factory->createProduct(enStrengthen);	//进度条
						strengthen->setIndex(nDaoju);
						strengthen->setPoint(mRect.left,mRect.top,false);
						m_ObjList[enStrengthen].AddTail(strengthen);  //将CEnemy类型的CObject添加到m_ObjList
					}
					count--;
					
					CGold* gold = (CGold *)factory->createProduct(enGold);
					gold->SetInfo(mRect.left+20,mRect.top+10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
					m_ObjList[enGold].AddTail(gold);

					CGold* gold2 = (CGold *)factory->createProduct(enGold);
					gold2->SetInfo(mRect.left+10,mRect.top+0,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
					m_ObjList[enGold].AddTail(gold2);

					CGold* gold3 = (CGold *)factory->createProduct(enGold);
					gold3->SetInfo(mRect.left+0,mRect.top-10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
					m_ObjList[enGold].AddTail(gold3);

					CGold* gold4 = (CGold *)factory->createProduct(enGold);
					gold4->SetInfo(mRect.left+30,mRect.top+20,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
					m_ObjList[enGold].AddTail(gold4);

					CGold* gold5 = (CGold *)factory->createProduct(enGold);
					gold5->SetInfo(mRect.left+40,mRect.top+30,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
					m_ObjList[enGold].AddTail(gold5);

					//删除敌机
					m_ObjList[enBoss].RemoveAt(ePos2);
					delete pEnemy;

					break;
				}
				
			}
		}
	}


	if(m_pMe==NULL)
		return;
	//大招 炸掉 敌机
	POSITION daZPos1=NULL,daZPos2=NULL;
	for(daZPos1=m_ObjList[enDazhao].GetHeadPosition();(daZPos2=daZPos1)!=NULL;)
	{
		CDazhao* pBomb = (CDazhao*)m_ObjList[enDazhao].GetNext(daZPos1);
		CRect bRect = pBomb->GetRect();	//导弹矩形

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enEnemy].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();//敌机矩形
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//如果敌机与导弹相交
			{
				
				if(pEnemy->getBlood()>1)
				{
					pEnemy->setBlood(pEnemy->getBlood()-1);
					

					//添加爆炸效果
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

				}
				else
				{

					static int count = rand() %3+2;

					//随机产生道具
					if(count<0)
					{
						count = rand()%3+2;//+3
						int nDaoju = rand()%4;
						CStrengthen* strengthen  = (CStrengthen *)factory->createProduct(enStrengthen);	//进度条
						strengthen->setIndex(nDaoju);
						strengthen->setPoint(mRect.left,mRect.top,false);
						m_ObjList[enStrengthen].AddTail(strengthen);  //将CEnemy类型的CObject添加到m_ObjList
					}
					count--;

					CGold* gold = (CGold *)factory->createProduct(enGold);
					gold->SetInfo(mRect.left+20,mRect.top+10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
					m_ObjList[enGold].AddTail(gold);	
					
					//删除敌机
					m_ObjList[enEnemy].RemoveAt(ePos2);
					delete pEnemy;

					break;
				}
			}
		}
	}

	if(m_pMe==NULL)
		return;
	//大招 炸掉 子弹
	POSITION da_BPos1=NULL,da_BPos2=NULL;
	for(da_BPos1=m_ObjList[enDazhao].GetHeadPosition();(da_BPos2=da_BPos1)!=NULL;)
	{
		CDazhao* pBomb = (CDazhao*)m_ObjList[enDazhao].GetNext(da_BPos1);
		CRect bRect = pBomb->GetRect();	//大招矩形

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enBall].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CBall* pEnemy = (CBall*)m_ObjList[enBall].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();//子弹矩形
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//如果子弹与大招相交
			{
				//添加爆炸效果
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);
				
					pEnemy->SetInfo(-100,-100,-1,-1,2);//删除子弹
			}
		}
	}


	if(m_pMe==NULL)
		return;
	//大招 炸掉 大小boss
	POSITION DaBPos1=NULL,DaBPos2=NULL;
	for(DaBPos1=m_ObjList[enDazhao].GetHeadPosition();(DaBPos2=DaBPos1)!=NULL;)
	{
		CDazhao* pBomb = (CDazhao*)m_ObjList[enDazhao].GetNext(DaBPos1);
		CRect bRect = pBomb->GetRect();	//导弹矩形
		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enBoss].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CBoss* pEnemy = (CBoss*)m_ObjList[enBoss].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();//boss矩形
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//如果敌机与导弹相交
			{
				if(pEnemy->getZhenboss())
				{
					if(pEnemy->getBlood()>1)
					{
						pEnemy->setBlood(pEnemy->getBlood()-1);

						//添加爆炸效果
						CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
						explosion->SetInfo(mRect.left,mRect.top);
						m_ObjList[enExplosion].AddTail(explosion);
					}else
					{
						if(pEnemy->getZhenboss())
						{
							score+=100;
							if(mission>5)
							{
								KillTimer(1);
								showInfo(m_pMemDC,_T("恭喜您通关！"),GAME_WIDTH/2,GAME_HEIGHT/2);
								btn[2].ShowWindow(SW_SHOW);
								btn[3].ShowWindow(SW_SHOW);
							}else
							{
								KillTimer(1);
								showInfo(m_pMemDC,_T("是否进入下一关？"),GAME_WIDTH/2,GAME_HEIGHT/2);
								btn[5].ShowWindow(SW_SHOW);
							}
						}else
						{

							//添加爆炸效果
							CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
							explosion->SetInfo(mRect.left,mRect.top);
							m_ObjList[enExplosion].AddTail(explosion);
					
							CGold* gold = (CGold *)factory->createProduct(enGold);
							gold->SetInfo(mRect.left+20,mRect.top+10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
							m_ObjList[enGold].AddTail(gold);
	
							CGold* gold2 = (CGold *)factory->createProduct(enGold);
							gold2->SetInfo(mRect.left+10,mRect.top+0,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
							m_ObjList[enGold].AddTail(gold2);

							CGold* gold3 = (CGold *)factory->createProduct(enGold);
							gold3->SetInfo(mRect.left+0,mRect.top-10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
							m_ObjList[enGold].AddTail(gold3);

							CGold* gold4 = (CGold *)factory->createProduct(enGold);
							gold4->SetInfo(mRect.left+30,mRect.top+20,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
							m_ObjList[enGold].AddTail(gold4);

							CGold* gold5 = (CGold *)factory->createProduct(enGold);
							gold5->SetInfo(mRect.left+40,mRect.top+30,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
							m_ObjList[enGold].AddTail(gold5);
						}
					
						//删除boss
						m_ObjList[enBoss].RemoveAt(ePos2);
						delete pEnemy;
					}
					

				}else
				{
					if(pEnemy->getBlood2()>1)
					{
						pEnemy->setBlood2(pEnemy->getBlood2()-1);
						//添加爆炸效果
						CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
						explosion->SetInfo(mRect.left,mRect.top);
						m_ObjList[enExplosion].AddTail(explosion);
					}else
					{
							//添加爆炸效果
							CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
							explosion->SetInfo(mRect.left,mRect.top);
							m_ObjList[enExplosion].AddTail(explosion);

							CGold* gold = (CGold *)factory->createProduct(enGold);
							gold->SetInfo(mRect.left+20,mRect.top+10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
							m_ObjList[enGold].AddTail(gold);
	
							CGold* gold2 = (CGold *)factory->createProduct(enGold);
							gold2->SetInfo(mRect.left+10,mRect.top+0,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
							m_ObjList[enGold].AddTail(gold2);

							CGold* gold3 = (CGold *)factory->createProduct(enGold);
							gold3->SetInfo(mRect.left+0,mRect.top-10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
							m_ObjList[enGold].AddTail(gold3);

							CGold* gold4 = (CGold *)factory->createProduct(enGold);
							gold4->SetInfo(mRect.left+30,mRect.top+20,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
							m_ObjList[enGold].AddTail(gold4);

							CGold* gold5 = (CGold *)factory->createProduct(enGold);
							gold5->SetInfo(mRect.left+40,mRect.top+30,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
							m_ObjList[enGold].AddTail(gold5);
							

							//删除boss
							m_ObjList[enBoss].RemoveAt(ePos2);
							delete pEnemy;
					
					}
				}
				
				
			}
		
		}
		
	}


	if(m_pMe==NULL)
		return;
	//战机 导弹2炸掉 敌机
	POSITION m2Pos1=NULL,m2Pos2=NULL;
	for(m2Pos1=m_ObjList[enBomb2].GetHeadPosition();(m2Pos2=m2Pos1)!=NULL;)
	{
		CBomb2* pBomb = (CBomb2*)m_ObjList[enBomb2].GetNext(m2Pos1);
		CRect bRect = pBomb->GetRect();	//导弹矩形

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enEnemy].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();//敌机矩形
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//如果敌机与导弹相交
			{
					static int count= rand() %3+2;
				
					//随机产生道具
					if(count<0)
					{		
						count = rand()%3+2;//+3
						int nDaoju = rand()%3;
						CStrengthen* strengthen  = (CStrengthen *)factory->createProduct(enStrengthen);	//进度条
						strengthen->setIndex(nDaoju);
						strengthen->setPoint(mRect.left,mRect.top,false);
						m_ObjList[enStrengthen].AddTail(strengthen);  //将CEnemy类型的CObject添加到m_ObjList
					}
					count--;

					CGold* gold = (CGold *)factory->createProduct(enGold);
					gold->SetInfo(mRect.left+20,mRect.top+10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
					m_ObjList[enGold].AddTail(gold);	

					//删除导弹
					CBomb2* bomb_t = (CBomb2*)m_ObjList[enBomb2].GetNext(m2Pos2);
					bomb_t->SetInfo(0,GAME_HEIGHT+100,0,0);				//直接移到屏幕外

					//添加爆炸效果
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

					
				

					
					//指向下一个敌机
					CPoint Da_Pt =pEnemy->GetPoint();//当前敌机坐标
					double x1=Da_Pt.x;
					double y1=Da_Pt.y;
					
					

					POSITION enemyPos1,enemyPos2;
					double juli=10000000000000;
					POSITION minPos=NULL;
					for( enemyPos1 = m_ObjList[enEnemy].GetHeadPosition(); ( enemyPos2 = enemyPos1 ) != NULL; )	//GetHeadPosition()得到头索引。
					{
						CEnemy* pObj = (CEnemy*)m_ObjList[enEnemy].GetNext( enemyPos1 );//GetNext(pos1)将pos1的值设置为下一位置，返回值为当前节点的地址，即当前物体的对象地址
						CPoint pppt = pObj->GetPoint();
						if(pObj->getToBomb2()!=NULL||pppt.y<0||pppt.y>GAME_HEIGHT)
							continue;
					
						CPoint enemyPt = pObj->GetPoint();
						double x2=enemyPt.x;
						double y2=enemyPt.y;

						double n= (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
						if(n<juli)
						{
							minPos=enemyPos2;
							juli=n;
						}
					}
					if(minPos!=NULL)
					{
						CEnemy* pObj = (CEnemy*)m_ObjList[enEnemy].GetNext(minPos);
						CPoint pppt = pObj->GetPoint();
						CBomb2* bomb2 = (CBomb2 *)factory->createProduct(enBomb2);//所指敌机
						bomb2->SetInfo(Da_Pt.x,Da_Pt.y,Da_Pt.x,0);
						bomb2->setToEnemy(minPos);
						m_ObjList[enBomb2].AddTail(bomb2);  //将CEnemy类型的CObject添加到m_ObjList
						pObj->setToBomb2(minPos);
					}
					
					//删除敌机
					m_ObjList[enEnemy].RemoveAt(ePos2);
					delete pEnemy;
					break;
				
			}
		}
	}
	
	if(m_pMe==NULL)
		return;
	//战机 导弹炸掉 boss
	POSITION boPos1=NULL,boPos2=NULL;
	for(boPos1=m_ObjList[enBomb].GetHeadPosition();(boPos2=boPos1)!=NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(boPos1);

		CRect bRect = pBomb->GetRect();	//导弹矩形

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enBoss].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CBoss* pEnemy = (CBoss*)m_ObjList[enBoss].GetNext(ePos1);
			if(!pEnemy->getZhenboss())
				continue;
			CRect mRect = pEnemy->GetRect();//boss矩形
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//如果敌机与导弹相交
			{
				if(pEnemy->getBlood()>1)
				{
					pEnemy->setBlood(pEnemy->getBlood()-1);

					//删除导弹
					CBomb* bomb_t = (CBomb*)m_ObjList[enBomb].GetNext(boPos2);
					bomb_t->SetInfo(0,GAME_HEIGHT+100,0);				//直接移到屏幕外

					//添加爆炸效果
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(bRect.left-33,bRect.top-33);
					m_ObjList[enExplosion].AddTail(explosion);


				}else
				{
					//添加爆炸效果
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

					//删除boss
					m_ObjList[enBoss].RemoveAt(ePos2);
					delete pEnemy;

					score+=100;
					if(mission>5)
					{
						KillTimer(1);
						showInfo(m_pMemDC,_T("恭喜您通关！"),GAME_WIDTH/2,GAME_HEIGHT/2);
						btn[2].ShowWindow(SW_SHOW);
						btn[3].ShowWindow(SW_SHOW);
					}else
					{
						KillTimer(1);
						showInfo(m_pMemDC,_T("是否进入下一关？"),GAME_WIDTH/2,GAME_HEIGHT/2);
						btn[5].ShowWindow(SW_SHOW);
					}
					break;
				}
			}
		
		}
		
	}

}
void CPlaneGameView::OnTimer(UINT_PTR nIDEvent)
{
	//刷新游戏帧画面: 在内存DC上绘图
	UpdateFrame(m_pMemDC);
	AI();
	m_time +=3;
	CView::OnTimer(nIDEvent);
}


