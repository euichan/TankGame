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

inline void gotoxy(int x, int y)//���� ���ϴ� ��ġ�� Ŀ�� �̵�
{
	COORD pos = { x , y };//Ŀ���� X��ǥ���� -1 �Ѱ�. Y��ǥ���� -1�� ������ �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API �Լ��Դϴ�. �̰� ���ʿ� �����
}
inline int random(int from, int to){
	return rand() % (from - to) + from;
}
inline void ScreenPrint( int x, int y, char *string )
{
	gotoxy(x,y);
	printf("%s",string);
}