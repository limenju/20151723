#include "PLAYER.h"

PLAYER::PLAYER()
{
	// Note: ���ΰ�
	nLife = 10;
	nX = 30;
	nY = 18;
	OldTime = clock();
	MoveTime = 50;
	FireTime = 50;
	OldFireTime = clock();
}