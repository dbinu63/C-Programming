#include <stdio.h>

int sum_dig(int in) {
    int res = 0;

    while (in > 9) {
        res += in % 10;
        in /= 10;
    }
    res += in;

    return res;
}

int main() {
    int in;

    printf("Enter an input: ");
    scanf("%d", &in);

    printf("Result: %d", sum_dig(in));
}