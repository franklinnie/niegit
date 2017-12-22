#pragma once
#include "LiftState.h"
class CStoppingState :
    public CLiftState
{
public:
    CStoppingState(void);
    ~CStoppingState(void);
    void Open();
    void Close();
    void Run();
    void Stop();
};
