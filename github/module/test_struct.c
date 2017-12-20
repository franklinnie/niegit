#include <stdio.h>

int main()
{
	struct test{
		char c;
		char d;
	};
	printf("test size is %d\n", sizeof(struct test));
	return 0;
}
