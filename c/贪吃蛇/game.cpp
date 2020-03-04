#include "tcs.h"

int direction=R,end=0,sleeptime=400;
void pause() {//暂停
	while (1) {
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE)) {
			break;
		}
	}
}

void init(int n) {//对游戏进程的初始化
	CreateMap();
	MarkMap();
	CreateSnake();
	count=0;
	printText();
	CreateFood();
	CreatePoison();
	CreateFood();
	for(int i=0;i<n;i++){
		CreateMine();
	}
	CreateFood();
	pause();
}
void printText() {
	Pos(50, 3);
	printf("不能穿墙，不能咬到自己");
	Pos(50, 5);
	printf("当蛇长度达到10时进入下一关");
	Pos(50, 7);
	printf("请用↑.↓.←.→键控制蛇的移动,空格键暂停");
	Pos(50, 9);
	printf("☆代表食物，吃到食物蛇身增加一个单位,得分加10分");
	Pos(50, 11);
	printf("※代表地雷，踩到地雷蛇身减少一半,得分减10分");
	Pos(50, 13);
	printf("♂代表毒草，吃到毒草蛇身减少一个单位,得分减5分");
}
void gaming(int num){//表示游戏进行中，num:关卡数
	while (length<10) {
		count++;
		Shine();
		Pos(50, 15);
		printf("分数：%d", score);
		SnakeMove();
		Sleep(sleeptime);
		if (GetAsyncKeyState(VK_UP) && direction != D)
			direction = U;
		else if (GetAsyncKeyState(VK_DOWN) && direction != U)
			direction = D;
		else if (GetAsyncKeyState(VK_LEFT) && direction != R)
			direction = L;
		else if (GetAsyncKeyState(VK_RIGHT) && direction != L)
			direction = R;
		else if (GetAsyncKeyState(VK_SPACE))
			pause();
		if (_kbhit()) {
			if (_getch() == ESC) {//按ESC存档并退出 
				Save();    //存档
				free(head);
				system("cls");
				Pos(8, 10);
				printf("存档中...\n");
				exit(0);
			}
		}
	}
	if (length >= 10) {
		switch (num) {
		case 1:
			sleeptime=200;
			break;
		case 2:
			sleeptime=100;
			break;
		case 3:
			system("cls");
			end = 6;
			EndGame();
		default:
			break;
		}
		system("cls");
		Pos(20, 6);
		printf("恭喜你通过第%d关，下面进入第%d关",num,num+1);
		Pos(28, 8);
		system("pause");
		system("cls");
		int i, j;
		for (i = 0; i < 38; i = i + 2)
			for (j = 1; j < 19; j++)
				str[j][i] = FLOOR;
		direction = R;
		snake *p, *t;
		p = tail;
		p->previous = NULL;
		for (i = 1; i <= length; i++) {
			t = p;
			p = p->next;
			free((void *)t);
		}
		head = NULL;
		RunGame();
	}

}
//3 food,1 poison,mine(1:3,2:5,3:8)
void level(int num){
	switch (num)
	{
	case 1:
		sleeptime = 400;
		init(3);
		break;
	case 2:
		sleeptime = 200;
		init(5);
		break;
	case 3:
		sleeptime = 100;
		init(8);
		break;
	default:
		break;
	}
	gaming(num);
}
void RunGame() {
	if (sleeptime == 400) level(1);
	if (sleeptime == 200) level(2);
	if (sleeptime == 100) level(3);
}
void EndGame() {
	system("COLOR 0B");
	int option = 1;
	system("cls");
	ScoreSave();
	Pos(10, 6);
	if (end == 1) printf("对不起，你咬到自己了，游戏结束。");
	else if (end == 2) printf("对不起，你撞到墙了，游戏结束。");
	else if (end == 3)printf("对不起，你被地雷炸死了，游戏结束");
	else if (end == 4)printf("对不起，你被毒死了，游戏结束");
	else if (end == 5)printf("         游戏结束");
	else if (end == 6) printf("    恭喜你，游戏胜利！");
	printf("\n\n\t\t你的得分是%d", score);
	ScoreLoad();
	Pos(12, 10);
	while (getchar() != 'y') {
		printf("是否结束游戏?(按“y”结束)\n\n\t\t");
	}
	free(head);
	Setcolor(15);
	exit(0);
}