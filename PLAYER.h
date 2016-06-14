#pragma once
#include "DEFINE.h"
#include "MONSTER.h"

class PLAYER : public ORGANISM
{
	clock_t FireTime;      // 미사일 발사 시간 간격
	clock_t OldFireTime;   // 이전 미사일 발사 시각

	clock_t OldTime;	// 이전 이동 시각
public:
	PLAYER();
	clock_t getOldTime() { return  OldTime; }
	clock_t getFireTime() { return  FireTime; }
	clock_t getOldFireTime() { return  OldFireTime; }

	void set_min_Life() { nLife--; }
	void set_add_X() { nX++; }
	void set_min_X() { nX--; }
	void set_OldTime(clock_t CurTime) { OldTime = CurTime; }
	void set_OldFireTime(clock_t CurTime) { OldFireTime = CurTime; }
};