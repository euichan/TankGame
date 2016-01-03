#pragma once
	#include <time.h>
	#include <conio.h>
	#include <Windows.h>
	#include <stdio.h>
	#include <iostream>
	#include <list>

using namespace std;

#define MAP_COL   23
#define MAP_ROW   18

#define BULLET_MOVE_TIME 100

enum _DIRECT { UP, DOWN, LEFT, RIGHT };
enum _STATE { ENEMY_STOP, ENEMY_RUN, ENEMY_ROTATION };

typedef struct pos
{
	int x, y;
}Pos;

inline void gotoxy(int x, int y)//내가 원하는 위치로 커서 이동
{
	COORD pos = { x , y };//커서가 X좌표에서 -1 한값. Y좌표에서 -1한 값으로 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API 함수입니다. 이건 알필요 없어요
}
inline int random(int from, int to){
	return rand() % (from - to) + from;
}
inline void ScreenPrint( int x, int y, char *string )
{
	gotoxy(x,y);
	printf("%s",string);
}