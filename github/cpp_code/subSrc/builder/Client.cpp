#include "../../include/builder/Director.h"
#include "../../include/test_case_common.h"
#include <stdint.h>

github_err_t builderClient(uint32_t num, void *userData) 
{
	AbstractBuilder* builder = new Builder();
	Director* director = new Director(builder);

	director->construct();
	
	Product* product = builder->getProduct();
	product->show();
	return GITHUB_ERR_NONE; 
}
