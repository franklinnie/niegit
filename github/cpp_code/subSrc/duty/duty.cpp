#include <stdint.h>
#include "../../include/test_case_common.h"
#include "../../include/duty/duty.h"

github_err_t duty(uint32_t num, void *userData)  
{     
    Manager *general = new GeneralManager(NULL, "A"); //设置上级，总经理没有上级  
    Manager *majordomo = new Majordomo(general, "B"); //设置上级  
    Manager *common = new CommonManager(majordomo, "C"); //设置上级  
    common->DealWithRequest("D",300);   //员工D要求加薪  
    common->DealWithRequest("E", 600);  
    common->DealWithRequest("F", 1000);  
    delete common; delete majordomo; delete general;  
    return GITHUB_ERR_NONE;  
}  
