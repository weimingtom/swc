#pragma once 

#include "stdafx.h"
#include "CDrawLayer.h"

class CBrush
{
	public:
	HBRUSH m_hBrush;
	CBrush(HBRUSH hBrush = NULL) 
	{ 
		m_hBrush=hBrush;
	}
	~CBrush()	{	DeleteObject();	}

	
	HBRUSH GetBrush() { return m_hBrush; }

	HBRUSH GetSafeHandle() { return GetBrush();} //compatibilidad con MFC

	operator HBRUSH() { return GetSafeHandle();}
	BOOL IsValidBrush() {return !(m_hBrush==NULL);}

	CBrush(COLORREF crColor)
	{	
		Attach(::CreateSolidBrush(crColor));
	}
	void Attach(HBRUSH hBrush)
	{
		if(m_hBrush != NULL)
			::DeleteObject(m_hBrush);
		m_hBrush = hBrush;
	}
	
	HBRUSH Detach()
	{
		HBRUSH hBrush = m_hBrush;
		m_hBrush = NULL;
		return hBrush;
	} 
	
	HBRUSH CreateSolidBrush(COLORREF crColor=CDrawLayer::GetRGBColorFace())
	{
		if (IsValidBrush()) return NULL;
		m_hBrush = ::CreateSolidBrush(crColor);
		return m_hBrush;
	}

	HBRUSH CreateHatchBrush(int nIndex=HS_VERTICAL,COLORREF crColor=CDrawLayer::GetRGBColorFace())
	{
		if ( IsValidBrush()) return NULL;
		m_hBrush = ::CreateHatchBrush(nIndex, crColor);
		return m_hBrush;
	}

	HBRUSH CreateBrushIndirect( LOGBRUSH* lpLogBrush)
	{
		if ( IsValidBrush()) return NULL;
		m_hBrush = ::CreateBrushIndirect(lpLogBrush);
		return m_hBrush;
	}

	HBRUSH CreatePatternBrush(HBITMAP hBitmap)
	{
		if ( IsValidBrush()) return NULL;
		m_hBrush = ::CreatePatternBrush(hBitmap);
		return m_hBrush;
	}

	HBRUSH CreateDIBPatternBrush( void* lpPackedDIB, UINT nUsage=DIB_PAL_COLORS)
	{
		if (lpPackedDIB == NULL) return NULL;
		m_hBrush=::CreateDIBPatternBrushPt(lpPackedDIB, nUsage);
		return m_hBrush;
	}
	
	HBRUSH CreateSysColorBrush(int nIndex)
	{
		if (IsValidBrush()) return NULL;
		m_hBrush = ::GetSysColorBrush(nIndex);
		return m_hBrush;
	}

	BOOL DeleteObject()
	{
		if (!IsValidBrush()) return FALSE;
		BOOL bres = ::DeleteObject(m_hBrush);
		if(bres)
			m_hBrush = NULL;
		return bres;
	}

	int GetLogBrush(LOGBRUSH* pLogBrush) 
	{
		if (! IsValidBrush()) return 0;
		return ::GetObject(m_hBrush, sizeof(LOGBRUSH), pLogBrush);
	}
	
};

