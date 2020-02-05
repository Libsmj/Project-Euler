// 003 - Largest prime factor
// @author Jacob Libsman

#include <stdio.h>

int main() {
	long long num = 600851475143;
	long long smallFactor = 2;
	long long largeFactor;
	char found = 0;

	printf("Finding the largest prime factor of the number %lld\n", num);
	// Tests numbers starting from 1/2 the target number
	while (!found && smallFactor <= num / 2) {
		// Test to see if the number is a factor
		if (num % smallFactor == 0) {
			largeFactor = num / smallFactor;
			// Test if the factor is prime
			printf("Testing if the number %lld is prime\n", largeFactor);
			long long testNum = 2;
			while (largeFactor % testNum != 0 && testNum <= largeFactor / 2)
				testNum++;
			if (testNum >= largeFactor / 2)
				found = 1;
		}
		smallFactor++;
	}
	if (found) {
		printf("The largest prime factor of the number %lld is %lld\n",num, largeFactor);
	}
	else {
		printf("%lld is a prime number\n", num);
	}
	return 0;
}
