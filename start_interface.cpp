#include<windows.h>
#include"start_interface.h"
#include"boundary.h"

//输出界面
void StartInterface::Print()
{
    //移动25次进入屏幕
    for(int t = 0; t < 25; ++t)
    {
        //先移动，再输出，避免覆盖
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
