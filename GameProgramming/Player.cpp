#include "Player.h"
#include "GameScene.h"
Player::Player(GameScene * context)
{
	this->context = context;
	image = "◈";
	isDead = false;

	hp=3;
}


Player::~Player()
{
}
void Player::update(){
	if (_kbhit()){
		int tmpX=0, tmpY=0;
		switch (_getch()){
		case 72 : //위
			gotoxy(pos.x*2,pos.y);
			printf("  ");
			tmpY -= 1;
			direction = UP;
			draw();
			break;
		case 80 : //아래
			gotoxy(pos.x*2,pos.y);
			printf("  ");
			tmpY += 1;
			direction = DOWN;
			draw();
			break;
		case 75 : // 왼쪽
			gotoxy(pos.x*2,pos.y);
			printf("  ");
			tmpX -= 1;
			direction = LEFT;
			draw();
			break;
		case 77 : // 오른쪽
			gotoxy(pos.x*2,pos.y);
			printf("  ");
			tmpX += 1;
			direction = RIGHT;
			draw();
			break;
		case 's' :
			Bullet * bullet;
			Pos tmp;
			tmp.x = pos.x;
			tmp.y = pos.y;

			switch (direction){
			case UP :
				tmp.y -= 1;
				bullet = new Bullet(direction, tmp, "↑", true);
				break;
			case DOWN:
				tmp.y += 1;
				bullet = new Bullet(direction, tmp, "↓", true);
				break;
			case LEFT:
				tmp.x -= 1;
				bullet = new Bullet(direction, tmp, "←", true);
				break;
			case RIGHT:
				tmp.x += 1;
				bullet = new Bullet(direction, tmp, "→", true);
				break;
			}
			context->bulletList.push_back(bullet);
			context->collisionCheck();
		}
		if (context->g_nMap[pos.y + tmpY][pos.x + tmpX] != 2 && context->g_nMap[pos.y + tmpY][pos.x + tmpX] != 1){
			gotoxy(pos.x*2,pos.y);
			printf("  ");
			pos.x+=tmpX;
			pos.y+=tmpY;
			draw();
		}
	}
}
void Player::draw(){
	gotoxy(pos.x*2, pos.y);
	printf("%s", image);
}
void Player::getDamage(){
	hp--;
	isDead = (hp > 0)? false : true;
}