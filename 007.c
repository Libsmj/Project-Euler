// 007 - 10001st prime
// @author Jacob Libsman

#include <stdio.h>

_Bool isPrime(int num);

int main() {
	int numOfPrime = 2;
	int prime = 1;
	int targetPrimeNum = 10001;
	while (numOfPrime < targetPrimeNum) {
		if (isPrime(prime + 1)) {
			numOfPrime++;
		}
		prime++;
	}
	printf("The 10001st prime number is %d\n", prime);
	return 0;
}

_Bool isPrime(int n) {
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