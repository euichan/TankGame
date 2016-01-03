#pragma once
#include "define.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "Box.h"
#include "Point.h"
class GameScene 
{
public:
	GameScene(int stage);
	~GameScene();
	void update(int t);
	void draw();
	void collisionCheck(); 
	int g_nMap[MAP_ROW][MAP_COL];
	
	Player * player;
	Point point;
	list <Enemy *> enemyList;
	list <Bullet *> bulletList;
	list <Box *> boxList;

	int stage;
	int state;
	int catchEnemys;
	int score;
};

