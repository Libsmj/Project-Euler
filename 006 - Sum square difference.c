// 006 - Sum square difference
// @author Jacob Libsman

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	long long sumOfSquares = 0;
	long squaredOfSum = 0;
	for (int i = 0; i < 101; i++) {
		sumOfSquares += (i * i);
		squaredOfSum += i;
	}
	squaredOfSum = squaredOfSum * squaredOfSum;
	cout << "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is " << (squaredOfSum - sumOfSquares) << "\n";
}