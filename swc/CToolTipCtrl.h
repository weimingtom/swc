#pragma once

#include "stdafx.h"
#include "ComControlEX.h"
#include "CApp.h"

class CToolTipCtrl : public ComControlEX
{
public:
	CToolTipCtrl(HWND hWnd=NULL){m_hWnd=hWnd;}
	~CToolTipCtrl(){};
public:
	BOOL Create(HWND hWndParent,UINT uID=BASE_TOOLTIPS_CLASS)
	{		
		BOOL bRes = CreateEx(0L, TOOLTIPS_CLASS, NULL,
						0L,CRect(0L, 0L, 0L, 0),hWndParent, uID, NULL);
		SubclassWnd(GetSafeHwnd());
		return bRes;
	}


	void GetText(LPTOOLINFO lpToolInfo) 
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_GETTEXT, 0L, (LPARAM)&lpToolInfo);
	}
	

	BOOL GetToolInfo(LPTOOLINFO lpToolInfo) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TTM_GETTOOLINFO, 0L, (LPARAM)lpToolInfo);
	}
	
	void SetToolInfo(LPTOOLINFO lpToolInfo)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_SETTOOLINFO, 0L, (LPARAM)lpToolInfo);
	}
	void SetToolRect(LPTOOLINFO lpToolInfo)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_NEWTOOLRECT, 0L, (LPARAM)lpToolInfo);
	}
	

	BOOL SetToolRect(HWND hWnd, LPCRECT lpRect, UINT uID )
	{
		
		TOOLINFO tti;
		ASSERT(m_hWnd);
		ASSERT(lpszText != NULL);
		
		memset(&tti,0x00,sizeof(TOOLINFO));
		tti.cbSize=sizeof(TOOLINFO);
		tti.hwnd=hWnd;
		tti.uFlags=0;
		tti.uId=uID;
		tti.lpszText = (LPTSTR)NULL;
		if (lpRect != NULL)
			memcpy(&tti.rect, lpRect, sizeof(RECT));
		return (BOOL) ::SendMessage(m_hWnd, TTM_NEWTOOLRECT, 0, (LPARAM)&tti);

	}


	int GetToolCount() 
	{
		if (!::IsWindow(m_hWnd)) return -1;
		return (int)SendMessage( TTM_GETTOOLCOUNT, 0L, 0L);
	}
	
	int GetDelayTime(DWORD dwType) 
	{
		if (!::IsWindow(m_hWnd)) return -1;
		return (int)SendMessage( TTM_GETDELAYTIME, dwType, 0L);
	}
	
	void SetDelayTime(DWORD dwType, int nTime)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_SETDELAYTIME, dwType, MAKELPARAM(nTime, 0));
	}
	void GetMargin(LPRECT lpRect) 
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_GETMARGIN, 0L, (LPARAM)lpRect);
	}
	void SetMargin(LPRECT lpRect)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_SETMARGIN, 0L, (LPARAM)lpRect);
	}
	int GetMaxTipWidth() 
	{
		if (!::IsWindow(m_hWnd)) return -1;
		return (int)SendMessage( TTM_GETMAXTIPWIDTH, 0L, 0L);
	}
	int SetMaxTipWidth(int nWidth)
	{
		if (!::IsWindow(m_hWnd)) return -1;
		return (int)SendMessage( TTM_SETMAXTIPWIDTH, 0L, nWidth);
	}
	COLORREF GetTipBkColor() 
	{
		if (!::IsWindow(m_hWnd)) return RGB(0L,0L,0);
		return (COLORREF)SendMessage( TTM_GETTIPBKCOLOR, 0L, 0L);
	}

	void SetTipBkColor(COLORREF clr)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_SETTIPBKCOLOR, (WPARAM)clr, 0L);
	}

	COLORREF GetTipTextColor() 
	{
		if (!::IsWindow(m_hWnd)) return RGB(0L,0L,0);
		return (COLORREF)SendMessage( TTM_GETTIPTEXTCOLOR, 0L, 0L);
	}

	void SetTipTextColor(COLORREF clr)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_SETTIPTEXTCOLOR, (WPARAM)clr, 0L);
	}
	
	BOOL GetCurrentTool(LPTOOLINFO lpToolInfo) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TTM_GETCURRENTTOOL, 0L, (LPARAM)lpToolInfo);
	}



	void Activate(BOOL bActivate)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_ACTIVATE, bActivate, 0L);
	}

	BOOL AddTool(HWND hWnd, LPCTSTR lpTxt, LPCRECT lpRect,UINT uID)
	{
		TOOLINFO tti;
		ASSERT(m_hWnd);
		ASSERT(lpszText != NULL);
		
		memset(&tti,0x00,sizeof(TOOLINFO));
		tti.cbSize=sizeof(TOOLINFO);
		tti.hwnd=hWnd;
		tti.uFlags=0;
		tti.uId=uID;
		tti.lpszText = (LPTSTR)lpTxt;
		if (lpRect != NULL)
			memcpy(&tti.rect, lpRect, sizeof(RECT));
		return (BOOL) ::SendMessage(m_hWnd, TTM_ADDTOOL, 0, (LPARAM)&tti);
	}

	BOOL AddTool(LPTOOLINFO lpToolInfo)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TTM_ADDTOOL, 0L, (LPARAM)lpToolInfo);
	}
	
	

	BOOL UpdateTipText(HWND hWnd, LPTSTR lpText= LPSTR_TEXTCALLBACK, LPCRECT lpRect = NULL, UINT nID = 0)
	{
		ASSERT(::IsWindow(m_hWnd));
		ASSERT(hWnd != NULL);
		
		TOOLINFO ti;
		
		memset(&ti, 0x00, sizeof(TOOLINFO));
		ti.cbSize = sizeof(TOOLINFO);
		//Why the follow instructions?, well it is count for 1 not 0
		if(nID == 0)
		{
			ti.hwnd = hWnd;
			ti.uFlags |= TTF_IDISHWND;
			ti.uId = (UINT_PTR)hWnd;
		}
		else
		{
			ti.hwnd = hWnd;
			ti.uId = nID;
		}
		if(lpRect != NULL)
			ti.rect = *lpRect;
		ti.lpszText = lpText;

		return (BOOL )::SendMessage(m_hWnd, TTM_UPDATETIPTEXT, 0,(LPARAM)&ti);
	}

	BOOL AddTool(HWND hWnd, LPTSTR lpText = LPSTR_TEXTCALLBACK, LPCRECT lpRect = NULL, UINT nID = 0)
	{
		ASSERT(::IsWindow(m_hWnd));
		ASSERT(hWnd != NULL);
		
		TOOLINFO ti;
		
		memset(&ti, 0x00, sizeof(TOOLINFO));
		ti.cbSize = sizeof(TOOLINFO);
		
		if(nID == 0)
		{
			ti.hwnd = ::GetParent(hWnd);
			ti.uFlags |= TTF_IDISHWND;
			ti.uId = (UINT_PTR)hWnd;
		}
		else
		{
			ti.hwnd = hWnd;
			ti.uId = nID;
		}
		if(lpRect != NULL)
			ti.rect = *lpRect;
		ti.hinst = theApp->GetInstance();
		ti.lpszText = lpText;
		ti.lParam = 0;/*NULL;*/
		return (BOOL)::SendMessage(m_hWnd, TTM_ADDTOOL, 0,(LPARAM)&ti);
	}


	void DelTool(LPTOOLINFO lpToolInfo)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_DELTOOL, 0L, (LPARAM)lpToolInfo);
	}
	
	BOOL HitTest(LPTTHITTESTINFO lpHitTestInfo) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TTM_HITTEST, 0L, (LPARAM)lpHitTestInfo);
	}
	
	void RelayEvent(LPMSG lpMsg)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_RELAYEVENT, 0L, (LPARAM)lpMsg);
	}
	void UpdateTipText(LPTOOLINFO lpToolInfo)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_UPDATETIPTEXT, 0L, (LPARAM)lpToolInfo);
	}
	

	BOOL EnumTools(UINT nTool, LPTOOLINFO lpToolInfo) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TTM_ENUMTOOLS, nTool, (LPARAM)lpToolInfo);
	}
	void Pop()
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_POP, 0L, 0L);
	}
	void TrackActivate(LPTOOLINFO lpToolInfo, BOOL bActivate)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_TRACKACTIVATE, bActivate, (LPARAM)lpToolInfo);
	}
	void TrackPosition(int xPos, int yPos)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_TRACKPOSITION, 0L, MAKELPARAM(xPos, yPos));
	}


#if (_WIN32_IE >= 0x0400)
	void Update()
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_UPDATE, 0L, 0L);
	}
#endif //(_WIN32_IE >= 0x0400)

#if (_WIN32_IE >= 0x0500)
	BOOL AdjustRect(LPRECT lpRect, BOOL bLarger= TRUE)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TTM_ADJUSTRECT, bLarger, (LPARAM)lpRect);
	}
	DWORD GetBubbleSize(LPTOOLINFO lpToolInfo) 
	{
		if (!::IsWindow(m_hWnd)) return 0;
		return (DWORD)SendMessage( TTM_GETBUBBLESIZE, 0L, (LPARAM)lpToolInfo);
		
	}
	BOOL SetTitle(UINT uIcon, LPCTSTR lpstrTitle)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TTM_SETTITLE, uIcon, (LPARAM)lpstrTitle);
	}
#endif //(_WIN32_IE >= 0x0500)

#if (_WIN32_WINNT >= 0x0501)
	void Popup()
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_POPUP, 0L, 0L);
	}

	void GetTitle(PTTGETTITLE pTTGetTitle) 
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_GETTITLE, 0L, (LPARAM)pTTGetTitle);
	}
	void SetWindowTheme(LPCWSTR lpstrTheme)
	{
		ASSERT(m_hWnd);
		SendMessage( TTM_SETWINDOWTHEME, 0L, (LPARAM)lpstrTheme);
	}

#endif //(_WIN32_WINNT >= 0x0501)

	
};

