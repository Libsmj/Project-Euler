#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int continued_fraction(int D);
int is_fraction_palindrome(int* array, int length);
int is_square(unsigned int n);

int main() {
    // 139 is giving the incorrect sequence, length 18 should give last number 22, but gives 12. Precision error?
    // Precision error, need to use a different algorithm
    for (int i = 139; i <= 139; i++) {
        if (!is_square(i)) {
            continued_fraction(i);
        }
    }
    return 0;
}

int continued_fraction(int D) {
    int array[1024];
    int length = 1;
    
    long double a_last = sqrt(D);
    array[0] = (int)a_last;

    printf("%Lf ", a_last);

    int stop = 0;
    while (!is_fraction_palindrome(array, length) && stop < 18) {
        a_last = 1.0 / (a_last - ((long double) array[length - 1]));
        array[length++] = a_last;
        if (is_fraction_palindrome(array, length)) {
            printf("%d\n", array[length - 1]);
            return length - 1;
        }
        stop++;
        printf("%Lf ", a_last);
    }
    printf("\n");
    return 0;
}

/// @brief Determines if a periodic array is of the form [a0;a1,a2,a3,...,a3,a2,a1,2*a0,a1,...]
/// @param array The terms of the sequence to test
/// @param length The size of array
/// @returns 1 if the array represents a periodic continued fraction
int is_fraction_palindrome(int* array, int length) {
    if (2*array[0] != array[length-1]) {
        return 0;
    }
    for (int i = 1; i < length - 1; i++) {
        if (array[i] != array[length-1-i]) {
            return 0;
        }
    }
    return 1;
}

/// @brief Determines if a number is a square number (sqrt(n) is an integer)
/// @param n The number to test
/// @return 1 if n is square
int is_square(unsigned int n) {
    unsigned int squareRoot = sqrt(n);
    return squareRoot * squareRoot == n;
}