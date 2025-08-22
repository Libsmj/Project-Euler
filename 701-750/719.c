#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    We define an S-number to be a natural number, n, that is a perfect square and its square root can be obtained by splitting the decimal representation of n into 2 or more numbers then adding the numbers.
    
    For example, 81 is an S-number because sqrt{81} = 8+1.
    6724 is an S-number: sqrt{6724} = 6+72+4.
    8281 is an S-number: sqrt{8281} = 8+2+81 = 82+8+1.
    9801 is an S-number: sqrt{9801} = 98+0+1.
    
    Further we define T(N) to be the sum of all S numbers n\le N. You are given T(10^4) = 41333.
    
    Find T(10^{12}). 
*/

#define TEN_TO_FOURTH 10000
#define TEN_TO_TWELFTH 1000000000000
#define MAX_POWER 12

typedef unsigned int Uint;
static inline int bit_check(Uint number, Uint n) {
    return (number >> n) & (Uint)1;
}
/*
    Returns 2^power
 */
static inline long two_power(int power) {
    return 1 << power;
}


/*
    Loop from 1 to 2^{number of partitions} - 1
    0 partitions not allowed

    Binary representation tells us where the paritions go, example with number 12345 and one combination of 2 partitions
        1 0 1 0 = 1 | 2   3 | 4   5 = 1 + 23 + 45
    Keep dividing by 10 until we find a bit set to 1, then that is the cutoff for our number
        0, pull off 5
        1, pull off 4, 4*10 + 5 = 45
        0, pull off 3
        1, pull off 2, 2*10 + 3 = 23
        pull off remainder 1
*/
int is_s_number(long, long, int);

int main() {
    long sum = 0;

    // Track number of partitions in square
    long nextTensPower = 10;
    int partitions = 0;

    for (long num = 1, square = num * num; square <= TEN_TO_TWELFTH; num++, square = num * num) {
        // Keep track of the maximuim number of partions we can use when breaking up the number
        while (square >= nextTensPower) {
            nextTensPower *= 10;
            partitions++;
        }
        // Optimization added after
        if ((square - num) % 9 == 0) {
            if (is_s_number(num, square, partitions)) {
                sum += square;
            }
        }
        
    }

    printf("%ld\n", sum);
    return 0;
}

int is_s_number(long num, long square, int partitions) {
    int digits[MAX_POWER] = {};
    int i = 0;
    while (square > 0) {
        digits[i++] = square % 10;
        square /= 10;
    }

    for (int i = 1; i <= two_power(partitions) - 1; i++) {
        // Running sum for this partition
        long sum = 0;
        // Current 10s place that we are adding to, E.G. tenPower=3 => 3rd tens place => sum+(digit*100)
        long tenPower = 1;
        
        for (int j = 0; j <= partitions; j++) {
            // Add the next digit to the correct 10s power
            sum += digits[j] * tenPower;
            if (sum > num) {
                break;
            }
            // Move to the next power of 10
            tenPower *= 10;

            // If a 1 bit is found, insert a partition, which is resetting the power of 10
            if (bit_check(i, j)) {
                tenPower = 1;
            }
        }
        // Check if the condition is satisfied
        if (sum == num) {
            return 1;
        }
    }
    
    return 0;
}

/*
Example partitions

    Partitioned Num      Num Digits   Binary      Decimal
    1 | 2 | 3 | 4 | 5   - 1 1 1 1 1 - 1 1 1 1   - 15
    1 | 2 | 3 | 4   5   - 1 1 1 2   - 1 1 1 0   - 14
    1 | 2 | 3   4 | 5   - 1 1 2 1   - 1 1 0 1   - 13
    1 | 2 | 3   4   5   - 1 1 3     - 1 1 0 0   - 12
    1 | 2   3 | 4 | 5   - 1 2 1 1   - 1 0 1 1   - 11
    1 | 2   3 | 4   5   - 1 2 2     - 1 0 1 0   - 10
    1 | 2   3   4 | 5   - 1 3 1     - 1 0 0 1   - 9
    1 | 2   3   4   5   - 1 4       - 1 0 0 0   - 8
    1   2 | 3 | 4 | 5   - 2 1 1 1   - 0 1 1 1   - 7
    1   2 | 3 | 4   5   - 2 1 2     - 0 1 1 0   - 6
    1   2 | 3   4 | 5   - 2 2 1     - 0 1 0 1   - 5
    1   2 | 3   4   5   - 2 3       - 0 1 0 0   - 4
    1   2   3 | 4 | 5   - 3 1 1     - 0 0 1 1   - 3
    1   2   3 | 4   5   - 3 2       - 0 0 1 0   - 2
    1   2   3   4 | 5   - 4 1       - 0 0 0 1   - 1

    1 | 2 | 3 | 4   5   - 1 1 1 2
    1 | 2 | 3   4 | 5   - 1 1 2 1
    1 | 2   3 | 4 | 5   - 1 2 1 1
    1   2 | 3 | 4 | 5   - 2 1 1 1

    1 | 2 | 3   4   5   - 1 1 3
    1 | 2   3 | 4   5   - 1 2 2
    1 | 2   3   4 | 5   - 1 3 1
    1   2 | 3 | 4   5   - 2 1 2
    1   2 | 3   4 | 5   - 2 2 1
    1   2   3 | 4 | 5   - 3 1 1

    1 | 2   3   4   5   - 1 4
    1   2 | 3   4   5   - 2 3
    1   2   3 | 4   5   - 3 2
    1   2   3   4 | 5   - 4 1



    9 | 8 | 0 | 1   - 1 1 1 1

    9 | 8 | 0   1   - 1 1 2
    9 | 8   0 | 1   - 1 2 1
    9   8 | 0 | 1   - 2 1 1

    9 | 8   0   1   - 1 3
    9   8 | 0   1   - 2 2
    9   8   0 | 1   - 3 1
*/