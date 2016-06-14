#pragma once
#include "MainScene.h"
#include "Define.h"

#include "_BOSS.h"
#include "_BOSS_MISSILE.h"
#include "_BOSS_MISSILE_INFO.h"

#include "_ENEMY_MISSILE.h"
#include "ENEMY.h"

#include "PLAYER.h"
#include "PLAYER_MISSILE.h"

#include "_STAGE_INFO.h"

#include "PAT.h"
#include "PAT_INFO.h"

#include "Sogo_Draw.h"

#include "Screen.h"

const int MISSILE_MOVE_TIME = 100;
const int  HERO_MISSILE = 5;

class Sogo_Play : public MainScene
{
	_ENEMY_MISSILE g_EnemyMissile[100];   // 적 미사일 버퍼
	MISSILE g_PlayerMissile[HERO_MISSILE];	//플레이어 미사일 버퍼
	BOSS_MISSILE_INFO g_sBossMissile;

	STAGE_INFO Stage;

	PAT_INFO *g_PatInfo;
	PAT_INFO *g_BossPatInfo;

	clock_t g_StartTime;
	clock_t g_nLimitTime;

	Sogo_Draw* draw_Sceen;

	int g_nEnemyIndex; // 적 캐릭터 출현 인덱스
	int g_nEnemyCount; // 적 캐릭터 수

	char g_EnemyType[4][3] = { "♨", "◆", "☎", "▣" };

	GAME_STATE		g_nGameState = INIT;
	int				g_nStage = -1;
	int				g_nGrade = 0; // 점수 
	int				g_nTotalGrade = 0; // 총점
	clock_t			g_GameStartTime, g_UpdateOldTime, g_RemainTime;
	int g_nPatCount;
	int g_nDeadEnemy;
	int g_nBossPatCount;

	PLAYER g_Player;		//플레이어
	BOSS g_Boss;		//보스
	ENEMY g_Enemy[50];		//적
	ENEMY* EnemyMaster;
public:
	Sogo_Play();
	Sogo_Play(int x) {}
	void Init();
	int Render();
	void Update();
	void Release();
	void Draw();

	void SoundInit();
	void SoundRelease();
	int Collision(int nX1, int nY1, int nX2, int nY2, int nX3, int nY3, int nX4, int nY4);
	void PatInit();
	// 주인공 미사일입장에서 보스와 보스 미사일 충돌
	void PlayerMissileBossCollision();
	// 보스 미사일 입장에서 주인공과 주인공 미사일 충돌 체크
	void BossMissileCollsion();
	void PlayerCollision();
	void SetupInput();

	void appearEnemy();			//적 출현
	void MoveEnemy();			//적 이동
	void CollisionCheckEnemy();		//주인공과 적캐릭터, 주인공과 적 미사일 충돌체크
	void MoveMissile();			//적 미사일 이동
	void MovePlayerMissile();		//플레이어 미사일 이동
	void CollisionCheckMissile();		//미사일과 미사일의 충돌체크
	void MoveBoss();		//보스 이동
	void CollisionCheckBossPlayer();		//보스와 플레이어 충돌체크
	void MoveBossMissile();	//보스미사일 이동
	void CollisionCheckEnemyBoss();		//주인공과 보스, 주인공과 보스 미사일 충돌체크

	void Gameover();
};
