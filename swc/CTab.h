#pragma once

#include "stdafx.h"
#include "CWin.h"

class CTab 
{
public:
	CTab(CWin* mpParent, LPCSTR lpMsgs=NULL, UINT uHmenu=0)
	{
		pParent	= mpParent;
		if (lpMsgs== NULL)
			GetWindowText(pParent->GetSafeHwnd(),lpMsg,128);
		else
			strcpy(lpMsg,lpMsgs);
		nMenu=uHmenu;

	}

	~CTab()
	{
	
	}

	
	
public:
	CWin*	pParent;
	TCHAR	lpMsg[128];
	CRect	rect;
	UINT	nMenu;
	
};

