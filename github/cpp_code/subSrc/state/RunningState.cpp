#include "../../include/state/RunningState.h"
#include "../../include/state/Context.h"
#include <iostream>
using std::cout;
using std::endl;

CRunningState::CRunningState(void)
{
}

CRunningState::~CRunningState(void)
{
}

void CRunningState::Open()
{
    //do nothing
}

void CRunningState::Close()
{
    //do nothing
}

void CRunningState::Run()
{
    cout << "电梯上下跑..." << endl;
}

void CRunningState::Stop()
{
    this->CLiftState::m_pContext->SetLiftState(CContext::pStoppingState);
    this->CLiftState::m_pContext->GetLiftState()->Stop();
}

