#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int key;
}element;
element stack[6];
int top = -1;
void push(int item){
	if(top >= 5){
		printf("Stack is full,  can't add element.\n\n");
	}
	else
		stack[++top].key = item;
}
int pop(){
	if(top == -1){
		printf("Stack is empty.\n\n");
	}
	else{
		printf("pop : %d\n\n", stack[top--].key);
		return stack[top--].key;
	} 
}
int main(){
	int flag = 0;
	int num;
	while(flag != 3){
		printf("Input : \n1.push\n2.pop\n3.exit\n");
		scanf("%d", &flag);
		switch(flag){
			case 1 :
				printf("Input the number : \n");
				scanf("%d", &num);
				push(num);
				break;
			case 2 :
				num = pop();
				break;
			case 3 :
				return 0;
		}
	}
	return 0;
}

