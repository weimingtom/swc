#pragma once

#include "stdafx.h"
#include "ComControlEX.h"
#include "CToolBarCtrl.h"

class CReBarCtrl : public ComControlEX
{
public:

	CReBarCtrl(HWND hWnd=NULL){m_hWnd=hWnd;}

										
	BOOL Create(HWND hWndParent,DWORD dwStyle=WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | RBS_VARHEIGHT | RBS_BANDBORDERS | RBS_AUTOSIZE|RBS_BANDBORDERS ,
			UINT uID=60000)
	{		

		BOOL bRes = CreateEx(0L, REBARCLASSNAME, NULL,
						dwStyle,CRect(0L, 0L, 0L, 0),hWndParent, uID, NULL);
		SubclassWnd(GetSafeHwnd());
		REBARINFO rbi;
		rbi.cbSize = sizeof(REBARINFO);
		rbi.fMask  = 0;
		if(!::SendMessage(m_hWnd, RB_SETBARINFO, 0L, (LPARAM)&rbi)) //SetBarInfo(&rbi)
		{
			DestroyWindow(m_hWnd);
			return FALSE;
		}
		return bRes;
	}


public:
	
	BOOL AddBar(CToolBarCtrl* pToolBar, int nID, LPTSTR lpstrTitle = NULL,
								 BOOL bNewRow = FALSE, DWORD dwStyle= RBBS_GRIPPERALWAYS  )
	{
		
		ASSERT(::IsWindow(m_hWnd));
		ASSERT(::IsWindow(pToolBar->GetSafeHwnd()));

		int nNumButton = pToolBar->GetButtonCount();
		
		REBARBANDINFO rbBand;
		rbBand.cbSize = sizeof(REBARBANDINFO);
		rbBand.fStyle = dwStyle|RBBS_VARIABLEHEIGHT ;
		BOOL bRet;
		SIZE sz;
		bRet = (BOOL) pToolBar->GetMaxSize(&sz);
	
		#if (_WIN32_IE >= 0x0400)
			rbBand.fMask = RBBIM_CHILD | RBBIM_IDEALSIZE |RBBIM_CHILDSIZE | RBBIM_STYLE | RBBIM_ID  ;
		#else
			rbBand.fMask = RBBIM_CHILD | RBBIM_CHILDSIZE |RBBIM_IDEALSIZE | RBBIM_STYLE | RBBIM_ID | RBBIM_SIZE;
		#endif 
		
		if(lpstrTitle != NULL)
			rbBand.fMask |= RBBIM_TEXT;
				
		if(bNewRow)
			rbBand.fStyle |= RBBS_BREAK;

		rbBand.lpText = lpstrTitle;
		rbBand.hwndChild = pToolBar->GetSafeHwnd();
		rbBand.wID = nID;
		rbBand.cxMinChild = sz.cx*0.40;
		//rbBand.fStyle |= RBBS_CHILDEDGE;
		rbBand.cxHeader=1;
		

		
		CRect rc;
		if(nNumButton > 0)
		{
			
			bRet = (BOOL) pToolBar->GetItemRect(nNumButton - 1, rc);
			
			ASSERT(bRet);
			rbBand.cx =  sz.cx;
			rbBand.cyMinChild = rc.Height();
		//	rbBand.cxMinChild = 4;
			rbBand.cyMaxChild= sz.cx;
			
		
		}
		else	
		{
			bRet = ::GetWindowRect(pToolBar->GetSafeHwnd(), rc);
			if(bRet)
			{
				rbBand.cx = rc.Width();
				//rbBand.cxMinChild = rc.Width();
				rbBand.cyMinChild = rc.Height();
				rbBand.cyMaxChild= rc.Width();
			}
		}

		#if (_WIN32_IE >= 0x0400)
			rbBand.cxIdeal = rbBand.cx;
		#endif 
			LRESULT lRes = (BOOL)InsertBand(&rbBand);

		return (BOOL)(lRes !=0);
		
	}

	UINT GetBandCount() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, RB_GETBANDCOUNT, 0, 0L);
	}
	BOOL GetBandInfo(int nBand, LPREBARBANDINFO lprbbi) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_GETBANDINFO, nBand, (LPARAM)lprbbi);
	}
	BOOL SetBandInfo(int nBand, LPREBARBANDINFO lprbbi)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_SETBANDINFO, nBand, (LPARAM)lprbbi);
	}
	BOOL GetBarInfo(LPREBARINFO lprbi) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_GETBARINFO, 0, (LPARAM)lprbi);
	}
	BOOL SetBarInfo(LPREBARINFO lprbi)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_SETBARINFO, 0, (LPARAM)lprbi);
	}
	UINT GetRowCount() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, RB_GETROWCOUNT, 0, 0L);
	}
	UINT GetRowHeight(int nBand) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, RB_GETROWHEIGHT, nBand, 0L);
	}

	COLORREF GetTextColor() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, RB_GETTEXTCOLOR, 0, 0L);
	}
	COLORREF SetTextColor(COLORREF clr)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, RB_SETTEXTCOLOR, 0, (LPARAM)clr);
	}
	COLORREF GetBkColor() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, RB_GETBKCOLOR, 0, 0L);
	}
	COLORREF SetBkColor(COLORREF clr)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, RB_SETBKCOLOR, 0, (LPARAM)clr);
	}
	UINT GetBarHeight() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, RB_GETBARHEIGHT, 0, 0L);
	}
	BOOL GetRect(int nBand, LPRECT lpRect) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_GETRECT, nBand, (LPARAM)lpRect);
	}
	CToolTipCtrl GetToolTips() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return CToolTipCtrl((HWND)::SendMessage(m_hWnd, RB_GETTOOLTIPS, 0, 0L));
	}
	void SetToolTips(HWND hwndToolTip)
	{
		ASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_SETTOOLTIPS, (WPARAM)hwndToolTip, 0L);
	}
	void GetBandBorders(int nBand, LPRECT lpRect) 
	{
		ASSERT(::IsWindow(m_hWnd));
		ASSERT(lpRect != NULL);
		::SendMessage(m_hWnd, RB_GETBANDBORDERS, nBand, (LPARAM)lpRect);
	}
	BOOL GetColorScheme(LPCOLORSCHEME lpColorScheme) 
	{
		ASSERT(::IsWindow(m_hWnd));
		ASSERT(lpColorScheme != NULL);
		return (BOOL)::SendMessage(m_hWnd, RB_GETCOLORSCHEME, 0, (LPARAM)lpColorScheme);
	}
	void SetColorScheme(LPCOLORSCHEME lpColorScheme)
	{
		ASSERT(::IsWindow(m_hWnd));
		ASSERT(lpColorScheme != NULL);
		::SendMessage(m_hWnd, RB_SETCOLORSCHEME, 0, (LPARAM)lpColorScheme);
	}
	HPALETTE GetPalette() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HPALETTE)::SendMessage(m_hWnd, RB_GETPALETTE, 0, 0L);
	}
	HPALETTE SetPalette(HPALETTE hPalette)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HPALETTE)::SendMessage(m_hWnd, RB_SETPALETTE, 0, (LPARAM)hPalette);
	}
	BOOL GetUnicodeFormat() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_GETUNICODEFORMAT, 0, 0L);
	}
	BOOL SetUnicodeFormat(BOOL bUnicode = TRUE)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_SETUNICODEFORMAT, bUnicode, 0L);
	}

	BOOL InsertBand(LPREBARBANDINFO lprbbi,int nBand=-1 )
	{
		ASSERT(::IsWindow(m_hWnd));
		lprbbi->cbSize = sizeof(REBARBANDINFO);
		return (BOOL)::SendMessage(m_hWnd, RB_INSERTBAND, nBand, (LPARAM)lprbbi);
	}
	BOOL DeleteBand(int nBand)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_DELETEBAND, nBand, 0L);
	}
	CWin SetNotifyWnd(HWND hWnd)
	{
		ASSERT(::IsWindow(m_hWnd));
		return CWin((HWND)::SendMessage(m_hWnd, RB_SETPARENT, (WPARAM)hWnd, 0L));
	}

	void BeginDrag(int nBand, DWORD dwPos)
	{
		ASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_BEGINDRAG, nBand, dwPos);
	}
	void BeginDrag(int nBand, int xPos, int yPos)
	{
		ASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_BEGINDRAG, nBand, MAKELPARAM(xPos, yPos));
	}
	void EndDrag()
	{
		ASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_ENDDRAG, 0, 0L);
	}
	void DragMove(DWORD dwPos)
	{
		ASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_DRAGMOVE, 0, dwPos);
	}
	void DragMove(int xPos, int yPos)
	{
		ASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_DRAGMOVE, 0, MAKELPARAM(xPos, yPos));
	}
	void MaximizeBand(int nBand)
	{
		ASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_MAXIMIZEBAND, nBand, 0L);
	}
	void MinimizeBand(int nBand)
	{
		ASSERT(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_MINIMIZEBAND, nBand, 0L);
	}
	BOOL SizeToRect(LPRECT lpRect)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_SIZETORECT, 0, (LPARAM)lpRect);
	}
	int IdToIndex(UINT uBandID) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, RB_IDTOINDEX, uBandID, 0L);
	}
	int HitTest(LPRBHITTESTINFO lprbht) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, RB_HITTEST, 0, (LPARAM)lprbht);
	}
	BOOL ShowBand(int nBand, BOOL bShow)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_SHOWBAND, nBand, bShow);
	}
	BOOL MoveBand(int nBand, int nNewPos)
	{
		ASSERT(::IsWindow(m_hWnd));
		ASSERT(nNewPos >= 0 && nNewPos <= ((int)GetBandCount() - 1));
		return (BOOL)::SendMessage(m_hWnd, RB_MOVEBAND, nBand, nNewPos);
	}

	int  HwndToIndex(HWND hWnd)
	{
		
		REBARBANDINFO rbbi;
		rbbi.cbSize = sizeof(rbbi);
		rbbi.fMask = RBBIM_CHILD|RBBIM_STYLE;
		int nCount = (int) ::SendMessage(GetSafeHwnd(), RB_GETBANDCOUNT, 0, 0L);
		for( int i = 0; i < nCount; i++ ) {
			BOOL bRet = (BOOL)::SendMessage(GetSafeHwnd(), RB_GETBANDINFO, i, (LPARAM) &rbbi);
			(void)bRet;
			if (rbbi.hwndChild==hWnd)
				return i;
		}
		return -1;

	}
	
	LRESULT OnShowBand(HWND hWnd)
	{
		int i=HwndToIndex(hWnd);
		REBARBANDINFO rbbi;
		rbbi.cbSize = sizeof(rbbi);
		rbbi.fMask = RBBIM_CHILD|RBBIM_STYLE;
		BOOL bRet = (BOOL)::SendMessage(GetSafeHwnd(), RB_GETBANDINFO, i, (LPARAM) &rbbi);
		CWin* pBar = reinterpret_cast<CWin*>(rbbi.hwndChild);
	    (void)bRet;
	    (void)pBar;
		BOOL bIsBandVisible= !(rbbi.fStyle & RBBS_HIDDEN);
		ShowBand(i, !bIsBandVisible);
		return 1;
	}
};
