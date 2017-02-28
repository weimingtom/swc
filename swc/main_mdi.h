#pragma once

#include "stdafx.h"
#include "CApp.h"
#include "CChildWnd.h"
#include "CEdit.h"
#include "CDialog.h"
#include "CFrameMDI.h"
#include "CToolBarCtrlEx.h"
#include "CButtonInfo.h"
#include "CListView.h"
#include "CMiniFrame.h"
#include "CFileOpen.h"
#include "resource.h"

#define HELLO 0x1111
#define IDPANEL0  60
#define IDPANEL1  20
#define IDPANEL2  20


int  Panels[]={ IDPANEL0,IDPANEL1,IDPANEL2};


class ChildHello : public CChildWnd
{

	HWND m_edit;
public:
	ChildHello(HWND hWnd=NULL): CChildWnd(hWnd)
	{}

	BOOL OnCreate(LPCREATESTRUCT lpCreateStruct)
	{
		
		m_edit= CreateWindowEx(0,"EDIT","",
			WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
			0,0,100,100,GetSafeHwnd(),(HMENU)HELLO,GetModuleHandle(NULL),NULL);
		return 0;
	}

	BOOL OnSize(UINT nType,long x, long y)
	{
		CRect rc1;
		GetClientRect(rc1);
		HWND hW=GetChild();
		::SetWindowPos(hW,NULL,rc1.left,rc1.top,rc1.Width(),rc1.Height(),SWP_NOZORDER);
		return TRUE;
	}

	
	void OnChangeEdit1(int wHp, int wLp, HWND hControl)
	{
	
	}

BEGIN_MSG_MAP()

	 ON_WM_CREATE(OnCreate)
	 ON_WM_SIZE(OnSize) 
	 ON_COMMAND_CONTROL(HELLO,EN_CHANGE, OnChangeEdit1)
	
END_MSG_MAP(CChildWnd)

};




class CAbout : public CDialog
{
	CEdit m_edit;
public:
	CAbout(){};
	~CAbout(){};
	virtual BOOL OnInitDialog(HWND wParam,LPARAM lParam);
	virtual BOOL OnOK(WPARAM wParam, LPARAM lParam, HWND hWnd);
	virtual BOOL OnCancel(WPARAM wParam, LPARAM lParam, HWND hWnd);
	
BEGIN_MSG_MAP()
	ON_WM_INITDIALOG(OnInitDialog)
	ON_COMMAND(IDOK,OnOK)
	ON_COMMAND(IDCANCEL,OnCancel)
END_MSG_MAP(CDialog)
};


BOOL CAbout::OnInitDialog(HWND wParam,LPARAM lParam)
{
	LINK_Control(IDC_EDIT_PWC,m_edit);
	return TRUE;
}

BOOL CAbout ::OnOK(WPARAM wParam, LPARAM lParam, HWND hWnd)
{
	char* lpText=(char*)malloc(200);
	m_edit.GetWindowText(lpText,20);
	MsgBox(lpText);
	CDialog::OnOK();	
	return TRUE;
}

BOOL CAbout ::OnCancel(WPARAM wParam, LPARAM lParam, HWND hWnd)
{
	CDialog::OnCancel();
	return TRUE;
}


class CWinFrame: public CFrameMDI
{
	CToolBarCtrlEx    m_ToolBar;
	CToolBarCtrlEx    m_ToolBar1;
	CListView	m_up;
	CMiniFrame		m_Mini;
public:

	CWinFrame(HWND hWnd=NULL):CFrameMDI(hWnd){}
	BOOL OnClose();
	BOOL OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnSize(UINT nType,long x, long y);
	
	
	void OnNew(WPARAM wParam, LPARAM lParam, HWND hWnd)
	{
		ChildHello* child=new ChildHello();
		if (!child->LoadFrame(IDR_MENUHELLO_MDI,GetSafeClientHwnd()))
			return;
		
		
	}
	
	void OnExit(WPARAM wParam, LPARAM lParam, HWND hWnd)
	{
		SendMessage(WM_CLOSE,0,0);
	}

	void Cascade(WPARAM wParam, LPARAM lParam, HWND hWnd)
	{
		MDICascade();
	}

	void OnToolBar(WPARAM wParam, LPARAM lParam, HWND hWnd)
	{
		OnShowBand(m_ToolBar.GetSafeHwnd());
		
	}

	void OnFileClose(WPARAM wParam, LPARAM lParam, HWND hWnd)
	{
		OnCloseChild();
	}

	void OnFileOpen(WPARAM wParam, LPARAM lParam, HWND hWnd)
	{
		CFileOpen co(this);
		co.DoModal(TRUE);
	}
	void OnAbout(WPARAM wParam, LPARAM lParam, HWND hWnd)
	{
		CAbout cb;
		cb.DoModal(this,(LPCTSTR)IDD_ABOUTBOX_MDI);
	}

	void OnTitle(WPARAM wParam, LPARAM lParam, HWND hWnd)
	{
		MDITile();
	}

	
/*	virtual LRESULT OnMeasureItem(LPMEASUREITEMSTRUCT lpms)
	{
		return CFrame::OnMeasureItem(lpms);
	}
	virtual BOOL OnDrawItem(LPDRAWITEMSTRUCT lpds)
	{
		return CFrame::OnDrawItem(lpds);
	}
*/	

BEGIN_MSG_MAP()
	 ON_WM_CREATE(OnCreate)
	 ON_COMMAND(ID_FILE_NEW_MDI,OnNew)
	 ON_WM_SIZE(OnSize) 
	 ON_COMMAND(ID_WINDOW_CASCADE_MDI,Cascade)
	 ON_COMMAND(ID_TOOLBAR_MDI,OnToolBar)
	 ON_COMMAND(IDM_EXIT_MDI,OnExit)
	 ON_COMMAND(ID_FILE_CLOSE_MDI,OnFileClose)
	 ON_COMMAND(ID_FILE_OPEN_MDI,OnFileOpen)
	 ON_COMMAND(ID_WINDOW_TILE_HORZ_MDI,OnTitle)
	 ON_COMMAND(IDM_ABOUT_MDI,OnAbout);
	 ON_WM_CLOSE(OnClose)
//	 ON_WM_DRAWITEM(OnDrawItem)
//	 ON_WM_MEASUREITEM(OnMeasureItem) 
END_MSG_MAP(CFrameMDI)

};

class CAppMain :public CApp 
{
public:
	~CAppMain();
	int InitInstance();
};
