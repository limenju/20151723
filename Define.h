#pragma once



#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;

//*********************************
//��� ����
//*********************************
#define EXT_KEY   0xffffffe0 //Ȯ��Ű �νİ� 
#define KEY_LEFT  0x4b
#define KEY_RIGHT  0x4d
#define KEY_UP   0x48
#define KEY_DOWN  0x50

enum {
	BLACK,      /*  0 : ��� */
	DARK_BLUE,    /*  1 : ��ο� �Ķ� */
	DARK_GREEN,    /*  2 : ��ο� �ʷ� */
	DARK_SKY_BLUE,  /*  3 : ��ο� �ϴ� */
	DARK_RED,    /*  4 : ��ο� ���� */
	DARK_VOILET,  /*  5 : ��ο� ���� */
	DARK_YELLOW,  /*  6 : ��ο� ��� */
	GRAY,      /*  7 : ȸ�� */
	DARK_GRAY,    /*  8 : ��ο� ȸ�� */
	BLUE,      /*  9 : �Ķ� */
	GREEN,      /* 10 : �ʷ� */
	SKY_BLUE,    /* 11 : �ϴ� */
	RED,      /* 12 : ���� */
	VOILET,      /* 13 : ���� */
	YELLOW,      /* 14 : ��� */
	WHITE,      /* 15 : �Ͼ� */
};

enum DIRECT {
	UP = 0, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT,
	LEFT, UP_LEFT
};

enum GAME_STATE {
	INIT = 0, READY, RUNNING, PLAYER_TALK, BOSS_TALK, BOSS_WAR,
	STOP, SUCCESS, FAILED, RESULT
};