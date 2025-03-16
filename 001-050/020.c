#include <stdio.h>
#include <stdlib.h>

#define max 200

/*
	n! means n × (n − 1) × ... × 3 × 2 × 1

	For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
	and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

	Find the sum of the digits in the number 100!
*/

int main(int argc, char** argv) {
	printf("Problem 20 - Factorial digit sum\n");
	int n = 100;
	int* d = calloc(max, sizeof(int));
	int p = 1;
	d[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < p; j++) {
			d[j] *= i;
		}
		for (int j = 0; j < p; j++) {
			d[j + 1] += d[j] / 10;
			d[j] %= 10;
			if (d[p]) {
				p++;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < p; i++) {
		sum += d[i];
	}

	printf("%d\n", sum);
	free(d);
	return 0;
}