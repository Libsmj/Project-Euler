#include <stdio.h>
#include <stdlib.h>

/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/


// Calculates all of the sums of proper devisors for all numbers under 'size'
// Then checks for all amicable numbers - i == sums[sums[i]]
int divisor_sum(int);

int main(int argc, char** argv) {
	printf("Problem 21 - Amicable numbers\n");
	if (argc < 2) {
		fprintf(stderr, "ERROR: Ussage ./a.out size\n");
		fprintf(stderr, "Problem 21 calculates the sum of all the amicable numbers under 'size'\n");
		return 1;
	}
	int i, sum, size;
	size = atoi(argv[1]);
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

	free(sums);
	return 0;
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
