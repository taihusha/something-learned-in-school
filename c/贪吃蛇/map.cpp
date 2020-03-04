#include "tcs.h"

int count=0;
int poison_x, poison_y;
int str[20][40];
int rand_num_x[10] = { 0 }, rand_num_y[10] = { 0 };
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
	if (sleeptime == 200) {//打印第二关额外的墙体
		for (i = 0; i < 5; i++) {
			Pos(28, i + 3);
			printf("%c%c", 0xa8, 0x80);
		}
	}
	else if (sleeptime == 100) {//打印第三关额外的墙体
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
	if (sleeptime == 200) {//更改第二关的标记地图
		for (i = 0; i < 5; i++) {
			str[i + 3][28] = WALL;
		}
	}
	else if (sleeptime == 100) {//更改第三关的标记地图
		for (i = 0; i < 5; i++) {
			str[i + 3][28] = WALL;
			str[i + 11][4] = WALL;
		}
	}
}

void CreateFood() {//生成食物，☆
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

void CreateMine() {//生成炸弹，※
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

void CreatePoison() {//生成毒草，♂
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

