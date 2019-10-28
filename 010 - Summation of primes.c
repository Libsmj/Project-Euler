// 010 - Summation of primes
// @author Jacob Libsman

#include "stdafx.h"
#include <iostream>
using namespace std;

bool isPrime(int num);

int main() {
	long long sum = 2;
	long long prime = 3;
	while (prime < (long long)2000000) {
		if (isPrime(prime))
			sum += prime;
		prime += 2;
	}
	cout << "The sum of all the primes below two million is " << sum << "\n";
}

// Does not check for 1
bool isPrime(int num) {
	if (num % 2 == 0)
		return false;
	long long testNum = 3;
	long sqr = sqrt(num + 1);
	while (testNum <= sqr) {
		if (num % testNum == 0)
			return false;
		testNum += 2;
	}
	return true;
}