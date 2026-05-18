#include <stdio.h>

int main() {
    int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int i, j, k, num;

    printf("Current: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nHow many moves would you like to make: ");
    scanf("%d", &num);

    for (i = 0; i < 3; i++) {
        for (k = 0; k < num; k++) {
            for (j = 0; j < 3; j++) {
                a[i][j + 1] += a[i][j];
                a[i][j] = a[i][j + 1] - a[i][j];
                a[i][j + 1] -= a[i][j];
            }
        }
    }

    printf("Result: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}