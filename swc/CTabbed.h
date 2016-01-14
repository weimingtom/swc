#pragma once

#include "stdafx.h"
#include "CContainer.h"
#include "CToolButton.h"
#include "CImageCtrl.h"
#include "CSize.h"
#include "CFont.h"
#include "CWorkTab.h"

#define SCROLLCLOSE 0x886

class  CTabbed :	public CContainer
{
	enum ExtTab{NORMAL_TAB=0,COMBO_TAB=1};
public:
	CTabbed(void);
	virtual ~CTabbed(void);	
protected:
	CToolButton m_toolBtn[2];
	CToolButton m_toolBtnC;
	CImageCtrl   m_img;
	CSize        m_sizeBtn;
	int			 m_nDif;
	ExtTab		 m_ExtTab;
	CFont		m_cfontNormal;
	CFont		m_cfontBold;
	int			m_count;
	int			m_doc;
public:

	void  virtual Drawtabs(CGDI* dc);
	void  SetExtileExt(ExtTab= NORMAL_TAB);
	void  AddNewtab(CWin* pParent,UINT nID, LPCSTR lpMsg=NULL);
	CSize GetSizeButton();
	void  OnScrollLeft(WPARAM wParam, LPARAM lParam, HWND handle);
	void  OnScrollRight(WPARAM wParam, LPARAM lParam, HWND handle);
	void  virtual OnScrollClose(WPARAM wParam, LPARAM lParam, HWND handle);
	BOOL OnSysColorChange( );
	int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	 BOOL OnEraseBkgnd(HDC hDC );
public:

	BEGIN_MSG_MAP()
	ON_WM_CREATE(OnCreate)
	ON_WM_SYSCOLORCHANGE(OnSysColorChange)
	ON_COMMAND(SCROLLLEFT,OnScrollLeft)
	ON_COMMAND(SCROLLRIGHT,OnScrollRight)
	ON_COMMAND(SCROLLCLOSE,OnScrollClose)
	ON_WM_ERASEBKGND(OnEraseBkgnd)
	END_MSG_MAP(CContainer)
};
