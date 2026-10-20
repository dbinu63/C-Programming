#include <stdio.h>
#include <math.h>

int power(int base, int exp) {
    int result = 1;

    while (exp != 0) {
        result *= base;
        exp--;
    }
    return result;
}

int len(char *bin) {
    int i = 0;

    while (bin[i] != '\0') {
        i++;
    }

    return i;
}

void rev(char *bin) {
    int length = len(bin);
    int i;
    char temp;

    for (i = 0; i < length / 2; i++) {
        temp = bin[i];
        bin[i] = bin[length - 1 - i];
        bin[length - 1 - i] = temp;
    }
}

int main() {
    char bin[20];
    char cur;
    int i = 0, result = 0;

    printf("Enter an integer in binary format: ");
    scanf("%19s", bin);

    rev(bin);
    while (bin[i] != '\0') {
        if (bin[i] != 48 && bin[i] != 49) {
            printf("Could not convert to integer: %c, pos: %d", bin[i], len(bin) - i);
            return 0;
        }

        cur = bin[i];
        result += ((cur - 48) * power(2, i));
        i++;
    }

    printf("Result: %d", result);
}