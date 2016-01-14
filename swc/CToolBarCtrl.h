#pragma once

#include "stdafx.h"
#include "ComControlEX.h"
#include "CImageCtrl.h"
#include "CToolTipCtrl.h"
#include "CComboBoxExt.h"

class CToolBarCtrl : public ComControlEX
{
	
	struct TBData
	{
		WORD wVersion;
		WORD wWidth;
		WORD wHeight;
		WORD wItemCount;
		WORD* items()
			{ return (WORD*)(this+1); }
	};
		
public:
	CImageCtrl	cImgCtrl;
	CToolBarCtrl(HWND hWnd=NULL){m_hWnd=hWnd;}
	~CToolBarCtrl(){cImgCtrl.Destroy();};
	COLORREF cl;
public:

	BOOL Create(HWND hWndParent,UINT uID=BASE_TOOLBAR_CLASS, 
			DWORD dwStyle=WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | CCS_NODIVIDER | CCS_NORESIZE | CCS_NOPARENTALIGN | TBSTYLE_TOOLTIPS | TBSTYLE_FLAT|TBSTYLE_LIST)
	{		
		BOOL bRes = CreateEx(0L, TOOLBARCLASSNAME, NULL,
						dwStyle,CRect(0L, 0L, 0L, 0),hWndParent, uID, NULL);
		cl=CDrawLayer::GetRGBColorXP();
		SubclassWnd(GetSafeHwnd());
		return bRes;
	}


	BOOL AddTrueColor(UINT uTb, UINT uTbType) 
	{
		
		if (!cImgCtrl.CreateColor(uTb))
			return FALSE;
		
		//SetImageList(cImgCtrl.GetImageHandle());
		//SendMessage(uTbType, 0, (LPARAM)cImgCtrl.GetImageHandle());
	
		return TRUE;
	}

	
	BOOL IsButtonEnabled(int nID) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_ISBUTTONENABLED, nID, 0L);
	}
	BOOL IsButtonChecked(int nID) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_ISBUTTONCHECKED, nID, 0L);
	}
	BOOL IsButtonPressed(int nID) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_ISBUTTONPRESSED, nID, 0L);
	}
	BOOL IsButtonHidden(int nID) 
	{
		ASSERT(m_hWnd);
		return(BOOL) SendMessage( TB_ISBUTTONHIDDEN, nID, 0L);
	}
	BOOL IsButtonIndeterminate(int nID) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_ISBUTTONINDETERMINATE, nID, 0L);
	}
	int GetState(int nID) 
	{
		ASSERT(m_hWnd);
		return (int)SendMessage( TB_GETSTATE, nID, 0L);
	}
	BOOL SetState(int nID, UINT nState)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETSTATE, nID, MAKELPARAM(nState, 0));
	}
	BOOL GetButton(int nIndex, LPTBBUTTON lpButton) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_GETBUTTON, nIndex, (LPARAM)lpButton);
	}
	int GetButtonCount() 
	{
		ASSERT(m_hWnd);
		return (int)SendMessage( TB_BUTTONCOUNT, 0L, 0L);
	}
	BOOL GetItemRect(int nIndex, LPRECT lpRect) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_GETITEMRECT, nIndex, (LPARAM)lpRect);
	}
	void SetButtonStructSize(int nSize = sizeof(TBBUTTON))
	{
		ASSERT(m_hWnd);
		SendMessage( TB_BUTTONSTRUCTSIZE, nSize, 0L);
	}
	BOOL SetButtonSize(SIZE size)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETBUTTONSIZE, 0L, MAKELPARAM(size.cx, size.cy));
	}
	BOOL SetButtonSize(int cx, int cy)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETBUTTONSIZE, 0L, MAKELPARAM(cx, cy));
	}
	BOOL SetBitmapSize(SIZE size)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETBITMAPSIZE, 0L, MAKELPARAM(size.cx, size.cy));
	}
	BOOL SetBitmapSize(int cx, int cy)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETBITMAPSIZE, 0L, MAKELPARAM(cx, cy));
	}
	CToolTipCtrl GetToolTips() 
	{
		return CToolTipCtrl((HWND)SendMessage( TB_GETTOOLTIPS, 0L, 0L));
	}
	void SetToolTips(HWND hWndToolTip)
	{
		ASSERT(m_hWnd);
		SendMessage( TB_SETTOOLTIPS, (WPARAM)hWndToolTip, 0L);
	}
	void SetNotifyWnd(HWND hWnd)
	{
		ASSERT(m_hWnd);
		SendMessage( TB_SETPARENT, (WPARAM)hWnd, 0L);
	}
	int GetRows() 
	{
		if (!::IsWindow(m_hWnd)) return -1;
		return (int)SendMessage( TB_GETROWS, 0L, 0L);
	}
	void SetRows(int nRows, BOOL bLarger, LPRECT lpRect)
	{
		ASSERT(m_hWnd);
		SendMessage( TB_SETROWS, MAKELPARAM(nRows, bLarger), (LPARAM)lpRect);
	}
	BOOL SetCmdID(int nIndex, UINT nID)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETCMDID, nIndex, nID);
	}
	DWORD GetBitmapFlags() 
	{
		ASSERT(m_hWnd);
		return (DWORD)SendMessage( TB_GETBITMAPFLAGS, 0L, 0L);
	}
	int GetBitmap(int nID) 
	{
		ASSERT(m_hWnd);
		return (int)SendMessage( TB_GETBITMAP, nID, 0L);
	}
	int GetButtonText(int nID, LPTSTR lpstrText) 
	{
		ASSERT(m_hWnd);
		return (int)SendMessage( TB_GETBUTTONTEXT, nID, (LPARAM)lpstrText);
	}

	CImageCtrl GetImageList() 
	{
		if (!::IsWindow(m_hWnd)) return NULL;
		return CImageCtrl((HIMAGELIST)SendMessage( TB_GETIMAGELIST, 0L, 0L));
	}
	CImageCtrl SetImageList(HIMAGELIST hImageList)
	{
		if (!::IsWindow(m_hWnd)) return NULL;
		return CImageCtrl((HIMAGELIST)SendMessage( TB_SETIMAGELIST, 0L, (LPARAM)hImageList));
	}
	CImageCtrl GetDisabledImageList() 
	{
		if (!::IsWindow(m_hWnd)) return NULL;
		return CImageCtrl((HIMAGELIST)SendMessage( TB_GETDISABLEDIMAGELIST, 0L, 0L));
	}
	CImageCtrl SetDisabledImageList(HIMAGELIST hImageList)
	{
		if (!::IsWindow(m_hWnd)) return NULL;
		return CImageCtrl((HIMAGELIST)SendMessage( TB_SETDISABLEDIMAGELIST, 0L, (LPARAM)hImageList));
	}
	CImageCtrl GetHotImageList() 
	{
		if (!::IsWindow(m_hWnd)) return NULL;
		return CImageCtrl((HIMAGELIST)SendMessage( TB_GETHOTIMAGELIST, 0L, 0L));
	}
	CImageCtrl SetHotImageList(HIMAGELIST hImageList)
	{
		if (!::IsWindow(m_hWnd)) return NULL;
		return CImageCtrl((HIMAGELIST)SendMessage( TB_SETHOTIMAGELIST, 0L, (LPARAM)hImageList));
	}
	DWORD GetStyle() 
	{
		ASSERT(m_hWnd);
		return (DWORD)SendMessage( TB_GETSTYLE, 0L, 0L);
	}
	void SetStyle(DWORD dwStyle)
	{
		ASSERT(m_hWnd);
		SendMessage( TB_SETSTYLE, 0L, dwStyle);
	}
	DWORD GetButtonSize() 
	{
		ASSERT(m_hWnd);
		return (DWORD)SendMessage( TB_GETBUTTONSIZE, 0L, 0L);
	}
	void GetButtonSize(SIZE& size) 
	{
		ASSERT(m_hWnd);
		DWORD dwRet = (DWORD)SendMessage( TB_GETBUTTONSIZE, 0L, 0L);
		size.cx = LOWORD(dwRet);
		size.cy = HIWORD(dwRet);
	}
	BOOL GetRect(int nID, LPRECT lpRect) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_GETRECT, nID, (LPARAM)lpRect);
	}
	int GetTextRows() 
	{
		ASSERT(m_hWnd);
		return (int)SendMessage( TB_GETTEXTROWS, 0L, 0L);
	}
	BOOL SetButtonWidth(int cxMin, int cxMax)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETBUTTONWIDTH, 0L, MAKELPARAM(cxMin, cxMax));
	}
	BOOL SetIndent(int nIndent)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETINDENT, nIndent, 0L);
	}
	BOOL SetMaxTextRows(int nMaxTextRows)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETMAXTEXTROWS, nMaxTextRows, 0L);
	}

#if (_WIN32_IE >= 0x0400)
	BOOL GetAnchorHighlight() 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_GETANCHORHIGHLIGHT, 0L, 0L);
	}
	BOOL SetAnchorHighlight(BOOL bEnable = TRUE)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETANCHORHIGHLIGHT, bEnable, 0L);
	}

	void GetButtonInfo(int nIndex, UINT& nID, UINT& nStyle, int& iImage) 
	{
		
		ASSERT(::IsWindow(m_hWnd));

		TBBUTTON button;
		GetButton(nIndex, &button);
		nID = button.idCommand;
		nStyle = MAKELONG(button.fsStyle, button.fsState);
		iImage = button.iBitmap;
	}

	
	int GetButtonInfo(int nID, LPTBBUTTONINFO lptbbi) 
	{
		if (!::IsWindow(m_hWnd)) return -1;
		return (int)SendMessage( TB_GETBUTTONINFO, nID, (LPARAM)lptbbi);
	}
	BOOL SetButtonInfo(int nID, LPTBBUTTONINFO lptbbi)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETBUTTONINFO, nID, (LPARAM)lptbbi);
	}
	int GetHotItem() 
	{
		if (!::IsWindow(m_hWnd)) return -1;
		return (int)SendMessage( TB_GETHOTITEM, 0L, 0L);
	}
	int SetHotItem(int nItem)
	{
		if (!::IsWindow(m_hWnd)) return -1;
		return (int)SendMessage( TB_SETHOTITEM, nItem, 0L);
	}
	BOOL IsButtonHighlighted(int nButtonID) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_ISBUTTONHIGHLIGHTED, nButtonID, 0L);
	}
	DWORD SetDrawTextFlags(DWORD dwMask, DWORD dwFlags)
	{
		if (!::IsWindow(m_hWnd)) return -1;
		return (DWORD)SendMessage( TB_SETDRAWTEXTFLAGS, dwMask, dwFlags);
	}
	BOOL GetColorScheme(LPCOLORSCHEME lpcs) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_GETCOLORSCHEME, 0L, (LPARAM)lpcs);
	}
	void SetColorScheme(LPCOLORSCHEME lpcs)
	{
		ASSERT(m_hWnd);
		SendMessage( TB_SETCOLORSCHEME, 0L, (LPARAM)lpcs);
	}
	DWORD GetExtendedStyle() 
	{
		if (!::IsWindow(m_hWnd)) return -1;
		return (DWORD)SendMessage( TB_GETEXTENDEDSTYLE, 0L, 0L);
	}
	DWORD SetExtendedStyle(DWORD dwStyle)
	{
		if (!::IsWindow(m_hWnd)) return -1;
		return (DWORD)SendMessage( TB_SETEXTENDEDSTYLE, 0L, dwStyle);
	}
	void GetInsertMark(LPTBINSERTMARK lptbim) 
	{
		ASSERT(m_hWnd);
		SendMessage( TB_GETINSERTMARK, 0L, (LPARAM)lptbim);
	}
	void SetInsertMark(LPTBINSERTMARK lptbim)
	{
		ASSERT(m_hWnd);
		SendMessage( TB_SETINSERTMARK, 0L, (LPARAM)lptbim);
	}
	COLORREF GetInsertMarkColor() 
	{
		if (!::IsWindow(m_hWnd)) return RGB(0L,0L,0);
		return (COLORREF)SendMessage( TB_GETINSERTMARKCOLOR, 0L, 0L);
	}
	COLORREF SetInsertMarkColor(COLORREF clr)
	{
		if (!::IsWindow(m_hWnd)) return RGB(0L,0L,0);
		return (COLORREF)SendMessage( TB_SETINSERTMARKCOLOR, 0L, (LPARAM)clr);
	}
	BOOL GetMaxSize(LPSIZE lpSize) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_GETMAXSIZE, 0L, (LPARAM)lpSize);
	}
	void GetPadding(LPSIZE lpSizePadding) 
	{
		ASSERT(m_hWnd);
		DWORD dwRet = (DWORD)SendMessage( TB_GETPADDING, 0L, 0L);
		lpSizePadding->cx = LOWORD(dwRet);
		lpSizePadding->cy = HIWORD(dwRet);
	}
	void SetPadding(int cx, int cy, LPSIZE lpSizePadding = NULL)
	{
		ASSERT(m_hWnd);
		DWORD dwRet = (DWORD)SendMessage( TB_SETPADDING, 0L, MAKELPARAM(cx, cy));
		if(lpSizePadding != NULL)
		{
			lpSizePadding->cx = LOWORD(dwRet);
			lpSizePadding->cy = HIWORD(dwRet);
		}
	}
	BOOL GetUnicodeFormat() 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_GETUNICODEFORMAT, 0L, 0L);
	}
	BOOL SetUnicodeFormat(BOOL bUnicode = TRUE)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_SETUNICODEFORMAT, bUnicode, 0L);
	}
#endif 

#if (_WIN32_IE >= 0x0500)
	int GetString(int nString, LPTSTR lpstrString, int cchMaxLen) 
	{
		ASSERT(m_hWnd);
		return (int)SendMessage( TB_GETSTRING, MAKEWPARAM(cchMaxLen, nString), (LPARAM)lpstrString);
	}
	
#endif 

#if (_WIN32_WINNT >= 0x0501)
	void GetMetrics(LPTBMETRICS lptbm) 
	{
		ASSERT(m_hWnd);
		SendMessage( TB_GETMETRICS, 0L, (LPARAM)lptbm);
	}
	void SetMetrics(LPTBMETRICS lptbm)
	{
		ASSERT(m_hWnd);
		SendMessage( TB_SETMETRICS, 0L, (LPARAM)lptbm);
	}
	void SetWindowTheme(LPCWSTR lpstrTheme)
	{
		ASSERT(m_hWnd);
		SendMessage( TB_SETWINDOWTHEME, 0L, (LPARAM)lpstrTheme);
	}
#endif 


	BOOL EnableButton(int nID, BOOL bEnable = TRUE)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_ENABLEBUTTON, nID, MAKELPARAM(bEnable, 0));
	}
	BOOL CheckButton(int nID, BOOL bCheck = TRUE)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_CHECKBUTTON, nID, MAKELPARAM(bCheck, 0));
	}
	BOOL PressButton(int nID, BOOL bPress = TRUE)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_PRESSBUTTON, nID, MAKELPARAM(bPress, 0));
	}
	BOOL HideButton(int nID, BOOL bHide = TRUE)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_HIDEBUTTON, nID, MAKELPARAM(bHide, 0));
	}
	BOOL Indeterminate(int nID, BOOL bIndeterminate = TRUE)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_INDETERMINATE, nID, MAKELPARAM(bIndeterminate, 0));
	}
	
	int AddBitmap(int nNumButtons, HBITMAP hBitmap)
	{
		ASSERT(m_hWnd);
		TBADDBITMAP tbab;
		tbab.hInst = theApp->GetInstance();
		tbab.nID = (UINT_PTR)hBitmap;
		return (int)SendMessage( TB_ADDBITMAP, (WPARAM)nNumButtons, (LPARAM)&tbab);
	}
	BOOL AddButtons(int nNumButtons, LPTBBUTTON lpButtons)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_ADDBUTTONS, nNumButtons, (LPARAM)lpButtons);
	}
	BOOL InsertButton(int nIndex, LPTBBUTTON lpButton)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_INSERTBUTTON, nIndex, (LPARAM)lpButton);
	}
	BOOL DeleteButton(int nIndex)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_DELETEBUTTON, nIndex, 0L);
	}
	UINT CommandToIndex(UINT nID) 
	{
		ASSERT(m_hWnd);
		return (UINT)SendMessage( TB_COMMANDTOINDEX, nID, 0L);
	}
	void SaveState(HKEY hKeyRoot, LPCTSTR lpszSubKey, LPCTSTR lpszValueName)
	{
		ASSERT(m_hWnd);
		TBSAVEPARAMS tbs;
		tbs.hkr = hKeyRoot;
		tbs.pszSubKey = lpszSubKey;
		tbs.pszValueName = lpszValueName;
		SendMessage( TB_SAVERESTORE, (WPARAM)TRUE, (LPARAM)&tbs);
	}
	void RestoreState(HKEY hKeyRoot, LPCTSTR lpszSubKey, LPCTSTR lpszValueName)
	{
		ASSERT(m_hWnd);
		TBSAVEPARAMS tbs;
		tbs.hkr = hKeyRoot;
		tbs.pszSubKey = lpszSubKey;
		tbs.pszValueName = lpszValueName;
		SendMessage( TB_SAVERESTORE, (WPARAM)FALSE, (LPARAM)&tbs);
	}
	void Customize()
	{
		ASSERT(m_hWnd);
		SendMessage( TB_CUSTOMIZE, 0L, 0L);
	}
	int AddString(UINT nStringID)
	{
		ASSERT(m_hWnd);
		return (int)SendMessage( TB_ADDSTRING, (WPARAM)theApp->GetInstance(), (LPARAM)nStringID);
	}
	int AddStrings(LPCTSTR lpszStrings)
	{
		ASSERT(m_hWnd);
		return (int)SendMessage( TB_ADDSTRING, 0L, (LPARAM)lpszStrings);
	}
	void AutoSize()
	{
		ASSERT(m_hWnd);
		SendMessage( TB_AUTOSIZE, 0L, 0L);
	}

	BOOL ChangeBitmap(int nID, int nBitmap)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_CHANGEBITMAP, nID, MAKELPARAM(nBitmap, 0));
	}
	int LoadImages(int nBitmapID)
	{
		ASSERT(m_hWnd);
		return (int)SendMessage( TB_LOADIMAGES, nBitmapID, (LPARAM)theApp->GetInstance());
	}
	int LoadStdImages(int nBitmapID)
	{
		ASSERT(m_hWnd);
		return (int)SendMessage( TB_LOADIMAGES, nBitmapID, (LPARAM)HINST_COMMCTRL);
	}
	BOOL ReplaceBitmap(LPTBREPLACEBITMAP ptbrb)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_REPLACEBITMAP, 0L, (LPARAM)ptbrb);
	}

#if (_WIN32_IE >= 0x0400)
	int HitTest(LPPOINT lpPoint)
	{
		ASSERT(m_hWnd);
		return (int)SendMessage( TB_HITTEST, 0L, (LPARAM)lpPoint);
	}
	BOOL InsertMarkHitTest(LPPOINT lpPoint, LPTBINSERTMARK lptbim)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_INSERTMARKHITTEST, (WPARAM)lpPoint, (LPARAM)lptbim);
	}
	BOOL InsertMarkHitTest(int x, int y, LPTBINSERTMARK lptbim)
	{
		ASSERT(m_hWnd);
		POINT pt = { x, y };
		return (BOOL)SendMessage( TB_INSERTMARKHITTEST, (WPARAM)&pt, (LPARAM)lptbim);
	}
	BOOL MapAccelerator(TCHAR chAccel, int& nID) 
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_MAPACCELERATOR, (WPARAM)chAccel, (LPARAM)&nID);
	}
	BOOL MarkButton(int nID, BOOL bHighlight = TRUE)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_MARKBUTTON, nID, MAKELPARAM(bHighlight, 0));
	}
	BOOL MoveButton(int nOldPos, int nNewPos)
	{
		ASSERT(m_hWnd);
		return (BOOL)SendMessage( TB_MOVEBUTTON, nOldPos, nNewPos);
	}


	
	BOOL CreateCombo(CComboBoxExt* pControl,UINT nID,int iSize,DWORD dwStyle);
	
	
#endif 
	void OnSize()
	{
		AutoSize();
	}

	//----------------------------------------
	//This funcion load the toolbar resource
	//----------------------------------------
	BOOL  LoadToolBar(UINT nIDResource)
	{
		
		BOOL bInitialSeparator=FALSE;
		HRSRC hRsrc = theApp->FindResourceToolBar(nIDResource);
		if (hRsrc == NULL)
			return FALSE;
	
		HGLOBAL hGlobal = theApp->LoadResource(hRsrc);
		if (hGlobal == NULL)
			return FALSE;
	
		TBData* pData = (TBData*)::LockResource(hGlobal);
		if (pData == NULL)
			return FALSE;
	
		if (pData->wVersion != 1)  
			return FALSE; 
	
		WORD* pItems = pData->items();
		int nItems = pData->wItemCount + (bInitialSeparator ? 1 : 0);
		TBBUTTON *pTBBtn = (TBBUTTON*)_alloca(nItems * sizeof(TBBUTTON));
	
		
		if(bInitialSeparator)
		{
			pTBBtn[0].iBitmap = 4;
			pTBBtn[0].idCommand = 0;
			pTBBtn[0].fsState = 0;
			pTBBtn[0].fsStyle = TBSTYLE_SEP;
			pTBBtn[0].dwData = 0;
			pTBBtn[0].iString = 0;
		}
	
		int nBmp = 0;
		for(int i = 0L, j = bInitialSeparator ? 1 : 0; i < pData->wItemCount; i++, j++)
		{
			if(pItems[i] != 0)
			{
				pTBBtn[j].iBitmap = nBmp++;
				pTBBtn[j].idCommand = pItems[i];
				pTBBtn[j].fsState = TBSTATE_ENABLED;
				pTBBtn[j].fsStyle = TBSTYLE_BUTTON;
				pTBBtn[j].dwData = 0;
				pTBBtn[j].iString = 0;
			}
			else
			{
				pTBBtn[j].iBitmap = 8;
				pTBBtn[j].idCommand = 0;
				pTBBtn[j].fsState = 0;
				pTBBtn[j].fsStyle = TBSTYLE_SEP;
				pTBBtn[j].dwData = 0;
				pTBBtn[j].iString = 0;
			}
		}
		
		SetButtonStructSize(sizeof(TBBUTTON));
		AddBitmap(nItems, (HBITMAP)nIDResource);
		AddButtons(nItems, pTBBtn);
		SetBitmapSize(pData->wWidth,pData->wHeight);
		SetButtonSize(pData->wWidth + 7,pData->wHeight);
		AutoSize();
	
		return TRUE;
	}

/*	void AddButtonText(UINT nID, CString szText)
	 {
	  TBBUTTONINFO tbi = { 0 };
	  tbi.cbSize = sizeof(TBBUTTONINFO),
	  tbi.dwMask  = TBIF_STYLE;
	  GetButtonInfo(nID, &tbi);
	  tbi.dwMask = TBIF_STYLE | TBIF_TEXT;
	  tbi.fsStyle |= TBSTYLE_AUTOSIZE;
	  tbi.pszText = (LPTSTR) (LPCTSTR) szText;
	  SetButtonInfo(nID, &tbi);
	 }
*/	
	 void AddDropDownButton(UINT nID)
	 {
	   SetExtendedStyle(TBSTYLE_EX_DRAWDDARROWS); 
	   TBBUTTONINFO tbi = { 0 };
	   tbi.cbSize  = sizeof(TBBUTTONINFO);
	   tbi.dwMask  = TBIF_STYLE;
	   GetButtonInfo(nID, &tbi);
	   tbi.fsStyle |= TBSTYLE_DROPDOWN;
	   SetButtonInfo(nID, &tbi);
   }
};
