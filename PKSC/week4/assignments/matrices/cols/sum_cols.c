#include <stdio.h>

int main() {
    int a[3][4] = {{9, 2, 5, 1}, {76, 4, 6, 43}, {56, 3, 6, 6}};
    int i, j, sum = 0;

    printf("Current: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 3; i++) {
            sum += a[i][j];
        }
        printf("%d ", sum);
        sum = 0;
    }
}