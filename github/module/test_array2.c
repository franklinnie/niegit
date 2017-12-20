#include <stdio.h>

typedef int *array[10];

 char *test()
{
	char *p = "12121212";
	return p;
}

//void test2(int 

int main()
{
	int a[10] = {10000,2,3,4,5};
	array c = {	
			&a[0],
			&a[0],
			&a[0],
			&a[0],
			&a[0],
			&a[0]
		     };	
	int *p = a;
	printf("p[3] is %d\n", p[3]);
		
	array *p1;
	p1 = c;
	
	printf("(*p1)[0][0] is %d\n", (*p1)[0][0]);
	printf("(*p1)[0][0] is %d\n", (*p1)[1][1]);
	printf("(*p1)[0][0] is %d\n", (*p1)[1][2]);
	printf("(*p1)[0][0] is %d\n", *(*(*p1+ 1) + 2));
	int x[10]  = {1,2,34,4,5,5,65,6,9};
	printf("a is %p\n", a);
	printf("a is %p\n", &a[0]);
	printf("a is %p\n", &a);

	//printf("a is %p\n", a + 1);
	//printf("a is %p\n", &a[0] + 1);
	//printf("a is %p\n", &a + 1 );
	//char *p3 = test();
	//p3[0] = 'x';
	//printf("p3 is %s\n", p3);
	int y[3][4] = { {1,2,4,5},
			{1,9,4,5},
			{1,19,4,5}
			};
	/*y[0][0],y[0,1],y[1][y[0],y[1][1]*/
	
	int ****yo = y;
	printf("yo is  %p y is %p\n", yo, y);
	printf("*yo is  %p *y is %p\n", *yo, *y);
	printf("*yo is  %d *y is %p\n", *yo, *y);
	
	printf("*yo is  %d *y is %p\n", *(yo + 2*4+ 1), *y);

	//printf("*(*(yo + 1) + 1) %d\n", *(*(yo + 1) + 1));
	int l = 100;
	int *lp1 = &l;
	int **lpp = &lp1;
	int *lp = &lp1;
	int **lcc;
	lcc = &lp1;
	int *lm = &lp;
	//printf("lp %p lpp %p lm %p lcc %p *lcc %p **lcc %d\n", lp, lpp, lm, lcc, *lcc, **lcc	);

	int a2[3][4] = { 
				{1,2,3,4},
				{1,2,3,4},
				{1,2,3,4}
			};
	int *ap1 = a2;
	int **ap = &ap1;
	//*ap = ap1 = a2
	int *ap3 = ap1;
	ap3 = ap1;
	int **ap4 = ap1;
	int *p5;
	printf("p5 %p &p5 %p\n", p5, &p5);
	printf("a2 + 2 %p *(a2 + 2 ) %p\n", a2 + 2, *(a2 + 2 ));

	printf("a2 %p *ap %p a2 %p ap3 %p ap1 %p ap4 %p &ap4 %p\n", a2,*ap, a2, ap3, ap1, ap4, &ap4 );

	printf("a2 %p *ap %p ap1 %p ap %p (*ap + 2)[1] %d *((*ap + 2) + 1 %d\n", a2,*ap, ap1, ap, (*ap + 2)[1], *((*ap + 2) + 1));
	//test(a2);
		
	
	return 0;
}
