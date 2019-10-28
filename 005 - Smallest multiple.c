// 005 - Smallest multiple
// @author Jacob Libsman

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	int smallest = 2;
	while (true) {
		int i = 10;
		while (i < 20 && smallest % i == 0) {
			i += 1;
		}
		if (i == 20) {
			cout << "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is " << smallest << "\n";
			return 0;
		}
		smallest += 2;
	}
}