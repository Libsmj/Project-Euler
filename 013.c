#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
    Work out the first ten digits of the sum of the following one-hundred 50-digit numbers (013.txt).
*/

int main(int argc, char** argv) {
    printf("Problem 13 - Large sum\n");
    int fd, i, j, carry;
    int d = 100;
    int p = 50;
    char* buff = malloc(50 * sizeof(int));
    char** nums = malloc(d * sizeof(char*));
    for (i = 0; i < d; i++) {
        nums[i] = malloc(p * sizeof(char));
    }
    int* sum = calloc(p, sizeof(int));

    if (argc > 1) {
		fd = open(argv[1], O_RDONLY);
	}
	else {
		fd = open("013.txt", O_RDONLY);
	}
	if (fd == -1) {
		perror("ERROR");
		return 1;
	}

    i = 0;
    while(1) {
        if (!read(fd, buff, p + 1)) {
            break;
        }
        buff[p] = 0;
        strcpy(nums[i++], buff);
    }

    for (i = 0; i < p; i++) {
        for (j = 0; j < d; j++) {
            sum[i] += nums[j][i] - '0';
        }
    }

    carry = 0;
    for (i = p - 1; i > 0; i--) {
        sum[i] += carry;
        carry = sum[i] / 10;
        sum[i] %= 10;
    }
    sum[0] += carry;

    int digits = -1;
    int num = sum[0];
    while (num) {
        digits++;
        num /= 10;
    }
    for (int i = 0; i < 10 - digits; i++) {
        printf("%d", sum[i]);
    }
    printf("\n");

    free(sum);
    for (i = 0; i < d; i++) {
        free(nums[i]);
    }
    free(nums);
    free(buff);

    return 0;
}