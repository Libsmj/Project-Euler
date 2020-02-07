#include <stdio.h>
#include <stdlib.h>

/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

int main(int argc, char** argv) {
	printf("Problem 20 - Factorial digit sum\n");
	int n = 10;
	int p = 1;
	for (int i = 2; i < n + 1; i++) {
		p *= i;
		if (p > 10) {
			
		}
	}
	printf("%d\n", p);
	return 0;
}