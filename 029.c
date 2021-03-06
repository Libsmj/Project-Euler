#include <stdio.h>
#include <stdlib.h>

/*
    Consider all integer combinations of a^b for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:

    2^2=4, 2^3=8, 2^4=16, 2^5=32
    3^2=9, 3^3=27, 3^4=81, 3^5=243
    4^2=16, 4^3=64, 4^4=256, 4^5=1024
    5^2=25, 5^3=125, 5^4=625, 5^5=3125
    If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:

    4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

    How many distinct terms are in the sequence generated by a^b for 2 ≤ a ≤ max and 2 ≤ b ≤ max?
*/


// Instead of calculating each term, we just store the base and power of the term.
// If there exists an x^y struct such that a^b=x, we let x=a be the new base, and then multiply the power y by b.


struct ab {
    int base;
    int power;
};

int power(struct ab x) {
    if (x.power == 0) {
        return 1;
    }
    int result = x.base;
    for (; x.power > 1; x.power--) {
        result *= x.base;
    }
    return result;
}

int areEqual(struct ab x, struct ab y) {
    return (x.base == y.base && x.power == y.power);
}

int main() {
    printf("Problem 29 - Distinct powers\n");

    int max = 100;

    struct ab** board = calloc(max + 1, sizeof(struct ab*));
    for (int i = 0; i <= max; i++) {
        board[i] = calloc(max + 1, sizeof(struct ab));
        for (int j = 0; j <= max; j++) {
            struct ab temp;
            temp.base = 0;
            temp.power = 1;
            board[i][j] = temp;
        }
    }

    // Form the board
    for (int i = 2; i <= max; i++) {
        for (int j = 2; j <= max; j++) {
            if (!board[i][j].base) {
                board[i][j].base = i;
            }
            board[i][j].power *= j;

            // Check if the expanded term is the base of another term on the board
            int x = power(board[i][j]);
            if (x >= 2 && x <= max) {
                for (int k = 2; k <= max; k++) {
                    board[x][k].base = board[i][j].base;
                    board[x][k].power = board[i][j].power;
                }
            }
        }
    }

    // Count the number of unique entries
    int n = 1;
    struct ab* list = calloc(max*max, sizeof(struct ab));
    list[0] = board[2][2];
    for (int i = 2; i <= max; i++) {
        for (int j = 2; j <= max; j++) {
            int k = 0;
            for (; k < n; k++) {
                if (areEqual(board[i][j], list[k])) {
                    break;
                }
            }
            if (k == n) {
                list[n] = board[i][j];
                n++;
            }
        }
    }
    printf("There are %d distinct terms in the sequence\n", n);

    free(list);
    for (int i = 0; i <= max; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}