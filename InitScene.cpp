#include "InitScene.h"

void InitScene::Init()
{
	input = 0;
}
int InitScene::Render()
{

	cout << "게임을 시작합니다" << endl;
	cout << "1번 - Snake" << endl;
	cout << "2번 - Sogo" << endl;

	cin >> input;

	return input;
}