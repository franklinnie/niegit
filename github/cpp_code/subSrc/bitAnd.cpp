#include <iostream>
#include <cstring>
#include <stdint.h>

#include "../include/test_case_common.h"
using namespace std;

github_err_t bitAnd(uint32_t num, void *userData) 
{
	int a = 0x1001efff;
	for(int i = 0; i < sizeof(a)*8; i++) {	
		cout<< "a>>i&1 is " << ((a>>i)&1) << endl;
	}
	return GITHUB_ERR_NONE;
}

/*
10000000000011110111111111111
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 0
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 1
a>>i&1 is 0
a>>i&1 is 0
a>>i&1 is 0
a>>i&1 is 0
a>>i&1 is 0
a>>i&1 is 0
a>>i&1 is 0
a>>i&1 is 0
a>>i&1 is 0
a>>i&1 is 0
a>>i&1 is 0
a>>i&1 is 1
a>>i&1 is 0
a>>i&1 is 0
a>>i&1 is 0

*/

github_err_t bitCircleShift(uint32_t num, void *userData) 
{
	int a = 0x12345678;
	for(int k = 0; k < sizeof(a)*8; k++) {
		//a=a<<k|(a>>(sizeof(a)*8-k));
		//a = a<<k|a>>32-k; 
		a = (a << k)|k;
		cout << "a is " << hex << a << endl;
	}
	return GITHUB_ERR_NONE;
}




