#pragma once

#include "stdafx.h"
#include "CToolBarCtrl.h"
#include "CRect.h"
#include "CImageCtrl.h"
#include "CSize.h"


class CButtonInfo : public TBBUTTONINFO
{
	int iButton;
	CToolBarCtrl* pTb;
	TCHAR szText[64];
	public:
		CButtonInfo(CToolBarCtrl* pToolbar,  int NumButton)
		{
			ASSERT(pTb->GetSafeHwnd());
			pTb=pToolbar;
			iButton=NumButton;
			memset(this,0x00,sizeof(TBBUTTONINFO));	   
			cbSize = sizeof(TBBUTTONINFO);
			dwMask = TBIF_TEXT | TBIF_STYLE | TBIF_STATE | TBIF_IMAGE;
			pszText = szText;
			cchText = (sizeof(szText) / sizeof(TCHAR)) - 1;
			pTb->GetButtonInfo(iButton, this);
			
	      	}
		~CButtonInfo()
		{

		}
	public:	
		BOOL IsChecked(){ return (fsState & TBSTATE_CHECKED) != 0;}
		BOOL IsPressed(){ return (fsState & TBSTATE_PRESSED )!= 0;}
		BOOL IsEnabled(){ return (fsState & TBSTATE_ENABLED)!= 0;}
		BOOL IsHidden() {return (fsState & TBSTATE_HIDDEN)!= 0;}
		BOOL IsWrap() { return (fsState & TBSTATE_WRAP)!= 0;}
		BOOL IsEllipses() { return (fsState & TBSTATE_ELLIPSES)!= 0;}
		BOOL IsMarked() { return (fsState & TBSTATE_MARKED)!= 0;}
		BOOL IsIndeterminate() { return (fsState & TBSTATE_INDETERMINATE)!= 0;}
		
		BOOL IsStyleFlat() { return (  fsStyle & TBSTYLE_FLAT)!= 0;}
		BOOL IsStyleList() { return (fsStyle & TBSTYLE_LIST )!= 0; }
		BOOL IsSeparator() {return (fsStyle & TBSTYLE_SEP )!= 0;}
		BOOL IsStyleCheck() {return (fsStyle & TBSTYLE_CHECK )!= 0;}
		BOOL IsStyleDropDown(){ return (fsStyle & TBSTYLE_DROPDOWN)!= 0;}
		BOOL IsImage() {return (BOOL)(iImage >= 0)!= 0; }
		
		LPCTSTR GetText()
		{
			if( ::lstrlen(szText) == 0 ) 
			     pTb->GetButtonText(iButton, szText);
			return (LPCTSTR)szText;
			
		}

		int GetID()
		{
			return idCommand;
		}
	
		int GetIndexImage()
		{
			return iImage;
		}
		CRect GetRect()
		{ 
			CRect rcBtn;
			pTb->GetItemRect(iButton,&rcBtn);
			return rcBtn;
		}
		
		CImageCtrl GetImageList()
		{
			return pTb->GetImageList();
		}	
		
		CSize GetButtonSize()
		{
			SIZE sz;
			pTb->GetButtonSize(sz);
			return sz ;
		}
		
};
