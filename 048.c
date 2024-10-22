#include <stdio.h>
#include <stdlib.h>

/*
    The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
    Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
 */

#define DIGITS 10000000000

unsigned long long power_ten_digits(int a, int b) {
    unsigned long long power = 1;
    for (int i = 0; i < b; i++) {
        power = (power * a) % DIGITS;
    }
    return (power % DIGITS);
}

int main() {
    unsigned long long sum = 0;
    for (int i = 1; i <= 1000; i++) {
        sum += power_ten_digits(i, i);
        sum %= DIGITS;
    }
    printf("%lld\n", sum);
    return 0;
}