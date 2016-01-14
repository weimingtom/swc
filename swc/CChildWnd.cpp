#include "stdafx.h"
#include "CChildWnd.h"

BOOL CChildWnd::LoadFrame(UINT nID,HWND hParentWnd,DWORD dwStyle)
{	
	
	int nLen;
	TCHAR szTemp[256];
	BOOL pbMaximized;
	LPCTSTR lpszName = MAKEINTRESOURCE((nID>>4)+1);
	if (::FindResource(GetModuleHandle(NULL), lpszName, RT_STRING) != NULL &&
		(nLen = ::LoadString(GetModuleHandle(NULL), nID, szTemp, 255) != 0)) {
	}
	HWND hWnd = (HWND)::SendMessage(hParentWnd, WM_MDIGETACTIVE, 0,
		(LPARAM)&pbMaximized);
	if (pbMaximized)
		dwStyle|=WS_MAXIMIZE;
	BOOL bRes=CreateEx(WS_EX_MDICHILD,_T( "MotsusChildWindow" ),_T("Untitled"),dwStyle,CRect(CW_USEDEFAULT,
			CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT),hParentWnd,nID);
	ModifyStyle(WS_EX_CLIENTEDGE, 0, SWP_FRAMECHANGED);
	hMenu=theApp->LoadMenuMDI((LPCTSTR)nID);		
	SetIcon(theApp->LoadIcon((LPCSTR)nID),FALSE);
	::SendMessage(GetParent(),WM_MDISETMENU,(WPARAM)hMenu,0);
	theApp->m_WinMain->cSpawn.RemapMenu(hMenu);
	theApp->m_WinMain->DrawMenuBar();

	
	return bRes;
}

LRESULT CChildWnd::DefWindowProc(HWND hWnd, UINT uID, WPARAM wParam, LPARAM lParam)
{
	if (lpfnOldWndProc !=NULL )
		return CallWindowProc(lpfnOldWndProc, hWnd, uID,wParam, lParam); 
	return ::DefMDIChildProc(hWnd,uID,wParam,lParam);
}

void CChildWnd::MDIActivate(HWND hWndActivate,LPARAM lParam)
{ 
	
	if(  lParam)
		::SendMessage(GetParent(),WM_MDISETMENU,(WPARAM)hMenu,0);
	else
		::SendMessage(GetParent(),WM_MDISETMENU,(WPARAM)theApp->GetMenuDefault(),0);
	
	theApp->m_WinMain->DrawMenuBar();
	
	if (::IsWindow(GetParent()))
		::SendMessage(GetParent(), WM_MDIACTIVATE,(WPARAM)m_hWnd, 0);
	
}

void CChildWnd::MDIMaximize(HWND hWndActivate)
{
	::SendMessage(GetParent(), WM_MDIMAXIMIZE,(WPARAM)m_hWnd, 0);
}
