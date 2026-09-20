#include <stdio.h>

int sum(int *m, int n) {
    if (n > 0) {
        return m[n-1] + sum(m, n -1);
    } else {
        return 0;
    }
}

int main() {
    int a[] = {9, 3, 5, 2, 5};
    int s;

    s = sum(a, 5);
    printf("The sum of all elements in the array is: %d", s);
    return 0;
}