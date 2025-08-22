#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
    Not all numbers produce palindromes so quickly. For example,
        349 + 943 = 1292
        1292 + 2921 = 4213
        4213 + 3124 = 7337
    That is, 349 took three iterations to arrive at a palindrome.
    Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. 
    A number that never forms a palindrome through the reverse and add process is called a Lychrel number. 
    Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. 
    In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. 
    In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).
    Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.
    How many Lychrel numbers are there below ten-thousand?
    NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.
*/

#define MAX_CHECK 10000
#define MAX_DEPTH 50

int next_check(unsigned long, int);
int is_palindrome(unsigned long);
unsigned long reverse_num(unsigned long);

int main() {
    int total = 0;
    for (int currentNum = 1; currentNum < MAX_CHECK; currentNum++) {
        if (next_check(currentNum, 0) == 0) {
            total++;
        }
    }

    printf("%d\n", total);
    return 0;
}

int next_check(unsigned long num, int depth) {
    if (depth >= MAX_DEPTH) {
        return 0;
    }
    unsigned long reverseNum = reverse_num(num);
    unsigned long nextNum = num + reverseNum;
    if (is_palindrome(nextNum)) {
        return 1;
    }
    if (next_check(nextNum, depth + 1)) {
        return 1;
    }
    return 0;
}

int is_palindrome(unsigned long num) {
    char buff[1024];
    int size = sprintf(buff, "%ld", num);
    for (int i = 0; i < size / 2; i++) {
        if (buff[i] != buff[size - i - 1]) {
            return 0;
        }
    }
    return 1;
}

unsigned long reverse_num(unsigned long num) {
    unsigned long reverseNum = 0;

    while (num > 0) {
        reverseNum *= 10;
        reverseNum += num % 10;
        num /= 10;
    }
    return reverseNum;
}