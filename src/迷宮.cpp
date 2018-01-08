/*
姓名 : 黃羿豪 
學號 : D0542487 
撰寫日期 : 2017/10/31
dev-cpp version : 5.11 
*/ 
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	short int row;
	short int col;
	short int from; //從哪個方向來 
	short int dir; 	//下一步的方向 
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
int countCol(FILE *fptr){ 						//計算檔案數字數量 
	char temp[50];
	int col = 0;
	while(fgets(temp, 50, fptr) != NULL){ 		//讀取一行 
		col++;
	}
	rewind(fptr); 	//回到檔案開頭 
	return col;
}
int countRow(FILE *fptr){ 						//計算檔案數字數量  	
	int temp, sum = 0;
	while(fscanf(fptr,"%d", &temp) != EOF){ 	//讀一個字元 
		sum++;
	}
	rewind(fptr); //回到檔案開頭 
	return sum/countCol(fptr);
}
void getDir(int dir, int row, int col, int *nrow, int *ncol){  //依照dir給nrow & ncol 
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
	FILE* fptr = fopen("maze.txt", "r"); 								//開檔 
	if(fptr == NULL){
		printf("File no found !");
		return -1;
	}
	row = countRow(fptr);  												//計算row 
	col = countCol(fptr);  												//計算col 
	int map[col][row];  												//地圖 
	int result[col][row]; 												//結果路徑 
	while(fscanf(fptr, "%d", &temp) != EOF){ 							//讀檔放進地圖		 
		map[i][j++] = temp;
		if(j == row){
			j = 0;
			i++;
		}
	}
	//第一格 
	stack[0].row = 1;													 
	stack[0].col = 1;
	stack[0].dir = 2;
	top = 0;
	//還沒找到終點執行迴圈 
	while(stack[top].row != row-2 || stack[top].col != col-2){ 
		flag = 1;
		count = 0;
		dir = stack[top].dir + 1;
		item.row = stack[top].row;
		item.col = stack[top].col;
		while(count++ < 7){												//7個方向 
			item.row = stack[top].row;
			item.col = stack[top].col;
			dir = (dir + 1)%8;
			if(dir == stack[top].from)dir = (dir + 1)%8;
			getDir(dir, item.row, item.col, &nrow, &ncol);				//用dir 0~7 回傳下個點的座標 
			if(map[ncol][nrow] == 0){ 									//找到路 
				flag = 0;
				stack[top].dir = dir;
				stack[++top].row = nrow;
				stack[top].col = ncol;
				stack[top].from = 7 - dir;
				map[item.col][item.row] = 2;							//走過的路改成2 
				break;
			}
		}
		if(flag && top == 0){											//無路可到終點 
			printf("No path!!\n");
			havePath = 0;
			break;
		}
		if(flag){														//沒找到路返回上個路徑 
			map[item.col][item.row] = 2;
			item.row = stack[top - 1].row;
			item.col = stack[top - 1].col;
			item.from = stack[top - 1].from;
			item.dir = stack[top - 2].dir;
			top--;
		}
	}
	if(havePath){
		//結果地圖預設1 
		for(i = 0 ; i < col ; i++){ 
			for(j = 0 ; j < row ; j++){
				result[i][j] = 1;
			}
		}
		//從stack pop 路徑出來 
		while(top > -1){ 
			item = pop();
			result[item.col][item.row] = 0;
		}
		//印出結果 
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

