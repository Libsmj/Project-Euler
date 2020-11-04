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

int recurringCycle(int* a, int n);

int main() {
    printf("Problem 26 - Reciprocal cycles\n");
    int longestCycle = 0;
    int D = 0;

    int* quotient = malloc(1000 * sizeof(int));
    for (int d = 2; d < 1000; d++) {
        int n = 0;
        int r = 0;

        int numerator = pow(10, (int)log10(d) + 1);
        printf("1/%3d : 0.", d);
        do {
            quotient[n] = numerator / d;

            printf("%d", quotient[n]);
            numerator = (numerator % d) * 10;

            n++;
            r = recurringCycle(quotient, n);
        } while (r == 0 && numerator != 0);

        printf("\n");
        if (n / 2 > longestCycle) {
            longestCycle = n / 2;
            D = d;
        }
    }
    free(quotient);
    printf("The value of d is %d with cycle %d\n", D, longestCycle);
    return 0;
}

int recurringCycle(int* a, int n) {
    // printf("0.");
    // for (int i = 0; i < n; i++) {
    //     printf("%d", a[i]);
    // }
    // printf("\n");
    for (int i = 0; i < n - 1; i++) {
        //printf("%d\n", i);
        if ((n - i) % 2) {
            continue;
        }

        int cycle = 1;
        for (int j = i; j < ((n + i) / 2); j++) {
            //printf("\t%d - %d\n", j, j + ((n - i) / 2));
            if (a[j] != a[j + ((n - i) / 2)]) {
                cycle = 0;
                break;
            }
        }
        if (cycle) {
            
            return (n - i) / 2;
        }
        //printf("-\n");
    }
    return 0;
}