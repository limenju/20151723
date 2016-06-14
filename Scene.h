#pragma once
class Scene
{
public:
	Scene() {}
	Scene(int x) {}
	virtual void Init() = 0;
	virtual int Render() = 0;
	virtual void Release() = 0;
	virtual void GameOver() {}
};