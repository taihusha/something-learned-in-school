#include "tcs.h"

void FirstPage() {        //游戏首页
	printf("\n\n\n\n\n\t欢迎来到贪吃蛇游戏！\n");
	printf("\n\t请用方向键控制上下左右\n\n\t");
	printf(" 按回车键开始游戏\n\n\t");
	getchar();
	system("cls");
}

void Choose() {
	int key, option = 1;    //默认是新建游戏 
	Pos(5, 5);
	printf("新游戏");
	Pos(13, 5);
	printf("->");
	Pos(5, 7);
	printf("继续游戏");
    Pos(5,9);
    printf("按ESC退出游戏");
	while ((key = _getch()) != ENTER) {
		if (GetAsyncKeyState(VK_UP))
			key = U;
		else if (GetAsyncKeyState(VK_DOWN))
			key = D;
		if (key == U && option > 1) option--;
		if (key == D && option < 2) option++;
        if (key == ESC) {
			system("cls");
			Setcolor(15);
			exit(0);
		}
		if (option == 1) {
			Pos(13, 5);
			printf(" ->");
			Pos(13, 7);
			printf("   ");
		}
		else {
			Pos(13, 7);
			printf(" ->");
			Pos(13, 5);
			printf("   ");
		}
	}
	system("cls");
	if (option == 1) ChooseLevel();//选择关卡
	else {
		Load();
		CreateMap();
		MarkMap();
		RunGame();
		system("pause");
	}
}

void ChooseLevel() {
	char key;
	printf("\n\n\n\t请选择关卡：(难度1-3)\n\n\n\t(若想要退出请输入n)\n\n\n\t\t");
	scanf("%c", &key);
	switch (key) {
	case('1'):system("cls");  level(1); break;
	case('2'):system("cls");   level(2); break;
	case('3'):system("cls");  level(3); break;
	case('n'):end = 5; EndGame(); break;
	}
	printf("\n\n\t");
	system("cls");
}


