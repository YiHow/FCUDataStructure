/*
姓名 : 黃羿豪 
學號 : D0542487 
撰寫日期 : 2017/9/23 
dev-cpp version : 5.11 
*/ 
#include <stdio.h>
#include <stdlib.h>

int main() {
	int primeNum[100000] = {}, numNow = 2, i, j, flag;
	printf("搜尋中...\n");
	for(i = 0 ; i < 100000 ;)//找出100000個質數 
	{
		flag = 1;
		for(j = 0 ; j < i/2 ; j++)//檢查是否被前面質數整除 
		{
			if(numNow%primeNum[j] == 0)
			{
				flag = 0;
				break;
			}
		}
		if(flag)//找到質數 
		{
			primeNum[i] = numNow;
			i++;
		}
		numNow++;
	}
	printf("第%d個質數 = %d\n", 100000, primeNum[99998]);//印出答案 
	system("pause");
	return 0;
} 
