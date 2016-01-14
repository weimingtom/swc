#pragma once

#include "stdafx.h"
#include "CMiniFrame.h"

class CMiniDock: public CMiniFrame
{
public:
	CMiniDock(HWND hWnd=NULL): CMiniFrame(hWnd)
	{
		m_Drag=FALSE;
		bDrawNormal=FALSE;
		bDrawTab=FALSE;
		bDrawNormalDock=FALSE;
	}
	~CMiniDock(){}

protected:
	BOOL m_Drag;
	CRect m_Oldrc; //Old Rect Normal float
	CRect m_OldrcTab; //Old Rect Tab
	CRect m_OldrcDock; //Old Rect Docking
	CRect mWin;
	BOOL	bDrawNormal;
	BOOL	bDrawTab;
	BOOL	bDrawNormalDock;

	

public:

	virtual void OnNcLButtonDown(UINT nHitTest, CPoint point);
	
	virtual void OnNcLButtonUp(UINT nHitTest, CPoint point);
	
	virtual void OnNcMouseMove(UINT nHitTest, CPoint point);
	virtual void OnMouseMove(UINT nHitTest, CPoint point);
	virtual void OnNcButtonDblClk(UINT nHitTest, CPoint point);
	virtual void OnLButtonUp(UINT nHitTest, CPoint point);
	virtual void OnWindowPostChanging(LPWINDOWPOS lpWindowsPos);
	virtual void OnRButtonDown(UINT nHitTest, CPoint point);
  	virtual void DrawFrame(CRect rc, BOOL bDrawTab=0);
	void DrawNormal();
	void DrawDock(CRect rc,CPoint point,DockManager* mDock, UINT bHorz);
	virtual void OnKeyDown(int iVkey, DWORD dTime); 
};
