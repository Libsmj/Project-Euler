#include <stdio.h>
#include <stdlib.h>

/*
	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

	What is the sum of the digits of the number 2^1000?
*/

// Brute force calculates 2^x and stores the digits in an array
int main(int argc, char* argv[]) {
	printf("Problem 16 - Power digit sum\n");
	if (argc < 2) {
		fprintf(stderr, "ERROR: Ussage ./a.out x\n");
		fprintf(stderr, "Problem 16 calculates the sum of all the digits of 2^x\n");
		return 1;
	}
	int power = atoi(argv[1]);
	char* digits = calloc(power, sizeof(char));
	int rank = 0;
	digits[0] = 1;
	for (int i = 0; i < power; i++) {
		for (int j = rank; j > -1; j--) {
			digits[j] *= 2;
			if (digits[j] > 9) {
				digits[j + 1] += 1;
				digits[j] -= 10;
			}
		}
		if (digits[rank + 1] != 0) {
			rank++;
		}
#ifdef debug
		for (int j = rank; j > -1; j--) {
			printf("%c", digits[j] + '0');
		}
		printf("\n");
#endif
	}
	int sum = 0;
	for (int i = 0; i < power; i++)
		sum += digits[i];
	free(digits);
	printf("%d\n", sum);
	return 0;
}
