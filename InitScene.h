#pragma once
#include "Scene.h"
#include "Define.h"

class InitScene : public Scene
{
	int input;
public:
	InitScene() {}
	InitScene(int x) {}
	void Init();
	int Render();
	void Release() {}

};