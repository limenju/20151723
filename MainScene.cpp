#include "MainScene.h"

void MainScene::Init()
{
	if (sort_game == 1) pGame = new Snake_Play();
	else if (sort_game == 2) pGame = new Sogo_Play();
}

int MainScene::Render()
{
	Init();

	pGame->Render();

	return 0;
}


void MainScene::Gameover() { 

	pGame->Gameover(); 

	Release();
}

void MainScene::Release()
{
	delete pGame;
}
int MainScene::gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void MainScene::SetColor(int color)

{
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);
}