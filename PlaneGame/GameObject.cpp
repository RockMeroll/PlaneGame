// GameObject.cpp : 实现文件
//

#include "stdafx.h"
#include "GameObject.h"


// CGameObject


CGameObject::CGameObject(int x,int y):m_ptPos(x,y)//定义构造函数
{
		
}

CGameObject::~CGameObject()
{
}

BOOL CGameObject::LoadImage(CImageList& imgList,UINT bmpID,COLORREF crMask,int cx,int cy,int nInitial)
{
	CBitmap bmp;
	if(!bmp.LoadBitmap(bmpID))		//加载指定的位图资源
		return FALSE;
	if(!imgList.Create(cx, cy, ILC_COLOR24|ILC_MASK, nInitial, 0))	//cx ,cy图片的实际像素宽与高;第三个参数：创建图像列表的类型；第四个：创建ImageList初始包括的图像个数；第五个：空间不够时增量
		return FALSE;
	imgList.Add(&bmp, crMask); //向传过来的imgList中添加根据bmpID找到的新图像。crMask:用于生成掩码,此颜色每像素的位图特定的已更改为黑色，并在掩码中对应的位设置为一个。
	return TRUE;
}

