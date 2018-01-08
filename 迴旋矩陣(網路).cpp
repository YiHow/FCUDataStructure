#include <stdio.h>
#include <stdlib.h>

int main(void) { 
	int n[30][30] = {0}; 
	int size, r; 
	int x = 0, y = 0, nx, ny; //這一步、下一步 
	int ax, ay, rx, ry; //增量、轉向 
	int temp; 
	int num = 1; 

	do { 
		printf("輸入size及旋轉方向 :"); 
		scanf("%d,%d", &size, &r); 
	} while (size < 1 || size > 30 || r < 1 || r > 2); 

	if (r == 1) { 
		ax = 1; 
		ay = 0; 
		rx = -1; 
		ry = 1; 
	}	 
	else { 
		ax = 0; 
		ay = 1; 
		rx = 1; 
		ry = -1; 
	} 

	while (num <= size * size) { 
		n[y][x] = num; 

	//下一步 
		nx = x + ax; 
		ny = y + ay; 

	//變更旋轉方向 
		if (nx < 0 || nx >= size || 
			ny < 0 || ny >= size || 
			n[ny][nx] != 0) { 

			temp = ax; 
			ax = ay * rx; 
			ay = temp * ry; 
		} 

		x += ax; 
		y += ay; 
		num++; 
	} 

//印出 
	int i, j; 
	for (i = 0; i < size; i++) { 
	for (j = 0; j < size; j++) { 
		if (j != 0) 
			printf(","); 
		printf("%03g", (float)n[i][j]); 
	} 
	printf("\n"); 
	} 
	return 0; 
}
