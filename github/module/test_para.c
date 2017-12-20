#include <stdio.h>

void test(int *p1)
{
	int x=0;
	*p1 = 10;
}

int main()
{
	int *p = (int *)malloc(4);
	memset(p,0,4);
	test(p);
	return 0;
}
