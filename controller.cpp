#include<windows.h>
#include<conio.h>
#include"controller.h"
#include"tools.h"
#include"start_interface.h"
#include"gamedata.h"

using namespace std;

int Controller::Start() //��ʼ����
{
    system("title 2048"); //������
    SetWindowSize(20, 28); //���ô��ڴ�С
    SetColor(15); //������ɫ
    StartInterface* start = new StartInterface();
    (*start).Print();
    delete start; //�ͷ��ڴ�ռ�

    //���ơ�Start���͡�Exit�������ҿ�ѡ
    int current_option = 0; //��¼��ǰѡ��
    SetCursorPosition(13, 9);
    SetBackColor(); //��һ��ѡ�����ñ���ɫ��ʾѡ��
    cout << "S T A R T";
    SetCursorPosition(16, 9);
    SetColor(15); //������ɫ
    cout << "E X I T";
    cin.clear(); cin.sync(); //������뻺��
    int ch; //���ռ�������
    bool enter_flag = false; //�Ƿ�����enter
    while((ch = getch()))
    {
        switch(ch)
        {
        case 13: //����enter
            enter_flag = true;
            break;
        case 72: //UP�����
            if(current_option == 0) break;
            else
            {
                current_option -= 1;
                SetCursorPosition(13, 9);
                SetBackColor();
                cout << "S T A R T";
                SetCursorPosition(16, 9);
                SetColor(15);
                cout << "E X I T";
                break;
            }
        case 80: //DOWN�����
            if(current_option == 1) break;
            else
            {
                current_option += 1;
                SetCursorPosition(16, 9);
                SetBackColor();
                cout << "E X I T";
                SetCursorPosition(13, 9);
                SetColor(15);
                cout << "S T A R T";
                break;
            }
        default: //��Ч����
            break;
        }
        SetCursorPosition(18, 0); //���߹��
        if(enter_flag) break; //����enter��ѭ��
    }
    return current_option; //Ϊ0ʱ��ʼ��Ϸ��Ϊ1ʱ�˳���Ϸ
}

int Controller::Mode() //��Ϸģʽ
{
    //����2048������
    SetCursorPosition(0, 0);
    SetColor(15);
    cout << "                           \n"
         << "                           \n"
         << "  ����Ҫ��лÿһλ���     \n"
         << "  Ը����������������     \n"
         << "  ����Ϸ~ Thanks           \n"
         << "                           \n"
         << "  ����˵����               \n"
         << "  �������һ�WASD�ƶ�       \n"
         << "  U�����Գ���һ�β���      \n"
         << "                           \n"
         << "  ������~                \n";
    for(int i = 12; i < 19; ++i)
    {
        cout << "                          \n";
    }
    //��2048�� & ��Unlimited��
    SetCursorPosition(13, 2);
    SetColor(15);
    cout << "ѡ��ģʽ: ";
    SetCursorPosition(16, 15);
    cout << "Unlimited";
    SetCursorPosition(13, 15);
    SetBackColor();
    cout << "2048";
    cin.clear(); cin.sync(); //������뻺��
    int current_option = 0; //��¼��ǰѡ��
    int ch;
    bool enter_flag = false;
    while((ch = getch()))
    {
        switch(ch)
        {
        case 13: //����enter
            enter_flag = true;
            break;
        case 72: //UP�����
            if(current_option == 0) break;
            else
            {
                current_option -= 1;
                SetCursorPosition(13, 15);
                SetBackColor();
                cout << "2048";
                SetCursorPosition(16, 15);
                SetColor(15);
                cout << "Unlimited";
                break;
            }
        case 80: //DOWN�����
            if(current_option == 1) break;
            else
            {
                current_option += 1;
                SetCursorPosition(16, 15);
                SetBackColor();
                cout << "Unlimited";
                SetCursorPosition(13, 15);
                SetColor(15);
                cout << "2048";
                break;
            }
        default: //��Ч����
            break;
        }
        SetCursorPosition(18, 0); //���߹��
        if(enter_flag) break; //����enter��ѭ��
    }
    return current_option; //Ϊ0ʱ2048ģʽ��Ϊ1ʱUnlimitedģʽ
}

void Controller::Border()
{
    SetCursorPosition(1, 0);
    SetColor(15);
    cout << " +-----+-----+-----+-----+\n"
         << " |     |     |     |     |\n"
         << " |     |     |     |     |\n"
         << " |     |     |     |     |\n"
         << " +-----+-----+-----+-----+\n"
         << " |     |     |     |     |\n"
         << " |     |     |     |     |\n"
         << " |     |     |     |     |\n"
         << " +-----+-----+-----+-----+\n"
         << " |     |     |     |     |\n"
         << " |     |     |     |     |\n"
         << " |     |     |     |     |\n"
         << " +-----+-----+-----+-----+\n"
         << " |     |     |     |     |\n"
         << " |     |     |     |     |\n"
         << " |     |     |     |     |\n"
         << " +-----+-----+-----+-----+";
}

int Controller::GameNumber(int mode)
{
    GameData* gamedata = new GameData();
    (*gamedata).GenerateNumber(); //�����������
    (*gamedata).PrintData(); //�����ʼ����
    int ch;
    while((ch = getch()))
    {
        switch(ch)
        {
        case 119:
        case 72: //UP
            if((*gamedata).UpMove())
            {
                (*gamedata).GenerateNumber();
                (*gamedata).ClearData();
                (*gamedata).PrintData();
                int end_status = 0;
                end_status = (*gamedata).Victory(mode);
                if(end_status) return end_status;
                end_status = (*gamedata).Lose();
                if(end_status) return end_status;
            }
            break;
        case 115:
        case 80: //DOWN
            if((*gamedata).DownMove())
            {
                (*gamedata).GenerateNumber();
                (*gamedata).ClearData();
                (*gamedata).PrintData();
                int end_status = 0;
                end_status = (*gamedata).Victory(mode);
                if(end_status) return end_status;
                end_status = (*gamedata).Lose();
                if(end_status) return end_status;
            }
            break;
        case 97:
        case 75: //LEFT
            if((*gamedata).LeftMove())
            {
                (*gamedata).GenerateNumber();
                (*gamedata).ClearData();
                (*gamedata).PrintData();
                int end_status = 0;
                end_status = (*gamedata).Victory(mode);
                if(end_status) return end_status;
                end_status = (*gamedata).Lose();
                if(end_status) return end_status;
            }
            break;
        case 100:
        case 77: //RIGHT
            if((*gamedata).RightMove())
            {
                (*gamedata).GenerateNumber();
                (*gamedata).ClearData();
                (*gamedata).PrintData();
                int end_status = 0;
                end_status = (*gamedata).Victory(mode);
                if(end_status) return end_status;
                end_status = (*gamedata).Lose();
                if(end_status) return end_status;
            }
            break;
        case 117: //Undo
            (*gamedata).Undo();
            (*gamedata).ClearData();
            (*gamedata).PrintData();
        default:
            break;
        }
    }
}

//��Ϸ����
void Controller::Game()
{
    int start_exit = Start();
    if(start_exit == 0) //��ʼ��Ϸ
    {
        while(1) //��Ϸѭ��
        {
            int mode_choose = Mode();
            Border();
            int end_status = GameNumber(mode_choose);
            if(end_status == 1) continue;
            if(end_status == 2) break;
        }
    }
}
