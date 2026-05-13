#include <stdio.h>

int main() {

    // Rectangle in alternating binary
    for (int i = 0; i < 5; i++) {
        for (int j = 1; j < 6; j++) {
            printf("%d", (j + i) % 2);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    // Numeric rectangle
    for (int i = 0; i < 5; i++) {
        for (int j = 1; j < 6; j++) {
            printf("%d", j + i);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    // 0s rectangle bounded by 1s
    for (float i = 0; i < 5; i++) {
        for (float j = 0; j < 5; j++) {
            printf("%d", i * j == 0 || i == 4 || j == 4);
        }
        printf("\n");
    }
}