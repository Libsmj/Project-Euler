#include <stdio.h>
#include <stdlib.h>

/*
    Work out the first ten digits of the sum of the following one-hundred 50-digit numbers (013.txt).
*/

int main(int argc, char** argv) {
    printf("Problem 13 - Large sum\n");
    int i, j, carry;
    int d = 100;
    int p = 50;
    char* buff = malloc((p+1) * sizeof(int));
    char** nums = malloc(d * sizeof(char*));
    for (i = 0; i < d; i++) {
        nums[i] = malloc((p+1) * sizeof(char));
    }
    int* sum = calloc(p, sizeof(int));
    FILE* fp = fopen("013.txt", "r");
    
    i = 0;
    for (i = 0; i < d; i++){
        fgets( buff, p+3, fp );
        for (j = 0; j < p; j++) {
            nums[i][j] = buff[j];
        }
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

    fclose(fp);
    free(sum);
    for (i = 0; i < d; i++) {
        free(nums[i]);
    }
    free(nums);
    free(buff);

    return 0;
}