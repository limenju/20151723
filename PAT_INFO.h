#pragma once

#include "DEFINE.h"
#include "PAT.h"

class PAT_INFO
{
public:
	int nCount;      // 패턴 개수
	int nX0, nY0;    // 시작 좌표
	PAT *pPat;       // 패턴 
};
