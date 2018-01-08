#include <stdio.h> 
#include <stdlib.h> 
void tower(int n,char A,char B,char C)
{
	if(n==1){
	printf("Move disk %d from %c to %c\n",n,A,C);
	}
	else{
		tower(n-1, A, C, B);
		printf("Move disk %d from %c to %c\n",n,A,C);
        tower(n-1, B, A, C);
	}
}
int main() {
	tower(4,'A','B','C');
	return 0;
}
