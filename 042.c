#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
    The nth term of the sequence of triangle numbers is given by, t_n = ½n(n+1); so the first ten triangle numbers are:

        1,3,6,10,15,21,28,36,45,55,...

    By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. 
    For example, the word value for SKY is 19+11+25=55=t_10. If the word value is a triangle number then we shall call the word a triangle word.

    Using 042.txt, a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/

int is_triangle_number(int n) {
    double inverse_num = (1 + sqrt(8*n+1)) / 2;
    return floor(inverse_num) == inverse_num;
}

int word_value(char* word) {
    int value = 0;
    for (int i = 0; word[i] != 0; i++) {
        // Don't count quotes
        if (word[i] == '\"') {
            continue;
        }
        value += word[i] - 'A' + 1;
    }
    return value;
}

int main() {
    int count = 0;
    FILE *fp;
    char row[100000];
    char *token;

    fp = fopen("042.txt","r");

    while (feof(fp) != 1)
    {
        fgets(row, 100000, fp);

        token = strtok(row, ",");

        while(token != NULL)
        {
            if (is_triangle_number(word_value(token))) {
                count++;
            }
            token = strtok(NULL, ",");
        }

    }
    printf("%d\n", count);
    fclose(fp);
    return 0;
}