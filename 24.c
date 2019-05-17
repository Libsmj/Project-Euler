#include <stdio.h>
#include <stdlib.h>

#define size 10
#define max 1000000

int main() {
	int i, k;
	long long j;
	long long num = 123456789;
	

	for (i = 0, j = 9, k = 0; i < max; i++, k++) {
		num += j;
		j *= 10;
		j += 9;
		if (k > size - 3) {
			break;
		}
	}
	
	printf("%lld\n", num);

	return 0;
}

