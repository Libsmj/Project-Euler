#include <stdio.h>
#include <stdlib.h>

// Will never finish, need to apply Euler's Theorem
int main() {
    unsigned long start = 1504170715041707;
    unsigned long modulus = 4503599627370517;
    unsigned long smallest = start;

    unsigned long long sum = start;
    unsigned long next = start;

    do {
        next += start;
        if (next > modulus) {
            next -= modulus;
        }
        if (next < smallest) {
            smallest = next;
            sum += next;
            printf("%lld\n", sum);
        }
    } while (next != start);    


    return 0;
}