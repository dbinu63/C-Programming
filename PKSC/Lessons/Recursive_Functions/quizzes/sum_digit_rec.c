#include <stdio.h>

int sum_dig(int in) {
    if (in < 10) {
        return in;
    } else {
        return in % 10 + sum_dig(in / 10);
    }
}

int main() {
    int in;

    printf("Enter an input: ");
    scanf("%d", &in);

    printf("Result: %d", sum_dig(in));
}