/*
�m�W : ������ 
�Ǹ� : D0542487 
���g��� : 2017/10/10 
dev-cpp version : 5.11 
*/ 
#include <stdio.h>
#include <stdlib.h>

int main(){
	int **x, i = 0, j = 0, count = 1, size, temp, tempsize, iplus, jplus; //temp�������ۤj�p 
	//��J�j�p(1~10) 
	do{
		printf("��J�x�}�e�� : ( 1 ~ 10 )\n");
		scanf("%d", &size);
	}while(size > 10 || size <= 0);
	printf("\n");
	
	//�ʺA���t�x�}�j�p 
	x = (int**)malloc(size*sizeof(*x));
	for(i = 0 ; i < size ; i++){
		x[i] = (int*)malloc(size*sizeof(x));
	}
	
	//�f�ɰw 
	//�Ĥ@�� 
	for(i = 0 ; i < size ; i++){ 
		x[i][j] = count++;	
	}
	i--;
	
	tempsize = size - 1;
	iplus = -1; //���W���W 
	jplus = 1; //���k���W
	while(tempsize > 0){
		
		j += jplus; //���k 
		for(temp = 0 ; temp < tempsize ; temp++){ 
			x[i][j] = count++;
			j += jplus;
		}
		j -= jplus;
		
		i += iplus; //�W�U 
		for(temp = 0 ; temp < tempsize ; temp++){ 
			x[i][j] = count++;
			i += iplus;
		}
		i -= iplus;
		
		tempsize--;
		
		iplus *= -1; //��V���� 
		jplus *= -1; //��V����	
	}
	printf("�f�ɰw : \n\n"); //�L�X�x�} 
	for(i = 0 ; i < size ; i++){
		for(j = 0 ; j < size ; j++){
			printf("%3d    ", x[i][j]);
		}
		printf("\n\n"); 
	}
	printf("���ɰw : \n\n"); //�L�X�x�} 
	for(i = 0 ; i < size ; i++){
		for(j = 0 ; j < size ; j++){
			printf("%3d    ", x[j][i]);//i, j���� 
		}
		printf("\n\n"); 
	}
	
	//����O���� 
	for(i = 0 ; i < size ; i++){ 
		free(x[i]);
	}
	free(x);
	
	return 0;
} 

