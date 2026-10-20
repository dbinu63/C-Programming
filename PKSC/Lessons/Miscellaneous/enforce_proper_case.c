#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    FILE *fp;
    int space = 1;

    fp = fopen("some.txt", "w");

    while((ch = getchar()) != '\n') {
        ch = space == 1 ? toupper(ch) : tolower(ch);
        space = (ch == ' ') ? 1 : 0;
        fputc(ch, fp);
    }

    fclose(fp);

    return 0;
}