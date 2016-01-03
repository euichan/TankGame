#pragma once
#include "define.h"
class GameScene;
class Player
{
public:
	Player(GameScene * context);
	~Player();
	void update();
	void draw();
	void getDamage();
	int direction;
	char * image;
	Pos pos;
	GameScene * context;
	int hp;
	bool isDead;
};

