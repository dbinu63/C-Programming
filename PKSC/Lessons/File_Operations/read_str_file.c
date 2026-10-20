#include <stdio.h>

int main() {
    FILE *fs;
    char string[100];

    fs = fopen("./context/sabc.txt", "r");

    while (fgets(string, sizeof(string), fs) != NULL) {
        printf("%s", string);
    }

    fclose(fs);
    return 0;
}