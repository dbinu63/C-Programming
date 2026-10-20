#include <stdio.h>
#define PTR char *

typedef char * POINTER;

int main() {
    POINTER x, y; // types work differentely: char *x, char *y
    PTR a, b;   // replaced as: char *a, b
    printf("%d, %d\n\n", sizeof(a), sizeof(b));
    printf("%d, %d", sizeof(x), sizeof(y));
}