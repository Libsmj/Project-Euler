#include <stdio.h>
#include <stdlib.h>

/*
    In the 20×20 grid below (011.txt), four numbers along a diagonal line have been marked in red.

    The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

    What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
*/

int main(int argc, char** argv) {
    printf("Problem 11 - Largest product in a grid\n");
    int i, j, k;
    int d = 20;
    int l = 4;
    int p = 2;
    int largestProduct = 0;
    char* buff = malloc( (p+2) * sizeof(char));
    int** grid = malloc(d * sizeof(int*));
    for (i = 0; i < d; i++) {
        grid[i] = malloc(d * sizeof(int));
    }
    FILE* fp = fopen("011.txt", "r");

    i = 0;
    for (i = 0; i < d; i++){
        for (j = 0; j < d; j++) {
            fgets( buff, p+2, fp );
            buff[p] = 0;
            grid[i][j] = (int) strtol(buff, (char**)NULL, 10);
        }
        fgets( buff, p, fp );
    }
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
    
    // Vertical
    for (i = 0; i < d; i++) {
        for (j = 0; j < d - l; j++) {
            int product = 1;
            for (k = 0; k < p; k++) {
                product *= grid[i][j + k];
            }
            if (product > largestProduct) {
                largestProduct = product;
            }
        }
    }

    // Horizontal
    for (i = 0; i < d - l; i++) {
        for (j = 0; j < d; j++) {
            int product = 1;
            for (k = 0; k < p; k++) {
                product *= grid[i + k][j];
            }
            if (product > largestProduct) {
                largestProduct = product;
            }
        }
    }

    // Diagonal top left to bottom right
    for (i = 0; i < d - l; i++) {
        for (j = 0; j < d - l; j++) {
            int product = 1;
            for (k = 0; k < l; k++) {
                product *= grid[i + k][j + k];
            }
            if (product > largestProduct) {
                largestProduct = product;
            }
        }
    }

    // Diagonal top right to bottom left
    for (i = 0; i < d - l; i++) {
        for (j = l; j < d; j++) {
            int product = 1;
            for (k = 0; k < l; k++) {
                product *= grid[i + k][j - k];
            }
            if (product > largestProduct) {
                largestProduct = product;
            }
        }
    }

    fclose(fp);
    for (int i = 0; i < d; i++) {
        free(grid[i]);
    }
    free(grid);
    free(buff);

    printf("%d\n", largestProduct);
    return 0;
}