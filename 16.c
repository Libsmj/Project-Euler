#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int power = atoi(argv[1]);
	char* digits = calloc(power, sizeof(char));
	int rank = 0;
	digits[0] = 1;
	for (int i = 0; i < power; i++) {
		for (int j = rank; j > -1; j--) {
			digits[j] *= 2;
			if (digits[j] > 9) {
				digits[j + 1] += 1;
				digits[j] -= 10;
			}
		}
		if (digits[rank + 1] != 0)
			rank++;
	}
	int sum = 0;
	for (int i = 0; i < power; i++)
		sum += digits[i];
	printf("%d\n", sum);
	return 0;
}
