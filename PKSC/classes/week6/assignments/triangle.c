#include <stdio.h>

void tri(int i, int j) {
    int k = 1;

    if (i <= j) {
        for (; k <= j - i; k++) {
            printf("  ");
        }

        for (k = 1; k <= i; k++) {
            printf("%d ", k);
        }

        printf("\n");
        
        tri(i + 1, j);
    }
}

int main() {
    int i = 1, j = 5;

    tri(i, j);
}