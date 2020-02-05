// 012 - Highly divisible triangular number
// @author Jacob Libsman

#include <stdio.h>
#include <math.h> // Compile with -lm

int main() {
	long long num = 0;
	int numOfDiv = 0;
	for (int i = 1; numOfDiv <= 500; i++) {
		num += i;
		numOfDiv = 0;
		int sqr = sqrt(num);
		for (long long j = 1; j <= sqr; j++) {
			if (num % j == 0) {
				numOfDiv += 2;
			}
		}
		if (sqr*sqr == num) {
			numOfDiv--;
		}
		//printf("%lld : %d\n", num, numOfDiv);
	}
	printf("The value of the first triangle number to have over five hundred divisors is %lld\n", num);
}