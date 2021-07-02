#include <stdio.h>
#include <stdlib.h>

/*
    Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

        1634 = 1^4 + 6^4 + 3^4 + 4^4
        8208 = 8^4 + 2^4 + 0^4 + 8^4
        9474 = 9^4 + 4^4 + 7^4 + 4^4

    As 1 = 1^4 is not a sum it is not included.

    The sum of these numbers is 1634 + 8208 + 9474 = 19316.

    Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

// Only need to check for numbers less than 7 digits.
// 9^5 = 59049, (9^5) * 7 = 413,343 < 1,000,000; therefore an x digit number where x>6 will 5th power sum to an y<x digit number 

int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    int result = x;
    for(; y > 1; y--) {
        result *= x;
    }
    return result;
}

int sumOfFifthPowers(int x) {
    char* temp = calloc(11, sizeof(char));
    int n = sprintf(temp, "%d", x);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += power(temp[i] - '0', 5);
    }
    free(temp);
    return sum;
}

int main() {
    printf("Problem 30 - Digit fifth powers\n");
    int sum = 0;
    for (int number = 2; number < 6*power(9,5); number++) {
        if (number == sumOfFifthPowers(number)) {
            sum += number;
        }
    }

    printf("The sum of all the numbers that can be written as the sum of fifth powers of their digits is %d\n", sum);
    return 0;
}
