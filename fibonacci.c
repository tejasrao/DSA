#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	long int curr = 1, next, prev = 0;
	int n = atoi(argv[1]);
	
	if(n <= 0) {
		exit(0);
	}
	printf("0\t1\t");
	while(n--) {
		next = curr + prev;
		curr = next;
		prev = curr;
		printf("%ld\t", next);
	}
}
