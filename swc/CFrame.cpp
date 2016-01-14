#include "stdafx.h"
#include "CFrame.h"
#include "CMiniDock.h"

void CFrame::CreateDock()
{
	m_DockLeft = new DockManager;
	if (!m_DockLeft->Create(WS_VISIBLE|WS_CHILD,CRect(0,0,100,100),this,BS_ALIGN_LEFT))
		return ;

	m_DockBottom = new DockManager;
	if (!m_DockBottom->Create(WS_VISIBLE|WS_CHILD,CRect(0,0,100,100),this,BS_ALIGN_BOTTOM))
		return ;

	m_DockRight = new DockManager;
	if (!m_DockRight->Create(WS_VISIBLE|WS_CHILD,CRect(0,0,100,100),this,BS_ALIGN_RIGHT))
		return ;
}

void CFrame::ShowFloatWindow(HWND hWnd)
{
	//CWin cw(hWnd);
	//cw.ShowWindow(TRUE);
	CContainer *cc=m_DockLeft->GetWichContainerIsTheParent(hWnd);
	if (cc != NULL)
		cc->ShowPane(TRUE);
	else if ((cc=m_DockBottom->GetWichContainerIsTheParent(hWnd))!= NULL) 
		cc->ShowPane(TRUE);
	else if ((cc=m_DockRight->GetWichContainerIsTheParent(hWnd))!= NULL) 
		cc->ShowPane(TRUE);

	UpdateFrame(TRUE);
}
void CFrame::UpdateFrame(BOOL bResizeBars)
{

	CRect rc;
	GetClientRect(rc);
	HDWP hDWP = ::BeginDeferWindowPos(3); 
			
	if (HIWORD(m_ReBar))
		if(m_ReBar->GetSafeHwnd() != NULL &&  m_ReBar->IsWindowVisible())
		{
			if (bResizeBars)
				::SendMessage(m_ReBar->GetSafeHwnd(), WM_SIZE, 0, 0);

			RECT rectTB;
			::GetWindowRect(m_ReBar->GetSafeHwnd(), &rectTB);
			rc.top += rectTB.bottom - rectTB.top;
			rc.top++;
		}
	
		if(m_statusCtrl.GetSafeHwnd() != NULL && m_statusCtrl.IsWindowVisible() )
		{
			if(bResizeBars)
			{
				m_statusCtrl.Size();
				m_statusCtrl.Invalidate();
				m_statusCtrl.UpdateWindow();
			}
			RECT rectSB;
			::GetWindowRect(m_statusCtrl.GetSafeHwnd(), &rectSB);
			rc.bottom -= (rectSB.bottom - rectSB.top)+2;
		}
	
	
	if (HIWORD(m_DockBottom))
	{
		CRect rcw;
		if (m_DockBottom->GetNumChild()> 0)
		{
			int iii=m_DockBottom->GetNumVisibleWindows();
			if (iii<=0)
			 DeferWindow(hDWP,m_DockBottom->GetSafeHwnd(),NULL,rc.left,rc.top,rc.left+3,rc.bottom,SWP_NOZORDER | SWP_NOACTIVATE|SWP_HIDEWINDOW);
			else
			{
				m_DockBottom->GetWindowRect(rcw);
				CSize cz=m_DockBottom->Getsize();
				if (cz.cy == 0)
					cz.cy=120;
				DeferWindow(hDWP,m_DockBottom->GetSafeHwnd(),NULL,rc.left,rc.bottom-((cz.cy<=0)?rcw.Height():cz.cy),rc.Width(),((cz.cy<=0)?rcw.Height():cz.cy),SWP_NOZORDER | SWP_NOACTIVATE|SWP_SHOWWINDOW);
				rc.bottom-=((cz.cy<=0)?rcw.Height():cz.cy);
				m_DockBottom->RecalLayout();
			}
		}
		else
		{
			DeferWindow(hDWP,m_DockBottom->GetSafeHwnd(),NULL,rc.left,rc.bottom-3,rc.Width(),rc.bottom,SWP_NOZORDER | SWP_NOACTIVATE|SWP_HIDEWINDOW);
		}

	}

	if (HIWORD(m_DockRight))
	{
		CRect rcw;
		if (m_DockRight->GetNumChild()> 0)
		{
			int iii=m_DockRight->GetNumVisibleWindows();
			if (iii<=0)
			 DeferWindow(hDWP,m_DockRight->GetSafeHwnd(),NULL,rc.left,rc.top,rc.left+3,rc.bottom,SWP_NOZORDER | SWP_NOACTIVATE|SWP_HIDEWINDOW);
			else
			{
				m_DockRight->GetWindowRect(rcw);
				CSize cz=m_DockRight->Getsize();
				if (cz.cx == 0)
					cz.cx=120;
				DeferWindow(hDWP,m_DockRight->GetSafeHwnd(),NULL,rc.right-((cz.cx<=0)?rcw.Width()-4:cz.cx-4),rc.top+2,((cz.cx<=0)?rcw.Width()-4:cz.cx-4),rc.Height(),SWP_NOZORDER | SWP_NOACTIVATE|SWP_SHOWWINDOW);
				rc.right-=((cz.cx<=0)?rcw.Width()-2:cz.cx-2);
				m_DockRight->RecalLayout();
			}
		}
		else
			DeferWindow(hDWP,m_DockRight->GetSafeHwnd(),NULL,rc.right-3,rc.top,rc.right,rc.bottom,SWP_NOZORDER | SWP_NOACTIVATE|SWP_HIDEWINDOW);
		
	}
	if (HIWORD(m_DockLeft))
	{
		CRect rcw;
		if (m_DockLeft->GetNumChild()>0)
		{
			int iii=m_DockLeft->GetNumVisibleWindows();
			if (iii<=0)
			 DeferWindow(hDWP,m_DockLeft->GetSafeHwnd(),NULL,rc.left,rc.top,rc.left+3,rc.bottom,SWP_NOZORDER | SWP_NOACTIVATE|SWP_HIDEWINDOW);
			else
			{
				m_DockLeft->GetWindowRect(rcw);
				ScreenToClient(rcw);
				CSize cz=m_DockLeft->Getsize();
				if (cz.cx == 0)
					cz.cx=120;
				DeferWindow(hDWP,m_DockLeft->GetSafeHwnd(),NULL,rc.left,rc.top+1,((cz.cx<=0)?rcw.Width():cz.cx),rc.Height(),SWP_NOZORDER | SWP_NOACTIVATE|SWP_SHOWWINDOW);
				
				rc.left+=((cz.cx<=0)?rcw.Width():cz.cx);
				m_DockLeft->RecalLayout();
			}
		}
		else
			DeferWindow(hDWP,m_DockLeft->GetSafeHwnd(),NULL,rc.left,rc.top,rc.left+3,rc.bottom,SWP_NOZORDER | SWP_NOACTIVATE|SWP_HIDEWINDOW);
	}
	if (hMDIClient!=NULL || HIWORD(m_ClientView) )
	{
		DeferWindow(hDWP,hMDIClient==NULL?m_ClientView->GetSafeHwnd():hMDIClient,NULL,rc.left,rc.top+2,rc.Width(),rc.Height()-1,SWP_NOZORDER | SWP_NOACTIVATE);
	}

	if (hDWP != NULL)
		::EndDeferWindowPos(hDWP);

}

BOOL CFrame::LoadFrame(UINT nID,DWORD dwStyle,HWND hParentWnd)
{	
	TCHAR szTemp[256];
	int nLen;
	LPCTSTR lpszName = MAKEINTRESOURCE((nID>>4)+1);
	if (::FindResource(GetModuleHandle(NULL), lpszName, RT_STRING) != NULL &&
		(nLen = ::LoadString(GetModuleHandle(NULL), nID, szTemp, 255) != 0)) {
	}

	BOOL bRes= Create(_T("MotsusMainWindow"),szTemp,dwStyle,CRect(0,0,200,200),hParentWnd,nID);
	uiTimerId = GfxSetSafeTimer(this, 100);
	return bRes;	
}


void CFrame::LoadPositionBar()
{
	//la idea es organizar toda las ventanas una vez se han cargado todas las ventanas
	//incluyendo el frame principal.
	//la idea es recorer cada una de las ventanas y ver cuales son ventanas principales
	// verificar cuales son flotantes de las principales y ponerlas a flotar.
	//luego recorer todas las ventanas e identificar cuales son hijas de un tab y retirarlas
	// de cada uno de los Cwindock y ubicarlas en cada uno de los tab.
	// Si las ventanas flotantes retirarlas creado un nuevo Container y ponderlas a flotar.
	// si no hay informacion de posicion de la ventana debe permanecer en la posicion de Cwindock.
	// si las ventanas son ocultas se deben esconder, pero manteniendo la position.
	
	//primero los criticos son las  ventanas flotantes y los tabs.
	//DockLeft
	if (m_DockLeft->GetNumChild() > 0)
	{
		for (int i=0; i < m_DockLeft->GetNumChild(); i++)
		{
			CDockPanelBase* pWin= (CDockPanelBase*)m_DockLeft->GetNumWnd(i) ;
			if (pWin->uAling == BS_FLOATING)
			{
				//pongamos a volar la ventana

			}

		}
	}
	int iDockWin=0;
	for (; iDockWin < 3; iDockWin++)
	{

		//las ventanas criticas son las flotantes y las principales.




	}// fin del bucle DockWin

	
}

void CFrame::FloatWindow(CWin* pParent, CPoint point, CRect rcw )
	{
		if (!HIWORD(pParent)) return;
		m_MiniFrame= new CMiniDock;
		//FIXME:
		CRect rect = CRect(point.x-4,point.y-4,point.x+200,point.y+200);
		CRect& rect2 = rect;
		if (!m_MiniFrame->Create(this,0x1004,
			rect2,pParent))
			return;
		
		m_MiniFrame->PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x+200, point.y+4));
		
	}

int  CFrame::OnPaint(HDC hDC)
{
	//DrawNcMenuBar(hDC);
	//Default();	
	return 0;
}
