#include "InitScene.h"

void InitScene::Init()
{
	input = 0;
}
int InitScene::Render()
{

	cout << "������ �����մϴ�" << endl;
	cout << "1�� - Snake" << endl;
	cout << "2�� - Sogo" << endl;

	cin >> input;

	return input;
}