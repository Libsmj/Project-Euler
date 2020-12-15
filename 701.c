#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Consider a rectangle made up of W x H square cells each with area 1.
    Each cell is independently coloured black with probability 0.5 otherwise white. Black cells sharing an edge are assumed to be connected.
    Consider the maximum area of connected cells.

    Define E(W,H) to be the expected value of this maximum area. For example, E(2,2) = 1.875.

    You are also given E(4,4) = 5.76487732, rounded to 8 decimal places.

    Find E(7,7), rounded to 8 decimal places.
*/

int main() {
    printf("Problem 701 - Random connected area\n");
    long temp = pow(2,7*7);
    printf("%lu\n", temp);
    return 0;
}