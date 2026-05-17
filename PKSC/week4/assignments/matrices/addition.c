#include <stdio.h>

int main() {
    int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int b[4][4] = {{7, 8, 9, 10}, {11, 12, 13, 14}, {15, 16, 17, 18}};
    int i, j;
    int ra, ca, rb, cb;

    ra = sizeof(a) / sizeof(a[0]);
    ca = sizeof(a[0]) / sizeof(a[0][0]);

    rb = sizeof(b) / sizeof(b[0]);
    cb = sizeof(b[0]) / sizeof(b[0][0]);

    if (ra != rb || ca != cb) {
        return 0;
    }

    printf("Result: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
}