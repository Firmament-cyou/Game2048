#include "tools.h"
#include <windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines)//设置窗口大小
{
    char cmd[30];
    //事实上，绘制图像时的xy轴与cmd的cols与lines定义相反
    sprintf(cmd, "mode con cols=%d lines=%d", lines, cols);//如果图形■占两个字符，则宽度lines乘以2
    system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void SetCursorPosition(int x, int y)//设置光标位置
{
    COORD position;
    //绘制图像时的xy轴与cmd的cols与lines定义相反
    position.X = y;
    position.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)//设置文本颜色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//设置文本背景色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
}
