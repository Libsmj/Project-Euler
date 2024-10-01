#include <stdio.h>
#include <stdlib.h>

/*
    An irrational decimal fraction is created by concatenating the positive integers:

        0.123456789101112131415161718192021...

    It can be seen that the 12th digit of the fractional part is 1.

    If dn represents the nth digit of the fractional part, find the value of the following expression.

    d1 x d10 x d100 x d1000 x d10000 x d100000 x d1000000

*/

void get_digits(int num, int* digits, int* count) {
    *count = 0;
    while (num > 0) {
        digits[(*count)++] = num % 10;
        num /= 10;
    }
}

int main() {
    int product = 1;

    int digits[8];
    int digitCount = 0;

    int currentNum = 1;
    int d = 0;
    while (d <= 1000000) {
        get_digits(currentNum, digits, &digitCount);
        for (int i = digitCount - 1; i >= 0; i--) {
            d++;
            if (d == 1 || d == 10 || d == 100 || d == 1000 || d == 10000 || d == 100000 || d == 1000000) {
                product *= digits[i];
            }
        }
        currentNum++;
    }
    printf("%d\n", product);
    return 0;
}