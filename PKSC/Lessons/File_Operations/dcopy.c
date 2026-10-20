#include <stdio.h>

int main() {
    FILE *fs, *ft;
    char ch;

    fs = fopen("./context/abc.txt", "r");
    ft = fopen("./context/xyz.txt", "w");

    while((ch = fgetc(fs)) != EOF) {
        fputc(ch, ft);
    }

    fclose(fs);
    fclose(ft);

    printf("File copied. ");
    return 0;
}