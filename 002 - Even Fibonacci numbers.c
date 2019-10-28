// 002 - Even Fibonacci numbers
// @author Jacob Libsman

#include <stdio.h>

int main() {
	int num0 = 1;
	int num1 = 1;
	int temp = 0;
	int sum = 0;
	while (num1 < 4000000) {
		temp = num1;
		num1 += num0;
		num0 = temp;
		if (num1 % 2 == 0)
			sum += num1;
	}

	printf("The sum of all the terms in the Fibonacci sequence whose values do not exceed four million is %d\n", sum);
}
