#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("./context/some.txt", "r");
    char ch;
    int spaces = 0;

    while ((ch = fgetc(fp)) != EOF) {
        spaces += ch == 32 ? 1 : 0;
    }
    spaces += 1;

    printf("There are %d words in the file. ", spaces);

    fclose(fp);
    return 0;
}