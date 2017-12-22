#ifndef BLOCKENEMY_H
#define BLOCKENEMY_H


#include <iostream>
#include "IStrategy.h"
class CBlockEnemy :    public IStrategy
{
public:
    CBlockEnemy(void);
    ~CBlockEnemy(void);
    void Operate(void);
};

#endif
