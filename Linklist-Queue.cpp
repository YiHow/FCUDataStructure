#include <stdio.h>
#include <stdlib.h>
typedef struct stack *pointer;
struct stack{
	int data;
	pointer link;
};
pointer head = NULL;
pointer ptr, ptr2, newptr;
pointer newNode(){
	pointer ptr = NULL;
	ptr = (pointer)malloc(sizeof(struct stack));
	ptr->link = NULL;
	return ptr;
}
pointer dequeue(){
	ptr = head;
	ptr2 = NULL;
	if(!ptr){
		return head;
	}
	else{
		head = ptr->link;
		return ptr;
	}
}

void enqueue(int key){
	newptr = newNode();
	newptr->data = key;
	if(!head){
		head = newptr;
	}
	else{
		ptr = head;
		while(ptr->link){
			ptr = ptr->link;
		}
		ptr->link = newptr;
	}
}

int main(){
	int select, num;
	pointer get;
	while(1){
		printf("Queue �п�J 1.dequeue 2.enqueue 3.�L�X 4.exit : ");
		scanf("%d", &select);
		fflush(stdin);
		switch(select){
			case 1:
				get = dequeue();
				if(get != NULL){
					printf("dequeue�X�Ӫ��Ʀr : %d\n", get->data);
					if(get != head)free(get);
					else head = NULL;
				}
				else{
					printf("Queue�L���!\n");
				}
				break;
			case 2:
				printf("��J�nenqueue���Ʀr : ");
				scanf("%d", &num);
				enqueue(num);
				break;
			case 3:
				ptr = head;
				while(ptr){
					printf("%d ", ptr->data);
					ptr = ptr->link;
				}
				printf("\n");
				break;
			case 4:
				printf("���}");
				return 0;
			default:
				printf("��J���~!\n");
		}
		printf("\n");
	}
	return 0;
}

