#pragma once

#include "stdafx.h"
#include "ComControlEX.h"
#include "CEdit.h"
#include "CImageCtrl.h"

class CTreeViewCtrl : public ComControlEX
{
public:

	CTreeViewCtrl(HWND hWnd=NULL){m_hWnd=hWnd;}

	BOOL Create(HWND hWndParent,DWORD dwStyle=0,
			UINT uID=0)
	{		
		BOOL bRes = CreateEx(0L, WC_TREEVIEW, NULL,
						dwStyle,CRect(0L, 0L, 0L, 0),hWndParent, uID, NULL);
		SubclassWnd(GetSafeHwnd());
		return bRes;
	}


	UINT GetCount() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)TreeView_GetCount(m_hWnd) ;
	}
	UINT GetIndent() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)TreeView_GetIndent(m_hWnd) ;
	}
	void SetIndent(UINT indent)
	{
		ASSERT(::IsWindow(m_hWnd));
		TreeView_SetIndent(m_hWnd, indent);
	}
	CImageCtrl GetImageList(UINT iImage) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return CImageCtrl((HIMAGELIST)TreeView_GetImageList(m_hWnd, iImage));
	}
	void SetImageList(HIMAGELIST himl, int iImage)
	{
		ASSERT(::IsWindow(m_hWnd));
		TreeView_SetImageList(m_hWnd,  himl,iImage);
	}


	BOOL GetItem(LPTVITEM pitem) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_GetItem(m_hWnd, pitem) ;
	}
	BOOL SetItem(LPTVITEM pitem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_SetItem(m_hWnd, pitem);
	}
	
	BOOL GetItemText(HTREEITEM hItem, LPTSTR lpstrText, int nSize) 
	{
		ASSERT(::IsWindow(m_hWnd));
		ASSERT(lpstrText != NULL);
		TVITEM item;
		item.hItem = hItem;
		item.mask = TVIF_TEXT;
		item.pszText = lpstrText;
		item.cchTextMax = nSize;

		return (BOOL)GetItem(&item);
	}


/*	BOOL SetItemText(HTREEITEM hItem, LPCTSTR lpszItem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return SetItem(hItem, TVIF_TEXT, lpszItem, 0, 0, 0, 0, NULL);
	}
*/	
	CEdit GetEditControl() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return CEdit((HWND)TreeView_GetEditControl(m_hWnd));
	}
	
	UINT GetVisibleCount() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (UINT)TreeView_GetVisibleCount(m_hWnd);
	}
	BOOL GetItemRect(HTREEITEM hitem, LPRECT lpRc, BOOL bCode) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_GetItemRect(m_hWnd, hitem, lpRc, bCode);
	}
	
	BOOL NodeIfChildren(HTREEITEM hItem) 
	{
		ASSERT(::IsWindow(m_hWnd));
		TVITEM Node;
		Node.hItem = hItem;
		Node.mask = TVIF_CHILDREN;
		GetItem(&Node);
		return Node.cChildren;
	}
	
	CToolTipCtrl GetToolTips() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return CToolTipCtrl((HWND)TreeView_GetToolTips(m_hWnd) );
	}
	
	void SetToolTips(HWND hWndTT)
	{
		ASSERT(::IsWindow(m_hWnd));
		TreeView_SetToolTips(m_hWnd,  hWndTT)  ;
	}
	int GetISearchString(LPTSTR  lpsz) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)TreeView_GetISearchString(m_hWnd, lpsz);
	}

	
#if (_WIN32_IE >= 0x0400)
	COLORREF GetBkColor() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)TreeView_GetBkColor(m_hWnd);
	}
	COLORREF SetBkColor(COLORREF clr)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)TreeView_SetBkColor(m_hWnd, clr);
	}
	COLORREF GetInsertMarkColor() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)TreeView_GetInsertMarkColor(m_hWnd);
	}
	COLORREF SetInsertMarkColor(COLORREF clr)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF) TreeView_SetInsertMarkColor(m_hWnd, clr);
	}
	int GetItemHeight() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)TreeView_GetItemHeight(m_hWnd);
	}
	int SetItemHeight(int iHeight)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)TreeView_SetItemHeight(m_hWnd,  iHeight) ;
	}
	int GetScrollTime() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)TreeView_GetScrollTime(m_hWnd) ;
	}
	int SetScrollTime(int uTime)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)TreeView_SetScrollTime(m_hWnd, uTime);
	}
	COLORREF GetTextColor() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)TreeView_GetTextColor(m_hWnd) ;
	}
	COLORREF SetTextColor(COLORREF clr)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (COLORREF)TreeView_SetTextColor(m_hWnd, clr) ;
	}
	BOOL GetUnicodeFormat() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_GetUnicodeFormat(m_hWnd);
	}
	BOOL SetUnicodeFormat(BOOL fUnicode)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_SetUnicodeFormat(m_hWnd, fUnicode);
	
	}
#endif 


	HTREEITEM InsertItem(LPTV_INSERTSTRUCT lpis)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HTREEITEM)TreeView_InsertItem(m_hWnd, lpis);
	}
	


	HTREEITEM InsertItem(LPCTSTR lpszItem, int nImage,int nSelectedImage,
						 HTREEITEM hParent= TVI_ROOT, HTREEITEM hInsertAfter = TVI_LAST)
    { 
		ASSERT(::IsWindow(m_hWnd)); 
		return InsertItem(hParent, hInsertAfter,TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE,
			lpszItem, nImage, nSelectedImage, 0, 0, 0 ); 
	}

    HTREEITEM InsertItem(LPCTSTR lpszItem, HTREEITEM hParent= TVI_ROOT, HTREEITEM hInsertAfter= TVI_LAST)
	{ 
		ASSERT(::IsWindow(m_hWnd)); 
		return InsertItem(hParent, hInsertAfter, TVIF_TEXT, lpszItem, 0, 0, 0, 0, 0 ); 
	}

	
 
	HTREEITEM InsertItem(HTREEITEM hParent, HTREEITEM hInsertAfter, UINT mask, LPCTSTR pszText, int iImage,
					 int iSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam)
	{
		TV_INSERTSTRUCT tv;
		tv.hParent = hParent;
		tv.hInsertAfter = hInsertAfter;
		tv.item.mask = mask;
		tv.item.pszText = (LPTSTR) pszText;
		tv.item.iImage = iImage;
		tv.item.iSelectedImage = iSelectedImage;
		tv.item.state = nState;
		tv.item.stateMask = nStateMask;
		tv.item.lParam = lParam;
		return (HTREEITEM)InsertItem(&tv); 
	}
	
		
	BOOL DeleteItem(HTREEITEM hitem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_DeleteItem(m_hWnd, hitem);
	}
	BOOL DeleteAllItems()
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_DeleteAllItems(m_hWnd) ;
	}
	BOOL Expand(HTREEITEM hItem, UINT code)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_Expand(m_hWnd, hItem, code);
	}
	HTREEITEM GetNextItem(HTREEITEM hitem, UINT code) 
	{ 
		ASSERT(::IsWindow(m_hWnd)); 
		return (HTREEITEM)TreeView_GetNextItem(m_hWnd, hitem, code);
	}
	HTREEITEM GetChild(HTREEITEM hitem) 
	{
		ASSERT(::IsWindow(m_hWnd)); 
		return (HTREEITEM)TreeView_GetChild(m_hWnd, hitem);
	}
	HTREEITEM GetNextSibling(HTREEITEM hitem) 
	{
		ASSERT(::IsWindow(m_hWnd)); 
		return (HTREEITEM)TreeView_GetNextSibling(m_hWnd, hitem);
	}
	HTREEITEM GetPrevSibling(HTREEITEM hitem) 
	{
		ASSERT(::IsWindow(m_hWnd)); 
		return (HTREEITEM)TreeView_GetPrevSibling(m_hWnd, hitem);
	}
	HTREEITEM GetParent(HTREEITEM hitem) 
	{
		ASSERT(::IsWindow(m_hWnd)); 
		return (HTREEITEM)TreeView_GetParent(m_hWnd, hitem);
	}
	HTREEITEM GetFirstVisibleItem() 
	{
		ASSERT(::IsWindow(m_hWnd)); 
		return (HTREEITEM)TreeView_GetFirstVisible(m_hWnd);
	}
	HTREEITEM GetNextVisible(HTREEITEM hitem) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HTREEITEM)TreeView_GetNextVisible(m_hWnd, hitem);
	}
	HTREEITEM GetPrevVisible(HTREEITEM hitem) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HTREEITEM)TreeView_GetPrevVisible(m_hWnd, hitem);
	}
	HTREEITEM GetSelected() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HTREEITEM)TreeView_GetSelection(m_hWnd) ;
	}
	HTREEITEM GetDropHilight() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HTREEITEM)TreeView_GetDropHilight(m_hWnd);
	}
	HTREEITEM GetRoot() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HTREEITEM)TreeView_GetRoot(m_hWnd);
	}
	BOOL Select(HTREEITEM hitem, UINT code)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_Select(m_hWnd, hitem, code) ;
	}
	BOOL SelectItem(HTREEITEM hitem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_SelectItem(m_hWnd, hitem);
	}
	BOOL SelectDropTarget(HTREEITEM hitem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_SelectDropTarget(m_hWnd, hitem);
	}
	BOOL SelectSetFirstVisible(HTREEITEM hitem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_SelectSetFirstVisible(m_hWnd, hitem) ;
	}

	CEdit EditLabel(HTREEITEM hitem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return CEdit((HWND)TreeView_EditLabel(m_hWnd, hitem)) ;
	}
	BOOL EndEditLabelNow(BOOL fCancel)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_EndEditLabelNow(m_hWnd, fCancel);
		
	}
	HTREEITEM HitTest(TV_HITTESTINFO* lpht)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (HTREEITEM)TreeView_HitTest(m_hWnd, lpht);
	}
	HTREEITEM HitTest(POINT pt, UINT* pFlags)
	{
		ASSERT(::IsWindow(m_hWnd));
		TV_HITTESTINFO hti;
		hti.pt = pt;
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_HITTEST, 0, (LPARAM)&hti);
		if (pFlags != NULL)
			*pFlags = hti.flags;
		return hTreeItem;
	}
	BOOL SortChildren(HTREEITEM hitem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_SortChildren(m_hWnd, hitem, TVM_SORTCHILDREN) ;
	}
	BOOL EnsureVisible(HTREEITEM hitem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_EnsureVisible(m_hWnd, hitem);
	}
	BOOL SortChildrenCB(LPTV_SORTCB psort)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_SortChildrenCB(m_hWnd, psort, TVM_SORTCHILDRENCB);
	}
	CImageCtrl RemoveImageList(int nImageList)
	{
		ASSERT(::IsWindow(m_hWnd));
		return CImageCtrl((HIMAGELIST)::SendMessage(m_hWnd, TVM_SETIMAGELIST, (WPARAM)nImageList, NULL));
	}
	CImageCtrl CreateDragImage(HTREEITEM hitem)
	{
		ASSERT(::IsWindow(m_hWnd));
		return CImageCtrl((HIMAGELIST)TreeView_CreateDragImage(m_hWnd, hitem));
	}

#if (_WIN32_IE >= 0x0400)
	BOOL SetInsertMark(HTREEITEM hItem, BOOL fAfter)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_SetInsertMark(m_hWnd, hItem, fAfter) ;
	}
	BOOL RemoveInsertMark()
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)TreeView_SetInsertMark(m_hWnd,0,0);
	}
#endif //(_WIN32_IE >= 0x0400)


};
