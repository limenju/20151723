#pragma once
#ifndef __FOOD_H__
#include "Define.h"
#include "MONSTER.h"

class Food : public ORGANISM {
public:
	Food() {
		nY = rand() % 20;
		nX = rand() % 35;
	}

	int make_food(int abs_x, int abs_y, Food* food);

	int gotoxy(int x, int y);
	void SetColor(int color);
};

#endif 