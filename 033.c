#include <stdio.h>
#include <stdlib.h>

/*
    The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98=4/8, which is correct, is obtained by cancelling the 9s.

    We shall consider fractions like, 30/50=3/5, to be trivial examples.

    There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

    If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 */

struct fraction {
    int numerator;
    int denominator;
};

int incorrect_reduce_fraction(struct fraction, struct fraction*);
struct fraction reduce_fraction(struct fraction number);
int are_fractions_equal(struct fraction f1, struct fraction f2);
struct fraction multiply_fractions(struct fraction f1, struct fraction f2);
int gcd(int a, int b);

int main() {
    struct fraction currentFraction;
    struct fraction incorrectResult;
    struct fraction product;
    product.numerator = 1;
    product.denominator = 1;

    for (currentFraction.numerator = 10; currentFraction.numerator < 100; currentFraction.numerator++) {
        for (currentFraction.denominator = currentFraction.numerator + 1; currentFraction.denominator < 100; currentFraction.denominator++) {
            if (incorrect_reduce_fraction(currentFraction, &incorrectResult) == 1) {
                if (are_fractions_equal(currentFraction, incorrectResult)) {
                    product = multiply_fractions(product, incorrectResult);
                }
            }
        }
    }

    product = reduce_fraction(product);

    printf("Product of fractions = %d/%d\n", product.numerator, product.denominator);

    return 0;
}

int incorrect_reduce_fraction(struct fraction number, struct fraction* reducedFraction) {
    int n1 = number.numerator / 10;
    int n2 = number.numerator % 10;

    int d1 = number.denominator / 10;
    int d2 = number.denominator % 10;
    
    if (n1 == d1) {
        (*reducedFraction).numerator = n2;
        (*reducedFraction).denominator = d2;
        return 1; 
    }
    if (n1 == d2) {
        (*reducedFraction).numerator = n2;
        (*reducedFraction).denominator = d1;
        return 1; 
    }
    if (n2 != 0) {
        if (n2 == d1) {
            (*reducedFraction).numerator = n1;
            (*reducedFraction).denominator = d2;
            return 1; 
        }
        if (n2 == d2) {
            (*reducedFraction).numerator = n1;
            (*reducedFraction).denominator = d1;
            return 1; 
        }
    }

    return 0;
}

struct fraction reduce_fraction(struct fraction number) {
    int d = gcd(number.numerator, number.denominator);
    struct fraction simpleFraction;
    simpleFraction.numerator = number.numerator / d;
    simpleFraction.denominator = number.denominator / d;
    return simpleFraction;
}

int are_fractions_equal(struct fraction f1, struct fraction f2) {
    struct fraction simple_f1 = reduce_fraction(f1);
    struct fraction simple_f2 = reduce_fraction(f2);

    return simple_f1.numerator == simple_f2.numerator && simple_f1.denominator == simple_f2.denominator;
}

struct fraction multiply_fractions(struct fraction f1, struct fraction f2) {
    struct fraction product;
    product.numerator = f1.numerator * f2.numerator;
    product.denominator = f1.denominator * f2.denominator;
    return product;
}

int gcd(int a, int b) {
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a; 
}