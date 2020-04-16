#include <stdio.h>
#include <stdlib.h>

/*
    A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

    Find the largest palindrome made from the product of two 3-digit numbers.
*/

int palandrome(int);
int power(int, int);

int main() {
    printf("Problem 4 - Largest palindrome product\n");
    int digits = 3;
    int upper = power(10, digits) - 1;
    int lower = power(10, digits - 1) - 1;
    int largestProduct = 0;
    int i, j;
    
    for (i = upper; i > lower; i--) {
        for (j = upper; j > lower; j--) {
            if (i * j < largestProduct) {
                break;
            }
            if (palandrome(i * j)) {
                largestProduct = i * j;
            }
        }
        if (i * upper < largestProduct) {
            break;
        }
    }

    printf("%d\n", largestProduct);
    return 0;
}

// Returns if x is a palindromic number
int palandrome(int x) {
    char* num = calloc(10, sizeof(char));
    int size = sprintf(num, "%d", x);
    for (int i = 0; i < size / 2; i++) {
        if (num[i] != num[size - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Returns x^y
int power(int x, int y) {
    if (!y) {
        return 1;
    }
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}