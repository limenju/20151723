#include "Draw.h"



int Draw::show_game_frame(int abs_y)
{
	int i;
	SetColor(GRAY);
	system("cls");
	gotoxy(0, 1);
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	for (i = 2; i<22; i++)
	{
		gotoxy(0, i);
		printf("早");
		
		gotoxy(72, i);
		printf("早");
	}
	gotoxy(0, 20 + abs_y);
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

	for (i = 4; i<20; i += 2)
	{
		gotoxy(76, i);
		printf("∞");
	}

	for (i = 5; i<20; i += 2)
	{
		gotoxy(75, i);
		printf("∞");
	}
	gotoxy(75, 2);
	printf("��");
	gotoxy(75, 3);
	printf("≒");

	gotoxy(4, 0);
	printf("Snake Ver 0.1                                    Made By Jae-Dong");
	return 0;
}

int Draw::gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void Draw::SetColor(int color)

{
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);
}