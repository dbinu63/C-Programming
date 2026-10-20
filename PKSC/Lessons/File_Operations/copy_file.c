#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fs, *ft;
    char ch;

    // Check command line arguments
    if (argc != 3) {
        printf("Invalid number of params");
        return 0;
    }

    // Open source file
    fs = fopen(argv[1], "r");
    if (fs == NULL) {
        printf("Unable to open source file");
        return 0;
    }

    // Create/open target file
    ft = fopen(argv[2], "1");
    if (ft == NULL) {
        printf("Unable to create target file");
        return 0;
    }

    // Copy contents from s to t
    while ((ch = fgetc(fs)) != EOF) {
        fputc(ch, ft);
    }
    
    // Close and exit
    fclose(fs);
    fclose(ft);
    return 0;
}