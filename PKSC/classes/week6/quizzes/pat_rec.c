#include <stdio.h>

void row(int r) {
    if (r <= 4) {
        col(1);
        printf("\n");
        row(r + 1);
    }
}

void col(int c) {
    if (c <= 5) {
        printf("%d", c);
        col(c + 1);
    }
}

int main() {
    row(1);
}

// when passing an array to a func, you can set the func arg to either int m[] or int *m - they both work
// a[3] = 3[a] = *a + 3