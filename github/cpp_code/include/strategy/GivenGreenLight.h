#ifndef GIVENGREENLIGHT_H
#define GIVENGREENLIGHT_H


#include <iostream>
#include "IStrategy.h"
class CGivenGreenLight :
    public IStrategy
{
public:
    CGivenGreenLight(void);
    ~CGivenGreenLight(void);
    void Operate(void);
};
#endif
