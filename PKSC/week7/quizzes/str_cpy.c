#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy(char *cpy, char *str);

int main() {
    char s[] = "Hello there";
    char *c;

    c = (char *)malloc((strlen(s) + 1) * sizeof(char));

    copy(c, s);

    printf("Copied string: %s", c);

    free(c);

    return 0;
}

void copy(char *cpy, char *str) {
    if (*str == '\0') {
        *cpy = '\0';
    } else {
        *cpy = *str;
        copy(cpy + 1, str + 1);
    }
}