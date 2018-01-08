/*
姓名 : 黃羿豪 
學號 : D0542487 
撰寫日期 : 2017/10/10 
dev-cpp version : 5.11 
*/ 
#include <stdio.h>
#include <stdlib.h>

int main(){
	int **x, i = 0, j = 0, count = 1, size, temp, tempsize, iplus, jplus; //temp控制螺旋大小 
	//輸入大小(1~10) 
	do{
		printf("輸入矩陣寬度 : ( 1 ~ 10 )\n");
		scanf("%d", &size);
	}while(size > 10 || size <= 0);
	printf("\n");
	
	//動態分配矩陣大小 
	x = (int**)malloc(size*sizeof(*x));
	for(i = 0 ; i < size ; i++){
		x[i] = (int*)malloc(size*sizeof(x));
	}
	
	//逆時針 
	//第一排 
	for(i = 0 ; i < size ; i++){ 
		x[i][j] = count++;	
	}
	i--;
	
	tempsize = size - 1;
	iplus = -1; //往上遞增 
	jplus = 1; //往右遞增
	while(tempsize > 0){
		
		j += jplus; //左右 
		for(temp = 0 ; temp < tempsize ; temp++){ 
			x[i][j] = count++;
			j += jplus;
		}
		j -= jplus;
		
		i += iplus; //上下 
		for(temp = 0 ; temp < tempsize ; temp++){ 
			x[i][j] = count++;
			i += iplus;
		}
		i -= iplus;
		
		tempsize--;
		
		iplus *= -1; //方向改變 
		jplus *= -1; //方向改變	
	}
	printf("逆時針 : \n\n"); //印出矩陣 
	for(i = 0 ; i < size ; i++){
		for(j = 0 ; j < size ; j++){
			printf("%3d    ", x[i][j]);
		}
		printf("\n\n"); 
	}
	printf("順時針 : \n\n"); //印出矩陣 
	for(i = 0 ; i < size ; i++){
		for(j = 0 ; j < size ; j++){
			printf("%3d    ", x[j][i]);//i, j互換 
		}
		printf("\n\n"); 
	}
	
	//釋放記憶體 
	for(i = 0 ; i < size ; i++){ 
		free(x[i]);
	}
	free(x);
	
	return 0;
} 

