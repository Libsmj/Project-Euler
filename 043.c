#include <stdio.h>
#include <stdlib.h>

/*
    The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

    Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

        d2d3d4 = 406 is divisible by 2
        d3d4d5 = 063 is divisible by 3
        d4d5d6 = 635 is divisible by 5
        d5d6d7 = 572 is divisible by 7
        d6d7d8 = 572 is divisible by 11
        d7d8d9 = 728 is divisible by 13
        d8d9d10 = 289 is divisible by 17
    
    Find the sum of all 0 to 9 pandigital numbers with this property.
*/

int fib(int n) {
    switch (n)
    {
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 5;
    case 4:
        return 7;
    case 5:
        return 11;
    case 6:
        return 13;
    case 7:
        return 17;
    default:
        return -1;
    }
}

int digits_fib(int* d) {
    for (int i = 1; i < 8; i++) {
        if ((d[i] * 100 + d[i+1] * 10 + d[i+2]) % fib(i) != 0) {
            return 0;
        }
    }
    return 1;
}

void swap(int* i, int* j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void permute(int index, int* digits, int n, long long* sum) {
    if (index == n - 1) {
        if (digits_fib(digits)) {
            long num = 0;
            for (int k = 0; k < n; k++) {
                num *= 10;
                num += digits[k];
            }
            *sum += num;
        }
        return;
    }
    for (int i = index; i < n; i++) {
        swap(digits + index, digits + i);
        permute(index + 1, digits, n, sum);
        swap(digits + i, digits + index);
    }
}

int main() {
    long long sum = 0;

    int digits[10];
    for (int i = 0; i < 10; i++) {
        digits[i] = i;
    }
    
    permute(0, digits, 10, &sum);
    printf("%lld\n", sum);
    return 0;
}