#pragma once

#include "stdafx.h"
#include "CWin.h"

class CEdit : public CWin
{
public:

	CEdit(HWND hWnd = NULL) : CWin(hWnd) { }
	virtual ~CEdit(){};

public:
	
	BOOL Create( HWND hwndParent,UINT nID=0L,LPCTSTR lpWindowName=NULL,
	   DWORD dwStyle=WS_VISIBLE,CRect rc=CRect(0L,0L,0L,0),LPVOID lpParam=NULL)
	{
		BOOL rs= CWin::Create(_T("edit"),lpWindowName,
		   dwStyle,rc,hwndParent,nID,lpParam);
		SubclassWnd(GetSafeHwnd());
		return rs;
	}
	
	
	void Paste()
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage(WM_PASTE, 0L, 0L);
	}
	
	void Copy()
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage(WM_COPY, 0L, 0L);
	}

	BOOL Undo()
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)SendMessage(EM_UNDO, 0L, 0L);
	}
	void Clear()
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage(WM_CLEAR, 0L, 0L);
	}
	
	void Cut()
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage(WM_CUT, 0L, 0L);
	}
	
	int CanUndo()
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int) SendMessage(EM_CANUNDO, 0L, 0L);
	}
	
	int GetLineCount() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage(EM_GETLINECOUNT, 0L, 0L);
	}
	
	int GetModify()
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage(EM_GETMODIFY, 0L, 0L);
	}
	
	void SetModify(BOOL bModified = TRUE)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage(EM_SETMODIFY, bModified, 0L);
	}
	
	void GetRect(LPRECT lpRect) 
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_GETRECT, 0L, (LPARAM)lpRect);
	}
	
	DWORD GetSel() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (DWORD)SendMessage( EM_GETSEL, 0L, 0L);
	}
	void GetSel(DWORD& dwStart, DWORD& dwEnd) 
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_GETSEL, (WPARAM)&dwStart, (LPARAM)&dwEnd);
	}
	HLOCAL GetHandle() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HLOCAL)SendMessage( EM_GETHANDLE, 0L, 0L);
	}
	void SetHandle(HLOCAL hBuffer)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_SETHANDLE, (WPARAM)hBuffer, 0L);
	}
	DWORD GetMargins() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (DWORD)SendMessage( EM_GETMARGINS, 0L, 0L);
	}
	void SetMargins(UINT nLeft, UINT nRight,UINT nFlag=EC_LEFTMARGIN|EC_RIGHTMARGIN)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_SETMARGINS, nFlag, MAKELONG(nLeft, nRight));
	}
	UINT GetLimitText() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)SendMessage( EM_GETLIMITTEXT, 0L, 0L);
	}
	void SetLimitText(UINT nLimit)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_SETLIMITTEXT, nLimit, 0L);
	}
	
	
	int GetLine(int nIndex, LPTSTR lpszBuffer) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( EM_GETLINE, nIndex, (LPARAM)lpszBuffer);
	}
	int GetLine(int nIndex, LPTSTR lpszBuffer, int nMaxLength) 
	{
		ASSERT(::IsWindow(m_hWnd));
		*(LPWORD)lpszBuffer = (WORD)nMaxLength;
		return (int)SendMessage( EM_GETLINE, nIndex, (LPARAM)lpszBuffer);
	}

	TCHAR GetPasswordChar() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (TCHAR)SendMessage( EM_GETPASSWORDCHAR, 0L, 0L);
	}
	void SetPasswordChar(TCHAR ch)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_SETPASSWORDCHAR, ch, 0L);
	}
	
	int GetFirstVisibleLine() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( EM_GETFIRSTVISIBLELINE, 0L, 0L);
	}
	int GetThumb() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( EM_GETTHUMB, 0L, 0L);
	}

	BOOL SetReadOnly(BOOL bReadOnly = TRUE)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)SendMessage( EM_SETREADONLY, bReadOnly, 0L);
	}


	void EmptyUndoBuffer()
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_EMPTYUNDOBUFFER, 0L, 0L);
	}
	BOOL FmtLines(BOOL bAddEOL=TRUE)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)SendMessage( EM_FMTLINES, bAddEOL, 0L);
	}
	void GetLimitText(int nChars = 0)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_LIMITTEXT, nChars, 0L);
	}
	int LineFromChar(int nIndex = -1) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( EM_LINEFROMCHAR, nIndex, 0L);
	}
	int LineIndex(int nLine = -1) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( EM_LINEINDEX, nLine, 0L);
	}
	int LineLength(int nLength) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)SendMessage( EM_LINELENGTH, nLength, 0L);
	}
	void LineScroll(int ncxLines, int ncyScroll)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_LINESCROLL, ncxLines, ncyScroll);
	}
	void ReplaceSel(LPCTSTR pszNewText, BOOL bCanUndo = FALSE)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_REPLACESEL, (WPARAM) bCanUndo, (LPARAM)pszNewText);
	}
	void SetRect(LPCRECT lpRect)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_SETRECT, 0L, (LPARAM)lpRect);
	}
	void SetRectNP(LPCRECT lpRect)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_SETRECTNP, 0L, (LPARAM)lpRect);
	}
	void SetSel(DWORD dwSelection, BOOL bNoScroll = FALSE)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_SETSEL, LOWORD(dwSelection), HIWORD(dwSelection));
		if(!bNoScroll)
			SendMessage( EM_SCROLLCARET, 0L, 0L);
	}
	void SetSel(DWORD dwStartChar, DWORD dwEndChar)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_SETSEL, dwStartChar, dwEndChar);
		
	}
	
	BOOL SetTabStops(int nTabStops, LPINT rgTabStops)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)SendMessage( EM_SETTABSTOPS, nTabStops, (LPARAM)rgTabStops);
	}
	BOOL SetTabStops()
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)SendMessage( EM_SETTABSTOPS, 0L, 0L);
	}

	BOOL SetTabStops( int cTab, LPDWORD lpTabs)    
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)SendMessage( EM_SETTABSTOPS, cTab, (LPARAM)lpTabs);
	}
	void ScrollCaret()
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_SCROLLCARET, 0L, 0L);
	}
	int Scroll(int nScroll)
	{
		ASSERT(::IsWindow(m_hWnd));
		return SendMessage( EM_SCROLL, nScroll, 0L);
		
		
	}

	EDITWORDBREAKPROC GetWordBreakProc() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (EDITWORDBREAKPROC)SendMessage( EM_GETWORDBREAKPROC, 0L, 0L);
	}

	void SetWordBreakProc(EDITWORDBREAKPROC edtWProc)
	{
		ASSERT(::IsWindow(m_hWnd));
		SendMessage( EM_SETWORDBREAKPROC, 0L, (LPARAM)edtWProc);
	}
		
};
