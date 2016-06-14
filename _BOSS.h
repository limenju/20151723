#pragma once
#include "DEFINE.h"
#include "PAT_INFO.h"
#include "_STAGE_INFO.h"
#include "MONSTER.h"

class BOSS : virtual public ORGANISM
{
	//int nPatType; // 패턴 형태
	//int nPatStep; // 현재 스텝  
	//int nPatIndex; // 이동 경로 인덱스
	clock_t OldTime;  // 이전 이동 시각

public:
	BOSS(){}
	
	void INIT_Boss(STAGE_INFO Stage, int g_nStage, PAT_INFO *g_BossPatInfo);
	clock_t getOldTime() { return  OldTime; }

	void set_min_Life() { nLife--; }

	void set_add_nPatType() { nPatType++; }
	void set_nPatType(int a) { nPatType = a; }
	void set_nPatStep(int a) { nPatStep = a; }
	void set_add_nPatStep() { nPatStep++; }
	void set_add_nPatIndex() { nPatIndex++; }
	void set_nPatIndex(int a) { nPatIndex = a; }

	void set_OldTime(clock_t CurTime) { OldTime = CurTime; }
	
};