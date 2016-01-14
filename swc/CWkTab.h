#pragma once

#include "stdafx.h"
#include "CDockPanelBase.h"
#include "CWorkTab.h"
#include "COutputList.h"
#include "CHeaderView.h"

class CWkTab : public CDockPanelBase
{
protected:
	CWorkTab	  m_wktab;
	
	COutputList m_wndOutList1;
	COutputList m_wndOutList2;
	COutputList m_wndOutList3;
	CHeaderView m_h1;
	CHeaderView m_h2;
	CHeaderView m_h3;
public:
	CWkTab()
	{
			
	}

	~CWkTab()
	{
		
	}
protected:
	virtual BOOL OnCreate(LPCREATESTRUCT lpCreateStruct)
	{

		if (!m_wktab.Create(WS_VISIBLE|WS_CHILD,CRect(0,0,0,0),this,0x9933))
			return -1;


		
			//-------------------------------------------------------------
			m_wndOutList1.Create (m_wktab.GetSafeHwnd(),WS_CHILD | WS_VISIBLE | WS_VSCROLL | LVS_REPORT,7000);
			m_wndOutList2.Create (m_wktab.GetSafeHwnd(),WS_CHILD | WS_VISIBLE | WS_VSCROLL | LVS_REPORT,8000);
			m_wndOutList3.Create (m_wktab.GetSafeHwnd(),WS_CHILD | WS_VISIBLE | WS_VSCROLL | LVS_REPORT,9000);
			
			m_wndOutList1.SendMessage (LVM_SETEXTENDEDLISTVIEWSTYLE, 0,
								LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
			m_wndOutList1.InsertColumn (0, _T("Description"), LVCFMT_LEFT, 200,0);
			m_wndOutList1.InsertColumn (1, _T("Line"), LVCFMT_LEFT, 100,0);

			m_wndOutList1.InsertItemText (0, _T("Could not open the temporary file c:\\temp\\example.exe"));
			m_wndOutList1.InsertItemText (0, 1, _T("23"));

			m_wndOutList2.SendMessage (LVM_SETEXTENDEDLISTVIEWSTYLE, 0,
								LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
			m_wndOutList2.InsertColumn (0, _T("Description"), LVCFMT_LEFT, 400,0);
			
			m_wndOutList2.InsertItemText (0, _T("Project loaded c:\\temp\\example.exe"));
			m_wndOutList2.InsertItemText (0, _T("Project loaded Microsoft.windows.common-controls"));
			m_wndOutList2.InsertItemText (0, _T("Project loaded c:\\windows\\system32\\shlapi.dll"));

			m_wndOutList3.SendMessage (LVM_SETEXTENDEDLISTVIEWSTYLE, 0,
								LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
			m_wndOutList3.InsertColumn (0, _T("Description"), LVCFMT_LEFT, 300,0);
			
			m_wndOutList3.InsertItemText (0, _T("Project loaded c:\\temp\\example.exe No sysmbols loaded"));
			m_wndOutList3.InsertItemText (0, _T("Project loaded PwcStudio [4260] Native has exit with code 0 (0x0)"));

			HWND hWndHeader = m_wndOutList1.GetDlgItem(0);
			m_h1.SubclassWnd(hWndHeader);

			hWndHeader = m_wndOutList2.GetDlgItem(0);
			m_h2.SubclassWnd(hWndHeader);

			hWndHeader = m_wndOutList3.GetDlgItem(0);
			m_h3.SubclassWnd(hWndHeader);

			m_wktab.Addtab (&m_wndOutList1, _T("Error List"));
			m_wktab.Addtab (&m_wndOutList2, _T("Command"));
			m_wktab.Addtab (&m_wndOutList3, _T("Output"));
			m_wktab.SetCaption();
			SetWindowText(_T("Demo Worktab"));
		//-------------------------------------------------------------

		return TRUE;
	}

		
	virtual BOOL OnPaint(HDC hDC)
	{
		CRect rcClient;
		CPaintDC dc(GetSafeHwnd()); // device context for painting
		m_wktab.GetWindowRect(rcClient);
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
		m_wktab.SetWindowPos(NULL,rc,SWP_NOACTIVATE|SWP_NOZORDER);	
	}
};
