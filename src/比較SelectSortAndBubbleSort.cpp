#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionsort(int a[])//selectionsort
{
	int i, j, min, temp, k;
	for(i = 0 ; i < 10000 ; i++)
	{
		min = i;
		for(j = i+1 ; j < 10000 ; j++)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
} 
void bubblesort(int a[]){
	int i, j, temp;
	for(i = 0 ; i < 10000; i++)
	{
		for(j = 0  ; j < 10000 - i ; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
int main() {
	double RunTimeB, RunTimeS;
	clock_t start, end;
	int a[10000], b[10000], i = 0, temp, k;
	FILE *fptr = fopen("sort_data.txt","r");	
	if(fptr==NULL)
	{
		printf("¥¼§ä¨ìÀÉ®×\n");
		return 0;
	}
	while(fscanf(fptr, "%d", &temp)!=EOF)
	{
		a[i] = temp;
		i++;
	}
	for(i = 0 ; i < 10000 ; i++) b[i] = a[i]; 
	start = clock();
	bubblesort(a);
	end = clock();
	RunTimeB = (double)(end - start)/CLOCKS_PER_SEC; 
	printf("BubbleSort = %lf\n", RunTimeB);
	start = clock();
	selectionsort(b);
	end = clock();
	RunTimeS = (double)(end - start)/CLOCKS_PER_SEC; 
	printf("SelectSort = %lf\n", RunTimeS);
	fclose(fptr);
	printf("BubbleSort - SelectSort = %lf\n", RunTimeB - RunTimeS);
	return 0;
}
