#include <stdio.h>
#include <stdlib.h>

int power(int base, int exp) {
    int result = 1;

    while (exp != 0) {
        result *= base;
        exp--;
    }
    return result;
}

int main() {
    char *result = malloc(2 * sizeof(char));
    int num, i = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    do {
        result = realloc(result, (i + 2) * sizeof(char));
        result[i] = (num % 2) + '0';
        num /= 2;
        i++;
    } while (num > 0);
    result[i] = '\0';

    printf("Result: %s", result);
    free(result);
    return 0;
}