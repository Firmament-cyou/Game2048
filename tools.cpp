#include "tools.h"
#include <windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines)//���ô��ڴ�С
{
    char cmd[30];
    //��ʵ�ϣ�����ͼ��ʱ��xy����cmd��cols��lines�����෴
    sprintf(cmd, "mode con cols=%d lines=%d", lines, cols);//���ͼ�Ρ�ռ�����ַ�������lines����2
    system(cmd);//system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�
}

void SetCursorPosition(int x, int y)//���ù��λ��
{
    COORD position;
    //����ͼ��ʱ��xy����cmd��cols��lines�����෴
    position.X = y;
    position.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)//�����ı���ɫ
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//�����ı�����ɫ
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
}
