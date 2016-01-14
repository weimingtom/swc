#include "stdafx.h"
#include "CWin.h"
#include "CApp.h"

BOOL CWin::OnDestroy()
{
	if (lpfnOldWndProc !=NULL )
		UnSubClassWnd();
	
	if(GetSafeHwnd() == theApp->GetMainWindows()->GetSafeHwnd())
	{
		
	 	PostQuitMessage(0);
		return TRUE;
	}

	return TRUE;
}
