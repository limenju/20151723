#pragma once
#include "Scene.h"
#include "Define.h"

class MainScene : public Scene
{
	int sort_game;	//1일때 snake, 2일때 sogo
	MainScene* pGame;
public:
	MainScene() {}
	MainScene(int x) { sort_game = x; }
	virtual void Init();
	virtual int Update(int i) { return 0; }
	virtual int Render();
	virtual void Release();
	virtual void SetupInput() {}

	int sort_get() { return sort_game; }
	void Gameover();
	int gotoxy(int x, int y);
	void SetColor(int color);
};

#include "Snake_Play.h"
#include "Sogo_Play.h"