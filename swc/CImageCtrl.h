#pragma once

#include "stdafx.h"
#include "CBitmap.h"
#include "CApp.h"

class CImageCtrl
{
	HIMAGELIST m_hImageList;
public:
	CImageCtrl(HIMAGELIST hImageList=NULL){ m_hImageList=hImageList;};
	~CImageCtrl(){ Destroy();};
public:

	operator HIMAGELIST() {return m_hImageList;}
	
	BOOL Create(int cx, int cy, UINT flags, int cInitial, int cGrow)
	{
		if (m_hImageList != NULL) return FALSE;
		m_hImageList=ImageList_Create(cx,cy, flags,cInitial, cGrow);
		if (m_hImageList== NULL)
			return FALSE;
		return TRUE;
	}

	BOOL CreateColor(UINT uTb, int nBtnIni=-1) 
	{
		
		BITMAP		bmp;
		HGDIOBJ hBmp=::LoadImage(theApp->GetInstance(),MAKEINTRESOURCE(uTb),IMAGE_BITMAP,0,0,LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
        //FIXME:
        //if (hBmp == NULL) {
        //    return FALSE;
        //}
		::GetObject(hBmp, sizeof(BITMAP), &bmp);
		RGBTRIPLE *pRbg= (RGBTRIPLE*) (bmp.bmBits);
		if (nBtnIni == -1)
			nBtnIni=bmp.bmWidth/bmp.bmBitsPixel;
		WORD cClrBits = (WORD)(bmp.bmPlanes * bmp.bmBitsPixel); 

		if (cClrBits == 1) 
			cClrBits = 1; 
		else if (cClrBits <= 4) 
			cClrBits = ILC_COLOR4; 
		else if (cClrBits <= 8) 
			cClrBits = ILC_COLOR8; 
		else if (cClrBits <= 16) 
			cClrBits = ILC_COLOR16; 
		else if (cClrBits <= 24) 
			cClrBits = ILC_COLOR24; 
		else cClrBits = ILC_COLOR32; 

		if(!Create(bmp.bmHeight,bmp.bmHeight,cClrBits|ILC_MASK,nBtnIni,0))
			return FALSE;
		if(Add((HBITMAP)hBmp,RGB(pRbg[0].rgbtRed,pRbg[0].rgbtGreen,pRbg[0].rgbtBlue))==-1)
			return FALSE;
		
		return TRUE;
	}

	HIMAGELIST GetImageHandle()
				{
					return m_hImageList;
				}
	
	BOOL Create( UINT nBitmapID, int cx, int nGrow, COLORREF crMask )
	{
		if (m_hImageList != NULL) return FALSE;
		return Create( MAKEINTRESOURCE(nBitmapID), cx, nGrow,crMask );
	}

	BOOL Create( LPCTSTR lpszBitmapID, int cx, int nGrow, COLORREF crMask )
	{
		if (m_hImageList != NULL) return FALSE;
		m_hImageList = ImageList_LoadBitmap(theApp->GetInstance(), lpszBitmapID, cx, nGrow, crMask);
		return (m_hImageList != NULL) ? TRUE : FALSE;
	}

	BOOL Destroy()
	{
		return ImageList_Destroy(m_hImageList);
	}

	BOOL Attach(HIMAGELIST hNewImageList)
	{
		if (m_hImageList != NULL || hNewImageList == NULL) return FALSE;
		m_hImageList = hNewImageList;
		return TRUE;
	}
	
	HIMAGELIST Detach()
	{
		HIMAGELIST hNewImageList = m_hImageList;
		m_hImageList = NULL;
		return hNewImageList;
	}

	int GetImageCount()
	{
		if (m_hImageList== NULL) return -1;
			return ImageList_GetImageCount(m_hImageList);
	}

	BOOL GetImageInfo(int nImage,IMAGEINFO* pImageInfo)
	{
		return ImageList_GetImageInfo(m_hImageList, nImage, pImageInfo);
	}
	

#if (_WIN32_IE >= 0x0300)
	int SetImageCount(UINT wNewCount)
	{
		if (m_hImageList== NULL) return -1;
		return ImageList_SetImageCount(m_hImageList,wNewCount);
	}
#endif

	int Add(HBITMAP hbmImage, HBITMAP hbmMask)
	{
		if (m_hImageList== NULL) return -1;
		return ImageList_Add(m_hImageList,hbmImage,hbmMask);
	}

	int Add(CBitmap* pbmImage, COLORREF crMask)
	{
		ASSERT(m_hImageList != NULL); 
		return ImageList_AddMasked(m_hImageList, (HBITMAP)pbmImage->GetSafeHandle(), crMask); 
	}

	int Add(HBITMAP hImage, COLORREF crMask)
	{
		ASSERT(m_hImageList != NULL); 
		return ImageList_AddMasked(m_hImageList, (HBITMAP)hImage, crMask); 
	}
	
	int ReplaceIcon(int i,HICON hicon)
	{
		if (m_hImageList== NULL) return -1;
		return ImageList_ReplaceIcon(m_hImageList,i, hicon);
	}

	int AddIcon(HICON hicon)
	{
		if (m_hImageList== NULL) return -1;
		return ImageList_ReplaceIcon(m_hImageList,-1, hicon);
	}
	
	COLORREF SetBkColor(COLORREF clrBk)
	{
		if (m_hImageList== NULL) return -1;
		return ImageList_SetBkColor(m_hImageList, clrBk);
	}

	COLORREF GetBkColor()
	{
		if (m_hImageList== NULL) return -1;
		return ImageList_GetBkColor(m_hImageList);
	}
	
	COLORREF SetOverlayImage(int iImage,int iOverlay)
	{
		if (m_hImageList== NULL) return -1;
		return ImageList_SetOverlayImage(m_hImageList,iImage,iOverlay);
	}

	BOOL Draw(int iImage, HDC hdcDst, int x, int y, UINT fStyle)
	{
		if (m_hImageList== NULL || hdcDst == NULL ) return FALSE;
		return ImageList_Draw(m_hImageList, iImage, hdcDst, x, y, fStyle);
	}

	BOOL Draw(int iImage, HDC hdcDst, POINT pt, UINT fStyle)
	{
		if (m_hImageList== NULL || hdcDst == NULL ) return FALSE;
		return Draw(iImage,hdcDst, pt.x, pt.y,fStyle);
	}


	BOOL Replace(int iImage, HBITMAP hbmImage, HBITMAP hbmMask)
	{
		if (m_hImageList== NULL) return FALSE;
		return ImageList_Replace(m_hImageList, iImage, hbmImage,hbmMask);
	}

	int AddMasked( HBITMAP hbmImage, COLORREF crMask)
	{
		if (m_hImageList== NULL) return -1;
		return ImageList_AddMasked(m_hImageList,hbmImage,crMask);
	}


	BOOL DrawEx(int iImage, HDC hdcDst, int x, int y, int dx, int dy, COLORREF rgbBk, COLORREF rgbFg, UINT fStyle)
	{
		 if (m_hImageList== NULL) return FALSE;
		 return ImageList_DrawEx(m_hImageList,iImage,hdcDst,x,y,dx,dy,rgbBk,rgbFg,fStyle);
	}

	
#if (_WIN32_IE >= 0x0300)
	
	BOOL DrawIndirect(IMAGELISTDRAWPARAMS* pimldp)
	{
		return ImageList_DrawIndirect(pimldp);
	}
#endif
	
	BOOL Remove(int iImage)
	{
		 if (m_hImageList== NULL) return FALSE;
		 return ImageList_Remove(m_hImageList, iImage);
	}

	BOOL RemoveAll()
	{
		if (m_hImageList== NULL) return FALSE;
		return ImageList_Remove(m_hImageList, -1);
	}

	HICON GetIcon(int iImage,UINT flags)
	{
		if (m_hImageList== NULL) return NULL;
		return ImageList_GetIcon(m_hImageList,iImage,flags);
	}

	
#if (_WIN32_IE >= 0x0300)
	BOOL Copy(int iDst, HIMAGELIST himlSrc, int iSrc, UINT uFlags)
	{
		if (m_hImageList== NULL || himlSrc== NULL ) return FALSE;
		return ImageList_Copy(m_hImageList, iDst,himlSrc,iSrc, uFlags);
	}

	BOOL Copy(int iDst, int iSrc, UINT uFlags)
	{
		if (m_hImageList== NULL ) return FALSE;
		return ImageList_Copy(m_hImageList, iDst,m_hImageList,iSrc, uFlags);
	}
#endif

	BOOL BeginDrag(int iTrack, int dxHotspot, int dyHotspot)
	{
		if (m_hImageList== NULL ) return FALSE;
		return ImageList_BeginDrag(m_hImageList, iTrack, dxHotspot,dyHotspot);
	}
	
	static void EndDrag()
	{
		ImageList_EndDrag();
	}
	

	static BOOL DragEnter(HWND hWndLock,int x, int y)
	{
		if (::IsWindow(hWndLock)) return FALSE;
		return ImageList_DragEnter(hWndLock, x, y);
	}

	static BOOL DragLeave(HWND hWndLock)
	{
		if (::IsWindow(hWndLock)) return FALSE;
		return ImageList_DragLeave( hWndLock);
	}
	
	static BOOL DragLeave(int x, int y)
	{
		return ImageList_DragMove( x, y);
	}
	
	static BOOL DragMove(int x, int y)
	{
		return ImageList_DragMove( x, y);
	}

	BOOL SetDragCursorImage(int iDrag, int dxHotspot, int dyHotspot)
	{
		if (m_hImageList== NULL ) return FALSE;
		return ImageList_SetDragCursorImage(m_hImageList,iDrag,dxHotspot, dyHotspot);
	}

	BOOL  ImageList_DragShowNolock(BOOL fShow)
	{
		return ImageList_DragShowNolock(fShow);
	}

	static HIMAGELIST GetDragImage(POINT FAR* ppt,POINT FAR* pptHotspot)
	{
		return ImageList_GetDragImage(ppt,pptHotspot);
	}

	HICON ExtractIcon( int iImage)
	{
		return GetIcon(iImage,0);
	}
	
	HIMAGELIST LoadBitmap(LPCTSTR lpszBitmapID,int cx,int nGrow, COLORREF crMask)
	{
		return ImageList_LoadBitmap(theApp->GetInstance(), lpszBitmapID, cx, nGrow, crMask);	
	}


#ifdef __IStream_INTERFACE_DEFINED__
	
	static HIMAGELIST Read(LPSTREAM pstm)
	{
		return ImageList_Read(pstm);
	}
	
	BOOL  Write(LPSTREAM pstm)
	{
		if (m_hImageList== NULL ) return FALSE;
		return ImageList_Write(m_hImageList,pstm);
	}
	
#endif

	BOOL GetIconSize(int FAR *cx, int FAR *cy)
	{
		if (m_hImageList== NULL ) return FALSE;
		return ImageList_GetIconSize(m_hImageList,cx, cy);
	}

	BOOL SetIconSize(int cx, int cy)
	{
		if (m_hImageList== NULL ) return FALSE;
		return ImageList_SetIconSize(m_hImageList,cx, cy);
	}

	BOOL GetIconSize(int &cx, int &cy)
	{
		if (m_hImageList== NULL ) return FALSE;
		return ImageList_GetIconSize(m_hImageList,&cx, &cy);
	}

	HIMAGELIST Merge(int i1, HIMAGELIST himl2, int i2, int dx, int dy)
	{
		if (m_hImageList== NULL ) return NULL;
		return ImageList_Merge(m_hImageList, i1,himl2,i2,dx, dy);
	}

#if (_WIN32_IE >= 0x0400)
	static HIMAGELIST  Duplicate(HIMAGELIST himl)
	{
		if (himl== NULL ) return NULL;
		return ImageList_Duplicate(himl);
	}
	
	HIMAGELIST  Duplicate()
	{
		if (m_hImageList== NULL ) return NULL;
		return ImageList_Duplicate(m_hImageList);
	}
#endif
};
