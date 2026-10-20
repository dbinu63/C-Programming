#include <stdio.h>
#include <stdlib.h>

// set define MAX or sometihng

void mat(int rows, int cols, char str[]);

void size(int *rows, int *cols, int length);

int main() {
    char ch, *str;
    int i = 0;
    int rows, cols;

    str = (char *)malloc(sizeof(char) * 0);

    printf("Enter the string you want to encode: ");
    while((ch = getchar()) != '\n') {
        str = (char *)realloc(str, sizeof(char) * i + 2);
        str[i++] = ch;
    }
    str[i + 1] = '\0';

    printf("You entered: %s\n", str);
    
    size(&rows, &cols, i);

    printf("Rows: %d\n", rows);
    printf("Cols: %d\n", cols);

    mat(rows, cols, str);

    free(str);
    return 0;
}

void size(int *rows, int *cols, int length) {
    int n = 1;

    while (n * n <= length) {
        n++;
    }

    if (length <= n * (n - 1)) {
        *rows = (n - 1);
        *cols = n;
    } else {
        *rows = *cols = n;
    }
}

void mat(int rows, int cols, char str[]) {
    int i, j, k = 0;
    char **matrix = (char **)malloc(sizeof(char) * rows);

    for (i = 0; i < rows; i++) {
        matrix[i] = (char *)malloc(cols * sizeof(char));
    }

    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            if (str[k] != '\0') {
                matrix[j][i] = str[k++];
                printf("%c ", matrix[j][i]);
            } else {
                continue;
            }
        }
        printf("\n");
    }
}