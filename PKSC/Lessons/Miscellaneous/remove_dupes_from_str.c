#include <stdio.h>

int main() {
    char str[] = "hello della johnson";
    int i = 0, j, k;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            i++;
            continue;
        }

        for (j = i + 1;  str[j] != '\0';) {
            if (str[i] == str[j]) {
                for (k = j; str[k] != '\0'; k++) {
                    str[k] = str[k + 1];
                }
            } else {
                j++;
            }
        }
        i++;
    }

    printf("Result: %s", str);
}