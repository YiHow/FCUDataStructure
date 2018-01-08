#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 0, i;
	while(n > 15 || n%2 == 0 || n < 0){
		printf("Input n : ");
		scanf("%d", &n);
	}
	int square[n][n] = {};
	int  x = n/2, y = 0;
	for(i = 0 ; i < n*n ; i++){
		int newx, newy;
		if(i == 0){
			square[y][x] = i + 1;
		}
		else{
			newx = x - 1;
			newy = y - 1;
			if(newx < 0) newx = n - 1;
			if(newy < 0) newy = n - 1;
			if(square[newy][newx] == 0){
				square[newy][newx] = i + 1;
				x = newx;
				y = newy;
			}
			else{
				y++;
				if(y == n) y = 0;
				square[y][x] = i + 1;
			}
		}
	}
	int j, k;
	for(j = 0 ; j < n ; j++){
		for(k = 0 ; k < n ; k++){
			printf("%d ", square[j][k]);
		}
		printf("\n");
	}
	return 0;
}
