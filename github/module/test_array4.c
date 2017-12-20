#include <stdio.h>

int *parray1[3] = {NULL,NULL, NULL};
int arrayData[3] = {0, 0, 0 };

int **init(int m, int n)
{
	int **p = parray1;
	int i,j,data = 1;
	for(i=0; i<m;i++)
	{
		p[i] = arrayData;
		for(j=0; j<n;j++){
			p[i][j] = data;
		}
	}
	return p;
}

void output(int **p, int m, int n)
{
	int i,j;
	for(i=0; i<m;i++)
	{
		for(j=0; j<n;j++){
			printf("p[%d][%d] %d\n", i, j, p[i][j]);
		}
	}
}

int main()
{
	int **p = init(3,3);
	output(p, 3,3);
	int array[4][4] = {
				{2,3,4,4},
				{2,5,5,5},
				{2,3,4,4},
				{2,3,4,4}
			};
	
	
	int i = 0;
	int j = 0;
	for(i = 0; i <4;i++)
		for(j=0;j<4;j++)
			printf("p2[%d][%d] %d\n", i, j, p2[i][j]);
	
	return 0;
}
