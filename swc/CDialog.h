#pragma once

#include "stdafx.h"
#include "CWin.h"

class CDialog : public CWin
{
public:
	CDialog(HWND hWnd=NULL) :CWin(hWnd)
	{bDialog=TRUE;}
	~CDialog()
	{}
protected:
		BOOL LoopMsg;
		int  rsMsg;
public:

	LRESULT Run()
	{
		MSG msg;
		BOOL bPeekMsg=TRUE;
		LoopMsg=TRUE;
		while ( LoopMsg && ::GetMessage(&msg, NULL, 0, 0) ) 
		{
			if ( msg.hwnd == NULL ) continue;
			if ( msg.message == WM_QUIT )
			{
				LoopMsg=FALSE;
				::PostQuitMessage(( int )msg.wParam );
				
				break;
			}
			//bresult=(!TranslateAccelerator (msg.hwnd, theApp->GetAccelTable(), &msg));
			CWin* pActive= reinterpret_cast<CWin*>(::GetWindowLong(msg.hwnd,GWL_USERDATA)); 
			BOOL bPre=TRUE;
			if (pActive)
				bPre=pActive->PreTranslateMessage(&msg);
			if (bPre) 
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		return  rsMsg;
	}



	int DoModal( CWin* pParent, LPCTSTR pszDialogName )
	{
		HWND hFocus = ::GetFocus();
		if ( !Create( pParent==NULL?NULL:pParent, pszDialogName ))
			 return FALSE;
		ShowWindow();
		UpdateWindow();
		if ( pParent && pParent->IsWindowEnabled())
		{
			pParent->EnableWindow( FALSE );
		}
		int resp=Run();
		if ( pParent )
		{
		   pParent->EnableWindow( TRUE );
		   pParent->SetForegroundWindow();
		}

		int nResult=0;
		::DestroyWindow(GetSafeHwnd());
		if ( hFocus ) 
			::SetFocus( hFocus );
		return resp;
	}

	LRESULT DefWindowProc(HWND hWnd, UINT uID, WPARAM wParam, LPARAM lParam)
	{
		return 0;  //sin uso
	}


	int DoModal( LPCTSTR pszDialogName )
	{
		return DoModal(NULL,pszDialogName);
	}


	BOOL Create( CWin* pParent,LPCTSTR pszDialogName )
	{
		if ( !::CreateDialogParam( GetModuleHandle(NULL), pszDialogName, pParent->GetSafeHwnd(),
			   (DLGPROC)WndProc, ( LPARAM )this))
			return FALSE;
		return TRUE;
	}
		

		
	BOOL EndDialog( int nResult )
	{
		LoopMsg=FALSE;
		rsMsg=nResult;
		return TRUE;
	}

		// Overidables.
	virtual BOOL OnOK()
	{
		EndDialog(IDOK);
		return TRUE;
	}

	virtual BOOL OnCancel()
	{
		EndDialog(IDCANCEL);
		return TRUE;
	}

	virtual BOOL OnInitDialog(HWND wParam,LPARAM lParam)
	{
		return TRUE;
	}

	
	virtual BOOL PreTranslateMessage(MSG* pMsg)
	{
		return TRUE;
	}
	
	void MapDialogRect(LPRECT lpRect) 
	{ 
		ASSERT(::IsWindow(m_hWnd)); 
		::MapDialogRect(m_hWnd, lpRect); 
	}

	void NextDlgCtrl()
	{ 
		ASSERT(::IsWindow(m_hWnd)); 
		::SendMessage(m_hWnd, WM_NEXTDLGCTL, 0, 0); 
	}

	void PrevDlgCtrl()
	{ 
		ASSERT(::IsWindow(m_hWnd)); 
		::SendMessage(m_hWnd, WM_NEXTDLGCTL, 1, 0); 
	}

	void GotoDlgCtrl(CWin* pWndCtrl)
	{ 
		ASSERT(::IsWindow(m_hWnd)); 
		::SendMessage(m_hWnd, WM_NEXTDLGCTL, (WPARAM)pWndCtrl->GetSafeHwnd(), 1L); 
	}

	void SetDefID(UINT nID)
	{ 
		ASSERT(::IsWindow(m_hWnd)); 
		::SendMessage(m_hWnd, DM_SETDEFID, nID, 0); 
	}

	DWORD GetDefID()
	{ 
		ASSERT(::IsWindow(m_hWnd)); 
		return ::SendMessage(m_hWnd, DM_GETDEFID, 0, 0); 
	}
	
BEGIN_MSG_MAP()
	ON_WM_INITDIALOG(OnInitDialog)
END_MSG_MAP(CWin)
};
