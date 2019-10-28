// 013 - Large sum
// @author Jacob Libsman

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <fstream>
using namespace std;

int main() {
	string nums[100];
	stack<int> digits;
	int sum = 0;

	ifstream inFile;
	inFile.open("..\\013 - Data.txt");
	for (int i = 0; i < 100; i++)
		inFile >> nums[i];
	for (int i = 49; i > -1; i--) {
		for (int j = 0; j < 100; j++)
			sum += nums[j].at(i) - '0';
		digits.push(sum % 10);
		sum = sum / 10;
	}
	while (sum != 0) {
		digits.push(sum % 10);
		sum /= 10;
	}
	cout << "The first ten digits of the sum of the one-hundred 50-digit numbers are ";
	for (int i = 0; i < 10; i++) {
		cout << digits.top();
		digits.pop();
	}
	cout << "\n";
}