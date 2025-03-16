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

/// @brief Gets the first n primes
/// @param n The largest number to check if prime
/// @param count Number of primes found
/// @return Pointer to list of primes
int* generate_primes(int n, int* count) {
	if (n < 2) { 
		*count = 0;
		return malloc(1);
	}
	// Get approximate number of primes < n
	int arrayMaxCount = n / log(n);
	int* primes = malloc(arrayMaxCount * sizeof(int));
	primes[0] = 2;

	int i = 1;
	for (int currentNum = 3; currentNum <= n; currentNum += 2) {
		// Double array size if too large
		if (i >= arrayMaxCount) {
			printf("%d\n", i);
			arrayMaxCount *= 2;
			primes = realloc(primes, arrayMaxCount * sizeof(int));
		}

		if (is_prime(currentNum)) {
			primes[i++] = currentNum;
		}
	}
	*count = i;
	return primes;
}

/// @brief Tests if the sum of primes if also prime
/// @param primes Array of primes
/// @param count Number of primes to check
/// @return The sum if it is prime, 0 otherwise
int prime_sum(int* primes, int count) {
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += primes[i];
	}
	if (is_prime(sum)) {
		return sum;
	}
	return 0;
}

int main() {
	int count = 0;
    int* primes = generate_primes(1000000, &count);

	int target = 1000000;

	// Not sure what the bound should be
	for (int i = 6; i < 1000; i++) {
		int largestSum = 0;

		// Split off even cases since the sequence must start at 2
		if (i % 2 == 0) {
			largestSum = prime_sum(primes, i);
			if (largestSum > target) {
				largestSum = 0;
			}
		}
		else {
			for (int j = 1; j < count - i; j++) {
				int sum = prime_sum(primes + j, i);
				if (sum > target) {
					break;
				}
				if (sum > largestSum) {
					largestSum = sum;
				}
			}

		}

		if (largestSum != 0) {
			printf("%d : %d\n", i, largestSum);
		}
	}

	free(primes);
    return 0;
}
