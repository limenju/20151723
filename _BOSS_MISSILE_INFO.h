#pragma once
#include "DEFINE.h"
#include "_BOSS_MISSILE.h"

class BOSS_MISSILE_INFO
{
public:
	clock_t MoveTime;
	clock_t FireTime;
	clock_t OldFireTime;
	BOSS_MISSILE sMissile[30];
	BOSS_MISSILE_INFO();
};
