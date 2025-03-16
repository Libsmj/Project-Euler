#include <stdio.h>
#include <stdlib.h>

/*
    We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. 
    For example, 2143 is a 4-digit pandigital and is also prime.

    What is the largest n-digit pandigital prime that exists?
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

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

// Going through all numbers and testing if they are pandigital takes too long, faster to generate all permutations of 1-n and test if they are prime
void permute(int index, int* digits, int n, int* largest) {
    if (index == n - 1) {
        int num = 0;
        for (int k = 0; k < n; k++) {
            num *= 10;
            num += digits[k];
        }
        if (num > *largest && is_prime(num)) {
            *largest = num;
        }
        return;
    }
    for (int i = index; i < n; i++) {
        swap(digits + index, digits + i);
        permute(index+1, digits, n, largest);
        swap(digits + i, digits + index);
    }
}

int main() {
    int largestPandigitalPrime = 0;
    for (int n = 1; n <= 9; n++) {
        int digits[n];
        for (int i = 0; i < n; i++) {
            digits[i] = i + 1;
        }
        permute(0, digits, n, &largestPandigitalPrime);
    }
    printf("%d\n", largestPandigitalPrime);
    return 0;
}