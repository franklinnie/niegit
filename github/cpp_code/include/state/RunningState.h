#pragma once
#include "LiftState.h"
class CRunningState :
    public CLiftState
{
public:
    CRunningState(void);
    ~CRunningState(void);
    void Open();
    void Close();
    void Run();
    void Stop();
};
