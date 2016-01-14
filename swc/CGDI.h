#pragma once 
#include "stdafx.h"
#include "CPen.h"
#include "CBrush.h"
#include "CFont.h"
#include "CBitmap.h"

class CGDI 
{
public:
	HDC m_hDC;
public:
	
	CGDI(HDC hDC=NULL)
	{ 
		m_hDC=hDC;
	}

	/*~CGDI()
	{
		if (m_hDC != NULL)
			::DeleteDC(m_hDC);
	}*/
		
	BOOL IsValidHandle() {return m_hDC != NULL;}
	//---------------------------------------------------------------------
	int SaveDC()
	{
		if (IsValidHandle())
			return ::SaveDC(m_hDC);
		return 0;
	}

	operator HDC() {return m_hDC;}
	BOOL RestoreDC(int nSavedDC)
	{
		if (IsValidHandle())
			return ::RestoreDC(m_hDC, nSavedDC);
		return 0;
	}

	int GetDeviceCaps(int nIndex) 
	{
		if (IsValidHandle())
			return ::GetDeviceCaps(m_hDC, nIndex);
		return 0;
	}

	COLORREF GetNearestColor(COLORREF crColor) 
	{ 
		if (IsValidHandle())
			return ::GetNearestColor(m_hDC, crColor); 
		else
			return 0;
	}


	UINT SetBoundsRect(LPCRECT lpRectBounds, UINT flags)
	{
		if (IsValidHandle())
			return ::SetBoundsRect(m_hDC, lpRectBounds, flags);
		return 0;
	}
	UINT GetBoundsRect(LPRECT lpRectBounds, UINT flags) 
	{
		if (IsValidHandle())
			return ::GetBoundsRect(m_hDC, lpRectBounds, flags);
		return 0;
	}
	BOOL ResetDC( DEVMODE* lpDevMode)
	{
		if (IsValidHandle())
			if(::ResetDC(m_hDC, lpDevMode)) return TRUE;
		return 0;
	}

	
	HFONT SelectFont(HFONT hFont)
	{

		return ((HFONT)::SelectObject((m_hDC), (HGDIOBJ)(HFONT)(hFont)));
	}




	HFONT SelectObject(CFont cf)
	{
		if (IsValidHandle())
			return (HFONT) ::SelectObject(m_hDC,(HFONT)cf.GetFont());
		return NULL;
	}
	//---------------------------------------------------------------------
	HPEN SelectObject(CPen* cp)
	{
		if (IsValidHandle())
			return (HPEN) ::SelectObject(m_hDC,(HPEN)cp->GetPen());
		return NULL;
	}

	HBRUSH SelectObject(CBrush* cb)
	{
		if (IsValidHandle())
			return (HBRUSH) ::SelectObject(m_hDC,(HBRUSH)cb->GetBrush());
		return NULL;
	}
	//--------------------------------------------------------------------
	HBITMAP SelectObject(CBitmap* cb)
	{
		if (IsValidHandle())
			return (HBITMAP) ::SelectObject(m_hDC,(HBITMAP)cb->GetBitMap());
		return NULL;
	}

	//---------------------------------------------------------------------


	HGDIOBJ SelectStockObject(int fnObjec)
	{
		if (IsValidHandle())
			return ::SelectObject(m_hDC,GetStockObject(fnObjec));
		return NULL;
	}

	HWND WindowFromDC() 
	{
		if (IsValidHandle())
			return ::WindowFromDC(m_hDC);
		return NULL;
	}

	CPen GetCurrentPen() 
	{
		if (IsValidHandle())
			return CPen((HPEN)::GetCurrentObject(m_hDC, OBJ_PEN));
		return CPen(NULL);

	}
	CBrush GetCurrentBrush() 
	{
		if (IsValidHandle())
			return CBrush((HBRUSH)::GetCurrentObject(m_hDC, OBJ_BRUSH));
		return CBrush();
	}
	/*CPalette GetCurrentPalette() 
	{
		if (IsValidHandle())
		return CPaletteHandle((HPALETTE)::GetCurrentObject(m_hDC, OBJ_PAL));
	}
	CFont GetCurrentFont() 
	{
		if (IsValidHandle())
		return CFontHandle((HFONT)::GetCurrentObject(m_hDC, OBJ_FONT));
	}*/
	CBitmap GetCurrentBitmap() 
	{
		if (IsValidHandle())
			return CBitmap((HBITMAP)::GetCurrentObject(m_hDC, OBJ_BITMAP));
		return CBitmap();
	}

	HDC CreateDC(LPCTSTR lpszDriverName, LPCTSTR lpszDeviceName, LPCTSTR lpszOutput,  DEVMODE* lpInitData)
	{
		if (IsValidHandle()) return m_hDC;
		m_hDC = ::CreateDC(lpszDriverName, lpszDeviceName, lpszOutput, lpInitData);
		return m_hDC;
	}

	HDC CreateCompatibleDC(HDC hDC = NULL)
	{
		if (IsValidHandle()) return m_hDC;
			m_hDC = ::CreateCompatibleDC(hDC);
		return m_hDC;
	}

	BOOL DeleteDC()
	{
		if (!IsValidHandle()) return FALSE;
		BOOL bres = ::DeleteDC(m_hDC);
		if(bres)
			m_hDC = NULL;
		return bres;
	}

	//--------------------------------------------------------------------------------
	
	
	COLORREF GetBkColor()
	{
		if (IsValidHandle())
			return ::GetBkColor(m_hDC);
		return RGB(0,0,0);
	}
	int GetBkMode() 
	{
		if (IsValidHandle())
			return ::GetBkMode(m_hDC);
		return 0;

	}
	int GetPolyFillMode() 
	{
		if (IsValidHandle())
			return ::GetPolyFillMode(m_hDC);
		return 0;
	}
	int GetROP2() 
	{
		if (IsValidHandle())
			return ::GetROP2(m_hDC);
		return 0;
	}
	int GetStretchBltMode() 
	{
		if (IsValidHandle())
			return ::GetStretchBltMode(m_hDC);
		return 0;
	}
	COLORREF GetTextColor() 
	{
		if (IsValidHandle())
			return ::GetTextColor(m_hDC);
		return RGB(0,0,0);
	}

	COLORREF SetBkColor(COLORREF crColor)
	{
		if (IsValidHandle())
			return ::SetBkColor(m_hDC, crColor);
		return RGB(0,0,0);
	}
	int SetBkMode(int nBkMode)
	{
		if (IsValidHandle())
			return ::SetBkMode(m_hDC, nBkMode);
		return 0;
	}
	int SetPolyFillMode(int nPolyFillMode)
	{
		if (IsValidHandle())
			return ::SetPolyFillMode(m_hDC, nPolyFillMode);
		return 0;
	}
	int SetROP2(int nDrawMode)
	{
		if (IsValidHandle())
			return ::SetROP2(m_hDC, nDrawMode);
		return 0;
	}
	int SetStretchBltMode(int nStretchMode)
	{
		if (IsValidHandle())
			return ::SetStretchBltMode(m_hDC, nStretchMode);
		return 0;
	}
	COLORREF SetTextColor(COLORREF crColor)
	{
		if (IsValidHandle())
			return ::SetTextColor(m_hDC, crColor);
		return RGB(0,0,0);
	}

	BOOL GetColorAdjustment(LPCOLORADJUSTMENT lpColorAdjust) 
	{
		if (IsValidHandle())
			return ::GetColorAdjustment(m_hDC, lpColorAdjust);
		return FALSE;
	}
	BOOL SetColorAdjustment( COLORADJUSTMENT* lpColorAdjust)
	{
		if (IsValidHandle())
			return ::SetColorAdjustment(m_hDC, lpColorAdjust);
		return FALSE;
	}

// ---------------------------------------------------------------------
	int GetMapMode() 
	{
		if (IsValidHandle())
			return ::GetMapMode(m_hDC);
		return 0;
	}
	BOOL GetViewportOrg(LPPOINT lpPoint) 
	{
		if (IsValidHandle())
			return ::GetViewportOrgEx(m_hDC, lpPoint);
		return 0;
	}
	int SetMapMode(int nMapMode)
	{
		if (IsValidHandle())
			return ::SetMapMode(m_hDC, nMapMode);
		return 0;
	}
	// Viewport Origin
	BOOL SetViewportOrg(int x, int y, LPPOINT lpPoint = NULL)
	{
		if (IsValidHandle())
			return ::SetViewportOrgEx(m_hDC, x, y, lpPoint);
		return FALSE;
	}
	BOOL SetViewportOrg(POINT point, LPPOINT lpPointRet = NULL)
	{
		if (IsValidHandle())
			return SetViewportOrg(point.x, point.y, lpPointRet);
		return FALSE;
	}
	BOOL OffsetViewportOrg(int nWidth, int nHeight, LPPOINT lpPoint = NULL)
	{
		if (IsValidHandle())
			return ::OffsetViewportOrgEx(m_hDC, nWidth, nHeight, lpPoint);
		return FALSE;
	}

	//---------------------------------------------------------------------------
	BOOL GetViewportExt(LPSIZE lpSize) 
	{
		if (IsValidHandle())
			return ::GetViewportExtEx(m_hDC, lpSize);
		return FALSE;
	}
	BOOL SetViewportExt(int x, int y, LPSIZE lpSize = NULL)
	{
		if (IsValidHandle())
			return ::SetViewportExtEx(m_hDC, x, y, lpSize);
		return FALSE;
	}
	BOOL SetViewportExt(SIZE size, LPSIZE lpSizeRet = NULL)
	{
		if (IsValidHandle())
			return SetViewportExt(size.cx, size.cy, lpSizeRet);
		return FALSE;
	}
	BOOL ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom, LPSIZE lpSize = NULL)
	{
		if (IsValidHandle())
			return ::ScaleViewportExtEx(m_hDC, xNum, xDenom, yNum, yDenom, lpSize);
		return FALSE;
	}

	// Window Origin
	BOOL GetWindowOrg(LPPOINT lpPoint) 
	{
		if (IsValidHandle())
			return ::GetWindowOrgEx(m_hDC, lpPoint);
		return FALSE;
	}
	BOOL SetWindowOrg(int x, int y, LPPOINT lpPoint = NULL)
	{
		if (IsValidHandle())
			return ::SetWindowOrgEx(m_hDC, x, y, lpPoint);
		return FALSE;
	}
	BOOL SetWindowOrg(POINT point, LPPOINT lpPointRet = NULL)
	{
		if (IsValidHandle())
			return SetWindowOrg(point.x, point.y, lpPointRet);
		return FALSE;
	}
	BOOL OffsetWindowOrg(int nWidth, int nHeight, LPPOINT lpPoint = NULL)
	{
		if (IsValidHandle())
			return ::OffsetWindowOrgEx(m_hDC, nWidth, nHeight, lpPoint);
		return FALSE;
	}

	
	BOOL GetWindowExt(LPSIZE lpSize) 
	{
		if (IsValidHandle())
			return ::GetWindowExtEx(m_hDC, lpSize);
		return FALSE;
	}
	BOOL SetWindowExt(int x, int y, LPSIZE lpSize = NULL)
	{
		if (IsValidHandle())
			return ::SetWindowExtEx(m_hDC, x, y, lpSize);
		return FALSE;
	}
	BOOL SetWindowExt(SIZE size, LPSIZE lpSizeRet)
	{
		if (IsValidHandle())
			return SetWindowExt(size.cx, size.cy, lpSizeRet);
		return FALSE;
	}
	BOOL ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom, LPSIZE lpSize = NULL)
	{
		if (IsValidHandle())
			return ::ScaleWindowExtEx(m_hDC, xNum, xDenom, yNum, yDenom, lpSize);
		return FALSE;
	}

//-----------------------------------------------------------------------------------
	BOOL DPtoLP(LPPOINT lpPoints, int nCount = 1) 
	{
		if (IsValidHandle())
			return ::DPtoLP(m_hDC, lpPoints, nCount);
		return FALSE;
	}
	BOOL DPtoLP(LPRECT lpRect) 
	{
		if (IsValidHandle())
			return ::DPtoLP(m_hDC, (LPPOINT)lpRect, 2);
		return FALSE;
	}
	
	BOOL LPtoDP(LPPOINT lpPoints, int nCount = 1) 
	{
		if (IsValidHandle())
			return ::LPtoDP(m_hDC, lpPoints, nCount);
		return FALSE;
	}
	BOOL LPtoDP(LPRECT lpRect) 
	{
		if (IsValidHandle())
			return ::LPtoDP(m_hDC, (LPPOINT)lpRect, 2);
		return FALSE;
	}
	
//--------------------------------------------------------------------------
	BOOL FillRgn(HRGN hRgn, HBRUSH hBrush)
	{
		if (IsValidHandle())
			return ::FillRgn(m_hDC, hRgn, hBrush);
		return FALSE;
	}
	BOOL FrameRgn(HRGN hRgn, HBRUSH hBrush, int nWidth, int nHeight)
	{
		if (IsValidHandle())
			return ::FrameRgn(m_hDC, hRgn, hBrush, nWidth, nHeight);
		return FALSE;
	}
	BOOL InvertRgn(HRGN hRgn)
	{
		if (IsValidHandle())
			return ::InvertRgn(m_hDC, hRgn);
		return FALSE;
	}
	BOOL PaintRgn(HRGN hRgn)
	{
		if (IsValidHandle())
			return ::PaintRgn(m_hDC, hRgn);
		return FALSE;
	}

// ----------------------------------------------------------------------------
	int GetClipBox(LPRECT lpRect) 
	{
		if (IsValidHandle())
			return ::GetClipBox(m_hDC, lpRect);
		return 0;
	}
	BOOL PtVisible(int x, int y) 
	{
		if (IsValidHandle())
			return ::PtVisible(m_hDC, x, y);
		return FALSE;
	}
	BOOL PtVisible(POINT point) 
	{
		if (IsValidHandle())
			return ::PtVisible(m_hDC, point.x, point.y);
		return FALSE;
	}
	BOOL RectVisible(LPCRECT lpRect) 
	{
		if (IsValidHandle())
			return ::RectVisible(m_hDC, lpRect);
		return FALSE;
	}
	int SelectClipRgn(HRGN hRgn)
	{
		if (IsValidHandle())
			return ::SelectClipRgn(m_hDC, (HRGN)hRgn);
		return 0;
	}
	int ExcludeClipRect(int x1, int y1, int x2, int y2)
	{
		if (IsValidHandle())
			return ::ExcludeClipRect(m_hDC, x1, y1, x2, y2);
		return 0;
	}
	int ExcludeClipRect(LPCRECT lpRect)
	{
		if (IsValidHandle())
			return ::ExcludeClipRect(m_hDC, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
		return 0;
	}
	int ExcludeUpdateRgn(HWND hWnd)
	{
		if (IsValidHandle())
			return ::ExcludeUpdateRgn(m_hDC, hWnd);
		return 0;
	}
	int IntersectClipRect(int x1, int y1, int x2, int y2)
	{
		if (IsValidHandle())
			return ::IntersectClipRect(m_hDC, x1, y1, x2, y2);
		return 0;
	}
	int IntersectClipRect(LPCRECT lpRect)
	{
		if (IsValidHandle())
			return ::IntersectClipRect(m_hDC, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
		return 0;
	}
	int OffsetClipRgn(int x, int y)
	{
		if (IsValidHandle())
			return ::OffsetClipRgn(m_hDC, x, y);
		return 0;
	}
	int OffsetClipRgn(SIZE size)
	{
		if (IsValidHandle())
			return ::OffsetClipRgn(m_hDC, size.cx, size.cy);
		return 0;
	}
	int SelectClipRgn(HRGN hRgn, int nMode)
	{
		if (IsValidHandle())
			return ::ExtSelectClipRgn(m_hDC, hRgn, nMode);
		return 0;
	}

//--------------------------------------------------------------------------
	BOOL GetCurrentPosition(LPPOINT lpPoint) 
	{
		if (IsValidHandle())
			return ::GetCurrentPositionEx(m_hDC, lpPoint);
		return FALSE;
	}
	BOOL MoveTo(int x, int y, LPPOINT lpPoint = NULL)
	{
		if (IsValidHandle())
			return ::MoveToEx(m_hDC, x, y, lpPoint);
		return FALSE;

	}
	BOOL MoveTo(POINT point, LPPOINT lpPointRet = NULL)
	{
		if (IsValidHandle())
			return MoveTo(point.x, point.y, lpPointRet);
		return FALSE;
	}
	BOOL LineTo(int x, int y)
	{
		if (IsValidHandle())
			return ::LineTo(m_hDC, x, y);
		return FALSE;
	}
	BOOL LineTo(POINT point)
	{
		if (IsValidHandle())
			return LineTo(point.x, point.y);
		return FALSE;
	}

	BOOL DrawLine(POINT pointOr,POINT pointTar)
	{
		if (IsValidHandle())
		{
			MoveTo(pointOr);
			LineTo(pointTar);
			return TRUE;
		}
		return FALSE;
	}

	BOOL DrawLine(POINT pointOr,POINT pointTar,COLORREF clColor)
	{
		if (IsValidHandle())
		{
			CPen Color;
			Color.CreatePen(PS_SOLID,1,clColor);
			CPen pOldPen=CPen(SelectObject(&Color));
			MoveTo(pointOr);
			LineTo(pointTar);
			SelectObject(&pOldPen);	
			return TRUE;
		}
		return FALSE;
	}

	void DrawRect(CRect* rclt,COLORREF clLT,COLORREF clBR)
	{
		DrawLine(CPoint(rclt->left,rclt->top),CPoint(rclt->left,rclt->bottom),clLT);
		DrawLine(CPoint(rclt->left,rclt->top+1),CPoint(rclt->right,rclt->top+1),clLT);
		DrawLine(CPoint(rclt->right,rclt->top+1),CPoint(rclt->right,rclt->bottom),clBR);
		DrawLine(CPoint(rclt->left,rclt->bottom-1),CPoint(rclt->right,rclt->bottom-1),clBR);
	}


	BOOL Arc(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{
		if (IsValidHandle())
			return ::Arc(m_hDC, x1, y1, x2, y2, x3, y3, x4, y4);
		return FALSE;
	}
	BOOL Arc(LPCRECT lpRect, POINT ptStart, POINT ptEnd)
	{
		if (IsValidHandle())
			return ::Arc(m_hDC, lpRect->left, lpRect->top,
				lpRect->right, lpRect->bottom, ptStart.x, ptStart.y,
				ptEnd.x, ptEnd.y);
		return FALSE;
	}
	BOOL Polyline(LPPOINT lpPoints, int nCount)
	{
		if (IsValidHandle())
			return ::Polyline(m_hDC, lpPoints, nCount);
		return FALSE;
	}

	BOOL AngleArc(int x, int y, int nRadius, float fStartAngle, float fSweepAngle)
	{
		if (IsValidHandle())
			return ::AngleArc(m_hDC, x, y, nRadius, fStartAngle, fSweepAngle);
		return FALSE;
	}
	BOOL ArcTo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{
		if (IsValidHandle())
			return ::ArcTo(m_hDC, x1, y1, x2, y2, x3, y3, x4, y4);
		return FALSE;
	}
	BOOL ArcTo(LPCRECT lpRect, POINT ptStart, POINT ptEnd)
	{
		if (IsValidHandle())
			return ArcTo(lpRect->left, lpRect->top, lpRect->right,
			lpRect->bottom, ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);
		return FALSE;
	}
	int GetArcDirection() 
	{
		if (IsValidHandle())
			return ::GetArcDirection(m_hDC);
		return FALSE;
	}
	int SetArcDirection(int nArcDirection)
	{
		if (IsValidHandle())
			return ::SetArcDirection(m_hDC, nArcDirection);
		return FALSE;
	}

	BOOL PolyDraw( POINT* lpPoints,  BYTE* lpTypes, int nCount)
	{
		if (IsValidHandle())
			return ::PolyDraw(m_hDC, lpPoints, lpTypes, nCount);
		return FALSE;
	}
	BOOL PolylineTo( POINT* lpPoints, int nCount)
	{
		if (IsValidHandle())
			return ::PolylineTo(m_hDC, lpPoints, nCount);
		return FALSE;
	}
	BOOL PolyPolyline( POINT* lpPoints,
		 DWORD* lpPolyPoints, int nCount)
	{
		if (IsValidHandle())
			return ::PolyPolyline(m_hDC, lpPoints, lpPolyPoints, nCount);
		return FALSE;
	}

	BOOL PolyBezier( POINT* lpPoints, int nCount)
	{
		if (IsValidHandle())
			return ::PolyBezier(m_hDC, lpPoints, nCount);
		return FALSE;
	}
	BOOL PolyBezierTo( POINT* lpPoints, int nCount)
	{
		if (IsValidHandle())
			return ::PolyBezierTo(m_hDC, lpPoints, nCount);
		return FALSE;
	}

// ----------------------------------------------------------------------
	
	void FillRect(LPCRECT lprc,CBrush* pBruhs)
	{
		if (IsValidHandle())
			::FillRect(m_hDC,lprc,(HBRUSH)pBruhs->GetBrush());
	}
	
	void FillRect(LPCRECT lprc,HBRUSH hBruhs)
	{
		if (IsValidHandle())
			::FillRect(m_hDC,lprc,hBruhs);
	}
	
	BOOL FrameRect(LPCRECT lpRect, HBRUSH hBrush)
	{
		if (IsValidHandle())
			return ::FrameRect(m_hDC, lpRect, hBrush);
		return FALSE;
	}
	BOOL InvertRect(LPCRECT lpRect)
	{
		if (IsValidHandle())
			return ::InvertRect(m_hDC, lpRect);
		return FALSE;
	}
	BOOL DrawIcon(int x, int y, HICON hIcon)
	{
		if (IsValidHandle())
			return ::DrawIcon(m_hDC, x, y, hIcon);
		return FALSE;
	}
	BOOL DrawIcon(POINT point, HICON hIcon)
	{
		if (IsValidHandle())
			return ::DrawIcon(m_hDC, point.x, point.y, hIcon);
		return FALSE;
	}
	BOOL DrawIconEx(int x, int y, HICON hIcon, int cxWidth, int cyWidth, UINT uStepIfAniCur = 0, HBRUSH hbrFlickerFreeDraw = NULL, UINT uFlags = DI_NORMAL)
	{
		if (IsValidHandle())
			return ::DrawIconEx(m_hDC, x, y, hIcon, cxWidth, cyWidth, uStepIfAniCur, hbrFlickerFreeDraw, uFlags);
		return FALSE;
	}
	BOOL DrawIconEx(POINT point, HICON hIcon, SIZE size, UINT uStepIfAniCur = 0, HBRUSH hbrFlickerFreeDraw = NULL, UINT uFlags = DI_NORMAL)
	{
		if (IsValidHandle())
			return ::DrawIconEx(m_hDC, point.x, point.y, hIcon, size.cx, size.cy, uStepIfAniCur, hbrFlickerFreeDraw, uFlags);
		return FALSE;
	}


	BOOL DrawState(CPoint pt, CSize size, HICON hIcon, UINT nFlags, CBrush* pBrush)
	{ 
		ASSERT(m_hDC != NULL); 
		return ::DrawState(m_hDC, (HBRUSH)pBrush->GetSafeHandle(), NULL,(LPARAM)hIcon, 0, 
			pt.x, pt.y, size.cx, size.cy, nFlags|DST_ICON); 
	}

	BOOL DrawState(POINT pt, SIZE size, HBITMAP hBitmap, UINT nFlags, HBRUSH hBrush = NULL)
	{
		if (IsValidHandle())
			return ::DrawState(m_hDC, hBrush, NULL, (LPARAM)hBitmap, 0, pt.x, pt.y, size.cx, size.cy, nFlags | DST_BITMAP);
		return FALSE;
	}
	BOOL DrawState(POINT pt, SIZE size, HICON hIcon, UINT nFlags, HBRUSH hBrush = NULL)
	{
		if (IsValidHandle())
			return ::DrawState(m_hDC, hBrush, NULL, (LPARAM)hIcon, 0, pt.x, pt.y, size.cx, size.cy, nFlags | DST_ICON);
		return FALSE;
	}


	BOOL DrawState(CPoint pt, CSize size, HICON hIcon, UINT nFlags, HBRUSH hBrush)
	{ 
		ASSERT(m_hDC != NULL); 
		return ::DrawState(m_hDC, hBrush, NULL,	(LPARAM)hIcon, 0,
			pt.x, pt.y, size.cx, size.cy, nFlags|DST_ICON); 
	}

	BOOL DrawState(CPoint pt, CSize size, HBITMAP hBitmap, UINT nFlags, HBRUSH hBrush)
	{ 
		ASSERT(m_hDC != NULL); 
		return ::DrawState(m_hDC, hBrush,NULL, (LPARAM)hBitmap, 0, pt.x, pt.y, size.cx, size.cy, nFlags|DST_BITMAP); 
	}

	


	BOOL DrawState(CPoint pt, CSize size, CBitmap* pBitmap, UINT nFlags, CBrush* pBrush)
	{ 
		ASSERT(m_hDC != NULL); 
		return ::DrawState(m_hDC, (HBRUSH)pBrush->GetSafeHandle(),NULL, 
			(LPARAM)pBitmap->GetSafeHandle(), 0, pt.x, pt.y, size.cx, size.cy, nFlags|DST_BITMAP); 
	}

	BOOL DrawState(CPoint pt, CSize size, LPCTSTR lpszText, UINT nFlags, BOOL bPrefixText, int nTextLen, CBrush* pBrush)
	{ 
		ASSERT(m_hDC != NULL); 
		return ::DrawState(m_hDC, (HBRUSH)pBrush->GetSafeHandle(),NULL, (LPARAM)lpszText, 
			(WPARAM)nTextLen, pt.x, pt.y, size.cx, size.cy, nFlags|(bPrefixText ? DST_PREFIXTEXT : DST_TEXT)); 
	}

	//	pdc->DrawState(p,m_SizeImage,m_Icon,DSS_MONO,CDrawLayer::GetRGBColorShadow());

	
	BOOL DrawState(CPoint pt, CSize size, LPCTSTR lpszText, UINT nFlags, BOOL bPrefixText, int nTextLen, HBRUSH hBrush)
	{ 
		ASSERT(m_hDC != NULL); 
		return ::DrawState(m_hDC, hBrush,NULL, (LPARAM)lpszText, 
			(WPARAM)nTextLen, pt.x, pt.y, size.cx, size.cy, nFlags|(bPrefixText ? DST_PREFIXTEXT : DST_TEXT)); 
	}
	
	

	BOOL DrawState(CPoint pt, CSize size, DRAWSTATEPROC lpDrawProc, LPARAM lData, UINT nFlags, HBRUSH hBrush)
	{ 
		ASSERT(m_hDC != NULL); 
		return ::DrawState(m_hDC, hBrush,lpDrawProc, lData, 0, pt.x, pt.y,
			size.cx, size.cy, nFlags|DST_COMPLEX); 
	}

	BOOL DrawState(CPoint pt, CSize size, DRAWSTATEPROC lpDrawProc, LPARAM lData, UINT nFlags, CBrush* pBrush)
	{ 
		ASSERT(m_hDC != NULL); 
		return ::DrawState(m_hDC, (HBRUSH)pBrush->GetSafeHandle(),lpDrawProc, lData, 0, pt.x, pt.y, 
		size.cx, size.cy, nFlags|DST_COMPLEX); 
	}

	
//----------------------------------------------------------------------------------------------
	BOOL Chord(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{
		if (IsValidHandle())
			return ::Chord(m_hDC, x1, y1, x2, y2, x3, y3, x4, y4);
		return FALSE;
	}
	BOOL Chord(LPCRECT lpRect, POINT ptStart, POINT ptEnd)
	{
		if (IsValidHandle())
			return ::Chord(m_hDC, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom, ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);
		return FALSE;
	}
	void DrawFocusRect(LPCRECT lpRect)
	{
		if (IsValidHandle())
			::DrawFocusRect(m_hDC, lpRect);
	}
	
	BOOL Ellipse(int x1, int y1, int x2, int y2)
	{
		if (IsValidHandle())
			return ::Ellipse(m_hDC, x1, y1, x2, y2);
		return FALSE;
	}
	BOOL Ellipse(LPCRECT lpRect)
	{
		if (IsValidHandle())
			return ::Ellipse(m_hDC, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
		return FALSE;
	}
	BOOL Pie(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{
		if (IsValidHandle())
			return ::Pie(m_hDC, x1, y1, x2, y2, x3, y3, x4, y4);
		return FALSE;
	}
	BOOL Pie(LPCRECT lpRect, POINT ptStart, POINT ptEnd)
	{
		if (IsValidHandle())
			return ::Pie(m_hDC, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom, ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);
		return FALSE;
	}
	BOOL Polygon(LPPOINT lpPoints, int nCount)
	{
		if (IsValidHandle())
			return ::Polygon(m_hDC, lpPoints, nCount);
		return FALSE;
	}
	BOOL PolyPolygon(LPPOINT lpPoints, LPINT lpPolyCounts, int nCount)
	{
		if (IsValidHandle())
			return ::PolyPolygon(m_hDC, lpPoints, lpPolyCounts, nCount);
		return FALSE;
	}
	BOOL Rectangle(int x1, int y1, int x2, int y2)
	{
		if (IsValidHandle())
			return ::Rectangle(m_hDC, x1, y1, x2, y2);
		return FALSE;
	}
	BOOL Rectangle(LPCRECT lpRect)
	{
		if (IsValidHandle())
			return ::Rectangle(m_hDC, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
		return FALSE;
	}
	BOOL RoundRect(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		if (IsValidHandle())
			return ::RoundRect(m_hDC, x1, y1, x2, y2, x3, y3);
		return FALSE;
	}
	BOOL RoundRect(LPCRECT lpRect, POINT point)
	{
		if (IsValidHandle())
			return ::RoundRect(m_hDC, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom, point.x, point.y);
		return FALSE;
	}

//------------------------------------------------------------------------------------
	BOOL PatBlt(int x, int y, int nWidth, int nHeight, DWORD dwRop)
	{
		if (IsValidHandle())
			return ::PatBlt(m_hDC, x, y, nWidth, nHeight, dwRop);
		return FALSE;
	}
	BOOL PatBlt(CRect rc, DWORD dwRop)
	{
		if (IsValidHandle())
			return ::PatBlt(m_hDC, rc.left,rc.top, rc.Width(),rc.Height(), dwRop);
		return FALSE;
	}
	BOOL BitBlt(int x, int y, int nWidth, int nHeight, HDC hSrcDC,
		int xSrc, int ySrc, DWORD dwRop)
	{
		if (IsValidHandle())
			return ::BitBlt(m_hDC, x, y, nWidth, nHeight, hSrcDC, xSrc, ySrc, dwRop);
		return FALSE;
	}
	BOOL BitBlt(CRect rc, HDC hSrcDC,
		int xSrc, int ySrc, DWORD dwRop)
	{
		if (IsValidHandle())
			return ::BitBlt(m_hDC, rc.left, rc.top, rc.right, rc.bottom, hSrcDC, xSrc, ySrc, dwRop);
		return FALSE;
	}
	BOOL StretchBlt(int x, int y, int nWidth, int nHeight, HDC hSrcDC, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, DWORD dwRop)
	{
		if (IsValidHandle())
			return ::StretchBlt(m_hDC, x, y, nWidth, nHeight, hSrcDC, xSrc, ySrc, nSrcWidth, nSrcHeight, dwRop);
		return FALSE;
	}
	COLORREF GetPixel(int x, int y) 
	{
		if (IsValidHandle())
			return ::GetPixel(m_hDC, x, y);
		return FALSE;
	}
	COLORREF GetPixel(POINT point) 
	{
		if (IsValidHandle())
			return ::GetPixel(m_hDC, point.x, point.y);
		return FALSE;
	}
	COLORREF SetPixel(int x, int y, COLORREF crColor)
	{
		if (IsValidHandle())
			return ::SetPixel(m_hDC, x, y, crColor);
		return FALSE;
	}
	COLORREF SetPixel(POINT point, COLORREF crColor)
	{
		if (IsValidHandle())
			return ::SetPixel(m_hDC, point.x, point.y, crColor);
		return FALSE;
	}
	BOOL FloodFill(int x, int y, COLORREF crColor)
	{
		if (IsValidHandle())
			return ::FloodFill(m_hDC, x, y, crColor);
		return FALSE;
	}
	BOOL ExtFloodFill(int x, int y, COLORREF crColor, UINT nFillType)
	{
		if (IsValidHandle())
			return ::ExtFloodFill(m_hDC, x, y, crColor, nFillType);
		return FALSE;
	}
	BOOL MaskBlt(int x, int y, int nWidth, int nHeight, HDC hSrcDC, int xSrc, int ySrc, HBITMAP hMaskBitmap, int xMask, int yMask, DWORD dwRop)
	{
		if (IsValidHandle())
			return ::MaskBlt(m_hDC, x, y, nWidth, nHeight, hSrcDC, xSrc, ySrc, hMaskBitmap, xMask, yMask, dwRop);
		return FALSE;
	}
	BOOL PlgBlt(LPPOINT lpPoint, HDC hSrcDC, int xSrc, int ySrc, int nWidth, int nHeight, HBITMAP hMaskBitmap, int xMask, int yMask)
	{
		if (IsValidHandle())
			return ::PlgBlt(m_hDC, lpPoint, hSrcDC, xSrc, ySrc, nWidth, nHeight, hMaskBitmap, xMask, yMask);
		return FALSE;
	}
	BOOL SetPixelV(int x, int y, COLORREF crColor)
	{
		if (IsValidHandle())
			return ::SetPixelV(m_hDC, x, y, crColor);
		return FALSE;
	}
	BOOL SetPixelV(POINT point, COLORREF crColor)
	{
		if (IsValidHandle())
			return ::SetPixelV(m_hDC, point.x, point.y, crColor);
		return FALSE;
	}

	//------------------------------------------------------------------------------------------
	
	BOOL TextOut(int x, int y, LPCTSTR lpszString, int nCount = -1)
	{
		if (IsValidHandle())
		{
			if(nCount == -1)
				nCount = lstrlen(lpszString);
			return ::TextOut(m_hDC, x, y, lpszString, nCount);
		}
		return FALSE;

	}
	BOOL ExtTextOut(int x, int y, UINT nOptions, LPCRECT lpRect, LPCTSTR lpszString, UINT nCount = -1, LPINT lpDxWidths = NULL)
	{
		if (IsValidHandle())
		{
			if(nCount == (UINT)(-1))
				nCount = lstrlen(lpszString);
			return ::ExtTextOut(m_hDC, x, y, nOptions, lpRect, lpszString, nCount, lpDxWidths);
		}
		return FALSE;
	}

	long  TabbedTextOut(int x, int y, LPCTSTR lpszString, int nCount = -1, int nTabPositions = 0, LPINT lpnTabStopPositions = NULL, int nTabOrigin = 0)
	{
		if (IsValidHandle())
		{
			if(nCount == -1)
				nCount = lstrlen(lpszString);
			LONG lres = ::TabbedTextOut(m_hDC, x, y, lpszString, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin);
			(void)lres;
		}
		return 0;
			
	}
	int DrawText(LPCTSTR lpstrText, int cchText, LPRECT lpRect, UINT uFormat)
	{
		if (IsValidHandle())
			return ::DrawText(m_hDC, lpstrText, cchText, lpRect, uFormat);
		return 0;
	}
	int DrawTextEx(LPTSTR lpstrText, int cchText, LPRECT lpRect, UINT uFormat, LPDRAWTEXTPARAMS lpDTParams = NULL)
	{
		if (IsValidHandle())
			return ::DrawTextEx(m_hDC, lpstrText, cchText, lpRect, uFormat, lpDTParams);
		return 0;
	}

	int  DrawText(LPCTSTR lpstrText, LPRECT lpRect,UINT uFormat=0)
	{
		return DrawText(lpstrText, _tcslen(lpstrText), lpRect, uFormat);
	}


	BOOL GetTextExtent(LPCTSTR lpszString, int nCount, LPSIZE lpSize) 
	{
		if (IsValidHandle())
		{
			if(nCount == -1)
				nCount = lstrlen(lpszString);
			return ::GetTextExtentPoint32(m_hDC, lpszString, nCount, lpSize);
		}
		return FALSE;
	}


	CSize GetTextExtent(LPCTSTR lpszString, int nCount) 
	{
		CSize sc;
		GetTextExtent(lpszString, nCount, &sc); 
		return sc;
	}

	DWORD GetTabbedTextExtent(LPCTSTR lpszString, int nCount = -1, int nTabPositions = 0, LPINT lpnTabStopPositions = NULL) 
	{
		if (IsValidHandle())
		{
			if(nCount == -1)
				nCount = lstrlen(lpszString);
			return ::GetTabbedTextExtent(m_hDC, lpszString, nCount, nTabPositions, lpnTabStopPositions);
		}
		return FALSE;
	}
	BOOL GrayString(HBRUSH hBrush, BOOL (CALLBACK* lpfnOutput)(HDC, LPARAM, int), LPARAM lpData, int nCount, int x, int y, int nWidth, int nHeight)
	{
		if (IsValidHandle())
			return ::GrayString(m_hDC, hBrush, (GRAYSTRINGPROC)lpfnOutput, lpData, nCount, x, y, nWidth, nHeight);
		return FALSE;
	}
	UINT GetTextAlign() 
	{
		if (IsValidHandle())
			return ::GetTextAlign(m_hDC);
		return 0;
	}
	UINT SetTextAlign(UINT nFlags)
	{
		if (IsValidHandle())
			return ::SetTextAlign(m_hDC, nFlags);
		return 0;
	}
	int GetTextFace(LPTSTR lpszFacename, int nCount) 
	{
		if (IsValidHandle())
			return ::GetTextFace(m_hDC, nCount, lpszFacename);
		return 0;
	}
	int GetTextFaceLen() 
	{
		if (IsValidHandle())
			return ::GetTextFace(m_hDC, 0, NULL);
		return 0;
	}

	BOOL GetTextMetrics(LPTEXTMETRIC lpMetrics) 
	{
		if (IsValidHandle())
			return ::GetTextMetrics(m_hDC, lpMetrics);
		return FALSE;
	}
	int SetTextJustification(int nBreakExtra, int nBreakCount)
	{
		if (IsValidHandle())
			return ::SetTextJustification(m_hDC, nBreakExtra, nBreakCount);
		return 0;
	}
	int GetTextCharacterExtra() 
	{
		if (IsValidHandle())
			return ::GetTextCharacterExtra(m_hDC);
		return 0;
	}
	int SetTextCharacterExtra(int nCharExtra)
	{
		if (IsValidHandle())
			return ::SetTextCharacterExtra(m_hDC, nCharExtra);
		return 0;
	}

// -----------------------------------------------------------------------------
	BOOL DrawEdge(LPRECT lpRect, UINT nEdge, UINT nFlags)
	{
		if (IsValidHandle())
			return ::DrawEdge(m_hDC, lpRect, nEdge, nFlags);
		return FALSE;
	}
	BOOL DrawFrameControl(LPRECT lpRect, UINT nType, UINT nState)
	{
		if (IsValidHandle())
			return ::DrawFrameControl(m_hDC, lpRect, nType, nState);
		return FALSE;
	}

//-------------------------------------------------------------------------------
	BOOL ScrollDC(int dx, int dy, LPCRECT lpRectScroll, LPCRECT lpRectClip, HRGN hRgnUpdate, LPRECT lpRectUpdate)
	{
		if (IsValidHandle())
			return ::ScrollDC(m_hDC, dx, dy, lpRectScroll, lpRectClip, hRgnUpdate, lpRectUpdate);
		return FALSE;
	}

	BOOL GetCharWidth(UINT nFirstChar, UINT nLastChar, LPINT lpBuffer) 
	{
		if (IsValidHandle())
			return ::GetCharWidth(m_hDC, nFirstChar, nLastChar, lpBuffer);
		return FALSE;
	}

	BOOL GetCharWidth32(UINT nFirstChar, UINT nLastChar, LPINT lpBuffer) 
	{
		if (IsValidHandle())
			return ::GetCharWidth32(m_hDC, nFirstChar, nLastChar, lpBuffer);
		return FALSE;
	}
	DWORD SetMapperFlags(DWORD dwFlag)
	{
		if (IsValidHandle())
			return ::SetMapperFlags(m_hDC, dwFlag);
		return FALSE;
	}
	BOOL GetAspectRatioFilter(LPSIZE lpSize) 
	{
		if (IsValidHandle())
			return ::GetAspectRatioFilterEx(m_hDC, lpSize);
		return FALSE;
	}

	BOOL GetCharABCWidths(UINT nFirstChar, UINT nLastChar, LPABC lpabc) 
	{
		if (IsValidHandle())
			return ::GetCharABCWidths(m_hDC, nFirstChar, nLastChar, lpabc);
		return FALSE;
	}
	DWORD GetFontData(DWORD dwTable, DWORD dwOffset, LPVOID lpData, DWORD cbData) 
	{
		if (IsValidHandle())
			return ::GetFontData(m_hDC, dwTable, dwOffset, lpData, cbData);
		return FALSE;
	}
	int GetKerningPairs(int nPairs, LPKERNINGPAIR lpkrnpair) 
	{
		if (IsValidHandle())
			return ::GetKerningPairs(m_hDC, nPairs, lpkrnpair);
		return FALSE;
	}
	UINT GetOutlineTextMetrics(UINT cbData, LPOUTLINETEXTMETRIC lpotm) 
	{
		if (IsValidHandle())
			return ::GetOutlineTextMetrics(m_hDC, cbData, lpotm);
		return FALSE;
	}
	DWORD GetGlyphOutline(UINT nChar, UINT nFormat, LPGLYPHMETRICS lpgm, DWORD cbBuffer, LPVOID lpBuffer,  MAT2* lpmat2) 
	{
		if (IsValidHandle())
			return ::GetGlyphOutline(m_hDC, nChar, nFormat, lpgm, cbBuffer, lpBuffer, lpmat2);
		return FALSE;
	}

	BOOL GetCharABCWidths(UINT nFirstChar, UINT nLastChar, LPABCFLOAT lpABCF) 
	{
		if (IsValidHandle())
			return ::GetCharABCWidthsFloat(m_hDC, nFirstChar, nLastChar, lpABCF);
		return FALSE;
	}
	BOOL GetCharWidth(UINT nFirstChar, UINT nLastChar, float* lpFloatBuffer) 
	{
		if (IsValidHandle())
			return ::GetCharWidthFloat(m_hDC, nFirstChar, nLastChar, lpFloatBuffer);
		return FALSE;
	}

//-------------------------------------------------------------------------------------
	int Escape(int nEscape, int nCount, LPCSTR lpszInData, LPVOID lpOutData)
	{
		if (IsValidHandle())
			return ::Escape(m_hDC, nEscape, nCount, lpszInData, lpOutData);
		return FALSE;
	}
	int Escape(int nEscape, int nInputSize, LPCSTR lpszInputData,
		int nOutputSize, LPSTR lpszOutputData)
	{
		if (IsValidHandle())
			return ::ExtEscape(m_hDC, nEscape, nInputSize, lpszInputData, nOutputSize, lpszOutputData);
		return FALSE;
	}
	int DrawEscape(int nEscape, int nInputSize, LPCSTR lpszInputData)
	{
		if (IsValidHandle())
			return ::DrawEscape(m_hDC, nEscape, nInputSize, lpszInputData);
		return FALSE;
	}

	
	int StartDoc(LPDOCINFO lpDocInfo)
	{
		if (IsValidHandle())
			return ::StartDoc(m_hDC, lpDocInfo);
		return FALSE;
	}
	int StartPage()
	{
		if (IsValidHandle())
			return ::StartPage(m_hDC);
		return FALSE;
	}
	int EndPage()
	{
		if (IsValidHandle())
			return ::EndPage(m_hDC);
		return FALSE;
	}
	int SetAbortProc(BOOL (CALLBACK* lpfn)(HDC, int))
	{
		if (IsValidHandle())
			return ::SetAbortProc(m_hDC, (ABORTPROC)lpfn);
		return FALSE;
	}
	int AbortDoc()
	{
		if (IsValidHandle())
			return ::AbortDoc(m_hDC);
		return FALSE;
	}
	int EndDoc()
	{
		if (IsValidHandle())
			return ::EndDoc(m_hDC);
		return FALSE;
	}


	//-----------------------------------------------------------------------
	BOOL AbortPath()
	{
		if (IsValidHandle())
			return ::AbortPath(m_hDC);
		return FALSE;
	}
	BOOL BeginPath()
	{
		if (IsValidHandle())
			return ::BeginPath(m_hDC);
		return FALSE;
	}
	BOOL CloseFigure()
	{
		if (IsValidHandle())
			return ::CloseFigure(m_hDC);
		return FALSE;
	}
	BOOL EndPath()
	{
		if (IsValidHandle())
			return ::EndPath(m_hDC);
		return FALSE;
	}
	BOOL FillPath()
	{
		if (IsValidHandle())
			return ::FillPath(m_hDC);
		return FALSE;
	}
	BOOL FlattenPath()
	{
		if (IsValidHandle())
			return ::FlattenPath(m_hDC);
		return FALSE;
	}
	BOOL StrokeAndFillPath()
	{
		if (IsValidHandle())
			return ::StrokeAndFillPath(m_hDC);
		return FALSE;
	}
	BOOL StrokePath()
	{
		if (IsValidHandle())
			return ::StrokePath(m_hDC);
		return FALSE;
	}
	BOOL WidenPath()
	{
		if (IsValidHandle())
			return ::WidenPath(m_hDC);
		return FALSE;
	}
	BOOL GetMiterLimit(PFLOAT pfMiterLimit) 
	{
		if (IsValidHandle())
			return ::GetMiterLimit(m_hDC, pfMiterLimit);
		return FALSE;
	}
	BOOL SetMiterLimit(float fMiterLimit)
	{
		if (IsValidHandle())
			return ::SetMiterLimit(m_hDC, fMiterLimit, NULL);
		return FALSE;
	}
	int GetPath(LPPOINT lpPoints, LPBYTE lpTypes, int nCount) 
	{
		if (IsValidHandle())
			return ::GetPath(m_hDC, lpPoints, lpTypes, nCount);
		return FALSE;
	}
	BOOL SelectClipPath(int nMode)
	{
		if (IsValidHandle())
			return ::SelectClipPath(m_hDC, nMode);
		return FALSE;
	}

	
	//-----------------------------------------------------------------------------------
	int SetDIBitsToDevice(int x, int y, DWORD dwWidth, DWORD dwHeight, int xSrc, int ySrc, UINT uStartScan, UINT cScanLines,  VOID* lpvBits,  BITMAPINFO* lpbmi, UINT uColorUse)
	{
		if (IsValidHandle())
			return ::SetDIBitsToDevice(m_hDC, x, y, dwWidth, dwHeight, xSrc, ySrc, uStartScan, cScanLines, lpvBits, lpbmi, uColorUse);
		return 0;
	}
	int StretchDIBits(int x, int y, int nWidth, int nHeight, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight,  VOID* lpvBits,  BITMAPINFO* lpbmi, UINT uColorUse, DWORD dwRop)
	{
		if (IsValidHandle())
			return ::StretchDIBits(m_hDC, x, y, nWidth, nHeight, xSrc, ySrc, nSrcWidth, nSrcHeight, lpvBits, lpbmi, uColorUse, dwRop);
		return 0;
	}
	UINT GetDIBColorTable(UINT uStartIndex, UINT cEntries, RGBQUAD* pColors) 
	{
		if (IsValidHandle())
			return ::GetDIBColorTable(m_hDC, uStartIndex, cEntries, pColors);
		return 0;
	}
	UINT SetDIBColorTable(UINT uStartIndex, UINT cEntries,  RGBQUAD* pColors)
	{
		if (IsValidHandle())
			return ::SetDIBColorTable(m_hDC, uStartIndex, cEntries, pColors);
		return 0;
	}


#if (_WIN32_WINNT >= 0x0500)

	COLORREF GetDCPenColor() 
	{
		if (IsValidHandle())
			return ::GetDCPenColor(m_hDC);
		return RGB(0,0,0);
	}
	COLORREF SetDCPenColor(COLORREF clr)
	{
		if (IsValidHandle())
			return ::SetDCPenColor(m_hDC, clr);
		return RGB(0,0,0);
	}
	COLORREF GetDCBrushColor() 
	{
		if (IsValidHandle())
			return ::GetDCBrushColor(m_hDC);
		return RGB(0,0,0);
	}
	COLORREF SetDCBrushColor(COLORREF clr)
	{
		if (IsValidHandle())
			return ::SetDCBrushColor(m_hDC, clr);
		return RGB(0,0,0);
	}

	DWORD GetFontUnicodeRanges(LPGLYPHSET lpgs) 
	{
		if (IsValidHandle())
			return ::GetFontUnicodeRanges(m_hDC, lpgs);
		return 0;
	}
	DWORD GetGlyphIndices(LPCTSTR lpstr, int cch, LPWORD pgi, DWORD dwFlags) 
	{
		if (IsValidHandle())
			return ::GetGlyphIndices(m_hDC, lpstr, cch, pgi, dwFlags);
		return 0;
	}

	BOOL GetTextExtentPointI(LPWORD pgiIn, int cgi, LPSIZE lpSize) 
	{
		if (IsValidHandle())
			return ::GetTextExtentPointI(m_hDC, pgiIn, cgi, lpSize);
		return FALSE;
	}
	BOOL GetTextExtentExPointI(LPWORD pgiIn, int cgi, int nMaxExtent, LPINT lpnFit, LPINT alpDx, LPSIZE lpSize) 
	{
		if (IsValidHandle())
			return ::GetTextExtentExPointI(m_hDC, pgiIn, cgi, nMaxExtent, lpnFit, alpDx, lpSize);
		return FALSE;
	}
	BOOL GetCharWidthI(UINT giFirst, UINT cgi, LPWORD pgi, LPINT lpBuffer) 
	{
		if (IsValidHandle())
			return ::GetCharWidthI(m_hDC, giFirst, cgi, pgi, lpBuffer);
		return FALSE;
	}
	BOOL GetCharABCWidthsI(UINT giFirst, UINT cgi, LPWORD pgi, LPABC lpabc) 
	{
		if (IsValidHandle())
			return ::GetCharABCWidthsI(m_hDC, giFirst, cgi, pgi, lpabc);
		return FALSE;
	}

#endif 


#if (WINVER >= 0x0500)

	BOOL ColorCorrectPalette(HPALETTE hPalette, DWORD dwFirstEntry, DWORD dwNumOfEntries)
	{
		if (IsValidHandle())
			return ::ColorCorrectPalette(m_hDC, hPalette, dwFirstEntry, dwNumOfEntries);
		return FALSE;
	}
#endif
	
	void FillSolidRect(LPCRECT lpRect, COLORREF clr)
	{
		
		if (!IsValidHandle()) return ;
		::SetBkColor(m_hDC, clr);
		::ExtTextOut(m_hDC, 0, 0, ETO_OPAQUE, lpRect, NULL, 0, NULL);
	}

	void FillSolidRect(int x, int y, int cx, int cy, COLORREF clr)
	{
		if (!IsValidHandle()) return ;

		::SetBkColor(m_hDC, clr);
		CRect rect(x, y, x + cx, y + cy);
		::ExtTextOut(m_hDC, 0, 0, ETO_OPAQUE, &rect, NULL, 0, NULL);
	}

	void Draw3dRect(LPCRECT lpRect,	COLORREF clrTopLeft, COLORREF clrBottomRight)
	{
		Draw3dRect(lpRect->left, lpRect->top, lpRect->right - lpRect->left,
			lpRect->bottom - lpRect->top, clrTopLeft, clrBottomRight);
	}

	void Draw3dRect(int x, int y, int cx, int cy,
		COLORREF clrTopLeft, COLORREF clrBottomRight)
	{
		FillSolidRect(x, y, cx - 1, 1, clrTopLeft);
		FillSolidRect(x, y, 1, cy - 1, clrTopLeft);
		FillSolidRect(x + cx, y, -1, cy, clrBottomRight);
		FillSolidRect(x, y + cy, cx, -1, clrBottomRight);
	}

	void DrawTextAjust(CRect rc,LPCSTR lpString, UINT uFormatDrop, UINT uFormatNormal)
	{
		TCHAR m_cadBreak[64];
		memset(m_cadBreak,0x00,64);
		lstrcpy(m_cadBreak,lpString);
		int contt;
		int cont =contt=strlen(m_cadBreak);
		CSize coor=GetTextExtent(m_cadBreak,cont);
		if ( coor.cx > rc.Width())
		{
			rc.left+=1;
			while(cont > 1 )
			{
				TCHAR m_scadtemp[64];
				memset(m_scadtemp,0x00,64);
				lstrcpy(m_scadtemp,m_cadBreak);
				lstrcat(m_scadtemp,_T("..."));
				CSize coor=GetTextExtent(m_scadtemp,lstrlen(m_scadtemp));
				if(coor.cx > rc.Width())
					*(m_cadBreak+cont)=0;
				else
					break;
				cont--;
			}
			lstrcat(m_cadBreak,_T("..."));
			rc.right+=3;
			
				DrawText(m_cadBreak,rc,uFormatDrop);
		}
		else
				DrawText(lpString,rc,uFormatNormal);
		
	}

	static CBrush* HalftGray()
	{
		const WORD GrayBmp[] = {0x0055, 0x00AA, 0x0055, 0x00AA,
				0x0055, 0x00AA, 0x0055, 0x00AA};
		HBITMAP hGray= ::CreateBitmap(8, 8, 1, 1, &GrayBmp);
		CBrush* cb=new CBrush();
		cb->CreatePatternBrush(hGray);
		DeleteObject((HGDIOBJ)hGray);
		return cb;

	}

	
	
};

