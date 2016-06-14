#pragma once
#include "DEFINE.h"
#include "MONSTER.h"

class PLAYER : public ORGANISM
{
	clock_t FireTime;      // �̻��� �߻� �ð� ����
	clock_t OldFireTime;   // ���� �̻��� �߻� �ð�

	clock_t OldTime;	// ���� �̵� �ð�
public:
	PLAYER();
	clock_t getOldTime() { return  OldTime; }
	clock_t getFireTime() { return  FireTime; }
	clock_t getOldFireTime() { return  OldFireTime; }

	void set_min_Life() { nLife--; }
	void set_add_X() { nX++; }
	void set_min_X() { nX--; }
	void set_OldTime(clock_t CurTime) { OldTime = CurTime; }
	void set_OldFireTime(clock_t CurTime) { OldFireTime = CurTime; }
};