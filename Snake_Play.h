#pragma once

#include "Define.h"

#include "MainScene.h"
#include "ExitScene.h"
#include "Body.h"
#include "Draw.h"
#include "Food.h"

class Snake_Play : public MainScene 
{
	BODY* Me;
	Draw* sceen;
	Food *food;

	int last_direction;
	int length; //≤ø∏Æ¿« ±Ê¿Ã
	int score;
	int speed;
public:
	Snake_Play() {}
	Snake_Play(int x) {}
	void Init();
	int Render();
	int Update(int i);
	void Release();
	void SetupInput();

	void Gameover();
};