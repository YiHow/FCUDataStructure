#include <stdio.h>
#include <stdlib.h>
//A(X) = 2X 10 + 5X 7 + 8X 2
//B(X) = 8X 7 + 9X 4 + 3X 2 + 2

typedef struct{
	int coef;
	int expon;
}poly;

int main(){
	poly terms[100];
	int avail; 
	int startA = 0;
	int finishA = 2;
	int startB = 3;
	int finishB = 6;
	int startC;
	int finishC;
	avail = 7;
	
 	terms[0].coef = 2;
	terms[0].expon = 10; 
	
	terms[1].coef = 5;
	terms[1].expon = 7;
	
	terms[2].coef = 8;
	terms[2].expon = 2;
	
	
	terms[3].coef = 8;
	terms[3].expon = 7;
	
	terms[4].coef = 9;
	terms[4].expon = 4;
	
	terms[5].coef = 3;
	terms[5].expon = 2;
	
	terms[6].coef = 2;
	terms[6].expon = 0;
	
	startC = avail;
	while(startA <= finishA && startB <= finishB){
		if(terms[startA].expon > terms[startB].expon){
			terms[avail].expon = terms[startA].expon;
			terms[avail].coef = terms[startA].coef;
			startA++;
		}
		else if(terms[startA].expon < terms[startB].expon){
			terms[avail].expon = terms[startB].expon;
			terms[avail].coef = terms[startB].coef;
			startB++;
		}
		else{
			terms[avail].expon = terms[startB].expon;
			terms[avail].coef = terms[startA].coef + terms[startB].coef;
			startA++;
			startB++;
		}
		avail++;
	}
	while(startA <= finishA)
	{
		terms[avail].expon = terms[startA].expon;
		terms[avail].coef = terms[startA].coef;
		startA++;
		avail++;
	}
	while(startB <= finishB)
	{
		terms[avail].expon = terms[startB].expon;
		terms[avail].coef = terms[startB].coef;
		startB++;
		avail++;
	}
	finishC = avail - 1;
	while(startC <= finishC){
		printf("%dX^%d ", terms[startC].coef, terms[startC].expon);
		startC++;
	}
	return 0;
}

