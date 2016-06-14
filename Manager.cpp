#include "Manager.h"

//int manager::Update(int i)
//{
//	int return_tmp = 0;
//
//	if (i%speed == 0)
//	{
//		if (return_tmp == 2) //꼬리가 늘어남
//		{
//			return_tmp = Me->make_tail(Me->get_dr());
//		}
//		else {
//			fflush(stdin);
//
//			return_tmp = Me->move_snake(Me->get_dr()); //단순히 이동
//		}
//
//		last_direction = Me->get_dr();
//
//		if (return_tmp == 1)  //충돌할때
//		{
//			sceen->show_gameover();
//			free_all();
//			return 0;
//		}
//		if (return_tmp == 2)  //먹이를 먹었을때
//		{
//			if (length % 5 == 0)
//				speed--;
//
//			if (speed<1)
//				speed = 1;
//
//			length++;
//			food->make_food(Me->abs_x, Me->abs_y, food);
//			i = 1; //스피드관련 변수 초기화
//		}
//	}
//	return i;
//}
//
//void manager::SetupInput()
//{
//	char keytemp;
//
//	if (kbhit())
//	{
//		keytemp = getche();
//
//		if (keytemp == EXT_KEY)
//		{
//			printf("\b");
//			keytemp = getche();
//			switch (keytemp)
//			{
//			case KEY_UP:
//				if (last_direction != 4)
//					Me->set_dr(1);
//
//				break;
//			case KEY_LEFT:
//				if (last_direction != 3)
//					Me->set_dr(2);
//				break;
//			case KEY_RIGHT:
//				if (last_direction != 2)
//					Me->set_dr(3);
//
//				break;
//			case KEY_DOWN:
//				if (last_direction != 1)
//					Me->set_dr(4);
//				break;
//			}
//		}
//	}
//}
//
//void manager::Render()
//{
//	int num;
//
//	init();
//
//	gotoxy(77, 23);
//	printf(" \b");
//	sceen->show_game_frame(Me->abs_y);
//	food->make_food(Me->abs_x, Me->abs_y, food);
//
//	for (int i = 1; 1; i++)
//	{
//		SetupInput();
//
//		num = Update(i);
//
//		if (num != 0) i = num;
//		else return;
//
//		SetColor(BLACK);
//		gotoxy(77, 23);
//		Sleep(10);
//		SetColor(BLACK);
//		gotoxy(77, 23);
//	}
//}
//
//int manager::init()
//{
//	Me = new BODY();
//	sceen = new Draw();
//	food = new Food();
//
//	srand(time(NULL));
//
//	//전역변수 초기화
//	length = 1;
//	speed = 25;
//	Me->set_dr(3);
//	last_direction = Me->get_dr();
//
//	Me->Init();
//
//	return 0;
//}
//
//int manager::free_all()
//{
//	Me->free_all();
//
//	return 0;
//}
//
//int manager::gotoxy(int x, int y)
//{
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos;
//	pos.Y = y;
//	pos.X = x;
//	SetConsoleCursorPosition(hConsole, pos);
//	return 0;
//}
//
//void manager::SetColor(int color)
//
//{
//	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(std_output_handle, color);
//}