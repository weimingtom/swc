#pragma once

#include "debug.h"

class CMenu
{
	HMENU m_hMenu;
public:
	CMenu(HMENU hMenu=NULL)
	{
		m_hMenu=hMenu; 
	};
	~CMenu()
	{
		DestroyMenu(); 
	};

public:
	BOOL DestroyMenu()
	{
		if (m_hMenu == NULL)
			return FALSE;
		return ::DestroyMenu(m_hMenu);
	}

	HMENU	GetHandleMenu()
	{
		return m_hMenu;
	}

	BOOL LoadMenu(LPCTSTR lpszMenuName)
	{
		if (lpszMenuName != NULL)
		{
			
			if ((m_hMenu = ::LoadMenu(GetModuleHandle(NULL), lpszMenuName)) == NULL)
			{
				return FALSE;
			}
			
			return TRUE;
		}
		return FALSE;
	}

	BOOL LoadMenuIndirect( void* lpMenuTemplate)
	{
		ASSERT(m_hMenu == NULL);
		if(!(m_hMenu = ::LoadMenuIndirect(lpMenuTemplate)))
			return FALSE;
		return TRUE;
	}

	BOOL CreateMenu()
	{
		ASSERT(m_hMenu == NULL);
		if (!(m_hMenu = ::CreateMenu()))
			return FALSE;
		return TRUE;
	}

	BOOL CreatePopupMenu()
	{
		ASSERT(m_hMenu == NULL);
		if (!(m_hMenu = ::CreatePopupMenu()))
			 return FALSE;
		return TRUE;
	}

	BOOL DeleteMenu(UINT uPosition, UINT uFlags=MF_BYCOMMAND)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::DeleteMenu(m_hMenu, uPosition, uFlags);
	}

	BOOL TrackPopupMenu(UINT uFlags, int x, int y, HWND hWndParent,LPCRECT lpRect = NULL,int nReserve=0)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::TrackPopupMenu(m_hMenu, uFlags, x, y, nReserve, hWndParent, lpRect);
	}

	BOOL TrackPopupMenuEx(UINT fuFlags, int x, int y, HWND hWnd, LPTPMPARAMS lptpm = NULL)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::TrackPopupMenuEx(m_hMenu, fuFlags, x, y, hWnd, lptpm);
	}


	BOOL AppendMenu(UINT uFlags=MF_STRING, UINT uIDNewItem = 0, LPCTSTR lpszNewItem = NULL)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::AppendMenu(m_hMenu, uFlags, uIDNewItem, lpszNewItem);
	}

	UINT CheckMenuItem(UINT uIDCheckItem, UINT uCheck=MF_BYCOMMAND)
	{
		ASSERT(::IsMenu(m_hMenu));
		return (UINT)::CheckMenuItem(m_hMenu, uIDCheckItem, uCheck);
	}

	UINT EnableMenuItem(UINT uIDEnableItem, UINT uEnable)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::EnableMenuItem(m_hMenu, uIDEnableItem, uEnable);
	}
	BOOL HiliteMenuItem(HWND hWnd, UINT uIDHiliteItem, UINT uHilite)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::HiliteMenuItem(hWnd, m_hMenu, uIDHiliteItem, uHilite);
	}
	int GetMenuItemCount() 
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::GetMenuItemCount(m_hMenu);
	}
	UINT GetMenuItemID(int nPos) 
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::GetMenuItemID(m_hMenu, nPos);
	}
	UINT GetMenuState(UINT uID, UINT uFlags) 
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::GetMenuState(m_hMenu, uID, uFlags);
	}
	int GetMenuString(UINT uIDItem, LPTSTR lpString, int nMaxCount, UINT uFlags=MF_BYCOMMAND) 
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::GetMenuString(m_hMenu, uIDItem, lpString, nMaxCount, uFlags);
	}
	int GetMenuStringLen(UINT uIDItem, UINT uFlags=MF_BYCOMMAND) 
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::GetMenuString(m_hMenu, uIDItem, NULL, 0, uFlags);
	}


	HMENU GetSubMenu(int nPos) 
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::GetSubMenu(m_hMenu, nPos);
	}
	BOOL InsertMenu(UINT uPosition, UINT uFlags, UINT uIDNewItem = 0, LPCTSTR lpszNewItem = NULL)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::InsertMenu(m_hMenu, uPosition, uFlags, uIDNewItem, lpszNewItem);
	}
	

	BOOL ModifyMenu(UINT uPosition, UINT uFlags, UINT uIDNewItem = 0, LPCTSTR lpszNewItem = NULL)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::ModifyMenu(m_hMenu, uPosition, uFlags, uIDNewItem, lpszNewItem);
	}
	
	BOOL RemoveMenu(UINT uPosition, UINT uFlags)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::RemoveMenu(m_hMenu, uPosition, uFlags);
	}
	BOOL SetMenuItemBitmaps(UINT uPosition, UINT uFlags, HBITMAP hBmpUnchecked, HBITMAP hBmpChecked)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::SetMenuItemBitmaps(m_hMenu, uPosition, uFlags, hBmpUnchecked, hBmpChecked);
	}
	BOOL CheckMenuRadioItem(UINT uIDFirst, UINT uIDLast, UINT uIDItem, UINT uFlags)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::CheckMenuRadioItem(m_hMenu, uIDFirst, uIDLast, uIDItem, uFlags);
	}

	BOOL GetMenuItemInfo(UINT uItem, BOOL bByPosition, LPMENUITEMINFO lpmii) 
	{
		ASSERT(::IsMenu(m_hMenu));
		return (BOOL)::GetMenuItemInfo(m_hMenu, uItem, bByPosition, lpmii);
	}
	BOOL SetMenuItemInfo(UINT uItem, BOOL bByPosition, LPMENUITEMINFO lpmii)
	{
		ASSERT(::IsMenu(m_hMenu));
		return (BOOL)::SetMenuItemInfo(m_hMenu, uItem, bByPosition, lpmii);
	}
	BOOL InsertMenuItem(UINT uItem, BOOL bByPosition, LPMENUITEMINFO lpmii)
	{
		ASSERT(::IsMenu(m_hMenu));
		return (BOOL)::InsertMenuItem(m_hMenu, uItem, bByPosition, lpmii);
	}

	UINT GetMenuDefaultItem(BOOL bByPosition = FALSE, UINT uFlags = 0U) 
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::GetMenuDefaultItem(m_hMenu, (UINT)bByPosition, uFlags);
	}
	BOOL SetMenuDefaultItem(UINT uItem = (UINT)-1,  BOOL bByPosition = FALSE)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::SetMenuDefaultItem(m_hMenu, uItem, (UINT)bByPosition);
	}
	BOOL GetMenuItemRect(HWND hWnd, UINT uItem, LPRECT lprcItem) 
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::GetMenuItemRect(hWnd, m_hMenu, uItem, lprcItem);
	}
	int MenuItemFromPoint(HWND hWnd, POINT point) 
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::MenuItemFromPoint(hWnd, m_hMenu, point);
	}


	BOOL SetMenuContextHelpId(DWORD dwContextHelpId)
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::SetMenuContextHelpId(m_hMenu, dwContextHelpId);
	}
	DWORD GetMenuContextHelpId() 
	{
		ASSERT(::IsMenu(m_hMenu));
		return ::GetMenuContextHelpId(m_hMenu);
	}

	

	void Attach(HMENU hMenu)
	{
		ASSERT(::IsMenu(hMenu));
		DestroyMenu();
		m_hMenu = hMenu;
	}

	HMENU Detach()
	{
		HMENU hMenu = m_hMenu;
		m_hMenu = NULL;
		return hMenu;
	}
};
