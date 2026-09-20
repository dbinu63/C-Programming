// WAP to find the sum of digits of a given input using recursive functions
// By: D.B.

#include <stdio.h>

int sum(int);

int main() {
    int num, res = 0;

    printf("Enter a number to calculate the sum of digits: ");
    scanf("%d", &num);

    res = sum(num);
    printf("The sum of digits is: %d", res);

    return 0;
}

int sum(int n) {    
    if (n < 10) {
        return n;
    } else {
        return n % 10 + sum(n / 10);
    }
}