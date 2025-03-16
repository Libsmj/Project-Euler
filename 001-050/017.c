#include <stdio.h>
#include <stdlib.h>

/*
	If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

	If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


	NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
	The use of "and" when writing out numbers is in compliance with British usage.
*/

// Creates a mapping of integers to the number of letters in their word
// 1-19 and 20,30...90 are entered manually and the rest are calculated dynamically
void num_to_word(int* map) {
	map[1] = 3;
	map[2] = 3;
	map[3] = 5;
	map[4] = 4;
	map[5] = 4;
	map[6] = 3;
	map[7] = 5;
	map[8] = 5;
	map[9] = 4;
	map[10] = 3;
	map[11] = 6;
	map[12] = 6;
	map[13] = 8;
	map[14] = 8;
	map[15] = 7;
	map[16] = 7;
	map[17] = 9;
	map[18] = 8;
	map[19] = 8;

	map[20] = 6;
	map[30] = 6;
	map[40] = 5;
	map[50] = 5;
	map[60] = 5;
	map[70] = 7;
	map[80] = 6;
	map[90] = 6;
	for (int i = 20; i < 100; i+=10) {
		for (int j = 1; j < 10; j++) {
			map[i + j] = map[i] + map[j];
		}
	}

	for (int i = 100; i < 1000; i+=100) {
		map[i] = map[i/100] + 7;
		for (int j = 1; j < 100; j++) {
			map[i + j] = map[i] + 3 + map[j];
		}
	}
	map[1000] = map[1] + 8;
}

int main(int argc, char** argv) {
	printf("Problem 17 - Number letter counts\n");
	int num = 1000;
	int* map = calloc(num + 1, sizeof(int));
	int sum = 0;

	num_to_word(map);

	for (int i = 1; i < 1001; i++) {
#ifdef debug
		printf("%d: %d\n", i, map[i]);
#endif
		sum += map[i];
	}
	printf("%d\n", sum);

	free(map);
	return 0;
}
