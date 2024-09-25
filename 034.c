#include <stdio.h>
#include <stdlib.h>

/*
    145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

    Find the sum of all numbers which are equal to the sum of the factorial of their digits.

    Note: As 1!=1 and 2!=2 are not sums they are not included.
 */

int digit_factorial_sum(int number);
int factorial_digit_map(int number);

int main() {
    int sum = 0;
    for (int i = 3; i < factorial_digit_map(9); i++) {
        if (i == digit_factorial_sum(i)) {
            printf("%d\n", i);
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}


int digit_factorial_sum(int number) {
    int sum = 0;
    while (number > 0) {
        sum += factorial_digit_map(number % 10);
        number /= 10;
    }
    
    return sum;
}

int factorial_digit_map(int number) {
    switch (number)
    {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 6;
    case 4:
        return 24;
    case 5:
        return 120;
    case 6:
        return 720;
    case 7:
        return 5040;
    case 8:
        return 40320;
    case 9:
        return 362880;
    default:
        return -1;
    }
}
