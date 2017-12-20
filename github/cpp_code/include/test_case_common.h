#ifndef TEST_CASE_COMMON_H
#define TEST_CASE_COMMON_H

#define GITHUB_SUCCESS(r) (r == 0)

typedef enum{
	GITHUB_ERR_NONE,
	GITHUB_ERR_GENERAL,
	GITHUB_ERR_INVALID_ARG,
	GITHUB_ERR_ALREADY_DONE,	
	GITHUB_ERR_NO_MEMORY,
	GITHUB_ERR_MAX
}github_err_t;


#endif




