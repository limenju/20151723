#include "ENEMY.h"

void ENEMY::INIT_Enemy(ENEMY* g_Enemy, int g_nEnemyCount, PAT_INFO* g_PatInfo)
{
	for (int i = 0; i < g_nEnemyCount; i++)
	{
		g_Enemy[i].nLife = 0;
		g_Enemy[i].nType = rand() % 4; // 임의의 패턴 선택
		g_Enemy[i].AppearTime = 1000 * (i + 1); // 출현 시간을 오름차순으로 설정	
		g_Enemy[i].MissileFireTime = rand() % 500 + 1000;
		g_Enemy[i].MissileOldTime = clock();
		g_Enemy[i].setnPatType(rand() % 4);
		g_Enemy[i].setnPatIndex(0);
		g_Enemy[i].setnPatStep(-1);
		g_Enemy[i].nX = g_PatInfo[g_Enemy[i].getnPatType()].nX0;
		g_Enemy[i].nY = g_PatInfo[g_Enemy[i].nPatType].nY0;
		g_Enemy[i].MoveTime = g_PatInfo[g_Enemy[i].getnPatType()].pPat[0].MoveTime;
		g_Enemy[i].OldMoveTime = clock();
	}
}