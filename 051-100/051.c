#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TARGET_FAMILY_COUNT 8
#define START 1000
#define MAX 1000000

typedef char bool;

int find_num();
int count_prime_family(char *partialNum, int indexCount, int *indices, int *smallestPrime);
void display_partial_num(char *stringNum, int indexCount, int *indices);
void populate_primes(unsigned int n);

bool *isPrime;
int *primeSet;
int numPrimes;

int main() {
    isPrime = malloc(MAX * sizeof(bool));
    primeSet = malloc(MAX * sizeof(int));
    populate_primes(MAX);

    find_num();

    free(isPrime);
    free(primeSet);
    return 0;
}

int find_num() {
    char stringNum[1024];
    char partialNum[1024];
    int indices[3];

    int indexCount = 3;

    for (int index = 0; index < numPrimes; index++) {
        int currentPrime = primeSet[index];

        sprintf(stringNum, "%d", currentPrime);
        strcpy(partialNum, stringNum);
        int length = strlen(stringNum);

        for (int i = 0; i < length; i++) { // TODO, don't hard code number of '*'
            indices[0] = i;

            for (int j = i + 1; j < length; j++) {
                indices[1] = j;
                
                for (int k = j + 1; k < length; k++) {
                    indices[2] = k;

                    int smallestPrime;
                    int count = count_prime_family(partialNum, indexCount, indices, &smallestPrime);

                    if (count == TARGET_FAMILY_COUNT) {
                        display_partial_num(partialNum, indexCount, indices);
                        printf("%d : %d : %s\n", smallestPrime, count, partialNum);
                        return 1;
                    }

                   partialNum[k] = stringNum[k];
                }

                partialNum[j] = stringNum[j];
            }

            partialNum[i] = stringNum[i];
        }
    }

    return 0;
}

int count_prime_family(char *partialNum, int indexCount, int *indices, int *smallestPrime) {
    int count = 0;
    *smallestPrime = 0;
    // Loop over every digit
    for (int i = 0; i < 10; i++) {
        // Leading 0 will have length miss-match and doesn't count
        if (indices[0] == 0 && i == 0) {
            continue;
        }

        // Update every index in 'indicies to be the same digit
        for (int j = 0; j < indexCount; j++) {
            int index = indices[j];
            partialNum[index] = '0' + i;
        }

        // Test if new number is prime
        int num = strtol(partialNum, NULL, 10);
        if (isPrime[num] == 1) {
            if (*smallestPrime == 0) {
                *smallestPrime = num;
            }
            count++;
        }
    }
    return count;
}

void display_partial_num(char *stringNum, int indexCount, int *indices) {
    for (int i = 0; i < indexCount; i++) {
        int index = indices[i];
        stringNum[index] = '*';
    }
}

void populate_primes(unsigned int maximumPrime) {
	if (maximumPrime < 2) {
        return;
	}
    isPrime[0] = 0; isPrime[1] = 0; isPrime[2] = 1; isPrime[3] = 1;
    primeSet[0] = 2; primeSet[1] = 3;

    numPrimes = 2;
    for (unsigned int num = 4; num < maximumPrime; num++) {

        // Test for divisibility by 2 || 3
        if (num % 2 == 0 || num % 3 == 0) {
            isPrime[num] = 0;
            continue;
        }

        // Test every number of the form 6k+1, 6k+5 to see if it divides the current number, up to √(testPrime)
        unsigned int divisor = 5;
        bool isprime = 1;
        while (divisor * divisor <= num) {
            if (num % divisor == 0 || num % (divisor + 2) == 0) {
                isprime = 0;
                break;
            }
            divisor += 6;
        }
        isPrime[num] = isprime;
        primeSet[numPrimes++] = num;
    }
}