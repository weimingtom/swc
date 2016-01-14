#pragma once

#include "stdafx.h"
#include "CWin.h"

class CButton : public CWin
{
	public:
		CButton(HWND hWnd=NULL) :CWin(hWnd) {}
		virtual ~CButton(){};
	public:
		
	
	BOOL Create( HWND hwndParent,UINT nID=0L,LPCTSTR lpWindowName=NULL,
	   DWORD dwStyle=WS_VISIBLE,CRect rc=CRect(0L,0L,0L,0),LPVOID lpParam=NULL)
	{
		BOOL rs= CWin::Create(_T("button"),lpWindowName,
		   dwStyle,rc,hwndParent,nID,lpParam);
		SubclassWnd(GetSafeHwnd());
		return rs;
	}
	
	int GetCheck() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage(BM_GETCHECK, 0L, 0L);
	}
	
	void SetCheck(int nCheck)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage(BM_SETCHECK, nCheck, 0L);
	}
	
	
	int GetState() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage(BM_GETSTATE, 0L, 0L);
	}
	
	void SetState(BOOL bState)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage(BM_SETSTATE, bState, 0L);
	}
	
	int GetButtonStyle()
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)GetWindowLong(m_hWnd,GWL_STYLE) & 0xff;
	}
	void SetButtonStyle(UINT style, BOOL redraw = TRUE)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage(BM_SETSTYLE, style, (LPARAM)redraw);
	}

	HICON GetIcon() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HICON)SendMessage(BM_GETIMAGE, IMAGE_ICON, 0L);
	}
	HICON SetIcon(HICON hIcon)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HICON)SendMessage(BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIcon);
	}
     
	int GetCheckBox() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return ( int ) SendMessage( BM_GETCHECK, 0L, 0L );
	}
	
	void SetCheckBox( UINT nCheck = BST_CHECKED )
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( BM_SETCHECK, nCheck,0L );
	}

	BOOL IsCheckBox()
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL) GetCheck() == BST_CHECKED;
	}
	
	virtual BOOL OnDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
	{
		return FALSE;
	}	
};
