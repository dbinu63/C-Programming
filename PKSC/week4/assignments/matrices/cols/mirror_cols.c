#include <stdio.h>

int main() {
    int a[5][4] = {{9, 2, 5, 1}, {76, 4, 6, 43}, {56, 3, 6, 6}, {54, 23, 6, 3}, {7, 3, 8, 65}};
    int i, j;

    printf("Current: \n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            a[i][j] += a[4 - i][j];
            a[4 - i][j] = a[i][j] - a[4 - i][j];
            a[i][j] -= a[4 - i][j];
        }
    }

    printf("Mirrored: \n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}