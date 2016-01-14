#pragma once

#include <windows.h>
#include <shellapi.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <commctrl.h>
#include <commdlg.h>
#include <Time.h>
#include <stdio.h>

#define BASE_STATUS_BAR  		0x999111
#define BASE_TOOLTIPS_CLASS 	0x9112
#define BASE_TOOLBAR_CLASS  	0x9113
#define ID_MDI_FIRSTCHILD   	0x5000
#define IDC_HSPLITBAR           30980       // splitter
#define IDC_VSPLITBAR           30981       // splitter
#define RT_TOOLBAR				MAKEINTRESOURCE(241)
#define DOCK_VERT				0x999922
#define DOCK_HORZ				0x999923
#define DOCK_LEFT				0x999924
#define DOCK_RIGHT				0x999925
#define DOCK_TOP				0x999926
#define DOCK_BOTTOM				0x999927

#define BS_FLOATING			0x00234
#define BS_DOCKING			0x00235
#define BS_DOCKINGTAB		0x00236
#define BS_DOCKINGLEFT		0x00237
#define BS_DOCKINGRIGHT		0x00238
#define BS_DOCKINGBOTTOM	0x00239

//#define WINNT     0x01
#define WIN2000   0x02
#define WINXP     0x03

#ifndef WS_EX_LAYERED
#define WS_EX_LAYERED           0x00080000
#define LWA_COLORKEY            0x00000001
#define LWA_ALPHA               0x00000002
#endif // ifndef WS_EX_LAYERED

//#pragma comment(lib, "comctl32.lib")











#define 	GUISTYLE_XP   0x08001 	
#define		GUISTYLE_2003 0x08002
#define		GUISTYLE_2003MENUBTN 0x08021
#define		WIN_NT		  0x08003 	
#define		WIN_2000	0x08004
#define		WIN_XP		0x08005
#define		WIN_95		0x08006
#define		WIN_98		0x08007
#define		WIN_32		0x08008
#define		WIN_ME		0x08009
#define		WIN_95OSR2	0x0800A
#define		WIN_98_SE	0x0800B













#define BS_ALIGN_LEFT	0x3100L
#define BS_ALIGN_BOTTOM	0x3101L
#define BS_ALIGN_RIGHT	0x3102L
#define BS_ALIGN_FLOAT	0x3103L

#define BS_ALIGN_VERT	0x3104L
#define BS_ALIGN_HORZ	0x3105L


#define BS_BORDER_LEFT	0x3106L
#define BS_BORDER_TOP	0x3107L
#define BS_BORDER_RIGHT	0x3108L

#define BS_SPLIT_VERT	0x3109L
#define BS_SPLIT_HORTZ	0x3110L

#define BS_AUTO_LEFT	0x3111L
#define BS_AUTO_BOTTOM	0x3112L
#define BS_AUTO_RIGHT	0x3113L
#define BS_AUTO_FLOAT	0x314L

