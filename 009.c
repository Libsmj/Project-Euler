// 009 - Special Pythagorean triplet
// @author Jacob Libsman

#include <stdio.h>
#include <math.h> // Compile with -lm

int main() {
	int a = 3;
	int b = 4;
	double c = 5;
	int target = 1000;
	for (a = 3; a < target; a++) {
		for (b = a + 1; b < target; b++) {
			c = sqrt(a * a + b * b);
			if (a + b + c == target) {
				break;
			}
		}
		c = sqrt(a * a + b * b);
		if (a + b + c == target) {
			break;
		}
	}
	if (c < target){
		printf("The product abc is %ld\n", (long)(a * b * c));
		printf("a is %d\n", a);
		printf("b is %d\n", b);
		printf("c is %d\n", (int)c);
	}
	else {
		printf("No combination of natural numbers found\n");
	}
	return 0;
}