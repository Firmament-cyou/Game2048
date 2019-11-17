#include<windows.h>
#include"start_interface.h"
#include"boundary.h"

//�������
void StartInterface::Print()
{
    //�ƶ�25�ν�����Ļ
    for(int t = 0; t < 25; ++t)
    {
        //���ƶ�������������⸲��
        for(auto& i : start_hyphen)
        {
            if(i.GetY() > 0) i.BoundaryClear();
            i.MoveIn();
            if(i.GetY() > 0) i.BoundaryHyphen();
        }
        for(auto& i : start_vertical)
        {
            if(i.GetY() > 0) i.BoundaryClear();
            i.MoveIn();
            if(i.GetY() > 0) i.BoundaryVertical();
        }
        for(auto& i : start_plus)
        {
            if(i.GetY() > 0) i.BoundaryClear();
            i.MoveIn();
            if(i.GetY() > 0) i.BoundaryPlus();
        }
        for(auto i : start_hyphen)
        {
            if(i.GetY() > 0) i.BoundaryHyphen();
        }
        for(auto i : start_vertical)
        {
            if(i.GetY() > 0) i.BoundaryVertical();
        }
        for(auto i : start_plus)
        {
            if(i.GetY() > 0) i.BoundaryPlus();
        }
        Sleep(interval_);
    }
}
