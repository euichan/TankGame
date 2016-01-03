#pragma once
#include "define.h"
class Bullet
{
public:
	Bullet(int direction, Pos pos,char * image,boolean type);
	~Bullet();
	void update(int t);
	void draw();
	int direction;
	Pos pos;
	boolean type;
	char *image;

	char * lastTouchImage;
};

