#include "stdafx.h"
#include "NewBValArray.h"

//see VALIDADD.CPP
BOOL AfxIsValidAddress(const void* lp, UINT nBytes, BOOL bReadWrite /* = TRUE */)
{
	// simple version using Win-32 APIs for pointer validation.
	return (lp != NULL && !IsBadReadPtr(lp, nBytes) &&
		(!bReadWrite || !IsBadWritePtr((LPVOID)lp, nBytes)));
}
