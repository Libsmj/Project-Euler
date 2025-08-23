#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Consider quadratic Diophantine equations of the form:
    x² - Dy² = 1
    For example, when D=13, the minimal solution in x is 649² - 13 * 180² = 1.
    It can be assumed that there are no solutions in positive integers when D is square.
    By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:
    
        3² - 2 * 2² = 1
        2² - 3 * 1² = 1
        9² - 5 * 4² = 1
        5² - 6 * 2² = 1
        8² - 7 * 3² = 1
        
    Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.
    Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.
 */

// Longest continued fraction sequence to test for
#define STOP 1000

/// @brief Represents the fraction (a*√[D] + b) / c
struct fraction {
    int a;
    int b;
    int c;
};

int is_square(unsigned int n);
long double minimal_pell_solution(int D);
int is_fraction_palindrome(int* array, int length);
struct fraction get_next_fraction(struct fraction a_last, int f, int D);
int gcd3(int a, int b, int c);
int gcd2(int a, int b);
long double calculate_x_solution(int *sequence, int length);

/// @brief Converts a fraction to its decimal value
/// @param n the fraction to divide
/// @param D the current value of D
/// @return A decimal approximation of the fraction
static inline long double fraction_to_decimal(struct fraction n, int D) {
    return (n.a * sqrt(D) + n.b) / n.c;
}

int main() {
    long double largest_solution = 0;
    int largest_D = 0;
    for (int i = 1; i <= 1000; i++) {
        if (!is_square(i)) {
            long double minimal_solution = minimal_pell_solution(i);
            if (minimal_solution > largest_solution) {
                largest_solution = minimal_solution;
                largest_D = i;
            }
        }
    }
    printf("D = %d : x ≈ %0.Lf\n", largest_D, largest_solution);
    return 0;
}

/// @brief Determines if a number is a square number (√[n] is an integer)
/// @param n The number to test
/// @return 1 if n is square
int is_square(unsigned int n) {
    unsigned int squareRoot = sqrt(n);
    return squareRoot * squareRoot == n;
}

/// @brief Calculates the minimum integer solution x (approximate) for the equation x²-Dy²=1
/// @param D the value of D in the equation
/// @return The minimum value of x that satisfies the equation. The value of x is approximate since the problem only needs relative solutions.
long double minimal_pell_solution(int D) {
    int sequence[1024];
    int length = 1;
    
    struct fraction a_last;
    a_last.a = 1;
    a_last.b = 0;
    a_last.c = 1;

    sequence[0] = fraction_to_decimal(a_last, D);
    
    int stop = 0;
    while (!is_fraction_palindrome(sequence, length) && stop < STOP) {
        a_last = get_next_fraction(a_last, sequence[length - 1], D);
        sequence[length++] = fraction_to_decimal(a_last, D);

        if (is_fraction_palindrome(sequence, length)) {
            return calculate_x_solution(sequence, length);
        }
        stop++;
        if (stop == STOP) {
            // Did not find solution, consider increasing stop
            printf("%d\n", D);
        }
    }
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

/// @brief Gets the next fractional number in the periodic array
/// @param a_last The last fractional number in the sequence
/// @param f The floor of the last number
/// @param D The constant D
/// @return The next fraction in the sequence
struct fraction get_next_fraction(struct fraction a_last, int f, int D) {
    struct fraction a_next;
    
    int p = a_last.b - (a_last.c * f);

    int a = a_last.a * a_last.c;
    int b = -1 * a_last.c * p;
    int c = (a_last.a*a_last.a*D) - (p*p);
    
    int gcd = gcd3(a, b, c);
    a_next.a = a / gcd;
    a_next.b = b / gcd;
    a_next.c = c / gcd;

    return a_next;
}

int gcd3(int a, int b, int c) {
    return gcd2(a, gcd2(b,c));
}

int gcd2(int a, int b) {
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a; 
}

/// @brief Calculates the numerator for the continued fraction defined by 'sequence' that solves Pell's equation
long double calculate_x_solution(int *sequence, int length) {
    long double x = 0;
    long double y = 1;
    long double temp = 0;
    switch (length % 2) {
        case 1: // Even sequence length
            for (int i = length - 2; i >= 0; i--) {
                temp = sequence[i] * y + x;
                x = y;
                y = temp;
            }
            return y;
        case 0: // Odd sequence length
            for (int i = length - 2; i >= 1; i--) {
                temp = sequence[i] * y + x;
                x = y;
                y = temp;
            }
            for (int i = length - 1; i >= 0; i--) {
                temp = sequence[i] * y + x;
                x = y;
                y = temp;
            }
            return y;
    }
    return 0;
}
