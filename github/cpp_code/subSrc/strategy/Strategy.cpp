#include <iostream>
#include <stdint.h>
#include "../../include/strategy/Context.h"
#include "../../include/strategy/BackDoor.h"
#include "../../include/strategy/GivenGreenLight.h"
#include "../../include/strategy/BlockEnemy.h"
#include "../../include/test_case_common.h"


using std::cout;
using std::endl;
github_err_t Strategy(uint32_t num, void *userData) 
{
    CContextStrategy *pContext;

    cout << "\14\n\n\n\n\17" << endl;
    cout << "----------刚刚到吴国的时候拆第一个----------" << endl;
    pContext = new CContextStrategy(new CBackDoor());
    pContext->Operate();
    delete pContext;

    cout << "\14\n\n\n\n\17" << endl;
    cout << "----------刘备乐不思蜀了，拆第二个了----------" << endl;
    pContext = new CContextStrategy(new CGivenGreenLight());
    pContext->Operate();
    delete pContext;

    cout << "\14\n\n\n\n\17" << endl;
    cout << "----------孙权的小兵追了，咋办？拆第三个----------" << endl;
    pContext = new CContextStrategy(new CBlockEnemy());
    pContext->Operate();
    delete pContext;


    return GITHUB_ERR_NONE;
}
