#ifndef STARTINTERFACE_H
#define STARTINTERFACE_H

#include<iostream>
#include<vector>
#include"boundary.h"

class StartInterface
{
public:
    StartInterface(): interval_(50)
    {
        //以下均为初始化，开始界面2048的位置
        start_hyphen.emplace_back(2, -23); //2
        start_hyphen.emplace_back(2, -22);
        start_hyphen.emplace_back(2, -21);
        start_hyphen.emplace_back(2, -20);
        start_plus.emplace_back(2, -19);
        start_vertical.emplace_back(3, -19);
        start_vertical.emplace_back(4, -19);
        start_vertical.emplace_back(5, -19);
        start_plus.emplace_back(6, -19);
        start_hyphen.emplace_back(6, -20);
        start_hyphen.emplace_back(6, -21);
        start_hyphen.emplace_back(6, -22);
        start_plus.emplace_back(6, -23);
        start_vertical.emplace_back(7, -23);
        start_vertical.emplace_back(8, -23);
        start_vertical.emplace_back(9, -23);
        start_plus.emplace_back(10, -23);
        start_hyphen.emplace_back(10, -22);
        start_hyphen.emplace_back(10, -21);
        start_hyphen.emplace_back(10, -20);
        start_hyphen.emplace_back(10, -19);

        start_plus.emplace_back(2, -17); //0
        start_hyphen.emplace_back(2, -16);
        start_hyphen.emplace_back(2, -15);
        start_hyphen.emplace_back(2, -14);
        start_plus.emplace_back(2, -13);
        start_vertical.emplace_back(3, -13);
        start_vertical.emplace_back(4, -13);
        start_vertical.emplace_back(5, -13);
        start_vertical.emplace_back(6, -13);
        start_vertical.emplace_back(7, -13);
        start_vertical.emplace_back(8, -13);
        start_vertical.emplace_back(9, -13);
        start_plus.emplace_back(10, -13);
        start_hyphen.emplace_back(10, -14);
        start_hyphen.emplace_back(10, -15);
        start_hyphen.emplace_back(10, -16);
        start_plus.emplace_back(10, -17);
        start_vertical.emplace_back(9, -17);
        start_vertical.emplace_back(8, -17);
        start_vertical.emplace_back(7, -17);
        start_vertical.emplace_back(6, -17);
        start_vertical.emplace_back(5, -17);
        start_vertical.emplace_back(4, -17);
        start_vertical.emplace_back(3, -17);

        start_vertical.emplace_back(2, -11); //4
        start_vertical.emplace_back(3, -11);
        start_vertical.emplace_back(4, -11);
        start_vertical.emplace_back(5, -11);
        start_plus.emplace_back(6, -11);
        start_hyphen.emplace_back(6, -10);
        start_hyphen.emplace_back(6, -9);
        start_hyphen.emplace_back(6, -8);
        start_vertical.emplace_back(2, -7);
        start_vertical.emplace_back(3, -7);
        start_vertical.emplace_back(4, -7);
        start_vertical.emplace_back(5, -7);
        start_plus.emplace_back(6, -7);
        start_vertical.emplace_back(7, -7);
        start_vertical.emplace_back(8, -7);
        start_vertical.emplace_back(9, -7);
        start_vertical.emplace_back(10, -7);

        start_plus.emplace_back(2, -5); //8
        start_hyphen.emplace_back(2, -4);
        start_hyphen.emplace_back(2, -3);
        start_hyphen.emplace_back(2, -2);
        start_plus.emplace_back(2, -1);
        start_vertical.emplace_back(3, -1);
        start_vertical.emplace_back(4, -1);
        start_vertical.emplace_back(5, -1);
        start_plus.emplace_back(6, -1);
        start_vertical.emplace_back(7, -1);
        start_vertical.emplace_back(8, -1);
        start_vertical.emplace_back(9, -1);
        start_plus.emplace_back(6, -5);
        start_hyphen.emplace_back(10, -2);
        start_hyphen.emplace_back(10, -3);
        start_hyphen.emplace_back(10, -4);
        start_plus.emplace_back(10, -5);
        start_vertical.emplace_back(9, -5);
        start_vertical.emplace_back(8, -5);
        start_vertical.emplace_back(7, -5);
        start_plus.emplace_back(10, -1);
        start_vertical.emplace_back(5, -5);
        start_vertical.emplace_back(4, -5);
        start_vertical.emplace_back(3, -5);
        start_hyphen.emplace_back(6, -4);
        start_hyphen.emplace_back(6, -3);
        start_hyphen.emplace_back(6, -2);
    }
    //输出界面
    void Print();
private:
    std::vector<Boundary> start_hyphen;
    std::vector<Boundary> start_vertical;
    std::vector<Boundary> start_plus;
    int interval_; //时间间隔
};

#endif // STARTINTERFACE_H
