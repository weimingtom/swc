#pragma once

#include "stdafx.h"
#include "CListView.h"

class COutputList : public CListView
{
public:
	COutputList(){};
	virtual ~COutputList(){};
	void  OnWindowPosChanging(WINDOWPOS* lpwndpos)
	{
		Default();
		ShowScrollBar (SB_HORZ, FALSE);
		//ModifyStyle (WS_HSCROLL, 0, SWP_DRAWFRAME);
	}
protected:
	
	BEGIN_MSG_MAP()
		ON_WM_WINDOWPOSCHANGING(OnWindowPosChanging)
	END_MSG_MAP(CListView)
};
