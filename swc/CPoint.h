#pragma once

#include "stdafx.h"

class CSize;
class CPoint : public POINT
{
public:

	//-------------------------------------------------
	CPoint (long  lx, long ly)
	{ x=lx; y=ly;}
	CPoint(){ x=0; y=0;}
	CPoint(POINT pt)
	{x=pt.x; y=pt.y;}

	CPoint(DWORD dwPoint)
	{
		x = (short)LOWORD(dwPoint);
		y = (short)HIWORD(dwPoint);
	}
	operator POINT() {return (POINT)(*this);}
	//-------------------------------------------------
	inline BOOL operator==(POINT point) 
	{return (point.x== x && point.y==y);}
	inline BOOL operator!=(POINT point) 
	{return (point.x!= x && point.y!=y);}
	inline void operator+=(SIZE size)
	{ x+=size.cx; y+=size.cy;}
	inline void operator-=(SIZE size)
	{ x-=size.cx; y-=size.cy;}
	inline void operator+=(POINT point)
	{ x+=point.x; y+=point.y;}
	inline void operator-=(POINT point)
	{ x-=point.x; y-=point.y;}

	//-------------------------------------------------
	inline CPoint operator+(SIZE size) 
	{return CPoint(size.cx+x,size.cy+y);}
	inline CPoint operator-(SIZE size) 
	{return CPoint(size.cx-x,size.cy-y);}
	inline CPoint operator-() 
	{return CPoint(-x,-y);}
	inline CPoint operator+(POINT point) 
	{return CPoint(point.x+x,point.y+y);}

	//-------------------------------------------------
//	inline CSize operator-(POINT point) 
//	{return CSize(x-point.x,y-point.y);}

};
