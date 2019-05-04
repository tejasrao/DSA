#include<stdio.h>
#include<stdlib.h>


void sort(int arr[], int n){
	int i, j, temp;
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			if(arr[i] > arr[j]){
				temp   = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}		
	}
}

void sumPairs(int arr[], int n, int sum){
	int i = 0, j = n - 1;
	// sort(arr, n);
	while(i < j){
		if( (arr[i] + arr[j]) > sum)
			j -= 1;
		else if((arr[i] + arr[j]) < sum)
			i += 1;
		else{
			printf("%d %d\n", arr[i], arr[j]);
			i += 1;
			j -= 1;
		}
	}
	
}

int main(void){
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = 7;
	sumPairs(arr, 10, sum);
	return 0;
}
