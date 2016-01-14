#pragma once 

#include "stdafx.h"
#include "CMenu.h"
#include "CSize.h"
#include "CImageCtrl.h"
#include "CBitmap.h"
#include "CWin.h"

class CMenuSpawn  
{
public:
	struct ToolBarData	
	{ // struct for toolbar resource; guess you already know it ;)
		WORD wVersion;
		WORD wWidth;			
		WORD wHeight;			
		WORD wItemCount;		
	};
	struct SpawnItem
	{
		int		iImageIdx;
		int		iCmd;
		char	cText[128];
		
	};
	struct ImageItem
	{
		int		iImageIdx;
		int		iCmd;
	};

	struct FlotMenu
	{
		int iCmd;
		int Width;
		int iSubMenu;
	};

public:
	bool IsSpawnMenu(CMenu pMenu, const int iItem, const bool bByPos);
	bool GetMenuItemText(LPSTR csText, CMenu * pMenu, const int cmd, bool bByPos);
	void SetBackBitmap(const int iRes, COLORREF crBackColor);
	void SetBackBitmap(const int iRes);
	void SetTextColor(const COLORREF crNormal, const COLORREF crSelected);
	bool FindKeyboardShortcut(UINT nChar, UINT nFlags, HMENU pMenu, LRESULT &lRes);
	bool SetFont(LOGFONT * lf);
	
	HFONT	hMenuFont, hGuiFont;
	CSize szImage;
	bool MeasureItem(LPMEASUREITEMSTRUCT lpm);
	bool DrawItem(LPDRAWITEMSTRUCT lp);
	int FindImageItem(const int cmd);
	SpawnItem * AddSpawnItem(const char * txt, const int cmd);
	void RemapMenu(HMENU pMenu);
	void AddImageItem(const int idx, WORD cmd);

	CImageCtrl ilList;
	CImageCtrl ilOther;

	COLORREF crMenuText, crMenuTextSel;
	COLORREF cr3dFace, crMenu, crHighlight, cr3dHilight, cr3dShadow, crGrayText;
	COLORREF m_clrBtnFace, m_clrBtnHilight, m_clrBtnShadow;

	int iSpawnItem;
	SpawnItem ** pSpawnItem;

	int iImageItem;
	ImageItem * pImageItem;
	FlotMenu  fltMenu;
	bool bIsPopup;
	bool bBackBitmap;
	CBitmap	bmpBack;

	bool LoadToolBarResource(unsigned int resId, UINT uBitmap=-1);
	bool AddToolBarResource(unsigned int resId, UINT uBitmap=-1);
	void EnableMenuItems(CMenu * pMenu, CWin * pParent);
	CMenuSpawn();
	CMenuSpawn(const bool _IsPopup);
	virtual ~CMenuSpawn();

protected:
	void Init();
};
