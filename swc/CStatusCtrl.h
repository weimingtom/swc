#pragma once

#include "stdafx.h"
#include "ComControl.h"

class CStatusCtrl: public ComControl
{

public:
	CStatusCtrl(){}; 
	~CStatusCtrl(){};
public:
	
	
	BOOL Create(HWND hWndParent,DWORD dwStyle=WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | SBARS_SIZEGRIP,
			UINT uID=BASE_STATUS_BAR)
	{		
		BOOL bRes = CreateEx(0L, STATUSCLASSNAME, NULL,
						dwStyle,CRect(0L, 0L, 0L, 0),hWndParent, uID, NULL);
		SubclassWnd(GetSafeHwnd());
		return bRes;
	}
	

#if (_WIN32_IE >= 0x0400)
	
	HICON GetIcon(int nIndex) 
	{
		if (nIndex < 256)
			return (HICON)SendMessage(SB_GETICON, nIndex, 0L);
	}

	BOOL SetIcon(int nIndex, HICON hIcon)
	{
		if(nIndex < 256)
			return (BOOL)SendMessage(SB_SETICON, nIndex, (LPARAM)hIcon);
	}


	COLORREF SetBkColor(COLORREF clrBk=CDrawLayer::GetRGBColorFace())
	{
		return (COLORREF)SendMessage(SB_SETBKCOLOR, 0L, (LPARAM)clrBk);
	}
	
	BOOL GetUnicodeFormat() 
	{
		return (BOOL)SendMessage(SB_GETUNICODEFORMAT, 0L, 0L);
	}
	
	BOOL SetUnicodeFormat(BOOL bUnicode = TRUE)
	{
		return (BOOL)SendMessage(SB_SETUNICODEFORMAT, bUnicode, 0L);
	}

	void GetTipText(int nPane, LPTSTR lpstrText, int nSize) 
	{
		 if(nPane < 256)
			SendMessage(SB_GETTIPTEXT, MAKEWPARAM(nPane, nSize), (LPARAM)lpstrText);
	}
	
	void SetTipText(int nPane, LPCTSTR lpstrText)
	{
		
		if(nPane < 256)
			SendMessage(SB_SETTIPTEXT, nPane, (LPARAM)lpstrText);
	}

#endif 


	

	BOOL GetBorders(int* pBorders) 
	{
		return (BOOL)SendMessage(SB_GETBORDERS, 0L, (LPARAM)pBorders);
	}
	

	void SetIndicators(int nArray[],int nIDCount)
	{
		SendMessage(SB_SETPARTS, nIDCount, (LPARAM)nArray);
	}
	
	
	BOOL GetPaneRect(int nIndex,CRect* rc)
	{
		RECT lpRect;
		if (nIndex < 256)
		{
			SendMessage(SB_GETRECT, nIndex, (LPARAM) &lpRect);
			rc->CopyRect(&lpRect);
			return TRUE;
		}
		return FALSE;
	}

	int GetNumPanels()
	{
		return SendMessage(SB_GETPARTS, 0L, 0);
	}

	int GetParts(int nIndex, int* pParts) 
	{
		return (int)SendMessage(SB_GETPARTS, nIndex, (LPARAM)pParts);
	}
	
	BOOL SetParts(int nIndex, int* pWidths)
	{
		return (BOOL)SendMessage(SB_SETPARTS, nIndex, (LPARAM)pWidths);
	}
	
	//---------------------------------------------------
	int GetTextLength(int nIndex, int* pType = NULL) 
	{
		DWORD dwRet;
		if(nIndex < 256)
			dwRet = (DWORD)SendMessage(SB_GETTEXTLENGTH, (WPARAM)nIndex, 0L);
		if (pType != NULL)
			*pType = (int)(short)HIWORD(dwRet);
		return (int)(short)LOWORD(dwRet);
	}

	int GetText(int nIndex, LPTSTR lpszText, int* pType = NULL) 
	{
		DWORD dwRet;
		if(nIndex < 256)
			dwRet = (DWORD)SendMessage(SB_GETTEXT, (WPARAM)nIndex, (LPARAM)lpszText);
		if(pType != NULL)
			*pType = (int)(short)HIWORD(dwRet);
		return (int)(short)LOWORD(dwRet);
	}

	BOOL SetPaneText(int nIndex,LPCTSTR plszNewText,int nType=0 )
	{
		if (nIndex < 256)
			return (BOOL)SendMessage(SB_SETTEXT, nIndex| nType, (LPARAM)plszNewText);
		return FALSE;
	}

	//---------------------------------------------------
	
	
	void SetMinHeight(int nMin)
	{
		SendMessage(SB_SETMINHEIGHT, nMin, 0L);
	}
	
	BOOL SetSimple(BOOL bSimple = TRUE)
	{
		return (BOOL)SendMessage(SB_SIMPLE, bSimple, 0L);
	}
	
	BOOL IsSimple() 
	{
		return (BOOL)SendMessage( SB_ISSIMPLE, 0L, 0L);
	}

	virtual void Size()
	{
		SendMessage(WM_SIZE,0L,0);
	}


};

