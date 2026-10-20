#include <stdio.h>
#include <ctype.h>

void upper(char *str);

void lower(char *str);

void proper(char *str);

int main() {
    char str[] = "Hello there.";

    printf("Upper function result: \n");
    upper(str);
    printf("%s", str);

    printf("\n\nLower function result: \n");
    lower(str);
    printf("%s", str);

    printf("\n\nProper function result: \n");
    proper(str);
    printf("%s", str);
}

void upper(char *str) {
    while (*str != '\0') {
        *str = toupper(*str);
        str += 1;
    }
}

void lower(char *str) {
    while (*str != '\0') {
        *str = tolower(*str);
        str += 1;
    }
}

void proper(char *str) {
    int up = 1;

    while (*str != '\0') {
        if (up) {
            *str = toupper(*str);
        } else {
            *str = tolower(*str);
        }

        up = *str == 32 ? 1 : 0;

        str += 1;
    }
}