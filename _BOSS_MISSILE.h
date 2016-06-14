#pragma once
#include "DEFINE.h"
#include "MONSTER.h"

class BOSS_MISSILE : virtual public ORGANISM
{
public:
	DIRECT Boss_Missile_nDirect;
	clock_t OldMoveTime;
};