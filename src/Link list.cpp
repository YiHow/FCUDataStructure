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
		printf("1.新增數字 2.修改數字 3.插入數字 4.刪除數字 5.全部印出 6.離開:\n");
		scanf("%d", &select);
		switch(select){
			case 1:	 										//新增 
				printf("輸入新增的數字 :");
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
			case 2: 										//修改 
				if(head == NULL){
					printf("The list is empty!\n");
					break;
				}
				printf("輸入要修改的數字 :");
				scanf("%d", &num);
				if(search(head, num)){
					printf("要改成的數字 :");
					scanf("%d", &num2);
					ptr = head;
					while(ptr->data != num)
						ptr = ptr->link;
					ptr->data = num2;
				}
				else{
					printf("無此數字\n");
				}
				break;
			case 3: 										//插入 
				if(head == NULL){
					printf("The list is empty!\n");
					break;
				} 
				printf("輸入要插入的數字 :");
				scanf("%d", &num2); 
				printf("輸入要插在哪個數字後面(以第一個為準) :");
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
					printf("無此數字!\n");
				}
				break;
			case 4: 										//刪除 
				if(head == NULL){
					printf("The list is empty!\n");
					break;
				}
				printf("輸入要刪除的數字 :");
				scanf("%d", &num);
				if(search(head, num)){
					if(head->data == num){  //刪除的是頭 
						ptr = head;
						head = head->link;
						free(ptr);	
					}	
					else{					//刪除的是中間 
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
					printf("無此數字\n");
				}
				break;
			case 5: 										//印出
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
			case 6:										 	//離開 
				ptr = head;
				while(ptr != NULL){
					ptr2 = ptr;
					ptr = ptr->link;
					free(ptr2);	
				} 
				return 0;
			default :
				printf("輸入錯誤!\n");
				break;
		}
		printf("\n");
	}
	return 0;
}
