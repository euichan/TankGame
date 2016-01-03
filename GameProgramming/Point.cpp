#include "Point.h"


Point::Point()
{
	isPop = false;
	hp=2;
}


Point::~Point()
{
}
void Point::draw(){
	gotoxy(pos.x*2, pos.y);
	printf("ขอ");
}
void Point::getDamage(){
	hp--;
	isPop = (hp > 0) ? false : true;
}