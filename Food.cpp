#include "Food.h"
#include "Body.h"

int Food::make_food(int abs_x ,int abs_y, Food* food)
{
	BODY* Body = new BODY();

	while (Body->strike_check(nX, nY, food) == 1)
	{
		nY = rand() % 20;
		nX = rand() % 35;
	}

	gotoxy(77, 23);  //È­¸é ±úÁüÀ» ¸·±âÀ§ÇÔ
	fflush(stdout);

	SetColor(RED);
	gotoxy(nX * 2 + abs_x, nY + abs_y);
	printf("¡ß");
	SetColor(BLACK);
	return 0;
}

int Food::gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void Food::SetColor(int color)

{
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);
}