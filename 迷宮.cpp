/*
�m�W : ������ 
�Ǹ� : D0542487 
���g��� : 2017/10/31
dev-cpp version : 5.11 
*/ 
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	short int row;
	short int col;
	short int from; //�q���Ӥ�V�� 
	short int dir; 	//�U�@�B����V 
	int rum;
}element;
element stack[100];
int top = -1;
void push(element item){
	if(top >= 99){
		printf("%d Stack is full ! \n", top);
	}
	else
		stack[++top] = item;
}
element pop(){
	if(top == -1){
		printf("Stack is empty !\n");
	}
	else
		return stack[top--];
}
int countCol(FILE *fptr){ 						//�p���ɮ׼Ʀr�ƶq 
	char temp[50];
	int col = 0;
	while(fgets(temp, 50, fptr) != NULL){ 		//Ū���@�� 
		col++;
	}
	rewind(fptr); 	//�^���ɮ׶}�Y 
	return col;
}
int countRow(FILE *fptr){ 						//�p���ɮ׼Ʀr�ƶq  	
	int temp, sum = 0;
	while(fscanf(fptr,"%d", &temp) != EOF){ 	//Ū�@�Ӧr�� 
		sum++;
	}
	rewind(fptr); //�^���ɮ׶}�Y 
	return sum/countCol(fptr);
}
void getDir(int dir, int row, int col, int *nrow, int *ncol){  //�̷�dir��nrow & ncol 
	switch(dir){
		case 0:
			*ncol = col - 1;
			*nrow = row;
			break;
		case 1:
			*ncol = col - 1;
			*nrow = row + 1;
			break;
		case 2:
			*ncol = col;
			*nrow = row + 1;
			break;
		case 3:
			*ncol = col + 1;
			*nrow = row + 1;
			break;
		case 4:
			*ncol = col - 1;
			*nrow = row - 1;
			break;
		case 5:
			*ncol = col;
			*nrow = row - 1;
			break;
		case 6:
			*ncol = col + 1;
			*nrow = row - 1;
			break;
		case 7:
			*ncol = col + 1;
			*nrow = row;
			break;	
	}
}
int main(){
	element item;
	int row, col, nrow, ncol, i = 0, j = 0, dir, temp, flag, count, havePath = 1;;
	FILE* fptr = fopen("maze.txt", "r"); 								//�}�� 
	if(fptr == NULL){
		printf("File no found !");
		return -1;
	}
	row = countRow(fptr);  												//�p��row 
	col = countCol(fptr);  												//�p��col 
	int map[col][row];  												//�a�� 
	int result[col][row]; 												//���G���| 
	while(fscanf(fptr, "%d", &temp) != EOF){ 							//Ū�ɩ�i�a��		 
		map[i][j++] = temp;
		if(j == row){
			j = 0;
			i++;
		}
	}
	//�Ĥ@�� 
	stack[0].row = 1;													 
	stack[0].col = 1;
	stack[0].dir = 2;
	top = 0;
	//�٨S�����I����j�� 
	while(stack[top].row != row-2 || stack[top].col != col-2){ 
		flag = 1;
		count = 0;
		dir = stack[top].dir + 1;
		item.row = stack[top].row;
		item.col = stack[top].col;
		while(count++ < 7){												//7�Ӥ�V 
			item.row = stack[top].row;
			item.col = stack[top].col;
			dir = (dir + 1)%8;
			if(dir == stack[top].from)dir = (dir + 1)%8;
			getDir(dir, item.row, item.col, &nrow, &ncol);				//��dir 0~7 �^�ǤU���I���y�� 
			if(map[ncol][nrow] == 0){ 									//���� 
				flag = 0;
				stack[top].dir = dir;
				stack[++top].row = nrow;
				stack[top].col = ncol;
				stack[top].from = 7 - dir;
				map[item.col][item.row] = 2;							//���L�����令2 
				break;
			}
		}
		if(flag && top == 0){											//�L���i����I 
			printf("No path!!\n");
			havePath = 0;
			break;
		}
		if(flag){														//�S������^�W�Ӹ��| 
			map[item.col][item.row] = 2;
			item.row = stack[top - 1].row;
			item.col = stack[top - 1].col;
			item.from = stack[top - 1].from;
			item.dir = stack[top - 2].dir;
			top--;
		}
	}
	if(havePath){
		//���G�a�Ϲw�]1 
		for(i = 0 ; i < col ; i++){ 
			for(j = 0 ; j < row ; j++){
				result[i][j] = 1;
			}
		}
		//�qstack pop ���|�X�� 
		while(top > -1){ 
			item = pop();
			result[item.col][item.row] = 0;
		}
		//�L�X���G 
		for(i = 0 ; i < col ; i++){ 
			for(j = 0 ; j < row ; j++){
				printf("%d ", result[i][j]);
			}
			printf("\n");
		}
	}
	fclose(fptr);
	return 0;
}

