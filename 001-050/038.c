#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Take the number 192 and multiply it by each of 1, 2, and 3:

        192 x 1 = 192
        192 x 2 = 384
        192 x 3 = 576

    By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3).

    The same can be achieved by starting with 9 and multiplying by 1,2,3,4, and 5, giving the pandigital, 918273645, 
    which is the concatenated product of 9 and (1,2,3,4,5).

    What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2,...,n) where n>1?
 */

typedef unsigned int Uint;
static inline Uint bit_set(Uint number, Uint n) {
    return number | ((Uint)1 << n);
}
static inline int bit_check(Uint number, Uint n) {
    return (number >> n) & (Uint)1;
}

int digit_check(int num, Uint* digitMap, int* pandigitalNumber) {
    int digits[9];
    int count = 0;
    while (num > 0) {
        // Get right-most digit
        int digit = num % 10;
        if (digit > 9) {
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
        digits[count++] = digit;
    }

    // Update pandigital number
    for (int i = count - 1; i >= 0; i--) {
        *pandigitalNumber *= 10;
        *pandigitalNumber += digits[i];
    }
    return 1; // No duplicate digit found
}

int is_pandigital(int count, int* numbers) {
    // Bit map for digits found in array
    Uint digitMap = 0;

    int pandigitalNumber = 0;

    for (int i = 0; i < count; i++) {
        // Get next number
        int num = numbers[i];

        // Check if any digits have already been used and set which digits have been used
        if (digit_check(num, &digitMap, &pandigitalNumber) == 0) {
            return 0; // Duplicate digit was found
        }
    }

    // Check that all digits 1-TARGET have been found in the array 
    for (int i = 1; i <= 9; i++) { 
        if (bit_check(digitMap, i) != 1) {
            return 0; // Digit was not found
        }
    }

    return pandigitalNumber; // All digits 1-TARGET used exactly once
}

int* multiply_list(int n, int multiplier) {
    int* list = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        list[i] = (i+1) * multiplier;
    }
    return list;
}

int main() {
    int largestPandigital = 0;
    for (int n = 2; n < 10; n++) {
        for (int multiplier = 1; log10(multiplier) <= 9 / n; multiplier++) {
            int* list = multiply_list(n, multiplier);

            int pandigital = is_pandigital(n, list);
            if (pandigital > largestPandigital) {
                largestPandigital = pandigital;
            }
            free(list);
        }
    }
    printf("%d\n", largestPandigital);
    return 0;
}