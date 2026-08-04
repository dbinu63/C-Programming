#include <stdio.h>

int sum(int *m, int n) {
    if (n == 0) {
        return 0;
    } else if (m[n - 1] % 2) {
        return 1 + sum(m, n - 1);
    } else {
        return 0 + sum(m, n - 1);
    }
}

int main() {
    int a[] = {9, 3, 5, 2, 5};
    int s;

    s = sum(a, 5);
    printf("The number of odd elements in the array is: %d", s);
    return 0;
}