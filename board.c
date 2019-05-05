#include<stdio.h>
#include<stdlib.h>

int forward(int x, int y) {
	if(x == 0 && y == 0) return 1;
	else if(x == 0) return forward(x, y - 1);
	else if(y == 0) return forward(x - 1, y);
	else return forward(x, y - 1) + forward(x - 1, y);
}

int main(int argc, char* argv[]) {
	int arr[100][100];
	int i, j;

	int x1 = atoi(argv[1]);
	int y1 = atoi(argv[2]);
	int x2 = atoi(argv[3]);
	int y2 = atoi(argv[4]);

	int x = x2 - x1;
	int y = y2 -y1;

	if(x < 0 || y < 0) {
		printf("Invalid co-ordinates\n");
		exit(0);
	}
	
	// printf("%d\n", forward(x, y));

	for(i = 0; i <= x; i++) {
		for(j = 0; j <= y; j++) {
			if(i == 0 || j == 0) arr[i][j] = 1;
			else if(i == 0) arr[i][j] = arr[i][j - 1];
			else if(j == 0) arr[i][j] = arr[i - 1][j];
			else arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}
	printf("%d\n", arr[x][y]);
	return 0;
} 
