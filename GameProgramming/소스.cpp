
#include "GameScene.h"

void ReadyScreen();
void Box();
void InitScreen();
void SuccessScreen();
void FailureScreen();
void ResultScreen();
void ScreenPrint( int x, int y, char *string );

int g_nStage=1;
int g_nTotalGrade=0;

void main(){
	int i = 1;
	
	InitScreen();
	_getch();
	while(1){
		GameScene * context=new GameScene(g_nStage);
		system("cls");
		ReadyScreen();
		_getch();
		system("cls");
		context->draw();
		while (context->state==0){
			i++;
			context->update(i);
			Sleep(10);
		}
		if(context->state==1){
			g_nTotalGrade+=context->score;
			if(g_nStage>=2){
				ResultScreen();
				_getch();
				exit(0);
			}
			SuccessScreen();
			_getch();
			g_nStage++;
		}
		else{
			FailureScreen();
			char ch=_getch();
			if(ch=='n') exit(0);
		}
		delete(context);
	}
}
void Box()
{
	int i;
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	for (i =1; i <= 19; i++)
		ScreenPrint(0, i, "┃                                                        ┃");
	ScreenPrint(0, 20, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void InitScreen()
{
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                                        ┃\n");
	printf("┃         -----                                          ┃\n");
	printf("┃        /    |                                       /  ┃\n");
	printf("┃       /       |    탱크 게임                       /   ┃\n");
	printf("┃      /          |                            /-----/   ┃\n");
	printf("┃     /            |---------------|         /           ┃\n");
	printf("┃    /                               |      /            ┃\n");
	printf("┃   /              ┏━━━━━┓      |   /             ┃\n");
	printf("┃  /               ┃          ┃       |/               ┃\n");
	printf("┃/                 ┃    ◎    ┃                        ┃\n");
	printf("┃     ( (    ┏━━━━━━━━━━━┓     ) )          ┃\n");
	printf("┃            ┃                      ┃                  ┃\n");
	printf("┃           ▤ ▤                   ▤ ▤                ┃\n");
	printf("┃           ▤ ▤ ━━━━━━━━━▤ ▤                ┃\n");
	printf("┃           ▤ ▤                   ▤ ▤                ┃\n");
	printf("┃  ~ ^ ~ $~ ~ ^ ~ ~ ~ ^ ~ ~ ~ ^ ~ ~ ~ ^~ ~ ~ ~ ~ $ ~    ~┃\n");
	printf("┃                                                        ┃\n");
	printf("┃                  Press Space Key !!                    ┃\n");
	printf("┃                                                        ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void ReadyScreen()
{
	char string[100];
	Box();
	sprintf_s(string, "%d 스테이지", g_nStage);
	ScreenPrint(25, 9, string);
}

void SuccessScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                                        ┃");
	ScreenPrint(0, 2, "┃                                                        ┃");
	ScreenPrint(0, 3, "┃                                                        ┃");
	ScreenPrint(0, 4, "┃                                                        ┃");
	ScreenPrint(0, 5, "┃                                                        ┃");
	ScreenPrint(0, 6, "┃                                                        ┃");
	ScreenPrint(0, 7, "┃                                                        ┃");
	ScreenPrint(0, 8, "┃                     ////＼＼                           ┃");
	ScreenPrint(0, 9, "┃                    q ∧. ∧ p (^)@                     ┃");
	ScreenPrint(0, 10, "┃                    (└──┘) //                       ┃");
	ScreenPrint(0, 11, "┃                   ♬ 미션 성공 ♪                      ┃");
	ScreenPrint(0, 12, "┃                                                        ┃");
	ScreenPrint(0, 13, "┃                                                        ┃");
	ScreenPrint(0, 14, "┃                                                        ┃");
	ScreenPrint(0, 15, "┃                                                        ┃");
	ScreenPrint(0, 16, "┃                                                        ┃");
	ScreenPrint(0, 17, "┃                                                        ┃");
	ScreenPrint(0, 18, "┃                                                        ┃");
	ScreenPrint(0, 19, "┃                                                        ┃");
	ScreenPrint(0, 20, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void FailureScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                                        ┃");
	ScreenPrint(0, 2, "┃                                                        ┃");
	ScreenPrint(0, 3, "┃                                                        ┃");
	ScreenPrint(0, 4, "┃                                                        ┃");
	ScreenPrint(0, 5, "┃                                                        ┃");
	ScreenPrint(0, 6, "┃                                                        ┃");
	ScreenPrint(0, 7, "┃                    미션 실패 !!!!                      ┃");
	ScreenPrint(0, 8, "┃                                                        ┃");
	ScreenPrint(0, 9, "┃                                                        ┃");
	ScreenPrint(0, 10, "┃                               ●┳━┓                 ┃");
	ScreenPrint(0, 11, "┃                                 ┛  ┗                 ┃");
	ScreenPrint(0, 12, "┃                                ■■■■                ┃");
	ScreenPrint(0, 13, "┃                                                        ┃");
	ScreenPrint(0, 14, "┃                                                        ┃");
	ScreenPrint(0, 15, "┃                                                        ┃");
	ScreenPrint(0, 16, "┃                계속 하시겠습니까? (y/n)                ┃");
	ScreenPrint(0, 17, "┃                                                        ┃");
	ScreenPrint(0, 18, "┃                                                        ┃");
	ScreenPrint(0, 19, "┃                                                        ┃");
	ScreenPrint(0, 20, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}


void ResultScreen()
{
	char string[100];

	Box();

	ScreenPrint(3, 3, "                     탱크 게임 끝");
	ScreenPrint(3, 6, "                    ┏━━━━━┓");
	ScreenPrint(3, 7, "               ~~   ┃          ┃");
	ScreenPrint(3, 8, "        ~~          ┃    ◎    ┃");
	ScreenPrint(3, 9, "    ●         ┏━━━━━━━━━━━┓");
	ScreenPrint(3, 10, "  ┗┃┛       ┃                      ┃");
	ScreenPrint(3, 11, "   ┏┓      ▤ ▤                   ▤ ▤");
	ScreenPrint(3, 12, "             ▤ ▤ ━━━━━━━━━▤ ▤");
	ScreenPrint(3, 13, "             ▤ ▤                   ▤ ▤");
	ScreenPrint(3, 14, "~ ~ ^ ~ $~ ~ ^ ~ ~ ~ ^ ~ ~ ~ ^ ~ ~ ~ ^~ ~ ~ ~ /~ $ ~~");
	sprintf_s(string, "Score : %d", g_nTotalGrade);
	ScreenPrint(39, 7, string);
}
