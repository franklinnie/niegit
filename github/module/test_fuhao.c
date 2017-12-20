#include <stdio.h>


	#define offset(type,field) ((int)&(((type *)0)->field)) 
	struct mystr
	{
		char a;
		int b;
		float c;
		double d;
		char e;	
	};
int main()
{
#if 0
	int i = -1;
	unsigned j = 100;
	printf("~i is %d ~j is %d\n", ~i, ~j); 
	if( ~i > 0 )
		printf("~i is > 0\n");
	if( ~j > 0 )
		printf("~j is > 0\n");
#endif
#if 0
	printf("%d\n", offset(mystr,a));
	printf("%d\n", offset(mystr,b));
	printf("%d\n", offset(mystr,c));
	printf("%d\n", offset(mystr,d));
	printf("%d\n", offset(mystr,e));
#endif
	int a = 100001;
	int b =1000;
	printf("(a+b)>>1 is %d\n", (a+b)>>1);
	int count = 0;
	while(a > 0 )
	{
		int x = a&1;
		if(x > 0 )
			count++;  
		a = a>>1;
	}
	printf("count is %d\n", count);
	a = 100001;
	count = 0;
	while(a > 0 )
	{
		count++;  
		a = a&(a-1);
	}
	printf("count is %d\n", count);
}
