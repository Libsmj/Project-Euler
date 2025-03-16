#include <stdio.h>
#include <stdlib.h>

/*
    We define an S-number to be a natural number, n, that is a perfect square and its square root can be obtained by splitting the decimal representation of n into 2 or more numbers then adding the numbers.
    
    For example, 81 is an S-number because sqrt{81} = 8+1.
    6724 is an S-number: sqrt{6724} = 6+72+4.
    8281 is an S-number: sqrt{8281} = 8+2+81 = 82+8+1.
    9801 is an S-number: sqrt{9801} = 98+0+1.
    
    Further we define T(N) to be the sum of all S numbers n\le N. You are given T(10^4) = 41333.
    
    Find T(10^{12}).
 */

int main() {
    return 0;
}

int is_s_number(long num, long square) {

    return 0;
}





/*
Example partitions

    1 | 2 | 3 | 4 | 5 - 1 1 1 1 1

    1 | 2 | 3 | 4   5 - 1 1 1 2
    1 | 2 | 3   4 | 5 - 1 1 2 1
    1 | 2   3 | 4 | 5 - 1 2 1 1
    1   2 | 3 | 4 | 5 - 2 1 1 1

    1 | 2 | 3   4   5 - 1 1 3
    1 | 2   3 | 4   5 - 1 2 2
    1 | 2   3   4 | 5 - 1 3 1
    1   2 | 3 | 4   5 - 2 1 2
    1   2 | 3   4 | 5 - 2 2 1
    1   2   3 | 4 | 5 - 3 1 1

    1 | 2   3   4   5 - 1 4
    1   2 | 3   4   5 - 2 3
    1   2   3 | 4   5 - 3 2
    1   2   3   4 | 5 - 4 1




    9   8   0   1

    9 | 8 | 0 | 1

    9 | 8 | 0   1
    9 | 8   0 | 1
    9   8 | 0 | 1

    9 | 8   0   1
    9   8 | 0   1
    9   8   0 | 1
*/