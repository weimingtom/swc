#pragma once

#include "stdafx.h"
#include "CDockPanelBase.h"
#include "CTreeViewCtrl.h"
#include "CImageCtrl.h"

class CClassView : public CDockPanelBase
{
protected:
	CTreeViewCtrl	  m_TreeResource;
	CImageCtrl	Image;
public:
	CClassView()
	{
		
	}

	~CClassView()
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
		HTREEITEM hRoot = m_TreeResource.InsertItem (_T("My Project"), 0, 0);
		
		m_TreeResource.InsertItem (_T("Global Functions and Variables"), 20, 20, hRoot);
		m_TreeResource.InsertItem (_T("Macros and Constantes"), 21, 21, hRoot);
		m_TreeResource.InsertItem (_T("CAbout"), 19, 19, hRoot);
		m_TreeResource.InsertItem (_T("CAppMain"), 19, 19, hRoot);
		m_TreeResource.InsertItem (_T("CClassView"), 19, 19, hRoot);
		m_TreeResource.InsertItem (_T("CExplorer"),19, 19, hRoot);
		m_TreeResource.InsertItem (_T("COutputList"), 19, 19, hRoot);
		m_TreeResource.InsertItem (_T("CResourcce"), 19, 19, hRoot);
		m_TreeResource.Expand (hRoot, TVE_EXPAND);
		
	
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
