#pragma once

#include <commctrl.h>
#include "stdafx.h"
#include "CWin.h"

class ComControl: public CWin
{
public:
	ComControl(){}
	virtual ~ComControl()	{}

public:	
	virtual BOOL OnChar(	LPNMCHAR pChar, BOOL &bNotify) {return FALSE; }
	virtual BOOL OnClick( LPNMHDR pNMHDR, BOOL &bNotify){return FALSE;}
	virtual BOOL OnCustomDraw( LPNMCUSTOMDRAW pCustomDraw, BOOL &bNotify)	{ return CDRF_DODEFAULT; }
	virtual BOOL OnDblclk( LPNMHDR pNMHDR, BOOL &bNotify){ return FALSE;}
	virtual BOOL OnHover( LPNMHDR pNMHDR, BOOL &bNotify){ return FALSE;}
	virtual BOOL OnKeydown( MY_LPNMKEY pKey, BOOL &bNotify){ return FALSE;}
	virtual BOOL OnKillFocus( LPNMHDR pNMHDR, BOOL &bNotify){ return FALSE;}
	virtual BOOL OnNCHitTest( LPNMMOUSE pMouse, BOOL &bNotify){ return FALSE;}
	virtual BOOL OnOutOfMemory( LPNMHDR pNMHDR, BOOL &bNotify){ return FALSE;}
	virtual BOOL OnRClick( LPNMHDR pNMHDR, BOOL &bNotify){ return FALSE;}
	virtual BOOL OnRDblclk( LPNMHDR pNMHDR, BOOL &bNotify){ return FALSE;}
	virtual BOOL OnReleasedCapture( LPNMHDR pNMHDR, BOOL &bNotify){ return FALSE;}
	virtual BOOL OnReturn( LPNMHDR pNMHDR, BOOL &bNotify){ return FALSE;}
	virtual BOOL OnSetCursor( LPNMMOUSE pMouse, BOOL &bNotify){ return FALSE; }
	virtual BOOL OnSetFocus( LPNMHDR pNMHDR, BOOL &bNotify)	{ return FALSE;}
//	virtual BOOL OnToolTipsCreated( LPNMTOOLTIPSCREATED pToolTipsCreated){ return FALSE;}
	
	virtual LRESULT ReflectChildNotify( LPNMHDR pNMHDR, BOOL &bNotify)
	{
		switch ( pNMHDR->code )
		{
			case	NM_CHAR:	    
				return OnChar(( LPNMCHAR )pNMHDR , bNotify);
			case	NM_CLICK:	    
				return OnClick( pNMHDR ,  bNotify);
			case	NM_CUSTOMDRAW:	    
				return OnCustomDraw( (LPNMCUSTOMDRAW) pNMHDR, bNotify);
			case	NM_DBLCLK:	    
				return OnDblclk( pNMHDR , bNotify);
			case	NM_HOVER:	    
				return OnHover( pNMHDR , bNotify);
			case	NM_KEYDOWN:	    
				return OnKeydown(( MY_LPNMKEY )pNMHDR , bNotify);
			case	NM_KILLFOCUS:	    
				return OnKillFocus( pNMHDR ,  bNotify);
			case	NM_NCHITTEST:	    
				return OnNCHitTest(( LPNMMOUSE )pNMHDR , bNotify);
			case	NM_OUTOFMEMORY:    
				return OnOutOfMemory( pNMHDR ,bNotify);
			case	NM_RCLICK:	    
				return OnRClick( pNMHDR ,bNotify);
			case	NM_RDBLCLK:	    
				return OnRDblclk( pNMHDR , bNotify);
			case	NM_RELEASEDCAPTURE: 
				return OnReleasedCapture( pNMHDR ,  bNotify);
			case	NM_RETURN:	    
				return OnReturn( pNMHDR , bNotify);
			case	NM_SETCURSOR:	    
				return OnSetCursor(( LPNMMOUSE )pNMHDR ,  bNotify);
			case	NM_SETFOCUS:	    
				return OnSetFocus( pNMHDR , bNotify);
//			case	NM_TOOLTIPSCREATED: 
//				return OnToolTipsCreated(( LPNMTOOLTIPSCREATED )pNMHDR );
		}
		return FALSE;
	}
};
