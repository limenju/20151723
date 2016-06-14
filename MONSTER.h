#pragma once
#include "DEFINE.h"

class ORGANISM {
protected:
	int nPatType; // 패턴 형태
	int nPatIndex; // 이동 경로 인덱스
	int nPatStep; // 현재 스텝  
	int  nLife;             // 생명
	int nX, nY;            // 이동 좌표
	clock_t MoveTime;     // 이동 시간 간격
public:
	ORGANISM() {}
	int getLife() { return nLife; }
	int getX() { return nX; }
	int getY() { return nY; }
	clock_t getMoveTime() { return MoveTime; }

	void set_X(int x) { nX = x; }
	void set_Y(int y) { nY = y; }
	void add_Y() { nY++; }
	void set_MoveTime(clock_t a) { MoveTime = a; }

	int getnPatType() { return  nPatType; }
	int getnPatStep() { return  nPatStep; }
	int getnPatIndex() { return  nPatIndex; }

	void setnPatType(int x) { nPatType = x; }
	void setnPatStep(int x) {  nPatStep = x; }
	void setnPatIndex(int x) {  nPatIndex = x; }
	void setLife(int x) { nLife = x; }
	void addnPatStep() { nPatStep++; }
	//void addnPatStep() { nPatStep++; }
};
