#include <stdio.h>
#include <stdlib.h>

#define size 28300

_Bool abundant_num(int);

int main() {
	int sum, i, j, max;
	int* nums = calloc(size, sizeof(int));
	_Bool* sums = calloc(size, sizeof(int));
	
	sum = 0;
	for (i = 0; i < size; i++) {
		sum += i;
	}

	for (i = 0, max = 0; i < size; i++) {
		if (abundant_num(i)) {
			nums[max++] = i;
		}
	}

	for (i = 0; i < max; i++) {
		for (j = 0; j < max; j++) {
			sums[nums[i] + nums[j]] = 1;
		}
	}

	for (i = 0; i < size; i++) {
		if (sums[i]){
			sum -= i;
		}
	}

	printf("%d\n", sum);
}

_Bool abundant_num(int n) {
	int sum, i;
	sum = 0;
	for (i = 1; i < n; i++) {
		if (!(n % i)) { 
			sum += i;
		}
	}
	return sum > n;
}
