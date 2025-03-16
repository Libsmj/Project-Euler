#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1
    Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

    Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

int recurringCycle(int d);

int main() {
    printf("Problem 26 - Reciprocal cycles\n");
    int longestCycle = 0;
    int d = 1;

    for (int D = 2; D < 1000; D++) {
        int cycle = recurringCycle(D);

        if (cycle > longestCycle) {
            longestCycle = cycle;
            d = D;
        }
    }

    printf("The value of d is %d with cycle %d\n", d, longestCycle);
    return 0;
}

// Record all the remainders from long division, once a remainder is 0 or repeats a number, we've found the cycle
// If we are dividing by x there are x-1 possible remainders.
int recurringCycle(int divisor) {
    int quotient = 0;
    int remainder = 0;
    int numerator = pow(10, (int)log10(divisor) + 1);
    
    int* remainders = calloc(divisor, sizeof(int));
    int n = 0;
    // printf("%d : ", divisor);
    while (1) {
        quotient = numerator / divisor;
        remainder = numerator - divisor * quotient;
        numerator = remainder * 10;
        // printf("%d", quotient);

        if (remainders[remainder]) {
            break;
        }
        remainders[remainder] = 1;
        n++;
    }
    // printf("\n");

    free(remainders);
    return n;
}