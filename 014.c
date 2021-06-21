#include <stdio.h>

/*
	The following iterative sequence is defined for the set of positive integers:

		n → n/2 (n is even)
		n → 3n + 1 (n is odd)

	Using the rule above and starting with 13, we generate the following sequence:

				13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
	
	It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

	Which starting number, under one million, produces the longest chain?

	NOTE: Once the chain starts the terms are allowed to go above one million.
*/

int main() {
	printf("Problem 14 - Longest Collatz sequence\n");
	int num = 1000000;
	int longestChain = 0;
	int largestNum = 0;
	while (num > 1) {
		long long chainNum = num;
		int chain = 0;
		while (chainNum != 1 ) {
			chain++;
			if (chainNum % 2 == 0)
				chainNum /= 2;
			else
				chainNum = (3 * chainNum) + 1;
		}
		chain++;
		if (chain > longestChain) {
			longestChain = chain;
			largestNum = num;
		}
		num--;
	}
	printf("The starting number, under one million, that produces the longest chain is %d : %d\n", largestNum, longestChain);
	return 0;
}