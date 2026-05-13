#include <stdio.h>

int main() {

    // Centered triangle of stars
    for (int i = 0; i < 5; i++) {
        for (int a = 0; a < 4 - i; a++) {
            printf(" ");
        }
        for (int b = 0; b < i * 2 + 1; b++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    // Centered triangle of periods
    for (int i = 0; i < 5; i++) {
        for (int a = 0; a < 4 - i; a++) {
            printf(" ");
        }
        for (int b = 0; b < i + 1; b++) {
            printf(". ");
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    // Centered triangle of numbers
    for (int i = 1; i < 6; i++) {
        for (int j = 5 - i; j > 0; j--) {
            printf("  ");
        }
        for (int a = 1; a <= i; a++) {
            printf("%d ", a);
        }
        for (int b = i-1; b > 0; b--) {
            printf("%d ", b);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    // Top right aligned triangle of descending numbers
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            printf("  ");
        }
        for (int a = 5 - i; a > 0; a--) {
            printf("%d ", a);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    // Bottom left aligned triangle of alphabet
    int b = 65;
    for (int i = 1; i < 6; i++) {
        for (int a = 1; a <= i; a++) {
            printf("%c ", b);
            b++;
        }
        printf("\n");
    }
}