#include "stdafx.h"
#include "CMiniDock.h"

void CMiniDock::OnLButtonUp(UINT nHitTest, CPoint pt)
 {
	ReleaseCapture();
	//if (bDrawTab)
	//	DrawFrame(m_OldrcTab);
	
	if (bDrawNormalDock)
		DrawFrame(m_OldrcDock);
	
	if (bDrawNormal)
		DrawFrame(m_Oldrc);
	
	m_Drag=FALSE;
	m_Oldrc.DeflateRect(1,1);
	CRect mWin;
	GetWindowRect(mWin);
	if (bDrawTab || bDrawNormalDock )
	{
			CPoint point;
			CRect rcL;
			CRect rcB;
			CRect rcR;
			GetCursorPos(&point);
			theApp->m_WinMain->m_DockLeft->GetWindowRect(rcL);
			theApp->m_WinMain->m_DockBottom->GetWindowRect(rcB);
			theApp->m_WinMain->m_DockRight->GetWindowRect(rcR);

			if (rcL.PtInRect(point))
			{
				CContainer* m_ct=theApp->m_WinMain->m_DockLeft->PointIsInCaption(point);
				if (m_ct != NULL)
				{
					int iT= ((CContainer*)m_ClientView)->GetCount(); //how many tabs we have?
					for (int i=0; i < iT; i++)
					{
						CTab* ct=((CContainer*)m_ClientView)->GetTab(i);
						ct->pParent->SetParent (m_ct);
						m_ct->Addtab(ct->pParent,ct->lpMsg,ct->nMenu);
					}

				}
				else
				{
					int iNum=theApp->m_WinMain->m_DockLeft->GetNumVisibleWindows();
					CRect rcW;
					int pos;
					int iDock=theApp->m_WinMain->m_DockLeft->PointInDock(point, rcW, pos);
					if (iDock == 0)
					{
						int iNum=theApp->m_WinMain->m_DockLeft->GetNumVisibleWindows();
						if (rcL.PtInRect(point))
							{
								iDock=1;
								pos =0;
							}
						
					}
					m_ClientView->SetParent (theApp->m_WinMain->m_DockLeft);
					if ( iDock==1)
						theApp->m_WinMain->m_DockLeft->AddWindow(m_ClientView,pos);
					else if( iDock==2)
					{
							if (iNum == pos)
								theApp->m_WinMain->m_DockLeft->AddWindow(m_ClientView);
							else
								theApp->m_WinMain->m_DockLeft->AddWindow(m_ClientView,pos+1);
					}
					
					
				}
				SendMessage(WM_CLOSE,0,0);
				theApp->m_WinMain->UpdateFrame();
			}
			else if (rcR.PtInRect(point))
			{
				CContainer* m_ct=theApp->m_WinMain->m_DockRight->PointIsInCaption(point);
				if (m_ct != NULL)
				{
					int iT= ((CContainer*)m_ClientView)->GetCount(); //how many tabs we have?
					for (int i=0; i < iT; i++)
					{
						CTab* ct=((CContainer*)m_ClientView)->GetTab(i);
						ct->pParent->SetParent (m_ct);
						m_ct->Addtab(ct->pParent,ct->lpMsg,ct->nMenu);
					}


				}
				else
				{
					int iNum=theApp->m_WinMain->m_DockRight->GetNumVisibleWindows();
					CRect rcW;
					int pos;
					int iDock=theApp->m_WinMain->m_DockRight->PointInDock(point, rcW, pos);
					if (iDock == 0)
					{
						int iNum=theApp->m_WinMain->m_DockRight->GetNumVisibleWindows();
						if (rcR.PtInRect(point))
							{
								iDock=1;
								pos =0;
							}
						
					}
					m_ClientView->SetParent (theApp->m_WinMain->m_DockRight);
					if ( iDock==1)
						theApp->m_WinMain->m_DockRight->AddWindow(m_ClientView,pos);
					else if( iDock==2)
					{
							if (iNum == pos)
								theApp->m_WinMain->m_DockRight->AddWindow(m_ClientView);
							else
								theApp->m_WinMain->m_DockRight->AddWindow(m_ClientView,pos+1);
					}
					
					
				}

				SendMessage(WM_CLOSE,0,0);
				theApp->m_WinMain->UpdateFrame();
			}

			else if (rcB.PtInRect(point))
			{
				CContainer* m_ct=theApp->m_WinMain->m_DockBottom->PointIsInCaption(point);
				if (m_ct != NULL)
				{
					int iT= ((CContainer*)m_ClientView)->GetCount(); //how many tabs we have?
					for (int i=0; i < iT; i++)
					{
						CTab* ct=((CContainer*)m_ClientView)->GetTab(i);
						ct->pParent->SetParent (m_ct);
						m_ct->Addtab(ct->pParent,ct->lpMsg,ct->nMenu);
					}


				}
				else
				{

					int iNum=theApp->m_WinMain->m_DockBottom->GetNumVisibleWindows();
					CRect rcW;
					int pos;
					int iDock=theApp->m_WinMain->m_DockBottom->PointInDock(point, rcW, pos);
					
					m_ClientView->SetParent (theApp->m_WinMain->m_DockBottom);
					if (iDock == 0)
					{
						int iNum=theApp->m_WinMain->m_DockBottom->GetNumVisibleWindows();
						if (rcB.PtInRect(point))
							{
								iDock=1;
								pos =0;
							}
						
					}
					if ( iDock==1)
						theApp->m_WinMain->m_DockBottom->AddWindow(m_ClientView,pos);
					else if( iDock==2)
					{
							if (iNum == pos)
								theApp->m_WinMain->m_DockBottom->AddWindow(m_ClientView);
							else
								theApp->m_WinMain->m_DockBottom->AddWindow(m_ClientView,pos+1);
					}
				
				}
				SendMessage(WM_CLOSE,0,0);
				theApp->m_WinMain->UpdateFrame();
			}
			bDrawTab=FALSE;
			bDrawNormalDock=FALSE;
			bDrawNormal=FALSE;
	}else
	{
		bDrawNormal=TRUE;
		SetWindowPos(0,m_Oldrc, SWP_NOSIZE|SWP_NOACTIVATE|SWP_NOZORDER|SWP_DRAWFRAME|SWP_NOSENDCHANGING|SWP_SHOWWINDOW);
	}
	
	Default();
 }

void CMiniDock::DrawNormal()
{
		CPoint pt;
		GetCursorPos(&pt);
		if ((m_oldPost.x != pt.x) || 
					(m_oldPost.y != pt.y))
				{
									
 				   int widht=mWin.Width();
					int Height=mWin.Height();
					if (m_oldPost.x < pt.x)
						mWin.left+=abs(m_oldPost.x - pt.x);
					else
						mWin.left-=abs(m_oldPost.x - pt.x);

					if (m_oldPost.y < pt.y)
						mWin.top+=abs(m_oldPost.y - pt.y);
					else
						mWin.top-=abs(m_oldPost.y - pt.y);
					mWin.right=mWin.left+widht;
					mWin.bottom=mWin.top+Height;
					SetWindowPos(0,mWin, SWP_NOSIZE|SWP_NOACTIVATE|SWP_NOZORDER|SWP_DRAWFRAME|SWP_NOSENDCHANGING|SWP_SHOWWINDOW);
					m_Oldrc=mWin;
					m_oldPost=pt;
						
					
				}

}

void CMiniDock::DrawDock(CRect rc,CPoint point,DockManager* mDock, UINT uALing  )
{
	BOOL bHorz = (uALing == BS_ALIGN_BOTTOM);
	CContainer* m_ct=mDock->PointIsInCaption(point);
	if (m_ct != NULL)
	{
		// Si el ultimo draw era flotante normal debemos eliminarlo
		if (bDrawNormal)
		{
			bDrawNormal=FALSE;
		}
		if (bDrawNormalDock)
		{
			DrawFrame(m_OldrcDock);
			bDrawNormalDock=FALSE;
		}
		if (!bDrawTab)
		{
			bDrawTab=TRUE;
			bDrawNormalDock=FALSE;
			bDrawNormal=FALSE;
			m_ct->GetWindowRect(m_OldrcTab);
		}
		
	

	}
	else // is possible dock
	{
		CRect rcW;
		int pos;
		int iDock=mDock->PointInDock(point, rcW, pos);
		if (iDock == 0)
		{
			int iNum=mDock->GetNumVisibleWindows();
			if (iNum == 0)
			{
				if (rc.PtInRect(point))
					{
						rcW=rc;
						iDock=1;
						pos =0;
					}
			}
			
		}
		if (iDock != 0)
		{
			if (bDrawNormal)
			{
				bDrawNormal=FALSE;
			}
			
			if (bDrawTab)
			{
				bDrawTab=FALSE;
			}
			if (!bDrawNormalDock)
			{
				int iNum=mDock->GetNumVisibleWindows();
				m_OldrcDock=rcW;
				if (!bHorz)
				{
					if (iNum <  1)
					{
						if (uALing == BS_ALIGN_RIGHT)
						{
							m_OldrcDock.left-= m_Oldrc.Width();
							m_OldrcDock.right= m_OldrcDock.left+m_Oldrc.Width();
						}
						else
							m_OldrcDock.left+= m_Oldrc.Width();
					}
					else
					{
						if (iDock ==1)
							m_OldrcDock.bottom=rcW.top+ (rcW.Height()/2);
						else
							m_OldrcDock.top=rcW.bottom- (rcW.Height()/2);
					}
					
				}
				else
				{
					if (iNum <  1)
					{
						m_OldrcDock.top-= m_Oldrc.Height();
						m_OldrcDock.bottom= m_OldrcDock.top+m_Oldrc.Height();
					}
					else
					{
						if (iDock ==1)
							m_OldrcDock.right=rcW.left+ (rcW.Width()/2);
						else
							m_OldrcDock.left=rcW.right- (rcW.Width()/2);
					}
					
				}
				DrawFrame(m_OldrcDock);
				bDrawNormalDock=TRUE;
				bDrawTab=FALSE;
				bDrawNormal=FALSE;
			}
		}
		else
		{
				if (bDrawTab)
				{
					bDrawTab=FALSE;
				}
				
				if (bDrawNormalDock)
				{
					DrawFrame(m_OldrcDock);
					bDrawNormalDock=FALSE;
				}
				if (!bDrawNormal)
				{
					DrawNormal();
					bDrawNormal=TRUE;
					bDrawTab=FALSE;
					bDrawNormalDock=FALSE;
				}
				else
				{
					DrawNormal();
				}

	
		}

	}
}

void CMiniDock::OnMouseMove(UINT nHitTest, CPoint pt)
{
	if (m_Drag)
	{
		CPoint point;
		GetCursorPos(&point);

		if ((m_oldPost.x != point.x) || 
					(m_oldPost.y != point.y))
				{
					CRect rcL;
					CRect rcR;
					CRect rcB;
					theApp->m_WinMain->m_DockLeft->GetWindowRect(rcL);
					theApp->m_WinMain->m_DockRight->GetWindowRect(rcR);
					theApp->m_WinMain->m_DockBottom->GetWindowRect(rcB);
					
					if (rcL.PtInRect(point))
					{
						DrawDock(rcL,point,theApp->m_WinMain->m_DockLeft,BS_ALIGN_LEFT);
					}
					else if (rcR.PtInRect(point))
					{
						DrawDock(rcR,point,theApp->m_WinMain->m_DockRight,BS_ALIGN_RIGHT);
					}
					else if(rcB.PtInRect(point) )
					{
						DrawDock(rcB,point,theApp->m_WinMain->m_DockBottom,BS_ALIGN_BOTTOM);
					}
					else
					{
						if (bDrawTab)
						{
							bDrawTab=FALSE;
						}
						
						if (bDrawNormalDock)
						{
							DrawFrame(m_OldrcDock);
							bDrawNormalDock=FALSE;
						}
						if (!bDrawNormal)
						{
							DrawNormal();
							bDrawNormal=TRUE;
							bDrawTab=FALSE;
							bDrawNormalDock=FALSE;
						}
						else
						{
							DrawNormal();
						}

					}
					
				}
	}
	
	Default();
}

void CMiniDock::OnNcLButtonUp(UINT nHitTest, CPoint point)
{

		  if (m_Drag==TRUE) 
		  {
			ReleaseCapture();
			m_Drag=FALSE;
		  }
		  Default();
}

void CMiniDock::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	
	m_Drag=FALSE;
	if (nHitTest == HTCAPTION){
		m_oldPost=point;
		m_Drag=TRUE;
		SetWindowPos(HWND_TOP,0,0,0,0, SWP_NOMOVE|SWP_NOSIZE);
		SetCapture();
		GetWindowRect(mWin);
		mWin.InflateRect(1,1);
     	m_Oldrc=mWin;
		bDrawNormal=TRUE;
		bDrawTab=FALSE;
		bDrawNormalDock=FALSE;
	}
	if (nHitTest == HTCLOSE)
	{
		OnNcButtonDblClk(nHitTest, point);
	}
	Default();
	
}

void CMiniDock::OnNcButtonDblClk(UINT nHitTest, CPoint point)
{
		CRect rc;
			theApp->m_WinMain->m_DockLeft->GetWindowRect(rc);
			UINT ds=((CContainer*)m_ClientView)->m_DOCKSITE;
			if (ds == BS_ALIGN_LEFT)
			{
				m_ClientView->SetParent (theApp->m_WinMain->m_DockLeft);
				theApp->m_WinMain->m_DockLeft->AddWindow(m_ClientView);

			}
			else if (ds == BS_ALIGN_RIGHT)
			{
				m_ClientView->SetParent (theApp->m_WinMain->m_DockRight);
				theApp->m_WinMain->m_DockRight->AddWindow(m_ClientView);
			}

			else if (ds == BS_ALIGN_BOTTOM)
			{
				m_ClientView->SetParent (theApp->m_WinMain->m_DockBottom);
				theApp->m_WinMain->m_DockBottom->AddWindow(m_ClientView);
			}
			else if ( ((CContainer*)m_ClientView)->m_pContainer != NULL)
			{
				CTab* ct=((CContainer*)m_ClientView)->GetTab(0);
				ct->pParent->SetParent (((CContainer*)m_ClientView)->m_pContainer);
				((CContainer*)m_ClientView)->m_pContainer->Addtab(ct->pParent);
			}
			else{
				
					
				Default();	
				return;
			}
			SendMessage(WM_CLOSE,0,0);
			theApp->m_WinMain->UpdateFrame();
			Default();	
			
	
}

void CMiniDock::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	Default();	
}

void CMiniDock::OnWindowPostChanging(LPWINDOWPOS lpWindowsPos)
 {
	 
	Default();

}

void CMiniDock::OnKeyDown(int iKey, DWORD dTime)
{
	if (!m_Drag) return;
	if (iKey == VK_ESCAPE)
		OnLButtonUp(0, CPoint(0,0));
}

void CMiniDock::OnRButtonDown(UINT nHitTest, CPoint point)
 {
	OnLButtonUp(0, CPoint(0,0));
 }

void CMiniDock::DrawFrame(CRect rc, BOOL bDrawTab)
{
	if (bDrawNormal) return;
	CWin cm(theApp->m_WinMain->GetDesktopWindow());
	CGDI pDC(cm.GetDCEx(NULL,DCX_WINDOW|DCX_CACHE|DCX_LOCKWINDOWUPDATE));
	CBrush* pBrush = CGDI::HalftGray();
    CBrush pBrushOld(pDC.SelectObject(pBrush));
	CRect rc1=rc;
	HRGN hRgn=	 CreateRectRgnIndirect(rc);
	rc.DeflateRect(3,3);
	rc.IntersectRect(rc,rc1);
	HRGN hRgnIn= CreateRectRgnIndirect(rc);
	HRGN hRgnDif=CreateRectRgn(0,0,0,0);
	CombineRgn(hRgnDif,hRgnIn,hRgn,RGN_XOR);
	pDC.SelectClipRgn(hRgnDif);	
	pDC.GetClipBox(rc);
	pDC.PatBlt(rc, PATINVERT);
	::DeleteObject(hRgn);
	::DeleteObject(hRgnIn);
	::DeleteObject(hRgnDif);
	pDC.SelectObject(&pBrushOld);
    cm.ReleaseDC(pDC.m_hDC);
	pBrush->DeleteObject();
	delete pBrush;

}
