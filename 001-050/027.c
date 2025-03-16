#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Euler discovered the remarkable quadratic formula:

        n²+n+41

    It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39. However, when n=40, 40²+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41, 41²+41+41 is clearly divisible by 41.

    The incredible formula n²-47n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79. The product of the coefficients, −79 and 1601, is −126479.

    Considering quadratics of the form:

        n²+an+b, where |a|<1000 and |b|≤1000

        where |n| is the modulus/absolute value of n
        e.g. |11|=11 and |-4|=4 

    Find the product of the coefficients,  and , for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.
*/

// n²+an+b is clearly divisible by b, so only need to test for 0≤n≤b

// Only need to check b odd or 2, 0²+0+b is divisible by 2 if b is even.

int f(int n, int a, int b);

int isPrime(int n);

int main() {
    printf("Problem 27 - Quadratic primes\n");

    int largest_a = 0;
    int largest_b = 0;
    int largest_n = 0;

    for (int a = -999; a <= 999; a++) {
        for (int b = -999; b <= 999; b+=2) {
            int n = 0;
            while ( n < b && isPrime(f(n++,a,b)) );
            n-=2;
            if (n > largest_n) {
                largest_a = a;
                largest_b = b;
                largest_n = n;
            }
        }
    }

    printf("n+(%d)n+(%d) gives primes up to n=%d, their product is %d\n", largest_a, largest_b, largest_n, largest_a * largest_b);
    return 0;
}

int f(int n, int a, int b) {
    return n * (n+a) + b;
}

int isPrime(int n) {
	if (n < 4) {
		return n > 1;
	}
	if (!(n % 2) || !(n % 3)) {
		return 0;
	}
	long long i = 5;
	while (i * i < n + 1) {
		if (!(n % i) || !(n % (i + 2))) {
			return 0;
		}
		i += 6;
	}
	return 1;
}