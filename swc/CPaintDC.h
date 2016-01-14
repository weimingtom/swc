#pragma once

#include "stdafx.h"
#include "CGDI.h"

class CPaintDC : public CGDI
{
	HWND m_hWnd;
	PAINTSTRUCT m_ps;
public:

	CPaintDC(HWND hWnd=NULL)
	{
		if(hWnd == NULL || ::IsWindow(hWnd))
		{
			m_hWnd = hWnd;
			m_hDC = ::BeginPaint(hWnd, &m_ps);
		}
	}
	
	CPaintDC(CWin* pWin)
	{
		m_hWnd=pWin->GetSafeHwnd();
		if(m_hWnd == NULL || ::IsWindow(m_hWnd))
			m_hDC = ::BeginPaint(m_hWnd, &m_ps);

	}
	
	~CPaintDC()
	{
		if (m_hDC != NULL && ::IsWindow(m_hWnd))
			::EndPaint(m_hWnd, &m_ps);
		
	}
};

