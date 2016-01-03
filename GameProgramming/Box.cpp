#include "Box.h"

Box::Box(Pos pos)
{
	this->pos = pos;
	hp = 3;
	isPop = false;
}


Box::~Box()
{
	gotoxy(pos.x*2,pos.y);
	printf("  ");
}

void Box::draw(){
	gotoxy(pos.x*2,pos.y);
	printf("бс");
}
void Box::getDamage(){
	hp--;
	isPop = (hp > 0) ? false : true;
}
