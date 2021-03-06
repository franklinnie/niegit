
#include <stdio.h>
#include <stdint.h>

#include "../../include/singleton/singleton.h"
#include "../../include/test_case_common.h"


github_err_t singletonClient(uint32_t num, void *userData)
{
	Singleton* singleton1 = Singleton::getInstance();
	Singleton* singleton2 = Singleton::getInstance();

	if (singleton1 == singleton2)
		fprintf(stderr,"singleton1 = singleton2\n");

	return GITHUB_ERR_NONE;
}
