#pragma once

#include "stdafx.h"

#ifdef DEBUG
#	define ASSERT (object)	((void)((object) || (AssertDebug(#object,__FILE__,__LINE__),1)))
#else
#	define ASSERT(nothing)	((void)0);
#endif

extern void AssertDebug(LPCSTR msg, LPCSTR file, unsigned line);
