#pragma once

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#define _WIN32_IE 0x0500 

#include "swc.h"
#include "resource.h"

#if __MINGW32_MAJOR_VERSION > 3
#ifndef MINGW_VERSION_4
#define MINGW_VERSION_4 1
#endif
#endif

/*FIXME: */
#ifndef TTM_SETTITLE
#define TTM_SETTITLE TTM_SETTITLEA
#endif

/*FIXME:  see COMMCTRL.H */

#if !MINGW_VERSION_4
typedef struct tagNMKEY
{
    NMHDR hdr;
    UINT  nVKey;
    UINT  uFlags;
} NMKEY, FAR *LPNMKEY;

typedef struct tagNMCHAR {
    NMHDR   hdr;
    UINT    ch;
    DWORD   dwItemPrev;     // Item previously selected 
    DWORD   dwItemNext;     // Item to be selected
} NMCHAR, FAR* LPNMCHAR;
#endif

/*
FIXME: WINUSER.H
*/

//#if(WINVER >= 0x0500)
#define ODS_HOTLIGHT        0x0040
#define ODS_INACTIVE        0x0080
//#endif /* WINVER >= 0x0500 */


/**
COMMCTRL.H
*/
#ifndef HDM_SETHOTDIVIDER
#define HDM_SETHOTDIVIDER          (HDM_FIRST + 19)
#endif

#ifndef Header_SetHotDivider
#define Header_SetHotDivider(hwnd, fPos, dw) \
        (int)SNDMSG((hwnd), HDM_SETHOTDIVIDER, (WPARAM)fPos, (LPARAM)dw)
#endif

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif
