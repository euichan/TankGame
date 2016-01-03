#include "GameScene.h"

GameScene::GameScene(int stage)
{
	this->stage=stage;
	FILE* fp;
	int i, j;

	int nEnemyCount;				// 적 캐릭터 수
	int nBossX, nBossY;				// 보스 초기 위치

	player=new Player(this);

	//fp = fopen_s("map1.txt", "rt");
	fopen_s(&fp,"map1.txt","rt");
	fscanf_s(fp, "적 캐릭터수 : %d\n", &nEnemyCount);

	for (i = 0; i < nEnemyCount; i++)
	{
		Enemy * enemy = new Enemy();
		fscanf_s(fp, "%d %d\n", &enemy->pos.x, &enemy->pos.y);
		fscanf_s(fp, "타입인덱스: %d 적캐릭터 생성 인덱스: %d 출현 시간: %d\n", &enemy->nTypeIndex, &enemy->nPosIndex, &enemy->nAppearanceTime);
		enemy->init(this);
		enemyList.push_back(enemy);
	}
	fscanf_s(fp, "보스 초기 위치 : %d %d\n", &nBossX, &nBossY);
	fscanf_s(fp, "플레이어 초기 위치 : %d %d\n", &player->pos.x, &player->pos.y);

	for (i = 0; i < MAP_ROW; i++)
	{
		for (j = 0; j < MAP_COL; j++)
		{
			fscanf_s(fp, "%d ", &g_nMap[i][j]);
			if (g_nMap[i][j] == 1){
				Pos pos;
				pos.x = j;
				pos.y = i;
				Box * box = new Box(pos);
				boxList.push_back(box);
			}
			else if (g_nMap[i][j] == 4){
				Pos pos;
				pos.x = j;
				pos.y = i;
				point.pos = pos;
			}
		}
	}
	state = 0;
	fclose(fp);

	catchEnemys = 0;
	score = 0;
}


GameScene::~GameScene()
{
	for (auto iter = enemyList.begin(); iter != enemyList.end(); iter++) delete(*iter);
	for (auto iter = bulletList.begin(); iter != bulletList.end(); iter++) delete(*iter);
	for (auto iter = boxList.begin(); iter != boxList.end(); iter++) delete(*iter);
	delete(player);
}
void GameScene::update(int t){
	char string[100];
	sprintf_s( string, "깃발상태: %d", point.hp );
	ScreenPrint( 50, 2, string );
	sprintf_s( string, "주인공 생명력: %d", player->hp );
	ScreenPrint( 50, 4, string );
	sprintf_s( string, "적 탱크 수: %d", enemyList.size() );
	ScreenPrint( 50, 6, string );
	sprintf_s( string, "파괴된 탱크 수: %d", catchEnemys );
	ScreenPrint( 50, 8, string );
	sprintf_s( string, "점수: %d", score );
	ScreenPrint( 50, 10, string );
	collisionCheck();
	if(enemyList.size()==0) state=1;
	for (auto iter = enemyList.begin(); iter != enemyList.end(); iter++){
		(*iter)->update(t);
	}
	for (auto iter = bulletList.begin(); iter != bulletList.end(); iter++){
		(*iter)->update(t);
	}
	player->update();
}
void GameScene::collisionCheck(){

	for (auto biter = bulletList.begin(); biter != bulletList.end(); biter++){
		bool bulletPop = false;
		if (g_nMap[(*biter)->pos.y][(*biter)->pos.x] == 2){
			bulletPop=true;
			(*biter)->lastTouchImage="▥";
		}
		if ((*biter)->pos.x == point.pos.x && (*biter)->pos.y == point.pos.y){    //수호점과 총알충돌
			bulletPop = true;
			point.getDamage();
			point.draw();
			(*biter)->lastTouchImage="♨";
			if (point.isPop) state = -1;
		}

		for (auto iter = boxList.begin(); iter != boxList.end(); iter++){
			if (((*iter)->pos.x == (*biter)->pos.x) && ((*iter)->pos.y == (*biter)->pos.y)){   //박스와 총알충돌
				bulletPop = true;
				(*iter)->getDamage();
				(*iter)->draw();
				(*biter)->lastTouchImage="■";
				if ((*iter)->isPop){
					delete(*iter);
					iter = boxList.erase(iter);
					if (iter == boxList.end()) break;
				}
			}
		}
		if ((*biter)->type){
			for (auto iter = enemyList.begin(); iter != enemyList.end(); iter++){
				if((*iter)->nAppearanceTime>0) continue;
				if ((*iter)->pos.x == (*biter)->pos.x && (*iter)->pos.y == (*biter)->pos.y){ //적과 우리총알 충돌
					bulletPop = true;
					(*iter)->getDamage();
					(*iter)->draw();
					(*biter)->lastTouchImage="★";
					if ((*iter)->isDead){
						catchEnemys++;
						delete(*iter);
						iter=enemyList.erase(iter);
						if (iter == enemyList.end()) break;
					}
				}
			}
		}

		else{
			if ((*biter)->pos.x == player->pos.x && (*biter)->pos.y == player->pos.y){ //플레이어와 적총알충돌
				bulletPop = true;
				(*biter)->lastTouchImage="◈";
				player->getDamage();
				if (player->isDead) state = -1;
			}
		}

		if (bulletPop){
			delete(*biter);
			biter = bulletList.erase(biter);
			if (biter == bulletList.end()) break;
		}
	}

	for(auto iter=enemyList.begin(); iter!=enemyList.end(); iter++){
		if((*iter)->pos.x==player->pos.x && (*iter)->pos.y==player->pos.y) state=-1;
	}
}
void GameScene::draw(){
	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < MAP_COL; j++)
		{
			if (g_nMap[i][j] == 2){
				gotoxy(j * 2, i);
				printf("▥");
			}
		}
	}
	
	point.draw();
	for (auto iter = boxList.begin(); iter != boxList.end(); iter++){
		(*iter)->draw();
	}
	for (auto iter = bulletList.begin(); iter != bulletList.end(); iter++){
		(*iter)->draw();
	}
	player->draw();
}