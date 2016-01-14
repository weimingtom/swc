#pragma once

#include "stdafx.h"
#include "CApp.h"

class CDockPanelBase : public CWin
{
public:
	CRect rcPosition;
	UINT  uAling;
	int	  iLasPosition;
	BOOL  bIsPartOfTabbed;
	BOOL  bIsShow;
	UINT   m_IdCtrlParent;	

public:
	CDockPanelBase(HWND hWnd=NULL)
	{
		m_hWnd=hWnd;
		rcPosition=CRect(0,0,0,0);
		bIsShow=TRUE;
		uAling=-1;
		iLasPosition=-1;
		bIsPartOfTabbed=FALSE;
		m_IdCtrlParent=0;
		
	}


public:

	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWin* pParentWnd, UINT nID,LPCTSTR lpCaption=_T("")) 
	{
		LPCTSTR lpclassname=RegisterDefaultClass(NULL,WS_CHILD|WS_VISIBLE);
		return CWin::Create(lpclassname, lpCaption, dwStyle, rect, pParentWnd->GetSafeHwnd(), nID);
	}


	virtual BOOL OnCreate(LPCREATESTRUCT lpCreateStruct)
	{
		return TRUE;
	}

	virtual BOOL OnSize(UINT nType,long x, long y)
	{
		UpdatePanel();
		Invalidate();
		UpdateWindow();
		Default();
		return TRUE;
	}

	virtual BOOL OnPaint(HDC hDC)
	{
		Default();
		return TRUE;
	}

	virtual void UpdatePanel()
	{
		
	}

	 virtual void SaveConfig()
	 {
	    CRect rc;
		TCHAR szSection[512];
		wsprintf(szSection, _T("%s-BaseDockBar-%d"), theApp->m_lpBuffer,GetDlgCtrlID());
		GetWindowRect(rc);
		WriteInteger(rc.left,szSection, _T("Left"));
		WriteInteger(rc.right,szSection, _T("Right"));
		WriteInteger(rc.top,szSection, _T("Top"));
		WriteInteger(rc.bottom,szSection, _T("Bottom"));
		WriteInteger(bIsShow,szSection, _T("IsVisible"));
		WriteInteger(uAling,szSection, _T("Aling"));
		WriteInteger(iLasPosition,szSection, _T("LasPosition"));
		WriteInteger(bIsPartOfTabbed,szSection, _T("IsPartofTabbed"));
		WriteInteger(m_IdCtrlParent,szSection, _T("CtrlIDParent"));

	 }

	 virtual  void GetConfig()
	 {

		TCHAR szSection[512];
		wsprintf(szSection, _T("%s-BaseDockBar-%d"), theApp->m_lpBuffer,GetDlgCtrlID());
		
		rcPosition.left=ReadInteger(szSection, _T("Left"));
		rcPosition.right=ReadInteger(szSection, _T("Right"));
		rcPosition.top=ReadInteger(szSection, _T("Top"));
		rcPosition.bottom=ReadInteger(szSection, _T("Bottom"));
		bIsShow=(BOOL)ReadInteger(szSection, _T("IsVisible"));
		uAling=(UINT)ReadInteger(szSection, _T("Aling"));
		iLasPosition=(BOOL)ReadInteger(szSection, _T("LasPosition"));
		bIsPartOfTabbed=(BOOL)ReadInteger(szSection, _T("IsPartofTabbed"));
		m_IdCtrlParent=(UINT)ReadInteger(szSection, _T("CtrlIDParent"));

	   	if (rcPosition.left <0 || rcPosition.right < 0 || rcPosition.bottom <= 0 || rcPosition.right <= 0)
			rcPosition=CRect(0,0,120,120);
		
		
	 }

	 virtual BOOL OnDestroy()
	 {
		 SaveConfig();
		 return TRUE;
	 }

BEGIN_MSG_MAP()
	 ON_WM_CREATE(OnCreate)
	 ON_WM_SIZE(OnSize) 
	 ON_WM_PAINT(OnPaint)
	
END_MSG_MAP(CWin)
};
