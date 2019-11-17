#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<iostream>

class Controller
{
public:
    Controller() {}
    //绘制开始界面
    int Start();
    //绘制模式界面
    int Mode();
    //绘制数字边框
    void Border();
    //循环输出其中的数字
    //接收游戏模式，并返回结束状态（1为循环，2为退出）
    int GameNumber(int mode);
    //游戏运行
    void Game();
private:
};
#endif // CONTROLLER_H
