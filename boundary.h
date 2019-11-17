#ifndef BOUNDARY_H
#define BOUNDARY_H

#include<iostream>

class Boundary
{
public:
    //初始化函数
    Boundary() {}
    Boundary(const int x, const int y): x_(x), y_(y) {}
    //绘制横向边界
    void BoundaryHyphen();
    //绘制纵向边界
    void BoundaryVertical();
    //绘制角
    void BoundaryPlus();
    //向画面中移动
    void MoveIn();
    //获得点的Y值
    int GetY();
    //清除边界（如果用得上的话）
    void BoundaryClear();
private:
    int x_, y_;
};

#endif // BOUNDARY_H
