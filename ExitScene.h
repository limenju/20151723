#pragma once
#include "Define.h"
#include "Scene.h"

class ExitScene : public Scene
{
public:
	ExitScene() {}
	ExitScene(int x) {}
	void Init() {}
	int Render() { printf("∞‘¿” ≥°~"); }
	void Release() {}
};