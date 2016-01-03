#pragma once
#include "define.h"
class Box
{
public:
	Box(Pos pos);
	~Box();
	void draw();
	void getDamage();
	bool isPop;
	int hp;
	Pos pos;
};