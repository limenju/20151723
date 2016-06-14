#pragma once
#ifndef __DRAW_H__

#include "Define.h"

class Draw {
public:
	int show_game_frame(int abs_y);

	int gotoxy(int x, int y);
	void SetColor(int color);
};

#endif 