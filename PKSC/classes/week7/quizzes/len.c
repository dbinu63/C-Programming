#include <stdio.h>

int len(char *str) {
    int length = 0;

    while (str[length] != '\0') { // can also write while (*str != '\0') {s = s + 1}, saves count var memory
        length++;
    }

    return length;
}

int main() {
    char *s, ch;

    while ((ch = getchar()) != '\n') {
        
    }

    printf("Length is: %d\n", len(s));

    return 0;
}