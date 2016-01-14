#if 1

#include "stdafx.h"
#include "main_mdi.h"
#include "CHookMenu.h"
#include "CFrame.h"
#include "mdi/resource.h"

BOOL CWinFrame::OnSize(UINT nType,long x, long y) 
{
	CFrameMDI::OnSize(nType,x,y);
	return TRUE;
}

BOOL CWinFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CFrameMDI::OnCreate(lpCreateStruct);

	if (!CreateExBars(Panels,3))
		return -1;
	if ( !m_ToolBar.Create(m_ReBar->GetSafeHwnd(),IDR_TOOLBAR))
		return -1;

	if ( !m_ToolBar1.Create(m_ReBar->GetSafeHwnd(),IDR_TOOLBAR1))
		return -1;

	//m_ToolBar.AddButtonText(ID_FILE_NEW, _T("Hola"));
	m_ToolBar.LoadToolBar(IDR_TOOLBAR);
	m_ToolBar1.LoadToolBar(IDR_TOOLBAR1);	
	AddBar(&m_ToolBar, IDR_TOOLBAR);
	AddBar(&m_ToolBar1, IDR_TOOLBAR1);
	m_ToolBar.AddTrueColor(IDB_TOOLBAR,TB_SETIMAGELIST);
	m_ToolBar1.AddTrueColor(IDr_BITMAP1,TB_SETIMAGELIST);
	SetPanelText(0,_T("Ready") );
	SetIcon(theApp->LoadIcon((LPCSTR)IDI_SMALL),FALSE);
	// COOLMENU SUPPORT
	cSpawn.LoadToolBarResource(IDR_TOOLBAR,IDB_TOOLBAR);
//	cSpawn.AddToolBarResource(IDR_SYSTEMBAR);
	cSpawn.AddToolBarResource(IDR_TOOLBAR1);
//	CreateDockBars(); 


	return 0;
}


BOOL CWinFrame::OnClose()
{
	int resp=MsgBox("Esta seguro de Salir","Close",MB_YESNO);
	if (resp==IDYES)
		return CWin::OnDestroy();
	return FALSE;
}







CAppMain::~CAppMain()
{
	CHookMenu::UnInstallHook();
}

int CAppMain::InitInstance()
{
	CHookMenu::InstallHook();	
	m_WinMain=(CFrame*)new CWinFrame(); 

	if (m_WinMain->LoadFrame(IDC_WINCLASS)== FALSE)
		return -1;
	SetMenuResource((LPCTSTR)IDC_WINCLASS);
	LoadMenu((LPCTSTR)IDC_WINCLASS);
//	m_WinMain->cSpawn.RemapMenu(m_Menu.GetHandleMenu());
	// 3D HIGHLIGHT CODE
	m_WinMain->ShowWindow();
	m_WinMain->UpdateWindow();
	hAccelTable = LoadAccelerators( (LPCTSTR)IDC_WINCLASS);
	return Run();	
}

int WINAPI WinMain(HINSTANCE hinstace, HINSTANCE PrehInstance, LPSTR cmdLine, int show)
{
	CAppMain cpMain;
	if (theApp==0)
		return 0;
	theApp->LoadMain(hinstace, PrehInstance, cmdLine, show);
	return theApp->InitInstance();				
}

#endif
