#include "tcs.h"

int length=0,score=0;
snake *head=NULL,*tail=NULL;
void AddSnake(int a, int b) {    //添加蛇头
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

void CreateSnake() {     //创建蛇
	AddSnake(4, 4);
	AddSnake(6, 4);
	AddSnake(8, 4);
	AddSnake(10, 4);
	length = 4;
}

void DeleteTail() {    //删除蛇尾
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
void SnakeMove() {//蛇的移动
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