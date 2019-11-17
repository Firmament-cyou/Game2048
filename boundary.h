#ifndef BOUNDARY_H
#define BOUNDARY_H

#include<iostream>

class Boundary
{
public:
    //��ʼ������
    Boundary() {}
    Boundary(const int x, const int y): x_(x), y_(y) {}
    //���ƺ���߽�
    void BoundaryHyphen();
    //��������߽�
    void BoundaryVertical();
    //���ƽ�
    void BoundaryPlus();
    //�������ƶ�
    void MoveIn();
    //��õ��Yֵ
    int GetY();
    //����߽磨����õ��ϵĻ���
    void BoundaryClear();
private:
    int x_, y_;
};

#endif // BOUNDARY_H
