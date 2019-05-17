#include <stdio.h>
#include <stdlib.h>

#define size 10000

int divisor_sum(int);

int main() {
	int i, sum;
	int* sums = malloc(size * sizeof(int));
	for (i = 0; i < size; i++) {
		sums[i] = divisor_sum(i);
	}

	sum = 0;
	for (i = 0; i < size; i++) {
		if (sums[i] < size) {
			if (i == sums[sums[i]] && i != sums[i]) {
				sum += i;
			}
		}
	}
	printf("%d\n", sum);
}

int divisor_sum(int n) {
	int sum, i;
	sum = 0;
	for (i = 1; i < n; i++) {
		if (!(n % i)) { 
			sum += i;
		}
	}
	return sum;
}
