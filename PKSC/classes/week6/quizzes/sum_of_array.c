#include <stdio.h>

int sum(int *m, int n) {
    int i, res = 0;
    for(i = 0;i < n; i++) {
        res += m[i];
    }
    return res;
}

int main() {
    int a[] = {9, 3, 5, 2, 5};
    int s;

    s = sum(a, 5);
    printf("The sum of all elements in the array is: %d", s);
    return 0;
}