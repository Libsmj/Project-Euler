#include <stdio.h>
#include <stdlib.h>

/*
    The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^{6972593} - 1; it contains exactly 2,098,960 digits. 
    Subsequently other Mersenne primes, of the form 2^p - 1, have been found which contain more digits.
    However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433 * 2^{7830457} + 1.
    Find the last ten digits of this prime number.
*/

#define EXPONENT 7830457

int main() {
    unsigned long result = 1;
    for (int i = 1; i <= EXPONENT; i++) {
        result *= 2;
        result %= 10000000000;
    }
    result = (28433 * result) + 1;
    result %= 10000000000;

    printf("%ld\n", result);
    return 0;
}