// WAP to print the fibonacci sequence up until a given position using recursive functions
// By: D.B.

#include <stdio.h>

void fib(int);

int main() {
    int num;

    printf("How many numbers would you like to print? ");
    scanf("%d", &num);

    fib(num);

    return 0;
}

void fib(int num) {
    int a = 0, b = 1, n = 0;

    printf("1: %d\n", a);
    for (n = 2; n <= num; n++) {
        printf("%d: %d\n", n, a += b);
        printf("%d: %d\n", n += 1, b += a);
    }
}