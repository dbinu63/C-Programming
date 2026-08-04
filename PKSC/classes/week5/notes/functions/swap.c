// WAP to swap two inputs using a by reference function
// BY: D.B.

#include <stdio.h>

void swap(int *, int *);

int main() {
    int a = 5, b = 7;

    printf("a: %d\nb: %d\n\n", a, b);

    swap(&a, &b);
}

void swap(int *a, int *b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;

    printf("a: %d\nb: %d", *a, *b);
}