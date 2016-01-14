#pragma once

#include "stdafx.h"
#include "CGDI.h"

class CClientDC : public CGDI
{
	HWND m_hWnd;
public:

	CClientDC(HWND hWnd)
	{
		if(hWnd == NULL || ::IsWindow(hWnd))
		{
			m_hWnd = hWnd;
			m_hDC = ::GetDC(hWnd);
		}
	}

	CClientDC(CWin* pWin)
	{
		m_hWnd = pWin->GetSafeHwnd();
		m_hDC = ::GetDC(m_hWnd);
	}
	
	~CClientDC()
	{
		if(m_hDC != NULL)
			::ReleaseDC(m_hWnd, m_hDC);
	}
};
