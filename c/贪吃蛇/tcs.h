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

struct snake {//蛇的数据结构
	int x;
	int y;
	struct snake *previous;
	struct snake *next;
}*head = NULL, *tail = NULL;

struct savescore {
	char name[20];
	int grade;
}person[3], temp, t;


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
void init(int n);
void gaming(int n);
void level(int n);
void Level_1();
void Level_2();
void Level_3();
void EndGame();
void Save();
void Load();
void ScoreSave();
void ScoreLoad();