#pragma once 

#include "stdafx.h"
#include "ComControlEX.h"
#include "CImageCtrl.h"
#include "CEdit.h"
#include "CHeaderCtrl.h"

class CListView: public ComControlEX
{
public:
	CListView(HWND hWnd=NULL){m_hWnd=hWnd;}


	BOOL Create(HWND hWndParent,DWORD dwStyle=0,
			UINT uID=0,LPCTSTR lpWindowName=NULL)
	{		
		BOOL bRes = CreateEx(0L, WC_LISTVIEW, lpWindowName,
						dwStyle,CRect(0L, 0L, 0L, 0),hWndParent, uID, NULL);
		SubclassWnd(GetSafeHwnd());
		return bRes;
	}

public:

	COLORREF GetBkColor() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)ListView_GetBkColor(m_hWnd);
	}

	BOOL SetBkColor(COLORREF clrBk)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_SetBkColor(m_hWnd, clrBk);
	}
	CImageCtrl GetImageList(int nImageListType) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return CImageCtrl((HIMAGELIST)ListView_GetImageList(m_hWnd,nImageListType));
	}
	CImageCtrl SetImageList(HIMAGELIST hImageList, int nImageList)
	{
		ASSERT(::IsWindow(m_hWnd)); 
		return CImageCtrl((HIMAGELIST)ListView_SetImageList(m_hWnd, hImageList, (WPARAM)hImageList));
	}
	int GetItemCount() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)ListView_GetItemCount(m_hWnd);
	}
	BOOL SetItemCount(int nItems)
	{
		ASSERT(::IsWindow(m_hWnd));
		//return (BOOL)ListView_SetItemCount(m_hWnd, nItems);
		ListView_SetItemCount(m_hWnd, nItems); //FIXME:
		return TRUE;
	}
	BOOL GetItem(LPLVITEMA pItem) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_GetItem(m_hWnd, pItem);
	}
	BOOL SetItem( LVITEMA* pItem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_SetItem(m_hWnd, pItem); 
	}
	
	UINT GetItemState(int nItem, UINT mask) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)ListView_GetItemState(m_hWnd, nItem, mask);
	}

	void SetItemState(int nIndex, UINT nState, UINT nMask)
	{
		ASSERT(::IsWindow(m_hWnd));
		ListView_SetItemState(m_hWnd, nIndex, nState, nMask);
	}
	

	void GetItemText(int nItem, int nSubItem, LPTSTR lpszText, int nLen)
	{
		ASSERT(::IsWindow(m_hWnd));
		ListView_GetItemText(m_hWnd, nItem, nSubItem, lpszText, nLen);
	}
	void SetItemText(int nItem, int nSubItem, LPSTR lpszText)
	{
		ASSERT(::IsWindow(m_hWnd));
		ListView_SetItemText(m_hWnd, nItem, nSubItem, lpszText);
	}
	
	BOOL GetItemData(int nItem) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_GetItem(m_hWnd, nItem);
	}
	
	UINT GetCallbackMask() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)ListView_GetCallbackMask(m_hWnd);
	}
	BOOL SetCallbackMask(UINT nMask)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_SetCallbackMask(m_hWnd, nMask);
	}
	BOOL GetItemPosition(int nItem, LPPOINT ppt) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_GetItemPosition(m_hWnd, nItem, ppt);
	}
	
	void SetItemPosition(int nItem, POINT pt)
	{
		ASSERT(::IsWindow(m_hWnd));
		ListView_SetItemPosition32(m_hWnd, nItem, pt.x, pt.y);
	}
	
	void SetItemPosition(int nItem, int x, int y)
	{
		POINT pt;
		pt.x=x; pt.y=y;
		ASSERT(::IsWindow(m_hWnd));
		SetItemPosition(nItem, pt);

	}
	int GetStringWidth(LPCTSTR psz) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)ListView_GetStringWidth(m_hWnd, psz);
	}
	CEdit GetEditControl() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return CEdit((HWND)ListView_GetEditControl(m_hWnd));
	}
	BOOL GetColumn(int nCol, LV_COLUMN* pCol) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_GetColumn(m_hWnd, nCol, pCol);
	}
	BOOL SetColumn(int nCol,  LV_COLUMN* pCol)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_SetColumn(m_hWnd, nCol, pCol);
	}
	
	int GetColumnWidth(int iCol) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)ListView_GetColumnWidth(m_hWnd, iCol);
	}
	
	BOOL SetColumnWidth(int nCol, int nCx)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_SetColumnWidth(m_hWnd, nCol, nCx);
	}
	
	BOOL GetViewRect(LPRECT lpRc) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_GetViewRect(m_hWnd, lpRc);
	}
	
	COLORREF GetTextColor() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)ListView_GetTextColor(m_hWnd); 
	}
	
	BOOL SetTextColor(COLORREF clrText)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_SetTextColor(m_hWnd, clrText);
	}
	
	COLORREF GetTextBkColor() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)ListView_GetTextBkColor(m_hWnd);
	}

	BOOL SetTextBkColor(COLORREF clrTextBk)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_SetTextBkColor(m_hWnd, clrTextBk);
	}

	int GetTopIndex() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)ListView_GetTopIndex(m_hWnd);
	}
	
	int GetCountPerPage() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)ListView_GetCountPerPage(m_hWnd);
	}
	
	BOOL GetOrigin(LPPOINT ppt) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_GetOrigin(m_hWnd, ppt);
	}
	
	UINT GetSelectedCount() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)ListView_GetSelectedCount(m_hWnd);
	}

	BOOL GetItemRect(int nIndex, LPRECT lpRect, UINT nCode) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_GetItemRect(m_hWnd, nIndex, lpRect, nCode);
	}

	HCURSOR GetHotCursor() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HCURSOR)ListView_GetHotCursor(m_hWnd);
	}

	HCURSOR SetHotCursor(HCURSOR hcur)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HCURSOR) ListView_SetHotCursor(m_hWnd, hcur);
	}
	int GetHotItem() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int) ListView_GetHotItem(m_hWnd);
	}
	
	int SetHotItem(int nIndex)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int) ListView_SetHotItem(m_hWnd, nIndex);
	}
	
	BOOL GetColumnOrderArray(int nCount, int* pi) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL) ListView_GetColumnOrderArray(m_hWnd, nCount, pi);
	}
	
	BOOL SetColumnOrderArray(int nCount, int* pi)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL) ListView_SetColumnOrderArray(m_hWnd, nCount, pi);
	}
	
	CHeaderCtrl GetHeader() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return CHeaderCtrl((HWND)::SendMessage(m_hWnd, LVM_GETHEADER, 0, 0L));
	}

	BOOL GetSubItemRect(int nItem, int nSubItem, int code, LPRECT prc) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL) ListView_GetSubItemRect(m_hWnd, nItem, nSubItem, code, prc);
	}
	
	DWORD SetIconSpacing(int cx, int cy)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (DWORD) ListView_SetIconSpacing(m_hWnd, cx, cy);
	}
	
	int GetISearchString(LPTSTR lpsz) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int) ListView_GetISearchString(m_hWnd, lpsz);
	}
	
	void GetItemSpacing(SIZE& pSize, BOOL fSmallIcon) 
	{
		ASSERT(::IsWindow(m_hWnd));
		DWORD dwRt=ListView_GetItemSpacing(m_hWnd, fSmallIcon);
		pSize.cx = HIWORD(dwRt);
		pSize.cy = LOWORD(dwRt);
	}

	
	int GetNextItem() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int) ListView_GetNextItem(m_hWnd, -1, MAKELPARAM(LVNI_ALL | LVNI_SELECTED, 0));
	}

	DWORD GetExtendedListViewStyle() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (DWORD)ListView_GetExtendedListViewStyle(m_hWnd);
	}
	DWORD SetExtendedListViewStyle(DWORD dwExStyle)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (DWORD) ListView_SetExtendedListViewStyle(m_hWnd, dwExStyle);
	}

	
	BOOL GetCheckState(int nItem) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return ListView_GetCheckState( m_hWnd, nItem );
		
	}

	
	BOOL GetBkImage(LPLVBKIMAGE plvbki) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_GetBkImage(m_hWnd, plvbki);
	}
	
	BOOL SetBkImage(LPLVBKIMAGE plvbki)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_SetBkImage(m_hWnd, plvbki);
			
	}
	int GetSelectionMark() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int) ListView_GetSelectionMark(m_hWnd);
	}

	int SetSelectionMark(int nIndex)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)ListView_SetSelectionMark(m_hWnd, nIndex);
	}
	
	BOOL GetWorkAreas(int nWrka, LPRECT lpRect) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_GetWorkAreas(m_hWnd, nWrka, lpRect);
	}

	BOOL SetWorkAreas(int nWrka, LPRECT lpRect)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL) ListView_SetWorkAreas(m_hWnd, nWrka, lpRect);
	}

	DWORD GetHoverTime() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (DWORD)(DWORD)SendMessage(LVM_GETHOVERTIME, 0, 0);
	}
	DWORD SetHoverTime(DWORD dwHoverTime)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (DWORD) SendMessage(LVM_SETHOVERTIME, 0, dwHoverTime);

	}

	BOOL GetNumberOfWorkAreas(int* pnWrka) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_GetNumberOfWorkAreas(m_hWnd, pnWrka);
		
	}

	BOOL SetItemCountEx(int cItems, DWORD dwFlags)
	{
		ASSERT(::IsWindow(m_hWnd));
		//FIXME:
		//return (BOOL)ListView_SetItemCountEx(m_hWnd, cItems, dwFlags);
		ListView_SetItemCountEx(m_hWnd, cItems, dwFlags);
		return TRUE;
	}

	CToolTipCtrl GetToolTips() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return CToolTipCtrl((HWND) SendMessage(LVM_GETTOOLTIPS, 0, 0) );
	}

	CToolTipCtrl SetToolTips(HWND hWnd)
	{
		ASSERT(::IsWindow(hWnd));
		return CToolTipCtrl((HWND)SendMessage(LVM_SETTOOLTIPS, (int)hWnd, 0));

	}
	BOOL GetUnicodeFormat() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_GetUnicodeFormat(m_hWnd);
	}
	BOOL SetUnicodeFormat(BOOL fUnicode = TRUE)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_SetUnicodeFormat(m_hWnd, fUnicode);
	}


	int InsertColumn(int nCol,  LV_COLUMN* pCol)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)ListView_InsertColumn(m_hWnd, nCol, pCol);
		
	}
	
	int InsertColumn(int nCol, LPCTSTR lpszText, int Flag, int nWidth, int nSubItem)
	{
		LV_COLUMN lvNewColumn;
		lvNewColumn.mask = LVCF_TEXT|LVCF_FMT;
		lvNewColumn.pszText = (LPTSTR)lpszText;
		lvNewColumn.fmt = Flag;
		lvNewColumn.cx = nWidth;
		lvNewColumn.iSubItem = nSubItem;
		if (nWidth != -1) lvNewColumn.mask |= LVCF_WIDTH;
		if (nSubItem != -1) lvNewColumn.mask |= LVCF_SUBITEM;
		return InsertColumn(nCol, &lvNewColumn);
	}

	BOOL DeleteColumn(int nCol)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL) ListView_DeleteColumn(m_hWnd, nCol);

	}
	
	int InsertItem( LVITEM* pitem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)ListView_InsertItem(m_hWnd, pitem);
	}
	
	int InsertItem(int nMask=LVIF_TEXT, int nItem=LVM_INSERTITEM, LPCTSTR lpszText=0, int nSubItem=0,
				   int nState=0, UINT nStateMask=0, int nImage=0, LPARAM lParam=0)
	{
		ASSERT(::IsWindow(m_hWnd));
		LVITEM stitem;
		stitem.mask = nMask;
		stitem.iItem = nItem;
		stitem.iSubItem = nSubItem;
		stitem.pszText = (LPTSTR)lpszText;
		stitem.state = nState;
		stitem.stateMask = nStateMask;
		stitem.iImage = nImage;
		stitem.lParam = lParam;
		return InsertItem(&stitem);
	}

	int InsertItemText(int nItem, LPCTSTR lpszText)
	{
		ASSERT(::IsWindow(m_hWnd));
		return InsertItem(LVIF_TEXT, nItem,lpszText);
	}
	
	int InsertItemText(int nItem, int nSubItem, LPCTSTR lpszText)
	{
		ASSERT(::IsWindow(m_hWnd));
		LVITEM stitem;
		stitem.iSubItem = nSubItem;
		stitem.pszText = (LPTSTR) lpszText;
		return ::SendMessage(m_hWnd, LVM_SETITEMTEXT, nItem, (LPARAM)&stitem);
	}

	int InsertItemTextImage(int nItem, LPCTSTR lpszText, int nImage)
	{
		ASSERT(::IsWindow(m_hWnd));
		return InsertItem(LVIF_TEXT|LVIF_IMAGE, nItem,lpszText, 0, 0, nImage, 0);
	}
	int GetNextItem(int nItem, int nFlags) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int) ListView_GetNextItem(m_hWnd, nItem, nFlags);
	}
	
	BOOL DeleteItem(int nItem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_DeleteItem(m_hWnd, nItem); 
	}
	BOOL DeleteAllItems()
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_DeleteAllItems(m_hWnd);
		
	}
	int FindItem(LV_FINDINFO* plvfi, int nStart) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int) ListView_FindItem(m_hWnd, nStart, plvfi);
	}
	int HitTest(LV_HITTESTINFO* pInfo) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int) ListView_HitTest(m_hWnd, pInfo);
		
	}
	
	BOOL EnsureVisible(int nItem, BOOL bPartialOK)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL) ListView_EnsureVisible(m_hWnd, nItem, bPartialOK);
		
	}
	BOOL Scroll(SIZE size)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_Scroll(m_hWnd, size.cx, size.cy);
	}
	
	BOOL RedrawItems(int nFirst, int nLast)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)ListView_RedrawItems(m_hWnd, nFirst, nLast);

	}
	BOOL Arrange(UINT nCode)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL) ListView_Arrange(m_hWnd, nCode);
	}
	
	CEdit EditLabel(int nItem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return CEdit((HWND)ListView_EditLabel(m_hWnd, nItem));
	}

	BOOL Update(int nItem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL) ListView_Update(m_hWnd, nItem);

	}
	BOOL SortItems(PFNLVCOMPARE pCompare, LPARAM lpSort)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL) ListView_SortItems(m_hWnd, pCompare, lpSort);
	}

	CImageCtrl RemoveImageList(int nImgList)
	{
		ASSERT(::IsWindow(m_hWnd));
		return CImageCtrl((HIMAGELIST)ListView_SetImageList(m_hWnd, nImgList, 0/*NULL*/));
	}

	CImageCtrl CreateDragImage(int nItem, LPPOINT lpptUpLeft)
	{
		ASSERT(::IsWindow(m_hWnd));
		return CImageCtrl((HIMAGELIST)ListView_CreateDragImage(m_hWnd, nItem, lpptUpLeft));
	}
	DWORD ApproximateViewRect(int nCx ,int nCy,  int nCount )
	{
		ASSERT(::IsWindow(m_hWnd));
		return (DWORD)ListView_ApproximateViewRect(m_hWnd, nCx, nCy, nCount);
	}
	int SubItemHitTest(LPLVHITTESTINFO plvhti)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)ListView_SubItemHitTest(m_hWnd, plvhti);
	}

	
	
};
