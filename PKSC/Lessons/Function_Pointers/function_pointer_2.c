#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}

int sub(int a, int b) {
    return a - b;
}

int calc(int a, int b, int (* ptr)(int, int)) {
    return ptr(a, b);
}

int main() {
    printf("%d\n", calc(10, 20, add));
    printf("%d\n", calc(10, 20, mult));
    printf("%d\n", calc(10, 20, sub));

    return 0;
}