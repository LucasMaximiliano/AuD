#include<stdio.h>

int maxSubarrayDyn(int* A, int n) {
	int bestSum = A[0];
	int sum = 0;
	for(int i=1; i<n; i++) {
		if(A[i]+sum > 0) {
			sum += A[i];
		} else	//neg numbers make result smaller, therefore ignored (reset)
			sum = 0;
		if(sum>bestSum)
			bestSum = sum;

	}
	return bestSum;
}

int main() {
	//Test
	int a[6] = {0,3,-7,2,1,4};
	int b[5] = {2,-1,1,-5,1};
	int c[4] = {-7,1,50,-30};
	printf("Die maximale Teilsequenz von a = [0 3 -7 2 1 4] ist : %d\n", maxSubarrayDyn(a,6));	
	printf("Die maximale Teilsequenz von b = [2 -1 1 -5 1] ist : %d\n", maxSubarrayDyn(b,5));
	printf("Die maximale Teilsequenz von c = [-7 1 50 -30] ist : %d\n", maxSubarrayDyn(c,4));
	return 0;
}
