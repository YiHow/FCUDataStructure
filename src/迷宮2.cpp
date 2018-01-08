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
    while(top > -1 && !found)   //�����|�ӥB�䤣��X�f
    {
        position = pop();   
        row = position.row;
        col = position.col;
        dir = position.dir;
        while(dir < 8 && !found)   //�٦���L��V�S����ӥB�䤣��X�f
        {
            nextRow = row + move[dir].vert;     //���ͤU�@�Brow��m
            nextCol = col + move[dir].horiz;    //���ͤU�@�Bcol��m

            if(nextRow == EXIT_ROW && nextCol == EXIT_COL)  //�P�w�O�_���X�f
            {
                found = true;    //���F
            }
            else if(!maze[nextRow][nextCol] && !mark[nextRow][nextCol])  //�O�_�i�H���ӥB�O�S���L����
            {
                mark[nextRow][nextCol] = 1;  //��U�@�B���аO
                position.row = row;     //�{�brow��m
                position.col = col;     //�{�bcol��m
                position.dir = ++dir;   //�U��������V
                push(position);         
                row = nextRow;          //�U����row��m
                col = nextCol;          //�U����col��m
                dir = 0;                //�q�Ĥ@�ղ��ʤ�V�}�l��_
            }
            else
            {
                ++dir;               //���U�@�ղ��ʤ�V
            }
        }
    }
    
    if(found)                 //�����X�f
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
