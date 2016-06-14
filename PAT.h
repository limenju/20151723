#pragma once
#include "DEFINE.h"

class PAT
{
public:
	DIRECT nDirect;    // 이동 방향
	int nStep;         // 스텝
	clock_t MoveTime;  // 이동 시간 간격
	int nDist;         // 이동 거리
};