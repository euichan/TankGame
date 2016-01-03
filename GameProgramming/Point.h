#pragma once
#include "define.h"
class Point
{
public:
	Point();
	~Point();
	void draw();
	void getDamage();
	Pos pos;
	int hp;
	int isPop;
};

