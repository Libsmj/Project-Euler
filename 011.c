#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
    In the 20×20 grid below (011.txt), four numbers along a diagonal line have been marked in red.

    The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

    What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
*/

int main(int argc, char** argv) {
    printf("Problem 11 - Largest product in a grid\n");
    int fd, i, j, k;
    int d = 20;
    int p = 4;
    int largestProduct = 0;
    char* buff = malloc(p * sizeof(char));
    int** grid = malloc(d * sizeof(int*));
    for (i = 0; i < d; i++) {
        grid[i] = malloc(d * sizeof(int));
    }

    if (argc > 1) {
		fd = open(argv[1], O_RDONLY);
	}
	else {
		fd = open("011.txt", O_RDONLY);
	}
	if (fd == -1) {
		perror("ERROR");
		return 1;
	}

    i = 0; j = 0;
    while(1) {
        if (!read(fd, buff, 3)) {
            break;
        }
        grid[i++][j] = atoi(buff);
        if (i == d) {
            i = 0; 
            j++;
        }
    }
    
    // Vertical
    for (i = 0; i < d; i++) {
        for (j = 0; j < d - p; j++) {
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
    for (i = 0; i < d - p; i++) {
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
    for (i = 0; i < d - p; i++) {
        for (j = 0; j < d - p; j++) {
            int product = 1;
            for (k = 0; k < p; k++) {
                product *= grid[i + k][j + k];
            }
            if (product > largestProduct) {
                largestProduct = product;
            }
        }
    }

    // Diagonal top right to bottom left
    for (i = 0; i < d - p; i++) {
        for (j = p; j < d; j++) {
            int product = 1;
            for (k = 0; k < p; k++) {
                product *= grid[i + k][j - k];
            }
            if (product > largestProduct) {
                largestProduct = product;
            }
        }
    }

    for (int i = 0; i < d; i++) {
        free(grid[i]);
    }
    free(grid);
    free(buff);

    printf("%d\n", largestProduct);
    return 0;
}