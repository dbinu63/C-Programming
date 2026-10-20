#include <stdio.h>

int main() {
    FILE *fs, *ft;
    char ch;

    fs = fopen("./context/xyz.txt", "r");
    ft = fopen("./context/temp.txt", "w");

    while((ch = fgetc(fs)) != EOF) {
        if (ch != 32) {
            fputc(ch, ft);
        }
    }

    fclose(fs);
    fclose(ft);

    fs = fopen("./context/temp.txt", "r");
    ft = fopen("./context/xyz.txt", "w");

    while((ch = fgetc(fs)) != EOF) {
        fputc(ch, ft);
    }

    remove("./context/temp.txt");

    printf("File edited.");
    return 0;
}