#include<cstdlib>
#include<time.h>
#include<conio.h>
#include"gamedata.h"
#include"tools.h"

using namespace std;

int GameData::GetData(int x, int y) //�õ�ĳ�������
{
    return data_[x][y];
}
void GameData::GenerateNumber() //��������µ�����
{
    srand((unsigned)time(0)); //ʹ�õ�ǰʱ����Ϊ�޷������͵�����
    //ȡ������Ϊ0�ĵ㲢��¼�������������һ���㸳ֵ
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
    int lucky_place = (rand() % zero_count); //ѡ����λ
    //����2 or 4 ��������4 : 1���ˣ�
    if(rand() % 5) data_[zerox[lucky_place]][zeroy[lucky_place]] = 2;
    else data_[zerox[lucky_place]][zeroy[lucky_place]] = 4;
    zerox.clear(); zeroy.clear(); //�����ʱ����
}
bool GameData::UpMove() //up�ƶ�
{
    vector<vector<int>> buffer_ = data_; //���ƶ�ǰ�����鱣��
    bool move_flag = false; //���Դ����Ƿ����ƶ������
    int temp; //��ʱ����
    vector<int> merge_out; //�������
    for(int j = 0; j < 4; ++j)
    {
        //�ϲ�����
        temp = 0;
        for(int i = 0; i < 4; ++i)
        {
            if(data_[i][j] == 0) continue; //��λ����
            else if(temp == 0) //�޴��ϲ�����
            {
                temp = data_[i][j];
            }
            else if(data_[i][j] == temp) //�д��ϲ���������ϲ�
            {
                merge_out.emplace_back(2 * temp);
                temp = 0;
            }
            else //�д��ϲ������Ҳ���ϲ�
            {
                merge_out.emplace_back(temp);
                temp = data_[i][j];
            }
        }
        merge_out.emplace_back(temp); //���������һ��tempҲҪ������
        while(merge_out.size() < 4) merge_out.emplace_back(0); //ĩβ��0
        //�������
        for(int i = 0; i < 4; ++i)
        {
            if(data_[i][j] == merge_out[i]) continue; //��ͬ�������
            else
            {
                data_[i][j] = merge_out[i];
                move_flag = true; //�����ƶ�
            }
        }
        merge_out.clear(); //�������
    }
    if(move_flag) databackup_ = buffer_; //�����ƶ��򱸷��������
    return move_flag;
}
bool GameData::DownMove() //down�ƶ�
{
    vector<vector<int>> buffer_ = data_;
    bool move_flag = false; //���Դ����Ƿ����ƶ������
    int temp; //��ʱ����
    vector<int> merge_out; //�������
    for(int j = 0; j < 4; ++j)
    {
        //�ϲ�����
        temp = 0;
        for(int i = 3; i >= 0; --i)
        {
            if(data_[i][j] == 0) continue; //��λ����
            else if(temp == 0) //�޴��ϲ�����
            {
                temp = data_[i][j];
            }
            else if(data_[i][j] == temp) //�д��ϲ���������ϲ�
            {
                merge_out.emplace_back(2 * temp);
                temp = 0;
            }
            else //�д��ϲ������Ҳ���ϲ�
            {
                merge_out.emplace_back(temp);
                temp = data_[i][j];
            }
        }
        merge_out.emplace_back(temp);
        while(merge_out.size() < 4) merge_out.emplace_back(0); //ĩβ��0
        //�������
        for(int i = 3; i >= 0; --i)
        {
            if(data_[i][j] == merge_out[3 - i]) continue; //��ͬ�������
            else
            {
                data_[i][j] = merge_out[3 - i];
                move_flag = true; //�����ƶ�
            }
        }
        merge_out.clear(); //�������
    }
    if(move_flag) databackup_ = buffer_;
    return move_flag;
}
bool GameData::LeftMove() //left�ƶ�
{
    vector<vector<int>> buffer_ = data_;
    bool move_flag = false; //���Դ����Ƿ����ƶ������
    int temp; //��ʱ����
    vector<int> merge_out; //�������
    for(int i = 0; i < 4; ++i)
    {
        //�ϲ�����
        temp = 0;
        for(int j = 0; j < 4; ++j)
        {
            if(data_[i][j] == 0) continue; //��λ����
            else if(temp == 0) //�޴��ϲ�����
            {
                temp = data_[i][j];
            }
            else if(data_[i][j] == temp) //�д��ϲ���������ϲ�
            {
                merge_out.emplace_back(2 * temp);
                temp = 0;
            }
            else //�д��ϲ������Ҳ���ϲ�
            {
                merge_out.emplace_back(temp);
                temp = data_[i][j];
            }
        }
        merge_out.emplace_back(temp);
        while(merge_out.size() < 4) merge_out.emplace_back(0); //ĩβ��0
        //�������
        for(int j = 0; j < 4; ++j)
        {
            if(data_[i][j] == merge_out[j]) continue; //��ͬ�������
            else
            {
                data_[i][j] = merge_out[j];
                move_flag = true; //�����ƶ�
            }
        }
        merge_out.clear(); //�������
    }
    if(move_flag) databackup_ = buffer_;
    return move_flag;
}
bool GameData::RightMove() //right�ƶ�
{
    vector<vector<int>> buffer_ = data_;
    bool move_flag = false; //���Դ����Ƿ����ƶ������
    int temp; //��ʱ����
    vector<int> merge_out; //�������
    for(int i = 0; i < 4; ++i)
    {
        //�ϲ�����
        temp = 0;
        for(int j = 3; j >= 0; --j)
        {
            if(data_[i][j] == 0) continue; //��λ����
            else if(temp == 0) //�޴��ϲ�����
            {
                temp = data_[i][j];
            }
            else if(data_[i][j] == temp) //�д��ϲ���������ϲ�
            {
                merge_out.emplace_back(2 * temp);
                temp = 0;
            }
            else //�д��ϲ������Ҳ���ϲ�
            {
                merge_out.emplace_back(temp);
                temp = data_[i][j];
            }
        }
        merge_out.emplace_back(temp);
        while(merge_out.size() < 4) merge_out.emplace_back(0); //ĩβ��0
        //�������
        for(int j = 3; j >= 0; --j)
        {
            if(data_[i][j] == merge_out[3 - j]) continue; //��ͬ�������
            else
            {
                data_[i][j] = merge_out[3 - j];
                move_flag = true; //�����ƶ�
            }
        }
        merge_out.clear(); //�������
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

int GameData::Victory(int mode) //�ж�ʤ��
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
    //ʤ��ʱ��ʾ
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
} //����0ʱδʤ��������1ʱʤ�����ؿ�������2ʱʤ�����˳�

int GameData::Lose() //�ж�ʧ��
{
    //�п�λ��δʧ��
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(data_[i][j] == 0) return 0;
        }
    }
    //������ͬ��δʧ��
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
    //ʣ�µľ���ʧ����
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
} //����0ʱδʧ�ܣ�����1ʱʧ�ܲ��ؿ�������2ʱʧ�ܲ��˳�
