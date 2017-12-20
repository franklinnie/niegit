#include <iostream>
#include <boost/lexical_cast.hpp>
#include "../include/test_case_common.h"
#include <stdint.h>

github_err_t boosttest(uint32_t num, void *userData)
{
    std::string s="100";
    int a=boost::lexical_cast<int>(s);
    int b=1;
    std::cout<<(a+b) <<std::endl;//输出101
    return GITHUB_ERR_NONE;
}
