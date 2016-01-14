#pragma once

#include "stdafx.h"
#include "CDialog.h"

class CFileOpen : public CDialog 
{
protected:
	OPENFILENAME ofn;
public:
	CFileOpen(CWin *pWin, LPCTSTR lpszDefExt = NULL,
			LPCTSTR lpszFileName = NULL,LPCSTR title=NULL,LPCSTR lpFilter=NULL,LPCSTR lpInitialDir=NULL,
			DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT)
	{
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = pWin->GetSafeHwnd();
		ofn.lpstrFilter = (LPSTR)lpFilter;
		ofn.lpstrFile = (LPSTR)lpszFileName;
		ofn.nMaxFile = MAX_PATH;
		ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
		ofn.lpstrDefExt = lpszDefExt;
		ofn.lpstrInitialDir=(LPSTR)lpInitialDir;
		ofn.Flags |= dwFlags | OFN_EXPLORER | OFN_ENABLEHOOK | OFN_ENABLESIZING;
		ofn.nMaxFileTitle = _MAX_FNAME;
	}
	
	int	DoModal(BOOL bOpenFile=TRUE)
	{ 	
		BOOL bRet;
		
		if(bOpenFile)
			bRet = ::GetOpenFileName(&ofn);
		else
			bRet = ::GetSaveFileName(&ofn);

		m_hWnd = NULL;
		
		if (bRet) return IDOK;
		
		return  IDCANCEL;
	
	}

	
	int GetFilePath(LPTSTR lpstrFilePath, int nLength) 
	{
		return (int)SendMessage(CDM_GETFILEPATH, nLength, (LPARAM)lpstrFilePath);
	}

	int GetFolderIDList(LPVOID lpBuff, int nLength) 
	{
		return (int)SendMessage(CDM_GETFOLDERIDLIST, nLength, (LPARAM)lpBuff);
	}

	int GetFolderPath(LPTSTR lpstrFolderPath, int nLength) 
	{
		return (int)SendMessage(CDM_GETFOLDERPATH, nLength, (LPARAM)lpstrFolderPath);
	}

	int GetSpec(LPTSTR lpstrSpec, int nLength)
	{
		return (int)SendMessage(CDM_GETSPEC, nLength, (LPARAM)lpstrSpec);
	}

	void SetControlText(int nCtrlID, LPCTSTR lpstrText)
	{
		SendMessage(CDM_SETCONTROLTEXT, nCtrlID, (LPARAM)lpstrText);
	}

	void SetDefExt(LPCTSTR lpstrExt)
	{
		SendMessage(CDM_SETDEFEXT, 0, (LPARAM)lpstrExt);
	}

	BOOL GetReadOnlyPref() 	
	{
		return (ofn.Flags & OFN_READONLY) ? TRUE : FALSE;
	}

	/*void HideControl(int nCtrlID)
	{
		SendMessage(CDM_HIDECONTROL, nCtrlID);
	}*/
	void setFilter(LPCSTR lpFilter)
	{
		if (lpFilter) 
			ofn.lpstrFilter=(LPSTR)lpFilter; 
	}
	
	void setDir(LPCSTR lpdir)
	{
		ofn.lpstrInitialDir=(LPSTR)lpdir; 
	}
		
	
};
