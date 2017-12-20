#include <stdio.h>

int add2(int num, ...)
{
	int sum = 0;
	int index = 0;
	int *p = NULL;
	p = (int *)&num +2;
	printf("*p is %d\n", *p);
	for(;index < (int)num;++index)
	{
		sum += *p++;
	}
	return sum;
}

int add(int x, int y)
{
	return (x+y);
}
int main()
{
#if 0
	int i = 1;
	int j = 2;
	int k = 3;
	printf("%d\n",add2(3,i,j,k));
	
	int *test();
	typedef int (*test)() func;

	char (*a)[10];
	char *a[10];
	template <>func()
	const int *p;
	int const *p;
	int * const p;
	const int * const p;

	#endif

	typedef int(*test)(int x, int y);
	test p = add;
	int x = (*p)(1,2);
	printf("x is %d\n",x);
	//int a[2][2] = {{1,2},{3,4}};
	int a[2] = {1,2};
	int i = 0;
	int j = 0;
	
	printf("a  is %d\n",*(a+1));
	//printf("a  is %d\n",*(a[0]+1));
	printf("a  is %d\n",*(&a+1));
	printf("a  is %d\n",*(&a[0]+1));


#if 0
	for(i=0; i< sizeof(a)/sizeof(a[0][0]);i++) {
		for(j=0; i< sizeof(a)/sizeof(a[0][0]);j++) {		
			printf("a[%d][%d] %d\n",i,j,a[i][j]);
		}
	}
#endif

	return 0;
}
