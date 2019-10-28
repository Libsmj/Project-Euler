// 007 - 10001st prime
// @author Jacob Libsman

#include "stdafx.h"
#include <iostream>
using namespace std;

bool isPrime(int num);

int main() {
	int numOfPrime = 2;
	int prime = 3;
	int targetPrimeNum = 10001;
	while (numOfPrime < targetPrimeNum) {
		if (isPrime(prime + 1))
			numOfPrime++;
		prime++;
	}
	cout << "The 10001st prime number is " << prime << "\n";
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