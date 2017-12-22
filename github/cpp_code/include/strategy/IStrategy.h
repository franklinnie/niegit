#ifndef ISTRATEGY_H
#define ISTRATEGY_H
 
#include <iostream>

class IStrategy
{
public:
    IStrategy(void){}
    virtual ~IStrategy(void){}
    virtual void Operate(void) = 0;
};

#endif
