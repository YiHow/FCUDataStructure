#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
typedef struct{
	int num;  
}element;
void enqueue(element q[], int* rear, int* front){
	int newRear = (*rear + 1)%SIZE;
	int num;
	if(*front == newRear){
		printf("queue is full!!\n\n");
	}
	else{
		printf("please enter the number : \n");
		scanf("%d", &num);
		printf("enqueue finish!!\n\n");
		q[newRear].num = num;
		*rear = newRear;
	}
}
void dequeue(element q[], int* rear, int* front){
	if(*front == *rear){
		printf("queue is empty!!\n\n");
	}
	else{
		*front = (*front + 1)%SIZE;
		printf("the number is %d\n\n", q[*front].num);
	}
}
int main(){
	int flag;
	int rear = 0, front = 0;
	element queue[SIZE];
	while(1){
		printf("please input 1.enqueue  2.dequeue  3.exit\n");
		scanf("%d", &flag);
		switch(flag){
			case 1 :	
				enqueue(queue, &rear, &front);
				break;
			case 2 :
				dequeue(queue, &rear, &front);
				break;
			case 3 :
				return 0;
			default : 
				printf("wrong input!!\n\n"); 
		} 
	}
	return 0;
}

