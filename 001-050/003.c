#include <stdio.h>

/*
	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143 ?
*/

long long isPrime(long long n);

int main() {
	printf("Problem 3 - Largest prime factor\n");
	long long num = 600851475143;
	long long smallFactor = 2;
	long long largeFactor;
	char found = 0;

	printf("Finding the largest prime factor of the number %lld\n", num);
	// Tests numbers starting from 1/2 the target number
	while (!found && smallFactor <= num / 2) {
		// Test to see if the number is a factor
		if (!(num % smallFactor)) {
			largeFactor = num / smallFactor;
			// Test if the factor is prime
			printf("Testing if the number %lld is prime\n", largeFactor);
			found = isPrime(largeFactor);
		}
		smallFactor++;
	}
	if (found) {
		printf("The largest prime factor of the number %lld is %lld\n", num, largeFactor);
	}
	else {
		printf("%lld is a prime number\n", num);
	}
	return 0;
}

long long isPrime(long long n) {
	if (n < 4) {
		return n > 1;
	}
	if (!(n % 2) || !(n % 3)) {
		return 0;
	}
	long long i = 5;
	while (i * i < n + 1) {
		if (!(n % i) || !(n % (i + 2))) {
			return 0;
		}
		i += 6;
	}
	return 1;
}