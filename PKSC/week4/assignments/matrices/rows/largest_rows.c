#include <stdio.h>

int main() {
    int a[3][4] = {{9, 2, 5, 1}, {76, 4, 6, 43}, {56, 3, 6, 6}};
    int i, j, largest;

    printf("Current: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        largest = a[i][0];
        for (j = 0; j < 4; j++) {
            if (a[i][j] > largest) {
                largest = a[i][j];
            }
        }
        printf("The largest number in row %d is: %d\n", i + 1, largest);
    }
}