#include <stdio.h>

int main() {
    char str[100];
    int i = 0, j, k;

    str = 'hello della johnson'

    while (str[i] != '\0') {
        if (str[i] != ' ') continue;

        for (j = i + 1; str[j] != '\0'; j++) {
            if (str[i] == str[j]) {
                for (k = j; str[k] != '\0'; k++) {
                    str[k] = str[k + 1];
                }
            }
        }
    }

    printf("Result: %s", str);
}