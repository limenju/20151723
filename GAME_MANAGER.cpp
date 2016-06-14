#include "GAME_MANAGER.h"

void GAME_MANAGER::Init()
{
	state = Start;

	pScene = new InitScene(0);
}

void GAME_MANAGER::Release()
{
	delete pScene;
}

int GAME_MANAGER::Render()
{
	Init();

	while (1)
 	{
		switch (state)
		{
		case Start:
		{
		int	num = pScene->Render();

			if (num == 1) state = Snake_Play;
			else if (num == 2) state = Sogo_Play;
			else return 0;

			break;
		}
		case Snake_Play:
			pScene = new MainScene(1);
			pScene->Render();
			state = Exit;
			
			break;

		case Sogo_Play:
			pScene = new MainScene(2);
			pScene->Render();
			state = Exit;

			break;
		case Exit:
				pScene->GameOver();

			break;

		default:
			break;
		}

	}
}