#pragma once

#include "stdafx.h"
#include "CButton.h"
#include "CToolTipCtrl.h"
#include "CFont.h"

class  CToolButton : public CButton
{

public:
	CToolButton();
	virtual ~CToolButton();
public:
	virtual BOOL Create( HWND hwndParent,UINT nID=0L,LPCTSTR lpWindowName=NULL,
					 DWORD dwStyle=WS_VISIBLE,CRect rc=CRect(0L,0L,0L,0),LPVOID lpParam=NULL);
	void SetToolTip(LPCTSTR szToolTip);
	void SetCaption(LPCTSTR szCaption);
	void SethIcon(HICON hIcon);
	void SetColor(COLORREF clColor);
	void RecalSize();
	void ShowDark(BOOL bShow);
	CSize GetSizeButton();
	void ShowMenu();
	void SetScrollButton(BOOL bScroll=TRUE);
	void SetSimpleButton(BOOL bSimple=TRUE){m_bSimple=bSimple;};
	void SetFontColor(COLORREF clrFont);

protected:

	virtual BOOL OnDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	BOOL OnEraseBkgnd(HDC pDC);
	void OnTimer(UINT nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void PreSubClassWnd();
	BOOL OnSysColorChange( );
	BOOL OnSetCursor(HWND hWnd, UINT nHitTest, UINT message);
	BOOL OnLButtonDown(UINT nFlags, CPoint pt);
	
protected:
	CToolTipCtrl m_toolTip;
	HICON		 m_Icon;
	CSize		 m_SizeImage;
	CSize		 m_SizeText;
	TCHAR		 m_szText[128];
	COLORREF	 m_clColor;
	BOOL		 m_bMouserOver;
	BOOL		 m_ReposWindow;
	CSize		 m_szButton;
	BOOL		 m_bShowDark;
	BOOL		 m_ScrollButton;	
	COLORREF	 m_clrFont;
	BOOL		 m_bSimple;
	BOOL		 m_bMousePress;
	CFont*		 cfont;
public:
	HMENU		 m_hMenu;
protected:


	BEGIN_MSG_MAP()
		ON_WM_SETCURSOR(OnSetCursor)
		ON_WM_SYSCOLORCHANGE(OnSysColorChange)
		ON_WM_ERASEBKGND(OnEraseBkgnd)
		ON_WM_TIMER(OnTimer)
		ON_WM_LBUTTONDOWN(OnLButtonDown) 
	END_MSG_MAP(CButton)
public:
	
};

