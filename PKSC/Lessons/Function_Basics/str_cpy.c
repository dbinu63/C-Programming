#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy(char *cpy, char *str);

int main() {
    char *str, *c, ch;
    int n = 1;

    str = (char *)malloc(sizeof(char));

    while((ch = getchar()) != '\n') {
        str = realloc(str, ++n * sizeof(char));
        str[n - 2] = ch;
    }
    str[n - 1] = '\0';

    c = (char *)malloc((strlen(str) + 1) * sizeof(char));

    copy(c, str);

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