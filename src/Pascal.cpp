#include <stdio.h>
#include <stdlib.h>

void tri(int a[], int  len, int n)
{
	int i, j;
	int newarray[len+1] = {0};
	if(n>0)
	{
		for(i = 0 ; i < len ; i++)
		{
			
			printf("%d ", a[i]);
		}
		printf("\n");
		newarray[0] = 1;
		newarray[len] = 1;
		for(i = 1; i < len; i++)
		{
			newarray[i] = a[i] + a[i-1];
		}
		tri(newarray, sizeof(newarray)/4, n-1);
	}
}
int main(int argc, char *argv[]) {
	int a[1];
	a[0] = 1;
	tri(a, sizeof(a)/4, 6);
	system("pause");
}
