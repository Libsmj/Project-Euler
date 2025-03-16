#include <stdio.h>
#include <stdlib.h>

int is_truncatable_prime(int number, char* primeMap);
char* map_primes();
int is_prime(int n);
int tens_map(int power);

int main() {
    char* primeMap = map_primes();

    int count = 0;
    int sum = 0;
    int i = 11;
    while (count < 11) {
        if (is_truncatable_prime(i+=2, primeMap) == 1) {
            count++;
            sum += i;
        }
    }

    printf("%d\n", sum);
    free(primeMap);
    return 0;
}

int is_truncatable_prime(int number, char* primeMap) {
    if (primeMap[number] != 1) {
        return 0;
    }

    int leftPop = number % 10;
    int rightPop = number / 10;
    int i = 1;
    while (rightPop > 0) {
        if (primeMap[leftPop] != 1) {
            return 0;
        }
        if (primeMap[rightPop] != 1) {
            return 0;
        }
        leftPop += (rightPop % 10) * tens_map(i);
        rightPop /= 10;
        i++;
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