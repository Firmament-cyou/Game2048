#ifndef GAMEDATA_H
#define GAMEDATA_H

#include<iostream>
#include<vector>

class GameData
{
public:
    GameData(): data_(4, std::vector<int>(4, 0)), databackup_(4, std::vector<int>(4, 0)) {}
    int GetData(int x, int y); //得到某格的数据
    void GenerateNumber(); //随机生成新的数字
    bool UpMove(); //up移动，返回bool值记录是否发生过移动，下同
    bool DownMove(); //down移动
    bool LeftMove(); //left移动
    bool RightMove(); //right移动
    void Undo(); //撤销一次操作
    int Victory(int mode); //判定胜利（接收模式信息）
    int Lose(); //判定失败
    void PrintData(); //输出数组
    void ClearData(); //擦除数组
private:
    std::vector<std::vector<int>> data_; //二维向量data_用来存放数据
    std::vector<std::vector<int>> databackup_; //存放上一次的数据以便undo
};

#endif // GAMEDATA_H
