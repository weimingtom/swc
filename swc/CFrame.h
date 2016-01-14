#pragma once

#include "stdafx.h"
#include "CWin.h"
#include "CReBarCtrlEx.h"
#include "CStatusCtrlEx.h"
#include "DockManager.h"
#include "CMenuSpawn.h"
#include "CWindowDC.h"

class CMiniDock;
class CFrame : public CWin
{
public:
	CWin*			m_ClientView;
	CReBarCtrlEx*	m_ReBar;
//	CArray			m_dockBars;
	CFont			m_fontMenu;	
	CStatusCtrlEx	m_statusCtrl;
	HWND			m_SubMenuActual;
	CMiniDock*		m_MiniFrame;
	HWND hMDIClient;
	DockManager*	m_DockLeft;
	DockManager*	m_DockBottom;
	DockManager*	m_DockRight;
	CImageCtrl		m_imgCtrl;
	CSize			m_sizeImagDocks;

public:
	
	// COOLMENU SUPPORT
		CMenuSpawn	cSpawn;
		CRect oldMenuBarRc;
		bool bMenuLooping;
		UINT uiTimerId;
	// END COOLMENU SUPPORT


public:
	
	CFrame(HWND hWnd=NULL) : CWin(hWnd)
	{
		m_ClientView=NULL;
		hMDIClient=NULL;
		oldMenuBarRc.SetRect(0,0,0,0);
		bMenuLooping = false;
		uiTimerId = 0;
		m_ReBar=NULL;
		m_ClientView=NULL;
		m_DockLeft=NULL;
		m_DockBottom=NULL;
		m_DockRight=NULL;
		m_sizeImagDocks=CSize(0,0);
	}
	
	virtual ~CFrame()
	{
		if (m_ReBar != NULL) delete m_ReBar;
		if (m_ClientView== NULL) return;
		if (::IsWindow(m_ClientView->GetSafeHwnd()))
			delete m_ClientView; 
		if (m_imgCtrl.GetImageHandle())
			m_imgCtrl.Destroy();
	};

	virtual BOOL LoadFrame(UINT uID,DWORD dwStyle=WS_OVERLAPPEDWINDOW,HWND hParentWnd=NULL);
	void LoadPositionBar();
	void ShowFloatWindow(HWND hWnd);
	UINT GfxSetSafeTimer(CWin * pWnd, const UINT uiElapse)
	{
		ASSERT(pWnd && pWnd->GetSafeHwnd());
		UINT iTimer = 1;
		while (iTimer < 10000)
		{
			UINT res = pWnd->SetTimer(1, uiElapse, NULL);
			if (res) return res;
			iTimer ++;
		}
		return 0;
	}

	void FloatWindow(CWin* pParent, CPoint point,CRect rc );
	void CreateDock();
	LRESULT OnReBarAutoSize(int idCtrl, LPNMHDR pnmh)
	{
		UpdateFrame(FALSE);	
		return 0;
	}

	
	int CreateExBars(int Panels[],int nIDCount)
	{
		m_ReBar=new CReBarCtrlEx();		
		if (!m_ReBar->Create(GetSafeHwnd()))
			return FALSE;
		if ( !m_statusCtrl.Create(GetSafeHwnd()))
			return FALSE;
		m_statusCtrl.SetIndicators(Panels,nIDCount);
		CreateDock();
		return TRUE;
	}

	int CreateBars(int Panels[],int nIDCount)
	{
		m_ReBar = new CReBarCtrlEx();
		if (!m_ReBar->Create(GetSafeHwnd()))
			return FALSE;

		if ( !m_statusCtrl.Create(GetSafeHwnd()))
			return FALSE;
		m_statusCtrl.SetIndicators(Panels,nIDCount);
		
		return TRUE;
	}

	BOOL SetPanelText(int iPanel,LPCTSTR lpText)
	{
		ASSERT(m_statusCtrl.GetSafeHwnd())
		return m_statusCtrl.SetPaneText(iPanel,lpText);
	}

	void SetImageDockWindows(UINT nBitmapID, int cx, int nGrow, COLORREF crMask)
	{
		
		if (nBitmapID != (UINT)(-1))
		{
			if(!m_imgCtrl.CreateColor(nBitmapID)) 
				return ;
			int x,y;
			x=y=0;
			m_imgCtrl.GetIconSize(&x,&y);
			m_sizeImagDocks=CSize(x,y);	
		}
		else
		{
			CBitmap cbmp;
			BITMAP bmp;
			m_imgCtrl.Create(nBitmapID,cx,nGrow,crMask);
			cbmp.LoadBitmap(theApp->GetInstance(),(LPCTSTR)nBitmapID);
			cbmp.GetBitmap(&bmp);
			m_imgCtrl.Add(&cbmp,crMask);
			m_sizeImagDocks=CSize(cx,bmp.bmHeight);	
			cbmp.DeleteObject();
			

		}		
	}

	void DrawIconDocks(int numIcon,CPoint cp, CGDI* dc)
	{
		if (m_imgCtrl.GetImageHandle())
			m_imgCtrl.Draw(numIcon,dc->m_hDC,cp,ILD_TRANSPARENT);

	}

	BOOL AddBar(CToolBarCtrl* pToolBar, int nID, LPTSTR lpstrTitle = NULL)
	{
		if(m_ReBar->GetSafeHwnd() != NULL )
		{
			m_ReBar->AddBar(pToolBar, nID,lpstrTitle);
			return TRUE;
		}
		
		return FALSE;
		
	}
	void UpdateFrame(BOOL bResizeBars=TRUE);

	

	HWND GetSafeClientHwnd()
	{
		return hMDIClient;
	}

	//--------------------------------------------
	// Messages map
	//--------------------------------------------
	int  OnPaint(HDC hDC);

   	LRESULT OnToolTipText(int idButton, LPNMHDR pnmh)
	{
		LPNMTTDISPINFOA lpNmDisPinfo = (LPNMTTDISPINFOA)pnmh;
		char Buffer[256];
		lpNmDisPinfo->szText[0] = 0;
		memset(Buffer,0x00,256);
		int iPos=0;
		(void)iPos;
		if((idButton != 0) && !(lpNmDisPinfo->uFlags & TTF_IDISHWND))
		{
			::LoadStringA(theApp->GetInstance(),idButton,Buffer,256);
			int i;
			for( i=0; i < lstrlen(Buffer); i++)
			{
				if (Buffer[i] == '\n')
					break;
			}			
			if (i <0) return 0;
			lstrcpynA(lpNmDisPinfo->szText,Buffer+i+1,
					  sizeof(lpNmDisPinfo->szText) / sizeof(lpNmDisPinfo->szText[0]));
			
		#if (_WIN32_IE >= 0x0300)
				lpNmDisPinfo->uFlags |= TTF_DI_SETITEM;
		#endif 
		
		}
	
		return 0;
	}

	LRESULT OnShowBand(HWND hWnd)
	{
		return m_ReBar->OnShowBand(hWnd);
	}

	CFont GetMenuFont()
	{
		if (!(HFONT)m_fontMenu) {
			NONCLIENTMETRICS info;
			info.cbSize = sizeof(info);
			SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(info), &info, 0);
			m_fontMenu.CreateFontIndirect(&info.lfMenuFont);
		}
		return m_fontMenu;
	}


	//--------------------------------------------
	//Menu Functions
	//--------------------------------------------

	
		void OnMenuSelect( UINT nItemID,UINT nFlags,HMENU hSysMenu )
		{
			if (nItemID != 0)
			{
				TCHAR szTemp[256];
				theApp->LoadString(nItemID,szTemp,255);
				for(int i=0; i < lstrlen(szTemp); i++)
				{
					if (szTemp[i] == '\n')
						szTemp[i]='\0';
				}			
				SetPanelText(0,szTemp );
			}

		}

		 virtual BOOL OnDrawItem( LPDRAWITEMSTRUCT lpDrawItemStruct)
		 {
			 if (!cSpawn.DrawItem(lpDrawItemStruct))
				Default();
			 return TRUE;
		 }
		 virtual LRESULT OnMeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
		 {
			 if (!cSpawn.MeasureItem(lpMeasureItemStruct))
				Default();
			 return TRUE;
		 }
		 void OnInitMenuPopup(HMENU hPopupMenu, UINT nIndex, BOOL bSysMenu)
		 {
			 if( !SubMenuSystem(hPopupMenu))
				 cSpawn.RemapMenu(hPopupMenu);
			 else
				Default();
			 
		 }

		 void OnInitMenu(HMENU hMMenu)
		 {
			 if( !SubMenuSystem(hMMenu))
				cSpawn.RemapMenu(hMMenu);
			 else
				Default();
		 }


		 

		 virtual void SaveConfig()
		 {
		    /* CRect rc;
			TCHAR szSection[512];
			wsprintf(szSection, _T("%s-MainWindow"), theApp->m_lpBuffer);
			GetWindowRect(rc);
			WriteInteger(rc.left,szSection, _T("Left"));
			WriteInteger(rc.right,szSection, _T("Right"));
			WriteInteger(rc.top,szSection, _T("Top"));
			WriteInteger(rc.bottom,szSection, _T("Bottom"));
			*/
		 }

		 virtual CRect GetConfig()
		 {
		    TCHAR szSection[512];
			CRect rcPosition;
			wsprintf(szSection, _T("%s-MainWindow"), theApp->m_lpBuffer);
		
			rcPosition.left=ReadInteger(szSection, _T("Left"));
			rcPosition.right=ReadInteger(szSection, _T("Right"));
			rcPosition.top=ReadInteger(szSection, _T("Top"));
			rcPosition.bottom=ReadInteger(szSection, _T("Bottom"));
		
	   		if (rcPosition.left <0 || rcPosition.right < 0 || rcPosition.bottom <= 0 || rcPosition.right <= 0)
				rcPosition=CRect(0,0,240,240);
		
			return rcPosition;
		 }

		 LRESULT OnMenuChar(UINT nChar, UINT nFlags, HMENU hMenu)
		 {
			 LRESULT lRes;
			if (!cSpawn.FindKeyboardShortcut(nChar, nFlags, hMenu, lRes)) 
				lRes = Default();
			return lRes;
		 }
		
		 BOOL SubMenuSystem(HMENU hPopupMenu)
		 {
			 MENUITEMINFO mii;
			 mii.cbSize = sizeof (MENUITEMINFO); // must fill up this field
			 mii.fMask = MIIM_ID;             // get the state of the menu item
			 return (BOOL)GetMenuItemInfo( hPopupMenu, SC_CLOSE, FALSE,&mii);
		 }

		/*void OnNcPaint(HRGN hRgn)
		{
			HDC hdc;
		    hdc = GetDCEx((HRGN)hRgn, DCX_WINDOW|DCX_EXCLUDERGN);
			Default();
			DrawNcMenuBar(hdc);
			ReleaseDC(hdc);

		}
		 void DrawNcMenuBar(HDC hdc)
		 {
			 CRect rc;
			 GetClientRect(rc);
			 rc.top+=GetSystemCaption()+GetSystemBorderX()*2+1;
			 rc.left+=GetSystemBorderY()*2;
			 rc.bottom=rc.top+GetSystemMenuHeight()+GetSystemBorderX()+1;
			 rc.top=rc.bottom-2;
			 CWindowDC wdc(GetSafeHwnd());
			 CBrush cb;
			 cb.CreateSysColorBrush(COLOR_BTNFACE);
			 wdc.FillRect(rc,&cb);
		 }*/

		
		 void OnTimer(UINT nIDEvent)
		 {
			 	if (uiTimerId == nIDEvent && !bMenuLooping)
				{
					CPoint pt;
					GetCursorPos(&pt);
					LRESULT res = SendMessage(WM_NCHITTEST, 0, MAKELONG(pt.x, pt.y));
					(void)res;
				}
				
				Default();
		 }

		 void OnEnterMenuLoop(BOOL bIsTrackPopupMenu)
		 {
			if (!(oldMenuBarRc.IsRectEmpty()))
			{
				CWindowDC dc(this);
				dc.Draw3dRect((LPCRECT)oldMenuBarRc,cSpawn.crMenu, cSpawn.crMenu);
				oldMenuBarRc.SetRect(0,0,0,0);
				dc.DeleteDC();
			}

			bMenuLooping = true;
		 }

		 void OnExitMenuLoop(BOOL bIsTrackPopupMenu)
		 {
			bMenuLooping = false;
		 }

		 BOOL OnNotifyItemChange(int wParam, LPNMHDR lParam)
		 {
			 if ((((LPNMTBHOTITEM)lParam)->dwFlags) & HICF_LEAVING)
				SetPanelText(0,"Ready");
			 else
			 {
				TCHAR szTemp[256];
				theApp->LoadString((((LPNMTBHOTITEM)lParam)->idNew),szTemp,255);
				for(int i=0; i < lstrlen(szTemp); i++)
				{
					if (szTemp[i] == '\n')
						szTemp[i]='\0';
				}			
				SetPanelText(0,szTemp );
			  }
			return TRUE;
		 }

		 BOOL OnSize(UINT nType,long x, long y) 
		 {
		 	UpdateFrame();
			return TRUE;
		 }
	
		 virtual BOOL OnDestroy()
		 {
			 SaveConfig();
			 return TRUE;
		 }
	//--------------------------------------------
	// End messages map
	//--------------------------------------------

BEGIN_MSG_MAP()
	 ON_WM_PAINT(OnPaint)
	 ON_WM_SIZE(OnSize) 
	 ON_NOTIFY_CODE(RBN_AUTOSIZE, OnReBarAutoSize)
	 ON_NOTIFY_CODE(TTN_GETDISPINFOA, OnToolTipText)
	 ON_NOTIFY_CODE(TBN_HOTITEMCHANGE, OnNotifyItemChange)
	 ON_WM_DRAWITEM(OnDrawItem)
	 ON_WM_MEASUREITEM(OnMeasureItem)
	 ON_WM_INITMENUPOPUP(OnInitMenuPopup)
	 ON_WM_MENUCHAR(OnMenuChar)
	 ON_WM_INITMENU(OnInitMenu)
	 ON_WM_TIMER(OnTimer)
	 ON_WM_ENTERMENULOOP(OnEnterMenuLoop)
	 ON_WM_EXITMENULOOP(OnExitMenuLoop)
	 ON_WM_MENUSELECT(OnMenuSelect)
	 //ON_WM_NCPAINT(OnNcPaint)
END_MSG_MAP(CWin)

};
