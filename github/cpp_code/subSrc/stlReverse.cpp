#include <stdint.h>
#include <iostream>
#include <cstring>
#include <cassert> 
#include <algorithm> // For reverse algorithm

#include "../include/test_case_common.h"

using namespace std;

github_err_t stlReverse(uint32_t num, void *userData) 
{
	char array1[] = "abc";
	int N1 = strlen(array1);
	int a[100], b[100];
	int i;

	reverse(&array1[0], &array1[N1]);
	for (i = 0; i < N1; i++)
		cout << "array1[" << i << "] = " << array1[i] << endl;
	for (i = 0; i < 100; ++i)
		a[i] = i;
	reverse_copy(&a[0], &a[100], &b[0]);
	for (i = 0; i < 100; i++)
		cout << "a: " << a[i] << " -- b: " << b[i] << endl;

	random_shuffle(&a[0], &a[100]);

	for (i = 0; i < 100; i++) {
	    cout << " " << a[i] << " ";
	}
	return GITHUB_ERR_NONE;
}







