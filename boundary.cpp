#include"boundary.h"
#include"tools.h"

//���ƺ���߽�
void Boundary::BoundaryHyphen()
{
    SetCursorPosition(x_, y_);
    std::cout << "-";
}
//��������߽�
void Boundary::BoundaryVertical()
{
    SetCursorPosition(x_, y_);
    std::cout << "|";
}
//���ƽ�
void Boundary::BoundaryPlus()
{
    SetCursorPosition(x_, y_);
    std::cout << "+";
}
//�������ƶ�
void Boundary::MoveIn()
{
    y_ += 1;
}
//��õ��Yֵ
int Boundary::GetY()
{
    return y_;
}
//����߽磨����õ��ϵĻ���
void Boundary::BoundaryClear()
{
    SetCursorPosition(x_, y_);
    std::cout << " ";
}
