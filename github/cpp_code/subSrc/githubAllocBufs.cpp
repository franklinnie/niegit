#include <stdlib.h>
#include <stdio.h>
#include "../include/test_case_common.h"
#include "../include/githuballoc.h"
#include <unistd.h>
#include <pthread.h>

Array<github_image_buf_t*> mPipelineBufs;

github_err_t githubAllocBufs(uint32_t num, void *userData)
{
	size_t stack_size;
        pthread_attr_t thread_attr;
        pthread_attr_init(&thread_attr);
	pthread_attr_getstacksize (&thread_attr, &stack_size);
	printf("githubAllocBufs threadSize 0x%x\r\n", stack_size);
	mPipelineBufs.alloc(num);	
	for (uint32_t i = 0; i < mPipelineBufs.size(); i++) {
		mPipelineBufs[i] = (github_image_buf_t*)calloc(1, sizeof(github_image_buf_t));
		
	}
	mPipelineBufs.free();
	while(1) {		
		printf("this is in githubAllocBufs\r\n");
		sleep(1);
	}
	
	return GITHUB_ERR_NONE;
}
