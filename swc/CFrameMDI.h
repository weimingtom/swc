#pragma once

#include "stdafx.h"
#include "CFrame.h"

class CFrameMDI : public CFrame
{

protected:
	CLIENTCREATESTRUCT ccs;
public:

	CFrameMDI(HWND hWnd) : CFrame(hWnd)
	{
		hMDIClient=NULL;
	}
	
	~CFrameMDI()
	{
	
	};

	virtual BOOL LoadFrame(UINT uID,DWORD dwStyle=WS_OVERLAPPEDWINDOW,HWND hParentWnd=NULL);
	HWND MDIGetActive(BOOL* pbMaximized);
	void MDIActivate(HWND hWndActivate,LPARAM lParam);
	void MDIIconArrange();
	void MDIMaximize(HWND hWndParent);
	void MDINext();
	void MDIRestore(HWND hWndParent);
	HMENU MDISetMenu(HMENU hMenuParent, HMENU hMenuWindow);
	void MDITile();
	void MDICascade();
	void MDICascade(int nType);
	void MDITile(int nType);
	virtual  LRESULT DefWindowProc(HWND hWnd, UINT uID, WPARAM wParam, LPARAM lParam);
	BOOL OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL WindowsPosChanged(LPWINDOWPOS lpWindowsPos);
	void OnCloseChild();
	
BEGIN_MSG_MAP()
	 ON_WM_WINDOWPOSCHANGED (WindowsPosChanged)
	 ON_WM_CREATE(OnCreate)
	 ON_WM_MDIMAXIMIZE(MDIMaximize)
END_MSG_MAP(CFrame)

 
};
