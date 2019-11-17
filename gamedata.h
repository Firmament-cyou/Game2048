#ifndef GAMEDATA_H
#define GAMEDATA_H

#include<iostream>
#include<vector>

class GameData
{
public:
    GameData(): data_(4, std::vector<int>(4, 0)), databackup_(4, std::vector<int>(4, 0)) {}
    int GetData(int x, int y); //�õ�ĳ�������
    void GenerateNumber(); //��������µ�����
    bool UpMove(); //up�ƶ�������boolֵ��¼�Ƿ������ƶ�����ͬ
    bool DownMove(); //down�ƶ�
    bool LeftMove(); //left�ƶ�
    bool RightMove(); //right�ƶ�
    void Undo(); //����һ�β���
    int Victory(int mode); //�ж�ʤ��������ģʽ��Ϣ��
    int Lose(); //�ж�ʧ��
    void PrintData(); //�������
    void ClearData(); //��������
private:
    std::vector<std::vector<int>> data_; //��ά����data_�����������
    std::vector<std::vector<int>> databackup_; //�����һ�ε������Ա�undo
};

#endif // GAMEDATA_H
