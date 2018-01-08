/*
�m�W : ������ 
�Ǹ� : D0542487 
���g��� : 2017/9/22
dev-cpp version : 5.11 
*/ 
#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b)//compare a,b
{
	if(a>b)
		return 1;
	else if(a<b)
		return -1;
	else 
		return 0;
}
void selectionsort(int a[], int n)//sorting
{
	int i, j, min, temp;
	for(i = 0 ; i < n ; i++)
	{
		min = i;
		for(j = i+1 ; j < n ; j++)
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
int bs(int a[], int left, int right, int n)//binary search
{
	while(left<=right)
	{
		int middle = (left + right)/2;
		switch(compare(a[middle],n))
		{
			case 1:
				right = middle - 1;
				break;
			case -1:
				left = middle + 1;
				break;
			case 0:
				return 1;
		}
		return bs(a, left, right, n);	
	}
	return 0;
}
void searchnum(int a[], int n)//using binarysearch 
{
	printf("�j�M%d...\n", n);
	if(bs(a, 0, 9999, n))
	{
		printf("�j�M��%d\n\n", n);
	}
	else
	{
		printf("���j�M��%d\n\n", n);
	}
}
int main(int argc, char *argv[]) {
	int a[10000], i = 0, temp, k;
	FILE *fptr = fopen("sort_data.txt","r");	
	if(fptr==NULL)
	{
		printf("������ɮ�\n");
		return 0;
	}
	while(fscanf(fptr, "%d", &temp)!=EOF)
	{
		a[i] = temp;
		i++;
	}
	selectionsort(a, 10000);
	searchnum(a, 7604);
	searchnum(a, 8763);
	searchnum(a, 9487);
	searchnum(a, 99987);
	system("pause");
	return 0;
}
