#pragma once

#include "Screen.h"

class Sogo_Draw {
public:
	Sogo_Draw() {}
	void InitScreen();
	void ReadyScreen();
	void SuccessScreen();
	void PlayerTalk();
	void BossTalk();
	void ScreenLine();
	void ResultScreen();
};