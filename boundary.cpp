#include"boundary.h"
#include"tools.h"

//绘制横向边界
void Boundary::BoundaryHyphen()
{
    SetCursorPosition(x_, y_);
    std::cout << "-";
}
//绘制纵向边界
void Boundary::BoundaryVertical()
{
    SetCursorPosition(x_, y_);
    std::cout << "|";
}
//绘制角
void Boundary::BoundaryPlus()
{
    SetCursorPosition(x_, y_);
    std::cout << "+";
}
//向画面中移动
void Boundary::MoveIn()
{
    y_ += 1;
}
//获得点的Y值
int Boundary::GetY()
{
    return y_;
}
//清除边界（如果用得上的话）
void Boundary::BoundaryClear()
{
    SetCursorPosition(x_, y_);
    std::cout << " ";
}
