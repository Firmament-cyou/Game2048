#include<windows.h>
#include<conio.h>
#include"controller.h"
#include"tools.h"
#include"start_interface.h"
#include"gamedata.h"

using namespace std;

int Controller::Start() //开始界面
{
    system("title 2048"); //窗口名
    SetWindowSize(20, 28); //设置窗口大小
    SetColor(15); //设置颜色
    StartInterface* start = new StartInterface();
    (*start).Print();
    delete start; //释放内存空间

    //绘制“Start”和“Exit”，并且可选
    int current_option = 0; //记录当前选项
    SetCursorPosition(13, 9);
    SetBackColor(); //第一个选项设置背景色表示选中
    cout << "S T A R T";
    SetCursorPosition(16, 9);
    SetColor(15); //字体颜色
    cout << "E X I T";
    cin.clear(); cin.sync(); //清空输入缓存
    int ch; //接收键盘输入
    bool enter_flag = false; //是否输入enter
    while((ch = getch()))
    {
        switch(ch)
        {
        case 13: //输入enter
            enter_flag = true;
            break;
        case 72: //UP方向键
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
        case 80: //DOWN方向键
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
        default: //无效按键
            break;
        }
        SetCursorPosition(18, 0); //移走光标
        if(enter_flag) break; //接收enter出循环
    }
    return current_option; //为0时开始游戏，为1时退出游戏
}

int Controller::Mode() //游戏模式
{
    //绘制2048并清屏
    SetCursorPosition(0, 0);
    SetColor(15);
    cout << "                           \n"
         << "                           \n"
         << "  首先要感谢每一位玩家     \n"
         << "  愿意玩做这款粗制滥造     \n"
         << "  的游戏~ Thanks           \n"
         << "                           \n"
         << "  操作说明：               \n"
         << "  上下左右或WASD移动       \n"
         << "  U键可以撤销一次操作      \n"
         << "                           \n"
         << "  玩得愉快~                \n";
    for(int i = 12; i < 19; ++i)
    {
        cout << "                          \n";
    }
    //“2048” & “Unlimited”
    SetCursorPosition(13, 2);
    SetColor(15);
    cout << "选择模式: ";
    SetCursorPosition(16, 15);
    cout << "Unlimited";
    SetCursorPosition(13, 15);
    SetBackColor();
    cout << "2048";
    cin.clear(); cin.sync(); //清空输入缓存
    int current_option = 0; //记录当前选项
    int ch;
    bool enter_flag = false;
    while((ch = getch()))
    {
        switch(ch)
        {
        case 13: //输入enter
            enter_flag = true;
            break;
        case 72: //UP方向键
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
        case 80: //DOWN方向键
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
        default: //无效按键
            break;
        }
        SetCursorPosition(18, 0); //移走光标
        if(enter_flag) break; //接收enter出循环
    }
    return current_option; //为0时2048模式，为1时Unlimited模式
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
    (*gamedata).GenerateNumber(); //随机生成数字
    (*gamedata).PrintData(); //输出初始数据
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

//游戏运行
void Controller::Game()
{
    int start_exit = Start();
    if(start_exit == 0) //开始游戏
    {
        while(1) //游戏循环
        {
            int mode_choose = Mode();
            Border();
            int end_status = GameNumber(mode_choose);
            if(end_status == 1) continue;
            if(end_status == 2) break;
        }
    }
}
