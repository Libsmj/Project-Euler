// 007 - 10001st prime
// @author Jacob Libsman

#include <stdio.h>
#include <math.h> // Compile with -lm

_Bool isPrime(int num);

int main() {
	int numOfPrime = 2;
	int prime = 3;
	int targetPrimeNum = 10001;
	while (numOfPrime < targetPrimeNum) {
		if (isPrime(prime + 1))
			numOfPrime++;
		prime++;
	}
	printf("The 10001st prime number is %d\n", prime);
	return 0;
}

// Does not check for 1
_Bool isPrime(int num) {
	if (num % 2 == 0)
		return 0;
	long long testNum = 3;
	long sqr = sqrt(num + 1);
	while (testNum <= sqr) {
		if (num % testNum == 0)
			return 0;
		testNum += 2;
	}
	return 1;
}