#pragma once
#include "Scene.h"
#include "InitScene.h"
#include "MainScene.h"
#include "ExitScene.h"

typedef enum {Start, Snake_Play, Sogo_Play, Exit} State;

class GAME_MANAGER
{
	Scene* pScene;
	State state;
public:
	void Init();
	int Render();
	void Release();
};