#include <stdio.h>
#include <stdlib.h>

#define size 28300

/*
	A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. 
	For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

	A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

	As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. 
	By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. 
	However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

	Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

_Bool abundant_num(int);

int main() {
	printf("Problem 23 - Non-abundant sums\n");
	int sum, i, j, max;
	int* nums = malloc(size * sizeof(int));
	_Bool* sums = malloc(size * sizeof(int));
	
	sum = 0;
	for (i = 0; i < size; i++) {
		sum += i;
	}

	for (i = 0, max = 0; i < size; i++) {
		if (abundant_num(i)) {
			nums[max++] = i;
		}
	}

	for (i = 0; i < max; i++) {
		for (j = 0; j < max; j++) {
			sums[nums[i] + nums[j]] = 1;
		}
	}

	for (i = 0; i < size; i++) {
		if (sums[i]){
			sum -= i;
		}
	}
	
	free(nums);
	free(sums);
	printf("%d\n", sum);
	return 0;
}

_Bool abundant_num(int n) {
	int sum, i;
	sum = 0;
	for (i = 1; i < n; i++) {
		if (!(n % i)) { 
			sum += i;
		}
	}
	return sum > n;
}
