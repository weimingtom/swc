#pragma once

#include "stdafx.h"
#include "CWin.h"

class CComboBox : public CWin
{
public:

	CComboBox(HWND hWnd = NULL) : CWin(hWnd) { }
	virtual ~CComboBox(){};

	BOOL Create( HWND hwndParent,UINT nID=0L,LPCTSTR lpWindowName=NULL,
	   DWORD dwStyle=WS_VISIBLE,CRect rc=CRect(0L,0L,0L,0),LPVOID lpParam=NULL)
	{
		BOOL rs= CWin::Create(_T("combobox"),lpWindowName,
		   dwStyle,rc,hwndParent,nID,lpParam);
		SubclassWnd(GetSafeHwnd());
		return rs;
	}


	void GetDroppedControlRect(LPRECT lprect) 
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( CB_GETDROPPEDCONTROLRECT, 0L, (LPARAM)lprect);
	}
	
	BOOL GetDroppedState() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)SendMessage( CB_GETDROPPEDSTATE, 0L, 0L);
	}
	
	int GetCount() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_GETCOUNT, 0L, 0L);
	}
	int GetCurSel() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_GETCURSEL, 0L, 0L);
	}
	
	WORD GetLocale() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (WORD)SendMessage( CB_GETLOCALE, 0L, 0L);
	}
	
	int GetLBText(int nIndex, LPTSTR lpszText) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_GETLBTEXT, nIndex, (LPARAM)lpszText);
	}

	int GetLBTextLen(int nIndex) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_GETLBTEXTLEN, nIndex, 0L);
	}

	int GetItemHeight(int nIndex) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_GETITEMHEIGHT, nIndex, 0L);
	}
	
	int GetTopIndex() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_GETTOPINDEX, 0L, 0L);
	}
	int SetTopIndex(int nIndex)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_SETTOPINDEX, nIndex, 0L);
	}
	BOOL GetExtendedUI() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)SendMessage( CB_GETEXTENDEDUI, 0L, 0L);
	}
	int  GetHorizontalExtent() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)SendMessage( CB_GETHORIZONTALEXTENT, 0L, 0L);
	}
	DWORD GetItemData(int nIndex) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (DWORD)SendMessage( CB_GETITEMDATA, nIndex, 0L);
	}
	DWORD GetEditSel() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (DWORD)SendMessage( CB_GETEDITSEL, 0L, 0L);
	}
	void SetHorizontalExtent(UINT nExtent)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( CB_SETHORIZONTALEXTENT, nExtent, 0L);
	}
	int GetDroppedWidth() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_GETDROPPEDWIDTH, 0L, 0L);
	}
	int SetDroppedWidth(int nWidth)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_SETDROPPEDWIDTH, nWidth, 0L);
	}


	
	BOOL SetEditSel(int nStart,  int nEnd)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)SendMessage( CB_SETEDITSEL, 0L, MAKELONG(nStart, nEnd));
	}

	int SetCurSel(int nSelect)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_SETCURSEL, nSelect, 0L);
	}
	
	int SetItemData(int nIndex, DWORD dwIdata)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_SETITEMDATA, nIndex, (LPARAM)dwIdata);
	}
	
	WORD SetLocale(WORD wLocale)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (WORD)SendMessage( CB_SETLOCALE, (WPARAM)wLocale, 0L);
	}
	
	int SetItemHeight(int nIndex, UINT cyIheight)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_SETITEMHEIGHT, nIndex, MAKELONG(cyIheight, 0));
	}
	
	int SetExtendedUI(BOOL bExtended = TRUE)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_SETEXTENDEDUI, bExtended, 0L);
	}
	


	int InitStorage(int nItems, UINT nBytes)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_INITSTORAGE, (WPARAM)nItems, nBytes);
	}
	void ResetContent()
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( CB_RESETCONTENT, 0L, 0L);
	}

	BOOL LimitText(int nChars)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)SendMessage( CB_LIMITTEXT, nChars, 0L);
	}

	void ShowDropDown(BOOL bShow = TRUE)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( CB_SHOWDROPDOWN, bShow, 0L);
	}

	int AddString(LPCTSTR lpszString)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_ADDSTRING, 0L, (LPARAM)lpszString);
	}
	int DeleteString(int nIndex)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_DELETESTRING, nIndex, 0L);
	}
	int InsertString(int nIndex, LPCTSTR lpszString)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_INSERTSTRING, nIndex, (LPARAM)lpszString);
	}
	int Dir(int attr, LPCTSTR lpszWildCard)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_DIR, attr, (LPARAM)lpszWildCard);
	}

	int FindString(int nStartAfter, LPCTSTR lpszString) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_FINDSTRING, nStartAfter, (LPARAM)lpszString);
	}
	int FindStringExact(int nIndexStart, LPCTSTR lpszFind) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_FINDSTRINGEXACT, nIndexStart, (LPARAM)lpszFind);
	}
	int SelectString(int nStartAfter, LPCTSTR lpszString)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( CB_SELECTSTRING, nStartAfter, (LPARAM)lpszString);
	}

	void Clear()
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( WM_CLEAR, 0L, 0L);
	}
	void Copy()
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( WM_COPY, 0L, 0L);
	}
	void Cut()
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( WM_CUT, 0L, 0L);
	}
	void Paste()
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( WM_PASTE, 0L, 0L);
	}
};
