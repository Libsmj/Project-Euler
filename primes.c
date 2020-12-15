#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int isPrime(int);

int main(int argc, char** argv) {
    long long n;
    if (argc == 2) {
		n = atoi(argv[1]);
	}
	else {
		printf("ERROR: Please enter an integer\n");
		return 1;
	}
    FILE* file = fopen("primes.txt", "w+");
    char* num = calloc(100, sizeof(char));

    for (long long i = 2; i <= n; i++) {
        if (isPrime(i)) {
            sprintf(num, "%llu,", i);
            fputs(num, file);
        }
    }

    free(num);
    fclose(file);
    return 0;
}

int isPrime(int n) {
	if (n < 4) {
		return n > 1;
	}
	if (!(n % 2) || !(n % 3)) {
		return 0;
	}
	long long i = 5;
	while (i * i < n + 1) {
		if (!(n % i) || !(n % (i + 2))) {
			return 0;
		}
		i += 6;
	}
	return 1;
}