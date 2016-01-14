#pragma once 

#include "stdafx.h"

class CGDI;
class CDrawLayer  
{

public:

	static COLORREF DarkenColor( long lScale, COLORREF lColor)
	{ 
	  long R = MulDiv(GetRValue(lColor),(255-lScale),255);
	  long G = MulDiv(GetGValue(lColor),(255-lScale),255);
	  long B = MulDiv(GetBValue(lColor),(255-lScale),255);

	  return RGB(R, G, B); 
	}

	
	static COLORREF GetRGBColorWhite()
	{
		return RGB(255,255,255);
	}

	

	static COLORREF GetRGBActiveBorder()
	{
		COLORREF clrPress = ::GetSysColor (COLOR_INACTIVEBORDER);
		BYTE byRvalue =GetRValue(clrPress);
		BYTE byGvalue =GetGValue(clrPress);
		BYTE byBvalue =GetBValue(clrPress);
		return RGB(byRvalue,byGvalue,byBvalue);	
	}

	static COLORREF GetRGBColorTabs()
	{
		BYTE byRvalue =GetRValue(GetRGBColorXP());
		BYTE byGvalue =GetGValue(GetRGBColorXP());
		BYTE byBvalue =GetBValue(GetRGBColorXP());
		int iMaximo=max(byRvalue,byGvalue);
		iMaximo=max(iMaximo,byBvalue);
		iMaximo= 255-iMaximo;
		iMaximo=iMaximo-(int)(iMaximo*0.51);
		return RGB(byRvalue+iMaximo,byGvalue+iMaximo,byBvalue+iMaximo);	
		
	}


	static COLORREF GetRGBSkinMenu()
	{
		BYTE byRvalue =GetRValue(CDrawLayer::GetRGBColorFace());
		BYTE byGvalue =GetGValue(CDrawLayer::GetRGBColorFace());
		BYTE byBvalue =GetBValue(CDrawLayer::GetRGBColorFace());
		byRvalue =byRvalue>>2;
		byGvalue =byGvalue>>2;
		byBvalue =byBvalue>>2;
		int iMaximo=max(byRvalue,byGvalue);
		iMaximo=max(iMaximo,byBvalue);
		iMaximo= 255-iMaximo;
		iMaximo=iMaximo-(int)(iMaximo*0.018);
		return RGB(byRvalue+iMaximo,byGvalue+iMaximo,byBvalue+iMaximo);	
		
	}

	static COLORREF GetRGBColorBTNHigh()
	{
		return ::GetSysColor(COLOR_BTNHIGHLIGHT);
	}



	static COLORREF GetRGBColorGrayText()
	{
		BYTE byRvalue =0;
		BYTE byGvalue =0;
		BYTE byBvalue =0;
		byRvalue =byRvalue>>1;
		byGvalue =byGvalue>>1;
		byBvalue =byBvalue>>1;
		int iMaximo=max(byRvalue,byGvalue);
		iMaximo=max(iMaximo,byBvalue);
		iMaximo= 255-iMaximo;
		iMaximo=iMaximo-(int)(iMaximo*0.60);
		return RGB(byRvalue+iMaximo,byGvalue+iMaximo,byBvalue+iMaximo);	
		
	}


	static COLORREF GetRGBColorFace()
	{
		return ::GetSysColor(COLOR_BTNFACE);
	}

	static COLORREF GetRGBColorShadow()
	{
		return ::GetSysColor(COLOR_BTNSHADOW);
	}

	static COLORREF GetRGBPressBXP()
	{
		
		BYTE byRvalue =GetRValue(::GetSysColor(COLOR_HIGHLIGHT));
		BYTE byGvalue =GetGValue(::GetSysColor(COLOR_HIGHLIGHT));
		BYTE byBvalue =GetBValue(::GetSysColor(COLOR_HIGHLIGHT));
		byRvalue =byRvalue>>2;
		byGvalue =byGvalue>>2;
		byBvalue =byBvalue>>2;
		int iMaximo=max(byRvalue,byGvalue);
		iMaximo=max(iMaximo,byBvalue);
		iMaximo= 255-iMaximo;
		iMaximo=iMaximo-(int)(iMaximo*0.21);
		return RGB(byRvalue+iMaximo,byGvalue+iMaximo,byBvalue+iMaximo);	
		
	}

	static COLORREF GetRGBMenu()
	{
		BYTE byRvalue =GetRValue(::GetSysColor(COLOR_HIGHLIGHT));
		BYTE byGvalue =GetGValue(::GetSysColor(COLOR_HIGHLIGHT));
		BYTE byBvalue =GetBValue(::GetSysColor(COLOR_HIGHLIGHT));
		byRvalue =byRvalue>>3;
		byGvalue =byGvalue>>3;
		byBvalue =byBvalue>>3;
		int iMaximo=max(byRvalue,byGvalue);
		iMaximo=max(iMaximo,byBvalue);
		iMaximo= 255-iMaximo;
		iMaximo=iMaximo-(int)(iMaximo*0.47);
		return RGB(byRvalue+iMaximo,byGvalue+iMaximo,byBvalue+iMaximo);	
		
	}

	static COLORREF GetRGBTitleMenu()
	{
		COLORREF clrPress = ::GetSysColor (COLOR_BTNSHADOW);

		BYTE byRvalue =GetRValue(::GetSysColor(clrPress));
		BYTE byGvalue =GetGValue(::GetSysColor(clrPress));
		BYTE byBvalue =GetBValue(::GetSysColor(clrPress));
		byRvalue =byRvalue>>2;
		byGvalue =byGvalue>>2;
		byBvalue =byBvalue>>2;
		int iMaximo=max(byRvalue,byGvalue);
		iMaximo=max(iMaximo,byBvalue);
		iMaximo= 255-iMaximo;
		iMaximo=iMaximo-(int)(iMaximo*0.8);
		return RGB(byRvalue+iMaximo,byGvalue+iMaximo,byBvalue+iMaximo);	
		
	}

	static COLORREF GetRGBCaptionXP()
	{

		BYTE byRvalue =GetRValue(::GetSysColor(COLOR_HIGHLIGHT));
		BYTE byGvalue =GetGValue(::GetSysColor(COLOR_HIGHLIGHT));
		BYTE byBvalue =GetBValue(::GetSysColor(COLOR_HIGHLIGHT));
		return RGB(byRvalue+10,byGvalue+10,byBvalue+10);	
	}

	static COLORREF GetRGBFondoXP()
	{
		BYTE byRvalue =GetRValue(::GetSysColor(COLOR_HIGHLIGHT));
		BYTE byGvalue =GetGValue(::GetSysColor(COLOR_HIGHLIGHT));
		BYTE byBvalue =GetBValue(::GetSysColor(COLOR_HIGHLIGHT));
		byRvalue =byRvalue>>2;
		byGvalue =byGvalue>>2;
		byBvalue =byBvalue>>2;
		int iMaximo=max(byRvalue,byGvalue);
		iMaximo=max(iMaximo,byBvalue);
		iMaximo= 255-iMaximo;
		iMaximo=iMaximo-(int)(iMaximo*0.14);
		return RGB(byRvalue+iMaximo,byGvalue+iMaximo,byBvalue+iMaximo);	
	}

	
	static COLORREF GetRGBGray()
	{
		BYTE byRvalue =GetRValue(::GetSysColor(COLOR_BTNSHADOW));
		BYTE byGvalue =GetGValue(::GetSysColor(COLOR_BTNSHADOW));
		BYTE byBvalue =GetBValue(::GetSysColor(COLOR_BTNSHADOW));
		byRvalue =byRvalue>>2;
		byGvalue =byGvalue>>2;
		byBvalue =byBvalue>>2;
		int iMaximo=max(byRvalue,byGvalue);
		iMaximo=max(iMaximo,byBvalue);
		iMaximo= 255-iMaximo;
		iMaximo=iMaximo-(int)(iMaximo*0.30);
		return RGB(byRvalue+iMaximo,byGvalue+iMaximo,byBvalue+iMaximo);	
		//return RGB(182,179,171);	
	}

	static BOOL IsGrayed()
	{
		BYTE byRvalue =GetRValue(::GetSysColor(COLOR_3DFACE));
		BYTE byGvalue =GetGValue(::GetSysColor(COLOR_3DFACE));
		BYTE byBvalue =GetBValue(::GetSysColor(COLOR_3DFACE));
		if (((byRvalue ==byGvalue) && (byGvalue == byBvalue) &&
			 (byBvalue > 190 && byBvalue < 193)) || (byBvalue == 216))
			return TRUE;
		else
			return FALSE;
	}

	static COLORREF GetRGBColorXP()
	{

		
		COLORREF clr3DFace = ::GetSysColor (COLOR_3DFACE);
		return RGB (((3*GetRValue (clr3DFace)+240)/4)+1,
					((3*GetGValue (clr3DFace)+240)/4)+1,
					((3*GetBValue (clr3DFace)+240)/4)+1);

	}

	static COLORREF GetRGBSemiShadow()
	{

		
		COLORREF clr3DFace = ::GetSysColor (COLOR_3DFACE);
		BYTE byRvalue =GetRValue(clr3DFace);
		BYTE byGvalue =GetGValue(clr3DFace);
		BYTE byBvalue =GetBValue(clr3DFace);
		byRvalue =byRvalue>>2;
		byGvalue =byGvalue>>2;
		byBvalue =byBvalue>>2;
		int iMaximo=max(byRvalue,byGvalue);
		iMaximo=max(iMaximo,byBvalue);
		iMaximo= 255-iMaximo;
		iMaximo=iMaximo-(int)(iMaximo*0.25);
		return RGB(byRvalue+iMaximo,byGvalue+iMaximo,byBvalue+iMaximo);	
	}
	int GetDropDownWidth()
	{
		int iSize;
		HDC hDC = GetDC(NULL);
		ASSERT(hDC != NULL);
		HFONT hFont;
		if ((hFont = CreateFont(GetSystemMetrics(SM_CYMENUCHECK), 0, 0, 0,
			FW_NORMAL, 0, 0, 0, SYMBOL_CHARSET, 0, 0, 0, 0, _T("Marlett"))) != NULL)
			hFont = (HFONT)SelectObject(hDC, hFont);
			GetCharWidth(hDC, '6', '6', &iSize);
		if (hFont != NULL)
		{
			SelectObject(hDC, hFont);
			DeleteObject(hFont);
		}
		ReleaseDC(NULL, hDC);
		ASSERT(iSize != -1);
		return iSize;
	}


	static int SWCFindChar(TCHAR Buffer[], TCHAR ch)
	{
		int i=0;
		for( i=0; i < lstrlen(Buffer); i++)
		{
			if (Buffer[i] == ch)
				break;
		}
		if (i== lstrlen(Buffer))
			return -1;
		return i;	
	}


	static void  SWCCopyRight(TCHAR BufferSrc[], int pos, char BufferTarget[])
	{
		lstrcpynA(BufferTarget,BufferSrc+pos,lstrlen(BufferSrc)-(pos-1));
		
	}

	static void  SWCCopyLeft(TCHAR BufferSrc[], int pos, char BufferTarget[])
	{
		lstrcpynA(BufferTarget,BufferSrc,pos);
	}

	//function of Bruno Podetti
	static void DrawCheck(CGDI* pDC,CRect m_rcTemp);
	static void DrawShade( CRect Rect,CPoint screen,CGDI* pDC);

};

