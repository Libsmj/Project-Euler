#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    The prime 41, can be written as the sum of six consecutive primes:

        41 = 2 + 3 + 5 + 7 + 11 + 13
        This is the longest sum of consecutive primes that adds to a prime below one-hundred.

    The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

    Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

int isPrime(int);

int main() {
    printf("Problem 50 - Consecutive prime sum\n");
    
    return 0;
}


int isPrime(int n) {
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