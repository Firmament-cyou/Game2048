#include<cstdlib>
#include<time.h>
#include<conio.h>
#include"gamedata.h"
#include"tools.h"

using namespace std;

int GameData::GetData(int x, int y) //得到某格的数据
{
    return data_[x][y];
}
void GameData::GenerateNumber() //随机生成新的数字
{
    srand((unsigned)time(0)); //使用当前时间作为无符号整型的种子
    //取出所有为0的点并记录，再在其中随机一个点赋值
    vector<int> zerox;
    vector<int> zeroy;
    int zero_count = 0;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(data_[i][j] == 0)
            {
                zerox.emplace_back(i);
                zeroy.emplace_back(j);
                zero_count += 1;
            }
        }
    }
    int lucky_place = (rand() % zero_count); //选定空位
    //生成2 or 4 （概率上4 : 1好了）
    if(rand() % 5) data_[zerox[lucky_place]][zeroy[lucky_place]] = 2;
    else data_[zerox[lucky_place]][zeroy[lucky_place]] = 4;
    zerox.clear(); zeroy.clear(); //清空临时数组
}
bool GameData::UpMove() //up移动
{
    vector<vector<int>> buffer_ = data_; //将移动前的数组保存
    bool move_flag = false; //用以储存是否发生移动并输出
    int temp; //临时储存
    vector<int> merge_out; //输出数组
    for(int j = 0; j < 4; ++j)
    {
        //合并数字
        temp = 0;
        for(int i = 0; i < 4; ++i)
        {
            if(data_[i][j] == 0) continue; //空位跳过
            else if(temp == 0) //无待合并数字
            {
                temp = data_[i][j];
            }
            else if(data_[i][j] == temp) //有待合并数字且需合并
            {
                merge_out.emplace_back(2 * temp);
                temp = 0;
            }
            else //有待合并数字且不需合并
            {
                merge_out.emplace_back(temp);
                temp = data_[i][j];
            }
        }
        merge_out.emplace_back(temp); //别忘了最后一个temp也要入数组
        while(merge_out.size() < 4) merge_out.emplace_back(0); //末尾补0
        //输出数字
        for(int i = 0; i < 4; ++i)
        {
            if(data_[i][j] == merge_out[i]) continue; //相同不需更改
            else
            {
                data_[i][j] = merge_out[i];
                move_flag = true; //发生移动
            }
        }
        merge_out.clear(); //清空数组
    }
    if(move_flag) databackup_ = buffer_; //发生移动则备份数组更新
    return move_flag;
}
bool GameData::DownMove() //down移动
{
    vector<vector<int>> buffer_ = data_;
    bool move_flag = false; //用以储存是否发生移动并输出
    int temp; //临时储存
    vector<int> merge_out; //输出数组
    for(int j = 0; j < 4; ++j)
    {
        //合并数字
        temp = 0;
        for(int i = 3; i >= 0; --i)
        {
            if(data_[i][j] == 0) continue; //空位跳过
            else if(temp == 0) //无待合并数字
            {
                temp = data_[i][j];
            }
            else if(data_[i][j] == temp) //有待合并数字且需合并
            {
                merge_out.emplace_back(2 * temp);
                temp = 0;
            }
            else //有待合并数字且不需合并
            {
                merge_out.emplace_back(temp);
                temp = data_[i][j];
            }
        }
        merge_out.emplace_back(temp);
        while(merge_out.size() < 4) merge_out.emplace_back(0); //末尾补0
        //输出数字
        for(int i = 3; i >= 0; --i)
        {
            if(data_[i][j] == merge_out[3 - i]) continue; //相同不需更改
            else
            {
                data_[i][j] = merge_out[3 - i];
                move_flag = true; //发生移动
            }
        }
        merge_out.clear(); //清空数组
    }
    if(move_flag) databackup_ = buffer_;
    return move_flag;
}
bool GameData::LeftMove() //left移动
{
    vector<vector<int>> buffer_ = data_;
    bool move_flag = false; //用以储存是否发生移动并输出
    int temp; //临时储存
    vector<int> merge_out; //输出数组
    for(int i = 0; i < 4; ++i)
    {
        //合并数字
        temp = 0;
        for(int j = 0; j < 4; ++j)
        {
            if(data_[i][j] == 0) continue; //空位跳过
            else if(temp == 0) //无待合并数字
            {
                temp = data_[i][j];
            }
            else if(data_[i][j] == temp) //有待合并数字且需合并
            {
                merge_out.emplace_back(2 * temp);
                temp = 0;
            }
            else //有待合并数字且不需合并
            {
                merge_out.emplace_back(temp);
                temp = data_[i][j];
            }
        }
        merge_out.emplace_back(temp);
        while(merge_out.size() < 4) merge_out.emplace_back(0); //末尾补0
        //输出数字
        for(int j = 0; j < 4; ++j)
        {
            if(data_[i][j] == merge_out[j]) continue; //相同不需更改
            else
            {
                data_[i][j] = merge_out[j];
                move_flag = true; //发生移动
            }
        }
        merge_out.clear(); //清空数组
    }
    if(move_flag) databackup_ = buffer_;
    return move_flag;
}
bool GameData::RightMove() //right移动
{
    vector<vector<int>> buffer_ = data_;
    bool move_flag = false; //用以储存是否发生移动并输出
    int temp; //临时储存
    vector<int> merge_out; //输出数组
    for(int i = 0; i < 4; ++i)
    {
        //合并数字
        temp = 0;
        for(int j = 3; j >= 0; --j)
        {
            if(data_[i][j] == 0) continue; //空位跳过
            else if(temp == 0) //无待合并数字
            {
                temp = data_[i][j];
            }
            else if(data_[i][j] == temp) //有待合并数字且需合并
            {
                merge_out.emplace_back(2 * temp);
                temp = 0;
            }
            else //有待合并数字且不需合并
            {
                merge_out.emplace_back(temp);
                temp = data_[i][j];
            }
        }
        merge_out.emplace_back(temp);
        while(merge_out.size() < 4) merge_out.emplace_back(0); //末尾补0
        //输出数字
        for(int j = 3; j >= 0; --j)
        {
            if(data_[i][j] == merge_out[3 - j]) continue; //相同不需更改
            else
            {
                data_[i][j] = merge_out[3 - j];
                move_flag = true; //发生移动
            }
        }
        merge_out.clear(); //清空数组
    }
    if(move_flag) databackup_ = buffer_;
    return move_flag;
}

void GameData::Undo()
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(databackup_[i][j])
            {
                data_ = databackup_;
                return;
            }
        }
    }
}

void GameData::PrintData()
{
    int print_number;
    for(int x = 0; x < 4; ++x)
    {
        for(int y = 0; y < 4; ++y)
        {
            SetCursorPosition(3 + 4 * x, 2 + 6 * y);
            print_number = GetData(x, y);
            if(print_number == 0) cout << "     ";
            else if(print_number < 16)
            {
                SetColor(15);
                cout << print_number;
            }
            else if (print_number < 256)
            {
                SetColor(12);
                cout << print_number;
            }
            else
            {
                SetColor(14);
                cout << print_number;
            }
        }
    }
}

void GameData::ClearData()
{
    for(int x = 0; x < 4; ++x)
    {
        for(int y = 0; y < 4; ++y)
        {
            SetCursorPosition(3 + 4 * x, 2 + 6 * y);
            cout << "     ";
        }
    }
}

int GameData::Victory(int mode) //判定胜利
{
    int final_number;
    bool win_flag = false;
    if(mode == 0) final_number = 2048;
    else final_number = 65536;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(data_[i][j] >= final_number) win_flag = true;
        }
    }
    //胜利时提示
    if(win_flag)
    {
        SetCursorPosition(18, 1);
        SetColor(10);
        cout << "!You win!";
        SetCursorPosition(18, 12);
        SetBackColor();
        cout << "Restart";
        SetCursorPosition(18, 21);
        SetColor(10);
        cout << "Exit";
        int ch, current_option = 1;
        bool enter_flag = false;
        while((ch = getch()))
        {
            switch(ch)
            {
            case 13:
                enter_flag = true;
                break;
            case 75:
                if(current_option == 1) break;
                current_option -= 1;
                SetCursorPosition(18, 12);
                SetBackColor();
                cout << "Restart";
                SetCursorPosition(18, 21);
                SetColor(10);
                cout << "Exit";
                break;
            case 77:
                if(current_option == 2) break;
                current_option += 1;
                SetCursorPosition(18, 21);
                SetBackColor();
                cout << "Exit";
                SetCursorPosition(18, 12);
                SetColor(10);
                cout << "Restart";
                break;
            default:
                break;
            }
            if(enter_flag)
            {
                SetCursorPosition(18, 1);
                cout << "                         ";
                return current_option;
            }
        }
    }
    return 0;
} //返回0时未胜利；返回1时胜利并重开；返回2时胜利并退出

int GameData::Lose() //判定失败
{
    //有空位则未失败
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(data_[i][j] == 0) return 0;
        }
    }
    //相邻相同则未失败
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(data_[i][j] == data_[i][j + 1]) return 0;
        }
    }
    for(int j = 0; j < 4; ++j)
    {
        for(int i = 0; i < 3; ++i)
        {
            if(data_[i][j] == data_[i + 1][j]) return 0;
        }
    }
    //剩下的就是失败了
    SetCursorPosition(18, 1);
    SetColor(10);
    cout << "Game over";
    SetCursorPosition(18, 12);
    SetBackColor();
    cout << "Restart";
    SetCursorPosition(18, 21);
    SetColor(10);
    cout << "Exit";
    int ch, current_option = 1;
    bool enter_flag = false;
    while((ch = getch()))
    {
        switch(ch)
        {
        case 13:
            enter_flag = true;
            break;
        case 75:
            if(current_option == 1) break;
            current_option -= 1;
            SetCursorPosition(18, 12);
            SetBackColor();
            cout << "Restart";
            SetCursorPosition(18, 21);
            SetColor(10);
            cout << "Exit";
            break;
        case 77:
            if(current_option == 2) break;
            current_option += 1;
            SetCursorPosition(18, 21);
            SetBackColor();
            cout << "Exit";
            SetCursorPosition(18, 12);
            SetColor(10);
            cout << "Restart";
            break;
        default:
            break;
        }
        if(enter_flag)
        {
            SetCursorPosition(18, 1);
            cout << "                         ";
            return current_option;
        }
    }
} //返回0时未失败；返回1时失败并重开；返回2时失败并退出
