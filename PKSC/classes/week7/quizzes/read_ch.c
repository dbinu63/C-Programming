#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);
        printf("%c", ch);
    }
    return 0;
}