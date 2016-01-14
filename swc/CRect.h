#pragma once

#include "stdafx.h"
#include "CPoint.h"
#include "CSize.h"

class CRect : public RECT
{
public:
	CRect(){ CRect (0,0,0,0);}

	CRect (CPoint ptLt, CPoint ptBr)
	{
		CRect(ptLt.x,ptLt.y,ptBr.x,ptBr.y);	
	}

	CRect (int x, int y, int Right, int Bottom)
	{
		left=x;
		top=y;
		right=Right;
		bottom=Bottom;
	}
	
	CRect(POINT point, SIZE size)
	{ right = (left = point.x) + size.cx; bottom = (top = point.y) + size.cy; }
	CRect(POINT topLeft, POINT bottomRight)
	{ left = topLeft.x; top = topLeft.y;right = bottomRight.x; bottom = bottomRight.y; }
	
	CRect(const RECT& srcRect)
	{	::CopyRect(this, &srcRect); }

	inline int  Width()	{	return (int )right-left;}

	inline int Height()	{	return (int )bottom-top;}
	
	inline CSize Size() 			{ return CSize(right - left, bottom - top); }
	inline CPoint  TopLeft()			{ return CPoint(top,left); }
	inline CPoint  BottomRight()		{ return CPoint(bottom,right); }
	
	inline CPoint  CenterPoint() 	{ return CPoint((left + right) / 2, (top + bottom) / 2); }
	inline operator LPRECT()			{ return this; }
	inline operator LPCRECT() 	{ return this; }
	inline BOOL  IsRectEmpty() 	{ return ::IsRectEmpty(this); }
	inline BOOL  IsRectNull() 	{ return (left == 0 && right == 0 && top == 0 && bottom == 0); }
	inline BOOL  PtInRect(POINT point) 		{ return ::PtInRect(this, point); }
	inline void  SetRect(int x1, int y1, int x2, int y2)	{ ::SetRect(this, x1, y1, x2, y2); }
	inline void  SetRect(POINT topLeft, POINT bottomRight)	{ ::SetRect(this, topLeft.x, topLeft.y, bottomRight.x, bottomRight.y); }
	inline void  SetRectEmpty()		{ ::SetRectEmpty(this); }
	inline void  CopyRect(LPCRECT lpSrcRect)		{ ::CopyRect(this, lpSrcRect); }
	inline BOOL  EqualRect(LPCRECT lpRect) 	{ return ::EqualRect(this, lpRect); }
	inline void  InflateRect(int x, int y)			{ ::InflateRect(this, x, y); }
	inline void  InflateRect(SIZE size)			{ ::InflateRect(this, size.cx, size.cy); }
	inline void  DeflateRect(int x, int y)			{ ::InflateRect(this, -x, -y); }
	inline void  DeflateRect(SIZE size)			{ ::InflateRect(this, -size.cx, -size.cy); }
	inline void  OffsetRect(int x, int y)			{ ::OffsetRect(this, x, y); }
	inline void  OffsetRect(POINT point)			{ ::OffsetRect(this, point.x, point.y); }
	inline void  OffsetRect(SIZE size)				{ ::OffsetRect(this, size.cx, size.cy); }
	inline BOOL  IntersectRect(LPCRECT lpRect1, LPCRECT lpRect2)	{ return ::IntersectRect(this, lpRect1, lpRect2);}
	inline BOOL  UnionRect(LPCRECT lpRect1, LPCRECT lpRect2)		{ return ::UnionRect(this, lpRect1, lpRect2); }
	inline void  operator=( RECT& srcRect)					{ ::CopyRect(this, &srcRect); }
	inline BOOL  operator==( RECT& rect) 				{ return ::EqualRect(this, &rect); }
	inline BOOL  operator!=( RECT& rect) 				{ return !::EqualRect(this, &rect); }
	inline void  operator+=(POINT point)							{ ::OffsetRect(this, point.x, point.y); }
	inline void  operator+=(SIZE size)								{ ::OffsetRect(this, size.cx, size.cy); }
	inline void  operator+=(LPCRECT lpRect)						{ InflateRect(lpRect); }
	inline void  operator-=(POINT point)							{ ::OffsetRect(this, -point.x, -point.y); }
	inline void  operator-=(SIZE size)								{ ::OffsetRect(this, -size.cx, -size.cy); }
	inline void  operator-=(LPCRECT lpRect)						{ DeflateRect(lpRect); }
	inline void  operator&=( RECT& rect)						{ ::IntersectRect(this, this, &rect); }
	inline void  operator|=( RECT& rect)						{ ::UnionRect(this, this, &rect); }
	inline CRect  operator+(POINT pt) 	{ CRect rect(*this); ::OffsetRect(&rect, pt.x, pt.y); return rect; }
	inline CRect  operator-(POINT pt) 	{ CRect rect(*this); ::OffsetRect(&rect, -pt.x, -pt.y); return rect; }
	inline CRect  operator+(SIZE size) 	{ CRect rect(*this); ::OffsetRect(&rect, size.cx, size.cy); return rect; }
	inline CRect  operator-(SIZE size) 	{ CRect rect(*this); ::OffsetRect(&rect, -size.cx, -size.cy); return rect; }
	inline BOOL  SubtractRect(LPCRECT lpRectSrc1, LPCRECT lpRectSrc2)	{ return ::SubtractRect(this, lpRectSrc1, lpRectSrc2); }
	inline CRect operator&(const RECT& rc) { CRect rect; ::IntersectRect(&rect, this, &rc);	return rect; }
	inline CRect operator|(const RECT& rc)	{ CRect rect; ::UnionRect(&rect, this, &rc); return rect; }
	
	inline void  InflateRect(LPCRECT lpRect)
	{
		left -= lpRect->left;
		top -= lpRect->top;
		right += lpRect->right;
		bottom += lpRect->bottom;
	}

	inline void  InflateRect(int l, int t, int r, int b)
	{
		left -= l;
		top -= t;
		right += r;
		bottom += b;
	}

	inline void  DeflateRect(LPCRECT lpRect)
	{
		left += lpRect->left;
		top += lpRect->top;
		right -= lpRect->right;
		bottom -= lpRect->bottom;
	}

	inline void  DeflateRect(int l, int t, int r, int b)
	{
		left += l;
		top += t;
		right -= r;
		bottom -= b;
	}

	inline CRect  MulDiv(int nMultiplier, int nDivisor) 
	{
		return CRect(
			::MulDiv(left, nMultiplier, nDivisor),
			::MulDiv(top, nMultiplier, nDivisor),
			::MulDiv(right, nMultiplier, nDivisor),
			::MulDiv(bottom, nMultiplier, nDivisor));
	}
};
