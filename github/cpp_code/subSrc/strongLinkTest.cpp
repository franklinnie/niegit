#include <stdlib.h>
#include <stdio.h>
#include "../include/test_case_common.h"
#include "../include/strongLinkTest.h"
#include <unistd.h>
#include <pthread.h>


github_err_t strongLinkTest(uint32_t num, void *userData)
{
	size_t stack_size;
        pthread_attr_t thread_attr;
        pthread_attr_init(&thread_attr);
	pthread_attr_getstacksize (&thread_attr, &stack_size);
	printf("strongLinkTest threadSize 0x%x\r\n", stack_size);
	A1(test, int) = num;
	while(1) {
		printf("A1(test, int):%d\r\n", test_int_type);
		sleep(1);
	}
	return GITHUB_ERR_NONE;
}	
