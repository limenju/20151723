#include "Sogo_Play.h"

char *g_strFileName[] = { "pat1.txt", "pat2.txt", "pat3.txt", "pat4.txt" };
char *g_strBossFileName[] = { "boss_pat1.txt", "boss_pat2.txt" };

Sogo_Play::Sogo_Play()
{
	g_nEnemyIndex = 0; // 출현 캐릭터의 인덱스 범위
	g_StartTime = clock();

	g_nGrade = 0;
	g_nDeadEnemy = 0;
}

void Sogo_Play::SoundInit()
{
	//// 시스템 오브젝트 생성과 초기화
	//FMOD_System_Create(&g_System);
	//FMOD_System_Init( g_System, 32, FMOD_INIT_NORMAL, NULL);

	//// 반복 사운드
	//FMOD_System_CreateSound( g_System, "intro.wav", FMOD_DEFAULT | FMOD_LOOP_NORMAL , 0, &g_IntroSound);
	//FMOD_System_CreateSound( g_System, "run.wav", FMOD_DEFAULT | FMOD_LOOP_NORMAL, 0, &g_RunSound);
	//FMOD_System_CreateSound( g_System, "fail.wav", FMOD_DEFAULT | FMOD_LOOP_NORMAL, 0, &g_FailSound); // 적군이 이겼을 때	

	//// 효과 사운드
	//FMOD_System_CreateSound( g_System, "stage.wav", FMOD_DEFAULT, 0, &g_EffectSound[0]); // 스테이지 시작
	//FMOD_System_CreateSound( g_System, "success.wav", FMOD_DEFAULT, 0, &g_EffectSound[1]); // 미션 성공
	//FMOD_System_CreateSound( g_System, "end.wav", FMOD_DEFAULT, 0, &g_EffectSound[2]); // 게임 종료
	//FMOD_System_CreateSound( g_System, "play_fire.wav", FMOD_DEFAULT , 0, &g_EffectSound[3]); // 주인공 미사일 발사 소리
	//FMOD_System_CreateSound( g_System, "enemy_fire.wav", FMOD_DEFAULT , 0, &g_EffectSound[4]); // 적 캐릭터 미사일 발사 소리	
	//FMOD_System_CreateSound( g_System, "collision.wav", FMOD_DEFAULT , 0, &g_EffectSound[5]); // 충돌 했을 때 	
}

void Sogo_Play::SoundRelease()
{
	/*int i;

	FMOD_Sound_Release(g_IntroSound);
	FMOD_Sound_Release(g_RunSound);
	FMOD_Sound_Release(g_FailSound);

	for( i = 0 ; i < 6 ; i++ )
	FMOD_Sound_Release(g_EffectSound[i]);

	FMOD_System_Close( g_System );
	FMOD_System_Release( g_System );*/
}

int Sogo_Play::Collision(int nX1, int nY1, int nX2, int nY2, int nX3, int nY3, int nX4, int nY4)
{
	if (nX1 <= nX4 && nX2 >= nX3 && nY1 <= nY4 && nY2 >= nY3)
		return 1;  // 충돌
	else
		return 0;  // 비충돌
}

void Sogo_Play::PatInit()
{
	int i, j;
	FILE *fp;

	if (g_nStage == -1)
	{
		SoundInit();
		g_nStage = 0;

		g_nPatCount = sizeof(g_strFileName) / sizeof(char *);
		g_PatInfo = (PAT_INFO *)malloc(sizeof(PAT_INFO) * g_nPatCount); //패턴메모리 생성

																		// 패턴 파일 읽기
		for (i = 0; i < g_nPatCount; i++)
		{
			fp = fopen(g_strFileName[i], "r");
			fscanf(fp, "%d\n", &g_PatInfo[i].nCount);
			fscanf(fp, "%d %d\n", &g_PatInfo[i].nX0, &g_PatInfo[i].nY0);
			g_PatInfo[i].pPat = (PAT*)malloc(sizeof(PAT) * g_PatInfo[i].nCount);

			for (j = 0; j < g_PatInfo[i].nCount; j++)
				fscanf(fp, "%d %d %d %d\n", &g_PatInfo[i].pPat[j].nDirect, &g_PatInfo[i].pPat[j].nStep, &g_PatInfo[i].pPat[j].MoveTime,
					&g_PatInfo[i].pPat[j].nDist);
			fclose(fp);
		}

		g_nBossPatCount = sizeof(g_strBossFileName) / sizeof(char *);
		g_BossPatInfo = (PAT_INFO *)malloc(sizeof(PAT_INFO) * g_nBossPatCount); //패턴메모리 생성

																				// 보스 패턴 파일 읽기
		for (i = 0; i < g_nBossPatCount; i++)
		{
			fp = fopen(g_strBossFileName[i], "r");
			fscanf(fp, "%d\n", &g_BossPatInfo[i].nCount);
			fscanf(fp, "%d %d\n", &g_BossPatInfo[i].nX0, &g_BossPatInfo[i].nY0);
			g_BossPatInfo[i].pPat = (PAT*)malloc(sizeof(PAT) * g_BossPatInfo[i].nCount);

			for (j = 0; j < g_BossPatInfo[i].nCount; j++)
				fscanf(fp, "%d %d %d %d\n", &g_BossPatInfo[i].pPat[j].nDirect, &g_BossPatInfo[i].pPat[j].nStep,
					&g_BossPatInfo[i].pPat[j].MoveTime, &g_BossPatInfo[i].pPat[j].nDist);
			fclose(fp);
		}

		//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_IntroSound, 0, &g_IntroChannel); 
	}
}

void Sogo_Play::Init()
{
	PatInit();

	g_nEnemyCount = Stage.g_nEnemyCount_nBossLife[g_nStage][0]; // 적 캐릭터수 
	EnemyMaster->INIT_Enemy(g_Enemy, g_nEnemyCount, g_PatInfo);		//적 초기화
	g_Boss.INIT_Boss(Stage, g_nStage, g_BossPatInfo);	//보스 초기화
}

// 주인공 미사일입장에서 보스와 보스 미사일 충돌
void Sogo_Play::PlayerMissileBossCollision()
{
	int i, j;

	for (i = 0; i < HERO_MISSILE; i++)
	{
		if (g_PlayerMissile[i].nLife)
		{
			// 주인공 미사일과 보스 충돌체크
			if (Collision(g_PlayerMissile[i].nX, g_PlayerMissile[i].nY, g_PlayerMissile[i].nX, g_PlayerMissile[i].nY,
				g_Boss.getX(), g_Boss.getY(), g_Boss.getX() + 16, g_Boss.getY() + 2))
			{
				g_PlayerMissile[i].nLife = 0;
				g_Boss.set_min_Life();
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5]);

				if (g_Boss.getLife() < 1)
				{
					g_nGameState = STOP;
					return;
				}

				continue;
			}

			// 주인공 미사일과 보스 미사일과 충돌 체크
			for (j = 0; j < 30; j++)
			{
				if (g_sBossMissile.sMissile[j].getLife())
				{
					if (Collision(g_PlayerMissile[i].nX, g_PlayerMissile[i].nY, g_PlayerMissile[i].nX, g_PlayerMissile[i].nY,
						g_sBossMissile.sMissile[j].getX(), g_sBossMissile.sMissile[i].getY(),
						g_sBossMissile.sMissile[j].getX() +1, g_sBossMissile.sMissile[i].getY()))
					{
						g_PlayerMissile[i].nLife = 0;
						g_sBossMissile.sMissile[j].setLife(0);
						//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5]);
						break;
					}
				}
			}
		}
	}
}

// 보스 미사일 입장에서 주인공과 주인공 미사일 충돌 체크
void Sogo_Play::BossMissileCollsion()
{
	int i, j;


	for (i = 0; i < 30; i++)
	{
		if (g_sBossMissile.sMissile[i].getLife())
		{
			// Note: 보스 미사일과 주인공과 충돌
			if (Collision(g_sBossMissile.sMissile[i].getX(), g_sBossMissile.sMissile[i].getY(),
				g_sBossMissile.sMissile[i].getX() + 1, g_sBossMissile.sMissile[i].getY(),
				g_Player.getX(), g_Player.getY(), g_Player.getX() + 4, g_Player.getY()))
			{
				g_sBossMissile.sMissile[i].setLife(0);
				g_Player.set_min_Life();
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5]);

				if (g_Player.getLife() < 1)
				{
					g_nGameState = STOP;
					return;
				}

				continue;
			}

			// Note: 보스 미사일과 주인공 미사일 충돌
			for (j = 0; j < HERO_MISSILE; j++)
			{
				if (g_PlayerMissile[j].nLife)
				{
					if (Collision(g_sBossMissile.sMissile[i].getX(), g_sBossMissile.sMissile[i].getY(),
						g_sBossMissile.sMissile[i].getX() + 1, g_sBossMissile.sMissile[i].getY(),
						g_PlayerMissile[j].nX, g_PlayerMissile[j].nY, g_PlayerMissile[j].nX, g_PlayerMissile[j].nY))
					{
						g_sBossMissile.sMissile[i].setLife(0);
						g_PlayerMissile[j].nLife = 0;
						//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5]);
						break;
					}
				}
			}
		}
	}
}

// Note: 출현 ( 출현 시간의 데이터는 오름차순으로 정렬되어 있다 )
void Sogo_Play::appearEnemy()
{
	int i;
	clock_t CurTime = clock();

	for (i = g_nEnemyIndex; i < g_nEnemyCount; i++)
	{
		if (g_Enemy[i].getLife() == 0)
		{
			if (CurTime - g_StartTime >= g_Enemy[i].AppearTime)
			{
				g_Enemy[i].setLife(1);
				g_nEnemyIndex++;
			}
			else {
				break;
			}
		}
	}
}

void Sogo_Play::MoveEnemy()
{
	int nSignX, nSignY, i, j;
	clock_t CurTime = clock();

	// Note:  적 캐릭터 이동 과 미사일 발사 시작 
	for (i = 0; i < g_nEnemyIndex; i++)
	{
		if (g_Enemy[i].getLife())
		{
			// Note: 적 캐릭터 업데이트
			if (CurTime - g_Enemy[i].OldMoveTime > g_Enemy[i].getMoveTime())
			{
				g_Enemy[i].OldMoveTime = CurTime;
				g_Enemy[i].addnPatStep();

				// 다음 패턴 인덱스로 진행
				if (g_Enemy[i].getnPatStep() == g_PatInfo[g_Enemy[i].getnPatType()].pPat[g_Enemy[i].getnPatIndex()].nStep)
				{
					g_Enemy[i].addnPatStep();
					if (g_Enemy[i].getnPatIndex() == g_PatInfo[g_Enemy[i].getnPatType()].nCount)
					{
						g_Enemy[i].setLife(0);
						g_nDeadEnemy++;

						if (g_nDeadEnemy == g_nEnemyCount)
						{
							g_nGameState = PLAYER_TALK;
							g_UpdateOldTime = CurTime;
							return;
						}
						else
							continue;  // 패턴이동이 종료되어 다음 캐릭터를 설정
					}
					else {
						g_Enemy[i].set_MoveTime(g_PatInfo[g_Enemy[i].getnPatType()].pPat[g_Enemy[i].getnPatIndex()].MoveTime);
						g_Enemy[i].setnPatStep(0);
					}
				}

				switch (g_PatInfo[g_Enemy[i].getnPatType()].pPat[g_Enemy[i].getnPatIndex()].nDirect)
				{
				case UP:
					nSignX = 0;
					nSignY = -1;
					break;
				case UP_RIGHT:
					nSignX = 1;
					nSignY = -1;
					break;
				case RIGHT:
					nSignX = 1;
					nSignY = 0;
					break;
				case DOWN_RIGHT:
					nSignX = 1;
					nSignY = 1;
					break;
				case DOWN:
					nSignX = 0;
					nSignY = 1;
					break;
				case DOWN_LEFT:
					nSignX = -1;
					nSignY = 1;
					break;
				case LEFT:
					nSignX = -1;
					nSignY = 0;
					break;
				case UP_LEFT:
					nSignX = -1;
					nSignY = -1;
					break;
				}
				g_Enemy[i].set_X(g_Enemy[i].getX() + nSignX*g_PatInfo[g_Enemy[i].getnPatType()].pPat[g_Enemy[i].getnPatIndex()].nDist);
				g_Enemy[i].set_Y(g_Enemy[i].getY() + nSignY*g_PatInfo[g_Enemy[i].getnPatType()].pPat[g_Enemy[i].getnPatIndex()].nDist);
			}

			// Note: 적 미사일 발사 하는 부분 ( 캐릭터가 살아 있는 때만 가능 )
			if (CurTime - g_Enemy[i].MissileOldTime > g_Enemy[i].MissileFireTime)
			{
				g_Enemy[i].MissileOldTime = CurTime;
				for (j = 0; j < 100; j++)
				{
					if (g_EnemyMissile[j].getLife() == 0)
					{
						g_EnemyMissile[j].set_X(g_Enemy[i].getX());
						g_EnemyMissile[j].set_Y(g_Enemy[i].getY() + 1);
						g_EnemyMissile[j].setLife(1);
						g_EnemyMissile[j].set_MoveTime(rand() % 100 + 80);
						g_EnemyMissile[j].OldMoveTime = CurTime;
						break;
					}
				}
			}
		}
	}
}

void Sogo_Play::MoveMissile()
{
	int i;
	clock_t CurTime = clock();

	for (i = 0; i < 100; i++)
	{
		if (g_EnemyMissile[i].getLife())
		{
			if (CurTime - g_EnemyMissile[i].OldMoveTime > g_EnemyMissile[i].getMoveTime())
			{
				g_EnemyMissile[i].OldMoveTime = CurTime;

				if (g_EnemyMissile[i].getY() + 1 > 22)
				{
					g_EnemyMissile[i].setLife(0);
					continue;
				}
				else {
					g_EnemyMissile[i].add_Y();
				}
			}
		}
	}
}

void Sogo_Play::CollisionCheckEnemy()
{
	int i, j;
	clock_t CurTime = clock();

	for (i = 0; i < g_nEnemyIndex; i++)
	{
		if (g_Enemy[i].getLife())
		{
			// Note: 적캐릭터와 주인공의 충돌 체크
			if (Collision(g_Enemy[i].getX(), g_Enemy[i].getY(), g_Enemy[i].getX() + 1, g_Enemy[i].getY(),
				g_Player.getX(), g_Player.getY(), g_Player.getX() + 4, g_Player.getY()))
			{
				g_Enemy[i].setLife(0);
				g_nGrade += 10; // 점수
				g_Player.set_min_Life();
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5]);

				if (g_Player.getLife() < 1)
				{
					g_nGameState = STOP;
					return;
				}

				g_nDeadEnemy++;
				if (g_nDeadEnemy == g_nEnemyCount)
				{
					g_nGameState = PLAYER_TALK;
					g_UpdateOldTime = CurTime;
					g_nDeadEnemy = 0;
					return;
				}

				continue;
			}

			// Note: 적 캐릭터와 주인공 미사일의 충돌 체크
			for (j = 0; j < 10; j++)
			{
				if (g_PlayerMissile[j].nLife)
				{
					if (Collision(g_Enemy[i].getX(), g_Enemy[i].getY(), g_Enemy[i].getX() + 1, g_Enemy[i].getY(),
						g_PlayerMissile[j].nX, g_PlayerMissile[j].nY, g_PlayerMissile[j].nX, g_PlayerMissile[j].nY))
					{
						g_Enemy[i].setLife(0);
						g_PlayerMissile[j].nLife = 0;
						g_nGrade += 10; // 점수
						g_nDeadEnemy++;
						//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5]);

						if (g_nDeadEnemy == g_nEnemyCount)
						{
							g_nGameState = PLAYER_TALK;
							g_UpdateOldTime = CurTime;
							g_nDeadEnemy = 0;
							return;
						}

						break;
					}
				}
			}
		}
	}

	MoveMissile();


	// Note:  적 미사일과 주인공, 주인공 미사일 충돌 체크 
	for (i = 0; i < 100; i++)
	{
		if (g_EnemyMissile[i].getLife())
		{
			// Note: 충돌 체크 => 적 미사일과 주인공 
			if (Collision(g_EnemyMissile[i].getX(), g_EnemyMissile[i].getY(), g_EnemyMissile[i].getX() + 1, g_EnemyMissile[i].getY(),
				g_Player.getX(), g_Player.getY(), g_Player.getX() + 4, g_Player.getY()))
			{
				g_EnemyMissile[i].setLife(0);
				g_Player.set_min_Life();
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5]);

				if (g_Player.getLife() < 1)
				{
					g_nGameState = STOP;
					return;
				}

				continue;
			}

			// Note: 충돌 체크 => 적 미사일과 주인공 미사일
			for (j = 0; j < HERO_MISSILE; j++)
			{
				if (g_PlayerMissile[j].nLife)
				{
					if (Collision(g_EnemyMissile[i].getX(), g_EnemyMissile[i].getY(), g_EnemyMissile[i].getX() + 1, g_EnemyMissile[i].getY(),
						g_PlayerMissile[j].nX, g_PlayerMissile[j].nY, g_PlayerMissile[j].nX, g_PlayerMissile[j].nY))
					{
						g_EnemyMissile[i].setLife(0);
						g_PlayerMissile[j].nLife = 0;
						//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5]);
						break;
					}
				}
			}
		}
	}
}

void Sogo_Play::MovePlayerMissile()
{
	int i;
	clock_t CurTime = clock();

	for (i = 0; i < HERO_MISSILE; i++)
	{
		if (g_PlayerMissile[i].nLife)
		{   // 주인공 미사일 이동
			if (CurTime - g_PlayerMissile[i].OldTime > MISSILE_MOVE_TIME)
			{
				g_PlayerMissile[i].OldTime = CurTime;
				if (g_PlayerMissile[i].nY - 1 > 2)
					g_PlayerMissile[i].nY--;
				else
					g_PlayerMissile[i].nLife = 0;
			}
		}
	}
}

void Sogo_Play::CollisionCheckMissile()
{
	int i, j;
	clock_t CurTime = clock();

	for (i = 0; i < HERO_MISSILE; i++)
	{
		if (g_PlayerMissile[i].nLife)
		{
			// Note: 주인공 미사일과 적 캐릭터의 충돌 체크
			for (j = 0; j < g_nEnemyIndex; j++)
			{
				if (g_Enemy[j].getLife())
				{
					if (Collision(g_PlayerMissile[i].nX, g_PlayerMissile[i].nY, g_PlayerMissile[i].nX, g_PlayerMissile[i].nY,
						g_Enemy[j].getX(), g_Enemy[j].getY(), g_Enemy[j].getX() + 1, g_Enemy[j].getY()))
					{
						g_PlayerMissile[i].nLife = 0;
						g_Enemy[j].setLife(0);
						g_nGrade += 10; // 점수
										//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5] );
						g_nDeadEnemy++; // 적 캐릭터 한개 소멸

						if (g_nDeadEnemy == g_nEnemyCount)
						{
							g_nGameState = PLAYER_TALK;
							g_UpdateOldTime = CurTime;
							g_nDeadEnemy = 0;
							return;
						}
						break;
					}
				}
			}
		}
	}

	// Note: 주인공 미사일과 적미사일의 충돌 체크
	for (i = 0; i < HERO_MISSILE; i++)
	{
		if (g_PlayerMissile[i].nLife)
		{
			for (j = 0; j < 100; j++)
			{
				if (g_EnemyMissile[j].getLife())
				{
					if (Collision(g_PlayerMissile[i].nX, g_PlayerMissile[i].nY, g_PlayerMissile[i].nX, g_PlayerMissile[i].nY,
						g_EnemyMissile[j].getX(), g_EnemyMissile[j].getY(), g_EnemyMissile[j].getX() + 1, g_EnemyMissile[j].getY()))
					{
						g_PlayerMissile[i].nLife = 0;
						g_EnemyMissile[j].setLife(0);
						//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5]);
						break;
					}
				}
			}
		}
	}
}

void Sogo_Play::MoveBoss()
{
	int nSignX, nSignY, i, j, nFireMissileCount;
	clock_t CurTime = clock();

	// Note: 보스의 이동
	if (g_Boss.getLife())
	{
		if (CurTime - g_Boss.getOldTime() > g_Boss.getMoveTime())
		{
			g_Boss.set_OldTime(CurTime);
			g_Boss.set_add_nPatStep();

			if (g_Boss.getnPatStep() == g_BossPatInfo[g_Boss.getnPatType()].pPat[g_Boss.getnPatIndex()].nStep)
			{
				g_Boss.set_add_nPatIndex();

				if (g_Boss.getnPatIndex() == g_BossPatInfo[g_Boss.getnPatType()].nCount)
				{
					g_Boss.set_add_nPatType();
					g_Boss.set_nPatType(g_Boss.getnPatType() % g_nBossPatCount); // 패턴 반복

					g_Boss.set_nPatIndex(0);
					g_Boss.set_nPatStep(-1);
					g_Boss.set_X(g_BossPatInfo[g_Boss.getnPatType()].nX0);
					g_Boss.set_Y(g_BossPatInfo[g_Boss.getnPatType()].nY0);
					g_Boss.set_MoveTime(g_BossPatInfo[g_Boss.getnPatType()].pPat[0].MoveTime);
					g_Boss.set_OldTime(clock());
				}
				else {
					g_Boss.set_MoveTime(g_BossPatInfo[g_Boss.getnPatType()].pPat[g_Boss.getnPatIndex()].MoveTime);
					g_Boss.set_nPatStep(0);
				}
			}

			switch (g_BossPatInfo[g_Boss.getnPatType()].pPat[g_Boss.getnPatIndex()].nDirect)
			{
			case UP:
				nSignX = 0;
				nSignY = -1;
				break;
			case UP_RIGHT:
				nSignX = 1;
				nSignY = -1;
				break;
			case RIGHT:
				nSignX = 1;
				nSignY = 0;
				break;
			case DOWN_RIGHT:
				nSignX = 1;
				nSignY = 1;
				break;
			case DOWN:
				nSignX = 0;
				nSignY = 1;
				break;
			case DOWN_LEFT:
				nSignX = -1;
				nSignY = 1;
				break;
			case LEFT:
				nSignX = -1;
				nSignY = 0;
				break;
			case UP_LEFT:
				nSignX = -1;
				nSignY = -1;
				break;
			}

			g_Boss.set_X(g_Boss.getX() + nSignX*g_BossPatInfo[g_Boss.getnPatType()].pPat[g_Boss.getnPatIndex()].nDist);
			g_Boss.set_Y(g_Boss.getY() + nSignY*g_BossPatInfo[g_Boss.getnPatType()].pPat[g_Boss.getnPatIndex()].nDist);
		}

		if (CurTime - g_sBossMissile.OldFireTime > g_sBossMissile.FireTime)
		{
			g_sBossMissile.OldFireTime = CurTime;
			nFireMissileCount = 0;

			for (i = 0; i < 30; i++)    // 30개의 미사일을 검색하는 부분
			{
				if (g_sBossMissile.sMissile[i].getLife() == 0)
				{
					g_sBossMissile.sMissile[i].set_X(g_Boss.getX() + 6);
					g_sBossMissile.sMissile[i].set_Y(g_Boss.getY() + 2);
					g_sBossMissile.sMissile[i].setLife(1);
					g_sBossMissile.sMissile[i].Boss_Missile_nDirect = (DIRECT)(DOWN_LEFT - nFireMissileCount); // 방향설정: 5, 4, 3
					g_sBossMissile.sMissile[i].OldMoveTime = CurTime;
					nFireMissileCount++;
					//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[4], 0, &g_pEffectChannel[4] );

					if (nFireMissileCount > 2) // 3발 이상 발사 되지 못하게 하는 부분
						break;
				}
			}
		}
	}
}

void Sogo_Play::CollisionCheckBossPlayer()
{
	int i;

	// Note: 보스와 주인공 미사일의 충돌 체크 (1)
	for (i = 0; i < HERO_MISSILE; i++)
	{
		if (g_PlayerMissile[i].nLife)
		{
			if (Collision(g_Boss.getX(), g_Boss.getY(), g_Boss.getX() + 16, g_Boss.getY() + 2,
				g_PlayerMissile[i].nX, g_PlayerMissile[i].nY, g_PlayerMissile[i].nX, g_PlayerMissile[i].nY))
			{
				g_PlayerMissile[i].nLife = 0;
				g_Boss.set_min_Life();
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5]);

				if (g_Boss.getLife() < 1)
				{
					g_nGameState = STOP;
					return;
				}

			}
		}
	}
}

void Sogo_Play::MoveBossMissile()
{
	int nSignX, nSignY, i, j;
	clock_t CurTime = clock();
	// Note: 보스 미사일 이동
	for (i = 0; i < 30; i++)
	{
		if (g_sBossMissile.sMissile[i].getLife())
		{
			if (CurTime - g_sBossMissile.sMissile[i].OldMoveTime > g_sBossMissile.MoveTime)
			{
				g_sBossMissile.sMissile[i].OldMoveTime = CurTime;
				switch (g_sBossMissile.sMissile[i].Boss_Missile_nDirect)
				{
				case DOWN_RIGHT:
					nSignX = 1;
					nSignY = 1;
					break;
				case DOWN:
					nSignX = 0;
					nSignY = 1;
					break;
				case DOWN_LEFT:
					nSignX = -1;
					nSignY = 1;
					break;
				}

				g_sBossMissile.sMissile[i].set_X(g_sBossMissile.sMissile[i].getX() + nSignX);
				g_sBossMissile.sMissile[i].set_Y(g_sBossMissile.sMissile[i].getY() + nSignY);
			}

			// Note: 경계 영역 충돌 체크
			if (g_sBossMissile.sMissile[j].getX() < 2 || g_sBossMissile.sMissile[j].getX() + 1 > 59 ||
				g_sBossMissile.sMissile[i].getY() > 22)
			{
				g_sBossMissile.sMissile[i].setLife(0);
			}
		}
	}
}

void  Sogo_Play::CollisionCheckEnemyBoss()
{
	int i;
	clock_t CurTime = clock();

	//------------------------ 주인공과 보스 미사일 충돌 체크 부분   ---------------------------//
	for (i = 0; i < 30; i++)
	{
		if (g_sBossMissile.sMissile[i].getLife())
		{
			if (Collision(g_sBossMissile.sMissile[i].getX(), g_sBossMissile.sMissile[i].getY(), g_sBossMissile.sMissile[i].getX() + 1, g_sBossMissile.sMissile[i].getY(),
				g_Player.getX(), g_Player.getY(), g_Player.getX() + 4, g_Player.getY()))
			{
				g_sBossMissile.sMissile[i].setLife(0);
				g_Player.set_min_Life();
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5]);

				if (g_Player.getLife() < 1)
				{
					g_nGameState = STOP;
					return;
				}
			}
		}
	}

	//------------------------ 주인공 미사일 이동  --------------------------//
	for (i = 0; i < HERO_MISSILE; i++)
	{
		if (g_PlayerMissile[i].nLife)
		{
			if (CurTime - g_PlayerMissile[i].OldTime > MISSILE_MOVE_TIME)
			{
				g_PlayerMissile[i].OldTime = CurTime;
				g_PlayerMissile[i].nY--;

				// 경계 영역 충돌 처리
				if (g_PlayerMissile[i].nY < 2)
				{
					g_PlayerMissile[i].nLife = 0;
				}
			}
		}
	}
}

void Sogo_Play::Update()
{
	int nSignX, nSignY, i, j, nFireMissileCount;
	clock_t CurTime = clock();

	switch (g_nGameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 3000)  // 3초
		{
			g_nGameState = RUNNING;
			g_GameStartTime = CurTime;

			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_RunSound, 0, &g_RunChannel ); // 게임 진행 사운드
		}
		break;

	case RUNNING:

		appearEnemy();
		MoveEnemy();
		//------------------ 적 캐릭터 이동 끝 ------------------------------
		CollisionCheckEnemy();
		MovePlayerMissile();
		CollisionCheckMissile();

		break;

	case PLAYER_TALK:
		if (CurTime - g_UpdateOldTime > 3000)  // 3초
		{
			g_nGameState = BOSS_TALK;
			g_UpdateOldTime = CurTime;
		}
		break;
	case BOSS_TALK:
		if (CurTime - g_UpdateOldTime > 3000)  // 3초
		{
			g_nGameState = BOSS_WAR;
			g_UpdateOldTime = CurTime;
			memset(g_PlayerMissile, 0, sizeof(MISSILE)*HERO_MISSILE);
		}
		break;

	case BOSS_WAR:
		MoveBoss();
		CollisionCheckBossPlayer();
		MoveBossMissile();


		BossMissileCollsion();

		CollisionCheckEnemyBoss();

		PlayerMissileBossCollision();
		break;

	case STOP:
		if (g_Player.getLife() < 1)
		{
			g_nGameState = FAILED;
			//FMOD_Channel_Stop( g_RunChannel ); // 배경음 중지
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_FailSound, 0, &g_FailChannel ); // 미션 실패 사운드
			break;
		}

		if (g_Boss.getLife() < 1)
		{
			g_UpdateOldTime = CurTime;
			g_nGameState = SUCCESS;
			g_nTotalGrade += g_nGrade;
			g_nTotalGrade += 100; // 보스를 이겼으므로
								  //FMOD_Channel_Stop( g_RunChannel ); // 배경음 중지
								  //FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[1], 0, &g_pEffectChannel[1] ); // 미션 성공 사운드
		}
		break;

	case SUCCESS:
		if (CurTime - g_UpdateOldTime > 3000)
		{
			g_UpdateOldTime = CurTime;
			++g_nStage;
			g_nStage = g_nStage % 3; 	// 스테이지가 3개밖에 없어서.	
			Init();
			g_nGameState = READY;
			//FMOD_Channel_Stop( g_pEffectChannel[1] );  // 미션 성공 사운드 출력 중지					
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[0], 0, &g_pEffectChannel[0]); // READY 사운드 출력
		}
		break;
	}
}

void Sogo_Play::Draw()
{
	int i;
	char string[100];
	ScreenClear();

	switch (g_nGameState)
	{
	case INIT:
		if (g_nStage == 0)
			draw_Sceen->InitScreen();
		break;

	case READY:
		draw_Sceen->ReadyScreen();
		sprintf(string, "%d Stage", g_nStage + 1);
		ScreenPrint(23, 9, string);
		break;

	case RUNNING:
		draw_Sceen->ScreenLine();

		for (i = 0; i < 100; i++)
		{
			if (g_EnemyMissile[i].getLife())
			{
				ScreenPrint(g_EnemyMissile[i].getX(), g_EnemyMissile[i].getY(), "↓");
			}
		}

		for (i = 0; i < g_nEnemyIndex; i++)
		{
			if (g_Enemy[i].getLife())
			{
				ScreenPrint(g_Enemy[i].getX(), g_Enemy[i].getY(), g_EnemyType[g_Enemy[i].nType]);
			}
		}

		for (i = 0; i < HERO_MISSILE; i++)
		{
			if (g_PlayerMissile[i].nLife == 1)
				ScreenPrint(g_PlayerMissile[i].nX, g_PlayerMissile[i].nY, "$");
		}

		ScreenPrint(g_Player.getX(), g_Player.getY(), "#-@-#");

		sprintf(string, "stage : %d ", g_nStage + 1);
		ScreenPrint(63, 3, string);
		sprintf(string, "주인공 HP : %d", g_Player.getLife());
		ScreenPrint(63, 5, string);
		sprintf(string, "점수: %d", g_nGrade);
		ScreenPrint(63, 7, string);
		break;

	case PLAYER_TALK:
		draw_Sceen->PlayerTalk();
		break;

	case BOSS_TALK:
		draw_Sceen->BossTalk();
		break;

	case BOSS_WAR:
		draw_Sceen->ScreenLine();
		ScreenPrint(g_Boss.getX(), g_Boss.getY(), " /| ━ // ━ |＼");
		ScreenPrint(g_Boss.getX(), g_Boss.getY() + 1, "//q ●    ● p＼");
		ScreenPrint(g_Boss.getX(), g_Boss.getY() + 2, "  (┗┻━┻┛)");

		for (i = 0; i < 30; i++)
		{
			if (g_sBossMissile.sMissile[i].getLife())
			{
				ScreenPrint(g_sBossMissile.sMissile[i].getX(), g_sBossMissile.sMissile[i].getY(), "↓");
			}
		}

		// 주인공 미사일 렌더링
		for (i = 0; i < HERO_MISSILE; i++)
		{
			if (g_PlayerMissile[i].nLife)
				ScreenPrint(g_PlayerMissile[i].nX, g_PlayerMissile[i].nY, "$");
		}

		ScreenPrint(g_Player.getX(), g_Player.getY(), "#-@-#");

		sprintf(string, "보스 HP : %d", g_Boss.getLife());
		ScreenPrint(63, 3, string);
		sprintf(string, "주인공 HP : %d", g_Player.getLife());
		ScreenPrint(63, 5, string);
		break;

	case SUCCESS:
		draw_Sceen->SuccessScreen();
		sprintf(string, "%d", g_nStage + 1);
		ScreenPrint(19, 7, string);
		sprintf(string, "총점: %d", g_nTotalGrade);
		ScreenPrint(18, 17, string);
		break;

	case RESULT:
		draw_Sceen->ResultScreen();
		sprintf(string, "%d", g_nTotalGrade);
		ScreenPrint(48, 13, string);
		break;

	}

	ScreenFlipping();
}

void Sogo_Play::Gameover() {
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                                          ┃");
	ScreenPrint(0, 2, "┃                                                          ┃");
	ScreenPrint(0, 3, "┃                                                          ┃");
	ScreenPrint(0, 4, "┃                                                          ┃");
	ScreenPrint(0, 5, "┃                                                          ┃");
	ScreenPrint(0, 6, "┃                                                          ┃");
	ScreenPrint(0, 7, "┃                     *┭┮  ┭┮*                         ┃");
	ScreenPrint(0, 8, "┃                  *.  ㅣㅣ▽ㅣㅣ   .*                     ┃");
	ScreenPrint(0, 9, "┃               ┏ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┓                   ┃");
	ScreenPrint(0, 10, "┃               ┃     미션 실패      ┃                   ┃");
	ScreenPrint(0, 11, "┃               ┗ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┛                   ┃");
	ScreenPrint(0, 12, "┃                                                          ┃");
	ScreenPrint(0, 13, "┃                                                          ┃");
	ScreenPrint(0, 14, "┃                   (*⌒⌒*)                               ┃");
	ScreenPrint(0, 15, "┃                  ┏O━━━O━━━━━━━━━━┓        ┃");
	ScreenPrint(0, 16, "┃                  ┃계속하시겠습니까? <y/n>     ┃        ┃");
	ScreenPrint(0, 17, "┃                  ┗━━━━━━━━━━━━━━┛        ┃");
	ScreenPrint(0, 18, "┃                                                          ┃");
	ScreenPrint(0, 19, "┃                                                          ┃");
	ScreenPrint(0, 20, "┃                                                          ┃");
	ScreenPrint(0, 21, "┃                                                          ┃");
	ScreenPrint(0, 22, "┃                                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void Sogo_Play::Release()
{
	int i, nFileCount;

	nFileCount = sizeof(g_strFileName) / sizeof(char *);
	for (i = 0; i < nFileCount; i++)
		free(g_PatInfo[i].pPat);

	free(g_PatInfo);

	nFileCount = sizeof(g_strBossFileName) / sizeof(char *);
	for (i = 0; i < nFileCount; i++)
		free(g_BossPatInfo[i].pPat);

	free(g_BossPatInfo);

	SoundRelease();
}

// Note: 주인공 입장에서 적 캐릭터와 적 미사일 충돌 체크
void Sogo_Play::PlayerCollision()
{
	int i, j;

	for (i = 0; i < g_nEnemyIndex; i++)
	{
		if (g_Enemy[i].getLife())
		{
			// 적 캐릭터와 충돌 체크
			if (Collision(g_Enemy[i].getX(), g_Enemy[i].getY(), g_Enemy[i].getX() + 1, g_Enemy[i].getY(), g_Player.getX(), g_Player.getY(), g_Player.getX() + 4, g_Player.getY()))
			{
				g_Enemy[i].setLife(0);
				g_Player.set_min_Life();
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5] ); // 충돌 사운드

				if (g_Player.getLife() < 1)
				{
					g_nGameState = STOP;
					return;
				}
			}
		}
	}

	// 적 미사일과 충돌 체크
	for (j = 0; j < 100; j++)
	{
		if (g_EnemyMissile[j].getLife())
		{
			if (Collision(g_EnemyMissile[j].getX(), g_EnemyMissile[j].getY(), g_EnemyMissile[j].getX() + 1, g_EnemyMissile[j].getY(),
				g_Player.getX(), g_Player.getY(), g_Player.getX() + 4, g_Player.getY()))
			{
				g_EnemyMissile[j].setLife(0);
				g_Player.set_min_Life();
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[5], 0, &g_pEffectChannel[5] ); // 충돌 사운드

				if (g_Player.getLife() < 1)
				{
					g_nGameState = STOP;
					return;
				}
			}
		}
	}
}

void Sogo_Play::SetupInput(void)
{
	int nKey, i;
	clock_t CurTime;

	CurTime = clock();

	if (_kbhit())
	{
		/*	if (g_nGameState == RESULT)
		break;*/

		nKey = _getch();

		switch (nKey)
		{
		case ' ':
			if (g_nGameState == INIT && g_nStage == 0)
			{
				g_nGameState = READY;
				//FMOD_Channel_Stop( g_IntroChannel ); // 배경음 중지
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[0], 0, &g_pEffectChannel[0]); // 스테이지 출력
				g_UpdateOldTime = clock();  // ready를 일정시간 지속해 주기 위해 							
			}
			break;

		case 75: // 왼쪽
			if (g_nGameState == RUNNING || g_nGameState == BOSS_WAR)
			{
				if (CurTime - g_Player.getOldTime() > g_Player.getMoveTime())
				{
					g_Player.set_OldTime(CurTime);
					if (g_Player.getX() - 1 > 1)
					{
						g_Player.set_min_X();

						PlayerCollision();
						break;
					}
				}
			}
			break;

		case 77: // 오른쪽
			if (g_nGameState == RUNNING || g_nGameState == BOSS_WAR)
			{
				if (CurTime - g_Player.getOldTime() > g_Player.getMoveTime())
				{
					g_Player.set_OldTime(CurTime);
					if (g_Player.getX() + 4 < 59)
					{
						g_Player.set_add_X();

						PlayerCollision();
						break;
					}
				}
			}
			break;

		case 's': // 미사일 발사
			if (g_nGameState == RUNNING || g_nGameState == BOSS_WAR)
			{
				if (CurTime - g_Player.getOldFireTime() > g_Player.getFireTime())
				{
					g_Player.set_OldFireTime(CurTime);
					for (i = 0; i < HERO_MISSILE; i++)
					{
						if (g_PlayerMissile[i].nLife == 0)
						{
							g_PlayerMissile[i].nLife = 1;
							g_PlayerMissile[i].nX = g_Player.getX() + 2;
							g_PlayerMissile[i].nY = g_Player.getY() - 1;
							g_PlayerMissile[i].OldTime = clock();
							//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[3], 0, &g_pEffectChannel[3] );
							break;
						}
					}
				}
			}
			break;
		case 'y':
		case 'Y':
			if (g_nGameState == FAILED)
			{
				Init();
				g_nGameState = READY;
				//FMOD_Channel_Stop( g_FailChannel );  // 미션 실패 사운드 출력 중지 
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_EffectSound[0], 0, &g_pEffectChannel[0]); // 스테이지 출력
				g_UpdateOldTime = clock();
			}
			break;
		case 'n':
		case 'N':
			if (g_nGameState == FAILED)
			{
				g_nGameState = RESULT;
				//FMOD_Channel_Stop( g_FailChannel );  // 미션 실패 사운드 출력 중지							
			}
			break;
		}
	}
}

int Sogo_Play::Render(void)
{

	ScreenInit();
	Init();

	while (1)
	{
		SetupInput();
		Update();
		Draw();
		//FMOD_System_Update( g_System );		
	}

	Release();
	ScreenRelease();
	return 0;
}