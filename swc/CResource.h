#pragma once

#include "stdafx.h"
#include "CDockPanelBase.h"
#include "CTreeViewCtrl.h"
#include "CImageCtrl.h"

class CResource : public CDockPanelBase
{
protected:
	CTreeViewCtrl	  m_TreeResource;
	CImageCtrl	Image;
public:
	CResource()
	{
		
	}

	~CResource()
	{
		
	}
protected:
	virtual BOOL OnCreate(LPCREATESTRUCT lpCreateStruct)
	{

		if (!m_TreeResource.Create(GetSafeHwnd(),WS_CHILD | WS_VISIBLE | TVS_HASLINES | 
								TVS_LINESATROOT | TVS_HASBUTTONS, 0x123456))
		return -1;
	
		
		
		if(!Image.CreateColor(IDB_TREEEXPLORER)) 
			return FALSE;
		m_TreeResource.SetImageList(Image.GetImageHandle(),TVSIL_NORMAL);
		PopulateTree();
		return TRUE;
	}

	void PopulateTree()
	{
		HTREEITEM hRoot = m_TreeResource.InsertItem (_T("My Project"), 1, 1);
		HTREEITEM hAcc = m_TreeResource.InsertItem (_T("Accelerator"), 2, 3, hRoot);
		HTREEITEM hBit = m_TreeResource.InsertItem (_T("Bitmap"), 2, 3, hRoot);
		HTREEITEM hDial = m_TreeResource.InsertItem (_T("Dialog"), 2, 3, hRoot);
		HTREEITEM hIcon = m_TreeResource.InsertItem (_T("Icon"), 2, 3, hRoot);
		HTREEITEM hMenu = m_TreeResource.InsertItem (_T("Menu"), 2, 3, hRoot);
		m_TreeResource.InsertItem (_T("IDC_WINCLASS"), 8, 8, hAcc);
		m_TreeResource.InsertItem (_T("IDB_BUILD"), 7, 7, hBit);
		m_TreeResource.InsertItem (_T("IDB_EDITTOOLBAR"), 7, 7, hBit);
		m_TreeResource.InsertItem (_T("IDB_MAINTOOLBAR"), 7, 7, hBit);
		m_TreeResource.InsertItem (_T("IDD_ABOUTBOX_MDI"), 9, 9, hDial);
		m_TreeResource.InsertItem (_T("IDI_SMALL"), 10, 10, hIcon);
		m_TreeResource.InsertItem (_T("IDI_BASEMENU"), 11, 11, hMenu);
		m_TreeResource.InsertItem (_T("IDI_MENUHELLO"), 11, 11, hMenu);
		m_TreeResource.InsertItem (_T("IDI_MENUOPTION"), 11, 11, hMenu);
		m_TreeResource.Expand (hRoot, TVE_EXPAND);
		m_TreeResource.Expand (hAcc, TVE_EXPAND);
		m_TreeResource.Expand (hBit, TVE_EXPAND);
		m_TreeResource.Expand (hDial, TVE_EXPAND);
		m_TreeResource.Expand (hIcon, TVE_EXPAND);
		m_TreeResource.Expand (hMenu, TVE_EXPAND);
	
	}

	
	virtual BOOL OnPaint(HDC hDC)
	{
		CRect rcClient;
		CPaintDC dc(GetSafeHwnd()); // device context for painting
		m_TreeResource.GetWindowRect(rcClient);
		ScreenToClient(rcClient);
		rcClient.InflateRect(1,1);
		rcClient.bottom+=1;
		dc.Draw3dRect(rcClient,GetSysColor(COLOR_BTNSHADOW),GetSysColor(COLOR_BTNSHADOW));
		dc.DeleteDC();
		return TRUE;
	}

	virtual void UpdatePanel()
	{
		CRect rc;
		
		GetClientRect(rc);
		
		rc.right-=2;
		rc.bottom-=3;
		rc.DeflateRect(1,1);
		m_TreeResource.SetWindowPos(NULL,rc,SWP_NOACTIVATE|SWP_NOZORDER);	
	}
};
