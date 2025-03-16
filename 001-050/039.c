#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p=120.

    {20,48,52}, {24,45,51}, {30,40,50} 

    For which value of p ≤ 1000, is the number of solutions maximised?
*/

int main() {
    int maxCount = 0;
    int maxP = 0;
    for (int p = 12; p <= 1000; p++) {
        int count = 0;
        for (int a = 1; 3*a < p; a++) {
            for (int b = a + 1; a + b < p; b++) {
                double c = sqrt(a*a + b*b);
                if (a + b + c == p) {
                    count++;
                }
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxP = p;
        }
    }
    printf("p = %d\n", maxP);
    return 0;
}