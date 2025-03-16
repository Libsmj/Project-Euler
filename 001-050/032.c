#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/*
    We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit 
    number, 15234 , is 1 through 5 pandigital.

    The product 7254 is unusual, as the identity, 39 x 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

    Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

    HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
 */

#define DEBUG 0
/**
 * Looks for 1-TARGET pandigital multiplicand/multiplier/product identity
 */
#define TARGET 9

typedef unsigned int Uint;
static inline Uint bit_set(Uint number, Uint n) {
    return number | ((Uint)1 << n);
}
static inline int bit_check(Uint number, Uint n) {
    return (number >> n) & (Uint)1;
}

/**
 * Tests if an array of numbers are Pandigital 1-TARGET.
 * \param count The number of integers being checked
 * \returns 1 if all numbers in the array together are Pandigital 1-TARGET
 */
int is_pandigital(int count, ...);

/**
 * Tests the digits of a given number to see if they have already been used.
 * Does not count 0.
 * \param num The number to check the digits of
 * \param digit_store Sets bits for digits 1-TARGET when found
 * \returns 1 if the number only contains unique digits, 0 if at least 1 digit is not unique or is 0
 */
int digit_check(int num, Uint* digit_store);

/**
 * Adds a number to a total sum if it has not already been added.
 * \param numToAdd The number to attemp to add to the sum
 * \param array List of numbers that have already been added to the sum
 * \param size Size of array
 * \returns 1 if the number was added to the sum, 0 otherwise
 */
int add_num(int numToAdd, int** array, int* size);

int main() {
    if (TARGET < 1 || TARGET > 9) {
        return -1; // Error if checking for anything outside 1-9
    }

    int size = 16;
    int* foundProducts = calloc(size, sizeof(int));

    // Any equation using a multiplicand larger than 5,000 cannot be pandigital 1-9.
    // 1 * 5,000 = 5,000 is not pandigital.
    // 2 * 5,000 = 10,000 has 10 digits in equation, so at least 1 digit must repeat or be 0.
    int maxMultNum = 5000;
    long sum = 0;

    // Loop over all valid multiplicands and multipliers. Multiplicand must be less than multiplier
    for (int multiplicand = 1; multiplicand < maxMultNum; multiplicand++) {
        for (int multiplier = multiplicand + 1; multiplier < maxMultNum; multiplier++) {
            
            int product = multiplicand * multiplier;
            if (is_pandigital(3, multiplicand, multiplier, product) == 1) {

                #if DEBUG
                // Print equations that are pandigital
                printf("%d * %d = %d\n", multiplicand, multiplier, product);
                #endif

                if (add_num(product, &foundProducts, &size) == 1) {
                    sum += product;
                }
            }
        }
    }

    printf("Sum of 1-%d pandigital products is %ld\n", TARGET, sum);
    free(foundProducts);
    return 0;
}

int is_pandigital(int count, ...) {
    // Bit map for digits found in array
    Uint digitMap = 0;

    va_list list;
    va_start(list, count);

    for (int i = 0; i < count; i++) {
        // Get next number
        int num = va_arg(list, int);

        // Check if any digits have already been used and set which digits have been used
        if (digit_check(num, &digitMap) == 0) {
            return 0; // Duplicate digit was found
        }
    }

    va_end(list);

    // Check that all digits 1-TARGET have been found in the array 
    for (int i = 1; i < TARGET + 1; i++) { 
        if (bit_check(digitMap, i) != 1) {
            return 0; // Digit was not found
        }
    }

    return 1; // All digits 1-TARGET used exactly once
}

int digit_check(int num, Uint* digitMap) {
    while (num > 0) {
        // Get right-most digit
        int digit = num % 10;
        if (digit > TARGET) {
            return 0;
        }
        // Don't count 0 as a valid digit
        if (digit == 0) {
            return 0;
        }
        // See if digit has already been used
        if (bit_check(*digitMap, digit)) {
            return 0; // Duplicate digit found
        }
        // Set digit as used
        *digitMap = bit_set(*digitMap, digit);
        // Pop right-most digit
        num /= 10;
    }
    return 1; // No duplicate digit found
}

int add_num(int numToAdd, int** array, int* size) {
    for (int i = 0; i < *size; i++) {
        if ((*array)[i] == 0) {
            (*array)[i] = numToAdd;
            return 1;
        }
        if ((*array)[i] == numToAdd) {
            return 0;
        }
    }

    // Resize array if out of space
    int oldSize = *size;
    *size = 2 * (*size);
    *array = realloc(*array, (*size) * sizeof(int));

    for (int i = oldSize; i < *size; i++) {
        (*array)[i] = 0;
    }
    (*array)[oldSize] = numToAdd;

    return 1;
}

