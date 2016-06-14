#include "_BOSS.h"

void BOSS::INIT_Boss(STAGE_INFO Stage, int g_nStage, PAT_INFO *g_BossPatInfo)
{
	// Note: 보스 설정
	nLife = Stage.g_nEnemyCount_nBossLife[g_nStage][1];
	nPatIndex = 0;
	nPatStep = -1;
	nPatType = 0;
	nX = g_BossPatInfo[nPatType].nX0;
	nY = g_BossPatInfo[nPatType].nY0;
	MoveTime = g_BossPatInfo[nPatType].pPat[0].MoveTime;
	OldTime = clock();
}