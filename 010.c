// 010 - Summation of primes
// @author Jacob Libsman

#include <stdio.h>
#include <math.h> // Compile with -lm

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

// Does not check for 1
_Bool isPrime(int num) {
	if (num % 2 == 0)
		return 0;
	long long testNum = 3;
	long sqr = sqrt(num + 1);
	while (testNum <= sqr) {
		if (num % testNum == 0) {
			return 0;
		}
		testNum += 2;
	}
	return 1;
}