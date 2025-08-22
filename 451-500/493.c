#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
    70 coloured balls are placed in an urn, 10 for each of the seven rainbow colours.
    What is the expected number of distinct colours in 20 randomly picked balls?
    Give your answer with nine digits after the decimal point (a.bcdefghij).
*/

#define COLORS 7
#define BALLS 10
#define SAMPLES 20

// Actual answer can be found in precise calculators, 7 * (1 - (60 choose 20) / (70 choose 20) )

int rand_int(int limit) {
    int divisor = RAND_MAX/(limit+1);
    int retval;

    do { 
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}

// Removes a random ball from the urn and returns the numeric value of the ball removed.
int sample(char* urn, int ballsRemoved) {
    int randomSample = rand_int(70 - 1 - ballsRemoved);

    int ballsSkipped = 0;

    for (int i = 0; i < COLORS; i++) {
        // Bound for random sample falling within current color = [total balls checked, total balls checked + the number of balls remaining for current color)
        if (randomSample >= ballsSkipped && randomSample < ballsSkipped + urn[i]) {
            urn[i] --;
            return i;
        }
        ballsSkipped += urn[i];
    }

    printf("Error, value of random sample is greater than the number of remaining balls\n");
    // Should only get here if we run out of balls
    return -1;
}

void initialize(char* urn, int* samples) {
    for (int i = 0; i < COLORS; i++) {
        urn[i] = BALLS; // How many balls remain in each urn
        samples[i] = 0; // How many times a color has been seen
    }
}

void print_urn(char* urn) {
    for (int i = 0; i < COLORS; i++) {
        printf("%d : %d\n", i, urn[i]);
    }
}

int trial(char* urn, int* colorSamples) {
    initialize(urn, colorSamples);

    for (int i = 0; i < SAMPLES; i++) {
        int color = sample(urn, i);
        colorSamples[color]++;
    }

    int uniqueColors = 0;
    for (int i = 0; i < COLORS; i++) {
        if (colorSamples[i] > 0) {
            uniqueColors++;
        }
    }
    return uniqueColors;
}


int main() {
    srand(time(NULL));
    char* urn = malloc((COLORS * BALLS) * sizeof(char));
    int* colorSamples = malloc(COLORS *  sizeof(int));

    int trials = 10000000;
    int uniqueColorTotal = 0;

    for (int i = 0; i < trials; i++) {
        uniqueColorTotal += trial(urn, colorSamples);
    }

    double experimentalExpectedValue = ((double) uniqueColorTotal) / ((double) trials);
    printf("%d : %d : %0.9f\n", uniqueColorTotal, trials, experimentalExpectedValue);

    free(colorSamples);
    free(urn);
    return 0;
}