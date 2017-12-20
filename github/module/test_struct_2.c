#include <stdio.h>


void test(char *p )
{
	p="ewefwfewf";
}

int main()
{
	
	struct node{
		char c;
		short i;
		float f;
		char t;
	};
	
	char *p ="12233eeeeeeeeeeeeeeee";
	test(p);
	printf("p is %s\n", p);
	int a=100;
	if(a<0) 
		printf("a < 0");
	return 0;
}
