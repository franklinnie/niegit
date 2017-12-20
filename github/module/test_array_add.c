#include <stdio.h>

int add_array(int a[],int n)
{
	int result;
	if(n == 0 )
		return 0;
	result = add_array(a,n-1) + a[n-1];
	/*
	add(a,4)+a[4]+ add(a,3)+ a[3] + add(a,2) + a[2] + add(a,1) + a[1] + add(a,0)
	+ a[0]
	*/
	
	return result;
}

int main()
{
	int a[5] = {1,2,3,4,5};
	int size = sizeof(a)/sizeof(a[0]); 
	printf("size is %d\n", size);
	int result = add_array(a, size);

	printf("result is %d\n", result);
	return 0;
}

