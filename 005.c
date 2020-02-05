// 005 - Smallest multiple
// @author Jacob Libsman

#include <stdio.h>

int main() {
	int smallest = 2;
	while (1) {
		int i = 10;
		while (i < 20 && smallest % i == 0) {
			i += 1;
		}
		if (i == 20) {
			printf("The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is %d\n", smallest);
			return 0;
		}
		smallest += 2;
	}
	return 0;
}