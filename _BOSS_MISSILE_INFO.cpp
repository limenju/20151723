#include "_BOSS_MISSILE_INFO.h"

BOSS_MISSILE_INFO::BOSS_MISSILE_INFO()
{
	// Note: ���� �̻��� ����
	FireTime = 1000;
	MoveTime = 90;
	OldFireTime = clock();
	memset(sMissile, 0, sizeof(BOSS_MISSILE) * 30);
}