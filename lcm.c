#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b){
	if(a == 0)
		return b;
	else if(b == 0)
		return a;
	if(a == b)
		return a;
	if(a > b)
		return gcd(b, a - b);
	else
		return gcd(a, b - a);
}

int lcm(int a, int b){
	if(a <= 0 || b <= 0) return -1;
	int n = gcd(a, b);
	return (a * b) / n;
}	

void test_lcm(){
	int a[10]    = { 6, 5, 4, 13, 11, -11, 27, 100, -100, 0};
	int b[10]    = { 1, 2, 3, 4, 5, 0, -1, -2, 11, 105};
        int res[10]  = { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0};
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


int main(int argc, char* argv[]){
	// printf("%d\n", lcm(atoi(argv[1]), atoi(argv[2])));
	test_lcm();
	return 0;
}
