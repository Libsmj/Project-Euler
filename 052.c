#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
    Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
 */

void get_digits(long, int*);
int same_digits(long, int*);

int main() {
    int* digits = malloc(10 * sizeof(int));

    long i = 125874;
    while (i < __LONG_MAX__) {
        if (same_digits(i, digits) == 1) {
            printf("%ld\n", i);
            break;
        }
        i++;
    }

    free(digits);
    return 0;
}

int same_digits(long num, int* digits) {
    get_digits(num, digits);
    for (int i = 2; i <= 6; i++) {
        long currentNum = num * i;
        while (currentNum > 0) {
            int digit = currentNum % 10;
            if (digits[digit] == 0) {
                return 0;
            }
            currentNum /= 10;
        }
    }
    return 1;
}

void get_digits(long num, int* digits) {
    memset(digits, 0, 10 * sizeof(int));
    
    while (num > 0) {
        digits[num % 10] = 1;
        num /= 10;
    }
}