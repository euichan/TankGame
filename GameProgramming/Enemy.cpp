#include "Enemy.h"
#include "GameScene.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
	gotoxy(pos.x*2,pos.y);
	printf("  ");
}
void Enemy::getDamage(){
	enemyLife--;
	isDead = (enemyLife > 0) ? false : true;
}
void Enemy::init(GameScene * context){
	this->context = context;
	if (nTypeIndex == 0){
		enemyLife = 2;
		enemyMove = 80;
		enemyFire = 200;
	}
	else {
		enemyLife = 3;
		enemyMove = 70;
		enemyFire = 250;
	}
	isDead = false;
	direction=random(0,4);

	//생명력: 2 이동시간 간격: 800 미사일: 2000
	//생명력: 3 이동시간 간격 : 700 미사일 : 2500
}
void Enemy::update(int t){
	if(nAppearanceTime-->0){
		if(nAppearanceTime<=0) draw();
		return ;
	}
	if (t%enemyMove == 0){
		int tmpX=0, tmpY=0;

		switch (direction){
		case UP :
			tmpY -= 1;
			break;
		case DOWN:
			tmpY += 1;
			break;
		case LEFT:
			tmpX -= 1;
			break;
		case RIGHT:
			tmpX += 1;
			break;
		}
		if (context->g_nMap[pos.y + tmpY][pos.x + tmpX] == 2 || context->g_nMap[pos.y + tmpY][pos.x + tmpX] == 1){
			int tmpDirect = direction;
			while (tmpDirect == direction) tmpDirect = random(0, 4);
			direction = tmpDirect;
		}else{
			gotoxy(pos.x*2,pos.y);
			printf("  ");
			pos.x+=tmpX;
			pos.y+=tmpY;
			draw();
		}
	}
	if (t%enemyFire==0){
		Bullet * bullet;
		Pos tmp;
		tmp.x = pos.x;
		tmp.y = pos.y;

		switch (direction){
		case UP :
			tmp.y -= 1;
			bullet = new Bullet(direction, tmp, "↑", false);
			break;
		case DOWN:
			tmp.y += 1;
			bullet = new Bullet(direction, tmp, "↓", false);
			break;
		case LEFT:
			tmp.x -= 1;
			bullet = new Bullet(direction, tmp, "←", false);
			break;
		case RIGHT:
			tmp.x += 1;
			bullet = new Bullet(direction, tmp, "→", false);
			break;
		}
		context->bulletList.push_back(bullet);
		context->collisionCheck();
	}
}
void Enemy :: draw(){
	gotoxy(pos.x*2,pos.y);
	printf("★");
}