#include "CApp.h"
#include "CFrame.h"

CApp* theApp = 0;

CApp::~CApp()
{
	if (HIWORD(m_WinMain))
	{
		delete m_WinMain;
	}
}

void CApp::LoadMain(HINSTANCE hinstace, HINSTANCE PrehInstance, LPSTR cmdLine, int show)
{
	m_hInstance=hinstace;
	m_prehInstance=PrehInstance;
	m_LineCommands=cmdLine;
	m_nShow=show;
	#if (_WIN32_IE >= 0x0300)
		INITCOMMONCONTROLSEX iccex;
		iccex.dwSize = sizeof(iccex);
		iccex.dwICC =  ICC_COOL_CLASSES | ICC_USEREX_CLASSES;	
		InitCommonControlsEx(&iccex);
	#else
		InitCommonControls();
	#endif
	registerClass(m_hInstance);
}

HACCEL CApp::LoadAccelerators(LPCTSTR lpTableName)
{
	return ::LoadAccelerators(GetInstance(),lpTableName);
}

HRSRC CApp::FindResource(UINT nResourceID, LPCTSTR lpType)
{
	return ::FindResource(m_hInstance, MAKEINTRESOURCE(nResourceID),lpType);
}

HRSRC CApp::FindResourceToolBar(UINT nResourceID)
{
	return FindResource(nResourceID,RT_TOOLBAR);
}

HGLOBAL CApp::LoadResource(HRSRC hRsrc)
{
	HGLOBAL hGlobal= ::LoadResource(m_hInstance, hRsrc);
	if (hGlobal == NULL)
		return NULL;
	return hGlobal;
}
	
BOOL CApp::LoadMenu(LPCTSTR lpszMenuName)
{
	if (!m_Menu.LoadMenu(lpszMenuName))
		return FALSE;
	::SetMenu(m_WinMain->GetSafeHwnd(),m_Menu.GetHandleMenu());
	m_WinMain->cSpawn.RemapMenu(m_Menu.GetHandleMenu());	
	
	return TRUE;	
}
	
HMENU CApp::LoadMenuMDI(LPCTSTR lpszMenuName)
{
	HMENU hMenul;
	if (lpszMenuName != NULL)
	{
		
		if ((hMenul = ::LoadMenu(GetModuleHandle(NULL), lpszMenuName)) == NULL)
		{
			return NULL;
		}
			
		return hMenul;
	}
	return NULL;
}		

HMENU CApp::LoadMenuWindow()
{
	if (m_WinMain->GetMenu() !=m_Menu.GetHandleMenu())
	{
		::SetMenu(m_WinMain->GetSafeHwnd(),m_Menu.GetHandleMenu());
	}

	return m_WinMain->GetMenu();
}

void CApp::SetRegistryKey(LPCSTR lpKey)
{
	lstrcpy(m_lpBuffer,lpKey);
}

int CApp::Run()
{
	MSG msg;
	BOOL bresult;
	BOOL bPeekMsg=TRUE;
	while (bPeekMsg || GetMessage(&msg, NULL, 0, 0)) 
	{
		
		if (bPeekMsg)
		{
			if(!PeekMessage(&msg,NULL,0,0,PM_REMOVE))
				bPeekMsg=m_WinMain->OnIdle();
			continue;
		}

		if (bMDI)
		{
			bresult=(
					(!TranslateMDISysAccel (m_WinMain->GetSafeClientHwnd(), &msg)) 
					&&  	(!TranslateAccelerator (msg.hwnd,hAccelTable, &msg)));
		}
		else
			bresult=(!TranslateAccelerator (msg.hwnd, hAccelTable, &msg));
	
		CWin* pActive= reinterpret_cast<CWin*>((HWND)::GetWindowLong(msg.hwnd,GWL_USERDATA)); //CWin::GetUserPointerWindow(msg.hwnd); 
		BOOL bPre=TRUE;
		if (pActive)
			bPre=pActive->PreTranslateMessage(&msg);
		if (bresult && bPre) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
	}
	return  msg.wParam;
}

CWin* CApp::GetMainWindows() 
{
	if (::IsWindow(m_WinMain->GetSafeHwnd()))
		return m_WinMain;
	else 
		return NULL;
}
