#ifndef TEST_CASE_H
#define TEST_CASE_H

#include "test_case_common.h"

typedef struct _s_test_case_func{
	const char *funcName;
	github_err_t (*test_func)(uint32_t, void*);
}s_test_case_func;

typedef struct _s_func_arg{
	uint32_t num;
	void *userData;
}s_func_arg;

extern github_err_t githubAllocBufs(uint32_t num, void *userData);
extern github_err_t strongLinkTest(uint32_t num, void *userData);
extern github_err_t device_create(uint32_t num, void *userData);
extern github_err_t platform_device(uint32_t num, void *userData);
extern github_err_t mmap_user(uint32_t num, void *userData);
extern github_err_t kmem_cache(uint32_t num, void *userData); 
extern github_err_t blog(uint32_t num, void *userData);
extern github_err_t builderClient(uint32_t num, void *userData);
extern github_err_t duty(uint32_t num, void *userData);
extern github_err_t state(uint32_t num, void *userData);
extern github_err_t Strategy(uint32_t num, void *userData); 
extern github_err_t singletonClient(uint32_t num, void *userData);
extern github_err_t stlVector(uint32_t num, void *userData);
extern github_err_t stlReverse(uint32_t num, void *userData);
extern github_err_t stlVectorMultiArray(uint32_t num, void *userData);
extern github_err_t stlMultimap(uint32_t num, void *userData);
extern github_err_t stlStringConw(uint32_t num, void *userData); 
extern github_err_t stlListInit(uint32_t num, void *userData); 

#endif









