#include "tcs.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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