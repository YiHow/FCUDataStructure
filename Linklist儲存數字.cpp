/*
�m�W : ������ 
�Ǹ� : D0542487 
���g��� : 2017/11/25 
dev-cpp version : 5.11 
*/ 
#include <stdio.h>
#include <stdlib.h>
typedef struct node *pointer;
struct node{
	int data;
	pointer link;
};
pointer newNode(){
	pointer ptr = NULL;
	ptr = (node*)malloc(sizeof(struct node));
	ptr->link = NULL;
	return ptr;
}
pointer linksort(pointer head){  //�w�j�Ƨ� 
	int size = 0, i, j;
	pointer ptr, temp, curr, prev;
	ptr = head;
	while(ptr){
		ptr = ptr->link;
		size++;
	}
	for(i = size ; i > 0 ; i--){
		curr = head;
		prev = head;
		for(j = 0 ; j < i - 1 && curr->link; j++){
			if(curr->data > curr->link->data){
				temp = curr->link;
				curr->link = temp->link;
				temp->link = curr;
				if(curr == head){
					head = temp;
					prev = temp;
				}else{
					prev->link = temp;
					prev = prev->link;
				}
			}
			else{
				curr = curr->link;
				if(j != 0)prev = prev->link;
			}
		}
	}
	return head;
}
int check(pointer head, int num){  //1 ��� 0 �䤣�� 
	pointer ptr = head;
	while(ptr){
		if(ptr->data == num){
			return 1;
		}
		ptr = ptr->link;
	}
	return 0;
}
int main(){
	int select, num, num2, flag;
	pointer head = NULL;
	pointer newptr, ptr, ptr2;
	while(1){
		printf("Input : 1.�s�W 2.�ק� 3.�R�� 4.�L�X 5.���} : ");
		scanf("%d", &select);
		switch(select){
			case 1:
				newptr = newNode();
				printf("��J�n�s�W���Ʀr : ");
				scanf("%d", &num);
				newptr->data = num;
				if(check(head, num)) printf("error!\n");
				else{
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
				if(head->link)head = linksort(head);
				break;
			case 2:
				if(!head){
					printf("empty\n");
					break; 
				}
				printf("��J�n�ק諸�Ʀr : ");
				scanf("%d", &num);
				printf("��J�n�令���Ʀr : ");
				scanf("%d", &num2);
				ptr = head;
				if(!check(head, num)) printf("not found\n");
				else if(check(head, num2)) printf("error!\n");
				else{
					while(ptr->data != num){ 
						ptr = ptr->link;
					} 
					ptr->data = num2;
				}
				if(head->link)head = linksort(head);
				break;
			case 3:  
				if(!head){
					printf("empty\n");
					break; 
				}
				printf("��J�n�R�����Ʀr : ");
				scanf("%d", &num);
				ptr = head;
				ptr2 = NULL;
				if(check(head, num)){
					if(ptr->data == num){
						head = head->link;
						free(ptr);
					}
					else{
						while(ptr->data != num ){
							ptr2 = ptr;
							ptr = ptr->link;
						}
						ptr2->link = ptr->link;
						free(ptr);
					}
				}
				else printf("not found\n");
				break;
			case 4:
				ptr = head;
				while(ptr){
					printf("%d ", ptr->data);
					ptr = ptr->link;
				}
				printf("\n");
				break;
			case 5:
				printf("exit\n");
				return 0;
			default:
				printf("Input Error!\n");
				break;
		}
	}
	return 0;
}
