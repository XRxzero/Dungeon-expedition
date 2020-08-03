#include "tools.h"
#include <Windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines)//设置窗口大小
{
	system("title Dungeon expedition");//设置窗口标题
	char cmd[30];
	sprintf_s(cmd, 30, "mode con cols=%d lines=%d", cols * 2, lines);//一个汉字占两个字符，故宽度乘以2
	system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void SetCursorPosition(const int x, const int y)//设置光标位置
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)//设置文本颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}
