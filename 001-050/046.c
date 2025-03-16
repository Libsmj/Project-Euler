#include <stdio.h>
#include <stdlib.h>

/*
    It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

         9 =  7 + 2 * 1^2
        15 =  7 + 2 * 2^2
        21 =  3 + 2 * 3^2
        25 =  7 + 2 * 3^2
        27 = 19 + 2 * 2^2
        33 = 31 + 2 * 1^2
    
    It turns out that the conjecture was false.

    What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/

int is_prime(int n) {
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

int satisfies_conjecture(int n, int* primes, int primeCount) {
    // Check primes from largest to smallest
    for (int i = primeCount - 1; i >= 0; i--) {
        // Find a square that satisfies conjecture, if sum is greater than n move on to next prime
        int square = 1;
        while (n > primes[i] + (2*square*square)) {
            square++;
        }
        if (n == primes[i] + 2*square*square) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Largest search value before we end program
    int maxSearch = 1000000;

    int n = 1;
    int* primes = calloc(maxSearch, sizeof(int));
    int primeCount = 0;

    while (n < maxSearch) {
        if (is_prime(n)) {
            primes[primeCount++] = n;
        }
        else if (n > 33) { // Wait till n>33 to build up a few primes
            if (!satisfies_conjecture(n, primes, primeCount)) {
                break;
            }
        }

        n += 2;
    }
    printf("%d\n", n);

    free(primes);
    return 0;
}