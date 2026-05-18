#include <stdio.h>

int main() {
    int a[5][5] = {{9, 2, 5, 1, 5}, {76, 4, 6, 43, 2}, {56, 3, 6, 6, 5}, {54, 23, 6, 3, 43}, {7, 3, 8, 65, 4}};
    int i, j, rows = 3;

    printf("Current: \n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (printf("%d  ", a[i][j]) < 4) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 5; i++) {
            a[i][j] += a[i][4 - j];
            a[i][4 - j] = a[i][j] - a[i][4 - j];
            a[i][j] -= a[i][4 - j];
        }
    }

    printf("Mirrored: \n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (printf("%d  ", a[i][j]) < 4) {
                printf(" ");
            }
        }
        printf("\n");
    }
}