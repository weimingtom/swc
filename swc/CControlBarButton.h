#pragma once

#include "stdafx.h"
#include "CImageCtrl.h"
#include "CToolTipCtrl.h"
#include "CGDI.h"

class  CControlBarButton 
{
public:
	enum Type
	{
		NORMAL    = 0,
		TOOLBUTTON
	};
	
	CRect rcArea;
protected:
	
	int m_nIcon;
	LPCTSTR m_lpMsg;
	CImageCtrl m_imgList;
	Type bTypeButton;
	BOOL m_bEnabled;
	CToolTipCtrl   m_toolTip;
	
public:
	
	CControlBarButton();
	void SetData(int nIcon, LPCTSTR lpMsg);
	~CControlBarButton();
	void Paint(CGDI* pDC, int st, CRect rc, COLORREF clrFondo,BOOL isBackDark=FALSE);
	void SetImageList(UINT nBitmapID, int cx, int nGrow, COLORREF crMask);
	void SetTypeButton(Type bTypeb = NORMAL);
	void SetEnabled(BOOL bEnabled);
};
