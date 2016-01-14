#include "stdafx.h"
#include "CControlBarButton.h"
#include "CBrush.h"
#include "CBitmap.h"

//FIXME:
#define NORMALBTN   1
#define OVERBTN     1
#define PRESSBTN    2

CControlBarButton::CControlBarButton()
{
	bTypeButton=(Type)NORMAL;
	m_bEnabled=TRUE;
}


CControlBarButton::~CControlBarButton()
{

}

void CControlBarButton::SetTypeButton(Type bTypeb)
{
	bTypeButton=bTypeb;
}


void CControlBarButton::SetEnabled(BOOL bEnabled)
{
	m_bEnabled=bEnabled;
}

void CControlBarButton::Paint(CGDI* pDC,int st,CRect rc,COLORREF clrFondo,BOOL isBackDark)
{
	CBrush cb;
	if(bTypeButton==NORMAL) 
		cb.CreateSolidBrush(clrFondo);
	else
	{
		if (m_bEnabled)
			if (st == OVERBTN)
				cb.CreateSolidBrush(CDrawLayer::GetRGBFondoXP());
			else if(st == PRESSBTN)
				cb.CreateSolidBrush(CDrawLayer::GetRGBPressBXP());
			else
				cb.CreateSolidBrush(clrFondo);
	}

	if (m_bEnabled)
	{
		pDC->FillRect(rc,&cb);
		if (st == OVERBTN)
			pDC->Draw3dRect(rc,bTypeButton==NORMAL?::GetSysColor(COLOR_BTNSHADOW):CDrawLayer::GetRGBCaptionXP(),
							   bTypeButton==NORMAL?::GetSysColor(COLOR_BTNSHADOW):CDrawLayer::GetRGBCaptionXP());
		if (st == PRESSBTN)
			pDC->Draw3dRect(rc,bTypeButton==NORMAL?::GetSysColor(COLOR_BTNHIGHLIGHT):CDrawLayer::GetRGBCaptionXP(),
			bTypeButton==NORMAL?::GetSysColor(COLOR_BTNHIGHLIGHT):CDrawLayer::GetRGBCaptionXP());
	}
	if(bTypeButton==NORMAL) 
		m_imgList.Draw(isBackDark? m_nIcon+1:m_nIcon, pDC->m_hDC,
						CPoint(rc.left+1,rc.top+2), ILD_TRANSPARENT);				
	else
	{
		HICON m_Icon=m_imgList.ExtractIcon(!isBackDark?m_nIcon:m_nIcon+1);
		//if (m_bEnabled)
		IMAGEINFO* pImageInfo = new IMAGEINFO;
		m_imgList.GetImageInfo(m_nIcon,pImageInfo);
		CRect rcbt=pImageInfo->rcImage;
		int difh= rc.Height()-rcbt.Height();
		int difw= rc.Width()-rcbt.Width();
		if (difh< 0) difh=0;
		if (difw< 0) difw=1;
		difh/=2;
		difw/=2;
		m_imgList.Draw(m_nIcon, pDC->m_hDC,CPoint(rc.left+1+difw,bTypeButton==NORMAL?rc.top+difh+1:rc.top+difh+1),m_bEnabled?ILD_TRANSPARENT:ILD_BLEND25);				
		delete pImageInfo;
		DestroyIcon (m_Icon);

	}
	cb.DeleteObject();
}

void CControlBarButton::SetData(int nIcon,LPCTSTR lpMsg)
{
	m_nIcon=nIcon;
	m_lpMsg=lpMsg;
}

void  CControlBarButton::SetImageList(UINT nBitmapID, int cx, int nGrow, COLORREF crMask)
{
	CBitmap cbmp;
	BITMAP bmp;
	m_imgList.Create(nBitmapID,cx,nGrow,crMask);
	cbmp.LoadBitmap(theApp->GetInstance(),(LPCTSTR)nBitmapID);
	cbmp.GetBitmap(&bmp);
	m_imgList.Add(&cbmp,crMask);
	cbmp.DeleteObject();

}
