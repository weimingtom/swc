#pragma once

#include "stdafx.h"
#include "CDockPanelBase.h"
#include "CToolBarCtrlEx.h"
#include "CTreeViewCtrl.h"
#include "CComboBox.h"
#include "CImageCtrl.h"
#include "CPaintDC.h"

class CExplorer : public CDockPanelBase
{
protected:
	CToolBarCtrlEx    m_ToolBarBuild;
	CTreeViewCtrl	  m_TreeExplorer;
	CComboBox	  m_comboboxExt;
	CImageCtrl	Image;
public:
	CExplorer()
	{
		
	}
	~CExplorer()
	{
		SaveConfig();
	}
protected:
	virtual BOOL OnCreate(LPCREATESTRUCT lpCreateStruct)
	{

		if ( !m_ToolBarBuild.Create(GetSafeHwnd(),IDR_BUILD_PWC))
		return -1;
	
		if (!m_comboboxExt.Create(GetSafeHwnd(),0x10000,NULL,WS_CHILD|WS_VISIBLE|CBS_DROPDOWN  | 
							WS_VSCROLL | CBS_HASSTRINGS |CBS_OWNERDRAWVARIABLE))
							return -1;

		m_ToolBarBuild.LoadToolBar(IDR_BUILD_PWC);
		m_ToolBarBuild.AddTrueColor(IDB_BUILD_PWC,TB_SETIMAGELIST);
		if (!m_TreeExplorer.Create(GetSafeHwnd(),WS_CHILD | WS_VISIBLE | TVS_HASLINES | 
								TVS_LINESATROOT | TVS_HASBUTTONS, 2))
		return -1;
	
		
		
		if(!Image.CreateColor(IDB_TREEEXPLORER_PWC)) 
			return FALSE;
		m_TreeExplorer.SetImageList(Image.GetImageHandle(),TVSIL_NORMAL);
		PopulateTree();
		return TRUE;
	}

	void PopulateTree()
	{
		HTREEITEM hRoot = m_TreeExplorer.InsertItem (_T("MySwc files"), 0, 0);
		HTREEITEM hSrc = m_TreeExplorer.InsertItem (_T("Source Files"), 2, 3, hRoot);

		m_TreeExplorer.InsertItem (_T("CMainWin.cpp"), 4, 4, hSrc);
		m_TreeExplorer.InsertItem (_T("CMenuSpawn.cpp"), 4, 4, hSrc);
		m_TreeExplorer.InsertItem (_T("CWinDock.cpp"), 4, 4, hSrc);
		m_TreeExplorer.InsertItem (_T("StdAfx.cpp"), 4, 4, hSrc);
		m_TreeExplorer.InsertItem (_T("MainFrm.cpp"), 4, 4, hSrc);
		m_TreeExplorer.InsertItem (_T("CComboBoxExt.cpp"), 4, 4, hSrc);
		m_TreeExplorer.InsertItem (_T("CContainer.cpp"), 4,4, hSrc);
		m_TreeExplorer.InsertItem (_T("CCFolder.cpp"), 4, 4, hSrc);
		m_TreeExplorer.InsertItem (_T("CCMMedia.cpp"), 4, 4, hSrc);
		m_TreeExplorer.InsertItem (_T("CCOutLook.cpp"), 4, 4, hSrc);
		m_TreeExplorer.InsertItem (_T("CSplitter.cpp"), 4, 4, hSrc);
		m_TreeExplorer.InsertItem (_T("CTabbed.cpp"), 4, 4, hSrc);
		m_TreeExplorer.InsertItem (_T("CWorkTab.cpp"), 4, 4, hSrc);

		HTREEITEM hInc = m_TreeExplorer.InsertItem (_T("Header Files"), 2, 3, hRoot);

		m_TreeExplorer.InsertItem (_T("CMainWin.h"), 5, 5, hInc);
		m_TreeExplorer.InsertItem (_T("CMenuSpawn.h"), 5, 5, hInc);
		m_TreeExplorer.InsertItem (_T("CWinDock.h"), 5, 5, hInc);
		m_TreeExplorer.InsertItem (_T("StdAfx.h"), 5, 5, hInc);
		m_TreeExplorer.InsertItem (_T("MainFrm.h"), 5, 5, hInc);
		m_TreeExplorer.InsertItem (_T("CComboBoxExt.h"), 5, 5, hInc);
		m_TreeExplorer.InsertItem (_T("CContainer.h"), 5, 5, hInc);
		m_TreeExplorer.InsertItem (_T("CCFolder.h"), 5, 5, hInc);
		m_TreeExplorer.InsertItem (_T("CCMMedia.h"), 5, 5, hInc);
		m_TreeExplorer.InsertItem (_T("CCOutLook.h"), 5, 5, hInc);
		m_TreeExplorer.InsertItem (_T("CSplitter.h"),5, 5, hInc);
		m_TreeExplorer.InsertItem (_T("CTabbed.h"), 5,5, hInc);
		m_TreeExplorer.InsertItem (_T("CWorkTab.h"), 5, 5, hInc);

		HTREEITEM hRes = m_TreeExplorer.InsertItem (_T("Resource Files"), 2, 3, hRoot);

		m_TreeExplorer.InsertItem (_T("MySwc.ico"), 10, 10, hRes);
		m_TreeExplorer.InsertItem (_T("MySwc.rc2"), 9, 9, hRes);
		m_TreeExplorer.InsertItem (_T("MySwcDoc.ico"), 10, 10, hRes);
		m_TreeExplorer.InsertItem (_T("Toolbar.bmp"), 13, 13, hRes);

		m_TreeExplorer.Expand (hRoot, TVE_EXPAND);
		m_TreeExplorer.Expand (hSrc, TVE_EXPAND);
		m_TreeExplorer.Expand (hInc, TVE_EXPAND);
		m_TreeExplorer.Expand (hRes, TVE_EXPAND);
	}

	
	virtual BOOL OnPaint(HDC hDC)
	{
		CRect rcClient;
		CPaintDC dc(GetSafeHwnd()); // device context for painting
		m_TreeExplorer.GetWindowRect(rcClient);
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
		CRect rcT;
		GetClientRect(rc);
		int nVal=0;
		rcT=rc;
		nVal=rc.top;
		rcT.bottom=22;
		m_comboboxExt.SetWindowPos(NULL,rcT,SWP_NOACTIVATE|SWP_NOZORDER);
		nVal+=24;
		rcT=rc;
		rcT.top=nVal;
		rcT.bottom=22;
		nVal+=22+2;
		m_ToolBarBuild.SetWindowPos(NULL,rcT,SWP_NOACTIVATE|SWP_NOZORDER);
		rcT=rc;
		rcT.right-=2;
		rcT.top=nVal;
		rcT.bottom-=nVal+3;
		rcT.DeflateRect(1,1);
		m_TreeExplorer.SetWindowPos(NULL,rcT,SWP_NOACTIVATE|SWP_NOZORDER);
		
	}
};
