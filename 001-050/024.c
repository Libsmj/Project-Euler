#include <stdio.h>
#include <stdlib.h>

/*
	A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

	012   021   102   120   201   210

	What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

int* getFactoradic(int* perm) {
	int* fact = malloc(sizeof(int));
	int n = *perm;
	int i = 1;
	while (n != 0) {
		fact = realloc(fact, i * sizeof(int));
		fact[i - 1] = n % i;
		n /= i++;
	}
	i--;
	int* reverse = malloc(i * sizeof(int));
	for (int j = 0; j < i; j++) {
		reverse[j] = fact[i - j - 1];
	}
	*perm = i;
	free(fact);
	return reverse;
}

int main() {
	printf("Problem 24 - Lexicographic permutations\n");
	
	int size = 10;
	int perm = 1000000 - 1;
	int* factoradic = getFactoradic(&perm);
	
	int* digits = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		digits[i] = i;
	}
	for (int i = 0; i < size; i++) {
		printf("%d", digits[factoradic[i]]);
		for (int j = factoradic[i]; j < size - 1; j++) {
			digits[j] = digits[j + 1];
		}
	}
	printf("\n");
	
	free(factoradic);
	free(digits);
	return 0;
}