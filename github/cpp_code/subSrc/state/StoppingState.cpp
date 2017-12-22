#include "../../include/state/StoppingState.h"
#include "../../include/state/Context.h"
#include <iostream>
using std::cout;
using std::endl;

CStoppingState::CStoppingState(void)
{
}

CStoppingState::~CStoppingState(void)
{
}

void CStoppingState::Open()
{
    this->CLiftState::m_pContext->SetLiftState(CContext::pOpenningState);
    this->CLiftState::m_pContext->GetLiftState()->Open();
}

void CStoppingState::Close()
{
    //do nothing
}

void CStoppingState::Run()
{
    this->CLiftState::m_pContext->SetLiftState(CContext::pRunningState);
    this->CLiftState::m_pContext->GetLiftState()->Run();
}

void CStoppingState::Stop()
{
    cout << "电梯停止了..." << endl;
}
