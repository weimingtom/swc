#pragma once

#include "stdafx.h"
#include "CToolButton.h"

//FIXME: no virtual function implement!!! 
class CNormalButton :public CToolButton
{
	public:
		enum StyleBtn{STL_NORMAL=0,STL_FLAT=1,STL_SEMIFLAT=2,STL_XP=3};
	public:
		CNormalButton(void){}
		virtual ~CNormalButton(void){}
		void SetStyleButton(StyleBtn StlButton){}
	private:
		StyleBtn m_stlbtn;
	protected:
		virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/){}

    BEGIN_MSG_MAP()
	END_MSG_MAP(CToolButton)
};
