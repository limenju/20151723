#pragma once
#ifndef __BODY_H__
#include "Define.h"
#include "Food.h"
#include "MONSTER.h"

class BODY : public  ORGANISM {
	BODY *snake_head;
	BODY *snake_tail;
	int direction;
public:
	int abs_x, abs_y;


	BODY * next;
	BODY() 
	{
		abs_x = 2;
		abs_y = 2;
	}

	void Init();
	int free_all();  //프로그램을 끝내기전 할당된 메모리를 모두 해제한다.
	void set_dr(int dr) { direction = dr; }
	int get_dr() { return direction; }

	int move_snake(int dir);
	int make_tail(int dir);
	int strike_check(int x, int y, Food* food); //이동하려는 좌표 //

	int gotoxy(int x, int y);
	void SetColor(int color);
};

#endif 