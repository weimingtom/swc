#pragma once

#include "stdafx.h"

class CPen
{
	
public:
	HPEN m_hPen;	
	CPen(HPEN hPen=NULL)	{ m_hPen=hPen;}

	~CPen()
	{
		DeleteObject();
	}

	BOOL IsValidPen() {return !(m_hPen==NULL);}
	
	HPEN GetPen() { if (! IsValidPen()) return NULL; return m_hPen;}
	
	HPEN CreatePen(int fnPenStyle=PS_SOLID,int nWidth=1,COLORREF clColor=RGB(0,0,0))
	{
		if (IsValidPen()) return NULL;
		m_hPen=::CreatePen(fnPenStyle,nWidth,clColor);
		return m_hPen;
	}

	HPEN ExtCreatePen( LOGBRUSH* lplb, int fnPenStyle=PS_SOLID,int nWidth=1, int dwStyleCount=0,  DWORD* lpStyle=NULL )
	{
		if (IsValidPen()) return NULL;
		m_hPen=::ExtCreatePen(fnPenStyle,nWidth,lplb,dwStyleCount,lpStyle);
		return m_hPen;
	}


	HPEN CreatePenIndirect( LOGPEN* lplgpen)
	{
		if (IsValidPen()) return NULL;
		m_hPen=::CreatePenIndirect(lplgpen);
		return m_hPen;
	}

	BOOL DeleteObject()
	{
		if (! IsValidPen()) return FALSE;
		BOOL brs = ::DeleteObject((HPEN)m_hPen);
		if(brs)	m_hPen = NULL;
		return brs;
	}


	int GetLogPen(LOGPEN* pLogPen) 
	{
		if (!IsValidPen()) return FALSE;
		return ::GetObject(m_hPen, sizeof(LOGPEN), pLogPen);
	}

	int GetExtLogPen(EXTLOGPEN* pLogPen) 
	{
		if (!IsValidPen()) return FALSE;
		return ::GetObject(m_hPen, sizeof(EXTLOGPEN), pLogPen);
	}


};

