#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isPrime(int n){
	int i;
	if(n <= 1)
		return 0;
	for(i = 2; i <= (int)sqrt(n) + 1; i++)
		if(n % i == 0)	return 0;
	return 1;
	
}

void test_prime(){
	int nums[10] = {-1, 2, 1, 13, 11, -11, 27, 100, -100, 0};
	int res[10]  = { 0, 0, 0,  1,  1,   0,  0,   0,    0, 0};
	int i;
	for(i = 0; i < 10; i++){
		if(isPrime(nums[i]) == 0){
			if(res[i] == 0) printf("PASS\n");
			else printf("FAIL\n");
		}else{
			if(res[i] == 1) printf("PASS\n");
                        else printf("FAIL\n");
		}
	}
}

int checkSumPair(int n){
	int p;
	if(n <= 3)
		return 0;
	else{
		p = n - 2;
		if(isPrime(p) == 1)
			return 1;
	}
	return 0;
}

void test_checkSumPair(){
	int nums[10] = {2, 3, 5, 7, 11, 13, 17, 23, 29, 31};
        int res[10]  = {0, 0, 1, 1,  0,  1,  0,  0,  0,  1};
        int i;
        for(i = 0; i < 10; i++){
                if(checkSumPair(nums[i]) == 0){
                        if(res[i] == 0) printf("PASS\n");
                        else printf("FAIL\n");
                }else{
                        if(res[i] == 1) printf("PASS\n");
                        else printf("FAIL\n");
                }
        }
}

int main(int argc, char* argv[]){
	// isPrime(atoi(argv[1]));
	// test_prime();
	// checkSumPair(atoi(argv[1]));
	test_checkSumPair();
	return 0;
}
