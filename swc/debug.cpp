#include "stdafx.h"
#include "debug.h"

void AssertDebug(LPCSTR msg, LPCSTR file, unsigned line)
{
	char buf[80];
	/*sprintf_s*/sprintf(buf,"at line %u in file %s: \"%s\"",line,file,msg);
	if (MessageBox(NULL,buf,"ASSERTION FAILURE",
			MB_OKCANCEL|MB_ICONSTOP|MB_TASKMODAL)!=IDOK)
		exit(-1);
}
