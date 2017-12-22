#ifndef CONTEXT_H
#define CONTEXT_H
#include "IStrategy.h"

class CContextStrategy
{
public:
    CContextStrategy(IStrategy *pStrategy);
    ~CContextStrategy(void);
    void Operate(void);
private:
    IStrategy *m_pStrategy;
};

#endif
