#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int row;
	int col;
	int value;
}spar;
int main(){
	FILE *fptr;
	fptr = fopen("sparse.txt","r");
	spar sp[100];
	int a[8][8]; 
	int i, j;
	int index = 1;
	int temp;
	sp[0].row = 8;
	sp[0].col = 8;
	sp[0].value = 0;
	for(i = 0 ; i < 8 ; i++){
		for(j = 0 ; j < 8 ; j++){
			fscanf(fptr, "%d ", &temp);
			a[i][j] = temp;
		}
	}
	
	for(i = 0 ; i < sp[0].row ; i++){
		for(j = 0 ; j < sp[0].col ; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	for(i = 0 ; i < sp[0].row ; i++){
		for(j = 0 ; j < sp[0].col ; j++){
			if(a[i][j] != 0){
				sp[0].value++;
				sp[index].row = i;
				sp[index].col = j;
				sp[index].value = a[i][j];
				index++;
			}
		}
	}
	
	for(i = 1 ; i <= sp[0].value ; i++){
		printf("( %d , %d ) %d\n", sp[i].row, sp[i].col, sp[i].value);
	}
	
	fclose(fptr);
	return 0;
}

