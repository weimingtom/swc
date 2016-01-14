#include "stdafx.h"
#include "CMiniFrame.h"

BOOL CMiniFrame::Create(CWin* pParentWnd, UINT nID, CRect& rc, CWin* pControls, DWORD dwStyle)
	{

		pParent=pParentWnd;
		m_ClientView=pControls;
		if (!m_ClientView) 
		{
			delete this;
			return false;
		}
	
		LPCTSTR lpclassname=RegisterDefaultClass();
		dwStyle|=WS_THICKFRAME;
		BOOL rb;
		CPoint pt (rc.left, rc.bottom);
		rb=CWin::Create(lpclassname,NULL,dwStyle,rc, pParentWnd->GetSafeHwnd(), nID);
		m_ClientView->SetWindowPos (NULL, 0, 0, 0, 0, SWP_NOZORDER|SWP_NOSIZE|SWP_SHOWWINDOW);
		m_ClientView->SetParent (this);
		m_ClientView->ShowWindow(SW_SHOW);
		ShowWindow (SW_HIDE);
		return rb;
	}

BOOL CMiniFrame::OnDestroy()
{
	
	return TRUE;
}
