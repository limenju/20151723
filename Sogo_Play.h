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
	_ENEMY_MISSILE g_EnemyMissile[100];   // �� �̻��� ����
	MISSILE g_PlayerMissile[HERO_MISSILE];	//�÷��̾� �̻��� ����
	BOSS_MISSILE_INFO g_sBossMissile;

	STAGE_INFO Stage;

	PAT_INFO *g_PatInfo;
	PAT_INFO *g_BossPatInfo;

	clock_t g_StartTime;
	clock_t g_nLimitTime;

	Sogo_Draw* draw_Sceen;

	int g_nEnemyIndex; // �� ĳ���� ���� �ε���
	int g_nEnemyCount; // �� ĳ���� ��

	char g_EnemyType[4][3] = { "��", "��", "��", "��" };

	GAME_STATE		g_nGameState = INIT;
	int				g_nStage = -1;
	int				g_nGrade = 0; // ���� 
	int				g_nTotalGrade = 0; // ����
	clock_t			g_GameStartTime, g_UpdateOldTime, g_RemainTime;
	int g_nPatCount;
	int g_nDeadEnemy;
	int g_nBossPatCount;

	PLAYER g_Player;		//�÷��̾�
	BOSS g_Boss;		//����
	ENEMY g_Enemy[50];		//��
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
	// ���ΰ� �̻������忡�� ������ ���� �̻��� �浹
	void PlayerMissileBossCollision();
	// ���� �̻��� ���忡�� ���ΰ��� ���ΰ� �̻��� �浹 üũ
	void BossMissileCollsion();
	void PlayerCollision();
	void SetupInput();

	void appearEnemy();			//�� ����
	void MoveEnemy();			//�� �̵�
	void CollisionCheckEnemy();		//���ΰ��� ��ĳ����, ���ΰ��� �� �̻��� �浹üũ
	void MoveMissile();			//�� �̻��� �̵�
	void MovePlayerMissile();		//�÷��̾� �̻��� �̵�
	void CollisionCheckMissile();		//�̻��ϰ� �̻����� �浹üũ
	void MoveBoss();		//���� �̵�
	void CollisionCheckBossPlayer();		//������ �÷��̾� �浹üũ
	void MoveBossMissile();	//�����̻��� �̵�
	void CollisionCheckEnemyBoss();		//���ΰ��� ����, ���ΰ��� ���� �̻��� �浹üũ

	void Gameover();
};
