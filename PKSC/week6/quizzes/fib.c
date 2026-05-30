#include <stdio.h>

void fib(int pp, int p, int m) {
    if (m > 0) {
        printf("%d ", pp + p);
        fib(p, pp + p, m - 1);
    }
}

int main() {
    int n;
    printf("How many numbers would you like to print? ");
    scanf("%d", &n);
    printf("0 1 ");
    fib(0, 1, n - 2);
    return 0;
}