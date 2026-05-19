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

    for (i = 0; i < 5; i++) {
        for (k = 0; k < 4; k++) {
            for (j = 0; j < 4; j++) {
                if (a[i][j] > a[i][j + 1]) {
                    a[i][j] += a[i][j + 1];
                    a[i][j + 1] = a[i][j] - a[i][j + 1];
                    a[i][j] -= a[i][j + 1];
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