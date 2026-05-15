#include <stdio.h>

int main() {
    int a[3][3];
    int n;
    int size = sizeof(a) / sizeof(int);

    for (int n = 1; n * n <= size; n++) {
        if (n * n == size) {
            printf("Unit matrix");
            return 0;
        }
    }

    printf("Not a unit matrix");
    return 0;
}