#include <stdio.h>
#include <stdlib.h>
typedef struct Node *pointer;
struct Node{
	int data;
	pointer link;
};
pointer newNode(){
	pointer ptr = NULL;
	ptr = (pointer)malloc(sizeof(struct Node));
	ptr->link = NULL;
	return ptr;
}
int search(pointer head, int num){
	pointer ptr;
	if(head == NULL){
		printf("The list is empty!\n");
		return 0;
	}
	ptr = head;
	while(ptr != NULL){
		if(ptr->data == num){
			return 1;
		}
		ptr = ptr->link;
	}
	return 0;
}
int main(){
	int select;
	pointer head = NULL;
	pointer ptr, ptr2, newptr, delptr;
	int num, num2, find;
	while(1){
		printf("1.�s�W�Ʀr 2.�ק�Ʀr 3.���J�Ʀr 4.�R���Ʀr 5.�����L�X 6.���}:\n");
		scanf("%d", &select);
		switch(select){
			case 1:	 										//�s�W 
				printf("��J�s�W���Ʀr :");
				scanf("%d", &num);
				newptr = newNode();
				newptr->data = num;
				if(head == NULL){
					head = newptr;
				}
				else{
					ptr = head;
					while(ptr->link !=NULL)
						ptr = ptr->link;
					ptr->link = newptr;
				}
				break;		
			case 2: 										//�ק� 
				if(head == NULL){
					printf("The list is empty!\n");
					break;
				}
				printf("��J�n�ק諸�Ʀr :");
				scanf("%d", &num);
				if(search(head, num)){
					printf("�n�令���Ʀr :");
					scanf("%d", &num2);
					ptr = head;
					while(ptr->data != num)
						ptr = ptr->link;
					ptr->data = num2;
				}
				else{
					printf("�L���Ʀr\n");
				}
				break;
			case 3: 										//���J 
				if(head == NULL){
					printf("The list is empty!\n");
					break;
				} 
				printf("��J�n���J���Ʀr :");
				scanf("%d", &num2); 
				printf("��J�n���b���ӼƦr�᭱(�H�Ĥ@�Ӭ���) :");
				scanf("%d", &num);
				if(search(head, num)){

					newptr = newNode();
					newptr->data = num2;
					/*if(head->data == num){		
						newptr->link = head;
						head = newptr;
						break;
					}
					else{	*/						
						ptr = head;
						while(ptr->data != num){
							ptr = ptr->link;
						}
						newptr->link = ptr->link;
						ptr->link = newptr;
					//}
				}
				else{
					printf("�L���Ʀr!\n");
				}
				break;
			case 4: 										//�R�� 
				if(head == NULL){
					printf("The list is empty!\n");
					break;
				}
				printf("��J�n�R�����Ʀr :");
				scanf("%d", &num);
				if(search(head, num)){
					if(head->data == num){  //�R�����O�Y 
						ptr = head;
						head = head->link;
						free(ptr);	
					}	
					else{					//�R�����O���� 
						ptr = head->link;
						ptr2 = head;
						while(ptr->data != num){
							ptr = ptr->link;
							ptr2 = ptr2->link;
						}
						ptr2->link = ptr->link;
						free(ptr);
					}				
				}
				else{
					printf("�L���Ʀr\n");
				}
				break;
			case 5: 										//�L�X
				if(head == NULL){
					printf("The list is empty!\n");
					break;
				}
				ptr = head;
				printf("The list : ");
				while(ptr != NULL){
					printf("%d ", ptr->data);
					ptr = ptr->link;
				}
				printf("\n");
				break;
			case 6:										 	//���} 
				ptr = head;
				while(ptr != NULL){
					ptr2 = ptr;
					ptr = ptr->link;
					free(ptr2);	
				} 
				return 0;
			default :
				printf("��J���~!\n");
				break;
		}
		printf("\n");
	}
	return 0;
}
