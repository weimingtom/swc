#pragma once

#include "stdafx.h"
#include "CFrame.h"

class CMiniFrame : public CFrame
{
protected:
	CWin* pParent;
	CPoint m_oldPost;
	

public:
	CMiniFrame(HWND hWnd=NULL): CFrame(hWnd)
	{
		
	}
	~CMiniFrame(){ }
public:
	

	virtual BOOL Create(CWin* pParentWnd, UINT nID, CRect& rc, CWin* pControls, DWORD dwStyle=WS_POPUP|WS_CAPTION|WS_CLIPSIBLINGS |WS_SYSMENU);
	
	virtual BOOL PreCreateWindow(LPCREATESTRUCT cs)
	{
		if (cs->style & WS_CAPTION)
			cs->dwExStyle |= WS_EX_TOOLWINDOW;
		cs->dwExStyle &= ~(WS_EX_CLIENTEDGE);
		return TRUE;
		
	}
	
	

	void OnNcDestroy(LPCREATESTRUCT lpst)
	{
		delete this;
	}
	

	virtual BOOL OnDestroy();
	

	BOOL OnSize(UINT nType,long x, long y) 
	{
	 	UpdateFrame();
		return TRUE;
	 }
	
virtual UINT OnNcHitTest(CPoint cp)
{
	
	return Default();
}

 virtual void OnNcLButtonDown(UINT nHitTest, CPoint point)
 {
	Default();
 }

 virtual void OnNcLButtonUp(UINT nHitTest, CPoint point)
 {
	Default();
 }

 virtual void OnMouseMove(UINT nHitTest, CPoint point)
 {
	Default();
 }
 virtual void OnNcMouseMove(UINT nHitTest, CPoint point)
 {
	Default();	
 }

 virtual void OnNcButtonDblClk(UINT nHitTest, CPoint point)
 {
	Default();
 }

 virtual void OnLButtonUp(UINT nHitTest, CPoint point)
 {
	Default();
 }
 virtual void OnRButtonDown(UINT nHitTest, CPoint point)
 {
	Default();
 }

 virtual void OnWindowPostChanging(LPWINDOWPOS lpWindowsPos)
 {
	 Default();
 }

 virtual void OnKeyDown(int iVkey, DWORD dTime)
 {
	 Default();
 }

BEGIN_MSG_MAP()
	ON_WM_NCDESTROY(OnNcDestroy)
	ON_WM_DESTROY(OnDestroy);
	ON_WM_SIZE(OnSize) 
	ON_WM_NCHITTEST(OnNcHitTest)
	//ON_WM_NCMOUSEMOVE(OnNcMouseMove)
	ON_WM_MOUSEMOVE(OnMouseMove)
	ON_WM_NCLBUTTONDOWN(OnNcLButtonDown)
	ON_WM_NCLBUTTONUP(OnNcLButtonUp)
	ON_WM_LBUTTONUP(OnLButtonUp)
	ON_WM_RBUTTONDOWN(OnRButtonDown)
	ON_WM_NCLBUTTONDBLCLK(OnNcButtonDblClk)
	ON_WM_KEYDOWN(OnKeyDown)
//	ON_WM_WINDOWPOSCHANGING(OnWindowPostChanging)
END_MSG_MAP(CFrame)
};
