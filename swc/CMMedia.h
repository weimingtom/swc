#pragma once

#include "stdafx.h"
#include "CFolder.h"
#include "CImageCtrl.h"
#include "CToolButton.h"
#include "CGDI.h"

#define SCLOSE  0x9998

class CMMedia : public CFolder
{
public:
	CMMedia();
	virtual ~CMMedia();

protected:	
	CImageCtrl	m_img;
	CToolButton m_toolBtnC;
	virtual void DrawFolder(CFolderBar* cfb,Style m_Style);
	int  OnCreate(LPCREATESTRUCT lpCreateStruct); 

public:
	BOOL OnPaint(HDC hDC);
	BOOL OnLButtonDown(UINT nFlags, CPoint pt);
	void OnMouseMove(UINT nFlags, CPoint pt);
	BOOL OnSize(UINT nType, int cx, int cy);
	BOOL OnEraseBkgnd(HDC hDC );
	BOOL OnLButtonDblClk(UINT nFlags, CPoint pt);
	BOOL OnLButtonUp(UINT nFlags, CPoint pt);
	void DrawGripper(CGDI* dc,CRect rcWin,BOOL bHorz=TRUE);
	void OnCloseBtn(WPARAM wParam, LPARAM lParam, HWND handle);

protected:
BEGIN_MSG_MAP()
	ON_WM_LBUTTONDOWN(OnLButtonDown)
	ON_WM_MOUSEMOVE(OnMouseMove)
	ON_WM_SIZE(OnSize)
	ON_WM_ERASEBKGND(OnEraseBkgnd)
	ON_WM_LBUTTONUP(OnLButtonUp)
	ON_WM_CREATE(OnCreate)
	ON_COMMAND(SCLOSE,OnCloseBtn)
END_MSG_MAP(CFolder)	
};
