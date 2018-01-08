#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100	
#define COL 17 	
#define ROW 13 	
#define EXIT_COL COL-2  
#define EXIT_ROW ROW-2  
#define FALSE 0  
#define true 1
typedef struct
{
    int row;
    int col;
    int dir;
}element;
int top
element stack[MAX_STACK_SIZE]={0};

typedef struct
{
    int vert;
    int horiz;
}offsets;
offsets move[8] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};	 

void push(element item)	  
{
    if(top>=MAX_STACK_SIZE-1)
    {
        printf("stack is full!!\n");
    }
    stack[++top]=item;
}

element pop()	
{
    if(top==-1)
    {
        printf("stack is empty!!\n");
    }
    return stack[top--];
}

void path(void)
{
    FILE * fptr = fopen("maze.txt","r");	
    int i,j=0,k=0,row,col,nextRow,nextCol,dir,found = FALSE;
    int mark[ROW][COL]= {0},maze[ROW][COL],result[ROW][COL],temp;
    while(fscanf(fptr,"%d",&temp)!=EOF)		
    {
        maze[j][k] = temp;
        k++;
        if(k == COL)
        {
            j++;
            k=0;
        }
    }
    for(j=0; j<ROW; j++)   /
    {
        for(k=0; k<COL; k++)
        {
            result[j][k]=1;    
        }
    }
    element position;
    mark[1][1] = 1;  
    top = 0;  
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 1;
    while(top > -1 && !found)   //有堆疊而且找不到出口
    {
        position = pop();   
        row = position.row;
        col = position.col;
        dir = position.dir;
        while(dir < 8 && !found)   //還有其他方向沒有找而且找不到出口
        {
            nextRow = row + move[dir].vert;     //產生下一步row位置
            nextCol = col + move[dir].horiz;    //產生下一步col位置

            if(nextRow == EXIT_ROW && nextCol == EXIT_COL)  //判定是否為出口
            {
                found = true;    //找到了
            }
            else if(!maze[nextRow][nextCol] && !mark[nextRow][nextCol])  //是否可以走而且是沒走過的路
            {
                mark[nextRow][nextCol] = 1;  //對下一步做標記
                position.row = row;     //現在row位置
                position.col = col;     //現在col位置
                position.dir = ++dir;   //下次走的方向
                push(position);         
                row = nextRow;          //下次的row位置
                col = nextCol;          //下次的col位置
                dir = 0;                //從第一組移動方向開始找起
            }
            else
            {
                ++dir;               //換下一組移動方向
            }
        }
    }
    
    if(found)                 //有找到出口
    {
        for(i=0;i<=top;i++)
        {
            result[stack[i].row][stack[i].col]=0;	 
        }
        result[row][col]=0;
        result[EXIT_ROW][EXIT_COL]=0;
        for(i=0;i<ROW;i++)
        {
            for(j=0;j<COL;j++)  
            {
                printf("%d ",result[i][j]);    
            }
            printf("\n");
        }
    }
    else
    {
        printf("No path!\n");   
    }
    fclose(fptr);  
}
int main(){
    path();
    return 0;
}
