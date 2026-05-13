#include <stdio.h>

int main() {
    int in, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &in);

    sum += in % 10;

    while (in > 10) {
        in /= 10;
    }

    sum += in;

    printf("%d", sum);
}