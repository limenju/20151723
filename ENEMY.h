#pragma once
#include "DEFINE.h"
#include "PAT_INFO.h"
#include "MONSTER.h"

class ENEMY : public ORGANISM
{
public:
	ENEMY() {}
	int  nType;
	clock_t AppearTime;
	clock_t OldMoveTime;
	clock_t MissileFireTime;
	clock_t MissileOldTime;

	void setLife(int life) { nLife = life; }
	void INIT_Enemy(ENEMY* g_Enemy, int g_nEnemyCount, PAT_INFO* g_PatInfo);
};