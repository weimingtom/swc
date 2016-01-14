#pragma once

#include "stdafx.h"
#include "CWin.h"
#include "CDockPanelBase.h"
#include "CContainer.h"
#include "NewBValArray.h"
#include "CArray.h"
#include "CRect.h"

class CDockStruct
{
public:
	CDockStruct(CWin* pParent)
	{
		if (!HIWORD(pParent)) return;
		m_WinDock=pParent;
		m_rectPost=CRect(0,0,0,0);

	}
public:
	CRect m_rectPost;
	CWin* m_WinDock;

};

class CMiniDock;
class DockManager : public CWin
{

public:
	DockManager();
	~DockManager();
	
public:
  CMiniDock* m_MiniFloat;

public:
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWin* pParentWnd, UINT nID);
	void AddWindow(CWin* pWin,int nPos=-1);
	UINT AddWindow(CDockPanelBase* pWin,UINT dlgCtrl=NULL,int nPos=-1);
	void FloatWindow(CWin *pWin);
	void DeleteWindow(int pWin);
	void RecalLayout(BOOL bReSize=FALSE);
	void DrawSppliter(CRect rc);
	void DrawSppliterInside(CPoint cp);
	BOOL IsFloating();
	BOOL IsVertical();
	BOOL IsHorz();
	BOOL IsLeft();
	BOOL IsRight();
	int  FindItem(HWND hWnd);
	CWin* GetNumWnd(int m_numWin); 
	int  GetNumChild();
	CSize Getsize();
	void CalSizeWindow();
	void EveryWindowsInsert();
	int  GetNumVisibleWindows();
	void ResizeWindow(CPoint cp);
	int GetFirstVisible();
	int GetLastVisible();
	CContainer*  GetWichContainerIsTheParent(HWND hWnd);
public:
	 BOOL OnPaint(HDC hDC);
	 BOOL OnLButtonDown(UINT nFlags, CPoint pt);
	 BOOL OnRButtonDown(UINT nFlags, CPoint pt);
	 BOOL OnSize(UINT nType, int cx, int cy);
	 BOOL OnEraseBkgnd(HDC hDC );
	 int  OnDestroy();
	 int  OnCreate(LPCREATESTRUCT lpCreateStruct); 
     BOOL OnSetCursor(HWND hWnd, UINT nHitTest, UINT message);
	 void OnNcMouseMove(UINT nHitTest, CPoint point);	
	 UINT OnNcHitTest(CPoint cp);
	 BOOL OnNcCalcSize(BOOL bCalcValidRects,LPNCCALCSIZE_PARAMS lpncsp);
	 void OnNcPaint(HRGN hRgn);
	 void OnTimer(UINT nIDEvent);
	 void OnNcLButtonDown(UINT nHitTest, CPoint point);
	 void OnNcLButtonUp(UINT nHitTest, CPoint point);
	 BOOL OnLButtonUp(UINT nFlags, CPoint pt);
	 void OnMouseMove(UINT nHitTest, CPoint point);
	 BOOL ShowMe(){return m_ShowMe;};
	 CContainer* PointIsInCaption(CPoint cp);
	 int PointInDock(CPoint cp, CRect& rc, int& pos);
protected:

   CArray m_DockWindows; 
   NewBValArray<CRect> m_Splits; 
  DWORD			m_Aling;		//Actual Aling
  DWORD			m_lastAling;	//before float where was the windows
  DWORD			m_Side;
  BOOL			m_Visible;		//Is the Windows visible 
  CMiniDock*	m_MiniDock;		
  CRect			m_Splitter;	
  CRect			m_OldSplitter;
  CSize			m_size;
  CWin*			m_pParent;
  int			m_NumWins;
  int			m_NumSep;
  BOOL			m_DragSplitter;
  BOOL			m_DragSplitterInside;
  CPoint		m_ptStartPos;
  CPoint		m_ptOldPos;
  int			m_SplitMove;
  BOOL			m_ShowMe;
  

protected:

BEGIN_MSG_MAP()
	ON_WM_ERASEBKGND(OnEraseBkgnd)
	ON_WM_PAINT(OnPaint)
	ON_WM_CREATE(OnCreate)
	ON_WM_SIZE(OnSize)
	ON_WM_LBUTTONDOWN(OnLButtonDown)
	ON_WM_RBUTTONDOWN(OnRButtonDown)
	ON_WM_DESTROY(OnDestroy)
	ON_WM_SETCURSOR(OnSetCursor)
	ON_WM_NCCALCSIZE(OnNcCalcSize)
	ON_WM_NCPAINT(OnNcPaint)
	ON_WM_NCHITTEST(OnNcHitTest);
	ON_WM_LBUTTONDOWN(OnLButtonDown)
	ON_WM_NCLBUTTONDOWN(OnNcLButtonDown)
	ON_WM_NCMOUSEMOVE(OnNcMouseMove)
	ON_WM_TIMER(OnTimer)
	ON_WM_NCLBUTTONUP(OnNcLButtonUp)
	ON_WM_LBUTTONUP(OnLButtonUp)
	ON_WM_MOUSEMOVE(OnMouseMove)
END_MSG_MAP(CWin)

};
