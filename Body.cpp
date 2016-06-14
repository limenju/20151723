#include "Body.h"

void BODY::Init()
{
	//뱀초기값 입력
	snake_tail = new BODY();
	snake_tail->set_X(5);
	snake_tail->set_Y(3);
	snake_head = snake_tail;
	snake_tail = new BODY();
	snake_tail->set_X(4);
	snake_tail->set_Y(3);
	snake_tail->next = NULL;
	snake_head->next = snake_tail;
}

int BODY::move_snake(int dir)
{
	int tmp_x, tmp_y;
	int i;
	BODY *tmp_body;


	tmp_x = snake_head->nX;
	tmp_y = snake_head->nY;

	switch (direction)
	{
	case 1:
		tmp_y--;
		break;
	case 2:
		tmp_x--;
		break;
	case 3:
		tmp_x++;
		break;
	case 4:
		tmp_y++;
		break;
	}
	i = strike_check(tmp_x, tmp_y, NULL);
	if (i == 1) //충돌할때
	{
		return 1;
	}

	gotoxy((snake_tail->nX * 2) + abs_x, snake_tail->nY + abs_y); //이동후의 잔상지우기
	printf("  ");



	gotoxy(77, 23);  //화면 깨짐을 막기위함
	fflush(stdout);

	SetColor(GRAY);
	gotoxy((snake_head->nX * 2) + abs_x, snake_head->nY + abs_y); //이동후의 머리모양 잔상지우기
	printf("○");
	gotoxy(tmp_x * 2 + abs_x, tmp_y + abs_y); //머리모양 프린트하기
	printf("●");
	gotoxy(77, 23);  //화면 깨짐을 막기위함
	SetColor(BLACK);


	tmp_body = new BODY(); //머리부분의 새로운 노드만들기
	tmp_body->nX = tmp_x;
	tmp_body->nY = tmp_y;
	tmp_body->next = snake_head;
	snake_head = tmp_body;


	while (tmp_body->next != snake_tail)  //꼬리노드 지우기
		tmp_body = tmp_body->next;

	tmp_body->next = NULL;
	free(snake_tail);
	snake_tail = tmp_body;

	return i;
}

int BODY::strike_check(int x, int y, Food* food)
{
	BODY *tmp_body;

	if (x<0 || x>34 || y<0 || y>19)  //머리가 벽에 부닥침
		return 1;

	tmp_body = snake_head;
	while (tmp_body != NULL)
	{
		if ((tmp_body->nX == x) && (tmp_body->nY == y))
			return 1;
		tmp_body = tmp_body->next;
	}

	if (food->getX() == x && food->getY() == y) //먹이를 물었음
		return 2;

	return 0;
}

int BODY::make_tail(int dir)
{
	int tmp_x, tmp_y;
	int i;
	BODY *tmp_body;


	tmp_x = snake_head->nX;
	tmp_y = snake_head->nY;
	switch (direction)
	{
	case 1:
		tmp_y--;
		break;
	case 2:
		tmp_x--;
		break;
	case 3:
		tmp_x++;
		break;
	case 4:
		tmp_y++;
		break;
	}
	i = strike_check(tmp_x, tmp_y, NULL);
	if (i == 1) //충돌할때
	{
		return 1;
	}


	gotoxy(77, 23);  //화면 깨짐을 막기위함
	fflush(stdout);

	SetColor(GRAY);
	gotoxy((snake_head->nX * 2) + abs_x, snake_head->nY + abs_y); //이동후의 머리모양 잔상지우기
	printf("○");
	gotoxy(tmp_x * 2 + abs_x, tmp_y + abs_y); //머리모양 프린트하기
	printf("●");
	gotoxy(77, 23);  //화면 깨짐을 막기위함
	SetColor(BLACK);


	tmp_body = new BODY(); //머리부분의 새로운 노드만들기
	tmp_body->nX = tmp_x;
	tmp_body->nY = tmp_y;
	tmp_body->next = snake_head;
	snake_head = tmp_body;

	return i;
}

int BODY::free_all()
{
	BODY *tmp1, *tmp2;

	tmp1 = snake_head;
	tmp2 = snake_head->next;
	while (tmp2 != NULL)
	{
		free(tmp1);
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	return 0;
}

int BODY::gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void BODY::SetColor(int color)

{
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);
}