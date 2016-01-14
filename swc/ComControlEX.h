#pragma once

#include "stdafx.h"
#include "ComControl.h"

class ComControlEX: public ComControl
{
	
	public:
		ComControlEX(){};
		~ComControlEX(){};
	
	public:
		
	virtual DWORD OnPrePaint( LPNMCUSTOMDRAW , BOOL &bNotify)
	{
		return CDRF_DODEFAULT;
	}
	virtual DWORD OnPostPaint( LPNMCUSTOMDRAW , BOOL &bNotify)
	{
		return CDRF_DODEFAULT;
	}
	virtual DWORD OnPreErase( LPNMCUSTOMDRAW , BOOL &bNotify)
	{
		return CDRF_DODEFAULT;
	}
	virtual DWORD OnPostErase( LPNMCUSTOMDRAW , BOOL &bNotify)
	{
		return CDRF_DODEFAULT;
	}
	virtual DWORD OnItemPrePaint( LPNMCUSTOMDRAW , BOOL &bNotify)
	{
		return CDRF_DODEFAULT;
	}
	virtual DWORD OnItemPostPaint( LPNMCUSTOMDRAW , BOOL &bNotify)
	{
		return CDRF_DODEFAULT;
	}
	virtual DWORD OnItemPreErase( LPNMCUSTOMDRAW , BOOL &bNotify)
	{
		return CDRF_DODEFAULT;
	}
	virtual DWORD OnItemPostErase( LPNMCUSTOMDRAW , BOOL &bNotify)
	{
		return CDRF_DODEFAULT;
	}

	virtual DWORD OnSubItemPrePaint( LPNMCUSTOMDRAW , BOOL &bNotify)
	{
		return CDRF_DODEFAULT;
	}
	
	
	virtual LRESULT ReflectChildNotify( LPNMHDR pNMHDR, BOOL &bNotify)
	{
		if (pNMHDR->code == (UINT)NM_CUSTOMDRAW)
		{	
      			LPNMCUSTOMDRAW lpNMCustomDraw = (LPNMCUSTOMDRAW)pNMHDR;
			switch(lpNMCustomDraw->dwDrawStage)
			{
			case CDDS_PREPAINT:
				return OnPrePaint(lpNMCustomDraw, bNotify);
				break;
			case CDDS_POSTPAINT:
				return OnPostPaint(lpNMCustomDraw, bNotify);
				break;
			case CDDS_PREERASE:
				return OnPreErase(lpNMCustomDraw,bNotify);
				break;
			case CDDS_POSTERASE:
				return OnPostErase(lpNMCustomDraw, bNotify);
				break;
			case CDDS_ITEMPREPAINT:
				return OnItemPrePaint(lpNMCustomDraw,  bNotify);
				break;
			case CDDS_ITEMPOSTPAINT:
				return OnItemPostPaint(lpNMCustomDraw, bNotify);
				break;
			case CDDS_ITEMPREERASE:
				return OnItemPreErase(lpNMCustomDraw,  bNotify);
				break;
			case CDDS_ITEMPOSTERASE:
				return OnItemPostErase(lpNMCustomDraw,  bNotify);
				break;
			#if (_WIN32_IE >= 0x0400)
			case (CDDS_ITEMPREPAINT | CDDS_SUBITEM):
				return OnSubItemPrePaint(lpNMCustomDraw,bNotify);
				break;
			#endif 
			}
		}
	else	
		return ComControl::ReflectChildNotify(pNMHDR, bNotify);
	return TRUE;
	}
};

