#pragma once

#include "stdafx.h"
#include "debug.h"
#include "CMsg.h"
#include "CRect.h"

class CWin : public CMsg
{
protected: 
	HWND m_hWnd;
	HINSTANCE hInsTance;
	HWND hMDI;
	WNDPROC lpfnOldWndProc;
	WNDPROC lpfnSuperWndProc;
	BOOL bDialog;  //is a dialog box
	BOOL bChildWnd;	
	HWND m_OldHwnd;
	BOOL m_LoadCompleted;
	int  m_Icon;
public:
	UINT ID;
protected:



	HWND hWndt;
	UINT uIDt;
	WPARAM wParamt;
	LPARAM lParamt;


public:

	friend class CApp;
	

public:	

	CWin(HWND hWnd=NULL)
	{
		m_hWnd=hWnd;
		lpfnOldWndProc=NULL;
		lpfnSuperWndProc=NULL;
		bDialog=FALSE;
		bChildWnd=FALSE;
		m_OldHwnd=NULL;
		m_LoadCompleted=FALSE;
		m_Icon=-1;
	}
	virtual ~CWin(){}


	LPTSTR  RegisterDefaultClass(LPCTSTR lpClassName=NULL,DWORD dwStyle=0,LPCTSTR lpszIcon=0,LPCTSTR lpszCursor=0)
	{
		char* szTemp1;
		char szTemp[128];
		if (lpClassName == NULL)
			sprintf(szTemp,"SWC:%p",this );
		else
			strcpy(szTemp,lpClassName);
		WNDCLASSEX	wcex;
		wcex.cbSize		= sizeof(wcex); 
		wcex.lpfnWndProc	= (WNDPROC)CWin::WndProc;
		wcex.style			= 0;
		wcex.cbClsExtra		= 0;
		wcex.cbWndExtra		= 0;
		wcex.hInstance		= GetModuleHandle(NULL);
		wcex.hIcon			= LoadIcon (wcex.hInstance, IDI_APPLICATION) ;
		wcex.hCursor		= LoadCursor(wcex.hInstance, IDC_ARROW);
		wcex.hbrBackground	= (HBRUSH) (COLOR_BTNFACE+1);
		wcex.lpszMenuName	= (LPCSTR)NULL;
		wcex.lpszClassName	= szTemp;
		wcex.hIconSm		= LoadIcon(NULL, IDI_APPLICATION);
		if ( ! RegisterClassEx( &wcex ))
			return NULL;
		szTemp1=(char*)malloc(sizeof(char)*128);
		memset(szTemp1,0x00,128);
		strcpy(szTemp1,szTemp);
		return szTemp1;
		
	}
	
	BOOL LoadCompleted()
	{
		return m_LoadCompleted;
	}

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uID, WPARAM wParam, LPARAM lParam) 
		 { 
			
			CWin* pWnd=NULL; 
			BOOL  bClose=FALSE; 
			BOOL  bResult=FALSE;
			LRESULT lResult=0;
			if( uID == WM_INITDIALOG )	//is a dialog window
			{ 
				if (pWnd== NULL)
				{
					pWnd =reinterpret_cast<CWin*>(lParam); 
					::SetWindowLong(hWnd,GWL_USERDATA,reinterpret_cast<long> (pWnd)); pWnd->SethWnd(hWnd);
				}
			}else if( uID == WM_NCCREATE) //is a normal windows
			{ 
				pWnd =reinterpret_cast<CWin*> ((long)((LPCREATESTRUCT)lParam)->lpCreateParams); 
				BOOL res=pWnd->IsMDI();
				if (res == 0)
				{
					pWnd =reinterpret_cast<CWin*> ((long)((LPCREATESTRUCT)lParam)->lpCreateParams); 
				}
				else
				{
					LPMDICREATESTRUCT pmcs = ( LPMDICREATESTRUCT )(( LPCREATESTRUCT )lParam )->lpCreateParams;
					pWnd =reinterpret_cast<CWin*>(pmcs->lParam); 
					pWnd->SethWnd(hWnd);
				}
				::SetWindowLong(hWnd,GWL_USERDATA,reinterpret_cast<long>(pWnd));
				pWnd->SethWnd(hWnd);


			}
			pWnd= reinterpret_cast<CWin*>(::GetWindowLong(hWnd,GWL_USERDATA)); 
			if (pWnd!=NULL)
				pWnd->SaveMsg(hWnd,uID, wParam,lParam); //save the actually message, the idea is if you need to call  the default message [Default()]
			if (HIWORD(pWnd))
			{
				if(uID ==	WM_COMMAND)
				{
					CWin* pChild=reinterpret_cast<CWin*>((HWND)
							::GetWindowLong(pWnd->GetDlgItem( LOWORD(wParam)),
										GWL_USERDATA) ); 
					if (HIWORD(pChild))
					{
						int x=HIWORD(wParam);
						if (x == CBN_EDITCHANGE ) 
							pChild->OnCbnEditChange();
						if (x == CBN_KILLFOCUS ) 
							pChild->OnCbnKillFocus();
						if (x == CBN_EDITUPDATE       ) 
							pChild->OnCbnEditUpdate();
						if (x == CBN_CLOSEUP ) 
							pChild->OnCbnCloseUp();
						if (x == CBN_SELENDOK  ) 
							pChild->OnCbnSelendOk();
						if (x == CBN_SELENDCANCEL   ) 
							pChild->OnCbnSelendCandel();
						if (x == CBN_SELCHANGE ) 
							pChild->OnCbnSelChange();
						if (x == CBN_SETFOCUS ) 
							pChild->OnCbnSetFocus();
						if (x == CBN_DROPDOWN ) 
							pChild->OnCbnDropDown();
					}
					else
						pWnd->OnCommand(wParam,lParam);
						
				}
				else if( uID ==  WM_DESTROY)
				{
					if(IsWindow(pWnd->GetSafeHwnd()) )
						pWnd->OnDestroy();
					 return 0;
				}
				else if (uID ==  WM_NCDESTROY)
					return 0;
				else if(uID == WM_CLOSE)
				{
					bClose=TRUE;
					lResult=pWnd->OnClose();
				}
				else if(uID == WM_COMPAREITEM )
				{
					if(wParam != 0)
					{
						CWin* pChild=reinterpret_cast<CWin*>((HWND)
							 ::GetWindowLong(pWnd->GetDlgItem( ((( LPDRAWITEMSTRUCT )lParam)->CtlID) ),
										GWL_USERDATA) ); 
						bResult=pChild->OnCompareItem((LPCOMPAREITEMSTRUCT) lParam  );
						if(bResult && pWnd->IsDialog()) 
							return ::SetWindowLong(pWnd->GetSafeHwnd(), DWL_MSGRESULT, ( LONG )bResult);
					}
				}	
				else if( uID ==	WM_MEASUREITEM) 
				{
					if(wParam != 0)
					{
						CWin* pChild=reinterpret_cast<CWin*>((HWND)
							 ::GetWindowLong(pWnd->GetDlgItem( ((( LPMEASUREITEMSTRUCT )lParam)->CtlID) ),
										GWL_USERDATA) ); 
						bResult=pChild->OnMeasureItem((LPMEASUREITEMSTRUCT) lParam  );
						if(bResult && pWnd->IsDialog()) 
							::SetWindowLong(pWnd->GetSafeHwnd(), DWL_MSGRESULT, ( LONG )bResult);
					}
					
				}
				else if (uID ==	WM_DRAWITEM) 
				{					
					//el problema con estos mensajes es que nunca llegan al control directamente, inicialmente el mensaje se envia
					//  al propietario del control,luego es labor nuestra  enrutarlo desde aqui a quien debe manejarlo.
					//
					if(wParam != 0)
					{
						CWin* pChild=reinterpret_cast<CWin*>((HWND)
							::GetWindowLong(pWnd->GetDlgItem( ((( LPDRAWITEMSTRUCT )lParam)->CtlID) ),
										GWL_USERDATA) ); 
						bResult=pChild->OnDrawItem((LPDRAWITEMSTRUCT) lParam  );
						if(bResult && pWnd->IsDialog()) 
							::SetWindowLong(pWnd->GetSafeHwnd(), DWL_MSGRESULT, ( LONG )bResult);
					}
					
				}
				else if(uID	==	WM_NOTIFY)
				{
					LPNMHDR pNMHDR = ( LPNMHDR )lParam;

					CWin* pChild=reinterpret_cast<CWin*>((HWND)
							::GetWindowLong(pNMHDR->hwndFrom,
										GWL_USERDATA) ); 
					if ( pChild )
					{
						BOOL bNotify=TRUE;
						bResult = pChild->ReflectChildNotify( pNMHDR, bNotify);
						if ( pWnd->IsDialog())
							::SetWindowLong(pWnd->GetSafeHwnd(), DWL_MSGRESULT, ( LONG )bResult);
						
						if(bNotify)
							pWnd->OnNotify(wParam,pNMHDR);

						if (bResult != 0)
							return bResult;
					}

				}


				if( pWnd->IsDialog())
				{
					if (bClose)
						return 0;
					
					bResult=pWnd->NewMsgProc(hWnd,uID,wParam,lParam,lResult);
					if(!bResult) 
						return pWnd->DefWindowProc(pWnd->GetSafeHwnd(),uID,wParam,lParam); 
					return 0;
				}
				else
				{	
					
					if(bClose )
					{
						if(lResult) 
							return pWnd->DefWindowProc(pWnd->GetSafeHwnd(),uID,wParam,lParam); 
						return 0;
					}

					bResult=pWnd->NewMsgProc(hWnd,uID,wParam,lParam,lResult);
					if(!bResult) 
						return pWnd->DefWindowProc(hWnd,uID,wParam,lParam); 

					if (pWnd->IsMDI() )
						return pWnd->DefWindowProc(hWnd,uID,wParam,lParam); 
				}
				
			}
			return lResult;	
		} 


	//-------------------------------------------------------

	void SetNumIcon(int mNumIcon)
	{
		m_Icon=mNumIcon;
	}

	int  GetNumIcon()
	{
		return m_Icon;
	}
		

	//---------------------------------------------------------------------------------------

	virtual BOOL PreCreateWindow(LPCREATESTRUCT Cs)
	{
		if (Cs->lpszClass==NULL)
			Cs->lpszClass = _T( "SWCclass" );
		return TRUE;
	}
	
	
	virtual BOOL Create(LPCTSTR lpClassName,LPCTSTR lpWindowName,
	   DWORD dwStyle,CRect rc, HWND hwndParent,UINT uID,LPVOID lpParam=NULL)
	{
	
		BOOL bres=CreateEx(0,lpClassName,lpWindowName, 
			 dwStyle,rc,hwndParent,uID,lpParam);
		return bres;
	}


	//----------------------------------------------------------------------------------------

	BOOL CreateEx(DWORD dwExStyle,LPCTSTR lpClassName,LPCTSTR lpWindowName,
	   DWORD dwStyle,CRect rc,HWND hwndParent,UINT uID, LPVOID lpParam=NULL)
	{
		
		ID=uID;
		CREATESTRUCT	cs;
		cs.dwExStyle	= dwExStyle;
		cs.lpszClass	= lpClassName;
		cs.lpszName		= lpWindowName;
		cs.style		= dwStyle;
		cs.x			= rc.left;
		cs.y			= rc.top;
		cs.cx			=  rc.Width();
		cs.cy			= rc.Height();
		cs.hwndParent	= hwndParent;
		cs.hMenu		= (HMENU)uID;
		cs.lpCreateParams = lpParam;
		cs.hInstance=GetModuleHandle(NULL);
		
		if (PreCreateWindow(&cs))
		{
			if (hwndParent != NULL)
			{
				if(::IsWindow(hwndParent))
					lpfnSuperWndProc=(WNDPROC)GetProc(hwndParent);
			}
			cs.style|=WS_CLIPCHILDREN;
			m_hWnd=CreateWindowEx(cs.dwExStyle,cs.lpszClass,cs.lpszName, 
					 cs.style,cs.x, cs.y, cs.cx, cs.cy,hwndParent,
					 NULL, NULL,(void*)this);
			UINT d=GetLastError();
			(void)d;
			if (m_hWnd == NULL)
				return FALSE;
			
			SetWindowLong(m_hWnd,GWL_ID,uID);
			return TRUE;
		}
		return FALSE;
	}	


	//-----------------------------------------------------------------------------------------
	BOOL IsDialog()
	{
		return bDialog==TRUE;
	}

	BOOL IsMDI()
	{
		return bChildWnd;
	}
	//-----------------------------------------------------------------------------------------
	
	void SetOwner(HWND hWnd)
	{
		ASSERT(::IsWindow(hWnd))
			m_hWnd=hWnd;
	}
	//-----------------------------------------------------------------------------------------
	void Setm_hWnd(HWND hWND)
	{
		ASSERT(::IsWindow(hWnd))
			m_hWnd=hWND;
	}

	int GetSystemCaption()
	{
		return ::GetSystemMetrics(SM_CYCAPTION);
	}
	
	int GetSystemMenuHeight()
	{
		return ::GetSystemMetrics(SM_CYMENUSIZE);
	}

	int GetSystemBorderX()
	{
		return ::GetSystemMetrics(SM_CXBORDER);
	}

	int GetSystemBorderY()
	{
		return ::GetSystemMetrics(SM_CYBORDER);
	}

	inline int  MsgBox(LPCTSTR lpText,LPCTSTR lpCaption=NULL, UINT uType=MB_OK)
	{	ASSERT(::IsWindow(m_hWnd)) return MessageBox(m_hWnd,lpText,lpCaption,uType); }

	BOOL SetMenu(HMENU hMenu)
	{	ASSERT(::IsWindow(m_hWnd)) return ::SetMenu(m_hWnd,hMenu); }
	 
	inline HACCEL LoadAccelerators(LPCTSTR lpRc)
	{	return ::LoadAccelerators(hInsTance,lpRc);	}

	inline HWND GetSafeHwnd()
	{	ASSERT(::IsWindow(m_hWnd)) return m_hWnd;
		
	}

	int GetClassName(HWND m_hWnd,LPTSTR lpClassName)
	{
		return ::GetClassName(m_hWnd,lpClassName,sizeof(lpClassName)/sizeof(lpClassName[0]));
	}

	int GetClassName(LPTSTR lpClassName)
	{
		return GetClassName(m_hWnd,lpClassName);
	}

	//----------------------------------------------------------------------------------------
	inline LRESULT SendMessage(UINT message, WPARAM wParam, LPARAM lParam)
	{	ASSERT(::IsWindow(m_hWnd)) return ::SendMessage(m_hWnd, message, wParam, lParam);  }

	inline BOOL PostMessage(UINT message, WPARAM wParam, LPARAM lParam)
	{ 	ASSERT(::IsWindow(m_hWnd)) return ::PostMessage(m_hWnd, message, wParam, lParam); }

	inline BOOL DragDetect(POINT pt) 
	{ 	ASSERT(::IsWindow(m_hWnd)) return ::DragDetect(m_hWnd, pt); }

	inline void SetWindowText(LPCTSTR lpszString)
	{ 	ASSERT(::IsWindow(m_hWnd)) ::SetWindowText(m_hWnd, lpszString); }

	inline int GetWindowText(LPTSTR lpszString, int nMaxCount) 
		{ ASSERT(::IsWindow(m_hWnd))  return ::GetWindowText(m_hWnd, lpszString, nMaxCount); }
	inline int GetWindowTextLength() 
		{ ASSERT(::IsWindow(m_hWnd))  return ::GetWindowTextLength(m_hWnd); }

	inline HMENU GetMenu() 
		{ ASSERT(::IsWindow(m_hWnd))  return ::GetMenu(m_hWnd); }

	inline void DrawMenuBar()
		{ ASSERT(::IsWindow(m_hWnd))  ::DrawMenuBar(m_hWnd); }
	inline HMENU GetSystemMenu(BOOL bRevert) 
		{ ASSERT(::IsWindow(m_hWnd))  return ::GetSystemMenu(m_hWnd, bRevert); }
	inline BOOL HiliteMenuItem(HMENU hMenu, UINT uIDHiliteItem, UINT uHilite)
		{ ASSERT(::IsWindow(m_hWnd))  return ::HiliteMenuItem(m_hWnd,hMenu, uIDHiliteItem, uHilite); }
	inline int GetDlgCtrlID() 
		{ ASSERT(::IsWindow(m_hWnd))  return ::GetDlgCtrlID(m_hWnd); }
	inline int SetDlgCtrlID(int nID)
		{ ASSERT(::IsWindow(m_hWnd))  return (int)::SetWindowLong(m_hWnd, GWL_ID, nID); }
	inline BOOL IsIconic() 
		{ ASSERT(::IsWindow(m_hWnd))  return ::IsIconic(m_hWnd); }
	inline BOOL IsZoomed() 
		{ ASSERT(::IsWindow(m_hWnd))  return ::IsZoomed(m_hWnd); }
	inline void MoveWindow(int x, int y, int nWidth, int nHeight, BOOL bRepaint=TRUE)
		{ ASSERT(::IsWindow(m_hWnd))  ::MoveWindow(m_hWnd, x, y, nWidth, nHeight, bRepaint); }
	inline void MoveWindow(LPCRECT lpRect, BOOL bRepaint=TRUE)
		{ MoveWindow(lpRect->left, lpRect->top, lpRect->right - lpRect->left,
			lpRect->bottom - lpRect->top, bRepaint); }
	inline BOOL SetWindowPos(HWND m_hWndAfter, int x, int y, int cx, int cy, UINT uFlags)
		{ ASSERT(::IsWindow(m_hWnd))  return ::SetWindowPos(m_hWnd, m_hWndAfter,
			x, y, cx, cy, uFlags); }
	inline BOOL SetWindowPos(HWND m_hWndAfter,CRect rc, UINT uFlags)
		{ ASSERT(::IsWindow(m_hWnd))  return ::SetWindowPos(m_hWnd, m_hWndAfter,
			rc.left, rc.top, rc.right, rc.bottom, uFlags); }

	inline UINT ArrangeIconicWindows()
		{ ASSERT(::IsWindow(m_hWnd))  return ::ArrangeIconicWindows(m_hWnd); }
	inline int SetWindowRgn(HRGN hRgn, BOOL bRedraw)
		{ ASSERT(::IsWindow(m_hWnd))  return ::SetWindowRgn(m_hWnd, hRgn, bRedraw); }
	inline int GetWindowRgn(HRGN hRgn) 
		{ if(::IsWindow(m_hWnd) && hRgn != NULL) {return ::GetWindowRgn(m_hWnd, hRgn);} return 0; }
	inline void BringWindowToTop()
		{ ASSERT(::IsWindow(m_hWnd))  ::BringWindowToTop(m_hWnd); }
	inline void GetWindowRect(LPRECT lpRect) 
		{ ASSERT(::IsWindow(m_hWnd))  ::GetWindowRect(m_hWnd, lpRect); }
	inline void GetClientRect(LPRECT lpRect) 
		{ ASSERT(::IsWindow(m_hWnd))  ::GetClientRect(m_hWnd, lpRect); }
	inline void MapWindowPoints(CWin* pwndTo, LPPOINT lpPoint, UINT uCount) 
		{ ASSERT(::IsWindow(m_hWnd))  ::MapWindowPoints(m_hWnd, pwndTo->GetSafeHwnd(), lpPoint, uCount); }
	inline void MapWindowPoints(CWin* pwndTo, LPRECT lpRect) 
		{ ASSERT(::IsWindow(m_hWnd))  ::MapWindowPoints(m_hWnd, pwndTo->GetSafeHwnd(), (LPPOINT)lpRect, 2); }
	
	
	inline void ClientToScreen(LPPOINT lpPoint) 
		{ ASSERT(::IsWindow(m_hWnd))  ::ClientToScreen(m_hWnd, lpPoint); }
	inline void ScreenToClient(LPPOINT lpPoint) 
		{ ASSERT(::IsWindow(m_hWnd))  ::ScreenToClient(m_hWnd, lpPoint); }
	
	inline void ScreenToClient(LPRECT lpRect)
	{
		ASSERT(::IsWindow(m_hWnd));
		::ScreenToClient(m_hWnd, (LPPOINT)lpRect);
		::ScreenToClient(m_hWnd, ((LPPOINT)lpRect)+1);
	}

	inline void ClientToScreen(LPRECT lpRect)
	{
		ASSERT(::IsWindow(m_hWnd));
		::ClientToScreen(m_hWnd, (LPPOINT)lpRect);
		::ClientToScreen(m_hWnd, ((LPPOINT)lpRect)+1);
	}

	
	inline HDC  BeginPaint(LPPAINTSTRUCT lpPaint)
		{ ASSERT(::IsWindow(m_hWnd))  return ::BeginPaint(m_hWnd, lpPaint); }
	inline void EndPaint(LPPAINTSTRUCT lpPaint)
		{ ASSERT(::IsWindow(m_hWnd))  ::EndPaint(m_hWnd, lpPaint); }
	inline HDC  GetDC()
		{ ASSERT(::IsWindow(m_hWnd))  return ::GetDC(m_hWnd); }
	inline HDC  GetWindowDC()
		{ ASSERT(::IsWindow(m_hWnd))  return ::GetWindowDC(m_hWnd); }
	inline int ReleaseDC(HDC hDC)
		{ ASSERT(::IsWindow(m_hWnd))  return ::ReleaseDC(m_hWnd, hDC); }
	inline void UpdateWindow()
		{ ASSERT(::IsWindow(m_hWnd))  ::UpdateWindow(m_hWnd); }
	inline void SetRedraw(BOOL bRedraw)
		{ ASSERT(::IsWindow(m_hWnd))  ::SendMessage(m_hWnd, WM_SETREDRAW, bRedraw, 0); }
	inline BOOL GetUpdateRect(LPRECT lpRect, BOOL bErase)
		{ ASSERT(::IsWindow(m_hWnd))  return ::GetUpdateRect(m_hWnd, lpRect, bErase); }
	inline int GetUpdateRgn(HRGN hRgn, BOOL bErase)
		{ ASSERT(::IsWindow(m_hWnd))  return ::GetUpdateRgn(m_hWnd, hRgn, bErase); }
	inline void Invalidate(BOOL bErase=TRUE)
		{ ASSERT(::IsWindow(m_hWnd))  ::InvalidateRect(m_hWnd, NULL, bErase); }
	inline void InvalidateRect(LPCRECT lpRect, BOOL bErase=TRUE)
		{ ASSERT(::IsWindow(m_hWnd))  ::InvalidateRect(m_hWnd, lpRect, bErase); }
	inline void InvalidateRgn(HRGN hRgn, BOOL bErase)
		{ ASSERT(::IsWindow(m_hWnd))  ::InvalidateRgn(m_hWnd, hRgn, bErase); }
	inline void ValidateRect(LPCRECT lpRect)
		{ ASSERT(::IsWindow(m_hWnd))  ::ValidateRect(m_hWnd, lpRect); }
	inline void ValidateRgn(HRGN hRgn)
		{ ASSERT(::IsWindow(m_hWnd))  ::ValidateRgn(m_hWnd, hRgn); }
	inline BOOL ShowWindow(int nCmdShow=SW_SHOW)
		{ ASSERT(::IsWindow(m_hWnd))  return ::ShowWindow(m_hWnd, nCmdShow); }
	inline BOOL IsWindowVisible() 
		{ ASSERT(::IsWindow(m_hWnd))  return ::IsWindowVisible(m_hWnd); }
	inline void ShowOwnedPopups(BOOL bShow)
		{ ASSERT(::IsWindow(m_hWnd))  ::ShowOwnedPopups(m_hWnd, bShow); }
	
	inline BOOL IsDialogMessage(LPMSG lpMsg)
		{ ASSERT(::IsWindow(m_hWnd))  return ::IsDialogMessage(m_hWnd, lpMsg); }

	inline HDC  GetDCEx(HRGN prgnClip, DWORD flags)
		{ ASSERT(::IsWindow(m_hWnd))  return ::GetDCEx(m_hWnd, prgnClip, flags); }
	inline BOOL LockWindowUpdate()
		{ ASSERT(::IsWindow(m_hWnd))  return ::LockWindowUpdate(m_hWnd); }
	inline void UnlockWindowUpdate()
		{ ASSERT(::IsWindow(m_hWnd))  ::LockWindowUpdate(NULL); }
	inline BOOL  RedrawWindow(LPCRECT lpRectUpdate, HRGN prgnUpdate,
		UINT flags)
		{ ASSERT(::IsWindow(m_hWnd))  return ::RedrawWindow(m_hWnd, lpRectUpdate, prgnUpdate, flags); }
	inline BOOL EnableScrollBar(int nSBFlags, UINT uArrowFlags)
		{ ASSERT(::IsWindow(m_hWnd))  return ::EnableScrollBar(m_hWnd, nSBFlags, uArrowFlags); }
	inline BOOL DrawAnimatedRects(int idAni, CONST RECT *lprcFrom, CONST RECT *lprcTo)
		{ ASSERT(::IsWindow(m_hWnd))  return (BOOL)::DrawAnimatedRects(m_hWnd, idAni, lprcFrom, lprcTo); }
	inline BOOL  DrawCaption(HDC hDC, LPCRECT lprc, UINT uFlags)
		{ ASSERT(::IsWindow(m_hWnd))  return (BOOL)::DrawCaption(m_hWnd, hDC, lprc, uFlags); }

	inline UINT SetTimer(UINT uIDEvent, UINT uElapse,
		void (CALLBACK* lpfnTimer)(HWND, UINT, UINT, DWORD))
	{ ASSERT(::IsWindow(m_hWnd)) return ::SetTimer(m_hWnd, uIDEvent, uElapse,
		(TIMERPROC)lpfnTimer); }

	
	
	inline BOOL  KillTimer(UINT uIDEvent)
		{ ASSERT(::IsWindow(m_hWnd))  return ::KillTimer(m_hWnd, uIDEvent); }

	inline BOOL  IsWindowEnabled() 
	{ ASSERT(::IsWindow(m_hWnd))  return ::IsWindowEnabled(m_hWnd); }
	inline BOOL  EnableWindow(BOOL bEnable)
	{ ASSERT(::IsWindow(m_hWnd))  return ::EnableWindow(m_hWnd, bEnable); }

	inline HWND GetActiveWindow()
	{	return ::GetActiveWindow(); }
	inline HWND SetActiveWindow()
	{ ASSERT(::IsWindow(m_hWnd))  return ::SetActiveWindow(m_hWnd); }
	inline HWND GetCapture()
	{ return ::GetCapture(); }
	inline HWND SetCapture()	{ ASSERT(::IsWindow(m_hWnd))  return ::SetCapture(m_hWnd); }
	inline HWND GetFocus()	{ return ::GetFocus(); }
	inline HWND SetFocus()	{ ASSERT(::IsWindow(m_hWnd))  return ::SetFocus(m_hWnd); }

	inline HWND GetDesktopWindow(){ return ::GetDesktopWindow(); }


	inline void CheckDlgButton(int nIDButton, UINT uCheck)
	{ ASSERT(::IsWindow(m_hWnd))  ::CheckDlgButton(m_hWnd, nIDButton, uCheck); }
	inline void CheckRadioButton(int nIDFirstButton, int nIDLastButton,int nIDCheckButton)
	{ ASSERT(::IsWindow(m_hWnd))  ::CheckRadioButton(m_hWnd, nIDFirstButton, nIDLastButton, nIDCheckButton); }


	inline int DlgDirList(LPTSTR lpPathSpec, int nIDListBox,int nIDStaticPath, UINT uFileType)
	{ ASSERT(::IsWindow(m_hWnd))  return ::DlgDirList(m_hWnd, lpPathSpec, nIDListBox,nIDStaticPath, uFileType); }
	inline int DlgDirListComboBox(LPTSTR lpPathSpec, int nIDComboBox,int nIDStaticPath, UINT uFileType)
	{ ASSERT(::IsWindow(m_hWnd))  return ::DlgDirListComboBox(m_hWnd, lpPathSpec,nIDComboBox, nIDStaticPath, uFileType); }
	inline BOOL DlgDirSelect(LPTSTR lpString, int nIDListBox)
	{ ASSERT(::IsWindow(m_hWnd))  return ::DlgDirSelectEx(m_hWnd, lpString, _MAX_PATH, nIDListBox); }
	inline BOOL DlgDirSelectComboBox(LPTSTR lpString, int nIDComboBox)
	{ ASSERT(::IsWindow(m_hWnd))  return ::DlgDirSelectComboBoxEx(m_hWnd, lpString, _MAX_PATH, nIDComboBox);}

	inline HWND GetDlgItem(int nID) 
	{ ASSERT(::IsWindow(m_hWnd))  return ::GetDlgItem(m_hWnd, nID); }
	inline void GetDlgItem(int nID, HWND* pm_hWnd) 
	{ ASSERT(::IsWindow(m_hWnd))  (pm_hWnd != NULL); *pm_hWnd = ::GetDlgItem(m_hWnd, nID); }
	inline UINT GetDlgItemInt(int nID, BOOL* lpTrans,BOOL bSigned) 
	{ ASSERT(::IsWindow(m_hWnd))  return ::GetDlgItemInt(m_hWnd, nID, lpTrans, bSigned);}
	inline int GetDlgItemText(int nID, LPTSTR lpStr, int nMaxCount) 
	{ ASSERT(::IsWindow(m_hWnd))  return ::GetDlgItemText(m_hWnd, nID, lpStr, nMaxCount);}


	inline HWND GetNextDlgGroupItem(CWin* pWndCtl, BOOL bPrevious) 
	{ ASSERT(::IsWindow(m_hWnd))  return  ::GetNextDlgGroupItem(m_hWnd,
			pWndCtl->GetSafeHwnd(), bPrevious); }
	inline HWND GetNextDlgTabItem(CWin* pWndCtl, BOOL bPrevious) 
	{ ASSERT(::IsWindow(m_hWnd))  return  ::GetNextDlgTabItem(m_hWnd,
			pWndCtl->GetSafeHwnd(), bPrevious); }


	inline UINT IsDlgButtonChecked(int nIDButton) 
	{ ASSERT(::IsWindow(m_hWnd))  return ::IsDlgButtonChecked(m_hWnd, nIDButton); }
	inline LPARAM SendDlgItemMessage(int nID, UINT message, WPARAM wParam, LPARAM lParam)
	{ ASSERT(::IsWindow(m_hWnd))  return ::SendDlgItemMessage(m_hWnd, nID, message, wParam, lParam); }
	inline void SetDlgItemInt(int nID, UINT uValue, BOOL bSigned)
	{ ASSERT(::IsWindow(m_hWnd))  ::SetDlgItemInt(m_hWnd, nID, uValue, bSigned); }
	inline void SetDlgItemText(int nID, LPCTSTR lpszString)
	{ ASSERT(::IsWindow(m_hWnd))  ::SetDlgItemText(m_hWnd, nID, lpszString); }
	inline int ScrollWindowEx(int dx, int dy,LPCRECT lpRectScroll, LPCRECT lpRectClip,
									HRGN prgnUpdate, LPRECT lpRectUpdate, UINT flags)
	{ ASSERT(::IsWindow(m_hWnd))  return ::ScrollWindowEx(m_hWnd, dx, dy, lpRectScroll, lpRectClip,
			prgnUpdate, lpRectUpdate, flags); }


	inline void ShowScrollBar(UINT uBar, BOOL bShow)
	{ ASSERT(::IsWindow(m_hWnd))  ::ShowScrollBar(m_hWnd, uBar, bShow); }
	inline HWND ChildWindowFromPoint(POINT point) 
	{ ASSERT(::IsWindow(m_hWnd))  return ::ChildWindowFromPoint(m_hWnd, point); }
	inline HWND ChildWindowFromPoint(POINT point, UINT uFlags) 
	{ ASSERT(::IsWindow(m_hWnd))  return ::ChildWindowFromPointEx(m_hWnd, point, uFlags); }
	inline HWND  FindWindow(LPCTSTR lpszClassName, LPCTSTR lpszWindowName)
	{ return ::FindWindow(lpszClassName, lpszWindowName); }
	inline  HWND FindWindowEx(HWND hwndParent, HWND hwndChildAfter, LPCTSTR lpszClass, LPCTSTR lpszWindow)
	{ return ::FindWindowEx(hwndParent, hwndChildAfter, lpszClass, lpszWindow); }

	inline HWND GetNextWindows(UINT uFlag= GW_HWNDNEXT ) 
	{ ASSERT(::IsWindow(m_hWnd))  return ::GetWindow(m_hWnd, uFlag); }
	inline HWND GetTopWindow() 
	{ ASSERT(::IsWindow(m_hWnd))  return ::GetTopWindow(m_hWnd); }
	inline  HWND GetWindow(UINT uCmd) 
	{ ASSERT(::IsWindow(m_hWnd))  return ::GetWindow(m_hWnd, uCmd); }
	inline HWND GetLastActivePopup() 
	{ ASSERT(::IsWindow(m_hWnd))  return ::GetLastActivePopup(m_hWnd); }
	inline BOOL  IsChild( CWin* pWnd) 
	{ ASSERT(::IsWindow(m_hWnd))  return ::IsChild(m_hWnd, pWnd->GetSafeHwnd()); }
	inline HWND  GetParent() 
	{ ASSERT(::IsWindow(m_hWnd))  return ::GetParent(m_hWnd);  }
	inline HWND SetParent(CWin* pWndNewParent)
	{ ASSERT(::IsWindow(m_hWnd))  return ::SetParent(m_hWnd,pWndNewParent->GetSafeHwnd()); }
	inline HWND PASCAL  WindowFromPoint(POINT point)
	{ return ::WindowFromPoint(point); }
	inline BOOL FlashWindow(BOOL bInvert)
	{ ASSERT(::IsWindow(m_hWnd))  return ::FlashWindow(m_hWnd, bInvert); }
	inline BOOL ChangeClipboardChain(HWND m_hWndNext)
	{ ASSERT(::IsWindow(m_hWnd))  return ::ChangeClipboardChain(m_hWnd, m_hWndNext); }
	inline HWND  SetClipboardViewer()
	{ ASSERT(::IsWindow(m_hWnd))  return ::SetClipboardViewer(m_hWnd); }
	inline BOOL  OpenClipboard()
	{ ASSERT(::IsWindow(m_hWnd))  return ::OpenClipboard(m_hWnd); }
	inline HWND  GetOpenClipboardWindow()
	{ return  ::GetOpenClipboardWindow(); }
	inline HWND  GetClipboardOwner()
	{ return  ::GetClipboardOwner(); }
	inline HWND  GetClipboardViewer()
	{ return  ::GetClipboardViewer(); }
	inline void  CreateCaret(HBITMAP hBitmap)
	{ ASSERT(::IsWindow(m_hWnd))  ::CreateCaret(m_hWnd, hBitmap, 0, 0); }
	inline void  CreateSolidCaret(int nWidth, int nHeight)
	{ ASSERT(::IsWindow(m_hWnd))  ::CreateCaret(m_hWnd, (HBITMAP)0, nWidth, nHeight); }
	inline void  CreateGrayCaret(int nWidth, int nHeight)
	{ ASSERT(::IsWindow(m_hWnd))  ::CreateCaret(m_hWnd, (HBITMAP)1, nWidth, nHeight); }
	inline POINT  GetCaretPos(LPPOINT lpPoint)
	{  ::GetCaretPos(lpPoint); return *lpPoint; }
	inline void PASCAL  SetCaretPos(POINT point)
	{ ::SetCaretPos(point.x, point.y); }
	inline void  HideCaret()
	{ ASSERT(::IsWindow(m_hWnd))  ::HideCaret(m_hWnd); }
	inline void  ShowCaret()
	{ ASSERT(::IsWindow(m_hWnd))  ::ShowCaret(m_hWnd); }
	inline BOOL  SetForegroundWindow()
	{ ASSERT(::IsWindow(m_hWnd))  return ::SetForegroundWindow(m_hWnd); }
	inline HWND  GetForegroundWindow()
	{ return  ::GetForegroundWindow(); }

	inline BOOL  SendNotifyMessage(UINT message, WPARAM wParam, LPARAM lParam)
	{ ASSERT(::IsWindow(m_hWnd))  return ::SendNotifyMessage(m_hWnd, message, wParam, lParam); }

	inline HICON  SetIcon(HICON hIcon, BOOL bBigIcon)
	{ ASSERT(::IsWindow(m_hWnd))  return (HICON)::SendMessage(m_hWnd, WM_SETICON, bBigIcon, (LPARAM)hIcon); }
	inline HICON  GetIcon(BOOL bBigIcon) 
	{ ASSERT(::IsWindow(m_hWnd))  return (HICON)::SendMessage(m_hWnd, WM_GETICON, bBigIcon, 0); }
	inline void  Print(HDC hDC, DWORD dwFlags) 
	{ ASSERT(::IsWindow(m_hWnd))  ::SendMessage(m_hWnd, WM_PRINT, (WPARAM)hDC, dwFlags); }
	inline void  PrintClient(HDC hDC, DWORD dwFlags) 
	{ ASSERT(::IsWindow(m_hWnd))  ::SendMessage(m_hWnd, WM_PRINTCLIENT, (WPARAM)hDC, dwFlags); }
	//----------------------------------------------------------------------------------------

	DWORD DeferWindow(HDWP hWinPosInfo,HWND hWnd,HWND hWndInsertAfter,int x, int y, int cx,int cy, UINT uFlags)
	{
		if (hWinPosInfo)
			return (DWORD)::DeferWindowPos(hWinPosInfo,hWnd,hWndInsertAfter,x,y,cx,cy,uFlags);
		else
			return (DWORD)SetWindowPos(hWndInsertAfter,x,y,cx,cy,uFlags);
	}

	DWORD DeferWindow(HDWP hWinPosInfo,HWND hWnd,HWND hWndInsertAfter,CRect rc, UINT uFlags)
	{
		return DeferWindow(hWinPosInfo,hWnd,hWndInsertAfter,rc.left,rc.top,rc.right,rc.bottom,uFlags);
	}

	BOOL GetScrollRange(int nBar,LPINT lpMinPos,LPINT lpMaxPos )
	{
		ASSERT(::IsWindow(m_hWnd))
			return ::GetScrollRange(m_hWnd,nBar,lpMinPos,lpMaxPos);
	}

	BOOL SetScrollRange(int nBar,int nMinPos,int nMaxPos,BOOL bRedraw=TRUE)
	{
		ASSERT(::IsWindow(m_hWnd))
			return ::SetScrollRange(m_hWnd,nBar,nMinPos,nMaxPos,bRedraw);
	}

	int SetScrollPos(int nBar,int nPos,BOOL bRedraw=TRUE)
	{
		ASSERT(::IsWindow(m_hWnd))
			return ::SetScrollPos(m_hWnd,nBar,nPos,bRedraw);
 	}
	
	int GetScrollPos(int nBar)
	{
		ASSERT(::IsWindow(m_hWnd))
		return ::GetScrollPos(m_hWnd,nBar);
	}

	int SetScrollInfo(int fnBar,LPSCROLLINFO lpsi,BOOL fRedraw=TRUE)
	{
		ASSERT(::IsWindow(m_hWnd))
			return ::SetScrollInfo(m_hWnd,fnBar,lpsi,fRedraw);
	}

	
	BOOL GetScrollInfo(int fnBar,LPSCROLLINFO lpsi)
	{
		ASSERT(::IsWindow(m_hWnd))
			return ::GetScrollInfo(m_hWnd,fnBar,lpsi);
	}



	BOOL GetWindowPlacement(WINDOWPLACEMENT *lpwndpl)
	{
		return ::GetWindowPlacement(m_hWnd,lpwndpl);
	}
	
	void ModifyExStyle( DWORD dwRmStyle, DWORD dwAddStyle, DWORD dwFlags=0,UINT uStyle=GWL_EXSTYLE  )
	{
		ASSERT( m_hWnd);
			
		DWORD m_dStyle = ::GetWindowLong( m_hWnd, GWL_STYLE );
	
		m_dStyle &= ~dwRmStyle;
		m_dStyle |= dwAddStyle;
	
		::SetWindowLong( m_hWnd, uStyle, ( LONG )( m_dStyle | dwFlags ));
	}
	
	void ModifyStyle( DWORD dwRmStyle, DWORD dwAddStyle, DWORD dwFlags=0,UINT uStyle=GWL_STYLE  )
	{
		ModifyExStyle( dwRmStyle,dwAddStyle,dwFlags,uStyle );
	}
	
	HFONT GetFont() const
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HFONT)::SendMessage(m_hWnd, WM_GETFONT, 0, 0);
	}

	//----------------------------------------------------------------------------------------
    LONG GetProc(HWND hWnd)
	{
		ASSERT(::IsWindow(hWnd))
		return (LONG)GetWindowLong(hWnd,GWL_WNDPROC);
		
	}
	//----------------------------------------------------------------------------------------
	UINT GetIDWindow()
	{
		ASSERT(::IsWindow(m_hWnd))
		return (BOOL)GetWindowLong(m_hWnd,GWL_ID);
	}

	HWND GetChild()
	{
		return GetWindow(GW_CHILD);
	}
	

	//----------------------------------------------------------------------------------------

	void SetDefProc(WNDPROC bNewWproc)
	{
		SetWindowLong(m_hWnd,GWL_WNDPROC,(LONG)bNewWproc);
	}

	//-----------------------------------------------------------------------------------------
	void SethWnd(HWND hWND)
	{
		ASSERT(HIWORD(hWND))
		m_hWnd=hWND;
	}

	//-----------------------------------------------------------------------------------------
	void WriteString(LPCSTR tsrcCad, LPCSTR subKey, LPCSTR Key)
	{
		HKEY hk;
		char szBuf[2048];
	
		if (RegCreateKey(HKEY_CURRENT_USER, _T(subKey), &hk))
			return;
		strcpy(szBuf, tsrcCad);

		if (RegSetValueEx(hk, _T(Key), 0, REG_EXPAND_SZ, (LPBYTE)szBuf, strlen(tsrcCad) + 1))
			return;
		
		RegCloseKey(hk);
	}

	

	char* ReadString(LPCSTR subKey, LPCSTR Key)
	{
		HKEY hk;
		char* str=(char*)malloc(2048);
		DWORD length = 2048;

		if (RegOpenKey(HKEY_CURRENT_USER, _T(subKey), &hk))
			return NULL;

		if (RegQueryValueEx(hk, _T(Key), NULL, NULL, (LPBYTE)str, &length))
			return NULL;

		RegCloseKey(hk);
		
		return str;
	}

	// Writing integers to the register

	void WriteInteger(int n, LPCSTR subKey, LPCSTR Key)
	{	
		char buffer[2048];
		_itoa(n, buffer, 10);
		WriteString(buffer, subKey, Key);
	}

	// Reading integers from the register

	int ReadInteger(LPCSTR subKey, LPCSTR Key)
	{
		char* strCad = ReadString(subKey, Key);
		int n=0;
		if (strCad == NULL)
			n=0;
		else
			n = atoi(strCad);
		return n;
	}
	//-----------------------------------------------------------------------------------------
	PTSTR  GetCtrlText()
	{
		int    iLength ;
		PTSTR  pstrCad;
	     		  
		iLength = GetWindowTextLength () ;
	     
		pstrCad = (PTSTR) malloc ((iLength + 1) * sizeof (TCHAR));
		if (pstrCad==NULL)
			return NULL;
	     
		GetWindowText (pstrCad, iLength + 1) ;
	        return pstrCad;
	}
	
	
	//-------------------------------------------------------
	
	BOOL SubclassWnd(HWND hWnd)
	{
		if (!::IsWindow(hWnd) )
			return FALSE;
		if (lpfnOldWndProc!=NULL) //is it subclass? 
			return TRUE;
		lpfnOldWndProc =(WNDPROC)GetProc(hWnd);
		if (lpfnOldWndProc== NULL || lpfnOldWndProc == WndProc )
			return FALSE;
		PreSubClassWnd();
		m_hWnd=hWnd;
		lpfnOldWndProc =(WNDPROC)::SetWindowLong(hWnd, GWL_WNDPROC, (DWORD)WndProc);
		CWin* pWnd =reinterpret_cast<CWin*>(this); 
		::SetWindowLong(hWnd,GWL_USERDATA,reinterpret_cast<long> (pWnd));
		return TRUE;

	}

	//--------------------------------------------------------
	void UnSubClassWnd()
	{
		if(!::IsWindow(m_hWnd)) return;
		if (lpfnOldWndProc)
		{			
		    SetWindowLong (m_hWnd, GWL_WNDPROC, (DWORD)lpfnOldWndProc); 
		    m_hWnd=NULL;	
		    lpfnOldWndProc=NULL;
		}
		
	}

	void LINK_Control(int nIDC, CWin& pCtrl)
	{
		if (pCtrl.m_hWnd == NULL) 
		{
			HWND hWnd = ::GetDlgItem(GetSafeHwnd(),nIDC);
			pCtrl.SethWnd(hWnd);
			if (!pCtrl.SubclassWnd(hWnd))
				return ;

		}
	}
	//  --------------------	virtual functions	------------------------------
	//------------------------------------------------------
	
	virtual BOOL OnSysColorChange()
	{
		return FALSE;
	}
	
	virtual BOOL OnIdle()
	{
		return FALSE; 
	}

	//------------------------------------------------------
	virtual void PreSubClassWnd()
	{ 
		
	}
	
	virtual BOOL PreTranslateMessage(MSG* pMsg)
	{
		if( IsDialog() && IsDialogMessage( pMsg) )
			return FALSE;
		CWin* pChild= reinterpret_cast<CWin*>(::GetWindowLong(GetParent(),GWL_USERDATA));//GetUserPointerWindow(GetParent()); 
		if(pChild) 
			if (pChild->IsDialogMessage( pMsg))
				return FALSE;
		return TRUE; /*go ahead with the message loop*/
		
	}
	
	virtual  LRESULT DefWindowProc(HWND hWnd, UINT uID, WPARAM wParam, LPARAM lParam)
	{
		if (lpfnOldWndProc !=NULL )
			return ::CallWindowProc(lpfnOldWndProc, hWnd, uID,wParam, lParam); 
		return ::DefWindowProc(hWnd,uID,wParam,lParam);
	}

	virtual BOOL OnDestroy();
	

	virtual void OnNcDestroy(LPCREATESTRUCT lParam)
	{
		m_hWnd=NULL;
		lpfnOldWndProc=NULL;
		lpfnSuperWndProc=NULL;
		bDialog=FALSE;  
		bChildWnd=FALSE;			
	}

	virtual BOOL OnCompareItem( LPCOMPAREITEMSTRUCT lpCompareItemsStruct)
	{
		return FALSE;
	}
	virtual LRESULT OnMeasureItem( LPMEASUREITEMSTRUCT lpMeasureItemStruct  )
	{
		return FALSE;
	}
	virtual BOOL OnDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct  )
	{
		return FALSE;
	}

	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam)
	{
		return FALSE;
	}

	virtual BOOL OnNotify(WPARAM wParam,  LPNMHDR pnmh)
	{

		return FALSE;
	}

	virtual LRESULT ReflectChildNotify( LPNMHDR pnmh, BOOL &bNotify)
	{
		return FALSE;
	}
	/*
		la idea de esta funcion es la siguiente, cada mensaje es enviado al procedimiento
		por defecto si no se procesa.
	    Si el mensaje se procesa o por lo menos existe en el mapa de mensajes de la ventana 
		el enrutador de mensajes WndProc nunca lo enviara
	    al procedimiento DefWindproc por lo que este se queda sin procesar, 
		ejemplo si usted define el mensaje WM_LBUTTONDOWN para hace subclassing de un boton
	    y efectua alguna accion  el comportamiento de un boton presionado se pierde por lo que 
		debe hacer un llamado a Default()
		Este tipo de mecanismo lo tiene incorporado MFC, la diferencia esta en que todos 
		los mensajes entan mapeados y esto adiciona gran cantidad de codigo. Ejemplo
	    void On_LButtonDown(....)
		{
			//mi codigo
			CWnd::On_LButtonDown(...);
		}	
	
		para SWC solo reemplace la ultima linea por Default() para el caso es lo mismo.
	*/


	LRESULT Default()
	{
		return DefWindowProc(hWndt,uIDt,wParamt,lParamt);
	}
	//combobox Messages
	virtual void OnCbnEditChange(){}
	virtual void OnCbnKillFocus(){}
	virtual void OnCbnEditUpdate(){}
	virtual void OnCbnCloseUp(){}
	virtual void OnCbnSelendOk(){}
	virtual void OnCbnSelendCandel(){}
	virtual void OnCbnSelChange(){}
	virtual void OnCbnSetFocus(){}
	virtual void OnCbnDropDown(){}


	void SaveMsg(HWND hWnd,UINT uID, WPARAM wParam,LPARAM lParam)
	{
		hWndt=hWnd;
		uIDt=uID;
		wParamt=wParam;
		lParamt=lParam;
	}

	
	virtual BOOL OnClose()
	{
		return TRUE;
	}

	
	
BEGIN_MSG_MAP()
	ON_WM_CLOSE(OnClose)
	ON_WM_DESTROY(OnDestroy)
	ON_WM_NCDESTROY(OnNcDestroy)
END_MSG_MAP_DEFAULT()	
};

