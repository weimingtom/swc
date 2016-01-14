#pragma once 
#include "stdafx.h"

class CFont
{
public:
	HFONT m_hFont;

	CFont(HFONT hFont = NULL) 
	{  m_hFont=hFont;}

	~CFont()
	{
		if(m_hFont != NULL && !::DeleteObject(m_hFont))
			m_hFont = NULL;
	}

public:
	
	operator HFONT() {return m_hFont;}  

	HFONT  GetFont(){ return m_hFont;}
	
	void Attach(HFONT hFont)
	{
		if( m_hFont != NULL)
			::DeleteObject(m_hFont);
		m_hFont = hFont;
	}
	
	HFONT Detach()
	{
		HFONT hFont = m_hFont;
		m_hFont = NULL;
		return hFont;
	}

	void DeleteObject()
	{
		if( m_hFont != NULL)
			::DeleteObject(m_hFont);
	}
	
	HFONT CreateFontIndirect(const LOGFONT* lpLogFont)
	{
		ASSERT(m_hFont == NULL);
		m_hFont = ::CreateFontIndirect(lpLogFont);
		return m_hFont;
	}


	HFONT CreateFont(int nHeight, int nWidth, int nEscapement,
			int nOrientation, int nWeight, BYTE bItalic, BYTE bUnderline,
			BYTE cStrikeOut, BYTE nCharSet, BYTE nOutPrecision,
			BYTE nClipPrecision, BYTE nQuality, BYTE nPitchAndFamily,
			LPCTSTR lpszFacename)
	{
		ASSERT(m_hFont == NULL);
		m_hFont = ::CreateFont(nHeight, nWidth, nEscapement,
			nOrientation, nWeight, bItalic, bUnderline, cStrikeOut,
			nCharSet, nOutPrecision, nClipPrecision, nQuality,
			nPitchAndFamily, lpszFacename);
		return m_hFont;
	}
	
	
	BOOL GetStockFont( int nStockFont )
	{
	
		HFONT hFont = ( HFONT )::GetStockObject( nStockFont );
		if ( !hFont) 	return FALSE;
		Attach( hFont );
		return TRUE;
	}


	int GetLogFont(LOGFONT* pLogFont) 
	{
		ASSERT(m_hFont != NULL);
		return ::GetObject(m_hFont, sizeof(LOGFONT), pLogFont);
	}
	
	bool GetLogFont(LOGFONT& LogFont) 
	{
		ASSERT(m_hFont != NULL);
		return (::GetObject(m_hFont, sizeof(LOGFONT), &LogFont) == sizeof(LOGFONT));
	}
};

