#include <stdio.h>

int len(char *str) {
    if (*str != '\0') {
        return 1 + len(str + 1);
    } else {
        return 0;
    }
}

int main() {
    char s[] = "Hello there";

    printf("Length is: %d\n", len(s));

    return 0;
}