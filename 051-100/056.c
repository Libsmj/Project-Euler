#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    A googol (10^{100}) is a massive number: one followed by one-hundred zeros; 100^{100} is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
    Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?
*/

#define MAX_SIZE 200

int main() {
    int* digits = calloc(MAX_SIZE + 1, sizeof(int));
    int largestIndex = MAX_SIZE;
    int largestSum = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = 1; b < 100; b++) {
            digits[0] = 1;
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < largestIndex; j++) {
                    digits[j] *= a;
                }
                for (int k = 0; k < largestIndex; k++) {
                    digits[k + 1] += digits[k] / 10;
                    digits[k] %= 10;
                }
            }
            int sum = 0;
            for (int i = 0; i < MAX_SIZE; i++) {
                sum += digits[i];
            }
            if (sum > largestSum) {
                largestSum = sum;
            }

            memset(digits, 0, MAX_SIZE * sizeof(int));
        }
        
    }

    printf("%d\n", largestSum);

    free(digits);
    return 0;
}