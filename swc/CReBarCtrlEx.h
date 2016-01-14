#pragma once

#include "stdafx.h"
#include "CReBarCtrl.h"
#include "CPaintDC.h"
#include "CGradient.h"

class CReBarCtrlEx: public CReBarCtrl
{
	public:
		
	BOOL Create(HWND hWndParent,DWORD dwStyle=WS_CHILD | WS_VISIBLE |  WS_CLIPCHILDREN | WS_CLIPSIBLINGS | RBS_VARHEIGHT | RBS_BANDBORDERS | RBS_AUTOSIZE,
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



	int  OnPaint(HDC hDC)
	{
		CPaintDC	dc(GetSafeHwnd());
		CRect rect;
		CGDI		m_dc;	
		CBitmap		m_bitmap;
		GetClientRect(&rect);
		m_dc.CreateCompatibleDC(dc.m_hDC);
		m_bitmap.CreateCompatibleBitmap(dc.m_hDC,rect.Width(),rect.Height());
		CBitmap m_OldBitmap=m_dc.SelectObject(&m_bitmap);
		//aqui debe utilizarse la brocha que define CDrawLayer, si no hacemos la siguiente
		//linea usted vera un horrible color negro, a cambio del dibujo.
		
		/*CGradient M(CSize(rect.Width(),rect.Height()));	
		M.PrepareVertical(&m_dc);
		M.Draw(&m_dc,0,0,0,0,rect.Width(),rect.Height(),SRCCOPY);	*/
		CBrush cb;
		cb.CreateSysColorBrush(COLOR_BTNFACE);
		//rc.top+=1;
		CRect rc1=rect;
		m_dc.FillRect(&rc1,&cb);
		int nCount = (int)::SendMessage(GetSafeHwnd(), RB_GETBANDCOUNT, 0, 0L);
		CRect rc=rect;	
		(void)rc;
		for(int i = 0; i < nCount; i++)
		{
			 
			REBARBANDINFO rbBand;
			rbBand.cbSize = sizeof(REBARBANDINFO);
			rbBand.fMask = RBBIM_SIZE|RBBIM_CHILD|RBBIM_CHILDSIZE; 

			BOOL bRet = (BOOL)::SendMessage(GetSafeHwnd(), RB_GETBANDINFO, i, (LPARAM)&rbBand);
			ASSERT(bRet);
			(void)bRet;
			RECT rct = { 0, 0, 0, 0 };
			::SendMessage(GetSafeHwnd(), RB_GETRECT, i, (LPARAM)&rct);
			SIZE lpSize;
			if (rbBand.hwndChild == m_hWnd) continue;
			::SendMessage( rbBand.hwndChild,TB_GETMAXSIZE, 0L,(LPARAM) &lpSize);
			rbBand.cx += rct.left + rct.right;
			CRect rc1=rct;
			rc1.left+=1;
			//rc1.right=rc1.left+lpSize.cx+13;
			CRect rc2=rct;
			rc2.left= rc2.right-6;
			CGradient M(CSize(rc2.Width(),rc2.Height()));	
			M.PrepareVertical(&m_dc,GUISTYLE_XP,CDrawLayer::GetRGBPressBXP());
			M.Draw(&m_dc,rc2.left,rc2.top,0,0,rc2.Width(),rc2.Height(),SRCCOPY);	
						
			
			CGradient M1(CSize(rc1.Width(),rc1.Height()));	
			M1.PrepareVertical(&m_dc); //,GUISTYLE_XP,CDrawLayer::GetRGBPressBXP());
			M1.Draw(&m_dc,rc1.left,rc1.top,0,0,9,rc1.Height(),SRCCOPY);	
			
			DrawGripper(&m_dc,rct);
			//round border efects
			rc1=rct;
			rc1.left+=1;
			rc1.right=rc1.left+1;
			rc1.top=rc1.bottom-1;
			m_dc.FillRect(&rc1,&cb);
			rc1=rct;
			rc1.left+=1;
			rc1.right=rc1.left+2;
			rc1.bottom=rc1.top+1;
			m_dc.FillRect(&rc1,&cb);
			rc1=rct;
			rc1.left+=1;
			rc1.right=rc1.left+1;
			rc1.bottom=rc1.top+2;
			m_dc.FillRect(&rc1,&cb);
			
		
		}
		dc.BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),m_dc.m_hDC,0L,0L,SRCCOPY);
		m_dc.SelectObject(&m_OldBitmap);
		m_bitmap.DeleteObject();
		m_OldBitmap.DeleteObject();
		m_dc.DeleteDC();
		cb.DeleteObject();
		dc.DeleteDC();
		return 0;
	}

	void DrawGripper(CGDI* dc,CRect rcWin,BOOL bHorz=TRUE)
	{

		if (bHorz)
		{
			
			rcWin.top+=6;
			rcWin.left+=5;
			rcWin.right=rcWin.left+2;
			rcWin.bottom-=2;
			CRect rcBlack;
			CBrush cb;
			for (int i=0; i < rcWin.Height(); i+=4)
			{
				CRect rcWindow;
				cb.CreateSolidBrush(::GetSysColor(COLOR_BTNHIGHLIGHT));
				rcWindow=rcWin;
				rcWindow.top=rcWin.top+i;
				rcWindow.bottom=rcWindow.top+2;
				dc->FillRect(rcWindow,&cb);
				rcBlack=rcWindow;
				rcBlack.left-=1;
				rcBlack.top=(rcWin.top+i)-1;
				rcBlack.bottom=rcBlack.top+2;
				rcBlack.right=rcBlack.left+2;
				cb.DeleteObject();
				cb.CreateSolidBrush(CDrawLayer::GetRGBColorShadow());
				dc->FillRect(rcBlack,&cb);
				cb.DeleteObject();
		
			}
			cb.DeleteObject();
			
		}
		else
		{
			rcWin.top+=3;
			rcWin.left+=4;
			rcWin.right-=2;
			rcWin.bottom=rcWin.top+2;
			CRect rcBlack;
			CBrush cb;
			for (int i=0; i < rcWin.Width(); i+=4)
			{
				CRect rcWindow;
				
				cb.CreateSolidBrush(::GetSysColor(COLOR_BTNHIGHLIGHT));
				rcWindow=rcWin;
				rcWindow.left=rcWindow.left+i;
				rcWindow.right=rcWindow.left+2;
				dc->FillRect(rcWindow,&cb);
				rcBlack=rcWindow;
				rcBlack.top-=1;
				rcBlack.left-=1;
				rcBlack.bottom=rcBlack.top+2;
				rcBlack.right=rcBlack.left+2;
				cb.DeleteObject();
				cb.CreateSolidBrush(CDrawLayer::GetRGBColorShadow());
				dc->FillRect(rcBlack,&cb);
		
			}
			cb.DeleteObject();
		}
	}

	BOOL OnDblclk( LPNMCHAR pNMHDR )
	{
		return TRUE;   //not use this event i' don't care
	}
	 
	
	/*BOOL OnSetCursor(CWin* pWnd, UINT nHitTest, UINT message) 
	{

		CPoint ptCurPos; 
		CRect rc;GetClientRect(rc);
		GetCursorPos (&ptCurPos);
		ScreenToClient (&ptCurPos);
		if (m_dwStyle & CBRS_ORIENT_HORZ)
		{
			rc.right=rc.left+2;
			if (ptCurPos.x< 0)
			{
				SetCursor (LoadCursor(NULL, IDC_SIZEALL));
				return TRUE;
			}
		}
		else
		{
			rc.bottom=rc.top+2;
			if (ptCurPos.y< 0)
			{
				SetCursor (LoadCursor(NULL, IDC_SIZEALL));
				return TRUE;
			}
		}
		return TRUE;

	}*/	
	   
	BEGIN_MSG_MAP()
		ON_WM_PAINT(OnPaint)
	END_MSG_MAP(CReBarCtrl)	
};	
