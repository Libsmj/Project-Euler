// 009 - Special Pythagorean triplet
// @author Jacob Libsman

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int a = 3;
	int b = 4;
	double c = 5;
	int target = 1000;
	for (a = 3; a < target; a++) {
		for (b = a + 1; b < target; b++) {
			c = sqrt(a * a + b * b);
			if (a + b + c == target)
				break;
		}
		c = sqrt(a * a + b * b);
		if (a + b + c == target)
			break;
	}
	if (c < target){
		cout << "The product abc is " << (long)(a * b * c) << "\n";
		cout << "a is " << a << "\n";
		cout << "b is " << b << "\n";
		cout << "c is " << c << "\n";
	}
	else
		cout << "No combination of natural numbers found\n";
}