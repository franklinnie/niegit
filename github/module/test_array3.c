#include <stdio.h>

void test1(int **p,int m, int n )
{
	int i = 0;	
	int j = 0;
	for( i = 0; i< m; i ++ )
	{
		for( j = 0; j< n; j ++ )
		{
			printf("*(*p[%d] + %d) is %d\n",i, j, *((*p +i) + j));
		}
	}
}

int main()
{
	int a[3][4] = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12}	
	};

	printf("a %p\t\t\t\n", a);
	printf("a[0] %p\t\t\t\n", a[0]);
	printf("*(a + 0 ) %p\t\t\t\n", *(a + 0 ));
	printf("*a %p\t\t\t\n", *a);
	printf("&a[0][0] %p\t\t\t\n", &a[0][0]);
	printf("&a[0] %p\t\t\t\n", &a[0]);

	printf("\n");

	printf("*a %p\t\t\t\n", *a);
	printf("*a[0] %d\t\t\t\n", *a[0]);
	printf("**(a + 0 ) %d\t\t\t\n", **(a + 0 ));
	printf("**a %d\t\t\t\n", **a);
	printf("*&a[0][0] %d\t\t\t\n", *&a[0][0]);
	printf("*&a[0] %p\t\t\t\n", *(&a[0]));

	
	
/*although these address are same ,but + 1 is different*/
	printf("\n");


	printf("a + 1 %p\t\t\t\n", a + 1);
	printf("a[0] + 1) %p\t\t\t\n", a[0] + 1);
	printf("*(a + 0 ) + 1 %p\t\t\t\n", *(a + 0 ) + 1);
	printf("*a + 1 %p\t\t\t\n", *a + 1);
	printf("&a[0][0] + 1 %p\t\t\t\n", &a[0][0] + 1);
	printf("&a[0] + 1 %p\t\t\t\n", &a[0] + 1);
	printf("\n");

	printf("*(a + 1) %p\t\t\t\n", *(a + 1));
	printf("*(a[0] + 1) %d\t\t\t\n", *(a[0] + 1));
	printf("*(*(a + 0 ) + 1) %d\t\t\t\n", *(*(a + 0 ) + 1));
	printf("*(*a + 1) %d\t\t\t\n", *(*a + 1));
	printf("*(&a[0][0] + 1) %d\t\t\t\n", *(&a[0][0] + 1));
	printf("*(&a[0] + 1) %p\t\t\t\n", *(&a[0] + 1));
	printf("\n");

	/*
	a 0xbfd38ac0			
	a[0] 0xbfd38ac0			
	*(a + 0 ) 0xbfd38ac0			
	*a 0xbfd38ac0			
	&a[0][0] 0xbfd38ac0			
	&a[0] 0xbfd38ac0			

	*a 0xbfd38ac0			
	*a[0] 1			
	**(a + 0 ) 1			
	**a 1			
	*&a[0][0] 1			
	*&a[0] 0xbfd38ac0			

	a + 1 0xbfd38ad0			
	a[0] + 1 0xbfd38ac4			
	*(a + 0 ) + 1 0xbfd38ac4			
	*a + 1 0xbfd38ac4			
	&a[0][0] + 1 0xbfd38ac4			
	&a[0] + 1 0xbfd38ad0			

	*(a + 1) 0xbfd38ad0			
	*(a[0] + 1) 2			
	*(*(a + 0 ) + 1) 2			
	*(*a + 1) 2			
	*(&a[0][0] + 1) 2			
	*(&a[0] + 1) 0xbfd38ad0

	*/


	printf("test1 result is:\n");

	test1(a, 1, 1 );
	return 0;
}
