#include <stdio.h>

/*
	If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

	Find the sum of all the multiples of 3 or 5 below 1000.
*/

int main() {
	printf("Problem 1 - Multiples of 3 and 5\n");
	int count = 0;
	int num = 3;
	while (num < 1000) {
		count += num;
		num += 3;
	}
	num = 5;
	while (num < 1000) {
		if (num % 3)
			count += num;
		num += 5;
	}
	printf("Num of multiples of 3 and 5 between 0 and 1000 - %d\n", count);
	return 0;
}
