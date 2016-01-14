#pragma once 

#include "stdafx.h"
#include "ComControlEX.h"
#include "CImageCtrl.h"

class CHeaderCtrl : public ComControlEX
{
public:

	CHeaderCtrl(HWND hWnd=NULL){m_hWnd=hWnd;}

	BOOL Create(HWND hWndParent,DWORD dwStyle=0,
			UINT uID=0)
	{		
		BOOL bRes = CreateEx(0L, WC_HEADER, NULL,
						dwStyle,CRect(0L, 0L, 0L, 0),hWndParent, uID, NULL);
		SubclassWnd(GetSafeHwnd());
		return bRes;
	}
	
public:
	
	int GetItemCount() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)Header_GetItemCount(m_hWnd);
		
	}
	BOOL GetItem(int nIndex, LPHDITEMA phdi) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)Header_GetItem(m_hWnd, nIndex, phdi) ;
	}
	BOOL SetItem(int nIndex, LPHDITEMA phdi)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)Header_SetItem(m_hWnd,nIndex, phdi);
	}

	void GetItemText(int nIndex,LPSTR lpBuffer,int nSize)
	{
		HDITEM hdi;
		hdi.mask = HDI_TEXT;
		hdi.pszText = lpBuffer;
		hdi.cchTextMax = nSize;

		GetItem(nIndex, &hdi);
	   		
	}

	void GetItemFull(int nIndex,HDITEM* hdi,LPSTR lpBuffer,int nSize)
	{
		hdi->mask = HDI_TEXT|HDI_WIDTH|HDI_HEIGHT|HDI_FORMAT|HDI_LPARAM|HDI_BITMAP|HDI_IMAGE|HDI_ORDER;
		hdi->pszText = lpBuffer;
		hdi->cchTextMax = nSize;

		GetItem(nIndex, hdi);
		
	   		
	}

	CImageCtrl GetImageList() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return CImageCtrl((HIMAGELIST)Header_GetImageList(m_hWnd));
	}
	CImageCtrl SetImageList(HIMAGELIST himl)
	{
		ASSERT(::IsWindow(m_hWnd));
		return CImageCtrl((HIMAGELIST)Header_SetImageList(m_hWnd, himl));
		
	}
	BOOL GetOrderArray(int iCount, int*  lpi) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)Header_GetOrderArray(m_hWnd, iCount, lpi) ;
	}
	BOOL SetOrderArray(int iCount, int* lpi)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)Header_SetOrderArray(m_hWnd, iCount, lpi);
	}
	BOOL GetItemRect(int iItem, LPRECT lprc) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)Header_GetItemRect(m_hWnd, iItem, lprc) ;
	}
	int SetHotDivider(BOOL fPos, DWORD dwInputVal)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)Header_SetHotDivider(m_hWnd, fPos, dwInputVal);
	}
	

#if (_WIN32_IE >= 0x0400)
	BOOL GetUnicodeFormat() 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)Header_GetUnicodeFormat(m_hWnd) ;
	
	}
	BOOL SetUnicodeFormat(BOOL fUnicode )
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)Header_SetUnicodeFormat(m_hWnd, fUnicode);
	}
#endif //(_WIN32_IE >= 0x0400)

	int InsertItem(int nItem, LPHDITEMA phdi)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)Header_InsertItem(m_hWnd,nItem, phdi) ;
	}
	BOOL DeleteItem(int nIndex)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)Header_DeleteItem(m_hWnd,nIndex);
	}
	BOOL Layout(HD_LAYOUT* playout)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (BOOL)Header_Layout(m_hWnd, playout) ;
	}
	int HitTest(LPHDHITTESTINFO lpHitTest) 
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, HDM_HITTEST, 0, (LPARAM)lpHitTest);
	}
	int OrderToIndex(int nOrder)
	{
		ASSERT(::IsWindow(m_hWnd));
		return (int)Header_OrderToIndex(m_hWnd, nOrder);
	}
	CImageCtrl CreateDragImage(int nIndex)
	{
		ASSERT(::IsWindow(m_hWnd));
		return CImageCtrl((HIMAGELIST)Header_CreateDragImage(m_hWnd, nIndex) );
	}

};
