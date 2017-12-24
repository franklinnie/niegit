#include <iostream>
#include <stdint.h>
#include "../include/test_case_common.h"


using namespace std;
#pragma  packed(3)
typedef struct _s_bitFiled{
	int a:4;
	int b:6;
	int c:6;
}s_bitFiled;

github_err_t bitFileld(uint32_t num, void *userData)
{
	int i = sizeof(s_bitFiled);
	cout << "struct s_bitFiled size is " << i << endl;
	/* output result is 4 */
	return GITHUB_ERR_NONE;
}

