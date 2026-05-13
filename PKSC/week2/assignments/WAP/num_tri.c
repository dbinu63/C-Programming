#include <stdio.h>

int main() {
    int i, j, n = 4;
    for (i = 0; i < 5; i++) {
        for (j = 1; j <= 5; j++) {
            if (n >= j) {
                printf("  ");
            } else {
                printf("%d ", j);
            }
        }
        printf("\n");
        n--;
    }
}