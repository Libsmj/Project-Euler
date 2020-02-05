// 001 - Multiples of 3 and 5
// @author Jacob Libsman

#include <stdio.h>

int main() {
	int count = 0;
	int num = 3;
	while (num < 1000) {
		count += num;
		num += 3;
	}
	num = 5;
	while (num < 1000) {
		if (num % 3 != 0)
			count += num;
		num += 5;
	}
	printf("Num of multiples of 3 and 5 between 0 and 1000 - %d\n", count);
	return 0;
}
