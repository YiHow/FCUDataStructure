/*
�m�W : ������ 
�Ǹ� : D0542487 
���g��� : 2017/9/23 
dev-cpp version : 5.11 
*/ 
#include <stdio.h>
#include <stdlib.h>

int main() {
	int primeNum[100000] = {}, numNow = 2, i, j, flag;
	printf("�j�M��...\n");
	for(i = 0 ; i < 100000 ;)//��X100000�ӽ�� 
	{
		flag = 1;
		for(j = 0 ; j < i/2 ; j++)//�ˬd�O�_�Q�e����ƾ㰣 
		{
			if(numNow%primeNum[j] == 0)
			{
				flag = 0;
				break;
			}
		}
		if(flag)//����� 
		{
			primeNum[i] = numNow;
			i++;
		}
		numNow++;
	}
	printf("��%d�ӽ�� = %d\n", 100000, primeNum[99998]);//�L�X���� 
	system("pause");
	return 0;
} 
