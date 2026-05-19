#include <stdio.h>

int main() {
    int a[5][4] = {{9, 2, 5, 1}, {76, 4, 6, 43}, {56, 3, 6, 6}, {54, 23, 6, 3}, {7, 3, 8, 65}};
    int i, j, k;

    printf("Current: \n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            if (printf("%d  ", a[i][j]) < 4) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
            for (i = 0; i <  4; i++) {
                if (a[i][j] > a[i + 1][j]) {
                    a[i][j] += a[i + 1][j];
                    a[i + 1][j] = a[i][j] - a[i + 1][j];
                    a[i][j] -= a[i + 1][j];
                }
            }
        }
    }

    printf("\nSorted: \n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            if (printf("%d  ", a[i][j]) < 4) {
                printf(" ");
            }
        }
        printf("\n");
    }
}