#include <stdio.h>

void largest(int a, int b) {
    int i = 0;

    for(; a < b; a++) i++;
    for(; b < a; b++) i++;

    print(i);
}

void print(int p) {
    printf("%d is the largest of the two inputs. ", p);
}

int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d", &a);
    scanf("%d", &b);

    // a > b ? print(a) : print(b);
    largest(a, b);

    return 0;
}