#include <stdio.h>
#include <stdlib.h>

/*
    The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
    There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
    What 12-digit number do you form by concatenating the three terms in this sequence?
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

void swap(int* i, int* j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void permute(int index, int* digits, int n, int* array, int* count) {
    if (index == n - 1) {
        // Convert array to integer
        int num = 0;
        for (int k = 0; k < n; k++) {
            num *= 10;
            num += digits[k];
        }
        // Check that num is unique
        for (int i = 0; i < *count; i++) {
            if (num == array[i]) {
                return;
            }
        }
        // Add if prime
        if (is_prime(num)) {
            array[(*count)++] = num;
        }
        return;
    }
    for (int i = index; i < n; i++) {
        swap(digits + index, digits + i);
        permute(index + 1, digits, n, array, count);
        swap(digits + i, digits + index);
    }
}

int compare(const void* a, const void* b) {
    int f = *((int*)a);
    int s = *((int*)b);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

/// @brief Gets all prime permutations of a number
/// @param n The number to get all prime permutations of 
/// @param array Output array of prime permutations sorted from smallest to largest
/// @return The number of elements in array
int get_prime_permutations(int n, int* array) {
    int digits[4];
    for (int i = 4-1; i >= 0; i--) {
        digits[i] = n % 10;
        n /= 10;
    }
    int count = 0;
    permute(0, digits, 4, array, &count);
    qsort(array, count, sizeof(int), compare);
    return count;
}

int main() {
    int* array = malloc(24 * sizeof(int));

    for (int n = 1000; n < 10000; n++) {
        if (is_prime(n)) {
            int count = get_prime_permutations(n, array);
            
            for (int i = 0; i < count; i++) {
                int difference = array[i] - n;
                if (difference <= 0) {
                    continue;
                }
                // Next number to look for in array
                int nextNum = array[i] + difference;
                // Look to see if next num is a prime permutation
                for (int j = i + 1; j < count; j++) {
                    if (array[j] == nextNum) {
                        printf("%d : %d : %d\n", n, array[i], array[j]);
                    }
                }
            }
        }
    }

    free(array);
    return 0;
}