#include <stdio.h>

char *get_str1(void)
{
	char a[] = {"abdbd"};
	return a;
}
char *get_str2(void)
{
	char *p = "abdbd";
	return p;
}


int main()
{
	printf("get_str1 %s\n", get_str1());
	printf("get_str2 %s\n", get_str2());
	int a = 11;
	int *p = &a;
	return 0;
}
