#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //获取句柄

#define U 1
#define D 2
#define L 3 
#define R 4    //蛇的状态，U：上 ；D：下；L:左 R：右

#define ESC 27
#define ENTER 13
#define FLOOR 0
#define WALL 1
#define SNAKE 2
#define FOOD 3
#define MINE 4
#define POISON 5

int poison_x, poison_y;
int rand_num_x[10] = { 0 }, rand_num_y[10] = { 0 };
int end = 0, length = 0, score = 0, count = 0;
int str[20][40];
int direction = R;
int sleeptime = 400;//每次运行的时间间隔
FILE * mem;     //游戏存档文件句柄
FILE *fp;

void FirstPage();
void Choose();
void ChooseLevel();
void CreateMap();
void MarkMap();
void AddSnake(int a, int b);
void CreateSnake();
void DeleteTail();
void CreateFood();
void CreateMine();
void CreatePoison();
void Shine();
void SnakeMove();
void pause();
void RunGame();
void Level_1();
void Level_2();
void Level_3();
void EndGame();
void Save();
void Load();
void ScoreSave();
void ScoreLoad();

void Pos(int x, int y) {     //设置光标位置
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

void Setcolor(int color) {//  实现彩色的函数  
	SetConsoleTextAttribute(hConsole, color);
}

void HideCursor() {    //隐藏光标
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

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
	while ((key = _getch()) != ENTER) {
		if (GetAsyncKeyState(VK_UP))
			key = U;
		else if (GetAsyncKeyState(VK_DOWN))
			key = D;
		if (key == U && option > 1) option--;
		if (key == D && option < 2) option++;
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
	case('1'):system("cls");  Level_1(); break;
	case('2'):system("cls");   Level_2(); break;
	case('3'):system("cls");  Level_3(); break;
	case('n'):end = 5; EndGame(); break;
	}
	printf("\n\n\t");
	system("cls");
}

void CreateMap() {             //打印地图
	int i;
	Setcolor(11);
	for (i = 0; i < 38; i = i + 2) {  //打印上下边框
		Pos(i, 0);
		printf("%c%c", 0xa8, 0x80);
		Pos(i, 19);
		printf("%c%c", 0xa8, 0x80);
	}
	for (i = 1; i < 19; i++) {
		Pos(0, i);
		printf("%c%c", 0xa8, 0x80);
		Pos(36, i);
		printf("%c%c", 0xa8, 0x80);
	}
	if (sleeptime == 200) {
		for (i = 0; i < 5; i++) {
			Pos(28, i + 3);
			printf("%c%c", 0xa8, 0x80);
		}
	}
	else if (sleeptime == 100) {
		for (i = 0; i < 5; i++) {
			Pos(28, i + 3);
			printf("%c%c", 0xa8, 0x80);
			Pos(4, i + 11);
			printf("%c%c", 0xa8, 0x80);
		}
	}
	Setcolor(15);
}

void MarkMap() {             //标记
	int i, j;
	for (i = 0; i < 19; i++)
		for (j = 0; j < 36; j++)
			str[i][j] = FLOOR;
	for (j = 0; j <= 36; j = j + 2) {
		str[0][j] = WALL;
		str[19][j] = WALL;
	}
	for (i = 0; i <= 19; i++) {
		str[i][0] = WALL;
		str[i][36] = WALL;
	}
	i = 0;
	if (sleeptime == 200) {
		for (i = 0; i < 5; i++) {
			str[i + 3][28] = WALL;
		}
	}
	else if (sleeptime == 100) {
		for (i = 0; i < 5; i++) {
			str[i + 3][28] = WALL;
			str[i + 11][4] = WALL;
		}
	}
}

struct snake {
	int x;
	int y;
	struct snake *previous;
	struct snake *next;
}*head = NULL, *tail = NULL;

void AddSnake(int a, int b) {    //增加一节蛇头 
	snake *temp = (snake *)malloc(sizeof(snake));
	temp->x = a;
	temp->y = b;
	temp->next = NULL;
	if (head == NULL) {
		tail = head = temp;
		head->next = NULL;
	}
	else {
		head->next = temp;
		temp->previous = head;
		head = head->next;
	}
	str[b][a] = SNAKE;
	Pos(a, b);
	printf("%c%c", 0xa8, 0x80);
	length++;
}

void CreateSnake() {     //初始化蛇身 
	AddSnake(4, 4);
	AddSnake(6, 4);
	AddSnake(8, 4);
	AddSnake(10, 4);
	length = 4;
}

void DeleteTail() {    //删除尾节点 
	struct snake *temp = NULL;
	Pos(tail->x, tail->y);
	printf("  ");
	str[tail->y][tail->x] = FLOOR;
	temp = tail;
	tail = tail->next;
	tail->previous = NULL;
	free((void *)temp);
	length--;
}

void CreateFood() {
	int food_x, food_y;
	srand((unsigned int)time(0));
	food_x = rand() % 34 + 1;
	while (food_x % 2 != 0) food_x = rand() % 34 + 1;
	food_y = rand() % 18 + 1;
	while (str[food_y][food_x] != FLOOR) {
		food_x = rand() % 34 + 1;
		while (food_x % 2 != 0) food_x = rand() % 34 + 1;
		food_y = rand() % 18 + 1;
	}
	str[food_y][food_x] = FOOD;
	Setcolor(14);
	Pos(food_x, food_y);
	printf("☆");
	Setcolor(15);
}

void CreateMine() {
	int mine_x, mine_y;
	srand((unsigned int)time(0));
	mine_x = rand() % 34 + 1;
	while (mine_x % 2 != 0) mine_x = rand() % 34 + 1;
	mine_y = rand() % 18 + 1;
	while (str[mine_y][mine_x] != FLOOR) {
		mine_x = rand() % 34 + 1;
		while (mine_x % 2 != 0) mine_x = rand() % 34 + 1;
		mine_y = rand() % 18 + 1;
	}
	str[mine_y][mine_x] = MINE;
	Setcolor(12);
	Pos(mine_x, mine_y);
	printf("※");
	Setcolor(15);
}

void CreatePoison() {
	int count_x = 0, count_y = 0;
	int j = 0, flag = 1, i;
	srand((unsigned)time(NULL));
	while (count_x < 10) {
		poison_x = rand() % 34 + 1;
		while (poison_x % 2 != 0) poison_x = rand() % 34 + 1;
		for (j = 0; j < 10; j++) {
			if (poison_x == rand_num_x[j]) {
				flag = 0;
				break;
			}
			else {
				flag = 1;
			}
		}
		if (flag) {
			rand_num_x[count_x] = poison_x;
			count_x++;
		}
	}
	while (count_y < 10) {
		poison_y = rand() % 18 + 1;
		for (j = 0; j < 10; j++) {
			if (poison_y == rand_num_y[j]) {
				flag = 0;
				break;
			}
			else {
				flag = 1;
			}
		}
		if (flag) {
			rand_num_y[count_y] = poison_y;
			count_y++;
		}
	}
	if (count % 2 == 0) {
		for (j = 0; j < 10; j++) {
			if (str[rand_num_y[j]][rand_num_x[j]] == FLOOR) {
				str[rand_num_y[j]][rand_num_x[j]] = POISON;
				Pos(rand_num_x[j], rand_num_y[j]);
				Setcolor(8);
				printf("♂");
			}
		}
	}
	else if (count != 2) {
		for (i = 0; i < 38; i = i + 2)
			for (j = 1; j < 19; j++) {
				if (str[j][i] == POISON) {
					Pos(i, j);
					printf("  ");
					str[j][i] = FLOOR;
				}
			}
	}
	Setcolor(15);
}

void Shine() {   //毒草闪烁函数
	int i, j;
	if (count <= 50) {
		if (count % 2 == 0) {
			for (j = 0; j < 10; j++) {
				if (str[rand_num_y[j]][rand_num_x[j]] == FLOOR) {
					str[rand_num_y[j]][rand_num_x[j]] = POISON;
					Pos(rand_num_x[j], rand_num_y[j]);
					Setcolor(8);
					printf("♂");
				}
			}
		}
		else if (count != 2) {
			for (i = 0; i < 38; i = i + 2)
				for (j = 1; j < 19; j++) {
					if (str[j][i] == POISON) {
						Pos(i, j);
						printf("  ");
						str[j][i] = FLOOR;
					}
				}
		}
	}
	else if (count > 50) {
		for (i = 0; i < 38; i = i + 2)
			for (j = 1; j < 19; j++) {
				if (str[j][i] == POISON) {
					Pos(i, j);
					printf("  ");
					str[j][i] = FLOOR;
				}
			}
	}
	Setcolor(15);
}

void SnakeMove() {
	int a, b, i, j;
	a = head->x;
	b = head->y;
	switch (direction) {
	case(U):b--; break;
	case(D):b++; break;
	case(L):a = a - 2; break;
	case(R):a = a + 2; break;
	}
	int t = str[b][a];
	if (t == FLOOR) {
		AddSnake(a, b);
		DeleteTail();
	}
	else if (t == WALL) {
		end = 2;
		EndGame();
	}
	else if (t == FOOD) {
		AddSnake(a, b);
		CreateFood();
		score = score + 10;
		str[b][a] = SNAKE;
	}
	else if (t == MINE) {
		if (length == 1) {
			end = 3;
			score = score - 10;
			EndGame();
		}
		else {
			AddSnake(a, b);
			str[b][a] = SNAKE;
			if (length % 2 == 0) i = length / 2;
			else i = (length - 1) / 2;
			j = length;
			while (j > i) {
				DeleteTail();
				j--;
			}
			score = score - 10;
			CreateMine();
		}
	}
	else if (t == POISON) {
		if (length == 1) {
			end = 4;
			score = score - 5;
			EndGame();
		}
		else {
			AddSnake(a, b);
			str[b][a] = SNAKE;
			DeleteTail();
			DeleteTail();
			score = score - 5;
		}
	}
	else if (t == SNAKE) {
		end = 1;
		EndGame();
	}

}

void pause() {//暂停
	while (1) {
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE)) {
			break;
		}
	}
}

void RunGame() {
	if (sleeptime == 400) Level_1();
	if (sleeptime == 200) Level_2();
	if (sleeptime == 100) Level_3();
}

void Level_1() {
	sleeptime = 400;
	CreateMap();
	MarkMap();
	CreateSnake();
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
	CreateFood();
	CreateMine();
	CreatePoison();
	CreateFood();
	CreateMine();
	CreateFood();
	CreateMine();
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
		sleeptime = 200;
		system("cls");
		Pos(20, 6);
		printf("恭喜你通过第一关，下面进入第二关");
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
		Level_2();
	}
}

void Level_2() {
	sleeptime = 200;
	MarkMap();
	CreateMap();
	CreateSnake();
	Pos(50, 3);
	printf("不能穿墙，不能咬到自己");
	Pos(50, 5);
	printf("当蛇长度达到10时进入下一关");
	Pos(50, 7);
	printf("请用↑.↓.←.→键控制蛇的移动，空格键暂停");
	Pos(50, 9);
	printf("☆代表食物，吃到食物蛇身增加一个单位,得分加10分");
	Pos(50, 11);
	printf("※代表地雷，踩到地雷蛇身减少一半,得分减10分");
	Pos(50, 13);
	printf("♂代表毒草，吃到毒草蛇身减少一个单位,得分减5分");
	CreateFood();
	CreateMine();
	CreateMine();
	CreatePoison();
	CreateFood();
	CreateMine();
	CreateFood();
	CreateMine();
	CreateMine();
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
		sleeptime = 100;
		system("cls");
		Pos(20, 6);
		printf("恭喜你通过第二关，下面进入第三关");
		Pos(28, 8);
		system("pause")
			; system("cls");
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
		Level_3();
	}
}

void Level_3() {
	sleeptime = 100;
	MarkMap();
	CreateMap();
	CreateSnake();
	Pos(50, 3);
	printf("不能穿墙，不能咬到自己");
	Pos(50, 5);
	printf("当蛇长度达到10时通关");
	Pos(50, 7);
	printf("请用↑.↓.←.→键控制蛇的移动，空格键暂停");
	Pos(50, 9);
	printf("☆代表食物，吃到食物蛇身增加一个单位,得分加10分");
	Pos(50, 11);
	printf("※代表地雷，踩到地雷蛇身减少一半,得分减10分");
	Pos(50, 13);
	printf("♂代表毒草，吃到毒草蛇身减少一个单位,得分减5分");
	CreateFood();
	CreateMine();
	CreatePoison();
	CreateMine();
	CreateMine();
	CreateFood();
	CreateMine();
	CreateFood();
	CreateMine();
	CreateMine();
	CreateMine();
	CreateMine();
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
	if (length == 10) {
		system("cls");
		end = 6;
		EndGame();
	}
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
		printf("是否结束游戏?(按“y”结束)\n\n\t\t      ");
	}
	exit(0);
}

void Save() {
	if ((mem = fopen("memory.txt", "wb")) == NULL) {
		printf("无法打开memory.txt!\n");
		fclose(mem);
	}
	else {
		fwrite(&sleeptime, sizeof(sleeptime), 1, mem);
		fwrite(&score, sizeof(score), 1, mem);
		fclose(mem);
	}
}

void Load() {
	if ((mem = fopen("memory.txt", "rb")) == NULL) {//读取游戏存档
		printf("\n\n\n\n\t\t无存档\n");
		fclose(mem);
	}
	else {
		fread(&sleeptime, sizeof(sleeptime), 1, mem);
		fread(&score, sizeof(score), 1, mem);
		fclose(mem);
	}
}

struct savescore {
	char name[20];
	int grade;
}person[3], temp, t;

void ScoreSave() {
	int i;
	if ((fp = fopen("排行榜.txt", "ab+")) == NULL) {
		printf("无法打开排行榜.txt!\n");
		fclose(fp);
	}
	else {
		Pos(12, 5);
		printf("请输入玩家的名字：\n\n\t\t");
		scanf("%s", temp.name);
		fp = fopen("排行榜.txt", "ab+");
		fread(&person[0], sizeof(person[0]), 1, fp);
		fread(&person[1], sizeof(person[1]), 1, fp);
		fread(&person[2], sizeof(person[2]), 1, fp);
		fclose(fp);
		if (person[0].grade == 0)
		{
			person[0].grade = score;
			person[1].grade = 0;
			person[2].grade = 0;
			strcpy(person[0].name, temp.name);
		}
		else if (person[1].grade == 0) {
			person[1].grade = score;
			person[2].grade = 0;
			strcpy(person[1].name, temp.name);
		}
		else if (person[2].grade == 0) {
			person[2].grade = score;
			strcpy(person[2].name, temp.name);
		}
		else if (score > person[2].grade) {
			person[2].grade = score;
			strcpy(person[2].name, temp.name);
		}
		if (person[2].grade > person[1].grade) {
			t.grade = person[2].grade;
			person[2].grade = person[1].grade;
			person[1].grade = t.grade;
			strcpy(t.name, person[2].name);
			strcpy(person[2].name, person[1].name);
			strcpy(person[1].name, t.name);
		}
		if (person[1].grade > person[0].grade) {
			t.grade = person[1].grade;
			person[1].grade = person[0].grade;
			person[0].grade = t.grade;
			strcpy(t.name, person[1].name);
			strcpy(person[1].name, person[0].name);
			strcpy(person[0].name, t.name);
		}
		if ((fp = fopen("排行榜.txt", "wb")) == NULL) {
			printf("无法打开排行榜.txt!\n");
			fclose(fp);
		}
		else {
			for (i = 0; i < 3; i++)
				fwrite(&person[i], sizeof(savescore), 1, fp);
			fclose(fp);
		}
	}
	printf("\n\n\t  ");
	system("cls");
}

void ScoreLoad() {
	int i, flag = 0;
	if ((fp = fopen("排行榜.txt", "rb+")) == NULL) {
		printf("\n\n\n\t\t\t\t  暂无游戏记录\n");
		fclose(fp);
	}
	else {
		fp = fopen("排行榜.txt", "rb+");
		for (i = 0; i < 3; i++)
			fread(&person[i], sizeof(savescore), 1, fp);
		Pos(50, 5);
		printf("   排行榜\n");
		for (i = 0; i < 3; i++) {
			Pos(50, 7 + 2 * i);
			printf("第%d名  %-10s：%6d", i + 1, person[i].name, person[i].grade);
			//}
		}
		fclose(fp);
	}
}

int main() {
	system("mode con cols=100 lines=30");
	system("COLOR 0B"); //设置背景
	HideCursor();//隐藏光标
	FirstPage();//游戏首页
	Choose();
	EndGame();
	system("pause");
	return 0;
}