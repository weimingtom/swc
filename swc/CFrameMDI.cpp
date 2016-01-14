#include "stdafx.h"
#include "CFrameMDI.h"

BOOL CFrameMDI::LoadFrame(UINT nID,DWORD dwStyle,HWND hParentWnd)
{	
	BOOL rs=CFrame::LoadFrame(nID,dwStyle,hParentWnd);
	if (rs==TRUE)
		if (theApp != NULL)
			theApp->bMDI=TRUE;
	return rs;

}
		
HWND CFrameMDI::MDIGetActive(BOOL* pbMaximized)
{
	
	if (hMDIClient == NULL)
		return NULL;
	
	HWND hWnd = (HWND)::SendMessage(hMDIClient, WM_MDIGETACTIVE, 0,
		(LPARAM)pbMaximized);
	if (hWnd)
		return hWnd;
		
	return NULL;
	
}
	
void CFrameMDI::MDIActivate(HWND hWndActivate,LPARAM lParam)
{ 

	if (::IsWindow(hMDIClient))
		::SendMessage(hMDIClient, WM_MDIACTIVATE,(WPARAM)hWndActivate, 0);
	
}
void CFrameMDI::MDIIconArrange()
{ 
	 if (::IsWindow(hMDIClient)) 
		::SendMessage(hMDIClient, WM_MDIICONARRANGE, 0, 0); 
}

void CFrameMDI::MDIMaximize(HWND hWndParent)
{
	if (::IsWindow(hMDIClient)) 
		::SendMessage(hMDIClient, WM_MDIMAXIMIZE, (WPARAM)hWndParent, 0); 
}

void CFrameMDI::MDINext()
{ 
	if (::IsWindow(hMDIClient)) 
		::SendMessage(hMDIClient, WM_MDINEXT, 0, 0); 
}

void CFrameMDI::MDIRestore(HWND hWndParent)
{ 
	if (::IsWindow(hMDIClient)) 
		::SendMessage(hMDIClient, WM_MDIRESTORE, (WPARAM)hWndParent, 0); 
}

HMENU CFrameMDI::MDISetMenu(HMENU hMenuParent, HMENU hMenuWindow)
{ 
	if (::IsWindow(hMDIClient)) 
		return (HMENU)::SendMessage(hMDIClient, WM_MDISETMENU, (WPARAM)hMenuParent,
							(LPARAM)hMenuWindow); 
	return NULL;
}

void CFrameMDI::MDITile()
{ 
	if (::IsWindow(m_hWnd)) 
		::SendMessage(hMDIClient, WM_MDITILE, 1, 0); 
}

void CFrameMDI::MDICascade()
{ 
	if (::IsWindow(m_hWnd)) 
		::SendMessage(hMDIClient, WM_MDICASCADE, 0, 0); 
}

void CFrameMDI::MDICascade(int nType)
{ 
	if (::IsWindow(m_hWnd)) 
		::SendMessage(hMDIClient, WM_MDICASCADE, nType, 0); 
}

void CFrameMDI::MDITile(int nType)
{ 
	if (::IsWindow(m_hWnd)) 
		::SendMessage(hMDIClient, WM_MDITILE, nType, 0); 
}


LRESULT CFrameMDI::DefWindowProc(HWND hWnd, UINT uID, WPARAM wParam, LPARAM lParam)

{
	
	HWND hWChild=(HWND)::SendMessage(hMDIClient,WM_MDIGETACTIVE,0,0);
	if (hWChild)
		::SendMessage(hWChild,WM_COMMAND,wParam,lParam);
	return ::DefFrameProc(hWnd,hMDIClient,uID,wParam,lParam);
	
}


BOOL CFrameMDI::OnCreate(LPCREATESTRUCT lpCreateStruct)
{	
	ccs.hWindowMenu  = ::GetMenu(GetSafeHwnd());
	ccs.idFirstChild = ID_MDI_FIRSTCHILD;
	if (hMDIClient != NULL) return TRUE;
	hMDIClient = CreateWindowEx(WS_EX_CLIENTEDGE, "MDIclient", NULL,
			WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | 
			ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE |
			ES_NOHIDESEL | MDIS_ALLCHILDSTYLES|WS_CLIPCHILDREN,
			CW_USEDEFAULT , CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
			m_hWnd, (HMENU)ID, GetModuleHandle(NULL), (LPVOID)&ccs);
	::BringWindowToTop(hMDIClient);
	if( hMDIClient==NULL)
		return FALSE;
	return TRUE;		

}


BOOL CFrameMDI::WindowsPosChanged(LPWINDOWPOS lpWindowsPos)
{ 
	BOOL bMaximize;
	HWND hWndChild = MDIGetActive(&bMaximize);
	if(hWndChild != NULL && hMDIClient != m_hWnd)
		return FALSE;
	    
	DWORD dwStyle = ::GetWindowLong(hMDIClient, GWL_EXSTYLE);
	DWORD dwNewStyle = dwStyle;
	dwNewStyle |= WS_EX_CLIENTEDGE;

	::RedrawWindow(hMDIClient, NULL, NULL,
				RDW_INVALIDATE | RDW_ALLCHILDREN);
	::SetWindowLong(hMDIClient, GWL_EXSTYLE, dwNewStyle);
	::SetWindowPos(hMDIClient, NULL, 0, 0, 0, 0,
		SWP_FRAMECHANGED | SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE |
		SWP_NOZORDER | SWP_NOCOPYBITS);
		return TRUE;
}

void CFrameMDI::OnCloseChild()
{
	BOOL pbMaximized;
	HWND hwndChild = MDIGetActive(&pbMaximized);
        
		if (::SendMessage (hwndChild, WM_QUERYENDSESSION, 0, 0))
			::SendMessage (hMDIClient, WM_MDIDESTROY,(WPARAM) hwndChild, 0) ;
          
}
