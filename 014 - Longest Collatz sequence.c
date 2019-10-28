// 014 - Longest Collatz sequence
// @author Jacob Libsman

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
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
	cout << "The starting number, under one million, that produces the longest chain is " << largestNum << " : " << longestChain << "\n";
}