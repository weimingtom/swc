#pragma once

#include "stdafx.h"
#include "CStatusCtrl.h"
#include "CFont.h"
#include "CString.h"

class CStatusCtrlEx: public CStatusCtrl
{

	enum Style{DEVSTUDIO=0,OFFICE=1};
	CFont m_cfont;
	Style m_Style;
public:

	CStatusCtrlEx()
	{
		m_Style=DEVSTUDIO;
		m_cfont.CreateFont(14,0,0,0,400,0,0,0,0,1,2,1,34,"Arial");
	}

	~CStatusCtrlEx()
	{
		m_cfont.DeleteObject();
	}

public:
	
	void SetStyle(Style nStyle)
	{
		m_Style=nStyle;
	}

	BOOL OnPaint(HDC hDC)
	{
		CRect rcClient,rcTemp;
		CBrush cb;
		CPaintDC dc(GetSafeHwnd()); 
		GetClientRect(&rcClient);
		cb.CreateSolidBrush(CDrawLayer::GetRGBColorFace());
		rcTemp=rcClient;
		CGDI		MemDC;
		CBitmap		m_BitmapMemDC;
		MemDC.CreateCompatibleDC(dc.m_hDC);
		m_BitmapMemDC.CreateCompatibleBitmap(dc.m_hDC,rcClient.Width(),rcClient.Height());	
		CBitmap *m_bitmapOld=new CBitmap(MemDC.SelectObject(&m_BitmapMemDC));
		MemDC.FillRect(&rcClient,&cb);

		/*CGradient M(CSize(rcClient.Width(),rcClient.Height()));	
		M.PrepareVertical(&dc);
		M.Draw(&MemDC,0,0,0,0,rcClient.Width(),rcClient.Height(),SRCCOPY);
		*/Drawpanels(&MemDC);
		dc.BitBlt(0,0,rcClient.Width(),rcClient.Height(),MemDC.m_hDC,
		     rcClient.left,rcClient.top,SRCCOPY);
		MemDC.SelectObject(m_bitmapOld);
		m_BitmapMemDC.DeleteObject();
		MemDC.DeleteDC();
		cb.DeleteObject();
		dc.DeleteDC();
		m_bitmapOld->DeleteObject();
		delete m_bitmapOld;
		return TRUE;
	}

	
	void  Drawpanels(CGDI *pDC)
	{
		int iCont=GetNumPanels();
		CRect rcCli,rcCliente;
		CString m_cad;
		int OldMode=pDC->SetBkMode(TRANSPARENT);
		for (int i=0; i < iCont; i++)
		{
			TCHAR lpsText[100];
			GetText(i, lpsText);
			GetPaneRect(i,&rcCli);
			CSize m_sChar(GetTextLength(i),0);
			if (rcCli.Width() < m_sChar.cx)
			{
				int dif=m_sChar.cx-rcCli.Width();
				rcCli.right=rcCli.left+m_sChar.cx-dif;
			}
			
			/*CGradient M(CSize(rcCli.Width(),rcCli.Height()));	
			M.PrepareReverseVert(pDC);
			M.Draw(pDC,rcCli.left,rcCli.top,0,0,rcCli.Width(),rcCli.Height(),SRCCOPY);

			*/
			if (m_Style == DEVSTUDIO)
				pDC->Draw3dRect(rcCli,CDrawLayer::GetRGBColorShadow(),CDrawLayer::GetRGBColorShadow());
			else
				pDC->Draw3dRect(rcCli,CDrawLayer::GetRGBColorTabs(),CDrawLayer::GetRGBColorTabs());
			if (i == iCont-1)
			{
				rcCli.left=rcCli.right;
				rcCli.right=rcCli.left+2;
				pDC->Draw3dRect(rcCli,CDrawLayer::GetRGBColorFace(),CDrawLayer::GetRGBColorFace());
				rcCli.right+=1;
				pDC->Draw3dRect(rcCli,CDrawLayer::GetRGBColorFace(),CDrawLayer::GetRGBColorFace());
				rcCli.right+=1;
				pDC->Draw3dRect(rcCli,CDrawLayer::GetRGBColorFace(),CDrawLayer::GetRGBColorFace());

			}
			CPoint pti;
			HFONT m_fontOld=pDC->SelectFont(m_cfont);
			CSize szText=pDC->GetTextExtent(lpsText,lstrlen(lpsText));
			pti.x= rcCli.left+4;
			pti.y=(rcCli.Height()/2)-4;
			pDC->DrawState(pti,szText,lpsText,DSS_NORMAL,TRUE,0,(HBRUSH)NULL);
			pDC->SelectFont(m_fontOld);
		}
		pDC->SetBkMode(OldMode);
		GetClientRect(&rcCliente);
		if ((rcCliente.right - rcCli.right) != 0)
		{
			CBrush cb;
			cb.CreateSolidBrush(CDrawLayer::GetRGBColorFace());
			rcCliente.left = rcCli.right;
			rcCliente.bottom= rcCliente.top+6;
			cb.DeleteObject();
			//pDC->FillRect(rcCliente,&cb);
		}
		//se dibuja la esquina que permite hacer sizing de la ventana
		CRect rc;
		CRect rc1;
		GetClientRect(&rc);
		rc1=rc;
		rc.left=rc.right-15;
		rc.top=rc.bottom-5;
		DrawGripper(pDC,rc, FALSE);
		rc.left=rc.right-11;
		rc.top=rc.bottom-10;
		DrawGripper(pDC,rc, FALSE);
		rc.left=rc.right-7;
		rc.top=rc.bottom-15;
		DrawGripper(pDC,rc, FALSE);
		
		
		

	}

	void Size()
	{
		SendMessage(WM_SIZE,0L,0);
		CRect rc;
		GetClientRect(rc);
		int width = rc.Width();
		int iSW[10];
		int iCont=GetNumPanels();
		int iAcum=20;
		for (int i=iCont-1; i>-1; i--)
		{
			int val= width-iAcum;
			iSW[i]=val;
			iAcum+=20;
			
		}
		SetIndicators(iSW,iCont);
		
	}

	void DrawGripper(CGDI* dc,CRect rcWin,BOOL bHorz=TRUE)
	{

		if (bHorz)
		{
			
			rcWin.top+=7;
			rcWin.left+=5;
			rcWin.right=rcWin.left+2;
			rcWin.bottom-=4;
			CRect rcBlack;
			CBrush cb;
			for (int i=0; i < rcWin.Height(); i+=4)
			{
				CRect rcWindow;
				cb.CreateSolidBrush(CDrawLayer::GetRGBColorShadow());
				rcWindow=rcWin;
				rcWindow.top=rcWin.top+i;
				rcWindow.bottom=rcWindow.top+2;
				dc->FillRect(rcWindow,&cb);
				rcBlack=rcWindow;
				rcBlack.left-=1;
				rcBlack.top=(rcWin.top+i)-1;
				rcBlack.bottom=rcBlack.top+2;
				rcBlack.right=rcBlack.left+2;
				cb.DeleteObject();
				cb.CreateSolidBrush(::GetSysColor(COLOR_BTNHIGHLIGHT));
				dc->FillRect(rcBlack,&cb);
				cb.DeleteObject();
			}
				cb.DeleteObject();
		
			
		}
		else
		{
			rcWin.top+=3;
			rcWin.left+=4;
			rcWin.right-=2;
			rcWin.bottom=rcWin.top+2;
			CRect rcBlack;
			CBrush cb;
			for (int i=0; i < rcWin.Width(); i+=4)
			{
				CRect rcWindow;
				cb.CreateSolidBrush(CDrawLayer::GetRGBColorShadow());
				rcWindow=rcWin;
				rcWindow.left=rcWindow.left+i;
				rcWindow.right=rcWindow.left+2;
				dc->FillRect(rcWindow,&cb);
				rcBlack=rcWindow;
				rcBlack.top-=1;
				rcBlack.left-=1;
				rcBlack.bottom=rcBlack.top+2;
				rcBlack.right=rcBlack.left+2;
				cb.DeleteObject();
				cb.CreateSolidBrush(::GetSysColor(COLOR_BTNHIGHLIGHT));
				dc->FillRect(rcBlack,&cb);
				cb.DeleteObject();
			}
			cb.DeleteObject();
		}
	}
	

	BEGIN_MSG_MAP()
		ON_WM_PAINT(OnPaint)
	END_MSG_MAP(CStatusCtrl)
};
