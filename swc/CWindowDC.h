#pragma once

#include "stdafx.h"
#include "CGDI.h"

class CWindowDC : public CGDI
{
	HWND m_hWnd;
public:
	CWindowDC(HWND hWnd=NULL)
	{
		if(hWnd == NULL || ::IsWindow(hWnd))
		{
			m_hWnd = hWnd;
			m_hDC = ::GetWindowDC(hWnd);
		}
	}
	

	CWindowDC(CWin* pWin)
	{
		CWindowDC(pWin->GetSafeHwnd());
	}
	

	~CWindowDC()
	{
		if(m_hDC != NULL)
			::ReleaseDC(m_hWnd, m_hDC);
	}
};


