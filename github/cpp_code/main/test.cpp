#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <stdint.h>
#include "../include/test_case_if.h"

s_test_case_func test_case_funcTbl[] = 
{
	{"githubAllocBufs", 	githubAllocBufs}, 	/* 0 */
	{"strongLinkTest" , 	strongLinkTest},	/* 1 */
	{"device_create",	device_create},	  	/* 2 */	
	{"platform_device",	platform_device},  	/* 3 */	
	{"mmap_user",		mmap_user},		/* 4 */
	{"kmem_cache",   	kmem_cache},		/* 5 */
	{"blog",		blog},			/* 6 */ 
	{"builderClient", 	builderClient},		/* 7 */
	{"duty"		,	duty},			/* 8 */	
	{"state"	,	state}			/* 9 */
};	

void* thread_entry(void *data);
void threadStop(int signalno);
static int mainThreadHanling = 1;

int main(int argc, char **argv)
{	
	uint32_t funcTblInx = 0;
	s_func_arg funcArg;
	pthread_t handle1;
	size_t stack_size;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
	pthread_attr_getstacksize (&attr, &stack_size);
	printf("main threadSize 0x%x\r\n", stack_size);
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

        signal(SIGINT, threadStop); 

	github_err_t funcresult = GITHUB_ERR_NONE;
	if (argc == 2) {
		funcTblInx = atoi(argv[1]);
	}
	if (funcTblInx > (sizeof(test_case_funcTbl) / sizeof(test_case_funcTbl[0])))
		return -1;	
	printf("func name is %s \r\n", test_case_funcTbl[funcTblInx].funcName);
	funcArg.num = funcTblInx;
	funcArg.userData = NULL;
	
	int rt = pthread_create(&handle1, &attr, thread_entry, (void *)&funcArg);
	while(mainThreadHanling) {
		sleep(1);
	}
	pthread_attr_destroy(&attr);
	
	
	return 0;
}

void* thread_entry( void *data)
{
	s_func_arg *arg = (s_func_arg*)data;
	uint32_t num = 0;
	printf("this is in thread_entry, arg->num %d\r\n", arg->num);
	if (arg->num == 0 ) 
		num = 5;
	test_case_funcTbl[arg->num].test_func(num, arg->userData);
		
	
	return NULL;
}	

void threadStop(int signalno)
{
	mainThreadHanling = 0;
	printf("this is in threadStop\r\n");
	exit(0);
}

