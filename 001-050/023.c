#include <stdio.h>
#include <stdlib.h>

#define largest_abundant_num 28123

/*
	A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. 
	For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

	A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

	As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. 
	By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. 
	However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

	Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

int is_abundant(int n);

int main() {
	printf("Problem 23 - Non-abundant sums\n");
	int sum, i, j, max;
	int* abundant_nums = calloc(largest_abundant_num, sizeof(int));
	int* abundant_sums = calloc(largest_abundant_num*2, sizeof(int));

	// Calculates if i is an abundant number, then stores it in the "list" nums
	for (i = 0, max = 0; i <= largest_abundant_num; i++) {
		if (is_abundant(i)) {
			abundant_nums[max++] = i;
		}
	}

	// Adds all the abundant_nums and sets these sums to 1 in the array abundant_sums
	for (i = 0; i < max; i++) {
		for (j = i; j < max; j++) {
			abundant_sums[abundant_nums[i] + abundant_nums[j]] = 1;
		}
	}

	// Adds all of the non-abundant_sums
	for (i = 0, sum = 0; i <= largest_abundant_num; i++) {
		if (!abundant_sums[i]){
			sum += i;
		}
	}
	
	free(abundant_nums);
	free(abundant_sums);
	printf("%d\n", sum);
	return 0;
}

int is_abundant(int n)
{
     int sum = 0;
     for (int i = 2; i*i <= n; i++)
     {
         if (!(n % i))
         {
            sum += i;
            if (i < n / i)
               sum += n / i;
            if (n <= sum)
               return 1;
         }
     }
     return sum > n;
}