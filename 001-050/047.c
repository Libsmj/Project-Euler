#include <stdio.h>
#include <stdlib.h>

/*
    The first two consecutive numbers to have two distinct prime factors are:

        14 = 2 * 7
        15 = 3 * 5

    The first three consecutive numbers to have three distinct prime factors are:

        644 = 2^2 * 7 * 23
        645 = 3 * 5 * 43
        646 = 2 * 17 * 19

    Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
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

void generate_primes(int* primes, int count) {
    int i = 0;
    
    int n = 2;
    while (i < count) {
        if (is_prime(n)) {
            primes[i++] = n;
        }
        n++;
    }
}

// Returns index of largest factor
int n_prime_factors(int number, int* primes, int* factors, int n) {
    int primeIndex = 0;
    int factorIndex = 0;

    while (number > 1) {
        if (number % primes[primeIndex] == 0) {
            // Prime factor found
            // Initialize factor
            factors[factorIndex] = 1;
            // Keep dividing by prime until it no longer divides the number
            while (number % primes[primeIndex] == 0) {
                number /= primes[primeIndex];
                factors[factorIndex] *= primes[primeIndex];
            }
            if (number != 1) {
                factorIndex++;
                // Too many factors found
                if (factorIndex > n) {
                    return 0;
                }
            }
        }
        primeIndex++;
    }

    // Must find exactly n factors
    if (factorIndex != n - 1) {
        return 0;
    }
    return 1;
}

int distinct_prime_factors(int** factors, int n) {
    for (int factorIndex = 0; factorIndex < n; factorIndex++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (factors[i][factorIndex] == factors[j][factorIndex]) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n = 4;

    // Precalculate a set number of primes
    int maxPrimes = 100000;
    int* primes = malloc(maxPrimes * sizeof(int));
    generate_primes(primes, maxPrimes);

    // Store n list of prime factors
    int** factors = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        factors[i] = calloc(n, sizeof(int));
    }

    int consecutiveNumbers = 0;
    int currentNum = 1;
    while (1) {
        if (n_prime_factors(currentNum, primes, factors[currentNum % n], n) == 1) {
            // Keep track of how many consecutive numbers have n prime factors
            consecutiveNumbers++;
        }
        else
        {
            consecutiveNumbers = 0;
        }
        if (consecutiveNumbers >= n) {
            if (distinct_prime_factors(factors, n))
            {
                break;
            }
        }
        currentNum++;
    }
    printf("%d consecutive numbers starting at %d\n", n, currentNum - n + 1);
    for (int i = 0; i < n; i++) {
        free(factors[i]);
    }
    free(factors);
    free(primes);
    return 0;
}