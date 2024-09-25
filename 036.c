#include <stdio.h>
#include <stdlib.h>

int decimal_to_binary(int base10Num, char* base2Num);
int is_palandrome(char* number, int size);

int main() {
    char base10NumberString[10];
    char* base2Number = malloc(20 * sizeof(char));
    int sum = 0;
    
    for (int number = 0; number < 1000000; number++) {
        int size = sprintf(base10NumberString, "%d", number);
        if (is_palandrome(base10NumberString, size) == 1) {
            size = decimal_to_binary(number, base2Number);
            if (is_palandrome(base2Number, size) == 1) {
                sum += number;
            }
        }
    }

    printf("%d\n", sum);

    free(base2Number);
    return 0;
}

int decimal_to_binary(int base10Num, char* base2Num)
{ 
    // counter for binary array
    int i = 0;
    while (base10Num > 0) {
        // storing remainder in binary array
        base2Num[i] = base10Num % 2;
        base10Num = base10Num / 2;
        i++;
    }
 
    return i;
}

int is_palandrome(char* number, int size) {
    for (int i = 0; i < size / 2; i++) {
        if (number[i] != number[size - i - 1]) {
            return 0;
        }
    }
    return 1;
}