#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

    There are thirteen such primes below 100: 2,3,5,7,11,13,17,31,37,71,73,79, and 97.

    How many circular primes are there below one million?
 */

int is_circular_number_prime(int number, int digits, char* primeMap);
int is_prime(int);
char* map_primes();
int tens_map(int);

int main() {
    char* primeMap = map_primes();
    int totalPrimes = 0;

    for (int power = 0; power < 6; power++) {
        for (int i = tens_map(power); i < tens_map(power + 1); i++) {
            if (is_circular_number_prime(i, power, primeMap) == 1) {
                totalPrimes++;
            }
        }
    }

    printf("Total Circular Primes: %d\n", totalPrimes);
    free(primeMap);
    return 0;
}

int is_circular_number_prime(int number, int digits, char* primeMap) {
    int tensPower = tens_map(digits);

    // Test base case
    if (primeMap[number] != 1) {
        return 0;
    }
    for (int i = 0; i < digits; i++) {
        // Rotate number
        int ones = number % 10;
        number /= 10;
        number += ones * tensPower;
        // Check if prime
        if (primeMap[number] != 1) {
            return 0;
        }
    }

    return 1;
}

// Get all the primes before main loop
char* map_primes() {
    char* map = malloc(1000000 * sizeof(char));

    map[0] = 0;
    for (int i = 1; i < 1000000; i++) {
        if (is_prime(i)) {
            map[i] = 1;
        }
    }

    return map;
}

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

// No point implementing power function if we only need 10^[0-6]
int tens_map(int power) {
    switch (power)
    {
    case 0:
        return 1;
    case 1:
        return 10;
    case 2:
        return 100;
    case 3:
        return 1000;
    case 4:
        return 10000;
    case 5:
        return 100000;
    case 6:
        return 1000000;
    default:
        return -1;
    }
}