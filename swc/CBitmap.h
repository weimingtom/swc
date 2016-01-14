#pragma once

#include "stdafx.h"
#include "CSize.h"

class CBitmap
{
	
public:

	HBITMAP m_hBitmap;
	CBitmap(HBITMAP hBitmap = NULL) { m_hBitmap=hBitmap;}

	~CBitmap() { DeleteObject();}

	BOOL IsValidBitmap() { return !(m_hBitmap== NULL);}

	HBITMAP GetBitMap() { if (IsValidBitmap()) return m_hBitmap; return NULL;}
	
	HBITMAP GetSafeHandle() { if (IsValidBitmap()) return m_hBitmap; return NULL;}
	HBITMAP LoadBitmap(HINSTANCE hInsTance,LPCTSTR lpBitmapName)
	{
		if (IsValidBitmap()) return NULL;
		m_hBitmap = ::LoadBitmap(hInsTance,lpBitmapName);
		return m_hBitmap;
	}
	
	HBITMAP LoadOEMBitmap(UINT nIDBitmap) 
	{
		if (IsValidBitmap()) return NULL;
		m_hBitmap = ::LoadBitmap(NULL, MAKEINTRESOURCE(nIDBitmap));
		return m_hBitmap;
	}

	HBITMAP CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitcount,  void* lpBits)
	{
		if (IsValidBitmap()) return NULL;
		m_hBitmap = ::CreateBitmap(nWidth, nHeight, nPlanes, nBitcount, lpBits);
		return m_hBitmap;
	}
	
	BOOL DeleteObject()
	{
		if (!IsValidBitmap()) return FALSE;
		BOOL bres = ::DeleteObject(m_hBitmap);
		if(bres)
			m_hBitmap = NULL;
		return bres;
	}

	int GetBitmap(BITMAP* pBitMap) 
	{
		if (!IsValidBitmap()) return FALSE;
		return ::GetObject(m_hBitmap, sizeof(BITMAP), pBitMap);
	}

	BOOL GetBitmap(BITMAP& bm) 
	{
		if (!IsValidBitmap()) return FALSE;
		return (::GetObject(m_hBitmap, sizeof(BITMAP), &bm) == sizeof(BITMAP));
	}

	BOOL GetSize(SIZE& size) 
	{
		if (!IsValidBitmap()) return FALSE;
		BITMAP bm;
		if(!GetBitmap(&bm))
			return false;
		size.cx = bm.bmWidth;
		size.cy = bm.bmHeight;
		return true;
	}

	CSize GetSize() 
	{
		if (!IsValidBitmap()) return CSize(0,0);
		BITMAP bm;
		if(!GetBitmap(&bm))
			return CSize(0,0);
		return CSize(bm.bmWidth,bm.bmHeight);
	}


	DWORD GetBitmapBits(DWORD dwCount, LPVOID lpBits) 
	{
		if (!IsValidBitmap()) return 0;
		return ::GetBitmapBits(m_hBitmap, dwCount, lpBits);
	}
	DWORD SetBitmapBits(DWORD dwCount,  void* lpBits)
	{
		if (!IsValidBitmap()) return 0;
		return ::SetBitmapBits(m_hBitmap, dwCount, lpBits);
	}
	BOOL GetBitmapDimension(LPSIZE lpSize) 
	{
		if (!IsValidBitmap()) return FALSE;
		return ::GetBitmapDimensionEx(m_hBitmap, lpSize);
	}
	BOOL SetBitmapDimension(int nWidth, int nHeight, LPSIZE lpSize = NULL)
	{
		if (!IsValidBitmap()) return FALSE;
		return ::SetBitmapDimensionEx(m_hBitmap, nWidth, nHeight, lpSize);
	}

	HBITMAP CreateBitmapIndirect(LPBITMAP lpBitmap)
	{
		if (IsValidBitmap()) return NULL;
		m_hBitmap = ::CreateBitmapIndirect(lpBitmap);
		return m_hBitmap;
	}
	HBITMAP CreateCompatibleBitmap(HDC hDC, int nWidth, int nHeight)
	{
		if (IsValidBitmap()) return NULL;
		m_hBitmap = ::CreateCompatibleBitmap(hDC, nWidth, nHeight);
		return m_hBitmap;
	}
	HBITMAP CreateDiscardableBitmap(HDC hDC, int nWidth, int nHeight)
	{
		if (IsValidBitmap()) return NULL;
		m_hBitmap = ::CreateDiscardableBitmap(hDC, nWidth, nHeight);
		return m_hBitmap;
	}


	HBITMAP CreateDIBitmap(HDC hDC,  BITMAPINFOHEADER* lpbmih, DWORD dwInit,  VOID* lpbInit,  BITMAPINFO* lpbmi, UINT uColorUse)
	{
		if (IsValidBitmap()) return NULL;
		m_hBitmap = ::CreateDIBitmap(hDC, lpbmih, dwInit, lpbInit, lpbmi, uColorUse);
		return m_hBitmap;
	}
	HBITMAP CreateDIBSection(HDC hDC,  BITMAPINFO* lpbmi, UINT uColorUse, VOID** ppvBits, HANDLE hSection, DWORD dwOffset)
	{
		if (IsValidBitmap()) return NULL;
		m_hBitmap = ::CreateDIBSection(hDC, lpbmi, uColorUse, ppvBits, hSection, dwOffset);
		return m_hBitmap;
	}
	int GetDIBits(HDC hDC, UINT uStartScan, UINT cScanLines,  LPVOID lpvBits, LPBITMAPINFO lpbmi, UINT uColorUse) 
	{
		if (!IsValidBitmap()) return 0;
		return ::GetDIBits(hDC, m_hBitmap, uStartScan, cScanLines,  lpvBits, lpbmi, uColorUse);
	}
	int SetDIBits(HDC hDC, UINT uStartScan, UINT cScanLines,  VOID* lpvBits,  BITMAPINFO* lpbmi, UINT uColorUse)
	{
		if (!IsValidBitmap()) return 0;
		return ::SetDIBits(hDC, m_hBitmap, uStartScan, cScanLines, lpvBits, lpbmi, uColorUse);
	}

};
