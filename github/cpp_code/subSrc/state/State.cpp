#include <iostream>
#include "../../include/state/ILift.h"
#include "../../include/state/lift.h"
#include "../../include/state/Context.h"
#include "../../include/state/OpenningState.h"
#include "../../include/state/CloseingState.h"
#include "../../include/state/RunningState.h"
#include "../../include/state/StoppingState.h"

#include "../../include/test_case_common.h"
#include <stdint.h>

using std::cout;
using std::endl;

void DoIt()
{
    //ILift.h, Lift.h, Lift.cpp
    ILift *pLift = new CLift();
    pLift->SetState(ILift::STOPPING_STATE);//电梯的初始条件是停止状态。
    pLift->Open();//首先是电梯门开启，人进去
    pLift->Close();//然后电梯门关闭
    pLift->Run();//再然后，电梯跑起来，向上或者向下
    pLift->Stop();//最后到达目的地，电梯停下来
    delete pLift;
}


void DoNew()
{
    //LiftState.h, LiftState.cpp, OpenningState.h, CloseingState.h, RunningState.h, StoppingState.h
    //Context.h, Context.cpp
    CContext context;
    CCloseingState closeingState;
    context.SetLiftState(&closeingState);
    context.Close();
    context.Open();
    context.Run();
    context.Stop();
}

github_err_t state(uint32_t num, void *userData) 
{
    cout << "----------使用模式之前----------" << endl;
    DoIt();
    cout << "----------使用模式之后----------" << endl;
    DoNew();

    return GITHUB_ERR_NONE;
}



