#pragma once

#include "CFrame.h"
#include "CGDI.h"
#include "CBitmap.h"
#include "CPen.h"
#include "CWindowDC.h"
#include "CBrush.h"
#include "CDrawLayer.h"

class CHookMenu
{
protected:
	
	static HHOOK hHook; 
	HWND  m_hWnd;
public:
    CHookMenu (HWND hWnd): m_hWnd(hWnd){};
   ~CHookMenu ();

private:
	
    static LRESULT CALLBACK CallWndProc (int code, WPARAM wParam, LPARAM lParam)
	{
	  
	    CWPSTRUCT* pst = (CWPSTRUCT*)lParam;
	
	    while ( code == HC_ACTION )
	    {
		
		if ( pst->message != WM_CREATE && pst->message != 0x01E2 )
		    break; // isn't our bussines
		
		TCHAR sClassName[10];
		::GetClassName (pst->hwnd, sClassName,10);
		if ( _tcscmp( sClassName, _T( "#32768" ))!=0)
			break; // isn't our bussines
		if ( ::GetProp( pst->hwnd,_T("SWC_OLDPROCMENU")) != NULL )
			break;					
		//w'll need this  proc in the subWndProc, thi's the original menu dialog procedure
		WNDPROC OldProc = (WNDPROC)::GetWindowLong (pst->hwnd, GWL_WNDPROC);
		if ( !OldProc ) break; //something is wrong
		if ( !SetProp (pst->hwnd, _T("SWC_OLDPROCMENU"), (void*)OldProc) ) break;  
		
		if ( !::SetWindowLong (pst->hwnd, GWL_WNDPROC, (DWORD)(unsigned long)SubWndProc) )
		{
		    ::RemoveProp (pst->hwnd, _T("SWC_OLDPROCMENU"));
		    break;
		}
		
		break;
	    }
	    return CallNextHookEx (hHook, code, wParam, lParam);
	}
	

    static LRESULT CALLBACK SubWndProc (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
	    WNDPROC oldWndProc = (WNDPROC)::GetProp (hWnd, _T("SWC_OLDPROCMENU"));
	    HWND hWndg = ::GetParent(hWnd);
		int Opc=theApp->m_WinMain->cSpawn.fltMenu.iCmd;
		if (Opc==-4)	
			theApp->m_WinMain->m_SubMenuActual=hWnd;
	    switch ( uMsg )
	    {
	     		
		case WM_WINDOWPOSCHANGING:
			{
				WINDOWPOS* pWP=(LPWINDOWPOS)lParam;
				pWP->cx--;
				pWP->cy--;
			}
	    case WM_PRINT:
			{

				CGDI	dc((HDC)wParam);
				CRect rect;
				CGDI		m_dc;	
				CBitmap		m_bitmap;
				CPen pen;
				CWindowDC dcw;
				dc.GetClipBox(rect);
				
				m_dc.CreateCompatibleDC(dc.m_hDC);
				m_bitmap.CreateCompatibleBitmap(dc.m_hDC,rect.Width(),rect.Height());
				CBitmap m_OldBitmap=m_dc.SelectObject(&m_bitmap);
				//aqui debe utilizarse la brocha que define CDrawLayer, si no hacemos la siguiente
				//linea usted vera un horrible color negro, a cambio del dibujo.
				
				HBRUSH hb=(HBRUSH)::SelectObject(m_dc.m_hDC,::GetStockObject(NULL_BRUSH));
				CBrush cb;
				::SendMessage( hWnd, WM_ERASEBKGND,  ( WPARAM )( HDC )m_dc.m_hDC, 0 );
				::SendMessage( hWnd, WM_PRINTCLIENT, ( WPARAM )( HDC )m_dc.m_hDC, lParam );
				//LRESULT lResult = CallWindowProc (oldWndProc, hWnd, uMsg,(WPARAM)m_dc.m_hDC, lParam);
				pen.CreatePen(PS_SOLID,1,CDrawLayer::GetRGBColorShadow());
				CPen cpen=m_dc.SelectObject(&pen);
				m_dc.Rectangle(rect);
				rect.DeflateRect(1,1);
				m_dc.Draw3dRect(rect,CDrawLayer::GetRGBColorWhite(),CDrawLayer::GetRGBColorWhite());
				rect.DeflateRect(1,1);
				m_dc.Draw3dRect(rect,CDrawLayer::GetRGBColorWhite(),CDrawLayer::GetRGBColorWhite());
				rect.InflateRect(2,2);
				::SelectObject(m_dc.m_hDC,hb);
				m_dc.SelectObject(&cpen);
				dc.BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),m_dc.m_hDC,0L,0L,SRCCOPY);
				cpen.DeleteObject();
				m_dc.SelectObject(&m_OldBitmap);
				m_bitmap.DeleteObject();
				m_OldBitmap.DeleteObject();
				cb.DeleteObject();
				m_dc.DeleteDC();
				dc.DeleteDC();
				return 0;	
			}
		break;

	    case WM_NCPAINT:
			{

				CRect rect;
				CWindowDC dc(hWnd);
				CPen pen;
				int Opc=theApp->m_WinMain->cSpawn.fltMenu.iCmd;
				theApp->m_WinMain->cSpawn.fltMenu.iCmd=-1;
				HBRUSH hb=(HBRUSH)::SelectObject(dc.m_hDC,::GetStockObject(NULL_BRUSH));
				dc.GetClipBox(rect); CRect rect1=rect;
				pen.CreatePen(PS_SOLID,1,CDrawLayer::GetRGBColorShadow());
				CPen cpen=dc.SelectObject(&pen);
				dc.Rectangle(rect);
				rect.DeflateRect(1,1);
				dc.Draw3dRect(rect,CDrawLayer::GetRGBColorWhite(),CDrawLayer::GetRGBColorWhite());
				rect.DeflateRect(1,1);
				int bottom =rect.bottom;
				rect.bottom=rect.top+1;
				dc.Draw3dRect(rect,CDrawLayer::GetRGBColorWhite(),CDrawLayer::GetRGBColorWhite());
				rect.bottom=bottom;
				rect.left=rect.right-1;
				dc.Draw3dRect(rect,CDrawLayer::GetRGBColorWhite(),CDrawLayer::GetRGBColorWhite());
				if (theApp->m_WinMain->m_SubMenuActual==hWnd)//;Opc==-4)
				{
					rect1.left+=1;
					rect1.right=rect1.left+theApp->m_WinMain->cSpawn.fltMenu.Width-1;
					rect1.bottom=rect1.top;
					dc.Draw3dRect(rect1,CDrawLayer::GetRGBColorXP(),CDrawLayer::GetRGBColorXP());
					
				}
				dc.SelectObject(&cpen);
				::SelectObject(dc.m_hDC,hb);
				pen.DeleteObject();
				cpen.DeleteObject();
				dc.DeleteDC();	
				return 0;	
			}
		break;
	
	    case WM_NCCALCSIZE:
		{
		    LRESULT lResult = CallWindowProc (oldWndProc, hWnd, uMsg, wParam, lParam);
		    NCCALCSIZE_PARAMS*  pCalcSize = ( NCCALCSIZE_PARAMS*  )lParam;	
		    pCalcSize->rgrc[0].left -= 1;
		//	pCalcSize->rgrc[0].right -=1;
		    pCalcSize->rgrc[0].bottom += 1;
		    return lResult;
		}
	}
	    return CallWindowProc (oldWndProc, hWnd, uMsg, wParam, lParam);
}	



public:
	static void InstallHook()
	{
		hHook = ::SetWindowsHookEx (WH_CALLWNDPROC, CallWndProc,theApp->GetInstance(), ::GetCurrentThreadId());
	}
	
	static void UnInstallHook()
	{
		if ( hHook)
		        ::UnhookWindowsHookEx (hHook);
		
	}
protected:
    
  void OnWindowPosChanging (WINDOWPOS* pWP);
  void OnEraseBkgnd ();
  void OnPrint (CWindowDC wDC, bool bOwnerDrawnItems);
  void OnNcPaint ();
  void OnNcDestroy ();
    
};
