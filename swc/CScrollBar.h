#pragma once

#include "stdafx.h"
#include "CWin.h"

class CScrollBar : public CWin
{
public:
	CScrollBar(HWND hWnd = NULL) : CWin(hWnd) { }
	virtual ~CScrollBar(){};

public:
	BOOL Create( HWND hwndParent,UINT nID=0L,LPCTSTR lpWindowName=NULL,
	   DWORD dwStyle=WS_VISIBLE,CRect rc=CRect(0L,0L,0L,0),LPVOID lpParam=NULL)
	{
		BOOL rs= CWin::Create(_T("scrollbar"),lpWindowName,
		   dwStyle,rc,hwndParent,nID,lpParam);
		SubclassWnd(GetSafeHwnd());
		return rs;
	}

	
	void GetRange(int& nMin, int& nMax) 
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( SBM_GETRANGE, ( WPARAM )&nMin, ( LPARAM )&nMax );
	}
	int GetPos() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return ( int )SendMessage( SBM_GETPOS, 0L, 0L );
	}
	int SetPos(int nPos, BOOL bRedraw = TRUE)
	{
		ASSERT(::IsWindow(m_hWnd));
		return ( int )SendMessage( SBM_SETPOS, nPos, bRedraw );
	}
	
	void SetRange(int nMin, int nMax, BOOL bRedraw = TRUE)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( bRedraw ? SBM_SETRANGEREDRAW : SBM_SETRANGE, nMin, nMax );
	}
	
	int SetInfo(LPSCROLLINFO lpScrollInfo)
	{
		ASSERT(::IsWindow(m_hWnd));
		return ( BOOL )SendMessage( SBM_GETSCROLLINFO, 0L, ( LPARAM )lpScrollInfo );
	}
	

	BOOL EnableScrollBar(int nFlags = ESB_ENABLE_BOTH)
	{
		ASSERT(::IsWindow(m_hWnd));
		return ( BOOL )SendMessage( SBM_ENABLE_ARROWS, nFlags,0L );	
	}
};
