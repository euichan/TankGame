#pragma once
#include "define.h"
class GameScene;
class Enemy
{
public:
	Enemy();
	~Enemy();
	void init(GameScene * context);
	void draw();
	void update(int t);
	void getDamage();
	
	Pos pos;

	int enemyLife;
	int enemyMove;
	int enemyFire;
	int nAppearanceTime;
	int nTypeIndex;
	int nPosIndex;

	int direction;
	GameScene * context;

	bool isDead;
};

