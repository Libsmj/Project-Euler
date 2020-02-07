// 010 - Summation of primes
// @author Jacob Libsman

#include <stdio.h>

_Bool isPrime(int num);

int main() {
	long long sum = 2;
	long long prime = 3;
	while (prime < (long long)2000000) {
		if (isPrime(prime)) {
			sum += prime;
		}
		prime += 2;
	}
	printf("The sum of all the primes below two million is %lld\n", sum);
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