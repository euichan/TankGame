#include "Bullet.h"

Bullet::Bullet(int direction,Pos pos, char* image,boolean type)
{
	this->type = type;
	this->pos = pos;
	this->direction = direction;
	this->image = image;

	draw();
}


Bullet::~Bullet()
{
	gotoxy(pos.x*2,pos.y);
	printf("%s",lastTouchImage);
}
void Bullet::update(int t){
	if (t % 10 == 0){
		gotoxy(pos.x*2,pos.y);
		printf("  ");
		switch (direction){
		case UP : 
			pos.y -= 1;
			break;
		case DOWN:
			pos.y += 1;
			break;
		case LEFT:
			pos.x -= 1;
			break;
		case RIGHT:
			pos.x += 1;
			break;
		}
		draw();
	}
}
void Bullet::draw(){
	gotoxy(pos.x*2, pos.y);
	printf("%s", image);
}