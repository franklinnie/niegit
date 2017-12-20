#include <stdio.h>

int test_strcpy(char *dst,char *src)
{
	if(dst == NULL || src == NULL )
		return -1; 
	
	while(*dst != '\0' && *src != '\0'){
		*dst++ = *src++;
	}
	return 0;
}
char *digital_to_str(int x)
{
	int 	
}

int main()
{
	char a[] = {'6','7','8','9'};	
	char b[] = {'1','2','3','4','5'};
	int result = test_strcpy(a,b);
	printf("result is %d a %s\n", result,a);
	return 0;
}
