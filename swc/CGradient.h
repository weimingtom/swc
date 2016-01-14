#pragma once
#include "stdafx.h"

#include "CGDI.h"
#include "CBitmap.h"
#include "CSize.h"

class CGradient  
{
public:
	CGradient(CSize Size=CSize(800,600))
	{
		m_Size=Size;
		m_dcMem=NULL;
	}

	virtual ~CGradient()
	{
		if(m_dcMem!=NULL)
		{
			m_dcMem->DeleteDC();
			delete m_dcMem;
		}
	}
	CSize GetDimensions()
	{
		return m_Size;
	}

	void SetDimensions(CSize Size)
	{
		m_Size=Size;
	}

	virtual void PrepareVertical(CGDI* pDC,DWORD m_StyleDisplay=GUISTYLE_XP,COLORREF m_clr=CDrawLayer::GetRGBColorTabs(), int nRate=40)
		{
		BYTE byRvalue =GetRValue(m_clr);//+(nRate==40 ?10:(15));
		BYTE byGvalue =GetGValue(m_clr);//+(nRate==40 ?10:(15));
		BYTE byBvalue =GetBValue(m_clr);//+(nRate==40 ?10:(15));
	/*	if (m_StyleDisplay!= GUISTYLE_XP )
		{
			COLORREF clrNear=pDC->GetNearestColor(CDrawLayer::GetRGBCaptionXP());
			if (clrNear==13595707)
				PrepareVertical(pDC,222,234,253,141,178,223);
			else if(clrNear==8039069)
				PrepareVertical(pDC,243,251,221,179,194,138);
			else if(clrNear==13221564)
				PrepareVertical(pDC,248,248,250,165,160,184);
		}
		else*/
			PrepareVertical(pDC,255,255,255,byRvalue-10,byGvalue-10,byBvalue-10);
	}

	void PrepareCaption(CGDI* pDC,DWORD m_StyleDisplay=GUISTYLE_XP)
	{
		
		COLORREF clrNear=pDC->GetNearestColor(CDrawLayer::GetRGBCaptionXP());
		if (clrNear==13595707)
			PrepareVertical(pDC,222,234,253,141,178,223);
		else if(clrNear==8039069)
			PrepareVertical(pDC,243,251,221,179,194,138);
		else if(clrNear==13221564)
			PrepareVertical(pDC,248,248,250,165,160,184);
		else
		{
			PrepareVertical(pDC);
		}
	}

	void PrepareCaptionVert(CGDI* pDC,DWORD m_StyleDisplay=GUISTYLE_XP)
	{
		BYTE byRvalue ;
		BYTE byGvalue ;
		BYTE byBvalue ;
		
		if (m_StyleDisplay!= GUISTYLE_XP)
		{
			PrepareHorizontal(pDC,249,200,102,248,248,205);
			return;
		}
		else if (m_StyleDisplay == GUISTYLE_2003)
		{
			byRvalue =GetRValue(CDrawLayer::GetRGBPressBXP());
			byGvalue =GetGValue(CDrawLayer::GetRGBPressBXP());
			byBvalue =GetBValue(CDrawLayer::GetRGBPressBXP());
		}
		else
		{
			byRvalue =GetRValue(CDrawLayer::GetRGBColorShadow());
			byGvalue =GetGValue(CDrawLayer::GetRGBColorShadow());
			byBvalue =GetBValue(CDrawLayer::GetRGBColorShadow());
		}
		PrepareHorizontal(pDC,byRvalue,byGvalue,byBvalue,byRvalue-40,byGvalue-40,byBvalue-40);
	}

	void PrepareTabs(CGDI* pDC, COLORREF m_clrL,COLORREF m_clrH)
	{

		BYTE byRvalueL =GetRValue(m_clrL);
		BYTE byGvalueL =GetGValue(m_clrL);
		BYTE byBvalueL =GetBValue(m_clrL);

		BYTE byRvalueH =GetRValue(m_clrH);
		BYTE byGvalueH =GetGValue(m_clrH);
		BYTE byBvalueH =GetBValue(m_clrH);
		PrepareVertical(pDC,byRvalueL,byGvalueL,byBvalueL,byRvalueH,byGvalueH,byBvalueH);
	}
	
	void PrepareReverseVert(CGDI* pDC,DWORD m_StyleDisplay=GUISTYLE_XP, COLORREF m_clr=CDrawLayer::GetRGBColorTabs())
	{

		BYTE byRvalue =GetRValue(CDrawLayer::GetRGBColorFace());
		BYTE byGvalue =GetGValue(CDrawLayer::GetRGBColorFace());
		BYTE byBvalue =GetBValue(CDrawLayer::GetRGBColorFace());
	/*	if (m_StyleDisplay!= GUISTYLE_XP)
		{
			COLORREF clrNear=pDC->GetNearestColor(CDrawLayer::GetRGBCaptionXP());
			if (clrNear==13595707)
				PrepareVertical(pDC,141,178,223,222,234,253);
			else if(clrNear==8039069)
				PrepareVertical(pDC,179,194,138,243,251,221);
			else if(clrNear==13221564)
				PrepareVertical(pDC,165,160,184,248,248,250);
		}
		else*/
			PrepareVertical(pDC,byRvalue-40,byGvalue-40,byBvalue-40,255,255,255);
		//PrepareVertical(pDC,byRvalue-2,byGvalue-2,byBvalue-2,byRvalue,byGvalue,byBvalue);
	}

	void PrepareReverseVertTab(CGDI* pDC,DWORD m_StyleDisplay=GUISTYLE_XP, COLORREF m_clr=CDrawLayer::GetRGBColorTabs())
	{

		BYTE byRvalue =GetRValue(m_clr);
		BYTE byGvalue =GetGValue(m_clr);
		BYTE byBvalue =GetBValue(m_clr);
		if (m_StyleDisplay!= GUISTYLE_XP)
		{
			COLORREF clrNear=pDC->GetNearestColor(CDrawLayer::GetRGBCaptionXP());
			if (clrNear==13595707)
				PrepareVertical(pDC,216,228,243,255,255,255);
			else if(clrNear==8039069)
				PrepareVertical(pDC,233,237,220,255,255,255);
			else if(clrNear==13221564)
				PrepareVertical(pDC,234,233,239,255,255,255);
		}
		else
		PrepareVertical(pDC,byRvalue-10,byGvalue-10,byBvalue-10,byRvalue,byGvalue,byBvalue);
	}

	void PrepareReverseColorTab(CGDI* pDC,DWORD m_StyleDisplay=GUISTYLE_XP, COLORREF m_clrL=CDrawLayer::GetRGBColorTabs(), COLORREF m_clrH=CDrawLayer::GetRGBColorTabs())
	{

		BYTE byRvalueL =GetRValue(m_clrL);
		BYTE byGvalueL =GetGValue(m_clrL);
		BYTE byBvalueL =GetBValue(m_clrL);

		BYTE byRvalueH =GetRValue(m_clrH);
		BYTE byGvalueH =GetGValue(m_clrH);
		BYTE byBvalueH =GetBValue(m_clrH);

		PrepareVertical(pDC,byRvalueL,byGvalueL,byBvalueL,byRvalueH,byGvalueH,byBvalueH);
	}
		
	virtual void PrepareReverseHor(CGDI* pDC,COLORREF m_clr=CDrawLayer::GetRGBColorFace(),COLORREF m_clr1=CDrawLayer::GetRGBColorShadow())
	{
		BYTE byRvalue =GetRValue(m_clr);
		BYTE byGvalue =GetGValue(m_clr);
		BYTE byBvalue =GetBValue(m_clr);
		BYTE byRvalue1 =GetRValue(m_clr1);
		BYTE byGvalue1 =GetGValue(m_clr1);
		BYTE byBvalue1 =GetBValue(m_clr1);
		/*if (m_StyleDisplay!= GUISTYLE_XP)
		{
			COLORREF clrNear=pDC->GetNearestColor(CDrawLayer::GetRGBCaptionXP());
			if (clrNear==13595707)
				PrepareHorizontal(pDC,222,234,253,141,178,223);
			else if(clrNear==8039069)
				PrepareHorizontal(pDC,243,251,221,179,194,138);
			else if(clrNear==13221564)
				PrepareHorizontal(pDC,248,248,250,165,160,184);
		}
		else*/
			PrepareHorizontal(pDC,byRvalue1,byGvalue1,byBvalue1,byRvalue,byGvalue,byBvalue);
			//PrepareHorizontal(pDC,byRvalue,byGvalue,byBvalue,byRvalue-40,byGvalue-40,byBvalue-40);
		
	}
	
	virtual void PrepareHorizontal(CGDI* pDC,COLORREF m_clrBase=CDrawLayer::GetRGBColorTabs(),COLORREF m_clr=CDrawLayer::GetRGBColorFace())
	{
		BYTE byRvalue =GetRValue(m_clrBase)+10;
		BYTE byGvalue =GetGValue(m_clrBase)+10;
		BYTE byBvalue =GetBValue(m_clrBase)+10;
		(void)byRvalue;
		(void)byGvalue;
		(void)byBvalue;
		BYTE byRvalue1 =GetRValue(m_clr);
		BYTE byGvalue1 =GetGValue(m_clr);
		BYTE byBvalue1 =GetBValue(m_clr);
		PrepareHorizontal(pDC,byRvalue1-10,byGvalue1-10,byBvalue1-10,255,255,255);
	}
	
	virtual void PrepareVertical(CGDI *pDC,UINT RTop,UINT GTop,UINT BTop,UINT RBot,UINT GBot,UINT BBot)
	{
		//Here we will create a memory bitmap and draw the colored bitmap on it
		//using my pretty Algorithm for generating colors.

		//if we have already a drawn DC then delete it so we will not have a
		//memory leak

		if(m_dcMem!=NULL)
		{
			m_dcMem->DeleteDC();
			delete m_dcMem;
			
		}

		//create the Memory Bitmap
		CBitmap Bitmap;
		m_dcMem=new CGDI;	//new Device Context
		m_dcMem->CreateCompatibleDC(pDC->m_hDC);	//Make it Compatible with pDC
		m_dcMem->SetMapMode(MM_TEXT);		//Pixels Mapping Mode
		//Make the Bitmap compatible with the memory DC
		Bitmap.CreateCompatibleBitmap(pDC->m_hDC,m_Size.cx,m_Size.cy);	
		//Select the bitmap into the memory DC
		m_dcMem->SelectObject(&Bitmap);

		////////////////////////////////////////////////////////////////
		////Drawing The Gradient in a MemDC
		////////////////////////////////////////////////////////////////
		//ALGORITHM:
		//We will have the RGB values of the color at which we will start
		//and the RGB values of the color at which we will end
		//we will fill 256 rectangles using all colors that lie between
		//these two colors. this is done by moving the R,G, and B values slowly
		//from the Starting color to the Ending Color.
		//For example: if we have RTop=100 and RBot=150 then we will draw 256
		//rectangles colored with the R-values of 100,100+(150-100)/256,
		//100+2*(150-100)/256,100+3*(150-100)/256,...
		//and the same will happen to G and B values.
		
		//rStep,gStep, and bStep are variables that will be used
		//to hold the values at which R,G,B will be changed respectivily
		//For example: if we have RTop=100 and RBot=150 then 
		//rStep=(150-100)/256 so when we start at R=100 and draw 256 rectangles
		//we will end at R=150 when we finish drawing these rectangles
		double rStep,gStep,bStep;
		double rCount,gCount,bCount;
		double RectHeight=m_Size.cy/256.0;
		const int NUM_COLORS=256;
		//We will start counting from TopColor to BottomColor
		//So we give an initial value of the TopColor
		rCount=RTop;
		gCount=GTop;
		bCount=BTop;
		//Calcualte the step of R,G,B values
		rStep=-((double)RTop-RBot)/NUM_COLORS;
		gStep=-((double)GTop-GBot)/NUM_COLORS;
		bStep=-((double)BTop-BBot)/NUM_COLORS;
		for(int ColorCount=0;ColorCount<NUM_COLORS;ColorCount++)
		{
			//Draw using current RGB values and Change RGB values
			//to represent the next color in the chain
			CRect tempRect(0, ColorCount * RectHeight,
				m_Size.cx, (ColorCount + 1) * RectHeight);
			CBrush tempBrush(RGB(rCount,gCount,bCount));
			m_dcMem->FillRect((LPCRECT)tempRect, &tempBrush);
			rCount+=rStep;
			gCount+=gStep;
			bCount+=bStep;
			
		}
		Bitmap.DeleteObject();
		
	}

	void PrepareHorizontal(CGDI *pDC,UINT RLeft,UINT GLeft,UINT BLeft,UINT RRight,UINT GRight,UINT BRight)
	{
		if(m_dcMem!=NULL)
		{
			m_dcMem->DeleteDC();
			delete m_dcMem;
			
		}
		CBitmap Bitmap;
		m_dcMem=new CGDI;
		m_dcMem->CreateCompatibleDC(pDC->m_hDC);
		m_dcMem->SetMapMode(MM_TEXT);
		Bitmap.CreateCompatibleBitmap(pDC->m_hDC,m_Size.cx,m_Size.cy);
		m_dcMem->SelectObject(&Bitmap);

		////////////////////////////////////////////////////////////////
		////Drawing The Gradient in a MemDC
		double rStep,gStep,bStep;
		double rCount,gCount,bCount;
		double RectWidth=m_Size.cx/256.0;
		const int NUM_COLORS=256;
		rCount=RRight;
		gCount=GRight;
		bCount=BRight;
		rStep=-((double)RRight-RLeft)/NUM_COLORS;
		gStep=-((double)GRight-GLeft)/NUM_COLORS;
		bStep=-((double)BRight-BLeft)/NUM_COLORS;
	
		for(int ColorCount=0;ColorCount<NUM_COLORS;ColorCount++)
		{
			CRect tempRect(ColorCount * RectWidth, 0,
				(ColorCount + 1) * RectWidth, m_Size.cy);
			CBrush tempBrush(RGB(rCount,gCount,bCount));
			m_dcMem->FillRect((LPCRECT)tempRect, &tempBrush);
			rCount+=rStep;
			gCount+=gStep;
			bCount+=bStep;
		
		}
	
		Bitmap.DeleteObject();
	}

	void Draw(CGDI *pDC, int xDest,int yDest,int xSrc, int ySrc, int Width, int Height,DWORD Rop)
	{
		//Use BitBlt to Draw on a DC
		
		pDC->BitBlt(xDest,yDest,Width,Height,m_dcMem->m_hDC,xSrc,ySrc,Rop);
	

		
	}
	

protected:
	CGDI *m_dcMem;
	CSize m_Size;
	HDC memDC;


};
