#pragma once

#include "stdafx.h"
#include "cpoint.h"

class CSize : public SIZE
{
public:
	//------------------------------------------------
	CSize()
	{cx=0; cy=0;}
	CSize(SIZE sz)
	{cx=sz.cx; cy=sz.cy;}
	CSize(long x, long y)
	{cx=x; cy=y;}

	//------------------------------------------------
	inline BOOL operator==(SIZE size) 
	{ return (size.cx== cx && size.cy == cy);	}
	inline BOOL operator!=(SIZE size) 
	{ return (size.cx != cx && size.cy != cy);	}	
	inline void operator+=(SIZE size)
	{ cx += size.cx; cy+=size.cy;}	
	inline void operator-=(SIZE size)
	{ cx -= size.cx; cy-=size.cy;}	
	
	//------------------------------------------------
	inline CSize operator+(SIZE size) 
	{return CSize (cx+size.cx,cy+size.cy);}
	

	inline CSize operator-(SIZE size) 
	{	return CSize (cx-size.cx,cy-size.cy);	}

	inline CSize operator-() 
	{ return CSize(-cx, -cy); }

	//------------------------------------------------
	inline CPoint operator+(POINT point) ;
	inline CPoint operator-(POINT point) ;

};

CPoint CSize::operator+(POINT point) { return CPoint(point.x+cx, point.y+cy);}
CPoint CSize::operator-(POINT point) { return CPoint(point.x-cx, point.y-cy);}

