#pragma once

#include "stdafx.h"
#include "CToolBarCtrl.h"
#include "CFont.h"
#include "CGDI.h"
#include "CRect.h"
#include "CBrush.h"
#include "CButtonInfo.h"
#include "CGradient.h"

class CToolBarCtrlEx : public CToolBarCtrl
{
	CFont m_cfont;
public:
	
	  CToolBarCtrlEx()
	  {
		//m_cfont.CreateFont(14,0,0,0,400,0,0,0,0,1,2,1,34,_T("Arial"));	
	  }
	
	  ~CToolBarCtrlEx(){}

public:
	  void DrawButton(LPNMTBCUSTOMDRAW lpNMCustomDraw)
	  {
	      CBrush cb;
		  CGDI dc(lpNMCustomDraw->nmcd.hdc);
		  cb.CreateSolidBrush(CDrawLayer::GetRGBColorFace());
	      CButtonInfo cbt(this,lpNMCustomDraw->nmcd.dwItemSpec);
		  UINT uItemState = lpNMCustomDraw->nmcd.uItemState;
		  bool bSelected = (uItemState & CDIS_SELECTED || uItemState & CDIS_HOT || uItemState &CDIS_CHECKED) != 0;
		  #if (_WIN32_IE >= 0x0400)
			CRect rcBtn = lpNMCustomDraw->nmcd.rc;
		  #else //!(_WIN32_IE >= 0x0400)
			CRect rcBtn;
			GetItemRect(0, rcBtn);
		  #endif //!(_WIN32_IE >= 0x0400)
	      BOOL Over=FALSE;
	      if (bSelected)
		  if (cbt.IsSeparator() )
		  {
				if (!cbt.IsWrap())
				{
					CRect m_Separ;
					m_Separ=rcBtn;
					
					int nhalf=(m_Separ.Width()/2)-1;
					m_Separ.top-=1;
					m_Separ.left+=nhalf;
					m_Separ.right=m_Separ.left+1;
					m_Separ.bottom+=1;
					CBrush cbs;
					cbs.CreateSolidBrush(RGB(167, 167, 167));
					if (!(cbt.IsSeparator()  &&(cbt.GetID() !=0)))
						dc.FillRect(m_Separ,&cbs);
					cbs.DeleteObject();
				
				}
		  }
		  else if(cbt.IsEnabled())
		  {
			CPoint pt;
			GetCursorPos(&pt);
			ScreenToClient(&pt);
			CBrush cblu;
			if(!rcBtn.PtInRect(pt))
			{
				if (cbt.IsChecked())
				{
					dc.Draw3dRect(rcBtn,CDrawLayer::GetRGBMenu(),CDrawLayer::GetRGBMenu());
					rcBtn.DeflateRect(1,1);
					cblu.CreateSolidBrush(CDrawLayer::GetRGBFondoXP());
					dc.FillRect(rcBtn,&cblu);					
				}
				
			}
			else
			{
				Over=TRUE;
				dc.Draw3dRect(rcBtn,CDrawLayer::GetRGBMenu(),CDrawLayer::GetRGBMenu());
				rcBtn.DeflateRect(1,1);
				if (cbt.IsChecked())
				{
					cblu.CreateSolidBrush(CDrawLayer::GetRGBFondoXP());
					dc.FillRect(rcBtn,&cblu);					
				}
				else
				{
					
					if (cbt.IsPressed())
					{
						cblu.CreateSolidBrush(CDrawLayer::GetRGBPressBXP());
						dc.FillRect(rcBtn,&cblu);
					}
					else
					{
						cblu.CreateSolidBrush(cbt.IsPressed()?CDrawLayer::GetRGBPressBXP():CDrawLayer::GetRGBFondoXP());
						dc.FillRect(rcBtn,&cblu);					
					}
					if (cbt.IsStyleDropDown()) 
					{
						
						CRect rcCli=rcBtn;
						int dif=rcBtn.right-8;
						rcCli.left=dif+1;
						
						if (!cbt.IsPressed())
						{
							CPen Cp;
							Cp.CreatePen( PS_SOLID, 1, CDrawLayer::GetRGBCaptionXP());
							CPen oldPen= dc.SelectObject(&Cp);
							dc.MoveTo(dif,rcBtn.top);
							dc.LineTo(dif,rcBtn.bottom);
							dc.SelectObject(&oldPen);
							Cp.DeleteObject();
						}
						
					}
					
				}
					rcBtn.InflateRect(1,1);
			}
			cblu.DeleteObject();
		}

	  
		if (!cbt.IsSeparator())
		{
	
			
				HIMAGELIST hiImg = (HIMAGELIST)SendMessage (TB_GETIMAGELIST, 0, 0);
				HICON hIcon = ImageList_ExtractIcon (theApp->GetInstance(), hiImg,cbt.GetIndexImage());
				int cxIcon, cyIcon;
				ImageList_GetIconSize(hiImg, &cxIcon, &cyIcon);
				CSize sizeButton( cbt.GetButtonSize());
				CSize siImg=CSize(cxIcon,cyIcon);
				CPoint pti(rcBtn.left+4,rcBtn.top+4);
				LPSTR mszText= (LPSTR)cbt.GetText();
				//HFONT m_fontOld=dc.SelectFont(m_cfont);
				CBrush cbShadow;
				cbShadow.CreateSolidBrush(CDrawLayer::GetRGBColorShadow());
								
				if (cbt.IsEnabled())
				{
					if (cImgCtrl.GetImageHandle())
						cImgCtrl.Draw(cbt.GetIndexImage(),dc,pti,ILD_NORMAL);
					else
						ImageList_Draw(hiImg,cbt.GetIndexImage(),dc,pti.x,pti.y,ILD_NORMAL);
					if (lstrlen(mszText) > 0)
					{
						
						CRect m_rctext=rcBtn;
						m_rctext.left+=siImg.cx+4;
						m_rctext.bottom-=1;
						CSize szText=dc.GetTextExtent(mszText,lstrlen(mszText));
						pti.x= m_rctext.left+8;
						pti.y=(m_rctext.Height()/2)-4;
						dc.DrawState(pti,szText,mszText,DSS_MONO,TRUE,0,(HBRUSH)NULL);
					}
					
					
					
				}
				else
				{
					
					 dc.DrawState(pti,siImg,hIcon,DSS_MONO,&cbShadow);
					 CRect m_rctext=rcBtn;
					 m_rctext.left+=siImg.cx+4;
					 m_rctext.bottom-=1;
					 CSize szText=dc.GetTextExtent(mszText,lstrlen(mszText));
					 pti.x= m_rctext.left+2;
					 pti.y=(m_rctext.Height()/2)-1;
					 dc.DrawState(pti,szText,mszText,DSS_DISABLED,TRUE,0,(HBRUSH)NULL);
				}
				DestroyIcon (hIcon);
				cbShadow.DeleteObject();
			
		}

	
		




	 }

	/*void DrawArrow(CGDI* pDC,CRect m_rc)
	{
		int difh =m_rc.Height()-mHeight.y;
		difh/=2;
		
		m_rc.left=m_rc.right-GetDropDownWidth();
		m_imgArrow.Draw(pDC,0,CPoint(m_rc.left+2,m_rc.top+difh),ILD_TRANSPARENT);		
		
	}*/
	
	DWORD OnPrePaint(LPNMCUSTOMDRAW lpNMCustomDraw,BOOL &bNotify)
	 {
	      CGDI dc(lpNMCustomDraw->hdc);
	      CRect rc=lpNMCustomDraw->rc;
		  SIZE lpSize;
		  ::SendMessage( GetSafeHwnd(),TB_GETMAXSIZE, 0L,(LPARAM) &lpSize);
		  CRect rc1=rc;  	
		  /*if (rc1.Width() > lpSize.cx)
		  {
				rc1.left= (rc1.right- (rc1.Width() - lpSize.cx))+5;
				rc.right=rc1.left;	
		  }*/
			CGradient M(CSize(rc.Width(),rc.Height()));	
			M.PrepareVertical(&dc);
			M.Draw(&dc,0,0,0,0,rc.Width(),rc.Height(),SRCCOPY);
			
		  return CDRF_NOTIFYITEMDRAW;  
	 }
	
	
	 DWORD OnItemPrePaint(LPNMCUSTOMDRAW lpNMCustomDraw,BOOL &bNotify)
	 {
	     
	      DrawButton((LPNMTBCUSTOMDRAW) lpNMCustomDraw );
	      return CDRF_SKIPDEFAULT;
	 }


	 
	

};

