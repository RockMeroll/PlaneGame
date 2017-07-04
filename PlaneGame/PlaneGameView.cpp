// PlaneGameView.cpp : CPlaneGameView ���ʵ��
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

afx_msg void CPlaneGameView::btnclick0(void)//��ʼ��Ϸ
{
	//MessageBox(_T("btn click0"));
	for(int i=0;i<9;i++)
	{
		m_ObjList[i].RemoveAll();
	}
	if(m_pMe==NULL)
		m_pMe = (CMyPlane *)factory->createProduct(enPlane);
	//��ʼ��
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


afx_msg void CPlaneGameView::btnclick1(void)//�޵�ģʽ
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
afx_msg void CPlaneGameView::btnclick2(void)//���¿�ʼ
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

afx_msg void CPlaneGameView::btnclick3(void)//�ص����˵�
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
afx_msg void CPlaneGameView::btnclick4(void)//����
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
afx_msg void CPlaneGameView::btnclick5(void)//��һ��
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


// CPlaneGameView ����/����

CPlaneGameView::CPlaneGameView():m_pMe(NULL)
{
	// TODO: �ڴ˴���ӹ������
	
}

CPlaneGameView::~CPlaneGameView()
{
}

BOOL CPlaneGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPlaneGameView ����

void CPlaneGameView::OnDraw(CDC* /*pDC*/)
{
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}



// CPlaneGameView ���

#ifdef _DEBUG
void CPlaneGameView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneGameDoc* CPlaneGameView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneGameDoc)));
	return (CPlaneGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneGameView ��Ϣ�������
void CPlaneGameView::OnInitialUpdate()									// 1
{
	CView::OnInitialUpdate();
	// TODO: �ڴ����ר�ô����/����û���
		
		m_time = 0;//ʱ��

		btn = new CButton[6];  //1��ʼ��Ϸ��2�޵�ģʽ��3���¿�ʼ
		DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;  
		DWORD dwStyle2 = WS_CHILD | BS_PUSHBUTTON; 
			btn[0].Create(_T("��ʼ��Ϸ"), dwStyle,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100,GAME_WIDTH/2+50,GAME_HEIGHT/2-75),this,buttonID+0);   
			//btn[0].SetFont(GetParent()->GetFont());  
			btn[1].Create(_T("�޵�ģʽ"), dwStyle,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100+35,GAME_WIDTH/2+50,GAME_HEIGHT/2-75+35),this,buttonID+1);   
			btn[1].SetFont(GetParent()->GetFont());  
			btn[2].Create(_T("���¿�ʼ"), dwStyle2,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100,GAME_WIDTH/2+50,GAME_HEIGHT/2-75),this,buttonID+2);   
			btn[2].SetFont(GetParent()->GetFont());
			btn[3].Create(_T("�������˵�"), dwStyle2,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100+35,GAME_WIDTH/2+50,GAME_HEIGHT/2-75+35),this,buttonID+3);   
			btn[3].SetFont(GetParent()->GetFont()); 
			btn[4].Create(_T("����"), dwStyle2,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100,GAME_WIDTH/2+50,GAME_HEIGHT/2-75),this,buttonID+4);   
			btn[4].SetFont(GetParent()->GetFont());
			btn[5].Create(_T("������һ��"), dwStyle2,CRect(GAME_WIDTH/2-50,GAME_HEIGHT/2-100,GAME_WIDTH/2+50,GAME_HEIGHT/2-75),this,buttonID+5);   
			btn[5].SetFont(GetParent()->GetFont());

		//��ʼ����Ϸ
		InitGame();														
}
void CPlaneGameView::StopGame()
{
	delete m_pMe;		//�ɻ���   CMyPlane*
	delete m_pMemDC;	//�ڴ�DC   CDC*  
	delete m_pDC;		//�豸DC   CClientDC*
	delete m_pMemBitmap;//�ڴ�λͼ CBitmap*  
}

BOOL CPlaneGameView::InitGame()											// 2
{
	
	factory = new SimpleFactory();		//����

	//CRect rc;
	//GetClientRect(rc);		//�õ��ͻ���Rect
		

	//�������������
	srand( (unsigned)time( NULL ) );


	//�����豸DC
	m_pDC = new CClientDC(this);	//CClientDC


	//�����ڴ�DC
	m_pMemDC = new CDC;				//CDC
	m_pMemDC->CreateCompatibleDC(m_pDC);								//����һ����ָ���豸DC(CClientDC)���ݵ��ڴ�DC(CDC)

	//�����ڴ�λͼ
	m_pMemBitmap = new CBitmap;		//CBitmap
	m_pMemBitmap->CreateCompatibleBitmap(m_pDC,GAME_WIDTH,GAME_HEIGHT); //����һ�����豸DC(CClientDC)�йص�λͼ(CBitmap)������ָ�����豸��������
							//λͼ(CBitmap)ѡ���ڴ�DC(CDC)

	//��λͼѡ���ڴ�DC
	m_pMemDC->SelectObject(m_pMemBitmap);	

	CMyPlane::LoadImage();	//���¼������LoadImage()���Ը�����������أ�ִ���ж������˸����LoadImage()��ֻ�ǵ��õĲ�����ͬ
	CMyPlane::LoadImage2();	//Ѫ��
	CMaps::LoadImage();
	CMaps::LoadImage2();
	CProgress::LoadImage();
	CEnemy::LoadImage();	//��Ϊÿ������static CImageList m_Images;��̬����������m_Imagesֻ��Ҫһ��ȷ���������඼����
	CEnemy::LoadImage2();
	CBoss::LoadImage();	//��Ϊÿ������static CImageList m_Images;��̬����������m_Imagesֻ��Ҫһ��ȷ���������඼����
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

	//��������(ս��)
	m_pMe = (CMyPlane *)factory->createProduct(enPlane);	//�ɻ�
	
	mission=1;
	maps = (CMaps *)factory->createProduct(enMap);		//����ͼ
	maps->SetInfo(0,0,0,-800,mission-1);
	
	progress = (CProgress *)factory->createProduct(enProgress);	//������
	progress->SetInfo(45,68,pro);
	
	shengming=(CStrengthen *)factory->createProduct(enStrengthen);	//����ͼ��
	shengming->setIndex(3);

	dazhao=(CStrengthen *)factory->createProduct(enStrengthen);	//����ͼ��
	dazhao->setIndex(2);

	return TRUE;
}

void CPlaneGameView::UpdateFrame(CDC* pMemDC)	//�����Ĳ���pMemDC���ڴ�DC							//4     4��5���ϵ�ѭ��
{
	//��������
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
		maps->Draw(m_pMemDC,FALSE);			//������ͼ
	}

	if(progress!=NULL)		
	{
		progress->SetTime(pro);
		progress->Draw(m_pMemDC,FALSE);		//��������
	}
	

	//�����ҷ�ս��
	if(m_pMe!=NULL)		//���ս����û��delete
	{
	   m_pMe->Draw(m_pMemDC,FALSE); //false ��ʾû��ֹͣ�˶�
		
		showInfo(m_pMemDC,score,_T("�÷֣�"),0,0);
		showInfo(m_pMemDC,mission,_T("�ؿ���"),0,20);
		showInfo(m_pMemDC,m_pMe->getBlood()*10,_T("Ѫ����"),0,40);
		showInfo(m_pMemDC,_T("���ȣ�"),0,60);
		showInfo(m_pMemDC,_T("��Esc��ͣ/����"),0,80);
		showInfo(m_pMemDC,_T("����:"),0,100);
		showInfo(m_pMemDC,_T("  Z �ռ䵯"),0,120);
		showInfo(m_pMemDC,_T("  X ������"),0,140);
		showInfo(m_pMemDC,_T("  C ���ٵ�"),0,160);
		showInfo(m_pMemDC,_T("  V ������"),0,180);
		showInfo(m_pMemDC,_T("�ո�  ��ɱ"),0,200);
		//showInfo(m_pMemDC,m_time,_T("ʱ�䣺"),0,GAME_HEIGHT-100);
		
		shengming->setPoint(0,GAME_HEIGHT-85,false);
		shengming->Draw(m_pMemDC,FALSE);	//������ͼ��
		showInfo(m_pMemDC,m_pMe->getFanghu(),_T(""),35,GAME_HEIGHT-75);

		dazhao->setPoint(0,GAME_HEIGHT-55,false);
		dazhao->Draw(m_pMemDC,FALSE);	//������ͼ��
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
	
	//���� ��������ը���л����ӵ�
	for(int i=0;i<9;i++)
	{
		POSITION pos1,pos2;			//POSITION������Ÿ���List��Array����������������ڱ���ʱ��ʶԪ�ص�λ�á�
		for( pos1 = m_ObjList[i].GetHeadPosition(); ( pos2 = pos1 ) != NULL; )	//GetHeadPosition()�õ�ͷ������
		{
			CGameObject* pObj = (CGameObject*)m_ObjList[i].GetNext( pos1 );//GetNext(pos1)��pos1��ֵ����Ϊ��һλ�ã�����ֵΪ��ǰ�ڵ�ĵ�ַ������ǰ����Ķ����ַ
			if(!pObj->Draw(pMemDC,FALSE))	//�������ʧ�ܣ���Ϊ���곬����Ļ��Χ
			{
				m_ObjList[i].RemoveAt(pos2);//pos2Ϊ��ǰ�����λ�ã�RemoveAt(pos2)��ɾ��pos2��ָ��
					//pObj=NULL;
					delete pObj;
			}	
		}
	}

	//�����ڴ�DC���豸DC
	m_pDC->BitBlt(0,0,GAME_WIDTH,GAME_HEIGHT,m_pMemDC,0,0,SRCCOPY);	//BitBlt()���ڴ�ԭ�豸�и���λͼ��Ŀ���豸,SRCCOPY:ֱ�Ӹ���Դ�豸����Ŀ���豸��
}
void CPlaneGameView::AI()																			//5
{

	static int nCreator = rand() %30+15;

	//��������л�
	if(nCreator<=0)
	{
		nCreator = rand()%30+10;

		CEnemy* enemy = (CEnemy *)factory->createProduct(enEnemy);
		m_ObjList[enEnemy].AddTail(enemy);  //��CEnemy���͵�CObject��ӵ�m_ObjList
	}
	nCreator--;
		
	if(m_pMe==NULL)	//����Լ��ɻ��Ѿ���ը�ˣ��Ͳ�����ִ����
		return;
	
	//��ҹ켣
	POSITION gPos1,gPos2;
	for( gPos1 = m_ObjList[enGold].GetHeadPosition(); ( gPos2 = gPos1 ) != NULL; )	//GetHeadPosition()�õ�ͷ������
		{
			CGold* pObj = (CGold*)m_ObjList[enGold].GetNext( gPos1 );//GetNext(pos1)��pos1��ֵ����Ϊ��һλ�ã�����ֵΪ��ǰ�ڵ�ĵ�ַ������ǰ����Ķ����ַ
			pObj->SetPlane(m_pMe->GetPoint().x,m_pMe->GetPoint().y);
		}
	
	//����boss
	if((m_time>4500&&m_time<4504))
	{
		CBoss* boss = (CBoss *)factory->createProduct(enBoss);
		boss->setIndex(mission);
		boss->setTimeY(m_time);
		boss->setZhenboss(true);
		m_ObjList[enBoss].AddTail(boss);  //��CEnemy���͵�CObject��ӵ�m_ObjList
		
	}
	
	//����СBOSS
	if(m_pMe==NULL)	
		return;
	if(score>20&&score%20>0&&score%20<3)
	{
		if(!m_ObjList[enBoss].GetCount())
		{
			CBoss* boss = (CBoss *)factory->createProduct(enBoss);
			boss->setZhenboss(false);
			boss->setTimeY(m_time);
			m_ObjList[enBoss].AddTail(boss);  //��CEnemy���͵�CObject��ӵ�m_ObjList
		
		}
	}

	if(GetKey(VK_ESCAPE)==1)
	{
		KillTimer(1);
		btn[3].ShowWindow(SW_SHOW);
		btn[4].ShowWindow(SW_SHOW);
	}

	static int yanchi5 = 3;//��ȡ�����ӳ�
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

	static int yanchi4 = 3;//��ȡ�����ӳ�
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
				for( enemyPos1 = m_ObjList[enEnemy].GetHeadPosition(); ( enemyPos2 = enemyPos1 ) != NULL; )	//GetHeadPosition()�õ�ͷ������
				{
					CEnemy* pObj = (CEnemy*)m_ObjList[enEnemy].GetNext( enemyPos1 );//GetNext(pos1)��pos1��ֵ����Ϊ��һλ�ã�����ֵΪ��ǰ�ڵ�ĵ�ַ������ǰ����Ķ����ַ
					
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
					m_ObjList[enBomb2].AddTail(bomb2);  //��CEnemy���͵�CObject��ӵ�m_ObjList
					pObj->setToBomb2(minPos);
				}
			yanchi4=3;
			}
		}
		yanchi4--;
	}

	//����2�켣
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

	static int yanchi3 = 3;//��ȡ�����ӳ�
	if(GetKey(0x58)==1)					//X ����
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

	static int yanchi2 = 3;//��ȡ�����ӳ�
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

	//���й켣
	if(m_pMe==NULL)	
		return;
	POSITION daPos1,daPos2;
	for( daPos1 = m_ObjList[enDazhao].GetHeadPosition(); ( daPos2 = daPos1 ) != NULL; )
	{
		CDazhao* dazhao = (CDazhao*)m_ObjList[enDazhao].GetNext( daPos1 );
		dazhao->setTimeX(m_time);
	}


	static int yanchi = 3;//��ȡ�����ӳ�
	if(GetKey(VK_SPACE)==1)
	{
		
		if(m_pMe->getDazhao()>0)
		{
			if(yanchi<0)
			{
				m_pMe->setDazhao(m_pMe->getDazhao()-1);
			
				//�����л�
				POSITION ePos1=NULL,ePos2=NULL;
				for(ePos1=m_ObjList[enEnemy].GetHeadPosition();(ePos2=ePos1)!=NULL;)
				{
					CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos1);
					CRect mRect = pEnemy->GetRect();//�л�����
					CRect tmpRect;
		
					//��ӱ�ըЧ��
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

					//ɾ���л�
					m_ObjList[enEnemy].RemoveAt(ePos2);
					delete pEnemy;
					score++;

				}
	
				//�����ӵ�
				POSITION pos1=NULL,pos2=NULL;
				for(pos1=m_ObjList[enBall].GetHeadPosition();(pos2=pos1)!=NULL;)
				{
					CBall* pEnemy = (CBall*)m_ObjList[enBall].GetNext(pos1);
					//ɾ���ӵ�
					m_ObjList[enBall].RemoveAt(pos2);
				}


			yanchi=3;
			}
		}
		yanchi--;
	}

	//����ĸ���������ƶ�ս��
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
	
	//ս�������ӵ�
	if(m_pMe!=NULL && m_pMe->Fired())
	{
		CPoint pt = m_pMe->GetPoint();//���ر�ʾ�ɻ�λ�õ�CPoint
		
		if(m_pMe->getBall()==1){
			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+20,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb1);//���ڵ�	
		}else if (m_pMe->getBall()==2)
		{	
			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+10,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb1);//���ڵ�	
			
			CBomb* bomb2 = (CBomb *)factory->createProduct(enBomb);
			bomb2->SetInfo(pt.x+30,pt.y+10,1);
			m_ObjList[enBomb].AddTail(bomb2);//���ڵ�	
		}else if (m_pMe->getBall()==3)
		{	

			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+10,pt.y+10,3);
			m_ObjList[enBomb].AddTail(bomb1);//���ڵ�	
			
			CBomb* bomb2 = (CBomb *)factory->createProduct(enBomb);
			bomb2->SetInfo(pt.x+20,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb2);//���ڵ�	

			CBomb* bomb3 = (CBomb *)factory->createProduct(enBomb);
			bomb3->SetInfo(pt.x+30,pt.y+10,2);
			m_ObjList[enBomb].AddTail(bomb3);//���ڵ�	
		}
		else if(m_pMe->getBall()==4)
		{	
			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+15,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb1);//��1	
			
			CBomb* bomb2 = (CBomb *)factory->createProduct(enBomb);
			bomb2->SetInfo(pt.x+25,pt.y+10,1);
			m_ObjList[enBomb].AddTail(bomb2);//��1	

			CBomb* bomb3 = (CBomb *)factory->createProduct(enBomb);
			bomb3->SetInfo(pt.x+5,pt.y+10,3);
			m_ObjList[enBomb].AddTail(bomb3);//��2	

			CBomb* bomb4 = (CBomb *)factory->createProduct(enBomb);
			bomb4->SetInfo(pt.x+35,pt.y+10,2);
			m_ObjList[enBomb].AddTail(bomb4);//��2	
		}	
		else if(m_pMe->getBall()==5)
		{	
			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+10,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb1);//��1	
			
			CBomb* bomb2 = (CBomb *)factory->createProduct(enBomb);
			bomb2->SetInfo(pt.x+30,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb2);//��1	
			
			CBomb* bomb5 = (CBomb *)factory->createProduct(enBomb);
			bomb5->SetInfo(pt.x+20,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb5);//���ڵ�	

			CBomb* bomb3 = (CBomb *)factory->createProduct(enBomb);
			bomb3->SetInfo(pt.x+0,pt.y+10,3);
			m_ObjList[enBomb].AddTail(bomb3);//��2	

			CBomb* bomb4 = (CBomb *)factory->createProduct(enBomb);
			bomb4->SetInfo(pt.x+40,pt.y+10,2);
			m_ObjList[enBomb].AddTail(bomb4);//��2	
		}	
		else if(m_pMe->getBall()==6)
		{	
			CBomb* bomb1 = (CBomb *)factory->createProduct(enBomb);
			bomb1->SetInfo(pt.x+15,pt.y+10,0);
			m_ObjList[enBomb].AddTail(bomb1);//��1	
			
			CBomb* bomb2 = (CBomb *)factory->createProduct(enBomb);
			bomb2->SetInfo(pt.x+25,pt.y+10,1);
			m_ObjList[enBomb].AddTail(bomb2);//��1	

			CBomb* bomb3 = (CBomb *)factory->createProduct(enBomb);
			bomb3->SetInfo(pt.x+5,pt.y+10,3);
			m_ObjList[enBomb].AddTail(bomb3);//��2	

			CBomb* bomb4 = (CBomb *)factory->createProduct(enBomb);
			bomb4->SetInfo(pt.x+35,pt.y+10,2);
			m_ObjList[enBomb].AddTail(bomb4);//��2	

			CBomb* bomb5 = (CBomb *)factory->createProduct(enBomb);
			bomb5->SetInfo(pt.x-5,pt.y+10,5);
			m_ObjList[enBomb].AddTail(bomb5);//��3	

			CBomb* bomb6 = (CBomb *)factory->createProduct(enBomb);
			bomb6->SetInfo(pt.x+45,pt.y+10,4);
			m_ObjList[enBomb].AddTail(bomb6);//��3	
		}	
	}	

	if(m_pMe==NULL)
		return;
	//�л������ӵ�
	CPoint PlanePt = m_pMe->GetPoint();
	for(POSITION ePos=m_ObjList[enEnemy].GetHeadPosition();ePos!=NULL;)//�����л�
	{
          CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos);//��ǰ�л�
		  if(!pEnemy->Fired())//����л����ܷ��䣬������һ��
			  continue;
		  CPoint  ePt = pEnemy->GetPoint();

		  BOOL by=FALSE;

		  //�л���ս��ǰ��
		  if(pEnemy->GetMontion()==1 &&ePt.y>PlanePt.y-300&& ePt.y<PlanePt.y) //GetMontion()�õ��л����з���1Ϊ���·ɣ����ҷɻ���y���ڵл���y
		         by=  TRUE;
		  //�л���ս������
		  if(pEnemy->GetMontion()==-1 && ePt.y>PlanePt.y)
				 by=  TRUE;	

		  if(by && ePt.x >= PlanePt.x-200 && ePt.x<PlanePt.x+CMyPlane::PLANE_WIDTH+200)  //�л���Էɻ� ���� �л���x���괦�ڷɻ��Ŀ��֮��
		  {
				CBall* ball = (CBall *)factory->createProduct(enBall);
				ball->SetInfo(ePt.x+10,ePt.y+10,0,0,1);
				m_ObjList[enBall].AddTail(ball);
		  }
	}

	if(m_pMe==NULL)
		return;
	//Boss�����ӵ�
	for(POSITION ePos=m_ObjList[enBoss].GetHeadPosition();ePos!=NULL;)//����boss
	{
          CBoss* pEnemy = (CBoss*)m_ObjList[enBoss].GetNext(ePos);//��ǰboss
		  if(!pEnemy->Fired())//���boss���ܷ��䣬������һ��
			  continue;
		  if(!pEnemy->getZhenboss())
			  continue;
		  CPoint  ePt = pEnemy->GetPoint();
		  pEnemy->setTimeX(m_time);
		  if(!pEnemy->getMove())
		  {
			CBall* ball = (CBall *)factory->createProduct(enBall);
			ball->SetInfo(ePt.x+50,ePt.y+80,0,3,2);
			m_ObjList[enBall].AddTail(ball); //��

			CBall* ball2 = (CBall *)factory->createProduct(enBall);
			ball2->SetInfo(ePt.x+50,ePt.y+80,2,2,2);
			m_ObjList[enBall].AddTail(ball2); //����

			CBall* ball3 = (CBall *)factory->createProduct(enBall);
			ball3->SetInfo(ePt.x+50,ePt.y+80,3,0,2);
			m_ObjList[enBall].AddTail(ball3); //��

			CBall* ball4 = (CBall *)factory->createProduct(enBall);
			ball4->SetInfo(ePt.x+50,ePt.y+80,2,-2,2);
			m_ObjList[enBall].AddTail(ball4); //����

			CBall* ball5 = (CBall *)factory->createProduct(enBall);
			ball5->SetInfo(ePt.x+50,ePt.y+80,0,-3,2);
			m_ObjList[enBall].AddTail(ball5); //��

			CBall* ball6 = (CBall *)factory->createProduct(enBall);
			ball6->SetInfo(ePt.x+50,ePt.y+80,-2,-2,2);
			m_ObjList[enBall].AddTail(ball6); //����

			CBall* ball7 = (CBall *)factory->createProduct(enBall);
			ball7->SetInfo(ePt.x+50,ePt.y+80,-3,0,2);
			m_ObjList[enBall].AddTail(ball7); //��

			CBall* ball8 = (CBall *)factory->createProduct(enBall);
			ball8->SetInfo(ePt.x+50,ePt.y+80,-2,2,2);
			m_ObjList[enBall].AddTail(ball8); //����
		  }
	}

	if(m_pMe==NULL)
		return;
	//СBoss�����ӵ�
	for(POSITION ePos=m_ObjList[enBoss].GetHeadPosition();ePos!=NULL;)//����boss
	{
			CBoss* pEnemy = (CBoss*)m_ObjList[enBoss].GetNext(ePos);//��ǰboss
			if(!pEnemy->Fired())//���boss���ܷ��䣬������һ��
			  continue;
			if(pEnemy->getZhenboss())
			  continue;
			CPoint  ePt = pEnemy->GetPoint2();
			pEnemy->setTimeX(m_time);
			if(!pEnemy->getMove())
			{
		  
			CBall* ball = (CBall *)factory->createProduct(enBall);
			ball->SetInfo(ePt.x+35,ePt.y+80,0,2,2);
			m_ObjList[enBall].AddTail(ball); //��

			CBall* ball2 = (CBall *)factory->createProduct(enBall);
			ball2->SetInfo(ePt.x+25,ePt.y+70,-1,2,2);
			m_ObjList[enBall].AddTail(ball2); //��

			CBall* ball3 = (CBall *)factory->createProduct(enBall);
			ball3->SetInfo(ePt.x+45,ePt.y+70,1,2,2);
			m_ObjList[enBall].AddTail(ball3); //��
			}
	}

	if(m_pMe==NULL)
		return;
	//�Ե���
	POSITION sPos1=NULL,sPos2=NULL;
	CRect smRect = m_pMe->GetRect();	//�ɻ��ľ���
	for(sPos1=m_ObjList[enStrengthen].GetHeadPosition();( sPos2 = sPos1 ) != NULL;) //�����ӵ���
	{
		CStrengthen* strengthen = (CStrengthen*)m_ObjList[enStrengthen].GetNext(sPos1);//��ǰ����
		CRect bRect = strengthen->GetRect();	//�ӵ��ľ���
		CRect tmpRect;
		if(strengthen->getJiemian())
			continue;
		if(tmpRect.IntersectRect(&bRect,smRect)) //�жϷɻ����ӵ��Ƿ��ཻ��IntersectRect()ʹtmpRect�����������о��εĽ�,�������Ϊ�գ��򷵻ط���ֵ�����������Ϊ���򷵻�0��
		{
			if(strengthen->getIndex()==0)//�ӵ���
			{
				if(m_pMe->getBall()<6)
					m_pMe->setBall(m_pMe->getBall()+1);
			}else if(strengthen->getIndex()==1)//������
			{
				m_pMe->setLife(m_pMe->getLife()+1);

				CStrengthen* ball = (CStrengthen *)factory->createProduct(enStrengthen);
				ball->setIndex(1);
				ball->setPoint(GAME_WIDTH*(m_pMe->getLife()/13+1)-40*(m_pMe->getLife()),(m_pMe->getLife()/13)*40,true);
				//ball->setPoint(800-50,0,true);
				m_ObjList[enStrengthen].AddTail(ball);
				
			}else if(strengthen->getIndex()==2)//����
			{
				m_pMe->setDazhao(m_pMe->getDazhao()+1);

			}else if(strengthen->getIndex()==3)//����
			{
					m_pMe->setFanghu(m_pMe->getFanghu()+1);
			}		
				//ɾ������
				m_ObjList[enStrengthen].RemoveAt(sPos2);
				//delete strengthen;
				break;
		}
	}
	
	if(m_pMe==NULL)
		return;
	//�Խ��
	POSITION ggPos1=NULL,ggPos2=NULL;
	CRect ggRect = m_pMe->GetRect();	//�ɻ��ľ���
	for(ggPos1=m_ObjList[enGold].GetHeadPosition();( ggPos2 = ggPos1 ) != NULL;) //�����ӵ���
	{
		CGold* strengthen = (CGold*)m_ObjList[enGold].GetNext(ggPos1);//��ǰ����
		CRect bRect = strengthen->GetRect();	//�ӵ��ľ���
		CRect tmpRect;
		if(tmpRect.IntersectRect(&bRect,ggRect)) //�жϷɻ����ӵ��Ƿ��ཻ��IntersectRect()ʹtmpRect�����������о��εĽ�,�������Ϊ�գ��򷵻ط���ֵ�����������Ϊ���򷵻�0��
		{
			m_ObjList[enGold].RemoveAt(ggPos2);
			score++;
		}
	}
	
	if(m_pMe==NULL)
		return;
	//�л��ӵ�ը��ս��
	POSITION bPos1=NULL,bPos2=NULL;
	CRect mRect = m_pMe->GetRect();	//�ɻ��ľ���
	for(bPos1=m_ObjList[enBall].GetHeadPosition();( bPos2 = bPos1 ) != NULL;) //�����ӵ�
	{
		CBall* pBall = (CBall*)m_ObjList[enBall].GetNext(bPos1);//��ǰ�ӵ�
		CRect bRect = pBall->GetRect();	//�ӵ��ľ���
		CRect tmpRect;
		if(tmpRect.IntersectRect(&bRect,mRect)) //�жϷɻ����ӵ��Ƿ��ཻ��IntersectRect()ʹtmpRect�����������о��εĽ�,�������Ϊ�գ��򷵻ط���ֵ�����������Ϊ���򷵻�0��
		{
			if(m_pMe->getBlood()>1)
			{
					if(!wudi){
						m_pMe->setBlood(m_pMe->getBlood()-1);
					}
				//��ӱ�ըЧ��
				CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
				explosion->SetInfo(mRect.left,mRect.top);
				m_ObjList[enExplosion].AddTail(explosion);
				
				//ɾ���ӵ�
				m_ObjList[enBall].RemoveAt(bPos2);
				delete pBall;
			}
			else
			{
				if(m_pMe->getLife()>0)
				{
					
					m_pMe->setBlood(10);
					m_pMe->setLife(m_pMe->getLife()-1);

					//���½���
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

					//ɾ���ӵ�
					m_ObjList[enBall].RemoveAt(bPos2);
						delete pBall;
				}else
				{
					//��ӱ�ըЧ��
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

					//ɾ���ӵ�
					m_ObjList[enBall].RemoveAt(bPos2);
					//if(pBall!=NULL)
						delete pBall;

					//ɾ��ս��
					delete m_pMe;
					
					m_pMe=NULL;
					break;
				}
			}
			
		}
	}
	if(m_pMe==NULL)
		return;
	//�л� ײ ս��
	POSITION eePos1=NULL,eePos2=NULL;
	CRect ppRect = m_pMe->GetRect();	//�ɻ��ľ���
	for(eePos1=m_ObjList[enEnemy].GetHeadPosition();( eePos2 = eePos1 ) != NULL;) //�����л�
	{
		CEnemy* pBall = (CEnemy*)m_ObjList[enEnemy].GetNext(eePos1);//��ǰ�л�
		CRect bRect = pBall->GetRect();	//�л��ľ���
		CRect tmpRect;
		if(tmpRect.IntersectRect(&bRect,ppRect)) //�жϷɻ����ӵ��Ƿ��ཻ��IntersectRect()ʹtmpRect�����������о��εĽ�,�������Ϊ�գ��򷵻ط���ֵ�����������Ϊ���򷵻�0��
		{
			if(m_pMe->getBlood()>1)
			{
				if(!wudi)//��������޵�
				{
					m_pMe->setBlood(m_pMe->getBlood()-1);
				}
				//ɾ���л�
				pBall->setPoint(0, GAME_HEIGHT+100);

				static int count = rand() %3+2;
					//�����������
					if(count<0)
					{		
						count = rand()%3+2;//+3
						int nDaoju = rand()%4;
						CStrengthen* strengthen  = (CStrengthen *)factory->createProduct(enStrengthen);	//������
						strengthen->setIndex(nDaoju);
						strengthen->setPoint(bRect.left,bRect.top,false);
						m_ObjList[enStrengthen].AddTail(strengthen);  //��CEnemy���͵�CObject��ӵ�m_ObjList
					}
					count--;

			}else
			{
				if(m_pMe->getLife()>0)
				{
					m_pMe->setBlood(10);
					m_pMe->setLife(m_pMe->getLife()-1);
						

					//���½���
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
					//ɾ���л�
					pBall->setPoint(0, GAME_HEIGHT+100);	
				}else
				{
					//ɾ���л�
					pBall->setPoint(0, GAME_HEIGHT+100);

					//ɾ��ս��
					delete m_pMe;
					
					m_pMe=NULL;
					break;
				}
			}
			//��ӱ�ըЧ��
			CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
			explosion->SetInfo(ppRect.left,ppRect.top);
			m_ObjList[enExplosion].AddTail(explosion);
		}
	}
	//��Сboss ײ ս��
	if(m_pMe==NULL)
		return;
	POSITION bbPos1=NULL,bbPos2=NULL;
	CRect bpRect = m_pMe->GetRect();	//�ɻ��ľ���
	for(bbPos1=m_ObjList[enBoss].GetHeadPosition();( bbPos2 = bbPos1 ) != NULL;) //�����л�
	{
		CBoss* pBall = (CBoss*)m_ObjList[enBoss].GetNext(bbPos1);//��ǰ�л�
		CRect bRect = pBall->GetRect();	//boss�ľ���
		CRect tmpRect;
		if(tmpRect.IntersectRect(&bRect,bpRect)) //�жϷɻ����ӵ��Ƿ��ཻ��IntersectRect()ʹtmpRect�����������о��εĽ�,�������Ϊ�գ��򷵻ط���ֵ�����������Ϊ���򷵻�0��
		{
			
			if(m_pMe->getBlood()>1)
			{
				if(!wudi)//��������޵�
				{
					m_pMe->setBlood(m_pMe->getBlood()-1);
				}
				//boss��Ѫ
				if(pBall->getZhenboss())
					pBall->setBlood(pBall->getBlood()-(pBall->getBossBlood()/10));
				//Сboss��Ѫ
				if(!pBall->getZhenboss())
					pBall->setBlood2(pBall->getBlood2()-(pBall->getBossBlood2()/10));
			}else
			{
				if(m_pMe->getLife()>0)
				{
					m_pMe->setBlood(10);
					m_pMe->setLife(m_pMe->getLife()-1);
					
					//���½���

					
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
					//boss��Ѫ
					pBall->setBlood(pBall->getBlood()-(pBall->getBossBlood()/10));	
				}else
				{

					//boss��Ѫ
					pBall->setBlood(pBall->getBlood()-(pBall->getBossBlood()/10));

					//ɾ��ս��
					delete m_pMe;
					
					m_pMe=NULL;
					break;
				}
			}
		
		//��ӱ�ըЧ��
		CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
		explosion->SetInfo(bRect.left,bRect.top);
		m_ObjList[enExplosion].AddTail(explosion);	
		}
	}

	if(m_pMe==NULL)
		return;
	//ս�� ����ը�� �л�
	POSITION mPos1=NULL,mPos2=NULL;
	for(mPos1=m_ObjList[enBomb].GetHeadPosition();(mPos2=mPos1)!=NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(mPos1);
		CRect bRect = pBomb->GetRect();	//��������

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enEnemy].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();//�л�����
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//����л��뵼���ཻ
			{
				
				if(pEnemy->getBlood()>1)
				{
					pEnemy->setBlood(pEnemy->getBlood()-1);
					
					//ɾ������
					CBomb* bomb_t = (CBomb*)m_ObjList[enBomb].GetNext(mPos2);
					bomb_t->SetInfo(0,GAME_HEIGHT+100,0);				//ֱ���Ƶ���Ļ��

					//��ӱ�ըЧ��
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

				}
				else
				{
	
					static int count = rand() %3+2;
					//�����������
					if(count<0)
					{		
						count = rand()%3+2;//+3
						int nDaoju = rand()%4;
						CStrengthen* strengthen  = (CStrengthen *)factory->createProduct(enStrengthen);	//������
						strengthen->setIndex(nDaoju);
						strengthen->setPoint(mRect.left,mRect.top,false);
						m_ObjList[enStrengthen].AddTail(strengthen);  //��CEnemy���͵�CObject��ӵ�m_ObjList
					}
					count--;

					CGold* gold = (CGold *)factory->createProduct(enGold);
					gold->SetInfo(mRect.left+20,mRect.top+10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
					m_ObjList[enGold].AddTail(gold);	
					
					//ɾ���л�
					m_ObjList[enEnemy].RemoveAt(ePos2);
					delete pEnemy;

					break;
				}
			}
		}
	}


	if(m_pMe==NULL)
		return;
	//ս�� ����ը�� Сboss
	POSITION m_xPos1=NULL,m_xPos2=NULL;
	for(m_xPos1=m_ObjList[enBomb].GetHeadPosition();(m_xPos2=m_xPos1)!=NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(m_xPos1);
		CRect bRect = pBomb->GetRect();	//��������

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enBoss].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CBoss* pEnemy = (CBoss*)m_ObjList[enBoss].GetNext(ePos1);
			if(pEnemy->getZhenboss())
				continue;
			CRect mRect = pEnemy->GetRect();//�л�����
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//����л��뵼���ཻ
			{
				if(pEnemy->getBlood2()>1)
				{
					pEnemy->setBlood2(pEnemy->getBlood2()-1);
					
					//ɾ������
					CBomb* bomb_t = (CBomb*)m_ObjList[enBomb].GetNext(m_xPos2);
					bomb_t->SetInfo(0,GAME_HEIGHT+100,0);				//ֱ���Ƶ���Ļ��

					//��ӱ�ըЧ��
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(bRect.left,bRect.top-60);
					m_ObjList[enExplosion].AddTail(explosion);

				}
				else
				{

					static int count = rand() %3+2;

					//�����������
					if(count<0)
					{
						count = rand()%3+2;//+3
						int nDaoju = rand()%4;
						CStrengthen* strengthen  = (CStrengthen *)factory->createProduct(enStrengthen);	//������
						strengthen->setIndex(nDaoju);
						strengthen->setPoint(mRect.left,mRect.top,false);
						m_ObjList[enStrengthen].AddTail(strengthen);  //��CEnemy���͵�CObject��ӵ�m_ObjList
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

					//ɾ���л�
					m_ObjList[enBoss].RemoveAt(ePos2);
					delete pEnemy;

					break;
				}
				
			}
		}
	}


	if(m_pMe==NULL)
		return;
	//���� ը�� �л�
	POSITION daZPos1=NULL,daZPos2=NULL;
	for(daZPos1=m_ObjList[enDazhao].GetHeadPosition();(daZPos2=daZPos1)!=NULL;)
	{
		CDazhao* pBomb = (CDazhao*)m_ObjList[enDazhao].GetNext(daZPos1);
		CRect bRect = pBomb->GetRect();	//��������

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enEnemy].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();//�л�����
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//����л��뵼���ཻ
			{
				
				if(pEnemy->getBlood()>1)
				{
					pEnemy->setBlood(pEnemy->getBlood()-1);
					

					//��ӱ�ըЧ��
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

				}
				else
				{

					static int count = rand() %3+2;

					//�����������
					if(count<0)
					{
						count = rand()%3+2;//+3
						int nDaoju = rand()%4;
						CStrengthen* strengthen  = (CStrengthen *)factory->createProduct(enStrengthen);	//������
						strengthen->setIndex(nDaoju);
						strengthen->setPoint(mRect.left,mRect.top,false);
						m_ObjList[enStrengthen].AddTail(strengthen);  //��CEnemy���͵�CObject��ӵ�m_ObjList
					}
					count--;

					CGold* gold = (CGold *)factory->createProduct(enGold);
					gold->SetInfo(mRect.left+20,mRect.top+10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
					m_ObjList[enGold].AddTail(gold);	
					
					//ɾ���л�
					m_ObjList[enEnemy].RemoveAt(ePos2);
					delete pEnemy;

					break;
				}
			}
		}
	}

	if(m_pMe==NULL)
		return;
	//���� ը�� �ӵ�
	POSITION da_BPos1=NULL,da_BPos2=NULL;
	for(da_BPos1=m_ObjList[enDazhao].GetHeadPosition();(da_BPos2=da_BPos1)!=NULL;)
	{
		CDazhao* pBomb = (CDazhao*)m_ObjList[enDazhao].GetNext(da_BPos1);
		CRect bRect = pBomb->GetRect();	//���о���

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enBall].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CBall* pEnemy = (CBall*)m_ObjList[enBall].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();//�ӵ�����
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//����ӵ�������ཻ
			{
				//��ӱ�ըЧ��
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);
				
					pEnemy->SetInfo(-100,-100,-1,-1,2);//ɾ���ӵ�
			}
		}
	}


	if(m_pMe==NULL)
		return;
	//���� ը�� ��Сboss
	POSITION DaBPos1=NULL,DaBPos2=NULL;
	for(DaBPos1=m_ObjList[enDazhao].GetHeadPosition();(DaBPos2=DaBPos1)!=NULL;)
	{
		CDazhao* pBomb = (CDazhao*)m_ObjList[enDazhao].GetNext(DaBPos1);
		CRect bRect = pBomb->GetRect();	//��������
		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enBoss].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CBoss* pEnemy = (CBoss*)m_ObjList[enBoss].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();//boss����
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//����л��뵼���ཻ
			{
				if(pEnemy->getZhenboss())
				{
					if(pEnemy->getBlood()>1)
					{
						pEnemy->setBlood(pEnemy->getBlood()-1);

						//��ӱ�ըЧ��
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
								showInfo(m_pMemDC,_T("��ϲ��ͨ�أ�"),GAME_WIDTH/2,GAME_HEIGHT/2);
								btn[2].ShowWindow(SW_SHOW);
								btn[3].ShowWindow(SW_SHOW);
							}else
							{
								KillTimer(1);
								showInfo(m_pMemDC,_T("�Ƿ������һ�أ�"),GAME_WIDTH/2,GAME_HEIGHT/2);
								btn[5].ShowWindow(SW_SHOW);
							}
						}else
						{

							//��ӱ�ըЧ��
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
					
						//ɾ��boss
						m_ObjList[enBoss].RemoveAt(ePos2);
						delete pEnemy;
					}
					

				}else
				{
					if(pEnemy->getBlood2()>1)
					{
						pEnemy->setBlood2(pEnemy->getBlood2()-1);
						//��ӱ�ըЧ��
						CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
						explosion->SetInfo(mRect.left,mRect.top);
						m_ObjList[enExplosion].AddTail(explosion);
					}else
					{
							//��ӱ�ըЧ��
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
							

							//ɾ��boss
							m_ObjList[enBoss].RemoveAt(ePos2);
							delete pEnemy;
					
					}
				}
				
				
			}
		
		}
		
	}


	if(m_pMe==NULL)
		return;
	//ս�� ����2ը�� �л�
	POSITION m2Pos1=NULL,m2Pos2=NULL;
	for(m2Pos1=m_ObjList[enBomb2].GetHeadPosition();(m2Pos2=m2Pos1)!=NULL;)
	{
		CBomb2* pBomb = (CBomb2*)m_ObjList[enBomb2].GetNext(m2Pos1);
		CRect bRect = pBomb->GetRect();	//��������

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enEnemy].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CEnemy* pEnemy = (CEnemy*)m_ObjList[enEnemy].GetNext(ePos1);
			CRect mRect = pEnemy->GetRect();//�л�����
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//����л��뵼���ཻ
			{
					static int count= rand() %3+2;
				
					//�����������
					if(count<0)
					{		
						count = rand()%3+2;//+3
						int nDaoju = rand()%3;
						CStrengthen* strengthen  = (CStrengthen *)factory->createProduct(enStrengthen);	//������
						strengthen->setIndex(nDaoju);
						strengthen->setPoint(mRect.left,mRect.top,false);
						m_ObjList[enStrengthen].AddTail(strengthen);  //��CEnemy���͵�CObject��ӵ�m_ObjList
					}
					count--;

					CGold* gold = (CGold *)factory->createProduct(enGold);
					gold->SetInfo(mRect.left+20,mRect.top+10,m_pMe->GetPoint().x,m_pMe->GetPoint().y);
					m_ObjList[enGold].AddTail(gold);	

					//ɾ������
					CBomb2* bomb_t = (CBomb2*)m_ObjList[enBomb2].GetNext(m2Pos2);
					bomb_t->SetInfo(0,GAME_HEIGHT+100,0,0);				//ֱ���Ƶ���Ļ��

					//��ӱ�ըЧ��
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

					
				

					
					//ָ����һ���л�
					CPoint Da_Pt =pEnemy->GetPoint();//��ǰ�л�����
					double x1=Da_Pt.x;
					double y1=Da_Pt.y;
					
					

					POSITION enemyPos1,enemyPos2;
					double juli=10000000000000;
					POSITION minPos=NULL;
					for( enemyPos1 = m_ObjList[enEnemy].GetHeadPosition(); ( enemyPos2 = enemyPos1 ) != NULL; )	//GetHeadPosition()�õ�ͷ������
					{
						CEnemy* pObj = (CEnemy*)m_ObjList[enEnemy].GetNext( enemyPos1 );//GetNext(pos1)��pos1��ֵ����Ϊ��һλ�ã�����ֵΪ��ǰ�ڵ�ĵ�ַ������ǰ����Ķ����ַ
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
						CBomb2* bomb2 = (CBomb2 *)factory->createProduct(enBomb2);//��ָ�л�
						bomb2->SetInfo(Da_Pt.x,Da_Pt.y,Da_Pt.x,0);
						bomb2->setToEnemy(minPos);
						m_ObjList[enBomb2].AddTail(bomb2);  //��CEnemy���͵�CObject��ӵ�m_ObjList
						pObj->setToBomb2(minPos);
					}
					
					//ɾ���л�
					m_ObjList[enEnemy].RemoveAt(ePos2);
					delete pEnemy;
					break;
				
			}
		}
	}
	
	if(m_pMe==NULL)
		return;
	//ս�� ����ը�� boss
	POSITION boPos1=NULL,boPos2=NULL;
	for(boPos1=m_ObjList[enBomb].GetHeadPosition();(boPos2=boPos1)!=NULL;)
	{
		CBomb* pBomb = (CBomb*)m_ObjList[enBomb].GetNext(boPos1);

		CRect bRect = pBomb->GetRect();	//��������

		POSITION ePos1=NULL,ePos2=NULL;
		for(ePos1=m_ObjList[enBoss].GetHeadPosition();(ePos2=ePos1)!=NULL;)
		{
			CBoss* pEnemy = (CBoss*)m_ObjList[enBoss].GetNext(ePos1);
			if(!pEnemy->getZhenboss())
				continue;
			CRect mRect = pEnemy->GetRect();//boss����
			CRect tmpRect;
			if(tmpRect.IntersectRect(&bRect,mRect))	//����л��뵼���ཻ
			{
				if(pEnemy->getBlood()>1)
				{
					pEnemy->setBlood(pEnemy->getBlood()-1);

					//ɾ������
					CBomb* bomb_t = (CBomb*)m_ObjList[enBomb].GetNext(boPos2);
					bomb_t->SetInfo(0,GAME_HEIGHT+100,0);				//ֱ���Ƶ���Ļ��

					//��ӱ�ըЧ��
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(bRect.left-33,bRect.top-33);
					m_ObjList[enExplosion].AddTail(explosion);


				}else
				{
					//��ӱ�ըЧ��
					CExplosion* explosion = (CExplosion *)factory->createProduct(enExplosion);
					explosion->SetInfo(mRect.left,mRect.top);
					m_ObjList[enExplosion].AddTail(explosion);

					//ɾ��boss
					m_ObjList[enBoss].RemoveAt(ePos2);
					delete pEnemy;

					score+=100;
					if(mission>5)
					{
						KillTimer(1);
						showInfo(m_pMemDC,_T("��ϲ��ͨ�أ�"),GAME_WIDTH/2,GAME_HEIGHT/2);
						btn[2].ShowWindow(SW_SHOW);
						btn[3].ShowWindow(SW_SHOW);
					}else
					{
						KillTimer(1);
						showInfo(m_pMemDC,_T("�Ƿ������һ�أ�"),GAME_WIDTH/2,GAME_HEIGHT/2);
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
	//ˢ����Ϸ֡����: ���ڴ�DC�ϻ�ͼ
	UpdateFrame(m_pMemDC);
	AI();
	m_time +=3;
	CView::OnTimer(nIDEvent);
}


