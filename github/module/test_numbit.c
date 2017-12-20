#include <stdio.h>

int main()
{
	int a = 15;
	int size = sizeof(int)*8;
	printf("size is %d\n", size);	
	int counter = 0;
	int i = 0;
	for(i = 0; i < size; i++ ) {
		if( ( a & 0x01 )  == 0x01 )
			counter++;
		a = a >> 1;
	} 
	printf("num of 1 in a is %d\n", counter);

	int x = 0x12345678;
	char c = x >> 24;
	if( c == 0x12 )
		printf("little\n");	
	else
		printf("big\n");


	union test
	{	
		int a;	
		char b;
	};

	union test l;
	l.a = 4;
	printf("l.b is %d\n", l.b);

	return 0;
}
