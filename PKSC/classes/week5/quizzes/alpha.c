#include <stdio.h>

void upper(char in) {
    if (in > 96 && in < 123) {
        printf("Result: %c", in - 32);
    }
}

void lower(char in) {
    if (in > 64 && in < 91) {
        printf("Result: %c", in + 32);
    }
}

int main() {
    int op;
    char in;

    printf("What char would you like to convert: ");
    scanf("%c", &in);

    upper(in);
    lower(in);

    return 0;
}