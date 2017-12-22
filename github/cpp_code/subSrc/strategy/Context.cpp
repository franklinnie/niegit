#include "../../include/strategy/Context.h"
CContextStrategy::CContextStrategy(IStrategy *pStrategy)
{
    this->m_pStrategy = pStrategy;
}
CContextStrategy::~CContextStrategy(void)
{
    delete this->m_pStrategy;
}
void CContextStrategy::Operate(void)
{
    this->m_pStrategy->Operate();
}
