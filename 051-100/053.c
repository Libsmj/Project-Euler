#include <stdio.h>
#include <stdlib.h>

/*
    There are exactly ten ways of selecting three from five, 12345:
        123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
    In combinatorics, we use the notation, ( 5, 3 ) = 10.
    In general, ( n, r ) = {n!}/{r!(n-r)!}, where r <= n, n! = n * (n-1)* ... * 3 * 2 * 1, and 0! = 1.
    
    It is not until n = 23, that a value exceeds one-million: ( 23, 10 ) = 1144066.
    How many, not necessarily distinct, values of ( n, r ) for 1 <= n <= 100, are greater than one-million?
*/

// https://www.desmos.com/calculator/5mx2yn9riw

/*
    Rearange problem, instead we are looking for n!/(n-r)! > 1,000,000 * r!
    n!/(n-r)! = n * n-1 * ... * (n-r+2)! * (n-r+1)!
    Starting at (100, 4) since I precalculated it is > 1,000,000
*/

int main() {
    int total = 0;

    long currentTarget = 2*3*4*1000000;
    int r = 4;
    for (int n = 100; n > 22; n--) {
        long product = n;
        for (int i = n-1; i > n-r; i--) {
            product *= i;
            if (product > currentTarget) {
                total += n - 2*r + 1;
                break;
            }
        }
        // Retry with next r + 1
        if (product <= currentTarget) {
            currentTarget *= (++r);
            n++;
        }
        if (r > n) {
            break;
        }
    }
    printf("%d\n", total);
    return 0;
}