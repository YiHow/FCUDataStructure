#include <stdio.h>
#include <stdlib.h>
void swap(char *x, char *y){
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void perm(char *list, int start, int end){
	int i;
	if(start==end){
		printf("%s\n", list);
	}
	else{
		for(i = start ; i < end ; i++){
			swap(&list[start], &list[i]);
			perm(list, start+1, end);
			swap(&list[i], &list[start]);
		} 
	}
}
int main(){
	char list[6] = {'A', 'B', 'C', 'D', 'E'};
	perm(list, 0, 5);
	return 0;
}
