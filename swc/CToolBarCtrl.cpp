#include "stdafx.h"
#include "CToolBarCtrl.h"
#include "CRect.h"
#include "CComboBoxExt.h"

BOOL CToolBarCtrl::CreateCombo(CComboBoxExt* pControl,UINT nID,int iSize,DWORD dwStyle)
{
	CRect rect;
	int nIndex = CommandToIndex(nID);
    TBBUTTON button;
	GetButton(nIndex, &button);
	UINT Style= MAKELONG(TBSTYLE_SEP, 0);
	button.idCommand = nID;
	button.iBitmap = iSize;
	button.fsStyle = (BYTE)LOWORD(Style);
	button.fsState = (BYTE)HIWORD(Style);
	InsertButton(nIndex, &button);
	GetItemRect(nIndex, &rect);
	rect.top = 1;
	rect.bottom = rect.top + 250 /*drop height*/;
	if(!pControl->Create(GetSafeHwnd(),nID,0,dwStyle, rect))
	{
		return FALSE;
	}
	//pControl->SetImageList(m_imgList);
	return TRUE;
	
}
