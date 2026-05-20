#include <stdio.h>

int main() {
    int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int b[4][3] = {{7, 8, 9}, {10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int c[50][50] = {0}, i, j, k;
    int ca, rb;

    ca = sizeof(a[0]) / sizeof(a[0][0]);
    rb = sizeof(b) / sizeof(b[0]);

    if (ca != rb) return 0;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < rb; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%6d", c[i][j]);
        }
        printf("\n");
    }
}