#include <stdio.h>
#include <stdlib.h>
/*
	The Fibonacci sequence is defined by the recurrence relation:

	Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

	What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

// Calculates fib nums with dynamic memory until we find one with 1000 digits

char* add(char*, char*);

int main() {
	printf("Problem 25 - 1000-digit Fibonacci number\n");
	char* fib1 = calloc(1000, sizeof(char));
	char* fib2 = calloc(1000, sizeof(char));
	int i = 2;
	fib1[0] = 1;
	fib2[0] = 1;

	while (!fib2[999]) {
		char* temp = add(fib1, fib2);
		free(fib1);
		fib1 = fib2;
		fib2 = temp;
		i++;
	}
	printf("Index is %d\n", i);
	free(fib1);
	free(fib2);
	return 0;
}

char* add(char* n1, char* n2) {
	char* temp = calloc(1000, sizeof(char));
	for (int i = 0; i < 1000; i++) {
		temp[i] += n1[i] + n2[i];
		if (temp[i] > 9) {
			temp[i + 1] = temp[i] / 10;
			temp[i] = temp[i] % 10; 
		}
	}
	return temp;
}