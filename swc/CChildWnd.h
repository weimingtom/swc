#pragma once

#include "stdafx.h"
#include "CFrame.h"

class CChildWnd : public CFrame
{
	HMENU hMenu;
public:
	CChildWnd(HWND hWnd=NULL): CFrame(hWnd)
	{bChildWnd=TRUE;}
	virtual BOOL LoadFrame(UINT uID,HWND hParentWnd=NULL,DWORD dwStyle=WS_VISIBLE|WS_CHILD|WS_OVERLAPPEDWINDOW);
	virtual  LRESULT DefWindowProc(HWND hWnd, UINT uID, WPARAM wParam, LPARAM lParam);
	void MDIActivate(HWND hWndActivate,LPARAM lParam);
	void MDIMaximize(HWND hWndActivate);
BEGIN_MSG_MAP()
  ON_WM_MDIACTIVATE(MDIActivate)
  ON_WM_MDIMAXIMIZE(MDIMaximize)	
END_MSG_MAP(CFrame)

};
