#include<stdio.h>
#include<stdlib.h>

int dp[100][100];

int main(int argc, char* argv[]) {
	int arr[3] = { 1, 2, 3};
	int n = 3;
	int stairs = atoi(argv[1]);
	int i, j;


	for(i = 0; i <= stairs; i++) {
		for(j = 0; j < n; j++) {	
			if((i - arr[j]) < 0) dp[i][j] = 0;
			else if((i - arr[j]) == 0) dp[i][j] = 1;
			else dp[i][j] += dp[i - arr[j]][j];
			printf("%d\t", dp[i][j]);
		}
	}
	printf("\n");	
	return 0;
}
