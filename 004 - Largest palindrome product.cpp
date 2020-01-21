// 004 - Largest palindrome product
// @author Jacob Libsman

#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(int num);

int main() {
	int largest = 0;
	for (int i = 999; i > 99; i--) {
		for (int j = i; j > 99; j--) {
			if (checkPalindrome(i * j) && i * j > largest)
				largest = i * j;
		}
	}
	printf("The largest palindrome made from the product of two 3-digit numbers is %d\n", largest);
}

bool checkPalindrome(int num) {
	string forward = to_string(num);
	string backward;
	for (int i = forward.size() - 1; i > -1 ; i--)
		backward += forward.at(i);
	return forward._Equal(backward);
}
