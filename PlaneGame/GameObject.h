#pragma once

//游戏对象的父类
class CGameObject : public CObject
{
public:

	CGameObject(int x=0,int y=0);	//构造函数 默认值x,y,=0
	virtual ~CGameObject();
	
	//绘制对象
	virtual BOOL Draw(CDC* pDC,BOOL bPause)=0;//虚函数

	//获得矩形区域
	virtual CRect GetRect()=0;//虚函数

	//获得左上角坐标
	CPoint GetPoint()
	{
		return m_ptPos;
	}


protected:
	//加载图像声明
	static BOOL LoadImage(CImageList& imgList,UINT bmpID,COLORREF crMask,int cx,int cy,int nInitial);
protected:
	//物体的位置
	CPoint  m_ptPos;
};


