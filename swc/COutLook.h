#pragma once

#include "stdafx.h"
#include "CToolButton.h"
#include "CRect.h"
#include "CWin.h"
#include "CImageCtrl.h"
#include "CArray.h"
#include "CSize.h"
#include "CRect.h"
#include "CPoint.h"

class COutLook;

class  CItems
{
public:
	CItems(COutLook* m_pParent,HICON m_hIcon,UINT Cmd,LPCSTR m_Message,LPCSTR m_ToolTip=_T(""), BOOL bTypeOutLook=TRUE);
public:
	CToolButton		   m_bt;
	int				   m_btipo;
	LPSTR			   m_szMessage;	
};

class   COutLook : public CWin
{
	friend class CItems;
public:
	COutLook();
	virtual ~COutLook();

public:

	virtual BOOL Create(DWORD dwStyle,  CRect& rect, CWin* pParentWnd, UINT nID) ;
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:
	void	AddItem(UINT Cmd,LPCSTR m_szCaption,int nIndex,LPCSTR m_ToolTip=_T(""));
	void	SetImageList(UINT nBitmapID, int cx, int nGrow, COLORREF crMask);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	void	RecalLayout();
	void	SetTypeLook(BOOL bNormal=TRUE)
	{
		m_TypeOutLook=bNormal;
	}
	
protected:
	CImageCtrl 	m_imageList;
	CArray 	m_ArrayButtons;
	CSize      	m_sizeImage;
	int		m_ActualButtonPres;
	int        	m_ultimoBotonResal;
	int        	m_NumBottoms;
	COLORREF  m_cbkg;	
	int		m_mouseMove;
	int        	m_Avance;
	CRect	m_rectArrowUp;
	CRect	m_rectArrowDown;	
	BOOL	   	m_iDrawFrameUp;		
	BOOL       	m_iDrawFrameDown;	    
	UINT	   	mnID;
	BOOL	   	m_bPressU;
	BOOL	   	m_bPressD;
	HDC		hdc;
	BOOL	   	m_bIsXp;
	BOOL		m_TypeOutLook;

	 BOOL OnPaint(HDC hDC);
	 BOOL OnLButtonDown(UINT nFlags, CPoint pt);
	 BOOL OnLButtonUp(UINT nFlags, CPoint pt);
	 BOOL OnSize(UINT nType, int cx, int cy);
	 BOOL OnSysColorChange();
	 void  OnTimer(UINT nIDEvent);
	 BOOL OnEraseBkgnd(HDC hDC );
	 int OnDestroy();
	 
protected:
BEGIN_MSG_MAP()
	ON_WM_PAINT(OnPaint)
	ON_WM_LBUTTONDOWN(OnLButtonDown)
	ON_WM_LBUTTONUP(OnLButtonUp)
	ON_WM_SIZE(OnSize)
	ON_WM_SYSCOLORCHANGE(OnSysColorChange)
	ON_WM_TIMER(OnTimer)
	ON_WM_ERASEBKGND(OnEraseBkgnd)
	ON_WM_DESTROY(OnDestroy)
END_MSG_MAP(CWin)	
};
